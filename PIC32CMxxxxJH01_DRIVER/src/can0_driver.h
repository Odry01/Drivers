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
   CAN0_DRIVER_Initialize

   Summary:
   Performs one‑time initialization of the CAN‑0 driver.

   Description:
   This routine configures the underlying CAN peripheral, sets up
   interrupts or DMA if used, and clears all internal status flags.
   It must be called once during system boot before any other
   CAN0_DRIVER_* functions are invoked.

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
   CAN0_DRIVER_Tasks

   Summary:
   Executes periodic driver tasks; should be called repeatedly.

   Description:
   The routine checks the CAN controller for new messages, handles
   transmission completions, and updates internal status flags.
   It is typically invoked from the main loop or a scheduler tick.

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
   CAN0_DRIVER_Get_Task_Start_Status

   Summary:
   Retrieves the “task start” flag for the driver.

   Description:
   The flag is set when a new message or configuration has been
   queued and cleared once the driver starts processing it.
   Application code can poll this flag to decide whether to
   issue another operation.

   Parameters:
   None.

   Returns:
   @return bool - true if a task has been requested but not yet started

   Remarks:
   None.
 */
bool CAN0_DRIVER_Get_Task_Start_Status(void);

/**
   Function:
   CAN0_DRIVER_Set_Task_Start_Status

   Summary:
   Sets the “task start” flag for the driver.

   Description:
   Passing `true` queues a new task; passing `false`
   clears the flag.  The driver will act on this flag during its
   next call to *CAN0_DRIVER_Tasks()*.

   Parameters:
   @param STATUS - desired state of the task‑start flag

   Returns:
   None.

   Remarks:
   None.
 */
void CAN0_DRIVER_Set_Task_Start_Status(bool STATUS);

/**
   Function:
   CAN0_DRIVER_Get_Task_Completed_Status

   Summary:
   Retrieves the “task completed” flag for the driver.

   Description:
   The flag is set to `true` when a queued operation (e.g. message
   transmission) finishes successfully.  Polling this flag allows
   the application to know when it can safely issue another task.

   Parameters:
   None.

   Returns:
   @return bool - true if the most recent task has finished

   Remarks:
   None.
 */
bool CAN0_DRIVER_Get_Task_Completed_Status(void);

/**
   Function:
   CAN0_DRIVER_Set_Task_Completed_Status

   Summary:
   Sets the “task completed” flag for the driver.

   Description:
   Passing `true` indicates that a configuration or transmission
   operation has finished; passing `false` clears the flag so
   the next operation can be started.  The flag is normally cleared
   automatically by the driver, but this setter allows manual control.

   Parameters:
   @param STATUS - desired state of the task‑completed flag

   Returns:
   None.

   Remarks:
   None.
 */
void CAN0_DRIVER_Set_Task_Completed_Status(bool STATUS);

/**
   Function:
   CAN0_DRIVER_Set_Message_Content

   Summary:
   Sets the CAN identifier for the next message to transmit.

   Description:
   The `ID` parameter is a standard (11‑bit) or extended
   (29‑bit) CAN ID.  It is stored in an internal transmit buffer
   and will be used by *CAN0_DRIVER_Tasks()* when sending the
   message.

   Parameters:
   @param ID - 32‑bit identifier (only lower 11 or 29 bits are used)

   Returns:
   None.

   Remarks:
   The driver automatically clears the “task start” flag once the
   transmission begins.
 */
void CAN0_DRIVER_Set_Message_Content(uint32_t ID);

/**
   Function:
   CAN0_DRIVER_Get_Received_Data

   Summary:
   Copies received CAN frames into a user‑supplied buffer.

   Description:
   The routine reads up to `NUMBER_OF_MESSAGES` frames from the
   driver’s receive FIFO, stores them in `RX_BUFFER`, and returns
   the actual number of frames copied.  `LENGTH_OF_RX_BUFFER`
   specifies how many entries are available in `RX_BUFFER` to avoid
   overruns.  Each element of `CAN_RX_BUFFER` should contain at
   least: ID, DLC, data[8], and a timestamp (if used).

   Parameters:
   @param NUMBER_OF_MESSAGES - maximum frames to copy
   @param RX_BUFFER          - pointer to caller‑allocated buffer
   @param LENGTH_OF_RX_BUFFER- size of the supplied buffer in entries

   Returns:
   None.

   Remarks:
   If more messages are pending than `LENGTH_OF_RX_BUFFER`,
   excess frames are discarded and an error flag may be set.
 */
