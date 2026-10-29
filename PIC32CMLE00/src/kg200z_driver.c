/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    kg200z_driver.c

  Status:
    In development
 
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

#include "kg200z_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

KG200Z_DRIVER_DATA kg200z_driverData;

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

bool KG200Z_DRIVER_Get_Task_Start_Status(void)
{
    return (kg200z_driverData.KG200Z_TASK_START);
}

void KG200Z_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    kg200z_driverData.KG200Z_TASK_START = STATUS;
}

bool KG200Z_DRIVER_Get_Task_Completed_Status(void)
{
    return (kg200z_driverData.KG200Z_TASK_COMPLETED);
}

void KG200Z_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    kg200z_driverData.KG200Z_TASK_COMPLETED = STATUS;
}

void KG200Z_DRIVER_Write_Command(char *MESSAGE)
{
    memset(kg200z_driverData.TX_BUFFER, 0, sizeof (kg200z_driverData.TX_BUFFER));
    sprintf(kg200z_driverData.TX_BUFFER, "%s\r\n", MESSAGE);
    DRV_USART_WriteBufferAdd(kg200z_driverData.USART_HANDLE, &kg200z_driverData.TX_BUFFER, strlen(kg200z_driverData.TX_BUFFER), &kg200z_driverData.USART_BUFFER_HANDLE);
}

void KG200Z_DRIVER_Read_Command(void)
{
    DRV_USART_ReadBufferAdd(kg200z_driverData.USART_HANDLE, &kg200z_driverData.RX_BYTE, 1, &kg200z_driverData.USART_BUFFER_HANDLE);
}

bool KG200Z_DRIVER_Get_Module_Response_Status(void)
{
    return (kg200z_driverData.KG200Z_RESPONSE_STATUS);
}

