/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    can0_driver.h

  Status:
    In development
 
  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "CAN0_DRIVER_Initialize" and "CAN0_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "CAN0_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _CAN0_DRIVER_H
#define _CAN0_DRIVER_H

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

#define CAN0_WRITE_ID(ID)   (ID << 18)
#define CAN0_READ_ID(ID)    (ID >> 18)
#define CAN0_MESSAGE_ID     0x1
#define CAN0_DATA_TX_BYTES  64

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
    CAN0_DRIVER_STATE_INIT = 0,
    CAN0_DRIVER_STATE_IDLE,
    CAN0_DRIVER_STATE_CHECK_BUS_OFF_INTERRUPT,
    CAN0_DRIVER_STATE_CHECK_BUS_ERROR_STATUS,
    CAN0_DRIVER_STATE_CHECK_NEW_MESSAGE_INTERRUPT_RX_FIFO0,
    CAN0_DRIVER_STATE_GET_MESSAGE_COUNT_RX_FIFO0,
    CAN0_DRIVER_STATE_RECEIVE_MESSAGE_RX_FIFO0,
    CAN0_DRIVER_STATE_CHECK_NEW_MESSAGE_INTERRUPT_RX_FIFO1,
    CAN0_DRIVER_STATE_GET_MESSAGE_COUNT_RX_FIFO1,
    CAN0_DRIVER_STATE_RECEIVE_MESSAGE_RX_FIFO1,
    CAN0_DRIVER_STATE_SET_CONTENT_TRANSMIT_MESSAGE,
    CAN0_DRIVER_STATE_MESSAGE_TRANSMIT,
    CAN0_DRIVER_STATE_ERROR,
} CAN0_DRIVER_STATES;

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
    CAN0_DRIVER_STATES state;

    /* Driver variables */
    CAN_TX_BUFFER *TX_BUFFER;
    volatile bool CAN0_TASK_START;
    volatile bool CAN0_TASK_COMPLETED;
    uint8_t TX_ERROR_COUNT;
    uint8_t RX_ERROR_COUNT;
    uint8_t RX_FIFO0_MESSAGE_COUNT;
    uint8_t RX_FIFO1_MESSAGE_COUNT;
    uint8_t TX_FIFO[CAN0_TX_FIFO_BUFFER_SIZE];
    uint8_t RX_FIFO0[CAN0_RX_FIFO0_SIZE];
    uint8_t RX_FIFO1[CAN0_RX_FIFO1_SIZE];
    uint8_t CAN0_RAM_ALOCATION[CAN0_MESSAGE_RAM_CONFIG_SIZE] __attribute__((aligned(32)));
    uint64_t EXAMPLE_RECEIVE_DATA_0;
} CAN0_DRIVER_DATA;

typedef union
{

    struct
    {
        uint64_t EXAMPLE_TRANSMIT_DATA_0;
        uint64_t EXAMPLE_TRANSMIT_DATA_1;
        uint64_t EXAMPLE_TRANSMIT_DATA_2;
        uint64_t EXAMPLE_TRANSMIT_DATA_3;
        uint64_t EXAMPLE_TRANSMIT_DATA_4;
        uint64_t EXAMPLE_TRANSMIT_DATA_5;
        uint64_t EXAMPLE_TRANSMIT_DATA_6;
        uint64_t EXAMPLE_TRANSMIT_DATA_7;
    } data;
    uint8_t bytes[CAN0_DATA_TX_BYTES];
} CAN0_DATA_TX;

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
    void CAN0_DRIVER_Initialize(void)

    Summary:
    Performs initialization of driver for console.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void CAN0_DRIVER_Initialize(void);

/**
    Function:
    void CAN0_DRIVER_Tasks(void)

    Summary:
    Executes periodic tasks.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void CAN0_DRIVER_Tasks(void);

/**
    Function:
    bool CAN0_DRIVER_Get_Task_Start_Status(void)

    Summary:
    Retrieves the "TASK_START" flag.

    Parameters:
    None.

    Returns:
    @return bool - true if a task has been started otherwise is not

    Remarks:
    None.
 */
bool CAN0_DRIVER_Get_Task_Start_Status(void);

/**
    Function:
    void CAN0_DRIVER_Set_Task_Start_Status(bool STATUS)

    Summary:
    Sets the "TASK_START" flag

    Parameters:
    @param STATUS - desired state of the "TASK_START" flag

    Returns:
    None.

    Remarks:
    None.
 */
void CAN0_DRIVER_Set_Task_Start_Status(bool STATUS);

/**
    Function:
    bool CAN0_DRIVER_Get_Task_Completed_Status(void)

    Summary:
    Retrieves the "TASK_COMPLETED" flag.

    Parameters:
    None.

    Returns:
    @return bool - true if a task has been completed otherwise is not

    Remarks:
    None.
 */
bool CAN0_DRIVER_Get_Task_Completed_Status(void);

