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
 *     CREATE ARGS
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

#ifndef xdc_runtime_knl_IThreadSupport__include
#define xdc_runtime_knl_IThreadSupport__include

#ifndef __nested__
#define __nested__
#define xdc_runtime_knl_IThreadSupport__top__
#endif

#ifndef __extern
#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif
#endif

#define xdc_runtime_knl_IThreadSupport___VERS 200


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <xdc/runtime/knl/package/package.defs.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/IModule.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* Priority */
enum xdc_runtime_knl_IThreadSupport_Priority {
    xdc_runtime_knl_IThreadSupport_Priority_INVALID,
    xdc_runtime_knl_IThreadSupport_Priority_LOWEST,
    xdc_runtime_knl_IThreadSupport_Priority_BELOW_NORMAL,
    xdc_runtime_knl_IThreadSupport_Priority_NORMAL,
    xdc_runtime_knl_IThreadSupport_Priority_ABOVE_NORMAL,
    xdc_runtime_knl_IThreadSupport_Priority_HIGHEST
};
typedef enum xdc_runtime_knl_IThreadSupport_Priority xdc_runtime_knl_IThreadSupport_Priority;

/* INVALID_OS_PRIORITY */
#define xdc_runtime_knl_IThreadSupport_INVALID_OS_PRIORITY (0)

/* GETPRI_FAILED */
#define xdc_runtime_knl_IThreadSupport_GETPRI_FAILED (-2)

/* CompStatus */
enum xdc_runtime_knl_IThreadSupport_CompStatus {
    xdc_runtime_knl_IThreadSupport_CompStatus_ERROR = -2,
    xdc_runtime_knl_IThreadSupport_CompStatus_LOWER = -1,
    xdc_runtime_knl_IThreadSupport_CompStatus_EQUAL = 0,
    xdc_runtime_knl_IThreadSupport_CompStatus_HIGHER = 1
};
typedef enum xdc_runtime_knl_IThreadSupport_CompStatus xdc_runtime_knl_IThreadSupport_CompStatus;

/* RunFxn */
typedef xdc_Void (*xdc_runtime_knl_IThreadSupport_RunFxn)(xdc_IArg arg1);

/* Stat */
struct xdc_runtime_knl_IThreadSupport_Stat {
    xdc_SizeT stackSize;
    xdc_SizeT stackUsed;
};


/*
 * ======== CREATE ARGS ========
 */

/* Args__create */
typedef struct xdc_runtime_knl_IThreadSupport_Args__create {
    xdc_runtime_knl_IThreadSupport_RunFxn fxn;
} xdc_runtime_knl_IThreadSupport_Args__create;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct xdc_runtime_knl_IThreadSupport_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    xdc_IArg arg;
    xdc_runtime_knl_IThreadSupport_Priority priority;
    xdc_Int osPriority;
    xdc_SizeT stackSize;
    xdc_Ptr tls;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct xdc_runtime_knl_IThreadSupport_Fxns__ {
    const xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2* __sysp;
    xdc_runtime_knl_IThreadSupport_Handle (*self)(xdc_runtime_Error_Block* eb);
    xdc_Bool (*start)(xdc_runtime_Error_Block* eb);
    xdc_Bool (*yield)(xdc_runtime_Error_Block* eb);
    xdc_Int (*compareOsPriorities)(xdc_Int p1, xdc_Int p2, xdc_runtime_Error_Block* eb);
    xdc_Bool (*sleep)(xdc_UInt timeout, xdc_runtime_Error_Block* eb);
    xdc_Bool (*join)(void* inst, xdc_runtime_Error_Block* eb);
    xdc_runtime_knl_IThreadSupport_Priority (*getPriority)(void* inst, xdc_runtime_Error_Block* eb);
    xdc_Bool (*setPriority)(void* inst, xdc_runtime_knl_IThreadSupport_Priority newPri, xdc_runtime_Error_Block* eb);
    xdc_Int (*getOsPriority)(void* inst, xdc_runtime_Error_Block* eb);
    xdc_Bool (*setOsPriority)(void* inst, xdc_Int newPri, xdc_runtime_Error_Block* eb);
    xdc_Ptr (*getOsHandle)(void* inst);
    xdc_Ptr (*getTls)(void* inst);
    xdc_Void (*setTls)(void* inst, xdc_Ptr tls);
    xdc_Bool (*stat)(void* inst, xdc_runtime_knl_IThreadSupport_Stat* buf, xdc_runtime_Error_Block* eb);
    xdc_runtime_Types_SysFxns2 __sfxns;
};
#ifndef xdc_runtime_knl_IThreadSupport_Module__BASE__CR

