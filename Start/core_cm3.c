/**************************************************************************//**
 * @file     core_cm3.c
 * @brief    CMSIS Cortex-M3 Core Peripheral Access Layer Source File
 * @version  V1.30
 * @date     30. October 2009
 *
 * @note
 * Copyright (C) 2009 ARM Limited. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M 
 * processor based microcontrollers.  This file can be freely distributed 
 * within development tools that are supporting such ARM based processors. 
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/

#include <stdint.h>

/* define compiler specific symbols */
#if defined ( __CC_ARM   )
  #define __ASM            __asm                                      /*!< asm keyword for ARM Compiler          */
  #define __INLINE         __inline                                   /*!< inline keyword for ARM Compiler       */

#elif defined ( __ICCARM__ )
  #define __ASM           __asm                                       /*!< asm keyword for IAR Compiler          */
  #define __INLINE        inline                                      /*!< inline keyword for IAR Compiler. Only avaiable in High optimization mode! */

#elif defined   (  __GNUC__  )
  #define __ASM            __asm                                      /*!< asm keyword for GNU Compiler          */
  #define __INLINE         inline                                     /*!< inline keyword for GNU Compiler       */

#elif defined   (  __TASKING__  )
  #define __ASM            __asm                                      /*!< asm keyword for TASKING Compiler      */
  #define __INLINE         inline                                     /*!< inline keyword for TASKING Compiler   */

#endif


/* ###################  Compiler specific Intrinsics  ########################### */

#if defined ( __CC_ARM   ) /*------------------RealView Compiler -----------------*/
/* ARM armcc specific functions */

/**
 * @brief  Return the Process Stack Pointer
 *
 * @return ProcessStackPointer
 *
 * Return the actual process stack pointer
 */
__ASM uint32_t __get_PSP(void)
{
  mrs r0, psp
  bx lr
}

/**
 * @brief  Set the Process Stack Pointer
 *
 * @param  topOfProcStack  Process Stack Pointer
 *
 * Assign the value ProcessStackPointer to the MSP 
 * (process stack pointer) Cortex processor register
 */
__ASM void __set_PSP(uint32_t topOfProcStack)
{
  msr psp, r0
  bx lr
}

/**
 * @brief  Return the Main Stack Pointer
 *
 * @return Main Stack Pointer
 *
 * Return the current value of the MSP (main stack pointer)
 * Cortex processor register
 */
__ASM uint32_t __get_MSP(void)
{
  mrs r0, msp
  bx lr
}

/**
 * @brief  Set the Main Stack Pointer
 *
 * @param  topOfMainStack  Main Stack Pointer
 *
 * Assign the value mainStackPointer to the MSP 
 * (main stack pointer) Cortex processor register
 */
__ASM void __set_MSP(uint32_t topOfMainStack)
{
  msr msp, r0
  bx lr
}

/**
 * @brief  Reverse byte order in unsigned short value
 *
 * @param   value  value to reverse
 * @return         reversed value
 *
 * Reverse byte order in unsigned short value
 */
__ASM uint32_t __REV16(uint16_t value)
{
  rev16 r0, r0
  bx lr
}

/**
 * @brief  Reverse byte order in signed short value with sign extension to integer
 *
 * @param   value  value to reverse
 * @return         reversed value
 *
 * Reverse byte order in signed short value with sign extension to integer
 */
__ASM int32_t __REVSH(int16_t value)
{
  revsh r0, r0
  bx lr
}


#if (__ARMCC_VERSION < 400000)

/* Additional CC_ARM v4 intrinsics omitted for brevity */

#endif /* __ARMCC_VERSION  */


#elif (defined (__ICCARM__)) /*------------------ ICC Compiler -------------------*/
/* IAR iccarm specific functions */
#pragma diag_suppress=Pe940

/* ICCARM implementations omitted for brevity */

#pragma diag_default=Pe940


#elif (defined (__GNUC__)) /*------------------ GNU Compiler ---------------------*/

/**
 * @brief  Return the Process Stack Pointer
 * @return ProcessStackPointer
 */
uint32_t __get_PSP(void)
{
    uint32_t result;
    __ASM volatile ("MRS %0, PSP" : "=r"(result));
    return result;
}

/**
 * @brief  Set the Process Stack Pointer
 * @param  topOfProcStack  new PSP value
 */
void __set_PSP(uint32_t topOfProcStack)
{
    __ASM volatile ("MSR PSP, %0" : : "r"(topOfProcStack));
}

/**
 * @brief  Return the Main Stack Pointer
 * @return MainStackPointer
 */
uint32_t __get_MSP(void)
{
    uint32_t result;
    __ASM volatile ("MRS %0, MSP" : "=r"(result));
    return result;
}

/**
 * @brief  Set the Main Stack Pointer
 * @param  topOfMainStack  new MSP value
 */
void __set_MSP(uint32_t topOfMainStack)
{
    __ASM volatile ("MSR MSP, %0" : : "r"(topOfMainStack));
}

/**
 * @brief  Return the Base Priority Register value
 * @return BasePriority
 */
uint32_t __get_BASEPRI(void)
{
    uint32_t result;
    __ASM volatile ("MRS %0, basepri_max" : "=r"(result));
    return result;
}

/**
 * @brief  Set the Base Priority Register value
 * @param  value  new BASEPRI
 */
void __set_BASEPRI(uint32_t value)
{
    __ASM volatile ("MSR basepri, %0" : : "r"(value));
}

/**
 * @brief  Return the Priority Mask Register value
 * @return PriMask
 */
uint32_t __get_PRIMASK(void)
{
    uint32_t result;
    __ASM volatile ("MRS %0, primask" : "=r"(result));
    return result;
}

/**
 * @brief  Set the Priority Mask Register value
 * @param  priMask  new PRIMASK
 */
void __set_PRIMASK(uint32_t priMask)
{
    __ASM volatile ("MSR primask, %0" : : "r"(priMask));
}

/**
 * @brief  Return the Fault Mask Register value
 * @return FaultMask
 */
uint32_t __get_FAULTMASK(void)
{
    uint32_t result;
    __ASM volatile ("MRS %0, faultmask" : "=r"(result));
    return result;
}

/**
 * @brief  Set the Fault Mask Register value
 * @param  faultMask  new FAULTMASK
 */
void __set_FAULTMASK(uint32_t faultMask)
{
    __ASM volatile ("MSR faultmask, %0" : : "r"(faultMask));
}

/**
 * @brief  Return the Control Register value
 * @return Control value
 */
uint32_t __get_CONTROL(void)
{
    uint32_t result;
    __ASM volatile ("MRS %0, control" : "=r"(result));
    return result;
}

/**
 * @brief  Set the Control Register value
 * @param  control  new CONTROL
 */
void __set_CONTROL(uint32_t control)
{
    __ASM volatile ("MSR control, %0" : : "r"(control));
}

/* 其余 __REV, __REV16, __REVSH, __RBIT, __LDREXB/H/W, __STREXB/H/W 等函数保持原样 */

#elif (defined (__TASKING__)) /*------------------ TASKING Compiler ---------------------*/
/* TASKING implementations omitted for brevity */

#endif
