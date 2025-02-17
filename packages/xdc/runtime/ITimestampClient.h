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

#ifndef xdc_runtime_ITimestampClient__include
#define xdc_runtime_ITimestampClient__include

#ifndef __nested__
#define __nested__
#define xdc_runtime_ITimestampClient__top__
#endif

#ifndef __extern
#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif
#endif

#define xdc_runtime_ITimestampClient___VERS 200


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/package/package.defs.h>

#include <xdc/runtime/IModule.h>
#include <xdc/runtime/Types.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct xdc_runtime_ITimestampClient_Fxns__ {
    const xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2* __sysp;
    xdc_Bits32 (*get32)(void);
    xdc_Void (*get64)(xdc_runtime_Types_Timestamp64* result);
    xdc_Void (*getFreq)(xdc_runtime_Types_FreqHz* freq);
    xdc_runtime_Types_SysFxns2 __sfxns;
};
#ifndef xdc_runtime_ITimestampClient_Module__BASE__CR

/* Interface__BASE__C */
__extern const xdc_runtime_Types_Base xdc_runtime_ITimestampClient_Interface__BASE__C;
#else
#define xdc_runtime_ITimestampClient_Interface__BASE__C (*((xdc_runtime_Types_Base *)(xdcRomConstPtr + xdc_runtime_ITimestampClient_Interface__BASE__C_offset)))
#endif


/*
 * ======== FUNCTION STUBS ========
 */

/* Module_id */
static inline xdc_runtime_Types_ModuleId xdc_runtime_ITimestampClient_Module_id(xdc_runtime_ITimestampClient_Module mod);
static inline xdc_runtime_Types_ModuleId xdc_runtime_ITimestampClient_Module_id(xdc_runtime_ITimestampClient_Module mod)
{
    return mod->__sysp->__mid;
}

/* get32 */
static inline xdc_Bits32 xdc_runtime_ITimestampClient_get32(xdc_runtime_ITimestampClient_Module mod);
static inline xdc_Bits32 xdc_runtime_ITimestampClient_get32( xdc_runtime_ITimestampClient_Module mod )
{
    return mod->get32();
}

/* get64 */
static inline xdc_Void xdc_runtime_ITimestampClient_get64(xdc_runtime_ITimestampClient_Module mod, xdc_runtime_Types_Timestamp64 *result);
static inline xdc_Void xdc_runtime_ITimestampClient_get64( xdc_runtime_ITimestampClient_Module mod, xdc_runtime_Types_Timestamp64 *result )
{
    mod->get64(result);
}

/* getFreq */
static inline xdc_Void xdc_runtime_ITimestampClient_getFreq(xdc_runtime_ITimestampClient_Module mod, xdc_runtime_Types_FreqHz *freq);
static inline xdc_Void xdc_runtime_ITimestampClient_getFreq( xdc_runtime_ITimestampClient_Module mod, xdc_runtime_Types_FreqHz *freq )
{
    mod->getFreq(freq);
}


/*
 * ======== FUNCTION SELECTORS ========
 */

/* These functions return function pointers for module and instance functions.
 * The functions accept modules and instances declared as types defined in this
 * interface, but they return functions defined for the actual objects passed
 * as parameters. These functions are not invoked by any generated code or
 * XDCtools internal code.
 */

/* get32_{FxnT,fxnP} */
typedef xdc_Bits32 (*xdc_runtime_ITimestampClient_get32_FxnT)(void);
static inline xdc_runtime_ITimestampClient_get32_FxnT xdc_runtime_ITimestampClient_get32_fxnP(xdc_runtime_ITimestampClient_Module mod);
static inline xdc_runtime_ITimestampClient_get32_FxnT xdc_runtime_ITimestampClient_get32_fxnP(xdc_runtime_ITimestampClient_Module mod)
{
    return (xdc_runtime_ITimestampClient_get32_FxnT)mod->get32;
}

/* get64_{FxnT,fxnP} */
typedef xdc_Void (*xdc_runtime_ITimestampClient_get64_FxnT)(xdc_runtime_Types_Timestamp64* result);
static inline xdc_runtime_ITimestampClient_get64_FxnT xdc_runtime_ITimestampClient_get64_fxnP(xdc_runtime_ITimestampClient_Module mod);
static inline xdc_runtime_ITimestampClient_get64_FxnT xdc_runtime_ITimestampClient_get64_fxnP(xdc_runtime_ITimestampClient_Module mod)
{
    return (xdc_runtime_ITimestampClient_get64_FxnT)mod->get64;
}

/* getFreq_{FxnT,fxnP} */
typedef xdc_Void (*xdc_runtime_ITimestampClient_getFreq_FxnT)(xdc_runtime_Types_FreqHz* freq);
static inline xdc_runtime_ITimestampClient_getFreq_FxnT xdc_runtime_ITimestampClient_getFreq_fxnP(xdc_runtime_ITimestampClient_Module mod);
static inline xdc_runtime_ITimestampClient_getFreq_FxnT xdc_runtime_ITimestampClient_getFreq_fxnP(xdc_runtime_ITimestampClient_Module mod)
{
    return (xdc_runtime_ITimestampClient_getFreq_FxnT)mod->getFreq;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef xdc_runtime_ITimestampClient__top__
#undef __nested__
#endif

#endif /* xdc_runtime_ITimestampClient__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(xdc_runtime_ITimestampClient__nolocalnames)

#ifndef xdc_runtime_ITimestampClient__localnames__done
#define xdc_runtime_ITimestampClient__localnames__done

/* module prefix */
#define ITimestampClient_Module xdc_runtime_ITimestampClient_Module
#define ITimestampClient_get32 xdc_runtime_ITimestampClient_get32
#define ITimestampClient_get32_fxnP xdc_runtime_ITimestampClient_get32_fxnP
#define ITimestampClient_get32_FxnT xdc_runtime_ITimestampClient_get32_FxnT
#define ITimestampClient_get64 xdc_runtime_ITimestampClient_get64
#define ITimestampClient_get64_fxnP xdc_runtime_ITimestampClient_get64_fxnP
#define ITimestampClient_get64_FxnT xdc_runtime_ITimestampClient_get64_FxnT
#define ITimestampClient_getFreq xdc_runtime_ITimestampClient_getFreq
#define ITimestampClient_getFreq_fxnP xdc_runtime_ITimestampClient_getFreq_fxnP
#define ITimestampClient_getFreq_FxnT xdc_runtime_ITimestampClient_getFreq_FxnT
#define ITimestampClient_Module_name xdc_runtime_ITimestampClient_Module_name

#endif /* xdc_runtime_ITimestampClient__localnames__done */
#endif
/*
 *  @(#) xdc.runtime; 2, 1, 0,0; 10-3-2020 15:24:56; /db/ztree/library/trees/xdc/xdc-K04/src/packages/
 */

