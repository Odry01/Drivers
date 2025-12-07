/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    app.h

  Status:
    Finished
 
  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _APP_H
#define _APP_H

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
    APP_STATE_INIT = 0,
    APP_STATE_START_MAIN_TMR,
    APP_STATE_IDLE,
    APP_STATE_HDC302X_DRIVER_OPERATION,
    APP_STATE_WAIT_FOR_FINISH_HDC302X_DRIVER_OPERATION,
    APP_STATE_CAN0_DRIVER_OPERATION,
    APP_STATE_WAIT_FOR_FINISH_CAN0_DRIVER_OPERATION,
    APP_STATE_CONSOLE_DRIVER_OPERATION,
    APP_STATE_WAIT_FOR_FINISH_CONSOLE_DRIVER_OPERATION,
} APP_STATES;

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
    APP_STATES state;

    /* Application variables */
    bool CAN0_ERROR;
    bool I2C_ERROR;
    bool SPI_ERROR;
    bool UART_ERROR;
} APP_DATA;

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
    void APP_Initialize(void)

    Summary:
    Performs one‑time initialization of all application modules and hardware
    peripherals.

    Description:
    This routine configures the device drivers, clears all error flags,
    registers callbacks, and puts the system into a known “idle” state.
    It must be called once during boot (e.g., from main() or before any
    other APP_* functions are used).

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void APP_Initialize(void);

/**
    Function:
    void APP_Tasks(void)

    Summary:
    Executes the main application task loop; should be called repeatedly.

    Description:
    This function is intended to be invoked from the system scheduler
    or main loop.  It performs any pending work such as polling sensors,
    handling communication, and updating state machines.  The routine
    returns immediately after completing all queued tasks.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void APP_Tasks(void);

/**
    Function:
    bool APP_Get_CAN0_Error_Status(void)

    Summary:
    Retrieves the current error status flag for CAN0.

    Description:
    The function returns "true" if a CAN0 communication error has been
    detected since the last call to *APP_Set_CAN0_Error_Status(false)*.
    It does not clear or modify the flag.

    Parameters:
    None.

    Returns:
    @return bool - current status of the CAN0 error flag (true = error pending)

    Remarks:
    None.
 */
bool APP_Get_CAN0_Error_Status(void);

/**
    Function:
    void APP_Set_CAN0_Error_Status(bool STATUS)

    Summary:
    Sets or clears the CAN0 error status flag.

    Description:
    Passing "true" indicates that an error has occurred; passing
    "false" clears the flag.  The flag is used by other parts of the
    application to trigger recovery actions (e.g., re‑initializing the bus).

    Parameters:
    @param STATUS - desired state of the CAN0 error flag

    Returns:
    None.

    Remarks:
    None.
 */
void APP_Set_CAN0_Error_Status(bool STATUS);

/**
    Function:
    bool APP_Get_I2C_Error_Status(void)

    Summary:
    Retrieves the current error status flag for I²C.

    Description:
    Returns "true" if an I²C communication error has been flagged
    since the last reset of the flag.  The function does not alter
    any internal state.

    Parameters:
    None.

    Returns:
    @return bool - current status of the I²C error flag (true = error pending)

    Remarks:
    None.
 */
bool APP_Get_I2C_Error_Status(void);

/**
    Function:
    void APP_Set_I2C_Error_Status(bool STATUS)

    Summary:
    Sets or clears the I²C error status flag.

    Description:
    When "STATUS" is "true", an I²C error condition is recorded.
    Setting it to "false" clears that record, typically after
    recovery logic has been executed.

    Parameters:
    @param STATUS - desired state of the I²C error flag

    Returns:
    None.

    Remarks:
    None.
 */
void APP_Set_I2C_Error_Status(bool STATUS);

/**
    Function:
    bool APP_Get_SPI_Error_Status(void)

    Summary:
    Retrieves the current error status flag for SPI.

    Description:
    The function returns "true" if an SPI communication error has
    been flagged since the last reset.  It does not modify any flags.

    Parameters:
    None.

    Returns:
    @return bool - current status of the SPI error flag (true = error pending)

    Remarks:
    None.
 */
bool APP_Get_SPI_Error_Status(void);

/**
    Function:
    void APP_Set_SPI_Error_Status(bool STATUS)

    Summary:
    Sets or clears the SPI error status flag.

    Description:
    A value of "true" records an error condition; "false"
    clears it.  This allows other modules to detect when
    the SPI bus needs re‑initialization or a fault handler
    has been invoked.

    Parameters:
    @param STATUS - desired state of the SPI error flag

    Returns:
    None.

    Remarks:
    None.
 */
void APP_Set_SPI_Error_Status(bool STATUS);

/**
    Function:
    bool APP_Get_UART_Error_Status(void)

    Summary:
    Retrieves the current error status flag for UART.

    Description:
    Returns "true" if a UART communication error has been
    detected since the last call to *APP_Set_UART_Error_Status(false)*.
    The function does not alter any internal state.

    Parameters:
    None.

    Returns:
    @return bool - current status of the UART error flag (true = error pending)

    Remarks:
    None.
 */
bool APP_Get_UART_Error_Status(void);

/**
    Function:
    void APP_Set_UART_Error_Status(bool STATUS)

    Summary:
    Sets or clears the UART error status flag.

    Description:
    When "STATUS" is set to "true", a UART error condition
    is recorded.  Setting it to "false" clears that record,
    typically after the application has handled the fault.

    Parameters:
    @param STATUS - desired state of the UART error flag

    Returns:
    None.

    Remarks:
    None.
 */
void APP_Set_UART_Error_Status(bool STATUS);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP_H */

/*******************************************************************************
 End of File
 */