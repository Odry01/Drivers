/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    rtc_driver.h

  Status:
    In development
 
  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "RTC_DRIVER_Initialize" and "RTC_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "RTC_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _RTC_DRIVER_H
#define _RTC_DRIVER_H

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
    RTC_DRIVER_STATE_INIT = 0,
    RTC_DRIVER_STATE_IDLE,
    RTC_DRIVER_STATE_CHECK_XOSC32K_ALERT,
    RTC_DRIVER_STATE_GET_TIME,
    RTC_DRIVER_STATE_STORE_TIME_VALUE,
    RTC_DRIVER_STATE_ERROR,
} RTC_DRIVER_STATES;

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
    RTC_DRIVER_STATES state;

    /* Driver variables */
    struct tm INIT_TIME;
    struct tm SYSTEM_TIME;
    struct tm ALARM_TIME;
    volatile bool RTC_TASK_START;
    volatile bool RTC_TASK_COMPLETED;
    volatile bool RTC_ALARM;
    volatile bool RTC_XOSC32K_ALERT;
    uint32_t TIME;
} RTC_DRIVER_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

void RTC_DRIVER_Alarm_Callback(RTC_CLOCK_INT_MASK INT, uintptr_t CONTEXT);

void RTC_DRIVER_XOSC32K_Alert_Callback(uintptr_t CONTEXT);

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void RTC_DRIVER_Initialize(void);

void RTC_DRIVER_Tasks(void);

bool RTC_DRIVER_Get_Task_Start_Status(void);

void RTC_DRIVER_Set_Task_Start_Status(bool STATUS);

bool RTC_DRIVER_Get_Task_Completed_Status(void);

void RTC_DRIVER_Set_Task_Completed_Status(bool STATUS);

void RTC_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _RTC_DRIVER_H */

/*******************************************************************************
 End of File
 */