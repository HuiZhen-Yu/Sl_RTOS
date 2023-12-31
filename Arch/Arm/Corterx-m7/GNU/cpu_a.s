@/*********************** (C) COPYRIGHT 2023 ********************************
@* File Name	        : port_cpu.s
@* Author               : yhz
@* Version		: V1.0
@* Date 		: 2023/09/14
@* Description	        : 
@***************************************************************************************/

@********************************************************************************************************
@                                           PUBLIC FUNCTIONS
@********************************************************************************************************
        .global  CPU_SR_Save
        .global  CPU_SR_Restore

@********************************************************************************************************
@                                      CODE GENERATION DIRECTIVES
@********************************************************************************************************

.text
.align 2
.syntax unified


@********************************************************************************************************
@                                      CRITICAL SECTION FUNCTIONS
@
@ Description : Disable/Enable interrupts by preserving the state of interrupts.  Generally speaking, the
@               state of the interrupt disable flag is stored in the local variable 'cpu_sr' & interrupts
@               are then disabled ('cpu_sr' is allocated in all functions that need to disable interrupts).
@               The previous interrupt state is restored by copying 'cpu_sr' into the CPU's status register.
@
@ Prototypes  : CPU_SR  CPU_SR_Save   (void);
@               void    CPU_SR_Restore(CPU_SR  cpu_sr);
@
@ Note(s)     : (1) These functions are used in general like this :
@
@                       void  Task (void  *p_arg)
@                       {
@                           CPU_SR_ALLOC();                     /* Allocate storage for CPU status register */
@                               :
@                               :
@                           CPU_CRITICAL_ENTER();               /* cpu_sr = CPU_SR_Save();                  */
@                               :
@                               :
@                           CPU_CRITICAL_EXIT();                /* CPU_SR_Restore(cpu_sr);                  */
@                               :
@                       }
@********************************************************************************************************

.thumb_func
CPU_SR_Save:
        MRS     R0, PRIMASK                     @ Set prio int mask to mask all (except faults)
        CPSID   I
        BX      LR

.thumb_func
CPU_SR_Restore:                                  @ See Note #2.
        MSR     PRIMASK, R0
        BX      LR
