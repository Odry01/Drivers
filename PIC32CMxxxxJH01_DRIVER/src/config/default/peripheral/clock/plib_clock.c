/*******************************************************************************
 CLOCK PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_clock.c

  Summary:
    CLOCK PLIB Implementation File.

  Description:
    None

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

#include "plib_clock.h"
#include "device.h"
#include "interrupts.h"



typedef struct
{
    OSC32KCTRL_CFD_CALLBACK   callback;
    uintptr_t        context;
} OSC32KCTRL_OBJECT;

/* Reference Object created for the OSCCTRL */
static volatile OSC32KCTRL_OBJECT osc32kctrlObj;



static void OSCCTRL_Initialize(void)
{
    uint32_t calibValue = (uint32_t)(((*(uint64_t*)0x00806020UL) >> 41 ) & 0x3fffffUL);
    OSCCTRL_REGS->OSCCTRL_CAL48M = calibValue;


    /* Selection of the Division Value */
    OSCCTRL_REGS->OSCCTRL_OSC48MDIV = (uint8_t)OSCCTRL_OSC48MDIV_DIV(0UL);

    while((OSCCTRL_REGS->OSCCTRL_OSC48MSYNCBUSY & OSCCTRL_OSC48MSYNCBUSY_OSC48MDIV_Msk) == OSCCTRL_OSC48MSYNCBUSY_OSC48MDIV_Msk)
    {
        /* Waiting for the synchronization */
    }

    while((OSCCTRL_REGS->OSCCTRL_STATUS & OSCCTRL_STATUS_OSC48MRDY_Msk) != OSCCTRL_STATUS_OSC48MRDY_Msk)
    {
        /* Waiting for the OSC48M Ready state */
    }
    OSCCTRL_REGS->OSCCTRL_OSC48MCTRL |= OSCCTRL_OSC48MCTRL_ONDEMAND_Msk;

}

static void OSC32KCTRL_Initialize(void)
{
    /****************** XOSC32K initialization  ******************************/

    /* Configure 32K External Oscillator */
    OSC32KCTRL_REGS->OSC32KCTRL_XOSC32K = OSC32KCTRL_XOSC32K_STARTUP(5UL) | OSC32KCTRL_XOSC32K_ENABLE_Msk | OSC32KCTRL_XOSC32K_EN1K_Msk | OSC32KCTRL_XOSC32K_ONDEMAND_Msk | OSC32KCTRL_XOSC32K_XTALEN_Msk;

    /* Enable clock failure detection */
    OSC32KCTRL_REGS->OSC32KCTRL_CFDCTRL |= OSC32KCTRL_CFDCTRL_CFDEN_Msk  ;

    OSC32KCTRL_REGS->OSC32KCTRL_OSC32K = 0x0UL;

    OSC32KCTRL_REGS->OSC32KCTRL_RTCCTRL = OSC32KCTRL_RTCCTRL_RTCSEL(4UL);
}



static void GCLK0_Initialize(void)
{

    GCLK_REGS->GCLK_GENCTRL[0] = GCLK_GENCTRL_DIV(1UL) | GCLK_GENCTRL_SRC(6UL) | GCLK_GENCTRL_GENEN_Msk;

    while((GCLK_REGS->GCLK_SYNCBUSY & GCLK_SYNCBUSY_GENCTRL0_Msk) == GCLK_SYNCBUSY_GENCTRL0_Msk)
    {
        /* wait for the Generator 0 synchronization */
    }
}

void CLOCK_Initialize (void)
{
    /* Function to Initialize the Oscillators */
    OSCCTRL_Initialize();

    /* Function to Initialize the 32KHz Oscillators */
    OSC32KCTRL_Initialize();

    GCLK0_Initialize();


    /* Selection of the Generator and write Lock for EIC */
    GCLK_REGS->GCLK_PCHCTRL[2] = GCLK_PCHCTRL_GEN(0x0UL)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[2] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for FREQM_MSR */
    GCLK_REGS->GCLK_PCHCTRL[3] = GCLK_PCHCTRL_GEN(0x0UL)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[3] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for FREQM_REF */
    GCLK_REGS->GCLK_PCHCTRL[4] = GCLK_PCHCTRL_GEN(0x0UL)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[4] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for EVSYS_0 */
    GCLK_REGS->GCLK_PCHCTRL[5] = GCLK_PCHCTRL_GEN(0x0UL)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[5] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for SERCOM0_CORE */
    GCLK_REGS->GCLK_PCHCTRL[18] = GCLK_PCHCTRL_GEN(0x0UL)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[18] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for SERCOM1_CORE */
    GCLK_REGS->GCLK_PCHCTRL[19] = GCLK_PCHCTRL_GEN(0x0UL)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[19] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for SERCOM2_CORE */
    GCLK_REGS->GCLK_PCHCTRL[20] = GCLK_PCHCTRL_GEN(0x0UL)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[20] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for SERCOM3_CORE */
    GCLK_REGS->GCLK_PCHCTRL[21] = GCLK_PCHCTRL_GEN(0x0UL)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[21] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for CAN0 */
    GCLK_REGS->GCLK_PCHCTRL[26] = GCLK_PCHCTRL_GEN(0x0UL)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[26] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for TCC0 TCC1 */
    GCLK_REGS->GCLK_PCHCTRL[28] = GCLK_PCHCTRL_GEN(0x0UL)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[28] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for TC0 TC1 */
    GCLK_REGS->GCLK_PCHCTRL[30] = GCLK_PCHCTRL_GEN(0x0UL)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[30] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for ADC0 */
    GCLK_REGS->GCLK_PCHCTRL[36] = GCLK_PCHCTRL_GEN(0x0UL)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[36] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for DAC */
    GCLK_REGS->GCLK_PCHCTRL[38] = GCLK_PCHCTRL_GEN(0x0UL)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[38] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for PDEC */
    GCLK_REGS->GCLK_PCHCTRL[41] = GCLK_PCHCTRL_GEN(0x0UL)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[41] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for AC */
    GCLK_REGS->GCLK_PCHCTRL[42] = GCLK_PCHCTRL_GEN(0x0UL)  | GCLK_PCHCTRL_CHEN_Msk;

    while ((GCLK_REGS->GCLK_PCHCTRL[42] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }



    /* Configure the APBC Bridge Clocks */
    MCLK_REGS->MCLK_APBCMASK = 0xc1a161fU;


    /* Enabling the Clock Failure Interrupt */
    OSC32KCTRL_REGS->OSC32KCTRL_INTENSET = OSC32KCTRL_INTENSET_CLKFAIL_Msk;

}



void OSC32KCTRL_CallbackRegister (OSC32KCTRL_CFD_CALLBACK callback, uintptr_t context)
{
    osc32kctrlObj.callback = callback;
    osc32kctrlObj.context = context;
}

void __attribute__((used)) OSC32KCTRL_InterruptHandler(void)
{
	uintptr_t context_var;

    /* Checking for the Clock Failure status */
    if ((OSC32KCTRL_REGS->OSC32KCTRL_STATUS & OSC32KCTRL_STATUS_CLKFAIL_Msk) == OSC32KCTRL_STATUS_CLKFAIL_Msk)
    {
        /* Clearing the Clock Fail Interrupt */
        OSC32KCTRL_REGS->OSC32KCTRL_INTFLAG = OSC32KCTRL_INTFLAG_CLKFAIL_Msk;

        if(osc32kctrlObj.callback != NULL)
        {
			context_var = osc32kctrlObj.context;
            osc32kctrlObj.callback(context_var);
        }
    }
}