/* Interface__BASE__C */
__extern const xdc_runtime_Types_Base xdc_runtime_knl_IThreadSupport_Interface__BASE__C;
#else
#define xdc_runtime_knl_IThreadSupport_Interface__BASE__C (*((xdc_runtime_Types_Base *)(xdcRomConstPtr + xdc_runtime_knl_IThreadSupport_Interface__BASE__C_offset)))
#endif


/*
 * ======== FUNCTION STUBS ========
 */

/* create */
xdc__CODESECT(xdc_runtime_knl_IThreadSupport_create, "xdc_runtime_knl_IThreadSupport_create")
__extern xdc_runtime_knl_IThreadSupport_Handle xdc_runtime_knl_IThreadSupport_create(xdc_runtime_knl_IThreadSupport_Module mod, xdc_runtime_knl_IThreadSupport_RunFxn fxn, const xdc_runtime_knl_IThreadSupport_Params *prms, xdc_runtime_Error_Block *eb);

/* delete */
xdc__CODESECT(xdc_runtime_knl_IThreadSupport_delete, "xdc_runtime_knl_IThreadSupport_delete")
__extern xdc_Void xdc_runtime_knl_IThreadSupport_delete(xdc_runtime_knl_IThreadSupport_Handle *inst);

/* Handle_to_Module */
static inline xdc_runtime_knl_IThreadSupport_Module xdc_runtime_knl_IThreadSupport_Handle_to_Module(xdc_runtime_knl_IThreadSupport_Handle inst);
static inline xdc_runtime_knl_IThreadSupport_Module xdc_runtime_knl_IThreadSupport_Handle_to_Module(xdc_runtime_knl_IThreadSupport_Handle inst)
{
    return inst->__fxns;
}

/* Handle_label */
static inline xdc_runtime_Types_Label *xdc_runtime_knl_IThreadSupport_Handle_label(xdc_runtime_knl_IThreadSupport_Handle inst, xdc_runtime_Types_Label *lab);
static inline xdc_runtime_Types_Label *xdc_runtime_knl_IThreadSupport_Handle_label(xdc_runtime_knl_IThreadSupport_Handle inst, xdc_runtime_Types_Label *lab)
{
    return inst->__fxns->__sysp->__label(inst, lab);
}

/* Module_id */
static inline xdc_runtime_Types_ModuleId xdc_runtime_knl_IThreadSupport_Module_id(xdc_runtime_knl_IThreadSupport_Module mod);
static inline xdc_runtime_Types_ModuleId xdc_runtime_knl_IThreadSupport_Module_id(xdc_runtime_knl_IThreadSupport_Module mod)
{
    return mod->__sysp->__mid;
}

/* self */
static inline xdc_runtime_knl_IThreadSupport_Handle xdc_runtime_knl_IThreadSupport_self(xdc_runtime_knl_IThreadSupport_Module mod, xdc_runtime_Error_Block *eb);
static inline xdc_runtime_knl_IThreadSupport_Handle xdc_runtime_knl_IThreadSupport_self( xdc_runtime_knl_IThreadSupport_Module mod, xdc_runtime_Error_Block *eb )
{
    return mod->self(eb);
}

/* start */
static inline xdc_Bool xdc_runtime_knl_IThreadSupport_start(xdc_runtime_knl_IThreadSupport_Module mod, xdc_runtime_Error_Block *eb);
static inline xdc_Bool xdc_runtime_knl_IThreadSupport_start( xdc_runtime_knl_IThreadSupport_Module mod, xdc_runtime_Error_Block *eb )
{
    return mod->start(eb);
}

