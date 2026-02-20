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

void WS281X_DRIVER_DMAC_CH5_Callback(DMAC_TRANSFER_EVENT EVENT, uintptr_t CONTEXT)
{
    if (EVENT == DMAC_TRANSFER_EVENT_COMPLETE)
    {
        ws281x_driverData.DMAC_CH5_TRANSFER_COMPLETED = true;
        ws281x_driverData.LED_INDEX = 0;
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

void WS281X_DRIVER_Set_Data_Bits(void)
{
    ws281x_driverData.LED_BITS[0] = 0xC0C0C0C0;
    ws281x_driverData.LED_BITS[1] = 0xC0C0C0F8;
    ws281x_driverData.LED_BITS[2] = 0xC0C0F8C0;
    ws281x_driverData.LED_BITS[3] = 0xC0C0F8F8;
    ws281x_driverData.LED_BITS[4] = 0xC0F8C0C0;
    ws281x_driverData.LED_BITS[5] = 0xC0F8C0F8;
    ws281x_driverData.LED_BITS[6] = 0xC0F8F8C0;
    ws281x_driverData.LED_BITS[7] = 0xC0F8F8F8;
    ws281x_driverData.LED_BITS[8] = 0xF8C0C0C0;
    ws281x_driverData.LED_BITS[9] = 0xF8C0C0F8;
    ws281x_driverData.LED_BITS[10] = 0xF8C0F8C0;
    ws281x_driverData.LED_BITS[11] = 0xF8C0F8F8;
    ws281x_driverData.LED_BITS[12] = 0xF8F8C0C0;
    ws281x_driverData.LED_BITS[13] = 0xF8F8C0F8;
    ws281x_driverData.LED_BITS[14] = 0xF8F8F8C0;
    ws281x_driverData.LED_BITS[15] = 0xF8F8F8F8;
}

void WS281X_DRIVER_Set_Strip_Color(void)
{
    for (uint8_t i = 0; i < NUMBER_OF_LEDS; i++)
    {
        ws281x_driverData.PIXEL[i][0] = ws281x_driverData.RED_LED;
        ws281x_driverData.PIXEL[i][1] = ws281x_driverData.GREEN_LED;
        ws281x_driverData.PIXEL[i][2] = ws281x_driverData.BLUE_LED;
    }
}

void WS281X_DRIVER_Set_Data(uint16_t *INDEX, uint8_t RED_LED, uint8_t GREEN_LED, uint8_t BLUE_LED)
{
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = ((ws281x_driverData.LED_BITS[GREEN_LED >> 4] >> 24) & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = ((ws281x_driverData.LED_BITS[GREEN_LED >> 4] >> 16) & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = ((ws281x_driverData.LED_BITS[GREEN_LED >> 4] >> 8) & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = (ws281x_driverData.LED_BITS[GREEN_LED >> 4] & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = ((ws281x_driverData.LED_BITS[GREEN_LED & 0x0F] >> 24) & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = ((ws281x_driverData.LED_BITS[GREEN_LED & 0x0F] >> 16) & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = ((ws281x_driverData.LED_BITS[GREEN_LED & 0x0F] >> 8) & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = (ws281x_driverData.LED_BITS[GREEN_LED & 0x0F] & 0xFF);

    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = ((ws281x_driverData.LED_BITS[RED_LED >> 4] >> 24) & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = ((ws281x_driverData.LED_BITS[RED_LED >> 4] >> 16) & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = ((ws281x_driverData.LED_BITS[RED_LED >> 4] >> 8) & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = (ws281x_driverData.LED_BITS[RED_LED >> 4] & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = ((ws281x_driverData.LED_BITS[RED_LED & 0x0F] >> 24) & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = ((ws281x_driverData.LED_BITS[RED_LED & 0x0F] >> 16) & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = ((ws281x_driverData.LED_BITS[RED_LED & 0x0F] >> 8) & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = (ws281x_driverData.LED_BITS[RED_LED & 0x0F] & 0xFF);

    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = ((ws281x_driverData.LED_BITS[BLUE_LED >> 4] >> 24) & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = ((ws281x_driverData.LED_BITS[BLUE_LED >> 4] >> 16) & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = ((ws281x_driverData.LED_BITS[BLUE_LED >> 4] >> 8) & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = (ws281x_driverData.LED_BITS[BLUE_LED >> 4] & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = ((ws281x_driverData.LED_BITS[BLUE_LED & 0x0F] >> 24) & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = ((ws281x_driverData.LED_BITS[BLUE_LED & 0x0F] >> 16) & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = ((ws281x_driverData.LED_BITS[BLUE_LED & 0x0F] >> 8) & 0xFF);
    ws281x_driverData.DMAC_CH5_BUFFER[MINIMUM_DELAY + (*INDEX)++] = (ws281x_driverData.LED_BITS[BLUE_LED & 0x0F] & 0xFF);
}

void WS281X_DRIVER_Set_Strip_Data(void)
{
    for (uint8_t i = 0; i < NUMBER_OF_LEDS; i++)
    {
        WS281X_DRIVER_Set_Data(&ws281x_driverData.LED_INDEX, ws281x_driverData.PIXEL[i][0], ws281x_driverData.PIXEL[i][1], ws281x_driverData.PIXEL[i][2]);
    }
}

void WS281X_DRIVER_Send_Data(void)
{
    DMAC_ChannelTransfer(DMAC_CHANNEL_5, ws281x_driverData.DMAC_CH5_BUFFER, (const void *) &SERCOM5_REGS->SPIM.SERCOM_DATA, sizeof (ws281x_driverData.DMAC_CH5_BUFFER));
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
    DMAC_ChannelCallbackRegister(DMAC_CHANNEL_5, WS281X_DRIVER_DMAC_CH5_Callback, 0);
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
            WS281X_DRIVER_Set_Data_Bits();
            ws281x_driverData.state = WS281X_DRIVER_STATE_IDLE;
            break;
        }

        case WS281X_DRIVER_STATE_IDLE:
        {
            if (WS281X_DRIVER_Get_Task_Start_Status() == true)
            {
                ws281x_driverData.state = WS281X_DRIVER_STATE_SET_LED_STRIP_COLOR;
            }
            break;
        }

        case WS281X_DRIVER_STATE_SET_LED_STRIP_COLOR:
        {
            WS281X_DRIVER_Set_Strip_Color();
            ws281x_driverData.state = WS281X_DRIVER_STATE_SET_LED_STRIP_DATA;
            break;
        }

        case WS281X_DRIVER_STATE_SET_LED_STRIP_DATA:
        {
            WS281X_DRIVER_Set_Strip_Data();
            ws281x_driverData.state = WS281X_DRIVER_STATE_SEND_LED_STRIP_DATA;
            break;
        }

        case WS281X_DRIVER_STATE_SEND_LED_STRIP_DATA:
        {
            WS281X_DRIVER_Send_Data();
            ws281x_driverData.state = WS281X_DRIVER_STATE_WAIT_FOR_TRANSFER_LED_STRIP_DATA;
            break;
        }

        case WS281X_DRIVER_STATE_WAIT_FOR_TRANSFER_LED_STRIP_DATA:
        {
            if (ws281x_driverData.DMAC_CH5_TRANSFER_COMPLETED == true)
            {
                WS281X_DRIVER_Set_Task_Completed_Status(true);
                ws281x_driverData.state = WS281X_DRIVER_STATE_IDLE;
            }
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