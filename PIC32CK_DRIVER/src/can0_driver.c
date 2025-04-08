/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    can0_driver.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "can0_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the CAN0_DRIVER_Initialize function.

    Application strings and buffers are be defined outside this structure.
 */

CAN0_DRIVER_DATA can0_driverData;

CAN0_DATA_TX can0DataTx;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

bool CAN0_DRIVER_Get_Task_Start_Status(void)
{
    return (can0_driverData.CAN0_TASK_START);
}

void CAN0_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    can0_driverData.CAN0_TASK_START = STATUS;
}

bool CAN0_DRIVER_Get_Task_Completed_Status(void)
{
    return (can0_driverData.CAN0_TASK_COMPLETED);
}

void CAN0_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    can0_driverData.CAN0_TASK_COMPLETED = STATUS;
}

void CAN0_DRIVER_Set_Message_Content(uint32_t ID)
{
    memset(can0_driverData.TX_FIFO, 0x00, CAN0_TX_FIFO_BUFFER_ELEMENT_SIZE);
    can0_driverData.TX_BUFFER = (CAN_TX_BUFFER *) can0_driverData.TX_FIFO;
    can0_driverData.TX_BUFFER->id = CAN0_WRITE_ID(ID);
    can0_driverData.TX_BUFFER->dlc = CAN0_DRIVER_Set_DLC(CAN0_DATA_TX_BYTES);
    can0_driverData.TX_BUFFER->fdf = 1;
    can0_driverData.TX_BUFFER->brs = 1;

    for (uint8_t i = 0; i < CAN0_DATA_TX_BYTES; i++)
    {
        can0_driverData.TX_BUFFER->data[i] = can0DataTx.bytes[i];
    }
}

void CAN0_DRIVER_Get_Received_Data(uint8_t NUMBER_OF_MESSAGES, CAN_RX_BUFFER *RX_BUFFER, uint8_t LENGTH_OF_RX_BUFFER)
{
    uint32_t ID = 0;

    for (uint8_t COUNT = 0; COUNT < NUMBER_OF_MESSAGES; COUNT++)
    {
        ID = RX_BUFFER->xtd ? RX_BUFFER->id : CAN0_READ_ID(RX_BUFFER->id);

        if (ID == 0xF)
        {

            typedef union
            {

                struct
                {
                    uint64_t DATA_0;
                    uint64_t DATA_1;
                    uint64_t DATA_2;
                    uint64_t DATA_3;
                    uint64_t DATA_4;
                    uint64_t DATA_5;
                    uint64_t DATA_6;
                    uint64_t DATA_7;
                } fields;
                uint8_t bytes[64];
            } CAN0_DATA_RX;

            CAN0_DATA_RX can0DataRx;

            for (uint8_t i = 0; i < 64; i++)
            {
                can0DataRx.bytes[i] = RX_BUFFER->data[i];
            }

            CAN0_DRIVER_Set_Data_Status(can0DataRx.fields.DATA_0);
        }
        RX_BUFFER += LENGTH_OF_RX_BUFFER;
    }
}

uint8_t CAN0_DRIVER_Set_DLC(uint8_t LENGTH)
{
    uint8_t DLC;

    if (LENGTH <= 8)
    {
        DLC = LENGTH;
    }
    else if (LENGTH <= 12)
    {
        DLC = 0x9;
    }
    else if (LENGTH <= 16)
    {
        DLC = 0xA;
    }
    else if (LENGTH <= 20)
    {
        DLC = 0xB;
    }
    else if (LENGTH <= 24)
    {
        DLC = 0xC;
    }
    else if (LENGTH <= 32)
    {
        DLC = 0xD;
    }
    else if (LENGTH <= 48)
    {
        DLC = 0xE;
    }
    else
    {
        DLC = 0xF;
    }
    return DLC;
}

void CAN0_DRIVER_Set_Data(uint64_t DATA_0, uint64_t DATA_1, uint64_t DATA_2, uint64_t DATA_3, uint64_t DATA_4, uint64_t DATA_5, uint64_t DATA_6, uint64_t DATA_7)
{
    can0DataTx.data.DATA_0 = DATA_0;
    can0DataTx.data.DATA_1 = DATA_1;
    can0DataTx.data.DATA_2 = DATA_2;
    can0DataTx.data.DATA_3 = DATA_3;
    can0DataTx.data.DATA_4 = DATA_4;
    can0DataTx.data.DATA_5 = DATA_5;
    can0DataTx.data.DATA_6 = DATA_6;
    can0DataTx.data.DATA_7 = DATA_7;
}

void CAN0_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)
{
    CAN0_ErrorCountGet(&can0_driverData.TX_ERROR_COUNT, &can0_driverData.RX_ERROR_COUNT);
    SYS_CONSOLE_Print
            (
             CONSOLE_HANDLE,
             "CAN0 TX error count: %d\r\n"
             "CAN0 RX error count: %d\r\n", can0_driverData.TX_ERROR_COUNT, can0_driverData.RX_ERROR_COUNT
             );
}



// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void CAN0_DRIVER_Initialize ( void )

  Remarks:
    See prototype in can0_driver.h.
 */

void CAN0_DRIVER_Initialize(void)
{
    can0_driverData.state = CAN0_DRIVER_STATE_INIT;
    CAN0_MessageRAMConfigSet(can0_driverData.CAN0_RAM_ALOCATION);
}

/******************************************************************************
  Function:
    void CAN0_DRIVER_Tasks ( void )

  Remarks:
    See prototype in can0_driver.h.
 */

void CAN0_DRIVER_Tasks(void)
{
    switch (can0_driverData.state)
    {
        case CAN0_DRIVER_STATE_INIT:
        {
            bool appInitialized = true;


            if (appInitialized)
            {

                can0_driverData.state = CAN0_DRIVER_STATE_SERVICE_TASKS;
            }
            break;
        }

        case CAN0_DRIVER_STATE_SERVICE_TASKS:
        {

            break;
        }
        
        default:
        {
            break;
        }
    }
}