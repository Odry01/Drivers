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

/**
    Function:
    void RTC_DRIVER_Initialize(void)

    Summary:
    Initializes the Real‑Time Clock (RTC) driver module.

    Description:
    This routine performs all one‑time configuration required for the
    system RTC peripheral.  It sets up the clock source, time‑base,
    interrupts and clears any pending status flags so that
    RTC_DRIVER_Tasks() can manage timekeeping safely.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
*/
void RTC_DRIVER_Initialize(void);

/**
    Function:
    void RTC_DRIVER_Tasks(void)

    Summary:
    Main task routine for the Real‑Time Clock driver.

    Description:
    This function contains the state‑machine that handles all RTC
    operations.  It monitors the task start flag, updates time counters,
    generates periodic interrupts or alarms and performs any
    necessary error handling.  It is intended to be called repeatedly
    from the application loop.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    The driver keeps an internal tick count that can be queried by
    other modules.
*/
void RTC_DRIVER_Tasks(void);

/**
    Function:
    bool RTC_DRIVER_Get_Task_Start_Status(void)

    Summary:
    Retrieves the current “task start” flag for the RTC driver.

    Description:
    Indicates whether a new RTC operation (e.g., time‑set, alarm) has been requested.  
    The application sets this flag via
    RTC_DRIVER_Set_Task_Start_Status(true) and clears it when processing is finished.

    Parameters:
    None.

    Returns:
    @return bool – `true` if an RTC task is pending, otherwise `false`.

    Remarks:
    None.
*/
bool RTC_DRIVER_Get_Task_Start_Status(void);

/**
    Function:
    void RTC_DRIVER_Set_Task_Start_Status(bool STATUS)

    Summary:
    Sets the “task start” flag for the RTC driver.

    Description:
    Allows the application to signal that a new RTC operation should
    be performed.  The driver will act on this flag during its next call to
    RTC_DRIVER_Tasks().

    Parameters:
    @param bool STATUS – Desired state of the task‑start flag (`true` = pending, `false` = cleared).

    Returns:
    None.

    Remarks:
    Resetting the flag after a successful operation prevents accidental repeats.
*/
void RTC_DRIVER_Set_Task_Start_Status(bool STATUS);

/**
    Function:
    bool RTC_DRIVER_Get_Task_Completed_Status(void)

    Summary:
    Retrieves the current “task completed” flag for the RTC driver.

    Description:
    Indicates whether the most recent RTC task has finished
    (successfully or not).  The driver sets this flag after the time
    setting, alarm configuration or read operation completes.

    Parameters:
    None.

    Returns:
    @return bool – `true` if the last RTC task is complete, otherwise `false`.

    Remarks:
    After a successful set operation the internal calendar is updated.
*/
bool RTC_DRIVER_Get_Task_Completed_Status(void);

/**
    Function:
    void RTC_DRIVER_Set_Task_Completed_Status(bool STATUS)

    Summary:
    Sets the “task completed” flag for the RTC driver.

    Description:
    Allows the driver to mark an RTC operation as finished.  
    The application may clear this flag when it is ready for another
    RTC request.

    Parameters:
    @param bool STATUS – Desired state of the task‑completed flag (`true` = complete, `false` = not yet).

    Returns:
    None.

    Remarks:
    None.
*/
void RTC_DRIVER_Set_Task_Completed_Status(bool STATUS);

/**
    Function:
    void RTC_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)

    Summary:
    Prints the current state of the RTC driver to a console.

    Description:
    The routine writes human‑readable information – such as the
    current date/time, alarm status, and any pending error flags –
    to the specified `SYS_CONSOLE_HANDLE`.  It is intended for debugging
    and diagnostic purposes only.

    Parameters:
    @param SYS_CONSOLE_HANDLE CONSOLE_HANDLE – Handle to an MPLAB Harmony console object.

    Returns:
    None.

    Remarks:
    The output format follows the conventions used by the rest of the
    application’s logging system.
*/
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