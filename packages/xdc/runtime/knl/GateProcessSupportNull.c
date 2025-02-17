/*
 *  ======== GateProcessSupportNull.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/Error.h>

#include "package/internal/GateProcessSupportNull.xdc.h"

/*
 *  ======== GateProcessSupportNull_enter ========
 */
IArg GateProcessSupportNull_enter(GateProcessSupportNull_Handle gate)
{
    return (0);
}

/*
 *  ======== GateProcessSupportNull_leave ========
 */
Void GateProcessSupportNull_leave(GateProcessSupportNull_Handle gate, IArg key)
{
}

/*
 *  ======== GateProcessSupportNull_getReferenceCount ========
 */
Int GateProcessSupportNull_getReferenceCount(GateProcessSupportNull_Handle gate,   Error_Block* eb)
{
    return (0);
}

/*
 *  ======== GateProcessSupportNull_query ========
 */
Bool GateProcessSupportNull_query(Int qual)
{
    return (TRUE);
}
/*
 *  @(#) xdc.runtime.knl; 1, 0, 0,0; 10-3-2020 15:25:00; /db/ztree/library/trees/xdc/xdc-K04/src/packages/
 */

