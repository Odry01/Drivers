/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    rstc_driver.h

  Status:
    In development
 
  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "RSTC_DRIVER_Initialize" and "RSTC_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "RSTC_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _RSTC_DRIVER_H
#define _RSTC_DRIVER_H

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
    RSTC_DRIVER_STATE_INIT = 0,
    RSTC_DRIVER_STATE_IDLE,
    RSTC_DRIVER_STATE_CHECK_POR_RESET,
    RSTC_DRIVER_STATE_CHECK_BODCORE_RESET,
    RSTC_DRIVER_STATE_CHECK_BODVDD_RESET,
    RSTC_DRIVER_STATE_CHECK_EXT_RESET,
    RSTC_DRIVER_STATE_CHECK_WDT_RESET,
    RSTC_DRIVER_STATE_CHECK_SYST_RESET,
} RSTC_DRIVER_STATES;

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
    RSTC_DRIVER_STATES state;

    /* Driver variables */
    volatile bool RSTC_TASK_START;
    volatile bool RSTC_TASK_COMPLETED;
    uint8_t RESET_REASON;
} RSTC_DRIVER_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/**
    Function:
    void RSTC_DRIVER_Initialize(void)

    Summary:
    Initializes the Reset Controller (RSTC) driver module.

    Description:
    This routine performs all one‑time configuration required for the
    system reset controller.  It sets up any necessary registers,
    clears pending status flags and prepares the driver so that
    RSTC_DRIVER_Tasks() can manage reset requests safely.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void RSTC_DRIVER_Initialize(void);

/**
    Function:
    void RSTC_DRIVER_Tasks(void)

    Summary:
    Main task routine for the Reset Controller driver.

    Description:
    This function contains the state‑machine that handles all reset
    operations.  It monitors the task start flag, triggers a system
    reset when requested, updates status flags and performs any
    necessary error handling.  It is intended to be called repeatedly
    from the application loop.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void RSTC_DRIVER_Tasks(void);

/**
    Function:
    bool RSTC_DRIVER_Get_Task_Start_Status(void)

    Summary:
    Retrieves the current “task start” flag for the reset controller.

    Description:
    Indicates whether a new reset request has been issued.  
    The application sets this flag via
    RSTC_DRIVER_Set_Task_Start_Status(true) and clears it when processing is finished.

    Parameters:
    None.

    Returns:
    @return bool – `true` if a reset task is pending, otherwise `false`.

    Remarks:
    None.
 */
bool RSTC_DRIVER_Get_Task_Start_Status(void);

/**
    Function:
    void RSTC_DRIVER_Set_Task_Start_Status(bool STATUS)

    Summary:
    Sets the “task start” flag for the reset controller.

    Description:
    Allows the application to signal that a system reset should be
    performed.  The driver will act on this flag during its next call to
    RSTC_DRIVER_Tasks().

    Parameters:
    @param bool STATUS – Desired state of the task‑start flag (`true` = pending, `false` = cleared).

    Returns:
    None.

    Remarks:
    None.
 */
void RSTC_DRIVER_Set_Task_Start_Status(bool STATUS);

/**
    Function:
    bool RSTC_DRIVER_Get_Task_Completed_Status(void)

    Summary:
    Retrieves the current “task completed” flag for the reset controller.

    Description:
    Indicates whether the most recent reset operation has finished
    (successfully or not).  The driver sets this flag after the reset
    sequence completes (or aborts).

    Parameters:
    None.

    Returns:
    @return bool – `true` if the last reset task is complete, otherwise `false`.

    Remarks:
    None.
 */
bool RSTC_DRIVER_Get_Task_Completed_Status(void);

/**
    Function:
    void RSTC_DRIVER_Set_Task_Completed_Status(bool STATUS)

    Summary:
    Sets the “task completed” flag for the reset controller.

    Description:
    Allows the driver to mark a reset operation as finished.  
    The application may clear this flag when it is ready for another
    reset request.

    Parameters:
    @param bool STATUS – Desired state of the task‑completed flag (`true` = complete, `false` = not yet).

    Returns:
    None.

    Remarks:
    None.
 */
void RSTC_DRIVER_Set_Task_Completed_Status(bool STATUS);

/**
    Function:
    void RSTC_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)

    Summary:
    Prints the current state of the reset controller to a console.

    Description:
    The routine writes human‑readable information – such as the
    current task status, any pending error flags, and the last reset
    timestamp – to the specified `SYS_CONSOLE_HANDLE`.  It is intended
    for debugging and diagnostic purposes only.

    Parameters:
    @param SYS_CONSOLE_HANDLE CONSOLE_HANDLE – Handle to an MPLAB Harmony console object.

    Returns:
    None.

    Remarks:
    None.
 */
void RSTC_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _RSTC_DRIVER_H */

/*******************************************************************************
 End of File
 */