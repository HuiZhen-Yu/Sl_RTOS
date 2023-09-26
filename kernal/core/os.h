/*
************************************************************************************************************************
*                                                      uC/OS-III
*                                                 The Real-Time Kernel
*
*                                  (c) Copyright 2009-2015; Micrium, Inc.; Weston, FL
*                           All rights reserved.  Protected by international copyright laws.
*
* File    : OS.H
* By      : JJL
* Version : V3.04.05
*
* LICENSING TERMS:
* ---------------
*           uC/OS-III is provided in source form for FREE short-term evaluation, for educational use or 
*           for peaceful research.  If you plan or intend to use uC/OS-III in a commercial application/
*           product then, you need to contact Micrium to properly license uC/OS-III for its use in your 
*           application/product.   We provide ALL the source code for your convenience and to help you 
*           experience uC/OS-III.  The fact that the source is provided does NOT mean that you can use 
*           it commercially without paying a licensing fee.
*
*           Knowledge of the source code may NOT be used to develop a similar product.
*
*           Please help us continue to provide the embedded community with the finest software available.
*           Your honesty is greatly appreciated.
*
*           You can find our product's user manual, API reference, release notes and
*           more information at https://doc.micrium.com.
*           You can contact us at www.micrium.com.
************************************************************************************************************************
* Note(s) : (1) Assumes the following versions (or more recent) of software modules are included in the project build:
*
*               (a) uC/LIB V1.36.01
*               (b) uC/CPU V1.29.00
************************************************************************************************************************
*/

#ifndef   OS_H
#define   OS_H

#include "os_cfg.h"
#include "cpu_core.h"

#if     OS_CFG_ISR_POST_DEFERRED_EN > 0u 

#define     OS_CRITICAL_ENTER()                                     \
            do{                                                     \
                CPU_CRITICAL_ENTER();                               \
                CPU_CRITICAL_EXIT();                                \
            }   while(0)


#define     OS_CRITICAL_EXIT()                                     \
            do{                                                    \
                CPU_CRITICAL_EXIT();                               \
                CPU_CRITICAL_EXIT();                               \
            }   while(0)

#else

#define  OS_CRITICAL_ENTER()                    CPU_CRITICAL_ENTER()

#define  OS_CRITICAL_ENTER_CPU_EXIT()

#define  OS_CRITICAL_EXIT()                     CPU_CRITICAL_EXIT()

#define  OS_CRITICAL_EXIT_NO_SCHED()            CPU_CRITICAL_EXIT()

#endif



#endif