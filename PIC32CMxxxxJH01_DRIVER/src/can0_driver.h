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

/**
    Function:
    void CAN0_DRIVER_Initialize(void)

    Summary:
    Initializes the CAN0 driver module.

    Description:
    This routine performs all one‑time configuration required for the
    CAN0 peripheral.  It sets up the hardware registers, configures
    interrupts, and clears any pending status flags so that
    CAN0_DRIVER_Tasks() can operate correctly.

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
    Main task routine for the CAN0 driver.

    Description:
    This function contains the state‑machine that manages all CAN0
    operations.  It polls for new messages, handles transmission,
    updates status flags and performs any necessary error handling.
    It is intended to be called repeatedly from the application loop.

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
    Retrieves the current “task start” flag for CAN0.

    Description:
    Indicates whether a new CAN operation has been requested.  
    The application sets this flag via
    CAN0_DRIVER_Set_Task_Start_Status(true) and clears it when processing is finished.

    Parameters:
    None.

    Returns:
    @return bool – `true` if a task is pending, otherwise `false`.

    Remarks:
    None.
 */
bool CAN0_DRIVER_Get_Task_Start_Status(void);

/**
    Function:
    void CAN0_DRIVER_Set_Task_Start_Status(bool STATUS)

    Summary:
    Sets the “task start” flag for CAN0.

    Description:
    Allows the application to signal that a new CAN transaction should begin.  
    The driver will act on this flag during its next call to
    CAN0_DRIVER_Tasks().

    Parameters:
    @param bool STATUS – Desired state of the task‑start flag (`true` = pending, `false` = cleared).

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
    Retrieves the current “task completed” flag for CAN0.

    Description:
    Indicates whether the most recent CAN transaction has finished
    successfully.  The driver sets this flag when all messages have been
    sent or received and processed.

    Parameters:
    None.

    Returns:
    @return bool – `true` if the last task is complete, otherwise `false`.

    Remarks:
    None.
 */
bool CAN0_DRIVER_Get_Task_Completed_Status(void);

/**
    Function:
    void CAN0_DRIVER_Set_Task_Completed_Status(bool STATUS)

    Summary:
    Sets the “task completed” flag for CAN0.

    Description:
    Allows the driver to mark a CAN transaction as finished.  
    The application may clear this flag when it is ready for another
    operation.

    Parameters:
    @param bool STATUS – Desired state of the task‑completed flag (`true` = complete, `false` = not yet).

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
    Sets the identifier for a CAN message to be transmitted.

    Description:
    The routine stores the supplied 11‑bit or 29‑bit identifier into
    the driver’s transmit buffer.  The actual transmission occurs when
    CAN0_DRIVER_Tasks() processes the queued message.

    Parameters:
    @param uint32_t ID – CAN identifier (11‑bit standard or 29‑bit extended).

    Returns:
    None.

    Remarks:
    The caller should ensure that `ID` conforms to the CAN framing rules
    for the selected frame type.
 */
void CAN0_DRIVER_Set_Message_Content(uint32_t ID);

/**
    Function:
    void CAN0_DRIVER_Get_Received_Data(uint8_t NUMBER_OF_MESSAGES, CAN_RX_BUFFER *RX_BUFFER, uint8_t LENGTH_OF_RX_BUFFER)

    Summary:
    Copies received CAN data into a user‑supplied buffer.

    Description:
    This routine reads up to `NUMBER_OF_MESSAGES` from the driver’s
    receive queue and copies them into the array pointed to by
    `RX_BUFFER`.  The caller must allocate at least
    `LENGTH_OF_RX_BUFFER` entries; if more messages are pending,
    the excess will be discarded.  Each entry in `CAN_RX_BUFFER`
    contains the message identifier, data length code (DLC), and payload.

    Parameters:
    @param uint8_t NUMBER_OF_MESSAGES – Maximum number of messages to retrieve.
    @param CAN_RX_BUFFER *RX_BUFFER – Pointer to an array that will receive the data.
    @param uint8_t LENGTH_OF_RX_BUFFER – Size of the `RX_BUFFER` array in elements.

    Returns:
    None.

    Remarks:
    The function does not return a status; it is the caller’s
    responsibility to verify that enough space was provided.
 */