void CAN0_DRIVER_Get_Received_Data(uint8_t NUMBER_OF_MESSAGES,
                                   CAN_RX_BUFFER *RX_BUFFER,
                                   uint8_t LENGTH_OF_RX_BUFFER);

/**
   Function:
   CAN0_DRIVER_Set_DLC

   Summary:
   Sets the Data Length Code (DLC) for a transmit frame.

   Description:
   `LENGTH` must be in the range 0‑8.  The function stores the
   value internally and returns it, allowing simple validation.
   If an invalid length is supplied, the driver may clamp to the
   nearest valid value or return an error code (implementation
   dependent).

   Parameters:
   @param LENGTH - desired DLC (number of data bytes)

   Returns:
   @return uint8_t - the accepted DLC (0‑8) or 0xFF on error

   Remarks:
   The driver applies this DLC when building the transmit frame.
 */
uint8_t CAN0_DRIVER_Set_DLC(uint8_t LENGTH);

/**
   Function:
   CAN0_DRIVER_Set_Received_Data

   Summary:
   Loads a 64‑bit word into the driver’s receive buffer.

   Description:
   This routine is primarily used for testing or simulation
   (e.g., when no physical CAN bus is present).  The supplied
   `DATA_0` value is copied to an internal structure that will be
   reported by *CAN0_DRIVER_Get_Received_Data()* as if it had been
   received from the bus.

   Parameters:
   @param DATA_0 - 64‑bit data word (only lower 8 bytes are used)

   Returns:
   None.

   Remarks:
   In normal operation, incoming frames come directly from hardware;
   this API is for mock or diagnostic use.
 */
void CAN0_DRIVER_Set_Received_Data(uint64_t DATA_0);

/**
   Function:
   CAN0_DRIVER_Set_Transmited_Data

   Summary:
   Loads up to eight 64‑bit words into the transmit buffer.

   Description:
   Each `DATA_n` argument represents a 8‑byte segment of the
   payload.  The driver concatenates them, applies the DLC,
   and transmits the resulting frame when *CAN0_DRIVER_Tasks()*
   is called.  Only the first `DLC` bytes are actually sent; the
   remaining words are ignored.

   Parameters:
   @param DATA_0 - first 8‑byte payload segment
   @param DATA_1 - second payload segment
   @param DATA_2 - third payload segment
   @param DATA_3 - fourth payload segment
   @param DATA_4 - fifth payload segment
   @param DATA_5 - sixth payload segment
   @param DATA_6 - seventh payload segment
   @param DATA_7 - eighth payload segment

   Returns:
   None.

   Remarks:
   For convenience, the API accepts 8 words even though only up to
   8 bytes can be transmitted.  Excess words are silently discarded.
 */
void CAN0_DRIVER_Set_Transmited_Data(uint64_t DATA_0,
                                     uint64_t DATA_1,
                                     uint64_t DATA_2,
                                     uint64_t DATA_3,
                                     uint64_t DATA_4,
                                     uint64_t DATA_5,
                                     uint64_t DATA_6,
                                     uint64_t DATA_7);

/**
   Function:
   CAN0_DRIVER_Print_Data

   Summary:
   Prints the current transmit/receive status to a console.

   Description:
   The routine outputs human‑readable information – such as
   last transmitted ID, DLC, payload bytes, and any error flags –
   through the specified `SYS_CONSOLE_HANDLE`.  It is intended for
   debugging or diagnostic sessions; no data is sent over CAN.

   Parameters:
   @param CONSOLE_HANDLE - handle returned by the system console API

   Returns:
   None.

   Remarks:
   The exact format of the output depends on the implementation
   of `SYS_CONSOLE_PRINT`.  Use this function only in non‑real‑time
   builds, as it may block.
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