/* yield */
static inline xdc_Bool xdc_runtime_knl_IThreadSupport_yield(xdc_runtime_knl_IThreadSupport_Module mod, xdc_runtime_Error_Block *eb);
static inline xdc_Bool xdc_runtime_knl_IThreadSupport_yield( xdc_runtime_knl_IThreadSupport_Module mod, xdc_runtime_Error_Block *eb )
{
    return mod->yield(eb);
}

/* compareOsPriorities */
static inline xdc_Int xdc_runtime_knl_IThreadSupport_compareOsPriorities(xdc_runtime_knl_IThreadSupport_Module mod, xdc_Int p1, xdc_Int p2, xdc_runtime_Error_Block *eb);
static inline xdc_Int xdc_runtime_knl_IThreadSupport_compareOsPriorities( xdc_runtime_knl_IThreadSupport_Module mod, xdc_Int p1, xdc_Int p2, xdc_runtime_Error_Block *eb )
{
    return mod->compareOsPriorities(p1, p2, eb);
}

/* sleep */
static inline xdc_Bool xdc_runtime_knl_IThreadSupport_sleep(xdc_runtime_knl_IThreadSupport_Module mod, xdc_UInt timeout, xdc_runtime_Error_Block *eb);
static inline xdc_Bool xdc_runtime_knl_IThreadSupport_sleep( xdc_runtime_knl_IThreadSupport_Module mod, xdc_UInt timeout, xdc_runtime_Error_Block *eb )
{
    return mod->sleep(timeout, eb);
}

/* join */
static inline xdc_Bool xdc_runtime_knl_IThreadSupport_join(xdc_runtime_knl_IThreadSupport_Handle inst, xdc_runtime_Error_Block *eb);
static inline xdc_Bool xdc_runtime_knl_IThreadSupport_join( xdc_runtime_knl_IThreadSupport_Handle inst, xdc_runtime_Error_Block *eb )
{
    return inst->__fxns->join((void*)inst, eb);
}

/* getPriority */
static inline xdc_runtime_knl_IThreadSupport_Priority xdc_runtime_knl_IThreadSupport_getPriority(xdc_runtime_knl_IThreadSupport_Handle inst, xdc_runtime_Error_Block *eb);
static inline xdc_runtime_knl_IThreadSupport_Priority xdc_runtime_knl_IThreadSupport_getPriority( xdc_runtime_knl_IThreadSupport_Handle inst, xdc_runtime_Error_Block *eb )
{
    return inst->__fxns->getPriority((void*)inst, eb);
}

/* setPriority */
static inline xdc_Bool xdc_runtime_knl_IThreadSupport_setPriority(xdc_runtime_knl_IThreadSupport_Handle inst, xdc_runtime_knl_IThreadSupport_Priority newPri, xdc_runtime_Error_Block *eb);
static inline xdc_Bool xdc_runtime_knl_IThreadSupport_setPriority( xdc_runtime_knl_IThreadSupport_Handle inst, xdc_runtime_knl_IThreadSupport_Priority newPri, xdc_runtime_Error_Block *eb )
{
    return inst->__fxns->setPriority((void*)inst, newPri, eb);
}

/* getOsPriority */
static inline xdc_Int xdc_runtime_knl_IThreadSupport_getOsPriority(xdc_runtime_knl_IThreadSupport_Handle inst, xdc_runtime_Error_Block *eb);
static inline xdc_Int xdc_runtime_knl_IThreadSupport_getOsPriority( xdc_runtime_knl_IThreadSupport_Handle inst, xdc_runtime_Error_Block *eb )
{
    return inst->__fxns->getOsPriority((void*)inst, eb);
}

/* setOsPriority */
static inline xdc_Bool xdc_runtime_knl_IThreadSupport_setOsPriority(xdc_runtime_knl_IThreadSupport_Handle inst, xdc_Int newPri, xdc_runtime_Error_Block *eb);
static inline xdc_Bool xdc_runtime_knl_IThreadSupport_setOsPriority( xdc_runtime_knl_IThreadSupport_Handle inst, xdc_Int newPri, xdc_runtime_Error_Block *eb )
{
    return inst->__fxns->setOsPriority((void*)inst, newPri, eb);
}

