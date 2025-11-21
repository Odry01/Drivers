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
    Initializes the application.

    Description:
    This routine performs all one‑time setup required by the application.  
    It places the program in its initial state, configures peripheral error flags,
    and prepares any global data structures so that subsequent calls to
    APP_Tasks() will run correctly.

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
    Main application task routine.

    Description:
    This function contains the core logic of the application.  
    It is typically called repeatedly from the main loop and performs
    periodic checks, state machine updates, and peripheral error handling.
    The routine may read or clear the error status bits set by the
    hardware drivers and take appropriate action (e.g., reset a module,
    log an event, etc.).

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
    Retrieves the current CAN0 error flag.

    Description:
    This function returns whether an error has been detected on the
    CAN0 peripheral.  The value is set by the driver or cleared by the
    application logic when the error condition is handled.

    Parameters:
    None.

    Returns:
    @return bool – `true` if a CAN error is currently flagged, otherwise `false`.

    Remarks:
    None.
 */
bool APP_Get_CAN0_Error_Status(void);

/**
    Function:
    void APP_Set_CAN0_Error_Status(bool STATUS)

    Summary:
    Sets the CAN0 error flag.

    Description:
    This routine allows the application to explicitly set or clear the
    CAN0 error status.  Passing `true` indicates that an error has been
    detected; passing `false` clears the flag so that normal operation can
    resume.

    Parameters:
    @param bool STATUS – The desired error state (`true` = error, `false` = no error).

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
    Retrieves the current I2C error flag.

    Description:
    This function returns whether an error has been detected on the
    I2C peripheral.  The status is updated by the driver and can be cleared
    by the application when the condition is resolved.

    Parameters:
    None.

    Returns:
    @return bool – `true` if an I2C error is flagged, otherwise `false`.

    Remarks:
    None.
 */
bool APP_Get_I2C_Error_Status(void);

/**
    Function:
    void APP_Set_I2C_Error_Status(bool STATUS)

    Summary:
    Sets the I2C error flag.

    Description:
    Explicitly sets or clears the I2C error status.  Use this when the
    application detects an error condition that is not automatically
    reported by the driver, or to acknowledge a handled error.

    Parameters:
    @param bool STATUS – Desired error state (`true` = error, `false` = no error).

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
    Retrieves the current SPI error flag.

    Description:
    This function reports whether an error has been detected on the
    SPI peripheral.  The driver updates this status, and the application
    may clear it after handling the fault.

    Parameters:
    None.

    Returns:
    @return bool – `true` if an SPI error is flagged, otherwise `false`.

    Remarks:
    None.
 */
bool APP_Get_SPI_Error_Status(void);

/**
    Function:
    void APP_Set_SPI_Error_Status(bool STATUS)

    Summary:
    Sets the SPI error flag.

    Description:
    Allows the application to manually set or clear the SPI error
    status.  This can be used for software‑generated error states or to
    acknowledge a handled fault.

    Parameters:
    @param bool STATUS – Desired error state (`true` = error, `false` = no error).

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
    Retrieves the current UART error flag.

    Description:
    This function returns whether an error has been detected on the
    UART peripheral.  The status is maintained by the driver and can be
    cleared by the application once the fault has been resolved.

    Parameters:
    None.

    Returns:
    @return bool – `true` if a UART error is flagged, otherwise `false`.

    Remarks:
    None.
 */
bool APP_Get_UART_Error_Status(void);

/**
    Function:
    void APP_Set_UART_Error_Status(bool STATUS)

    Summary:
    Sets the UART error flag.

    Description:
    Explicitly sets or clears the UART error status.  The application
    can use this to indicate an error condition that was not reported by
    the driver, or to acknowledge a handled error.

    Parameters:
    @param bool STATUS – Desired error state (`true` = error, `false` = no error).

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