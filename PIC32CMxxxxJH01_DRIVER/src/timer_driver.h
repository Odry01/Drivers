/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    timer_driver.h

  Status:
    In development
 
  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "TIMER_DRIVER_Initialize" and "TIMER_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "TIMER_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _TIMER_DRIVER_H
#define _TIMER_DRIVER_H

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

#define MAIN_TIMER          5000
#define BUS_TIMER           500
#define WAIT_TIMER          10

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
    /* Driver variables */
    SYS_TIME_HANDLE MAIN_TMR;
    SYS_TIME_HANDLE BUS_TMR;
    SYS_TIME_HANDLE WAIT_TMR;
    volatile bool MAIN_TMR_EXPIRED;
    volatile bool BUS_TMR_EXPIRED;
    volatile bool WAIT_TMR_EXPIRED;
} TIMER_DRIVER_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

void Main_TMR_Callback(uintptr_t CONTEXT);

void Bus_TMR_Callback(uintptr_t CONTEXT);

void Wait_TMR_Callback(uintptr_t CONTEXT);

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/**
    Function:
    void TIMER_DRIVER_Initialize(void)

    Summary:
    Initializes the Timer driver module.

    Description:
    This routine performs all one‑time configuration required for the
    three software timers.  It sets up the hardware
    timer peripheral(s), configures prescalers, clears pending status
    flags and prepares internal state variables so that timer start/stop
    operations work correctly.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void TIMER_DRIVER_Initialize(void);

/**
    Function:
    bool TIMER_DRIVER_Get_Main_TMR_Status(void)

    Summary:
    Retrieves the current status of the main timer.

    Description:
    Indicates whether the main timer is currently running.  The
    function returns `true` if the timer has been started and not yet stopped,
    otherwise it returns `false`.

    Parameters:
    None.

    Returns:
    @return bool – `true` when the main timer is active, otherwise `false`.

    Remarks:
    The status reflects only the software flag; the hardware counter may be
    running even after a logical stop depending on the implementation.
 */
bool TIMER_DRIVER_Get_Main_TMR_Status(void);

/**
    Function:
    void TIMER_DRIVER_Set_Main_TMR_Status(bool STATUS)

    Summary:
    Sets the internal status flag for the main timer.

    Description:
    Allows other modules to override the main timer’s running state
    (e.g., during initialization or error handling).  The driver will
    respect this flag when performing start/stop operations.

    Parameters:
    @param bool STATUS – Desired running state (`true` = running, `false` = stopped).

    Returns:
    None.

    Remarks:
    This function does not modify the hardware counter; it only updates
    the internal status variable.
 */
void TIMER_DRIVER_Set_Main_TMR_Status(bool STATUS);

/**
    Function:
    void TIMER_DRIVER_Start_Main_TMR(void)

    Summary:
    Starts the main timer.

    Description:
    Initializes the underlying hardware timer, clears any previous count,
    and sets the running flag to `true`.  The timer then counts
    periodically according to its configured prescaler and period.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    If the timer is already running this call has no effect.
 */
void TIMER_DRIVER_Start_Main_TMR(void);

/**
    Function:
    void TIMER_DRIVER_Stop_Main_TMR(void)

    Summary:
    Stops the main timer.

    Description:
    Disables the underlying hardware timer and clears the running flag
    to `false`.  The current count value may be retained for later use.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    If the timer is already stopped this call has no effect.
 */
void TIMER_DRIVER_Stop_Main_TMR(void);

/**
    Function:
    bool TIMER_DRIVER_Get_Bus_TMR_Status(void)

    Summary:
    Retrieves the current status of the bus timer.

    Description:
    Indicates whether the bus timer is currently running.  The
    function returns `true` if the timer has been started and not yet stopped,
    otherwise it returns `false`.

    Parameters:
    None.

    Returns:
    @return bool – `true` when the bus timer is active, otherwise `false`.

    Remarks:
    The status reflects only the software flag; the hardware counter may be
    running even after a logical stop depending on the implementation.
 */
bool TIMER_DRIVER_Get_Bus_TMR_Status(void);

/**
    Function:
    void TIMER_DRIVER_Set_Bus_TMR_Status(bool STATUS)

    Summary:
    Sets the internal status flag for the bus timer.

    Description:
    Allows other modules to override the bus timer’s running state
    (e.g., during initialization or error handling).  The driver will
    respect this flag when performing start/stop operations.

    Parameters:
    @param bool STATUS – Desired running state (`true` = running, `false` = stopped).

    Returns:
    None.

    Remarks:
    This function does not modify the hardware counter; it only updates
    the internal status variable.
 */
void TIMER_DRIVER_Set_Bus_TMR_Status(bool STATUS);

/**
    Function:
    void TIMER_DRIVER_Start_Bus_TMR(void)

    Summary:
    Starts the bus timer.

    Description:
    Initializes the underlying hardware timer, clears any previous count,
    and sets the running flag to `true`.  The timer then counts
    periodically according to its configured prescaler and period.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    If the timer is already running this call has no effect.
 */
void TIMER_DRIVER_Start_Bus_TMR(void);

/**
    Function:
    void TIMER_DRIVER_Stop_Bus_TMR(void)

    Summary:
    Stops the bus timer.

    Description:
    Disables the underlying hardware timer and clears the running flag
    to `false`.  The current count value may be retained for later use.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    If the timer is already stopped this call has no effect.
 */
void TIMER_DRIVER_Stop_Bus_TMR(void);

/**
    Function:
    bool TIMER_DRIVER_Get_Wait_TMR_Status(void)

    Summary:
    Retrieves the current status of the wait timer.

    Description:
    Indicates whether the wait timer is currently running.  The
    function returns `true` if the timer has been started and not yet stopped,
    otherwise it returns `false`.

    Parameters:
    None.

    Returns:
    @return bool – `true` when the wait timer is active, otherwise `false`.

    Remarks:
    The status reflects only the software flag; the hardware counter may be
    running even after a logical stop depending on the implementation.
 */
bool TIMER_DRIVER_Get_Wait_TMR_Status(void);

/**
    Function:
    void TIMER_DRIVER_Set_Wait_TMR_Status(bool STATUS)

    Summary:
    Sets the internal status flag for the wait timer.

    Description:
    Allows other modules to override the wait timer’s running state
    (e.g., during initialization or error handling).  The driver will
    respect this flag when performing start/stop operations.

    Parameters:
    @param bool STATUS – Desired running state (`true` = running, `false` = stopped).

    Returns:
    None.

    Remarks:
    This function does not modify the hardware counter; it only updates
    the internal status variable.
 */
void TIMER_DRIVER_Set_Wait_TMR_Status(bool STATUS);

/**
    Function:
    void TIMER_DRIVER_Start_Wait_TMR(void)

    Summary:
    Starts the wait timer.

    Description:
    Initializes the underlying hardware timer, clears any previous count,
    and sets the running flag to `true`.  The timer then counts
    periodically according to its configured prescaler and period.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    If the timer is already running this call has no effect.
 */
void TIMER_DRIVER_Start_Wait_TMR(void);

/**
    Function:
    void TIMER_DRIVER_Stop_Wait_TMR(void)

    Summary:
    Stops the wait timer.

    Description:
    Disables the underlying hardware timer and clears the running flag
    to `false`.  The current count value may be retained for later use.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    If the timer is already stopped this call has no effect.
 */
void TIMER_DRIVER_Stop_Wait_TMR(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _TIMER_DRIVER_H */

/*******************************************************************************
 End of File
 */