/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    fcm360w_driver.h

  Status:
    In development
 
  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "FCM360W_DRIVER_Initialize" and "FCM360W_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "FCM360W_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _FCM360W_DRIVER_H
#define _FCM360W_DRIVER_H

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

#define FCM360W_RX_DATA_SIZE                            256
#define FCM360W_TX_DATA_SIZE                            256

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
    FCM360W_DRIVER_STATE_INIT = 0,
    FCM360W_DRIVER_STATE_CHECK_USART_HANDLER,
    FCM360W_DRIVER_STATE_QRST_MESSAGE_TRANSMIT,
    FCM360W_DRIVER_STATE_QRST_WAIT_FOR_MESSAGE_TRANSMIT,
    FCM360W_DRIVER_STATE_QRST_READ_MODULE_RESPONSE,
    FCM360W_DRIVER_STATE_QRST_WAIT_FOR_MESSAGE_RECEIVE,
    FCM360W_DRIVER_STATE_QRST_STORE_BYTE,
    FCM360W_DRIVER_STATE_QRST_STORE_END_OF_LINE_COUNT,
    FCM360W_DRIVER_STATE_QRST_CHECK_CR_LF_COUNT,
    FCM360W_DRIVER_STATE_QRST_CHECK_MODULE_RESPONSE,
    FCM360W_DRIVER_STATE_IDLE,
    FCM360W_DRIVER_STATE_TIMER_EXPIRED,
    FCM360W_DRIVER_STATE_ERROR,
} FCM360W_DRIVER_STATES;

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
    FCM360W_DRIVER_STATES state;

    /* Driver variables */
    DRV_HANDLE USART_HANDLE;
    DRV_USART_BUFFER_HANDLE USART_BUFFER_HANDLE;
    volatile bool FCM360W_TASK_START;
    volatile bool FCM360W_TASK_COMPLETED;
    volatile bool FCM360W_RESPONSE_STATUS;
    char RX_BYTE;
    char RX_BUFFER[FCM360W_RX_DATA_SIZE];
    char TX_BUFFER[FCM360W_TX_DATA_SIZE];
    uint8_t RX_COUNT;
    uint8_t END_OF_LINE_COUNT;
} FCM360W_DRIVER_DATA;

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

void FCM360W_DRIVER_Initialize(void);

void FCM360W_DRIVER_Tasks(void);

bool FCM360W_DRIVER_Get_Task_Start_Status_Get(void);

void FCM360W_DRIVER_Set_Task_Start_Status(bool STATUS);

bool FCM360W_DRIVER_Get_Task_Completed_Status(void);

void FCM360W_DRIVER_Set_Task_Completed_Status(bool STATUS);

void FCM360W_DRIVER_Write_Command(char *MESSAGE);

void FCM360W_DRIVER_Read_Command(void);

bool FCM360W_DRIVER_Get_Module_Response_Status(void);

void FCM360W_DRIVER_Set_Module_Response_Status(bool FCM360W_RESPONSE_STATUS);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _FCM360W_DRIVER_H */

/*******************************************************************************
 End of File
 */