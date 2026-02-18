/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    ws281x_driver.h

  Status:
    In development
 
  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "WS281X_DRIVER_Initialize" and "WS281X_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "WS281X_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _WS281X_DRIVER_H
#define _WS281X_DRIVER_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "configuration.h"
#include "definitions.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C"
{

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

#define NUMBER_OF_LEDS          1
#define MINIMUM_DELAY           0xFA

// *****************************************************************************

/** Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
 */

typedef enum
{
    WS281X_DRIVER_STATE_INIT = 0,
    WS281X_DRIVER_STATE_IDLE,
    WS281X_DRIVER_STATE_SET_LED_STRIP_COLOR,
    WS281X_DRIVER_STATE_SET_LED_STRIP_DATA,
    WS281X_DRIVER_STATE_SEND_LED_STRIP_DATA,
    WS281X_DRIVER_STATE_WAIT_FOR_TRANSFER_LED_STRIP_DATA,
} WS281X_DRIVER_STATES;

// *****************************************************************************

/** Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* The application's current state */
    WS281X_DRIVER_STATES state;

    /* Driver variables */
    volatile bool WS281X_TASK_START;
    volatile bool WS281X_TASK_COMPLETED;
    volatile bool DMAC_CH5_TRANSFER_COMPLETED;
    uint8_t RED_LED;
    uint8_t GREEN_LED;
    uint8_t BLUE_LED;
    uint8_t PIXEL[NUMBER_OF_LEDS][3];
    uint8_t DMAC_CH5_BUFFER[2048];
    uint16_t LED_INDEX;
    uint32_t LED_BITS[16];
} WS281X_DRIVER_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

void WS281X_DRIVER_DMAC_CH5_Callback(DMAC_TRANSFER_EVENT EVENT, uintptr_t CONTEXT);

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void WS281X_DRIVER_Initialize(void);

void WS281X_DRIVER_Tasks(void);

bool WS281X_DRIVER_Get_Task_Start_Status(void);

void WS281X_DRIVER_Set_Task_Start_Status(bool STATUS);

bool WS281X_DRIVER_Get_Task_Completed_Status(void);

void WS281X_DRIVER_Set_Task_Completed_Status(bool STATUS);

void WS281X_DRIVER_Set_Color(uint8_t RED_LED, uint8_t GREEN_LED, uint8_t BLUE_LED);

void WS281X_DRIVER_Set_Data_Bits(void);

void WS281X_DRIVER_Set_Strip_Color(void);

void WS281X_DRIVER_Set_Data(uint16_t *INDEX, uint8_t RED_LED, uint8_t GREEN_LED, uint8_t BLUE_LED);

void WS281X_DRIVER_Set_Strip_Data(void);

void WS281X_DRIVER_Send_Data(void);

void WS281X_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _WS281X_DRIVER_H */

/*******************************************************************************
 End of File
 */