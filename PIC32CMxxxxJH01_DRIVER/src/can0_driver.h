/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    can0_driver.h

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

/* Application states

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
    CAN0_DRIVER_STATE_CHECK_BUS_STATUS,
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

/* Application Data

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
    bool CAN0_TASK_START;
    bool CAN0_TASK_COMPLETED;
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
        uint64_t EXAMPLE_TRANSIT_DATA_0;
        uint64_t EXAMPLE_TRANSIT_DATA_1;
        uint64_t EXAMPLE_TRANSIT_DATA_2;
        uint64_t EXAMPLE_TRANSIT_DATA_3;
        uint64_t EXAMPLE_TRANSIT_DATA_4;
        uint64_t EXAMPLE_TRANSIT_DATA_5;
        uint64_t EXAMPLE_TRANSIT_DATA_6;
        uint64_t EXAMPLE_TRANSIT_DATA_7;
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

/*******************************************************************************
  Function:
    void CAN0_DRIVER_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    CAN0_DRIVER_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    CAN0_DRIVER_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
 */

void CAN0_DRIVER_Initialize(void);

/*******************************************************************************
  Function:
    void CAN0_DRIVER_Tasks ( void )

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
    CAN0_DRIVER_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void CAN0_DRIVER_Tasks(void);

bool CAN0_DRIVER_Get_Task_Start_Status(void);

void CAN0_DRIVER_Set_Task_Start_Status(bool STATUS);

bool CAN0_DRIVER_Get_Task_Completed_Status(void);

void CAN0_DRIVER_Set_Task_Completed_Status(bool STATUS);

void CAN0_DRIVER_Set_Message_Content(uint32_t ID);

void CAN0_DRIVER_Get_Received_Data(uint8_t NUMBER_OF_MESSAGES, CAN_RX_BUFFER *RX_BUFFER, uint8_t LENGTH_OF_RX_BUFFER);

uint8_t CAN0_DRIVER_Set_DLC(uint8_t LENGTH);

void CAN0_DRIVER_Set_Received_Data(uint64_t DATA_0);

void CAN0_DRIVER_Set_Transmited_Data(uint64_t DATA_0, uint64_t DATA_1, uint64_t DATA_2, uint64_t DATA_3, uint64_t DATA_4, uint64_t DATA_5, uint64_t DATA_6, uint64_t DATA_7);

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