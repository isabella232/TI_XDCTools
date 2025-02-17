/* 
 *  Copyright (c) 2008-2020 Texas Instruments Incorporated
 *  All rights reserved. This program and the accompanying materials
 *  are made available under the terms of the Eclipse Public License v1.0
 *  which accompanies this distribution, and is available at
 *  http://www.eclipse.org/legal/epl-v10.html
 *
 *  Contributors:
 *      Texas Instruments - initial implementation
 *
 * */
/*
 *  ======== Model.xs ========
 */

/* global print, Packages Program, xdc */

var noRuntime = false; /* keeps track if no RTSC runtime */
var cmodules = {};     /* map of C modules with ROV code */

/*
 *  ======== start ========
 */
function start(vers, executable, recap, sym, mem, callBack)
{
    xdc.om.$$bind('$name', 'rov');
    xdc.global.Program = xdc.useModule('xdc.rov.Program');

    /* Check Model compatibility. */
    if (!(vers == 4 && this.vers == 5) && vers != this.vers) {
        Program.debugPrint("Incompatible version of ROV Model. Model version "
                           + this.vers + ", client version " + vers + ".");
        throw (new Error("Incompatible version of ROV Model. Model version "
                         + this.vers + ", client version " + vers + "."));
    }

    /* Store off the objects passed in */
    this.$private.sym = sym;
    this.$private.mem = mem;
    this.$private.callBack = callBack;
    if (recap != null) {
        this.$private.recap = recap;
    }
    this.$private.files = [executable];
    if (this.$private.recap) {
        var path = this.$private.recap.$path;
        if (path.indexOf("xdc/rov/noruntime.rov.xs") == -1) {
            this.$private.files.push(path);
        }
    }

    xdc.useModule('xdc.rov.support.ScalarStructs');

    /* Read the ROV config file and/or sysconfig ROV file */
    var files = readConfig(executable);
    this.$private.files = this.$private.files.concat(files);

    /* Store off the list of all modules in the recap file */
    var mnames = [];
    for (var m in this.$private.recap.$modules) {
        if (m[0] != '#') {
            mnames.push(m);
        }
    }

    for (var name in cmodules) {
        mnames.push(name);
    }

    Program.$unseal('moduleNames');
    Program.moduleNames.$unseal();
    Program.moduleNames = mnames.sort();
    Program.moduleNames.$seal();
    Program.$seal('moduleNames');

    Program.$$bind('build', this.$private.recap.build);

    Program.$$bind('$modules', this.$private.recap.$modules);

    /* Read construct objects the old way, if they are not already acquired */
    if (!("$constructInst" in Program)) {
        var rovFile = executable.replace(/(\/Debug)|(\/Release)/, "");
        rovFile = rovFile.replace(/.out$/, "");
        var startTime = java.lang.System.currentTimeMillis();
        fetchConstructObjects(executable);
        if (java.lang.System.currentTimeMillis() - startTime > 30000) {
            callBack.updateStartupProgress(90, "Parsing DWARF data was taking "
                + "too long.\nTo speed up the ROV startup, with some loss of "
                + "functionality, you can create a new empty file " + rovFile
                + ".rov.js. For a detailed explanation of this feature, see "
                + "http://rtsc.eclipseprojects.io/docs-tip/Runtime_Object_Viewer"
                + "#Retrieving_constructed_objects.");
                java.lang.Thread.currentThread().sleep(10000);
        }
    }

    /* Notify the CallBack that we are about to start loading the packages. */
    callBack.updateStartupProgress(120, "Loading packages ...");

    /* Indicates whether getModuleDesc has been called on all modules. */
    Program.$private.allModsRead = false;

    Program.$$bind('loadModFailed', "Failed to load module");

    /*
     * Load all of the packages so the user gets this hit during
     * startup rather than on the first view.
     */
    for each (var mod in this.$private.recap.$modules) {
        /*
         * 'getModuleDesc' will handle modules which are missing from the path.
         * If it fails for any other reason, we need to allow that exception
         * to propogate up.
         */
        try {
            Program.getModuleDesc(mod.$name);
        }
        catch (e) {
            Program.debugPrint("Failed to load module " + mod.$name + ": " + e);
            throw (new Error("Failed to load module " + mod.$name + ": " + e));
        }
    }

    /* getModuleDesc has been called on all modules. */
    Program.$private.allModsRead = true;

    /*
     * TODO - version checks to ensure package versions in recap file
     * match package versions found along XDCPATH.
     */
    /*
    for each (var mod in this.$private.recap.$modules) {
        recapPkgVers = mod.$package.$vers.toString();
        pathPkg = xdc.loadPackage(mod.$package.$name);
        pathPkgVers = pathPkg.$vers;

        if (recapPkgVers != pathPkgVers) {
            throw new Error("xdc.rov.Model: Package " + mod.$package.$name
                + " version mismatch: Executable built with "
                + recapPkgVers + ", Package in path " + pathPkgVers);
        }
        else {
            print(mod.$package.$name + "Version matches fine.");
        }
    }
    */

    Program.debugPrint("bitsPerChar = "
        + this.$private.recap.build.target.bitsPerChar);

    /*
     * Create the StringReader for reading dynamic strings. Create this first
     * in case the OFReader needs to fall back on it.
     */
    var strReader = initStringReader();

    /* Create and initialize the object file reader. */
    var ofReader = initOFReader(executable);

    /* Bind the OFReader and StringReader to Program for looking up strings. */
    Program.$$bind('strReader', strReader);
    Program.$$bind('ofReader', ofReader);

    /*
     * Set up the printf Formatter for any views that will use it.
     * The formatter needs the symbol table for %r and the object
     * file reader for %s.
     */
    xdc.loadPackage('xdc.rta');

    /*
     * TODO - We should be able to get the java implementation directly;
     * we shouldn't need to create a wrapper.
     */
    //var javaSymTab = sym.getJavaImp();

    var javaSymTab = new xdc.jre.xdc.rov.ISymbolTable(
        {
            lookupDataSymbol: function lookupDataSymbol(addr) {
                return (sym.lookupDataSymbol(addr));
            },
            lookupFuncName: function lookupFuncName(addr) {
                return (sym.lookupFuncName(addr));
            }
        });

    xdc.jre.xdc.rta.Formatter.setSymbolTable(javaSymTab);

    /* Tell the Formatter the target size of an Arg in bits */
    xdc.jre.xdc.rta.Formatter.setArgSize(
        this.$private.recap.build.target.stdTypes['t_IArg'].size *
        this.$private.recap.build.target.bitsPerChar);

    /* Create the StructureDecoder and bind to Program. */
    var StructureDecoder = xdc.useModule('xdc.rov.StructureDecoder');
    var strDec = StructureDecoder.create(mem, this.$private.recap.build.target);
    Program.$$bind('strDec', strDec);

    /* Create the StateReader and bind to Program. */
    var StateReader = xdc.useModule('xdc.rov.StateReader');
    var stateReader = StateReader.create(sym, strDec);
    Program.$$bind('stateReader', stateReader);

    //Program.getModuleDesc('xdc.runtime.Text'); // ?????

    this.$private.initialized = true;
}