void CAN0_DRIVER_Get_Received_Data(uint8_t NUMBER_OF_MESSAGES, CAN_RX_BUFFER *RX_BUFFER, uint8_t LENGTH_OF_RX_BUFFER);

/**
    Function:
    uint8_t CAN0_DRIVER_Set_DLC(uint8_t LENGTH)

    Summary:
    Sets the Data Length Code (DLC) for a CAN message.

    Description:
    The routine validates `LENGTH` (0‑8 bytes for standard frames, 0‑64 for extended
    frames) and stores it in the driver’s transmit buffer.  It returns the
    actual DLC value that will be transmitted (which may be truncated if
    invalid).

    Parameters:
    @param uint8_t LENGTH – Desired number of data bytes.

    Returns:
    @return uint8_t – The DLC that was accepted by the driver.

    Remarks:
    For extended frames the maximum valid value is 64; values greater than
    this are clipped to 64.
 */
uint8_t CAN0_DRIVER_Set_DLC(uint8_t LENGTH);

/**
    Function:
    void CAN0_DRIVER_Set_Received_Data(uint64_t DATA_0)

    Summary:
    Stores a received data word into the driver’s internal buffer.

    Description:
    The routine copies `DATA_0` into the first slot of the receive
    buffer.  This is typically used by lower‑level ISR code to pass
    received payloads up to the application layer.

    Parameters:
    @param uint64_t DATA_0 – 8‑byte data word received from CAN.

    Returns:
    None.

    Remarks:
    Only the most recent value is retained; subsequent calls overwrite it.
 */
void CAN0_DRIVER_Set_Received_Data(uint64_t DATA_0);

/**
    Function:
    void CAN0_DRIVER_Set_Transmited_Data(uint64_t DATA_0, uint64_t DATA_1, uint64_t DATA_2, uint64_t DATA_3, uint64_t DATA_4, uint64_t DATA_5, uint64_t DATA_6, uint64_t DATA_7)

    Summary:
    Copies eight 8‑byte words into the CAN transmit buffer.

    Description:
    The routine stores up to 64 bytes of payload data (the maximum
    DLC for an extended frame).  Each argument represents one 8‑byte
    segment; unused segments may be set to zero.  The driver will send
    the concatenated payload when it processes the queued message.

    Parameters:
    @param uint64_t DATA_0 – First 8‑byte segment of the payload.
    @param uint64_t DATA_1 – Second 8‑byte segment.
    @param uint64_t DATA_2 – Third 8‑byte segment.
    @param uint64_t DATA_3 – Fourth 8‑byte segment.
    @param uint64_t DATA_4 – Fifth 8‑byte segment.
    @param uint64_t DATA_5 – Sixth 8‑byte segment.
    @param uint64_t DATA_6 – Seventh 8‑byte segment.
    @param uint64_t DATA_7 – Eighth 8‑byte segment.

    Returns:
    None.

    Remarks:
    If the DLC is less than 64 bytes, only the leading segments
    are transmitted; the remaining segments are ignored.
 */
void CAN0_DRIVER_Set_Transmited_Data(uint64_t DATA_0, uint64_t DATA_1, uint64_t DATA_2, uint64_t DATA_3, uint64_t DATA_4, uint64_t DATA_5, uint64_t DATA_6, uint64_t DATA_7);

/**
    Function:
    void CAN0_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)

    Summary:
    Prints the current state of the CAN0 driver to a console.

    Description:
    The routine writes human‑readable information – such as
    transmit/receive queues, error counters, and last message contents –
    to the specified `SYS_CONSOLE_HANDLE`.  It is intended for debugging
    and diagnostic purposes only.

    Parameters:
    @param SYS_CONSOLE_HANDLE CONSOLE_HANDLE – Handle to an MPLAB Harmony console object.

    Returns:
    None.

    Remarks:
    The output format follows the conventions used by the rest of the
    application’s logging system.
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