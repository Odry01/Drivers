/*******************************************************************************
  System Definitions

  File Name:
    definitions.h

  Summary:
    project system definitions.

  Description:
    This file contains the system-wide prototypes and definitions for a project.

 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2025 Microchip Technology Inc. and its subsidiaries.
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
//DOM-IGNORE-END

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "peripheral/nvmctrl/plib_nvmctrl.h"
#include "peripheral/supc/plib_supc.h"
#include "peripheral/ac/plib_ac.h"
#include "peripheral/tc/plib_tc0.h"
#include "peripheral/rtc/plib_rtc.h"
#include "peripheral/freqm/plib_freqm.h"
#include "driver/i2c/drv_i2c.h"
#include "system/time/sys_time.h"
#include "peripheral/pdec/plib_pdec.h"
#include "peripheral/adc/plib_adc0.h"
#include "driver/spi/drv_spi.h"
#include "peripheral/divas/plib_divas.h"
#include "system/int/sys_int.h"
#include "system/ports/sys_ports.h"
#include "system/dma/sys_dma.h"
#include "osal/osal.h"
#include "system/debug/sys_debug.h"
#include "peripheral/sercom/i2c_master/plib_sercom3_i2c_master.h"
#include "peripheral/sercom/spi_master/plib_sercom2_spi_master.h"
#include "peripheral/sercom/usart/plib_sercom1_usart.h"
#include "peripheral/evsys/plib_evsys.h"
#include "peripheral/sercom/usart/plib_sercom0_usart.h"
#include "peripheral/port/plib_port.h"
#include "peripheral/clock/plib_clock.h"
#include "peripheral/nvic/plib_nvic.h"
#include "peripheral/systick/plib_systick.h"
#include "peripheral/dmac/plib_dmac.h"
#include "peripheral/wdt/plib_wdt.h"
#include "peripheral/pm/plib_pm.h"
#include "peripheral/can/plib_can0.h"
#include "peripheral/eic/plib_eic.h"
#include "peripheral/rstc/plib_rstc.h"
#include "peripheral/dac/plib_dac.h"
#include "peripheral/tcc/plib_tcc1.h"
#include "peripheral/tcc/plib_tcc0.h"
#include "driver/usart/drv_usart.h"
#include "peripheral/ccl/plib_ccl.h"
#include "system/console/sys_console.h"
#include "system/console/src/sys_console_uart_definitions.h"
#include "app.h"
#include "ad9954_driver.h"
#include "bme690_driver.h"
#include "can0_driver.h"
#include "console_driver.h"
#include "fan_driver.h"
#include "fcm360w_driver.h"
#include "hdc302x_driver.h"
#include "mcp9808_driver.h"
#include "ntc_driver.h"
#include "rstc_driver.h"
#include "rtc_driver.h"
#include "sen6x_driver.h"
#include "sht4x_driver.h"
#include "timer_driver.h"
#include "ws281x_driver.h"
#include "xm125_driver.h"



// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

/* Device Information */
#define DEVICE_NAME          "PIC32CM5164JH01032"
#define DEVICE_ARCH          "CORTEX-M0PLUS"
#define DEVICE_FAMILY        "PIC32CM"
#define DEVICE_SERIES        "PIC32CMJH01"

/* CPU clock frequency */
#define CPU_CLOCK_FREQUENCY 48000000U

// *****************************************************************************
// *****************************************************************************
// Section: System Functions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* System Initialization Function

  Function:
    void SYS_Initialize( void *data )

  Summary:
    Function that initializes all modules in the system.

  Description:
    This function initializes all modules in the system, including any drivers,
    services, middleware, and applications.

  Precondition:
    None.

  Parameters:
    data            - Pointer to the data structure containing any data
                      necessary to initialize the module. This pointer may
                      be null if no data is required and default initialization
                      is to be used.

  Returns:
    None.

  Example:
    <code>
    SYS_Initialize ( NULL );

    while ( true )
    {
        SYS_Tasks ( );
    }
    </code>

  Remarks:
    This function will only be called once, after system reset.
*/

void SYS_Initialize( void *data );

// *****************************************************************************
/* System Tasks Function

Function:
    void SYS_Tasks ( void );

Summary:
    Function that performs all polled system tasks.

Description:
    This function performs all polled system tasks by calling the state machine
    "tasks" functions for all polled modules in the system, including drivers,
    services, middleware and applications.

Precondition:
    The SYS_Initialize function must have been called and completed.

Parameters:
    None.

Returns:
    None.

Example:
    <code>
    SYS_Initialize ( NULL );

    while ( true )
    {
        SYS_Tasks ( );
    }
    </code>

Remarks:
    If the module is interrupt driven, the system will call this routine from
    an interrupt context.
*/

void SYS_Tasks ( void );

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* System Objects

Summary:
    Structure holding the system's object handles

Description:
    This structure contains the object handles for all objects in the
    MPLAB Harmony project's system configuration.

Remarks:
    These handles are returned from the "Initialize" functions for each module
    and must be passed into the "Tasks" function for each module.
*/

typedef struct
{
    /* I2C0 Driver Object */
    SYS_MODULE_OBJ drvI2C0;

    SYS_MODULE_OBJ  sysTime;
    SYS_MODULE_OBJ  sysConsole0;

    /* SPI0 Driver Object */
    SYS_MODULE_OBJ drvSPI0;

    SYS_MODULE_OBJ  drvUsart0;

} SYSTEM_OBJECTS;

// *****************************************************************************
// *****************************************************************************
// Section: extern declarations
// *****************************************************************************
// *****************************************************************************



extern SYSTEM_OBJECTS sysObj;

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* DEFINITIONS_H */
/*******************************************************************************
 End of File
*/

