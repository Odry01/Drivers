/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    max17335_driver.h

  Status:
    In development
 
  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "MAX17335_DRIVER_Initialize" and "MAX17335_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "MAX17335_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _MAX17335_DRIVER_H
#define _MAX17335_DRIVER_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
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

#define MAX17335_I2C_RX_BUFFER_SIZE     32
#define MAX17335_I2C_TX_BUFFER_SIZE     32

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
    MAX17335_DRIVER_STATE_INIT = 0,
    MAX17335_DRIVER_STATE_SERVICE_TASKS,
} MAX17335_DRIVER_STATES;

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
    MAX17335_DRIVER_STATES state;

    /* Driver variables */
    DRV_HANDLE I2C_HANDLE;
    DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE;
    volatile bool MAX17335_TASK_START;
    volatile bool MAX17335_TASK_COMPLETED;
    volatile bool MAX17335_ALERT;
    uint8_t I2C_ADDRESS[2];
    uint8_t I2C_DATA_RECEIVE[MAX17335_I2C_RX_BUFFER_SIZE];
    uint8_t I2C_DATA_TRANSMIT[MAX17335_I2C_TX_BUFFER_SIZE];
} MAX17335_DRIVER_DATA;

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

void MAX17335_DRIVER_Initialize(void);

void MAX17335_DRIVER_Tasks(void);

bool MAX17335_DRIVER_Get_Task_Start_Status(void);

void MAX17335_DRIVER_Set_Task_Start_Status(bool STATUS);

bool MAX17335_DRIVER_Get_Task_Completed_Status(void);

void MAX17335_DRIVER_Set_Task_Completed_Status(bool STATUS);

bool MAX17335_DRIVER_Get_Alert_Status(void);

void MAX17335_DRIVER_Set_Alert_Status(bool STATUS);

void MAX17335_DRIVER_Set_I2C_Address(void);

void MAX17335_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _MAX17335_DRIVER_H */

/*******************************************************************************
 End of File
 */