void KG200Z_DRIVER_Set_Module_Response_Status(bool KG200Z_RESPONSE_STATUS)
{
    kg200z_driverData.KG200Z_RESPONSE_STATUS = KG200Z_RESPONSE_STATUS;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void KG200Z_DRIVER_Initialize(void)
{
    kg200z_driverData.state = KG200Z_DRIVER_STATE_INIT;
    kg200z_driverData.USART_HANDLE = DRV_HANDLE_INVALID;
    kg200z_driverData.USART_BUFFER_HANDLE = DRV_USART_BUFFER_HANDLE_INVALID;
}

void KG200Z_DRIVER_Tasks(void)
{
    switch (kg200z_driverData.state)
    {
        case KG200Z_DRIVER_STATE_INIT:
        {
            kg200z_driverData.USART_HANDLE = DRV_USART_Open(DRV_USART_INDEX_0, DRV_IO_INTENT_READWRITE);
            kg200z_driverData.state = KG200Z_DRIVER_STATE_CHECK_USART_HANDLER;
            break;
        }

        case KG200Z_DRIVER_STATE_CHECK_USART_HANDLER:
        {
            if (kg200z_driverData.USART_HANDLE == DRV_HANDLE_INVALID)
            {
                kg200z_driverData.state = KG200Z_DRIVER_STATE_ERROR;
            }
            else
            {
                kg200z_driverData.state = KG200Z_DRIVER_STATE_IDLE;
            }
            break;
        }

        case KG200Z_DRIVER_STATE_IDLE:
        {
            if (KG200Z_DRIVER_Get_Task_Start_Status() == true)
            {
                kg200z_driverData.state = KG200Z_DRIVER_STATE_ATQ_MESSAGE_TRANSMIT;
            }
            break;
        }

        case KG200Z_DRIVER_STATE_ATQ_MESSAGE_TRANSMIT:
        {
            char TX_BUFFER[KG200Z_TX_DATA_SIZE];
            snprintf(TX_BUFFER, sizeof (TX_BUFFER), "ATQ");
            KG200Z_DRIVER_Write_Command(TX_BUFFER);
            TIMER_DRIVER_Start_Bus_TMR();
            kg200z_driverData.state = KG200Z_DRIVER_STATE_ATQ_WAIT_FOR_MESSAGE_TRANSMIT;
            break;
        }

        case KG200Z_DRIVER_STATE_ATQ_WAIT_FOR_MESSAGE_TRANSMIT:
        {
            if (DRV_USART_BufferStatusGet(kg200z_driverData.USART_BUFFER_HANDLE) == DRV_USART_BUFFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                kg200z_driverData.state = KG200Z_DRIVER_STATE_ATQ_READ_MODULE_RESPONSE;
            }
            else if (DRV_USART_BufferStatusGet(kg200z_driverData.USART_BUFFER_HANDLE) == DRV_USART_BUFFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                kg200z_driverData.state = KG200Z_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                kg200z_driverData.state = KG200Z_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case KG200Z_DRIVER_STATE_ATQ_READ_MODULE_RESPONSE:
        {
            KG200Z_DRIVER_Read_Command();
            TIMER_DRIVER_Start_Bus_TMR();
            kg200z_driverData.state = KG200Z_DRIVER_STATE_ATQ_WAIT_FOR_MESSAGE_RECEIVE;
            break;
        }

        case KG200Z_DRIVER_STATE_ATQ_WAIT_FOR_MESSAGE_RECEIVE:
        {
            if (DRV_USART_BufferStatusGet(kg200z_driverData.USART_BUFFER_HANDLE) == DRV_USART_BUFFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                kg200z_driverData.state = KG200Z_DRIVER_STATE_ATQ_STORE_BYTE;
            }
            else if (DRV_USART_BufferStatusGet(kg200z_driverData.USART_BUFFER_HANDLE) == DRV_USART_BUFFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                kg200z_driverData.state = KG200Z_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                kg200z_driverData.state = KG200Z_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case KG200Z_DRIVER_STATE_ATQ_STORE_BYTE:
        {
            kg200z_driverData.RX_BUFFER[kg200z_driverData.RX_COUNT] = kg200z_driverData.RX_BYTE;
            kg200z_driverData.RX_COUNT++;
            kg200z_driverData.state = KG200Z_DRIVER_STATE_ATQ_STORE_END_OF_LINE_COUNT;
            break;
        }

        case KG200Z_DRIVER_STATE_ATQ_STORE_END_OF_LINE_COUNT:
        {
            if (kg200z_driverData.RX_BYTE == '\n')
            {
                kg200z_driverData.END_OF_LINE_COUNT++;
                kg200z_driverData.state = KG200Z_DRIVER_STATE_ATQ_CHECK_CR_LF_COUNT;
            }
            else
            {
                kg200z_driverData.state = KG200Z_DRIVER_STATE_ATQ_READ_MODULE_RESPONSE;
            }
            break;
        }

        case KG200Z_DRIVER_STATE_ATQ_CHECK_CR_LF_COUNT:
        {
            if (kg200z_driverData.END_OF_LINE_COUNT == 2)
            {
                kg200z_driverData.RX_COUNT = 0;
                kg200z_driverData.END_OF_LINE_COUNT = 0;
                kg200z_driverData.state = KG200Z_DRIVER_STATE_ATQ_CHECK_MODULE_RESPONSE;
            }
            else
            {
                kg200z_driverData.state = KG200Z_DRIVER_STATE_ATQ_READ_MODULE_RESPONSE;
            }
            break;
        }

        case KG200Z_DRIVER_STATE_ATQ_CHECK_MODULE_RESPONSE:
        {
            if (KG200Z_DRIVER_Get_Module_Response_Status() == true)
            {
                KG200Z_DRIVER_Set_Module_Response_Status(false);
                kg200z_driverData.state = KG200Z_DRIVER_STATE_IDLE;
            }
            else
            {
                kg200z_driverData.state = KG200Z_DRIVER_STATE_ERROR;
            }
            break;
        }

        case KG200Z_DRIVER_STATE_TIMER_EXPIRED:
        {
            DRV_USART_Close(kg200z_driverData.USART_HANDLE);
            APP_Set_UART_Error_Status(true);
            KG200Z_DRIVER_Set_Task_Completed_Status(true);
            kg200z_driverData.state = KG200Z_DRIVER_STATE_IDLE;
            break;
        }

        case KG200Z_DRIVER_STATE_ERROR:
        {
            DRV_USART_Close(kg200z_driverData.USART_HANDLE);
            APP_Set_UART_Error_Status(true);
            KG200Z_DRIVER_Set_Task_Completed_Status(true);
            kg200z_driverData.state = KG200Z_DRIVER_STATE_IDLE;
            break;
        }

        default:
        {
            break;
        }
    }
}

/*******************************************************************************
 End of File
 */