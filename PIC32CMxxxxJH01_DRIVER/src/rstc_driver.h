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
    Performs initialization of driver for RSTC peripheral.

    Description:
    The routine sets initial state of state machine. 

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
    Executes periodic tasks.

    Description:
    Executes periodic driver tasks.

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
    Retrieves the "TASK START" flag.

    Description:
    This function retrieve "TASK START" flag.

    Parameters:
    None.

    Returns:
    @return bool - true if a task has been started otherwise is not

    Remarks:
    None.
 */
bool RSTC_DRIVER_Get_Task_Start_Status(void);

/**
    Function:
    void RSTC_DRIVER_Set_Task_Start_Status(bool STATUS)

    Summary:
    Sets the "TASK START" flag

    Description:
    Set "TASK START" flag. It is used for start state machine in idle state.

    Parameters:
    @param STATUS - desired state of the "TASK START" flag

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
    Retrieves the "TASK COMPLETED" flag.

    Description:
    This function retrieve "TASK COMPLETED" flag.

    Parameters:
    None.

    Returns:
    @return bool - true if a task has been completed otherwise is not

    Remarks:
    None.
 */
bool RSTC_DRIVER_Get_Task_Completed_Status(void);

/**
    Function:
    void RSTC_DRIVER_Set_Task_Completed_Status(bool STATUS)

    Summary:
    Sets the "TASK COMPLETED" flag

    Description:
    Set "TASK COMPLETED" flag. It is used for end state machine in last state.

    Parameters:
    @param STATUS - desired state of the "TASK COMPLETED" flag

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
    Prints the text to a console.

    Description:
    Prints formatted text to console. You can use it for debug messages.

    Parameters:
    @param CONSOLE_HANDLE - console handle returned by the library

    Returns:
    None.

    Remarks:
    For reading a text use TeraTerm, CoolTerm, etc.
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