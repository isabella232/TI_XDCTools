/* 
 *Copyright (c) 2008 Texas Instruments and others.
 *  All rights reserved. This program and the accompanying materials
 *  are made available under the terms of the Eclipse Public License v1.0
 *  which accompanies this distribution, and is available at
 *  http://www.eclipse.org/legal/epl-v10.html
 * 
 *  Contributors:
 *      Texas Instruments - initial implementation
 *
 * */
metaonly interface Widget {
instance:
    create(Any parent);
    void dispose();

    Bool isValid();

    readonly config Any control;
};
/*
 *  @(#) xdc.tools.sg.widgets; 1,0,0,0; 7-9-2020 13:58:15; /db/ztree/library/trees/xdctools/xdctools-h05/src/
 */

