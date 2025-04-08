/*******************************************************************************
  External Interrupt Controller (EIC) PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_eic.c

  Summary
    Source for EIC peripheral library interface Implementation.

  Description
    This file defines the interface to the EIC peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:
    None.

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/* This section lists the other files that are included in this file.
*/

#include "plib_eic.h"
#include "interrupts.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************

/* EIC Channel Callback object */
static volatile EIC_CALLBACK_OBJ    eicCallbackObject[EXTINT_COUNT];


void EIC_Initialize (void)
{
    /* Reset all registers in the EIC module to their initial state and
       EIC will be disabled. */
    EIC_REGS->EIC_CTRLA |= EIC_CTRLA_SWRST_Msk;

    while((EIC_REGS->EIC_SYNCBUSY & EIC_SYNCBUSY_SWRST_Msk) == EIC_SYNCBUSY_SWRST_Msk)
    {
        /* Wait for sync */
    }

    /* EIC is by default clocked by GCLK */

    /* NMI Control register */


    /* Interrupt sense type and filter control for EXTINT channels 0 to (16-1) */
    EIC_REGS->EIC_CONFIG0 =  EIC_CONFIG0_SENSE0_FALL | EIC_CONFIG0_FILTEN0_Msk
        | EIC_CONFIG0_SENSE1_FALL | EIC_CONFIG0_FILTEN1_Msk
        | EIC_CONFIG0_SENSE2_FALL | EIC_CONFIG0_FILTEN2_Msk
        | EIC_CONFIG0_SENSE3_FALL | EIC_CONFIG0_FILTEN3_Msk
        | EIC_CONFIG0_SENSE4_FALL | EIC_CONFIG0_FILTEN4_Msk
        | EIC_CONFIG0_SENSE5_FALL | EIC_CONFIG0_FILTEN5_Msk
        | EIC_CONFIG0_SENSE6_FALL | EIC_CONFIG0_FILTEN6_Msk
        | EIC_CONFIG0_SENSE7_FALL | EIC_CONFIG0_FILTEN7_Msk;

    EIC_REGS->EIC_CONFIG1 =  EIC_CONFIG1_SENSE8_FALL | EIC_CONFIG1_FILTEN8_Msk
        | EIC_CONFIG1_SENSE9_FALL | EIC_CONFIG1_FILTEN9_Msk
        | EIC_CONFIG1_SENSE10_FALL | EIC_CONFIG1_FILTEN10_Msk
        | EIC_CONFIG1_SENSE11_FALL | EIC_CONFIG1_FILTEN11_Msk
        | EIC_CONFIG1_SENSE12_FALL | EIC_CONFIG1_FILTEN12_Msk
        | EIC_CONFIG1_SENSE13_FALL | EIC_CONFIG1_FILTEN13_Msk
        | EIC_CONFIG1_SENSE14_FALL | EIC_CONFIG1_FILTEN14_Msk
        | EIC_CONFIG1_SENSE15_FALL | EIC_CONFIG1_FILTEN15_Msk;



    /* Debouncer enable */
    EIC_REGS->EIC_DEBOUNCEN = 0xffff;


    /* Debouncer Setting */
    EIC_REGS->EIC_DPRESCALER = EIC_DPRESCALER_PRESCALER0(3) | EIC_DPRESCALER_PRESCALER1(3) | EIC_DPRESCALER_STATES0_Msk | EIC_DPRESCALER_STATES1_Msk ;

    /* External Interrupt enable*/
    EIC_REGS->EIC_INTENSET = 0xffff;
    /* Callbacks for enabled interrupts */
    eicCallbackObject[0].eicPinNo = EIC_PIN_0;
    eicCallbackObject[1].eicPinNo = EIC_PIN_1;
    eicCallbackObject[2].eicPinNo = EIC_PIN_2;
    eicCallbackObject[3].eicPinNo = EIC_PIN_3;
    eicCallbackObject[4].eicPinNo = EIC_PIN_4;
    eicCallbackObject[5].eicPinNo = EIC_PIN_5;
    eicCallbackObject[6].eicPinNo = EIC_PIN_6;
    eicCallbackObject[7].eicPinNo = EIC_PIN_7;
    eicCallbackObject[8].eicPinNo = EIC_PIN_8;
    eicCallbackObject[9].eicPinNo = EIC_PIN_9;
    eicCallbackObject[10].eicPinNo = EIC_PIN_10;
    eicCallbackObject[11].eicPinNo = EIC_PIN_11;
    eicCallbackObject[12].eicPinNo = EIC_PIN_12;
    eicCallbackObject[13].eicPinNo = EIC_PIN_13;
    eicCallbackObject[14].eicPinNo = EIC_PIN_14;
    eicCallbackObject[15].eicPinNo = EIC_PIN_15;

    /* Enable the EIC */
    EIC_REGS->EIC_CTRLA |= EIC_CTRLA_ENABLE_Msk;

    while((EIC_REGS->EIC_SYNCBUSY & EIC_SYNCBUSY_ENABLE_Msk) == EIC_SYNCBUSY_ENABLE_Msk)
    {
        /* Wait for sync */
    }
}