/*
 *  ======== initStringReader ========
 *  Creates a StringReader instance and saves it to the Model's $private
 *  object.
 */
function initStringReader()
{
    var Model = xdc.useModule('xdc.rov.Model');
    xdc.loadPackage('xdc.rov');

    /* Retrieve the MemoryImage java object. */
    var memReader = Model.getMemoryImageInst();

    /* Create a StringReader instance using the memory reader instance. */
    var strReader = new xdc.jre.xdc.rov.StringReader(memReader);

    /* Store the StringReader in the Model's $private object. */
    Model.$private.strReader = strReader;

    return (strReader);
}

/*
 *  ======== initOFReader ========
 *  A private function that creates and initializes the object file reader.
 *
 *  Model.private.$recap must be already defined. It is not enforced in the
 *  code because this can only be invoked from within this module.
 *
 *  The StringReader should be initialized first; if anything goes wrong
 *  creating the object file reader, we fall back on the string reader.
 */
function initOFReader(executable)
{
    var Model = xdc.useModule('xdc.rov.Model');

    if (Model.$private.ofReader != null) {
        return (Model.$private.ofReader);
    }

    /* Retrieve the class name of the binary parser to use */
    var binaryParser = "xdc.targets.omf.Elf";

    if (noRuntime == false) {
        binaryParser = Model.$private.recap.build.target.binaryParser;
    }
    var ofReader;

    /* Make sure the target defines a binary parser. */
    if (binaryParser != undefined) {
        try {
            if (binaryParser == "ti.targets.omf.elf.Elf"
                || binaryParser == "ti.targets.omf.elf.Elf32") {
                /* This if-block will be removed when we don't need to support
                 * products that still reference ti.targets.omf.elf.
                 */
                binaryParser = "xdc.targets.omf.Elf";
            }

            /* Parse the package name from the class name so we can load it. */
            var parserPackage =
                binaryParser.substring(0, binaryParser.lastIndexOf('.'));

            /* Load the parser's package */
            xdc.loadPackage(parserPackage);

            /* Get the parser's Java class */
            var binaryParserClass = Packages[binaryParser];

            /* Create an instance of the ofReader */
            ofReader = new binaryParserClass();

            /* Initialize the OFReader */
            ofReader.parse(executable);
            ofReader.parseSymbols();

            /*
             * Close the reader to release the file handle. The reader will
             * reopen the file when a string lookup occurs.
             */
            ofReader.close();
        }
        /*
         * If there was a problem creating the OFReader, use the
         * StringReader instead.
         */
        catch (e) {
            print("Caught an exception while initializing the object "
                  + "file reader:\n" + e);
            ofReader = Model.$private.strReader;
        }
    }
    /*
     * If the target doesn't define an object file reader, use the
     * string reader.
     */
    else {
        print("The target does not specify an object file reader; using the "
              + "dynamic string reader instead.");
        ofReader = Model.$private.strReader;
    }

    /* Store the object file reader in the Model. */
    Model.$private.ofReader = ofReader;

    /* Initialize the formatter's OFReader */
    xdc.jre.xdc.rta.Formatter.setOFReader(ofReader);

    return (ofReader);
}

