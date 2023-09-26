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
*                                            INCLUDE FILES
*********************************************************************************************************
*/


#include "cpu_core.h"


/*
*********************************************************************************************************
*                                     CPU_IntDisMeasMaxCurReset()
*
* Description : Reset current maximum interrupts disabled time.
*
* Argument(s) : none.
*
* Return(s)   : Maximum interrupts disabled time (in CPU timestamp timer counts) before resetting.
*
*               See also 'cpu_core.h  FUNCTION PROTOTYPES  CPU_TS_TmrRd()      Note #2c'
*                      & 'cpu_core.h  FUNCTION PROTOTYPES  CPU_TSxx_to_uSec()  Note #2'.
*
* Caller(s)   : Application.
*
*               This function is a CPU module application programming interface (API) function 
*               & MAY be called by application function(s).
*
* Note(s)     : (1) After initialization, 'CPU_IntDisMeasMaxCur_cnts' MUST ALWAYS be accessed
*                   exclusively with interrupts disabled -- but NOT with critical sections.
*********************************************************************************************************
*/

#ifdef  CPU_CFG_INT_DIS_MEAS_EN
void  CPU_IntDisMeasStart (void)
{
    // CPU_IntDisMeasCtr++;
    // if (CPU_IntDisNestCtr == 0u) {                                  /* If ints NOT yet dis'd, ...                       */
    //     CPU_IntDisMeasStart_cnts = CPU_TS_TmrRd();                  /* ... get ints dis'd start time.                   */
    // }
    // CPU_IntDisNestCtr++;
}
#endif

#ifdef  CPU_CFG_INT_DIS_MEAS_EN
void  CPU_IntDisMeasStop (void)
{
    // CPU_TS_TMR  time_ints_disd_cnts;


    // CPU_IntDisNestCtr--;
    // if (CPU_IntDisNestCtr == 0u) {                                  /* If ints NO longer dis'd,        ...              */
    //     CPU_IntDisMeasStop_cnts = CPU_TS_TmrRd();                   /* ... get  ints dis'd stop time & ...              */
    //                                                                 /* ... calc ints dis'd tot  time (see Note #1b2A).  */
    //     time_ints_disd_cnts     = CPU_IntDisMeasStop_cnts -
    //                               CPU_IntDisMeasStart_cnts;
    //                                                                 /* Calc max ints dis'd times.                       */
    //     if (CPU_IntDisMeasMaxCur_cnts < time_ints_disd_cnts) {
    //         CPU_IntDisMeasMaxCur_cnts = time_ints_disd_cnts;
    //     }
    //     if (CPU_IntDisMeasMax_cnts    < time_ints_disd_cnts) {
    //         CPU_IntDisMeasMax_cnts    = time_ints_disd_cnts;
    //     }
    // }
}
#endif


