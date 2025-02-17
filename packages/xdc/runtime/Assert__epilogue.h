/* 
 *  Copyright (c) 2008-2018 Texas Instruments Incorporated
 *  This program and the accompanying materials are made available under the
 *  terms of the Eclipse Public License v1.0 and Eclipse Distribution License
 *  v. 1.0 which accompanies this distribution. The Eclipse Public License is
 *  available at http://www.eclipse.org/legal/epl-v10.html and the Eclipse
 *  Distribution License is available at
 *  http://www.eclipse.org/org/documents/edl-v10.php.
 *
 *  Contributors:
 *      Texas Instruments - initial implementation
 * */

#ifndef xdc_runtime_Assert__epilogue__include
#define xdc_runtime_Assert__epilogue__include

/*
 *  ======== xdc_runtime_Assert_getMask ========
 *  Convert an id into a mask
 */
#define xdc_runtime_Assert_getMask(id) ( \
    (id != 0U) ? ((id) & 0x0000FFFFU & ~xdc_runtime_Diags_ASSERT) \
         : xdc_runtime_Diags_INTERNAL \
)

/*
 *  ======== xdc_runtime_Assert_isTrue ========
 */
#ifndef xdc_runtime_Assert_DISABLE_ALL
#ifdef xdc_runtime_Assert_DISABLE_CONDITIONAL_ASSERT

#define xdc_runtime_Assert_isTrue(expr, id) (\
    !(expr) ? \
        xdc_runtime_Assert_raise__I(Module__MID, xdc_FILE__, __LINE__, ((xdc_runtime_Assert_Id)((uintptr_t)id))) \
        : (void)0)


#else

#define xdc_runtime_Assert_isTrue(expr, id) (\
    (xdc_runtime_Diags_query(xdc_runtime_Diags_ASSERT)) ? ( \
        ((((xdc_runtime_Assert_getMask((xdc_runtime_Assert_Id)((uintptr_t)id)) == 0U) || xdc_runtime_Diags_query(xdc_runtime_Assert_getMask((xdc_runtime_Assert_Id)((uintptr_t)id)))) && !(expr)) ? \
         xdc_runtime_Assert_raise__I(Module__MID, xdc_FILE__, __LINE__, ((xdc_runtime_Assert_Id)((uintptr_t)id))) : (void)0) \
    ) : (void)0)

#endif  /* xdc_runtime_Assert_DISABLE_CONDITIONAL_ASERT */

#else

#define xdc_runtime_Assert_isTrue(expr, id)

#endif  /* xdc_runtime_Assert_DISABLE_ALL */
#endif
/*
 *  @(#) xdc.runtime; 2, 1, 0,0; 10-3-2020 15:24:56; /db/ztree/library/trees/xdc/xdc-K04/src/packages/
 */