/* getOsHandle */
static inline xdc_Ptr xdc_runtime_knl_IThreadSupport_getOsHandle(xdc_runtime_knl_IThreadSupport_Handle inst);
static inline xdc_Ptr xdc_runtime_knl_IThreadSupport_getOsHandle( xdc_runtime_knl_IThreadSupport_Handle inst )
{
    return inst->__fxns->getOsHandle((void*)inst);
}

/* getTls */
static inline xdc_Ptr xdc_runtime_knl_IThreadSupport_getTls(xdc_runtime_knl_IThreadSupport_Handle inst);
static inline xdc_Ptr xdc_runtime_knl_IThreadSupport_getTls( xdc_runtime_knl_IThreadSupport_Handle inst )
{
    return inst->__fxns->getTls((void*)inst);
}

/* setTls */
static inline xdc_Void xdc_runtime_knl_IThreadSupport_setTls(xdc_runtime_knl_IThreadSupport_Handle inst, xdc_Ptr tls);
static inline xdc_Void xdc_runtime_knl_IThreadSupport_setTls( xdc_runtime_knl_IThreadSupport_Handle inst, xdc_Ptr tls )
{
    inst->__fxns->setTls((void*)inst, tls);
}

/* stat */
static inline xdc_Bool xdc_runtime_knl_IThreadSupport_stat(xdc_runtime_knl_IThreadSupport_Handle inst, xdc_runtime_knl_IThreadSupport_Stat *buf, xdc_runtime_Error_Block *eb);
static inline xdc_Bool xdc_runtime_knl_IThreadSupport_stat( xdc_runtime_knl_IThreadSupport_Handle inst, xdc_runtime_knl_IThreadSupport_Stat *buf, xdc_runtime_Error_Block *eb )
{
    return inst->__fxns->stat((void*)inst, buf, eb);
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

/* self_{FxnT,fxnP} */
typedef xdc_runtime_knl_IThreadSupport_Handle (*xdc_runtime_knl_IThreadSupport_self_FxnT)(xdc_runtime_Error_Block* eb);
static inline xdc_runtime_knl_IThreadSupport_self_FxnT xdc_runtime_knl_IThreadSupport_self_fxnP(xdc_runtime_knl_IThreadSupport_Module mod);
static inline xdc_runtime_knl_IThreadSupport_self_FxnT xdc_runtime_knl_IThreadSupport_self_fxnP(xdc_runtime_knl_IThreadSupport_Module mod)
{
    return (xdc_runtime_knl_IThreadSupport_self_FxnT)mod->self;
}

/* start_{FxnT,fxnP} */
typedef xdc_Bool (*xdc_runtime_knl_IThreadSupport_start_FxnT)(xdc_runtime_Error_Block* eb);
static inline xdc_runtime_knl_IThreadSupport_start_FxnT xdc_runtime_knl_IThreadSupport_start_fxnP(xdc_runtime_knl_IThreadSupport_Module mod);
static inline xdc_runtime_knl_IThreadSupport_start_FxnT xdc_runtime_knl_IThreadSupport_start_fxnP(xdc_runtime_knl_IThreadSupport_Module mod)
{
    return (xdc_runtime_knl_IThreadSupport_start_FxnT)mod->start;
}

/* yield_{FxnT,fxnP} */
typedef xdc_Bool (*xdc_runtime_knl_IThreadSupport_yield_FxnT)(xdc_runtime_Error_Block* eb);
static inline xdc_runtime_knl_IThreadSupport_yield_FxnT xdc_runtime_knl_IThreadSupport_yield_fxnP(xdc_runtime_knl_IThreadSupport_Module mod);
static inline xdc_runtime_knl_IThreadSupport_yield_FxnT xdc_runtime_knl_IThreadSupport_yield_fxnP(xdc_runtime_knl_IThreadSupport_Module mod)
{
    return (xdc_runtime_knl_IThreadSupport_yield_FxnT)mod->yield;
}

/* compareOsPriorities_{FxnT,fxnP} */
typedef xdc_Int (*xdc_runtime_knl_IThreadSupport_compareOsPriorities_FxnT)(xdc_Int p1, xdc_Int p2, xdc_runtime_Error_Block* eb);
static inline xdc_runtime_knl_IThreadSupport_compareOsPriorities_FxnT xdc_runtime_knl_IThreadSupport_compareOsPriorities_fxnP(xdc_runtime_knl_IThreadSupport_Module mod);
static inline xdc_runtime_knl_IThreadSupport_compareOsPriorities_FxnT xdc_runtime_knl_IThreadSupport_compareOsPriorities_fxnP(xdc_runtime_knl_IThreadSupport_Module mod)
{
    return (xdc_runtime_knl_IThreadSupport_compareOsPriorities_FxnT)mod->compareOsPriorities;
}

/* sleep_{FxnT,fxnP} */
typedef xdc_Bool (*xdc_runtime_knl_IThreadSupport_sleep_FxnT)(xdc_UInt timeout, xdc_runtime_Error_Block* eb);
static inline xdc_runtime_knl_IThreadSupport_sleep_FxnT xdc_runtime_knl_IThreadSupport_sleep_fxnP(xdc_runtime_knl_IThreadSupport_Module mod);
static inline xdc_runtime_knl_IThreadSupport_sleep_FxnT xdc_runtime_knl_IThreadSupport_sleep_fxnP(xdc_runtime_knl_IThreadSupport_Module mod)
{
    return (xdc_runtime_knl_IThreadSupport_sleep_FxnT)mod->sleep;
}

/* join_{FxnT,fxnP} */
typedef xdc_Bool (*xdc_runtime_knl_IThreadSupport_join_FxnT)(xdc_Void *inst, xdc_runtime_Error_Block* eb);
static inline xdc_runtime_knl_IThreadSupport_join_FxnT xdc_runtime_knl_IThreadSupport_join_fxnP(xdc_runtime_knl_IThreadSupport_Handle inst);
static inline xdc_runtime_knl_IThreadSupport_join_FxnT xdc_runtime_knl_IThreadSupport_join_fxnP(xdc_runtime_knl_IThreadSupport_Handle inst)
{
    return (xdc_runtime_knl_IThreadSupport_join_FxnT)inst->__fxns->join;
}

/* getPriority_{FxnT,fxnP} */
typedef xdc_runtime_knl_IThreadSupport_Priority (*xdc_runtime_knl_IThreadSupport_getPriority_FxnT)(xdc_Void *inst, xdc_runtime_Error_Block* eb);
static inline xdc_runtime_knl_IThreadSupport_getPriority_FxnT xdc_runtime_knl_IThreadSupport_getPriority_fxnP(xdc_runtime_knl_IThreadSupport_Handle inst);
static inline xdc_runtime_knl_IThreadSupport_getPriority_FxnT xdc_runtime_knl_IThreadSupport_getPriority_fxnP(xdc_runtime_knl_IThreadSupport_Handle inst)
{
    return (xdc_runtime_knl_IThreadSupport_getPriority_FxnT)inst->__fxns->getPriority;
}

/* setPriority_{FxnT,fxnP} */
typedef xdc_Bool (*xdc_runtime_knl_IThreadSupport_setPriority_FxnT)(xdc_Void *inst, xdc_runtime_knl_IThreadSupport_Priority newPri, xdc_runtime_Error_Block* eb);
static inline xdc_runtime_knl_IThreadSupport_setPriority_FxnT xdc_runtime_knl_IThreadSupport_setPriority_fxnP(xdc_runtime_knl_IThreadSupport_Handle inst);
static inline xdc_runtime_knl_IThreadSupport_setPriority_FxnT xdc_runtime_knl_IThreadSupport_setPriority_fxnP(xdc_runtime_knl_IThreadSupport_Handle inst)
{
    return (xdc_runtime_knl_IThreadSupport_setPriority_FxnT)inst->__fxns->setPriority;
}

/* getOsPriority_{FxnT,fxnP} */
typedef xdc_Int (*xdc_runtime_knl_IThreadSupport_getOsPriority_FxnT)(xdc_Void *inst, xdc_runtime_Error_Block* eb);
static inline xdc_runtime_knl_IThreadSupport_getOsPriority_FxnT xdc_runtime_knl_IThreadSupport_getOsPriority_fxnP(xdc_runtime_knl_IThreadSupport_Handle inst);
static inline xdc_runtime_knl_IThreadSupport_getOsPriority_FxnT xdc_runtime_knl_IThreadSupport_getOsPriority_fxnP(xdc_runtime_knl_IThreadSupport_Handle inst)
{
    return (xdc_runtime_knl_IThreadSupport_getOsPriority_FxnT)inst->__fxns->getOsPriority;
}

/* setOsPriority_{FxnT,fxnP} */
typedef xdc_Bool (*xdc_runtime_knl_IThreadSupport_setOsPriority_FxnT)(xdc_Void *inst, xdc_Int newPri, xdc_runtime_Error_Block* eb);
static inline xdc_runtime_knl_IThreadSupport_setOsPriority_FxnT xdc_runtime_knl_IThreadSupport_setOsPriority_fxnP(xdc_runtime_knl_IThreadSupport_Handle inst);
static inline xdc_runtime_knl_IThreadSupport_setOsPriority_FxnT xdc_runtime_knl_IThreadSupport_setOsPriority_fxnP(xdc_runtime_knl_IThreadSupport_Handle inst)
{
    return (xdc_runtime_knl_IThreadSupport_setOsPriority_FxnT)inst->__fxns->setOsPriority;
}

/* getOsHandle_{FxnT,fxnP} */
typedef xdc_Ptr (*xdc_runtime_knl_IThreadSupport_getOsHandle_FxnT)(xdc_Void *inst);
static inline xdc_runtime_knl_IThreadSupport_getOsHandle_FxnT xdc_runtime_knl_IThreadSupport_getOsHandle_fxnP(xdc_runtime_knl_IThreadSupport_Handle inst);
static inline xdc_runtime_knl_IThreadSupport_getOsHandle_FxnT xdc_runtime_knl_IThreadSupport_getOsHandle_fxnP(xdc_runtime_knl_IThreadSupport_Handle inst)
{
    return (xdc_runtime_knl_IThreadSupport_getOsHandle_FxnT)inst->__fxns->getOsHandle;
}

/* getTls_{FxnT,fxnP} */
typedef xdc_Ptr (*xdc_runtime_knl_IThreadSupport_getTls_FxnT)(xdc_Void *inst);
static inline xdc_runtime_knl_IThreadSupport_getTls_FxnT xdc_runtime_knl_IThreadSupport_getTls_fxnP(xdc_runtime_knl_IThreadSupport_Handle inst);
static inline xdc_runtime_knl_IThreadSupport_getTls_FxnT xdc_runtime_knl_IThreadSupport_getTls_fxnP(xdc_runtime_knl_IThreadSupport_Handle inst)
{
    return (xdc_runtime_knl_IThreadSupport_getTls_FxnT)inst->__fxns->getTls;
}

/* setTls_{FxnT,fxnP} */
typedef xdc_Void (*xdc_runtime_knl_IThreadSupport_setTls_FxnT)(xdc_Void *inst, xdc_Ptr tls);
static inline xdc_runtime_knl_IThreadSupport_setTls_FxnT xdc_runtime_knl_IThreadSupport_setTls_fxnP(xdc_runtime_knl_IThreadSupport_Handle inst);
static inline xdc_runtime_knl_IThreadSupport_setTls_FxnT xdc_runtime_knl_IThreadSupport_setTls_fxnP(xdc_runtime_knl_IThreadSupport_Handle inst)
{
    return (xdc_runtime_knl_IThreadSupport_setTls_FxnT)inst->__fxns->setTls;
}

/* stat_{FxnT,fxnP} */
typedef xdc_Bool (*xdc_runtime_knl_IThreadSupport_stat_FxnT)(xdc_Void *inst, xdc_runtime_knl_IThreadSupport_Stat* buf, xdc_runtime_Error_Block* eb);
static inline xdc_runtime_knl_IThreadSupport_stat_FxnT xdc_runtime_knl_IThreadSupport_stat_fxnP(xdc_runtime_knl_IThreadSupport_Handle inst);
static inline xdc_runtime_knl_IThreadSupport_stat_FxnT xdc_runtime_knl_IThreadSupport_stat_fxnP(xdc_runtime_knl_IThreadSupport_Handle inst)
{
    return (xdc_runtime_knl_IThreadSupport_stat_FxnT)inst->__fxns->stat;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef xdc_runtime_knl_IThreadSupport__top__
#undef __nested__
#endif

#endif /* xdc_runtime_knl_IThreadSupport__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(xdc_runtime_knl_IThreadSupport__nolocalnames)

#ifndef xdc_runtime_knl_IThreadSupport__localnames__done
#define xdc_runtime_knl_IThreadSupport__localnames__done

/* module prefix */
#define IThreadSupport_Instance xdc_runtime_knl_IThreadSupport_Instance
#define IThreadSupport_Handle xdc_runtime_knl_IThreadSupport_Handle
#define IThreadSupport_Module xdc_runtime_knl_IThreadSupport_Module
#define IThreadSupport_Priority xdc_runtime_knl_IThreadSupport_Priority
#define IThreadSupport_INVALID_OS_PRIORITY xdc_runtime_knl_IThreadSupport_INVALID_OS_PRIORITY
#define IThreadSupport_GETPRI_FAILED xdc_runtime_knl_IThreadSupport_GETPRI_FAILED
#define IThreadSupport_CompStatus xdc_runtime_knl_IThreadSupport_CompStatus
#define IThreadSupport_RunFxn xdc_runtime_knl_IThreadSupport_RunFxn
#define IThreadSupport_Stat xdc_runtime_knl_IThreadSupport_Stat
#define IThreadSupport_Priority_INVALID xdc_runtime_knl_IThreadSupport_Priority_INVALID
#define IThreadSupport_Priority_LOWEST xdc_runtime_knl_IThreadSupport_Priority_LOWEST
#define IThreadSupport_Priority_BELOW_NORMAL xdc_runtime_knl_IThreadSupport_Priority_BELOW_NORMAL
#define IThreadSupport_Priority_NORMAL xdc_runtime_knl_IThreadSupport_Priority_NORMAL
#define IThreadSupport_Priority_ABOVE_NORMAL xdc_runtime_knl_IThreadSupport_Priority_ABOVE_NORMAL
#define IThreadSupport_Priority_HIGHEST xdc_runtime_knl_IThreadSupport_Priority_HIGHEST
#define IThreadSupport_CompStatus_ERROR xdc_runtime_knl_IThreadSupport_CompStatus_ERROR
#define IThreadSupport_CompStatus_LOWER xdc_runtime_knl_IThreadSupport_CompStatus_LOWER
#define IThreadSupport_CompStatus_EQUAL xdc_runtime_knl_IThreadSupport_CompStatus_EQUAL
#define IThreadSupport_CompStatus_HIGHER xdc_runtime_knl_IThreadSupport_CompStatus_HIGHER
#define IThreadSupport_Params xdc_runtime_knl_IThreadSupport_Params
#define IThreadSupport_self xdc_runtime_knl_IThreadSupport_self
#define IThreadSupport_self_fxnP xdc_runtime_knl_IThreadSupport_self_fxnP
#define IThreadSupport_self_FxnT xdc_runtime_knl_IThreadSupport_self_FxnT
#define IThreadSupport_start xdc_runtime_knl_IThreadSupport_start
#define IThreadSupport_start_fxnP xdc_runtime_knl_IThreadSupport_start_fxnP
#define IThreadSupport_start_FxnT xdc_runtime_knl_IThreadSupport_start_FxnT
#define IThreadSupport_yield xdc_runtime_knl_IThreadSupport_yield
#define IThreadSupport_yield_fxnP xdc_runtime_knl_IThreadSupport_yield_fxnP
#define IThreadSupport_yield_FxnT xdc_runtime_knl_IThreadSupport_yield_FxnT
#define IThreadSupport_compareOsPriorities xdc_runtime_knl_IThreadSupport_compareOsPriorities
#define IThreadSupport_compareOsPriorities_fxnP xdc_runtime_knl_IThreadSupport_compareOsPriorities_fxnP
#define IThreadSupport_compareOsPriorities_FxnT xdc_runtime_knl_IThreadSupport_compareOsPriorities_FxnT
#define IThreadSupport_sleep xdc_runtime_knl_IThreadSupport_sleep
#define IThreadSupport_sleep_fxnP xdc_runtime_knl_IThreadSupport_sleep_fxnP
#define IThreadSupport_sleep_FxnT xdc_runtime_knl_IThreadSupport_sleep_FxnT
#define IThreadSupport_join xdc_runtime_knl_IThreadSupport_join
#define IThreadSupport_join_fxnP xdc_runtime_knl_IThreadSupport_join_fxnP
#define IThreadSupport_join_FxnT xdc_runtime_knl_IThreadSupport_join_FxnT
#define IThreadSupport_getPriority xdc_runtime_knl_IThreadSupport_getPriority
#define IThreadSupport_getPriority_fxnP xdc_runtime_knl_IThreadSupport_getPriority_fxnP
#define IThreadSupport_getPriority_FxnT xdc_runtime_knl_IThreadSupport_getPriority_FxnT
#define IThreadSupport_setPriority xdc_runtime_knl_IThreadSupport_setPriority
#define IThreadSupport_setPriority_fxnP xdc_runtime_knl_IThreadSupport_setPriority_fxnP
#define IThreadSupport_setPriority_FxnT xdc_runtime_knl_IThreadSupport_setPriority_FxnT
#define IThreadSupport_getOsPriority xdc_runtime_knl_IThreadSupport_getOsPriority
#define IThreadSupport_getOsPriority_fxnP xdc_runtime_knl_IThreadSupport_getOsPriority_fxnP
#define IThreadSupport_getOsPriority_FxnT xdc_runtime_knl_IThreadSupport_getOsPriority_FxnT
#define IThreadSupport_setOsPriority xdc_runtime_knl_IThreadSupport_setOsPriority
#define IThreadSupport_setOsPriority_fxnP xdc_runtime_knl_IThreadSupport_setOsPriority_fxnP
#define IThreadSupport_setOsPriority_FxnT xdc_runtime_knl_IThreadSupport_setOsPriority_FxnT
#define IThreadSupport_getOsHandle xdc_runtime_knl_IThreadSupport_getOsHandle
#define IThreadSupport_getOsHandle_fxnP xdc_runtime_knl_IThreadSupport_getOsHandle_fxnP
#define IThreadSupport_getOsHandle_FxnT xdc_runtime_knl_IThreadSupport_getOsHandle_FxnT
#define IThreadSupport_getTls xdc_runtime_knl_IThreadSupport_getTls
#define IThreadSupport_getTls_fxnP xdc_runtime_knl_IThreadSupport_getTls_fxnP
#define IThreadSupport_getTls_FxnT xdc_runtime_knl_IThreadSupport_getTls_FxnT
#define IThreadSupport_setTls xdc_runtime_knl_IThreadSupport_setTls
#define IThreadSupport_setTls_fxnP xdc_runtime_knl_IThreadSupport_setTls_fxnP
#define IThreadSupport_setTls_FxnT xdc_runtime_knl_IThreadSupport_setTls_FxnT
#define IThreadSupport_stat xdc_runtime_knl_IThreadSupport_stat
#define IThreadSupport_stat_fxnP xdc_runtime_knl_IThreadSupport_stat_fxnP
#define IThreadSupport_stat_FxnT xdc_runtime_knl_IThreadSupport_stat_FxnT
#define IThreadSupport_Module_name xdc_runtime_knl_IThreadSupport_Module_name
#define IThreadSupport_create xdc_runtime_knl_IThreadSupport_create
#define IThreadSupport_delete xdc_runtime_knl_IThreadSupport_delete
#define IThreadSupport_Handle_label xdc_runtime_knl_IThreadSupport_Handle_label
#define IThreadSupport_Handle_to_Module xdc_runtime_knl_IThreadSupport_Handle_to_Module

#endif /* xdc_runtime_knl_IThreadSupport__localnames__done */
#endif
/*
 *  @(#) xdc.runtime.knl; 1, 0, 0,0; 10-3-2020 15:25:00; /db/ztree/library/trees/xdc/xdc-K04/src/packages/
 */