/**
    Function:
    void CAN0_DRIVER_Set_Task_Completed_Status(bool STATUS)

    Summary:
    Sets the "TASK_COMPLETED" flag

    Parameters:
    @param STATUS - desired state of the "TASK_COMPLETED" flag

    Returns:
    None.

    Remarks:
    None.
 */
void CAN0_DRIVER_Set_Task_Completed_Status(bool STATUS);

/**
    Function:
    void CAN0_DRIVER_Set_Message_Content(uint32_t ID)

    Summary:
    Sets the CAN identifier for the next message to transmit.

    Parameters:
    @param ID - message identifier

    Returns:
    None.

    Remarks:
    None.
 */
void CAN0_DRIVER_Set_Message_Content(uint32_t ID);

/**
    Function:
    void CAN0_DRIVER_Get_Received_Data(uint8_t NUMBER_OF_MESSAGES, CAN_RX_BUFFER *RX_BUFFER, uint8_t LENGTH_OF_RX_BUFFER)

    Summary:
    Copies received CAN frames into a user variables.

    Parameters:
    @param NUMBER_OF_MESSAGES - message count
    @param RX_BUFFER - pointer to RX buffer structure
    @param LENGTH_OF_RX_BUFFER- number of received bytes

    Returns:
    None.

    Remarks:
    None.
 */
void CAN0_DRIVER_Get_Received_Data(uint8_t NUMBER_OF_MESSAGES, CAN_RX_BUFFER *RX_BUFFER, uint8_t LENGTH_OF_RX_BUFFER);

/**
    Function:
    uint8_t CAN0_DRIVER_Set_DLC(uint8_t LENGTH)

    Summary:
    Sets the DLC for a transmit frame.

    Parameters:
    @param LENGTH - data bytes count

    Returns:
    @return uint8_t - DLC value

    Remarks:
    None.
 */
uint8_t CAN0_DRIVER_Set_DLC(uint8_t LENGTH);

/**
    Function:
    void CAN0_DRIVER_Set_Received_Data(uint64_t DATA_0)

    Summary:
    Loads a 64 bit word into the variables from receive buffer.

    Parameters:
    @param DATA_0 - 64 bit data word

    Returns:
    None.

    Remarks:
    That data is it there only as example. Use own params for this function.
 */
void CAN0_DRIVER_Set_Received_Data(uint64_t DATA_0);

/**
    Function:
    void CAN0_DRIVER_Set_Transmited_Data(uint64_t EXAMPLE_TRANSMIT_DATA_0, uint64_t EXAMPLE_TRANSMIT_DATA_1, uint64_t EXAMPLE_TRANSMIT_DATA_2, uint64_t EXAMPLE_TRANSMIT_DATA_3, uint64_t EXAMPLE_TRANSMIT_DATA_4, uint64_t EXAMPLE_TRANSMIT_DATA_5, uint64_t EXAMPLE_TRANSMIT_DATA_6, uint64_t EXAMPLE_TRANSMIT_DATA_7)
    Summary:
    Loads up to eight 64 bit words into the transmit buffer.

    Parameters:
    @param EXAMPLE_TRANSMIT_DATA_0 - first byte payload segment
    @param EXAMPLE_TRANSMIT_DATA_1 - second payload segment
    @param EXAMPLE_TRANSMIT_DATA_2 - third payload segment
    @param EXAMPLE_TRANSMIT_DATA_3 - fourth payload segment
    @param EXAMPLE_TRANSMIT_DATA_4 - fifth payload segment
    @param EXAMPLE_TRANSMIT_DATA_5 - sixth payload segment
    @param EXAMPLE_TRANSMIT_DATA_6 - seventh payload segment
    @param EXAMPLE_TRANSMIT_DATA_7 - eighth payload segment

    Returns:
    None.

    Remarks:
    That data is it there only as example. Use own params for this function.
 */
void CAN0_DRIVER_Set_Transmited_Data(uint64_t EXAMPLE_TRANSMIT_DATA_0, uint64_t EXAMPLE_TRANSMIT_DATA_1, uint64_t EXAMPLE_TRANSMIT_DATA_2, uint64_t EXAMPLE_TRANSMIT_DATA_3, uint64_t EXAMPLE_TRANSMIT_DATA_4, uint64_t EXAMPLE_TRANSMIT_DATA_5, uint64_t EXAMPLE_TRANSMIT_DATA_6, uint64_t EXAMPLE_TRANSMIT_DATA_7);

/**
    Function:
    void CAN0_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)

    Summary:
    Prints the text to a console.

    Parameters:
    @param CONSOLE_HANDLE - console handle returned by the library

    Returns:
    None.

    Remarks:
    For reading a text use TeraTerm, CoolTerm, etc.
 */
void CAN0_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _CAN0_DRIVER_H */

/*******************************************************************************
 End of File
 */