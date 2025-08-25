/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    ws281x_driver.c

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

#include "ws281x_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

WS281X_DRIVER_DATA ws281x_driverData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void WS281X_DRIVER_DMAC_CH4_Callback(DMAC_TRANSFER_EVENT EVENT, uintptr_t CONTEXT)
{
    if (EVENT == DMAC_TRANSFER_EVENT_COMPLETE)
    {
        TCC1_PWMStop();
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

bool WS281X_DRIVER_Get_Task_Start_Status(void)
{
    return (ws281x_driverData.WS281X_TASK_START);
}

void WS281X_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    ws281x_driverData.WS281X_TASK_START = STATUS;
}

bool WS281X_DRIVER_Get_Task_Completed_Status(void)
{
    return (ws281x_driverData.WS281X_TASK_COMPLETED);
}

void WS281X_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    ws281x_driverData.WS281X_TASK_COMPLETED = STATUS;
}

void WS281X_DRIVER_Set_Color(uint8_t RED_LED, uint8_t GREEN_LED, uint8_t BLUE_LED)
{
    ws281x_driverData.RED_LED = RED_LED;
    ws281x_driverData.GREEN_LED = GREEN_LED;
    ws281x_driverData.BLUE_LED = BLUE_LED;
}

void WS281X_DRIVER_Set_LED_Strip_Data(uint8_t RED_LED, uint8_t GREEN_LED, uint8_t BLUE_LED)
{
    for (int i = 0; i < NUMBER_OF_LEDS; i++)
    {
        for (int j = 7; j >= 0; j--)
        {
            ws281x_driverData.DMAC_CH4_BUFFER[i][j] = (GREEN_LED >> (7 - j) & 1);

            if (ws281x_driverData.DMAC_CH4_BUFFER[i][j] == 1)
            {
                ws281x_driverData.DMAC_CH4_BUFFER[i][j] = T1H;
            }
            else
            {
                ws281x_driverData.DMAC_CH4_BUFFER[i][j] = T1L;
            }

            ws281x_driverData.DMAC_CH4_BUFFER[i][8 + j] = (RED_LED >> (7 - j)) & 1;

            if (ws281x_driverData.DMAC_CH4_BUFFER[i][8 + j] == 1)
            {
                ws281x_driverData.DMAC_CH4_BUFFER[i][8 + j] = T1H;
            }
            else
            {
                ws281x_driverData.DMAC_CH4_BUFFER[i][8 + j] = T1L;
            }

            ws281x_driverData.DMAC_CH4_BUFFER[i][16 + j] = (BLUE_LED >> (7 - j)) & 1;

            if (ws281x_driverData.DMAC_CH4_BUFFER[i][16 + j] == 1)
            {
                ws281x_driverData.DMAC_CH4_BUFFER[i][16 + j] = T1H;
            }
            else
            {
                ws281x_driverData.DMAC_CH4_BUFFER[i][16 + j] = T1L;
            }
        }
    }
}

void WS281X_DRIVER_Send_LED_Strip_Data(void)
{
    if (DMAC_ChannelTransfer(DMAC_CHANNEL_4, (void*) &ws281x_driverData.DMAC_CH4_BUFFER[0][0], (void*) &TCC1_REGS->TCC_CCBUF[0], BUFFER_SIZE))
    {
        TCC1_PWMStart();
    }
}

void WS281X_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)
{
    SYS_CONSOLE_Print
            (
             CONSOLE_HANDLE,
             "Red LED value: %d\r\n"
             "Green LED value: %d\r\n"
             "Blue LED value: %d\r\n",
             ws281x_driverData.RED_LED,
             ws281x_driverData.GREEN_LED,
             ws281x_driverData.BLUE_LED
             );
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void WS281X_DRIVER_Initialize(void)
{
    ws281x_driverData.state = WS281X_DRIVER_STATE_INIT;
    DMAC_ChannelCallbackRegister(DMAC_CHANNEL_4, WS281X_DRIVER_DMAC_CH4_Callback, 0);
}

void WS281X_DRIVER_Tasks(void)
{
    switch (ws281x_driverData.state)
    {
        case WS281X_DRIVER_STATE_INIT:
        {
            ws281x_driverData.RED_LED = 128;
            ws281x_driverData.GREEN_LED = 128;
            ws281x_driverData.BLUE_LED = 128;
            ws281x_driverData.state = WS281X_DRIVER_STATE_IDLE;
            break;
        }

        case WS281X_DRIVER_STATE_IDLE:
        {
            if (WS281X_DRIVER_Get_Task_Start_Status() == true)
            {
                ws281x_driverData.state = WS281X_DRIVER_STATE_SET_COLOR;
            }
            break;
        }

        case WS281X_DRIVER_STATE_SET_COLOR:
        {
            WS281X_DRIVER_Set_Color(ws281x_driverData.RED_LED, ws281x_driverData.GREEN_LED, ws281x_driverData.BLUE_LED);
            ws281x_driverData.state = WS281X_DRIVER_STATE_SET_LED_STRIP_DATA;
            break;
        }

        case WS281X_DRIVER_STATE_SET_LED_STRIP_DATA:
        {
            WS281X_DRIVER_Set_LED_Strip_Data(ws281x_driverData.RED_LED, ws281x_driverData.GREEN_LED, ws281x_driverData.BLUE_LED);
            ws281x_driverData.state = WS281X_DRIVER_STATE_SEND_LED_STRIP_DATA;
            break;
        }

        case WS281X_DRIVER_STATE_SEND_LED_STRIP_DATA:
        {
            WS281X_DRIVER_Send_LED_Strip_Data();
            WS281X_DRIVER_Set_Task_Completed_Status(true);
            ws281x_driverData.state = WS281X_DRIVER_STATE_IDLE;
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