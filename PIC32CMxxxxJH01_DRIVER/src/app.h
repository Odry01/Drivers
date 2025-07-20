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
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application. It places the
    application in its initial state and prepares it to run so that its
    APP_Tasks function can be called.

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
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function. It
    defines the application's state machine and core logic.

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
    Gets the error status of CAN0 peripheral.

  Description:
    This function retrieves the error status of the CAN0 peripheral.

  Parameters:
    None.

  Returns:
    @return bool - True if a CAN error is detected, false otherwise.

  Remarks:
    None.
 */
bool APP_Get_CAN0_Error_Status(void);

/**
  Function:
    void APP_Set_CAN0_Error_Status(bool STATUS)

  Summary:
    Sets the error status of CAN0 peripheral.

  Description:
    This function sets the error status of the CAN0 peripheral.

  Parameters:
    @param bool STATUS: bool - The desired error status to set. True indicates an error, false indicates no error.

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
    Gets the error status of the I2C DRV.

  Description:
    This function retrieves the current error status of the I2C Core driver.

  Parameters:
    None.

  Returns:
    @return bool - True if an I2C error is detected, false otherwise.

  Remarks:
    None.
 */
bool APP_Get_I2C_Error_Status(void);

/**
  Function:
    void APP_Set_I2C_Error_Status(bool STATUS)

  Summary:
    Sets the error status of the I2C Core driver.

  Description:
    This function sets the current error status of the I2C Core driver.

  Parameters:
    @param bool STATUS: - The desired error status to set. True indicates an error, false indicates no error.

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
    Gets the error status of the SPI Core driver.

  Description:
    This function retrieves the current error status of the SPI Core driver.

  Parameters:
    None.

  Returns:
    @return bool - True if an SPI error is detected, false otherwise.

  Remarks:
    None.
 */
bool APP_Get_SPI_Error_Status(void);

/**
  Function:
    void APP_Set_SPI_Error_Status(bool STATUS)

  Summary:
    Sets the error status of the SPI Core driver.

  Description:
    This function sets the current error status of the SPI Core driver.

  Parameters:
    @param bool STATUS: - The desired error status to set. True indicates an error, false indicates no error.

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
    Gets the error status of the UART Core driver.

  Description:
    This function retrieves the current error status of the UART Core driver.

  Parameters:
    None.

  Returns:
    @return bool - True if a UART error is detected, false otherwise.

  Remarks:
    None.
 */
bool APP_Get_UART_Error_Status(void);

/**
  Function:
    void APP_Set_UART_Error_Status(bool STATUS)

  Summary:
    Sets the error status of the UART Core driver.

  Description:
    This function sets the current error status of the UART Core driver.

  Parameters:
    @param bool STATUS: The desired error status to set. True indicates an error, false indicates no error.

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