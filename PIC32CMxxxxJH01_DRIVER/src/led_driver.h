/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    led_driver.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "LED_DRIVER_Initialize" and "LED_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "LED_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _LED_DRIVER_H
#define _LED_DRIVER_H

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

#define LED_DATA_WIDTH  24
#define NO_OF_LEDS      20
#define NO_OF_BUFFER    1
#define BUFFER_SIZE     (LED_DATA_WIDTH * NO_OF_LEDS * 4)
#define T1H             20
#define T1L             9

// *****************************************************************************

/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
 */

typedef enum
{
    LED_DRIVER_STATE_INIT = 0,
    LED_DRIVER_STATE_IDLE,
    LED_DRIVER_STATE_SET_COLOR,
    LED_DRIVER_STATE_SET_LED_STRIP_DATA,
    LED_DRIVER_STATE_SEND_LED_STRIP_DATA,
    LED_DRIVER_STATE_SEND_LED_STRIP_DATA_WAIT_FOR_TRANSFER,
} LED_DRIVER_STATES;

// *****************************************************************************

/* Application Data

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
    LED_DRIVER_STATES state;

    /* Driver variables */
    bool LED_TASK_START;
    bool LED_TASK_COMPLETED;
    bool DMAC_CH4_TRANSFER_STATUS;
    uint8_t RED_LED;
    uint8_t GREEN_LED;
    uint8_t BLUE_LED;
    uint32_t DMAC_CH4_BUFFER[NO_OF_BUFFER][NO_OF_LEDS][LED_DATA_WIDTH];
} LED_DRIVER_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

void LED_DRIVER_DMAC_CH4_Callback(DMAC_TRANSFER_EVENT EVENT, uintptr_t CONTEXT);

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void LED_DRIVER_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    LED_DRIVER_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    LED_DRIVER_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
 */

void LED_DRIVER_Initialize(void);

/*******************************************************************************
  Function:
    void LED_DRIVER_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    LED_DRIVER_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void LED_DRIVER_Tasks(void);

bool LED_DRIVER_Get_Task_Start_Status(void);

void LED_DRIVER_Set_Task_Start_Status(bool STATUS);

bool LED_DRIVER_Get_Task_Completed_Status(void);

void LED_DRIVER_Set_Task_Completed_Status(bool STATUS);

void LED_DRIVER_Set_Color(uint8_t RED_LED, uint8_t GREEN_LED, uint8_t BLUE_LED);

void LED_DRIVER_Set_LED_Strip_Data(uint8_t BUFFER_INDEX, uint8_t RED_LED, uint8_t GREEN_LED, uint8_t BLUE_LED);

void LED_DRIVER_Send_LED_Strip_Data(void);

void LED_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _LED_DRIVER_H */

/*******************************************************************************
 End of File
 */