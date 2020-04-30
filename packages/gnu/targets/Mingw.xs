/*
 *  ======== Mingw.archive ========
 */
function archive(goal)
{
    var result = this.$super.archive.$fxn.call(this, goal);
    var path = ".;$(rootDir)/bin;$(PATH)";
    result.path = path.split(";"); 
    return (result);
}

/*
 *  ======== Mingw.compile ========
 */
function compile(goal) {
    var result = this.$super.compile.$fxn.call(this, goal, false);
    var path = ".;$(rootDir)/bin;$(PATH)";
    result.path = path.split(";"); 
    return (result);
}


/*
 *  ======== Mingw.link ========
 */
function link(goal) {
    var result = this.$super.link.$fxn.call(this, goal);
    var path = ".;$(rootDir)/bin;$(PATH)";
    result.path = path.split(";"); 
    return (result);
}

/*
 *  ======== Mingw.scompile ========
 */
function scompile(goal) {
    var result = this.$super.scompile.$fxn.call(this, goal, true);
    var path = ".;$(rootDir)/bin;$(PATH)";
    result.path = path.split(";"); 
    return (result);
}
/*
 *  @(#) gnu.targets; 1, 0, 1,0; 2-9-2020 18:50:41; /db/ztree/library/trees/xdc/xdc-I08/src/targets/
 */
