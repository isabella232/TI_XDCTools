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

#ifndef xdc_runtime_IModule__include
#define xdc_runtime_IModule__include

#ifndef __nested__
#define __nested__
#define xdc_runtime_IModule__top__
#endif

#ifndef __extern
#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif
#endif

#define xdc_runtime_IModule___VERS 200


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/package/package.defs.h>

#include <xdc/runtime/Types.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/Error.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct xdc_runtime_IModule_Fxns__ {
    const xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2* __sysp;
    xdc_runtime_Types_SysFxns2 __sfxns;
};
#ifndef xdc_runtime_IModule_Module__BASE__CR

/* Interface__BASE__C */
__extern const xdc_runtime_Types_Base xdc_runtime_IModule_Interface__BASE__C;
#else
#define xdc_runtime_IModule_Interface__BASE__C (*((xdc_runtime_Types_Base *)(xdcRomConstPtr + xdc_runtime_IModule_Interface__BASE__C_offset)))
#endif


/*
 * ======== FUNCTION STUBS ========
 */

/* Module_id */
static inline xdc_runtime_Types_ModuleId xdc_runtime_IModule_Module_id(xdc_runtime_IModule_Module mod);
static inline xdc_runtime_Types_ModuleId xdc_runtime_IModule_Module_id(xdc_runtime_IModule_Module mod)
{
    return mod->__sysp->__mid;
}


/*
 * ======== FUNCTION SELECTORS ========
 */


/*
 * ======== EPILOGUE ========
 */

#ifdef xdc_runtime_IModule__top__
#undef __nested__
#endif

#endif /* xdc_runtime_IModule__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(xdc_runtime_IModule__nolocalnames)

#ifndef xdc_runtime_IModule__localnames__done
#define xdc_runtime_IModule__localnames__done

/* module prefix */
#define IModule_Module xdc_runtime_IModule_Module
#define IModule_Module_name xdc_runtime_IModule_Module_name

#endif /* xdc_runtime_IModule__localnames__done */
#endif
/*
 *  @(#) xdc.runtime; 2, 1, 0,0; 10-3-2020 15:24:56; /db/ztree/library/trees/xdc/xdc-K04/src/packages/
 */

