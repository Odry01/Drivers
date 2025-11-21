/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    console_driver.h

  Status:
    In development
 
  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "CONSOLE_DRIVER_Initialize" and "CONSOLE_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "CONSOLE_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _CONSOLE_DRIVER_H
#define _CONSOLE_DRIVER_H

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
    CONSOLE_DRIVER_STATE_INIT = 0,
    CONSOLE_DRIVER_STATE_IDLE,
    CONSOLE_DRIVER_STATE_PRINT_DATA,
} CONSOLE_DRIVER_STATES;

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
    CONSOLE_DRIVER_STATES state;

    /* Driver variables */
    SYS_CONSOLE_HANDLE CONSOLE_HANDLE;
    volatile bool CONSOLE_TASK_START;
    volatile bool CONSOLE_TASK_COMPLETED;
} CONSOLE_DRIVER_DATA;

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
    void CONSOLE_DRIVER_Initialize(void)

    Summary:
    Initializes the console driver module.

    Description:
    This routine performs all one‑time configuration required for the
    console peripheral (UART, USB CDC, or other interface).  It sets up
    hardware registers, configures buffers, and clears any pending status
    flags so that CONSOLE_DRIVER_Tasks() can operate correctly.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
*/
void CONSOLE_DRIVER_Initialize(void);

/**
    Function:
    void CONSOLE_DRIVER_Tasks(void)

    Summary:
    Main task routine for the console driver.

    Description:
    This function contains the state‑machine that handles all console
    operations.  It polls for new input, processes outgoing data,
    updates status flags and performs any necessary error handling.
    It is intended to be called repeatedly from the application loop.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
*/
void CONSOLE_DRIVER_Tasks(void);

/**
    Function:
    bool CONSOLE_DRIVER_Get_Task_Start_Status(void)

    Summary:
    Retrieves the current “task start” flag for the console driver.

    Description:
    Indicates whether a new console transaction has been requested.  
    The application sets this flag via
    CONSOLE_DRIVER_Set_Task_Start_Status(true) and clears it when processing is finished.

    Parameters:
    None.

    Returns:
    @return bool – `true` if a task is pending, otherwise `false`.

    Remarks:
    None.
*/
bool CONSOLE_DRIVER_Get_Task_Start_Status(void);

/**
    Function:
    void CONSOLE_DRIVER_Set_Task_Start_Status(bool STATUS)

    Summary:
    Sets the “task start” flag for the console driver.

    Description:
    Allows the application to signal that a new console operation should begin.  
    The driver will act on this flag during its next call to
    CONSOLE_DRIVER_Tasks().

    Parameters:
    @param bool STATUS – Desired state of the task‑start flag (`true` = pending, `false` = cleared).

    Returns:
    None.

    Remarks:
    None.
*/
void CONSOLE_DRIVER_Set_Task_Start_Status(bool STATUS);

/**
    Function:
    bool CONSOLE_DRIVER_Get_Task_Completed_Status(void)

    Summary:
    Retrieves the current “task completed” flag for the console driver.

    Description:
    Indicates whether the most recent console transaction has finished
    successfully.  The driver sets this flag when all data have been sent or received and processed.

    Parameters:
    None.

    Returns:
    @return bool – `true` if the last task is complete, otherwise `false`.

    Remarks:
    None.
*/
bool CONSOLE_DRIVER_Get_Task_Completed_Status(void);

/**
    Function:
    void CONSOLE_DRIVER_Set_Task_Completed_Status(bool STATUS)

    Summary:
    Sets the “task completed” flag for the console driver.

    Description:
    Allows the driver to mark a console transaction as finished.  
    The application may clear this flag when it is ready for another
    operation.

    Parameters:
    @param bool STATUS – Desired state of the task‑completed flag (`true` = complete, `false` = not yet).

    Returns:
    None.

    Remarks:
    None.
*/
void CONSOLE_DRIVER_Set_Task_Completed_Status(bool STATUS);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _CONSOLE_DRIVER_H */

/*******************************************************************************
 End of File
 */