/*
 *  ======== reset ========
 */
function reset()
{
    var Program = xdc.useModule('xdc.rov.Program');
    Program.resetMods();
    Program.$$bind('moduleNames', undefined);
    Program.$$bind('build', undefined);
    Program.$$bind('$modules', undefined);
    Program.$$bind('_decoder', undefined);
}

/*
 *  ======== getISymbolTableInst ========
 */
function getISymbolTableInst()
{
    return (this.$private.sym);
}

/*
 *  ======== getMemoryImageInst ========
 */
function getMemoryImageInst()
{
    return (this.$private.mem);
}

/*
 *  ======== getICallBackInst ========
 */
function getICallBackInst()
{
    return (this.$private.callBack);
}

/*
 *  ======== getICallStackInst ========
 *  Called by clients to get the optional call stack parser.
 *
 *  Returns `null` in the event that there is no call stack parser; i.e.,
 *  there is no implementation of this functionality in the current
 *  `Model` context.
 */
function getICallStackInst()
{
    return (this.$private.callStack);
}

/*
 *  ======== getRecap ========
 */
function getRecap(execPath)
{
    var rInst = new Packages.xdc.rta.Recap();
    var recapFile;
    noRuntime = false;
    try {
        recapFile = rInst.locateRecap(execPath, ".rov.xs");
        noRuntime = false;
    }
    catch (e) {
        recapFile = "xdc/rov/noruntime.rov.xs";
        noRuntime = true;
    }

    var recap = xdc.loadCapsule(recapFile);
    if (noRuntime) {
        var modules = {};
        for (var mname in recap.$modules) {
            if (mname == "xdc.runtime.System"
                || mname == "xdc.rov.runtime.Monitor") {
                modules[mname] = recap.$modules[mname];
            }
        }
        recap.$modules = modules;
    }
    this.$private.recap = recap;

    initOFReader(execPath);

    if (noRuntime == true) {
        var build = {};
        var elfTarget = this.$private.ofReader.getTarget();
        var targ = {
            binaryParser: "xdc.targets.omf.Elf",
            bitsPerChar: elfTarget.charsize * 8,
            model: {
                endian: "little",
                shortEnums: null,
                dataModel: null,
                codeModel: null
            }
        };
        targ.vendor = elfTarget.vendor;
        if (elfTarget.bigendian == true) {
            targ.model.endian = "big";
        }
        if (elfTarget.architecture != undefined) {
            switch (elfTarget.architecture) {
                case 4:
                    targ.isa = "v5T";
                    break;
                case 10:
                    if (elfTarget.profile == 77) {
                        targ.isa = "v7M";
                    }
                    else if (elfTarget.profile == 65) {
                        targ.isa = "v7A";
                    }
                    else if (elfTarget.profile == 82) {
                        targ.isa = "v7R";
                    }
                    break;
                case 13:
                    targ.isa = "v7M4";
                    break;
                case 17:
                    targ.isa = "v8M";
                    break;
            }
            if (elfTarget.FP != undefined && elfTarget.FP != 0) {
                targ.hardFP = 1;
                switch (elfTarget.FP) {
                    case 3:
                        targ.FP = "fpv3";
                        break;
                    case 4:
                        targ.FP = "fpv3-sp-d16";
                        break;
                    case 6:
                        targ.FP = "fpv4-sp-d16";
                        break;
                    case 8:
                        targ.FP = "fpv5-sp-d16";
                        break;
                    default:
                        targ.FP = "" + elfTarget.FP;
                        break;
                }
            }
            if (elfTarget.shortEnums == 1) {
                targ.model.shortEnums = true;
            }
            else if (elfTarget.shortEnums == 2 || elfTarget.shortEnums == 3) {
                targ.model.shortEnums = false;
            }
        }
        var stdTypes = recap.stdTypes[elfTarget.machine];
        if (stdTypes == null) {
            throw new Error("ROV cannot detect target architecture for the "
                + "executable " + execPath);
        }
        targ.stdTypes = stdTypes;
        build.target = targ;
        recap.build = build;
    }

    return (recap);
}

