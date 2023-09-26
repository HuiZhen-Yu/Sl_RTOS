/*
*********************************************************************************************************
*                                                uC/CPU
*                                    CPU CONFIGURATION & PORT LAYER
*
*                          (c) Copyright 2004-2015; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*
*               uC/CPU is provided in source form to registered licensees ONLY.  It is 
*               illegal to distribute this source code to any third party unless you receive 
*               written permission by an authorized Micrium representative.  Knowledge of 
*               the source code may NOT be used to develop a similar product.
*
*               Please help us continue to provide the Embedded community with the finest 
*               software available.  Your honesty is greatly appreciated.
*
*               You can find our product's user manual, API reference, release notes and
*               more information at https://doc.micrium.com.
*               You can contact us at www.micrium.com.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                               MODULE
*********************************************************************************************************
*/

#ifndef  CPU_CFG_H
#define  CPU_CFG_H



/*
*********************************************************************************************************
*                                     CPU TIMESTAMP CONFIGURATION
*
* Note(s) : (1) Configure CPU_CFG_TS_xx_EN to enable/disable CPU timestamp features :
*
*               (a) CPU_CFG_TS_32_EN   enable/disable 32-bit CPU timestamp feature
*               (b) CPU_CFG_TS_64_EN   enable/disable 64-bit CPU timestamp feature
*
*           (2) (a) Configure CPU_CFG_TS_TMR_SIZE with the CPU timestamp timer's word size :
*
*                       CPU_WORD_SIZE_08         8-bit word size
*                       CPU_WORD_SIZE_16        16-bit word size
*                       CPU_WORD_SIZE_32        32-bit word size
*                       CPU_WORD_SIZE_64        64-bit word size
*
*               (b) If the size of the CPU timestamp timer is not a binary multiple of 8-bit octets 
*                   (e.g. 20-bits or even 24-bits), then the next lower, binary-multiple octet word 
*                   size SHOULD be configured (e.g. to 16-bits).  However, the minimum supported word 
*                   size for CPU timestamp timers is 8-bits.
*
*                   See also 'cpu_core.h  FUNCTION PROTOTYPES  CPU_TS_TmrRd()  Note #2a'.
*********************************************************************************************************
*/

                                                                /* Configure CPU timestamp features (see Note #1) :     */
#define  CPU_CFG_TS_32_EN                       DEF_ENABLED
#define  CPU_CFG_TS_64_EN                       DEF_DISABLED
                                                                /*   DEF_DISABLED  CPU timestamps DISABLED              */
                                                                /*   DEF_ENABLED   CPU timestamps ENABLED               */

                                                                /* Configure CPU timestamp timer word size ...          */
                                                                /* ... (see Note #2) :                                  */
#define  CPU_CFG_TS_TMR_SIZE                    CPU_WORD_SIZE_32

/*CPU中断时间测量设置
*********************************************************************************************************
*                        CPU INTERRUPTS DISABLED TIME MEASUREMENT CONFIGURATION
*
* Note(s) : (1) (a) Configure CPU_CFG_INT_DIS_MEAS_EN to enable/disable measuring CPU's interrupts 
*                   disabled time :
*
*                   (a)  Enabled,       if CPU_CFG_INT_DIS_MEAS_EN      #define'd in 'cpu_cfg.h'
*
*                   (b) Disabled,       if CPU_CFG_INT_DIS_MEAS_EN  NOT #define'd in 'cpu_cfg.h'
*
*                   See also 'cpu_core.h  FUNCTION PROTOTYPES  Note #1'.
*
*               (b) Configure CPU_CFG_INT_DIS_MEAS_OVRHD_NBR with the number of times to measure & 
*                   average the interrupts disabled time measurements overhead.
*
*                   See also 'cpu_core.c  CPU_IntDisMeasInit()  Note #3a'.
*********************************************************************************************************
*/

#if 1                                                           /* Configure CPU interrupts disabled time ...           */
#define  CPU_CFG_INT_DIS_MEAS_EN                                /* ... measurements feature (see Note #1a).             */
#endif

                                                                /* Configure number of interrupts disabled overhead ... */
#define  CPU_CFG_INT_DIS_MEAS_OVRHD_NBR                    1u   /* ... time measurements (see Note #1b).                */


#endif