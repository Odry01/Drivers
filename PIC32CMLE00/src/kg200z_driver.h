/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    kg200z_driver.h

  Status:
    In development
 
  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "KG200Z_DRIVER_Initialize" and "KG200Z_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "KG200Z_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _KG200Z_DRIVER_H
#define _KG200Z_DRIVER_H

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

#define KG200Z_RX_DATA_SIZE                            256
#define KG200Z_TX_DATA_SIZE                            256

// *****************************************************************************

typedef enum
{
    KG200Z_DRIVER_STATE_INIT = 0,
    KG200Z_DRIVER_STATE_CHECK_USART_HANDLER,
    KG200Z_DRIVER_STATE_IDLE,
    KG200Z_DRIVER_STATE_ATQ_MESSAGE_TRANSMIT,
    KG200Z_DRIVER_STATE_ATQ_WAIT_FOR_MESSAGE_TRANSMIT,
    KG200Z_DRIVER_STATE_ATQ_READ_MODULE_RESPONSE,
    KG200Z_DRIVER_STATE_ATQ_WAIT_FOR_MESSAGE_RECEIVE,
    KG200Z_DRIVER_STATE_ATQ_STORE_BYTE,
    KG200Z_DRIVER_STATE_ATQ_STORE_END_OF_LINE_COUNT,
    KG200Z_DRIVER_STATE_ATQ_CHECK_CR_LF_COUNT,
    KG200Z_DRIVER_STATE_ATQ_CHECK_MODULE_RESPONSE,
    KG200Z_DRIVER_STATE_TIMER_EXPIRED,
    KG200Z_DRIVER_STATE_ERROR,
} KG200Z_DRIVER_STATES;

// *****************************************************************************

typedef struct
{
    /* The application's current state */
    KG200Z_DRIVER_STATES state;

    /* Driver variables */
    DRV_HANDLE USART_HANDLE;
    DRV_USART_BUFFER_HANDLE USART_BUFFER_HANDLE;
    volatile bool KG200Z_TASK_START;
    volatile bool KG200Z_TASK_COMPLETED;
    volatile bool KG200Z_RESPONSE_STATUS;
    char RX_BYTE;
    char RX_BUFFER[KG200Z_RX_DATA_SIZE];
    char TX_BUFFER[KG200Z_TX_DATA_SIZE];
    uint8_t RX_COUNT;
    uint8_t END_OF_LINE_COUNT;
} KG200Z_DRIVER_DATA;

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

void KG200Z_DRIVER_Initialize(void);

void KG200Z_DRIVER_Tasks(void);

bool KG200Z_DRIVER_Get_Task_Start_Status(void);

void KG200Z_DRIVER_Set_Task_Start_Status(bool STATUS);

bool KG200Z_DRIVER_Get_Task_Completed_Status(void);

void KG200Z_DRIVER_Set_Task_Completed_Status(bool STATUS);

void KG200Z_DRIVER_Write_Command(char *MESSAGE);

void KG200Z_DRIVER_Read_Command(void);

bool KG200Z_DRIVER_Get_Module_Response_Status(void);

void KG200Z_DRIVER_Set_Module_Response_Status(bool KG200Z_RESPONSE_STATUS);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _KG200Z_DRIVER_H */

/*******************************************************************************
 End of File
 */