/*
 *  ======== getIOFReaderInst ========
 */
function getIOFReaderInst()
{
    return (this.$private.ofReader);
}

/*
 * ======== getModuleList ========
 */
function getModuleList()
{
    /* Check if the module list has already been computed. */
    if (this.$private.modList) {
        return (this.$private.modList);
    }

    var root = {name: "ModuleList", modules: [], subPkgs: []};
    root.children = new Array();

    var pkg = root;

    /* For each module in the system... */
    for (var i = 0; i < Program.moduleNames.length; i++) {

        /* Break the module name into packages */
        var names = Program.moduleNames[i].split(".");

        for (var j = 0; j < names.length; j++) {
            var fullName = getFullName(names, j);

            /* If this is a module... */
            if (j == (names.length - 1)) {
                var modDesc = Program.getModuleDesc(fullName);

                var module = {};
                module.name = names[j];
                module.fullName = fullName;
                module.loadFailed = modDesc.loadFailed;
                module.loadFailedMsg = modDesc.loadFailedMsg;
                module.tabs = Program.getSupportedTabs(fullName);
                pkg.modules[pkg.modules.length] = module;
                continue;
            }

            /* If the package hasn't already been created */
            var index;
            if ((index = indexOfChild(pkg, fullName)) == -1) {
                var newPkg = {
                                name: names[j],
                                fullName: fullName,
                                modules: [],
                                subPkgs: []
                             };
                pkg.subPkgs[pkg.subPkgs.length] = newPkg;
                pkg = newPkg;
            }
            else {
                pkg = pkg.subPkgs[index];
            }
        }

        /* Start back from the root. */
        pkg = root;
    }

    /* Store off the computed module list. */
    this.$private.modList = root;

    return (root);
}

