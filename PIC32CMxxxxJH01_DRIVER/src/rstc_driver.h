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
    bool RSTC_TASK_START;
    bool RSTC_TASK_COMPLETED;
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

/*******************************************************************************
  Function:
    void RSTC_DRIVER_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    RSTC_DRIVER_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    RSTC_DRIVER_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
 */

void RSTC_DRIVER_Initialize(void);

/*******************************************************************************
  Function:
    void RSTC_DRIVER_Tasks ( void )

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
    RSTC_DRIVER_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void RSTC_DRIVER_Tasks(void);

bool RSTC_DRIVER_Get_Task_Start_Status(void);

void RSTC_DRIVER_Set_Task_Start_Status(bool STATUS);

bool RSTC_DRIVER_Get_Task_Completed_Status(void);

void RSTC_DRIVER_Set_Task_Completed_Status(bool STATUS);

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