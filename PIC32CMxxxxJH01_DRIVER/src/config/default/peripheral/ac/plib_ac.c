/*******************************************************************************
  Analog Comparator PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_ac.c

  Summary:
    AC Source File

  Description:
    This file defines the interface to the AC peripheral library.
    This library provides access to and control of the associated
    Analog Comparator.

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
#include "interrupts.h"
#include "plib_ac.h"


static volatile AC_OBJECT acObj;

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

void AC_Initialize(void)
{
    /*Reset AC registers*/
    AC_REGS->AC_CTRLA = (uint8_t)AC_CTRLA_SWRST_Msk;
    while((AC_REGS->AC_SYNCBUSY & AC_SYNCBUSY_SWRST_Msk) == AC_SYNCBUSY_SWRST_Msk)
    {
        /* Wait for Synchronization */
    }


    AC_REGS->AC_CTRLA = (uint8_t)AC_CTRLA_ENABLE_Msk;
    while((AC_REGS->AC_SYNCBUSY & AC_SYNCBUSY_ENABLE_Msk) == AC_SYNCBUSY_ENABLE_Msk)
    {
        /* Wait for Synchronization */
    }
}

void AC_Start( AC_CHANNEL channel_id )
{
    /* Start Comparison */
    AC_REGS->AC_CTRLB |= ((uint8_t)1U << (uint8_t)channel_id);
}

void AC_SetVddScalar( AC_CHANNEL channel_id , uint8_t vdd_scalar)
{
    AC_REGS->AC_SCALER[channel_id] = vdd_scalar;
}

void AC_SwapInputs( AC_CHANNEL channel_id )
{
    /* Disable comparator before swapping */
    AC_REGS->AC_COMPCTRL[channel_id] &= ~AC_COMPCTRL_ENABLE_Msk;
    /* Check Synchronization to ensure that the comparator is disabled */
    while((AC_REGS->AC_SYNCBUSY != 0U))
    {
        /* Wait for Synchronization */
    }
    /* Swap inputs of the given comparator */
    AC_REGS->AC_COMPCTRL[channel_id] |= AC_COMPCTRL_SWAP_Msk;
    AC_REGS->AC_COMPCTRL[channel_id] |= AC_COMPCTRL_ENABLE_Msk;
    while((AC_REGS->AC_SYNCBUSY != 0U))
    {
        /* Wait for Synchronization */
    }
}

void AC_ChannelSelect( AC_CHANNEL channel_id , AC_POSINPUT positiveInput, AC_NEGINPUT negativeInput)
{
    /* Disable comparator before swapping */
    AC_REGS->AC_COMPCTRL[channel_id] &= ~AC_COMPCTRL_ENABLE_Msk;
    /* Check Synchronization to ensure that the comparator is disabled */
    while((AC_REGS->AC_SYNCBUSY != 0U))
    {
        /* Wait for Synchronization */
    }
    AC_REGS->AC_COMPCTRL[channel_id] &= ~(AC_COMPCTRL_MUXPOS_Msk | AC_COMPCTRL_MUXNEG_Msk);
    AC_REGS->AC_COMPCTRL[channel_id] |= ((uint32_t)positiveInput | (uint32_t)negativeInput);

    /* Enable comparator channel */
    AC_REGS->AC_COMPCTRL[channel_id] |= AC_COMPCTRL_ENABLE_Msk;
    while((AC_REGS->AC_SYNCBUSY != 0U))
    {
        /* Wait for Synchronization */
    }

}

bool AC_StatusGet (AC_CHANNEL channel)
{
    bool breturnVal = false;

    if((AC_REGS->AC_STATUSB & (AC_STATUSB_READY0_Msk << (uint8_t)channel)) == (AC_STATUSB_READY0_Msk << (uint8_t)channel))
    {
        if((AC_REGS->AC_STATUSA & (AC_STATUSA_STATE0_Msk << (uint8_t)channel)) == (AC_STATUSA_STATE0_Msk << (uint8_t)channel))
        {
            breturnVal = true;
        }
        else
        {
            breturnVal = false;
        }
    }

    return breturnVal;
}

void AC_CallbackRegister (AC_CALLBACK callback, uintptr_t context)
{
    acObj.callback = callback;
    acObj.context = context;
}