/*
 *  ======== getFullName ========
 *  Takes the array of names created by splitting a module's name
 *  by the periods '.' and finds the package name referenced at
 *  the given index.
 *  For example, for the module xdc.runtime.HeapStd, index 1 will return
 *  "xdc.runtime".
 */
function getFullName(names, index)
{
    var pkgName = "";
    for (var i = 0; i <= index; i++) {
        if (i == 0) {
            pkgName += names[i];
        }
        else {
            pkgName += "." + names[i];
        }
    }
    return (pkgName);
}

/*
 *  ======== getStartFileList ========
 */
function getStartFileList()
{
    return (this.$private.files);
}

/*
 *  ======== setICallStackInst ========
 *  Called only during Model initialization
 *
 *  This method is called to "bind" an optional stack call stack parser
 *  and is called by the same client that calls Model.start().
 */
function setICallStackInst(callStack)
{
    this.$private.callStack = callStack;
}

/*
 *  ======== indexOfChild ========
 */
function indexOfChild(pkg, name)
{
    for (var i = 0; i < pkg.subPkgs.length; i++) {
        if (pkg.subPkgs[i].fullName.equals(name)) {
            return (i);
        }
    }

    return (-1);
}

/*
 *  ======== setFullName ========
 *
 *  From an ROV module name, which may or may not contain a namespace name
 *  separated by "::", creates <namespace>.<short module name>. We add '.' to
 *  conform to RTSC fully qualified names that separate the package name and
 *  the module name with '.' for RTSC ROV.
 *  The default ROV namespace is "Global". If there is a clash, where
 *  two modules have the same full name, we add numbers to the namespace name.
 */
function setFullName(fullname) {
    var namespace = "Global";
    var shortname = fullname;
    var splitstr = fullname.match(/(.*)::([^:]+)$/);
    if (splitstr != null) {
        shortname = splitstr[2];
        if (splitstr[1].length > 0) {
            namespace = splitstr[1];
        }
    }
    var modname;

    modname = namespace + "." + shortname;
    var cnt = 1;
    while (cmodules[modname] != undefined) {
        modname = namespace + cnt++ + "." + shortname;
    };
    return (modname);
}

/*
 *  ======== readConfig ========
 *  An executable can have an ROV config file found next to the executable
 *  or in a directory above.
 */
