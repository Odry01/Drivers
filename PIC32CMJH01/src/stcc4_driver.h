/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    stcc4_driver.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "STCC4_DRIVER_Initialize" and "STCC4_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "STCC4_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _STCC4_DRIVER_H
#define _STCC4_DRIVER_H

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

#define STCC4_I2C_RX_BUFFER_SIZE                            8
#define STCC4_I2C_TX_BUFFER_SIZE                            8

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
    STCC4_DRIVER_STATE_INIT = 0,
    STCC4_DRIVER_STATE_IDLE,
} STCC4_DRIVER_STATES;

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
    STCC4_DRIVER_STATES state;

    /* Driver variables */
    DRV_HANDLE I2C_HANDLE;
    DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE;
    volatile bool STCC4_TASK_START;
    volatile bool STCC4_TASK_COMPLETED;
    uint8_t I2C_ADDRESS[1];
    uint8_t I2C_DATA_RECEIVE[STCC4_I2C_RX_BUFFER_SIZE];
    uint8_t I2C_DATA_TRANSMIT[STCC4_I2C_TX_BUFFER_SIZE];
} STCC4_DRIVER_DATA;

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

void STCC4_DRIVER_Initialize(void);

void STCC4_DRIVER_Tasks(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _STCC4_DRIVER_H */

/*******************************************************************************
 End of File
 */