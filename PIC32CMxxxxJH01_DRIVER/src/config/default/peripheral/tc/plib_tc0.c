/*******************************************************************************
  Timer/Counter(TC0) PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_TC0.c

  Summary
    TC0 PLIB Implementation File.

  Description
    This file defines the interface to the TC peripheral library. This
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
#include "interrupts.h"
#include "plib_tc0.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************


static volatile TC_CAPTURE_CALLBACK_OBJ TC0_CallbackObject;

// *****************************************************************************
// *****************************************************************************
// Section: TC0 Implementation
// *****************************************************************************
// *****************************************************************************

void TC0_CaptureInitialize( void )
{
    /* Reset TC */
    TC0_REGS->COUNT16.TC_CTRLA = TC_CTRLA_SWRST_Msk;

    while((TC0_REGS->COUNT16.TC_SYNCBUSY & TC_SYNCBUSY_SWRST_Msk) == TC_SYNCBUSY_SWRST_Msk)
    {
        /* Wait for Write Synchronization */
    }

    /* Configure counter mode, prescaler, standby & on demand mode */
    TC0_REGS->COUNT16.TC_CTRLA = TC_CTRLA_MODE_COUNT16 | TC_CTRLA_PRESCALER_DIV1 | TC_CTRLA_PRESCSYNC_PRESC
                                  | TC_CTRLA_CAPTEN0_Msk | TC_CTRLA_CAPTEN1_Msk  ;


    TC0_REGS->COUNT16.TC_EVCTRL = (uint16_t)(TC_EVCTRL_EVACT_PPW | TC_EVCTRL_TCEI_Msk);

    /* Clear all interrupt flags */
    TC0_REGS->COUNT16.TC_INTFLAG = (uint8_t)TC_INTFLAG_Msk;

    /* Enable Interrupt */
    TC0_REGS->COUNT16.TC_INTENSET = (uint8_t)(TC_INTENSET_MC0_Msk | TC_INTENSET_OVF_Msk);
    TC0_CallbackObject.callback = NULL;
}


void TC0_CaptureStart( void )
{
    /* Enable TC */
    TC0_REGS->COUNT16.TC_CTRLA |= TC_CTRLA_ENABLE_Msk;

    while((TC0_REGS->COUNT16.TC_SYNCBUSY & TC_SYNCBUSY_ENABLE_Msk) == TC_SYNCBUSY_ENABLE_Msk)
    {
        /* Wait for Write Synchronization */
    }
}

void TC0_CaptureStop( void )
{
    /* Disable TC */
    TC0_REGS->COUNT16.TC_CTRLA &= ~TC_CTRLA_ENABLE_Msk;

    while((TC0_REGS->COUNT16.TC_SYNCBUSY & TC_SYNCBUSY_ENABLE_Msk) == TC_SYNCBUSY_ENABLE_Msk)
    {
        /* Wait for Write Synchronization */
    }
}

uint32_t TC0_CaptureFrequencyGet( void )
{
    return (uint32_t)(48000000U);
}

void TC0_CaptureCommandSet(TC_COMMAND command)
{
    TC0_REGS->COUNT16.TC_CTRLBSET = (uint8_t)((uint32_t)command << TC_CTRLBSET_CMD_Pos);
    while((TC0_REGS->COUNT16.TC_SYNCBUSY) != 0U)
    {
        /* Wait for Write Synchronization */
    }
}


uint16_t TC0_Capture16bitChannel0Get( void )
{
    return (uint16_t)TC0_REGS->COUNT16.TC_CC[0];
}

uint16_t TC0_Capture16bitChannel1Get( void )
{
    return (uint16_t)TC0_REGS->COUNT16.TC_CC[1];
}

void TC0_CaptureCallbackRegister( TC_CAPTURE_CALLBACK callback, uintptr_t context )
{
    TC0_CallbackObject.callback = callback;
    TC0_CallbackObject.context = context;
}

void __attribute__((used)) TC0_CaptureInterruptHandler( void )
{
    if (TC0_REGS->COUNT16.TC_INTENSET != 0U)
    {
        TC_CAPTURE_STATUS status;
        status = (TC_CAPTURE_STATUS) (TC0_REGS->COUNT16.TC_INTFLAG);
        /* Clear all interrupts */
        TC0_REGS->COUNT16.TC_INTFLAG = (uint8_t)TC_INTFLAG_Msk;

        if((TC0_CallbackObject.callback != NULL) && (status != TC_CAPTURE_STATUS_NONE))
        {
            uintptr_t context = TC0_CallbackObject.context;
            TC0_CallbackObject.callback(status, context);
        }
    }
}