function readConfig(executable)
{
    var files = [];
    var sysConfig = locateSysconfigFile(executable);
    if (sysConfig != "") {
        var sconfig = xdc.loadCapsule(sysConfig);
        files.push(sconfig.$path);
        var list = sconfig.crovFiles;
        for (var k = 0; k < list.length; k++) {
            var modCaps = {};
            if (xdc.findFile(list[k]) != null) {
                try {
                    modCaps = xdc.loadCapsule(list[k]);
                }
                catch (e) {
                   throw new Error("Error in " + xdc.findFile(list[k])
                       + ": " + e);
                }
            }
            else {
                /* ignore missing capsules; proceed with what's possible */
                Program.debugPrint("Warning: Can't find " + list[k]
                                   + " along the path: " + xdc.curPath());
            }

            var mod = {};
            if (modCaps.moduleName != null && modCaps.viewMap != null) {
                mod.name = setFullName(modCaps.moduleName);
                mod.viewMap = modCaps.viewMap;
                mod.argsMap = modCaps.argsMap;
                mod.capsule = modCaps;
                Program.addCMod(mod);
                cmodules[mod.name] = 1;
            }
        }
    }

    var rovConfig = locateRovFile(executable, ".rov.js");
    if (rovConfig != "") {
        //try {
            var config = xdc.loadCapsule(rovConfig);
            files.push(config.$path);
            /* This code reads an array of declared constructed objects from
             * a ROV configuration file with the .rov.js extension.
             *  Example:
             *  var constructedObjects = [
             *      {
             *          "type": "ti_sysbios_knl_Task_Struct",
             *          "name": "tStruct",
             *      },
             *      {
             *          "type": "ti_sysbios_knl_Task_Struct",
             *          "name": "tStruct2",
             *      },
             *      {
             *          "type": "ti_sysbios_knl_Semaphore_Struct",
             *          "name": "sem",
             *      },
             * ];
             *
             * The .rov.js file should have the same name as the executable
             * (.out) and can be in the same directory as, one directory level
             * above or two directory levels above the executable.
             */
            var constructed = config.constructedObjects;
            if (constructed != null) {
                var constructInstArr = [];
                /* Run through all the user specified construct objects */
                for (var i = 0; i < constructed.length; i++) {
                    var varObj = {};
                    varObj.name = constructed[i].name;
                    varObj.type = constructed[i].type;
                    varObj.addr = constructed[i].addr;
                    varObj.offset = 0;
                    if (constructed[i].offset != undefined) {
                        varObj.offset = constructed[i].offset;
                        varObj.name = varObj.name + "." + varObj.offset;
                    }

                    /* Add it to an Array */
                    constructInstArr[varObj.name] = varObj;
                }
                /* Add it to the Program instance for later use */
                Program.$$bind('$constructInst', constructInstArr);
            }

            var extraPkgs = config.additionalPackages;
            var path = xdc.curPath();
            var dirArray = path.split(';');
            for (var i = 0; i < extraPkgs.length; i++) {
                var pkg = extraPkgs[i].replace(/\./g, "/");
                for (var j = 0; j < dirArray.length; j++) {
                    var p = dirArray[j] + '/' + pkg;
                    var File = xdc.useModule('xdc.services.io.File');
                    if (File.isDirectory(p)) {
                        var rovFiles = File.ls(p, "rov.js");
                        for (var k = 0; k < rovFiles.length; k++) {
                            var modCaps = xdc.loadCapsule(
                                p + '/' + rovFiles[k]);
                            var mod = {};
                            if (modCaps.moduleName != null
                                && modCaps.viewMap != null) {
                                mod.name = setFullName(modCaps.moduleName);
                                mod.viewMap = modCaps.viewMap;
                                mod.argsMap = modCaps.argsMap;
                                mod.capsule = modCaps;
                                Program.addCMod(mod);
                                cmodules[mod.name] = 1;
                            }
                        }
                    }
                }
            }
        //}
        //catch(e) {
            Program.debugPrint("Cannot load " + rovConfig);
        //}
    }
    return (files);
}

/*
 *  ======== fetchConstructObjects ========
 *  Reads constructed objects from the object file
 */
