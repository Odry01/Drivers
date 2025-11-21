/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    fcm360w_driver.c

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

#include "fcm360w_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

FCM360W_DRIVER_DATA fcm360w_driverData;

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

bool FCM360W_DRIVER_Get_Task_Start_Status(void)
{
    return (fcm360w_driverData.FCM360W_TASK_START);
}

void FCM360W_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    fcm360w_driverData.FCM360W_TASK_START = STATUS;
}

bool FCM360W_DRIVER_Get_Task_Completed_Status(void)
{
    return (fcm360w_driverData.FCM360W_TASK_COMPLETED);
}

void FCM360W_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    fcm360w_driverData.FCM360W_TASK_COMPLETED = STATUS;
}

void FCM360W_DRIVER_Write_Command(char *MESSAGE)
{
    sprintf(fcm360w_driverData.TX_BUFFER, "%s\r", MESSAGE);
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Read_Command(void)
{
    DRV_USART_ReadBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.RX_BYTE, 1, &fcm360w_driverData.USART_BUFFER_HANDLE);
}

bool FCM360W_DRIVER_Get_Module_Response_Status(void)
{
    if (strstr(fcm360w_driverData.RX_BUFFER, "OK") || strstr(fcm360w_driverData.RX_BUFFER, ">"))
    {
        fcm360w_driverData.FCM360W_RESPONSE_STATUS = true;
    }
    else
    {
        fcm360w_driverData.FCM360W_RESPONSE_STATUS = false;
    }
    return (fcm360w_driverData.FCM360W_RESPONSE_STATUS);
}

void FCM360W_DRIVER_Set_Module_Response_Status(bool FCM360W_RESPONSE_STATUS)
{
    fcm360w_driverData.FCM360W_RESPONSE_STATUS = FCM360W_RESPONSE_STATUS;
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void FCM360W_DRIVER_Initialize(void)
{
    fcm360w_driverData.state = FCM360W_DRIVER_STATE_INIT;
    fcm360w_driverData.USART_HANDLE = DRV_HANDLE_INVALID;
    fcm360w_driverData.USART_BUFFER_HANDLE = DRV_USART_BUFFER_HANDLE_INVALID;
}

void FCM360W_DRIVER_Tasks(void)
{
    switch (fcm360w_driverData.state)
    {
        case FCM360W_DRIVER_STATE_INIT:
        {
            fcm360w_driverData.USART_HANDLE = DRV_USART_Open(DRV_USART_INDEX_0, DRV_IO_INTENT_READWRITE);
            fcm360w_driverData.state = FCM360W_DRIVER_STATE_CHECK_USART_HANDLER;
            break;
        }

        case FCM360W_DRIVER_STATE_CHECK_USART_HANDLER:
        {
            if (fcm360w_driverData.USART_HANDLE == DRV_HANDLE_INVALID)
            {
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_ERROR;
            }
            else
            {
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_IDLE;
            }
            break;
        }

        case FCM360W_DRIVER_STATE_IDLE:
        {
            if (FCM360W_DRIVER_Get_Task_Start_Status() == true)
            {
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_MESSAGE_TRANSMIT;
            }
            break;
        }

        case FCM360W_DRIVER_STATE_QRST_MESSAGE_TRANSMIT:
        {
            FCM360W_DRIVER_Write_Command("AT+QRST");
            TIMER_DRIVER_Start_Bus_TMR();
            fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_WAIT_FOR_MESSAGE_TRANSMIT;
            break;
        }

        case FCM360W_DRIVER_STATE_QRST_WAIT_FOR_MESSAGE_TRANSMIT:
        {
            if (DRV_USART_BufferStatusGet(fcm360w_driverData.USART_BUFFER_HANDLE) == DRV_USART_BUFFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_READ_MODULE_RESPONSE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case FCM360W_DRIVER_STATE_QRST_READ_MODULE_RESPONSE:
        {
            FCM360W_DRIVER_Read_Command();
            TIMER_DRIVER_Start_Bus_TMR();
            fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_WAIT_FOR_MESSAGE_RECEIVE;
            break;
        }

        case FCM360W_DRIVER_STATE_QRST_WAIT_FOR_MESSAGE_RECEIVE:
        {
            if (DRV_USART_BufferStatusGet(fcm360w_driverData.USART_BUFFER_HANDLE) == DRV_USART_BUFFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_STORE_BYTE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case FCM360W_DRIVER_STATE_QRST_STORE_BYTE:
        {
            fcm360w_driverData.RX_BUFFER[fcm360w_driverData.RX_COUNT] = fcm360w_driverData.RX_BYTE;
            fcm360w_driverData.RX_COUNT++;
            fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_STORE_END_OF_LINE_COUNT;
            break;
        }

        case FCM360W_DRIVER_STATE_QRST_STORE_END_OF_LINE_COUNT:
        {
            if (fcm360w_driverData.RX_BYTE == '\n')
            {
                fcm360w_driverData.END_OF_LINE_COUNT++;
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_CHECK_CR_LF_COUNT;
            }
            else
            {
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_READ_MODULE_RESPONSE;
            }
            break;
        }

        case FCM360W_DRIVER_STATE_QRST_CHECK_CR_LF_COUNT:
        {
            if (fcm360w_driverData.END_OF_LINE_COUNT == 2)
            {
                fcm360w_driverData.RX_COUNT = 0;
                fcm360w_driverData.END_OF_LINE_COUNT = 0;
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_CHECK_MODULE_RESPONSE;
            }
            else
            {
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_READ_MODULE_RESPONSE;
            }
            break;
        }

        case FCM360W_DRIVER_STATE_QRST_CHECK_MODULE_RESPONSE:
        {
            if (FCM360W_DRIVER_Get_Module_Response_Status() == true)
            {
                FCM360W_DRIVER_Set_Module_Response_Status(false);
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_IDLE;
            }
            else
            {
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_ERROR;
            }
            break;
        }

        case FCM360W_DRIVER_STATE_TIMER_EXPIRED:
        {
            DRV_USART_Close(fcm360w_driverData.USART_HANDLE);
            FCM360W_DRIVER_Set_Task_Completed_Status(true);
            fcm360w_driverData.state = FCM360W_DRIVER_STATE_IDLE;
            break;
        }

        case FCM360W_DRIVER_STATE_ERROR:
        {
            DRV_USART_Close(fcm360w_driverData.USART_HANDLE);
            FCM360W_DRIVER_Set_Task_Completed_Status(true);
            fcm360w_driverData.state = FCM360W_DRIVER_STATE_IDLE;
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