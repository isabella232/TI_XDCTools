/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-K04
 */

/*
 * ======== GENERATED SECTIONS ========
 *
 *     PROLOGUE
 *     INCLUDES
 *
 *     PER-INSTANCE TYPES
 *     VIRTUAL FUNCTIONS
 *     FUNCTION STUBS
 *     FUNCTION SELECTORS
 *
 *     EPILOGUE
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef xdc_runtime_IInstance__include
#define xdc_runtime_IInstance__include

#ifndef __nested__
#define __nested__
#define xdc_runtime_IInstance__top__
#endif

#ifndef __extern
#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif
#endif

#define xdc_runtime_IInstance___VERS 200


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/package/package.defs.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct xdc_runtime_IInstance_Params {
    size_t __size;
    xdc_CString name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct xdc_runtime_IInstance_Fxns__ {
    const xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2* __sysp;
    xdc_runtime_Types_SysFxns2 __sfxns;
};
#ifndef xdc_runtime_IInstance_Module__BASE__CR

/* Interface__BASE__C */
__extern const xdc_runtime_Types_Base xdc_runtime_IInstance_Interface__BASE__C;
#else
#define xdc_runtime_IInstance_Interface__BASE__C (*((xdc_runtime_Types_Base *)(xdcRomConstPtr + xdc_runtime_IInstance_Interface__BASE__C_offset)))
#endif


/*
 * ======== FUNCTION STUBS ========
 */

/* create */
xdc__CODESECT(xdc_runtime_IInstance_create, "xdc_runtime_IInstance_create")
__extern xdc_runtime_IInstance_Handle xdc_runtime_IInstance_create(xdc_runtime_IInstance_Module mod, const xdc_runtime_IInstance_Params *prms, xdc_runtime_Error_Block *eb);

/* delete */
xdc__CODESECT(xdc_runtime_IInstance_delete, "xdc_runtime_IInstance_delete")
__extern xdc_Void xdc_runtime_IInstance_delete(xdc_runtime_IInstance_Handle *inst);

/* Handle_to_Module */
static inline xdc_runtime_IInstance_Module xdc_runtime_IInstance_Handle_to_Module(xdc_runtime_IInstance_Handle inst);
static inline xdc_runtime_IInstance_Module xdc_runtime_IInstance_Handle_to_Module(xdc_runtime_IInstance_Handle inst)
{
    return inst->__fxns;
}

/* Handle_label */
static inline xdc_runtime_Types_Label *xdc_runtime_IInstance_Handle_label(xdc_runtime_IInstance_Handle inst, xdc_runtime_Types_Label *lab);
static inline xdc_runtime_Types_Label *xdc_runtime_IInstance_Handle_label(xdc_runtime_IInstance_Handle inst, xdc_runtime_Types_Label *lab)
{
    return inst->__fxns->__sysp->__label(inst, lab);
}

/* Module_id */
static inline xdc_runtime_Types_ModuleId xdc_runtime_IInstance_Module_id(xdc_runtime_IInstance_Module mod);
static inline xdc_runtime_Types_ModuleId xdc_runtime_IInstance_Module_id(xdc_runtime_IInstance_Module mod)
{
    return mod->__sysp->__mid;
}


/*
 * ======== FUNCTION SELECTORS ========
 */


/*
 * ======== EPILOGUE ========
 */

#ifdef xdc_runtime_IInstance__top__
#undef __nested__
#endif

#endif /* xdc_runtime_IInstance__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(xdc_runtime_IInstance__nolocalnames)

#ifndef xdc_runtime_IInstance__localnames__done
#define xdc_runtime_IInstance__localnames__done

/* module prefix */
#define IInstance_Instance xdc_runtime_IInstance_Instance
#define IInstance_Handle xdc_runtime_IInstance_Handle
#define IInstance_Module xdc_runtime_IInstance_Module
#define IInstance_Params xdc_runtime_IInstance_Params
#define IInstance_Module_name xdc_runtime_IInstance_Module_name
#define IInstance_delete xdc_runtime_IInstance_delete
#define IInstance_Handle_label xdc_runtime_IInstance_Handle_label
#define IInstance_Handle_to_Module xdc_runtime_IInstance_Handle_to_Module

#endif /* xdc_runtime_IInstance__localnames__done */
#endif
/*
 *  @(#) xdc.runtime; 2, 1, 0,0; 10-3-2020 15:24:56; /db/ztree/library/trees/xdc/xdc-K04/src/packages/
 */