void EIC_InterruptEnable (EIC_PIN pin)
{
    EIC_REGS->EIC_INTENSET = (1UL << (uint32_t)pin);
}

void EIC_InterruptDisable (EIC_PIN pin)
{
    EIC_REGS->EIC_INTENCLR = (1UL << (uint32_t)pin);
}

void EIC_CallbackRegister(EIC_PIN pin, EIC_CALLBACK callback, uintptr_t context)
{
    if (eicCallbackObject[pin].eicPinNo == pin)
    {
        eicCallbackObject[pin].callback = callback;

        eicCallbackObject[pin].context  = context;
    }
}


void __attribute__((used)) EIC_EXTINT_0_InterruptHandler(void)
{
    /* Clear interrupt flag */
    EIC_REGS->EIC_INTFLAG = (1UL << 0);
    (void)EIC_REGS->EIC_INTFLAG;
    /* Find any associated callback entries in the callback table */
    if ((eicCallbackObject[0].callback != NULL))
    {
        uintptr_t context = eicCallbackObject[0].context;
        eicCallbackObject[0].callback(context);
    }

}
void __attribute__((used)) EIC_EXTINT_1_InterruptHandler(void)
{
    /* Clear interrupt flag */
    EIC_REGS->EIC_INTFLAG = (1UL << 1);
    (void)EIC_REGS->EIC_INTFLAG;
    /* Find any associated callback entries in the callback table */
    if ((eicCallbackObject[1].callback != NULL))
    {
        uintptr_t context = eicCallbackObject[1].context;
        eicCallbackObject[1].callback(context);
    }

}
void __attribute__((used)) EIC_EXTINT_2_InterruptHandler(void)
{
    /* Clear interrupt flag */
    EIC_REGS->EIC_INTFLAG = (1UL << 2);
    (void)EIC_REGS->EIC_INTFLAG;
    /* Find any associated callback entries in the callback table */
    if ((eicCallbackObject[2].callback != NULL))
    {
        uintptr_t context = eicCallbackObject[2].context;
        eicCallbackObject[2].callback(context);
    }

}
void __attribute__((used)) EIC_EXTINT_3_InterruptHandler(void)
{
    /* Clear interrupt flag */
    EIC_REGS->EIC_INTFLAG = (1UL << 3);
    (void)EIC_REGS->EIC_INTFLAG;
    /* Find any associated callback entries in the callback table */
    if ((eicCallbackObject[3].callback != NULL))
    {
        uintptr_t context = eicCallbackObject[3].context;
        eicCallbackObject[3].callback(context);
    }

}
void __attribute__((used)) EIC_EXTINT_4_InterruptHandler(void)
{
    /* Clear interrupt flag */
    EIC_REGS->EIC_INTFLAG = (1UL << 4);
    (void)EIC_REGS->EIC_INTFLAG;
    /* Find any associated callback entries in the callback table */
    if ((eicCallbackObject[4].callback != NULL))
    {
        uintptr_t context = eicCallbackObject[4].context;
        eicCallbackObject[4].callback(context);
    }

}
void __attribute__((used)) EIC_EXTINT_5_InterruptHandler(void)
{
    /* Clear interrupt flag */
    EIC_REGS->EIC_INTFLAG = (1UL << 5);
    (void)EIC_REGS->EIC_INTFLAG;
    /* Find any associated callback entries in the callback table */
    if ((eicCallbackObject[5].callback != NULL))
    {
        uintptr_t context = eicCallbackObject[5].context;
        eicCallbackObject[5].callback(context);
    }

}
void __attribute__((used)) EIC_EXTINT_6_InterruptHandler(void)
{
    /* Clear interrupt flag */
    EIC_REGS->EIC_INTFLAG = (1UL << 6);
    (void)EIC_REGS->EIC_INTFLAG;
    /* Find any associated callback entries in the callback table */
    if ((eicCallbackObject[6].callback != NULL))
    {
        uintptr_t context = eicCallbackObject[6].context;
        eicCallbackObject[6].callback(context);
    }

}
void __attribute__((used)) EIC_EXTINT_7_InterruptHandler(void)
{
    /* Clear interrupt flag */
    EIC_REGS->EIC_INTFLAG = (1UL << 7);
    (void)EIC_REGS->EIC_INTFLAG;
    /* Find any associated callback entries in the callback table */
    if ((eicCallbackObject[7].callback != NULL))
    {
        uintptr_t context = eicCallbackObject[7].context;
        eicCallbackObject[7].callback(context);
    }

}
void __attribute__((used)) EIC_EXTINT_8_InterruptHandler(void)
{
    /* Clear interrupt flag */
    EIC_REGS->EIC_INTFLAG = (1UL << 8);
    (void)EIC_REGS->EIC_INTFLAG;
    /* Find any associated callback entries in the callback table */
    if ((eicCallbackObject[8].callback != NULL))
    {
        uintptr_t context = eicCallbackObject[8].context;
        eicCallbackObject[8].callback(context);
    }

}
void __attribute__((used)) EIC_EXTINT_9_InterruptHandler(void)
{
    /* Clear interrupt flag */
    EIC_REGS->EIC_INTFLAG = (1UL << 9);
    (void)EIC_REGS->EIC_INTFLAG;
    /* Find any associated callback entries in the callback table */
    if ((eicCallbackObject[9].callback != NULL))
    {
        uintptr_t context = eicCallbackObject[9].context;
        eicCallbackObject[9].callback(context);
    }

}
void __attribute__((used)) EIC_EXTINT_10_InterruptHandler(void)
{
    /* Clear interrupt flag */
    EIC_REGS->EIC_INTFLAG = (1UL << 10);
    (void)EIC_REGS->EIC_INTFLAG;
    /* Find any associated callback entries in the callback table */
    if ((eicCallbackObject[10].callback != NULL))
    {
        uintptr_t context = eicCallbackObject[10].context;
        eicCallbackObject[10].callback(context);
    }

}
void __attribute__((used)) EIC_EXTINT_11_InterruptHandler(void)
{
    /* Clear interrupt flag */
    EIC_REGS->EIC_INTFLAG = (1UL << 11);
    (void)EIC_REGS->EIC_INTFLAG;
    /* Find any associated callback entries in the callback table */
    if ((eicCallbackObject[11].callback != NULL))
    {
        uintptr_t context = eicCallbackObject[11].context;
        eicCallbackObject[11].callback(context);
    }

}
void __attribute__((used)) EIC_EXTINT_12_InterruptHandler(void)
{
    /* Clear interrupt flag */
    EIC_REGS->EIC_INTFLAG = (1UL << 12);
    (void)EIC_REGS->EIC_INTFLAG;
    /* Find any associated callback entries in the callback table */
    if ((eicCallbackObject[12].callback != NULL))
    {
        uintptr_t context = eicCallbackObject[12].context;
        eicCallbackObject[12].callback(context);
    }

}
void __attribute__((used)) EIC_EXTINT_13_InterruptHandler(void)
{
    /* Clear interrupt flag */
    EIC_REGS->EIC_INTFLAG = (1UL << 13);
    (void)EIC_REGS->EIC_INTFLAG;
    /* Find any associated callback entries in the callback table */
    if ((eicCallbackObject[13].callback != NULL))
    {
        uintptr_t context = eicCallbackObject[13].context;
        eicCallbackObject[13].callback(context);
    }

}
void __attribute__((used)) EIC_EXTINT_14_InterruptHandler(void)
{
    /* Clear interrupt flag */
    EIC_REGS->EIC_INTFLAG = (1UL << 14);
    (void)EIC_REGS->EIC_INTFLAG;
    /* Find any associated callback entries in the callback table */
    if ((eicCallbackObject[14].callback != NULL))
    {
        uintptr_t context = eicCallbackObject[14].context;
        eicCallbackObject[14].callback(context);
    }

}
void __attribute__((used)) EIC_EXTINT_15_InterruptHandler(void)
{
    /* Clear interrupt flag */
    EIC_REGS->EIC_INTFLAG = (1UL << 15);
    (void)EIC_REGS->EIC_INTFLAG;
    /* Find any associated callback entries in the callback table */
    if ((eicCallbackObject[15].callback != NULL))
    {
        uintptr_t context = eicCallbackObject[15].context;
        eicCallbackObject[15].callback(context);
    }

}