function fetchConstructObjects(executable)
{
    var constructInstArr = [];
    var binaryParser = "";
    var ofReader = null;

    /* Read from the object file */
    try {
        binaryParser = Program.build.target.binaryParser;
        if (binaryParser !== undefined) {

            /* Parse the package name from the class name so we can load it. */
            var parserPackage =
                binaryParser.substring(0, binaryParser.lastIndexOf('.'));

            /* Load the parser's package */
            xdc.loadPackage(parserPackage);

            /* Get the parser class */
            var binaryParserClass = Packages[binaryParser];

            /* Get the Global Variables */
            ofReader = new binaryParserClass();
            ofReader.parse(executable);

            var varList = ofReader.getGlobalVariablesByType(".*_Struct$");
            var semList =
                ofReader.getGlobalVariablesByType(".*sysbios_Semaphore$");
            ofReader.close(); /* close file handle */

            /* Run through the list and add only constructed objects */
            for (var i = 0; i < varList.length; i++) {
                var varObj = {};
                varObj.name = varList[i].name;
                varObj.type = varList[i].type;
                if (varObj.type == "SemaphoreP_Struct"
                    || varObj.type == "HwiP_Struct"
                    || varObj.type == "SwiP_Struct"
                    || varObj.type == "ClockP_Struct") {
                    varObj.type = "ti_sysbios_knl_"
                        + varObj.type.replace("P_Struct", "_Struct");
                }
                varObj.offset = 0;
                if (varList[i].offset != undefined) {
                    varObj.offset = varList[i].offset;
                }
                constructInstArr[varObj.name] = varObj;
            }
            for (var i = 0; i < semList.length; i++) {
                var varObj = {};
                varObj.name = semList[i].name;
                varObj.type = "ti_sysbios_knl_Semaphore_Struct";
                varObj.offset = 0;
                if (semList[i].offset != undefined) {
                    varObj.offset = semList[i].offset;
                }
                constructInstArr[varObj.name] = varObj;
            }
        }
    }
    catch (e) {
        if (ofReader != null) {
            ofReader.close();
        }
        Program.debugPrint("The binary parser '" + binaryParser + "' could not"
                           + " get global variables info from " + executable);
    }
    /* Add it to the Program instance for later use */
    Program.$$bind('$constructInst', constructInstArr);
}

/*
 *  ======== locate the ROV config file ========
 *  Find a file with the exe's name but with a ".rov.js" extension
 */
 function locateRovFile(mainExec, extension)
{
    try {
        var ePath = mainExec.replace(/\\/g, '/');
        var fPath = ePath.substring(0, ePath.lastIndexOf('/') + 1);
        var fName = ePath.substring(ePath.lastIndexOf('/') + 1);
        fName = fName.substring(0, fName.lastIndexOf('.')) + extension;

        var locatedFile = "";
        /* Search the file */
        var File = xdc.useModule('xdc.services.io.File');
        if (File.exists(fPath + fName)) {
            locatedFile = fPath + fName;
        }
        else if (File.exists(fPath + "../" + fName)) {
            locatedFile = fPath + "../" + fName;
        }
        if (locatedFile != "") {
            return (String(File.getCanonicalPath(locatedFile)));
        }
    }
    catch(e) {
        Program.debugPrint("Cannot open " + fName + ". " + e.toString());
    }
    return("");
}

/*
 *  ======== locate the sysconfig ROV file ========
 */
function locateSysconfigFile(mainExec) {
    var sysconfigFile = "syscfg_c.rov.xs";
    try {
        var ePath = mainExec.replace(/\\/g, '/');
        var fPath = ePath.substring(0, ePath.lastIndexOf('/') + 1);

        /* Search for the file */
        var locatedFile = "";
        var File = xdc.useModule('xdc.services.io.File');
        if (File.exists(fPath + sysconfigFile)) {
            locatedFile = fPath + sysconfigFile;
        }
        else if (File.exists(fPath + "syscfg/" + sysconfigFile)) {
            locatedFile = fPath + "syscfg/" + sysconfigFile;
        }
        else if (File.exists(fPath + "/../" + sysconfigFile)) {
            locatedFile = fPath + "/../" + sysconfigFile;
        }
        else if (File.exists(fPath + "/../syscfg/" + sysconfigFile)) {
            locatedFile = fPath + "/../syscfg/" + sysconfigFile;
        }
        else if (File.exists(fPath + "/../../" + sysconfigFile)) {
            locatedFile = fPath + "/../../" + sysconfigFile;
        }
        else if (File.exists(fPath + "/../../syscfg/" + sysconfigFile)) {
            locatedFile = fPath + "/../../syscfg/" + sysconfigFile;
        }
        if (locatedFile != "") {
            return (String(File.getCanonicalPath(locatedFile)));
        }
    }
    catch(e) {
        Program.debugPrint("Cannot open " + sysconfigFile + ": "
            + e.toString());
    }
    return("");

}
/*
 *  @(#) xdc.rov; 1, 0, 1,0; 10-3-2020 15:24:48; /db/ztree/library/trees/xdc/xdc-K04/src/packages/
 */

