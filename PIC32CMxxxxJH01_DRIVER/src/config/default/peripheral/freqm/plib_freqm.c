/*******************************************************************************
  FREQUENCY METER(FREQM) PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_freqm.c

  Summary:
    FREQM PLIB Implementation File.

  Description:
    This file defines the interface to the FREQM peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:
    None.

*******************************************************************************/

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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "interrupts.h"
#include "plib_freqm.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: FREQM Interface Implementations
// *****************************************************************************
// *****************************************************************************

void FREQM_Initialize(void)
{
    FREQM_REGS->FREQM_CFGA = (uint16_t)(FREQM_CFGA_REFNUM(1UL) );

    /* Enable FREQM */
    FREQM_REGS->FREQM_CTRLA = (uint8_t)FREQM_CTRLA_ENABLE_Msk;

    while((FREQM_REGS->FREQM_SYNCBUSY) != 0U)
    {
        /* Wait for Sync */
    }
}

bool FREQM_MeasurementStart(void)
{
    bool status = false;

    /* Check if measurement is already in progress */
    if((FREQM_REGS->FREQM_STATUS & FREQM_STATUS_BUSY_Msk) != FREQM_STATUS_BUSY_Msk)
    {
        /* Clear the Done Interrupt flag */
        FREQM_REGS->FREQM_INTFLAG = (uint8_t)FREQM_INTFLAG_DONE_Msk;

        /* Start measurement */
        FREQM_REGS->FREQM_CTRLB = (uint8_t)FREQM_CTRLB_START_Msk;

        status = true;
    }

    return status;
}

bool FREQM_IsBusy(void)
{
    bool freqmIsBusy = false;

    if((FREQM_REGS->FREQM_STATUS & FREQM_STATUS_BUSY_Msk) == FREQM_STATUS_BUSY_Msk)
    {
        freqmIsBusy = true;
    }

    return freqmIsBusy;
}

FREQM_ERROR FREQM_ErrorGet(void)
{
    FREQM_ERROR errorStatus = FREQM_ERROR_NONE;

    errorStatus = ((FREQM_ERROR)FREQM_REGS->FREQM_STATUS & FREQM_STATUS_OVF_Msk);

    /* Clear overflow status */
    FREQM_REGS->FREQM_STATUS = (uint8_t)FREQM_STATUS_OVF_Msk;

    return errorStatus;
}

static uint64_t FREQM_Mul32x32(uint32_t r0, uint32_t r1)
{
    return (r0 * (uint64_t)r1);
}

uint32_t FREQM_FrequencyGet(void)
{
    uint64_t result = 0U;

    result = FREQM_Mul32x32(FREQM_REGS->FREQM_VALUE, 48000000UL);

    result = (result >> 0);

    return (uint32_t)result;
}


