/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    led_driver.c

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

#include "led_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

LED_DRIVER_DATA led_driverData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void LED_DRIVER_DMAC_CH4_Callback(DMAC_TRANSFER_EVENT EVENT, uintptr_t CONTEXT)
{
    if (EVENT == DMAC_TRANSFER_EVENT_COMPLETE)
    {
        led_driverData.DMAC_CH4_TRANSFER_STATUS = true;
        TCC1_PWMStop();
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

bool LED_DRIVER_Get_Task_Start_Status(void)
{
    return (led_driverData.LED_TASK_START);
}

void LED_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    led_driverData.LED_TASK_START = STATUS;
}

bool LED_DRIVER_Get_Task_Completed_Status(void)
{
    return (led_driverData.LED_TASK_COMPLETED);
}

void LED_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    led_driverData.LED_TASK_COMPLETED = STATUS;
}

void LED_DRIVER_Set_Color(uint8_t RED_LED, uint8_t GREEN_LED, uint8_t BLUE_LED)
{
    led_driverData.RED_LED = RED_LED;
    led_driverData.GREEN_LED = GREEN_LED;
    led_driverData.BLUE_LED = BLUE_LED;
}

void LED_DRIVER_Set_LED_Strip_Data(uint8_t BUFFER_INDEX, uint8_t RED_LED, uint8_t GREEN_LED, uint8_t BLUE_LED)
{
    for (int i = 0; i < NO_OF_LEDS; i++)
    {
        for (int j = 7; j >= 0; j--)
        {
            led_driverData.DMAC_CH4_BUFFER[BUFFER_INDEX][i][j] = (GREEN_LED >> (7 - j) & 1);

            if (led_driverData.DMAC_CH4_BUFFER[BUFFER_INDEX][i][j] == 1)
            {
                led_driverData.DMAC_CH4_BUFFER[BUFFER_INDEX][i][j] = T1H;
            }
            else
            {
                led_driverData.DMAC_CH4_BUFFER[BUFFER_INDEX][i][j] = T1L;
            }

            led_driverData.DMAC_CH4_BUFFER[BUFFER_INDEX][i][8 + j] = (RED_LED >> (7 - j)) & 1;

            if (led_driverData.DMAC_CH4_BUFFER[BUFFER_INDEX][i][8 + j] == 1)
            {
                led_driverData.DMAC_CH4_BUFFER[BUFFER_INDEX][i][8 + j] = T1H;
            }
            else
            {
                led_driverData.DMAC_CH4_BUFFER[BUFFER_INDEX][i][8 + j] = T1L;
            }

            led_driverData.DMAC_CH4_BUFFER[BUFFER_INDEX][i][16 + j] = (BLUE_LED >> (7 - j)) & 1;

            if (led_driverData.DMAC_CH4_BUFFER[BUFFER_INDEX][i][16 + j] == 1)
            {
                led_driverData.DMAC_CH4_BUFFER[BUFFER_INDEX][i][16 + j] = T1H;
            }
            else
            {
                led_driverData.DMAC_CH4_BUFFER[BUFFER_INDEX][i][16 + j] = T1L;
            }
        }
    }
}

void LED_DRIVER_Send_LED_Strip_Data(void)
{
    for (int i = 0; i < NO_OF_BUFFER; i++)
    {
        DMAC_ChannelTransfer(DMAC_CHANNEL_0, (void*) &led_driverData.DMAC_CH4_BUFFER[i][0][0], (void*) &TCC1_REGS->TCC_CCBUF[0], BUFFER_SIZE);
        TCC1_PWMStart();
    }
}

void LED_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)
{
    SYS_CONSOLE_Print
            (
             CONSOLE_HANDLE,
             "Red LED value: %d\r\n"
             "Green LED value: %d\r\n"
             "Blue LED value: %d\r\n",
             led_driverData.RED_LED,
             led_driverData.GREEN_LED,
             led_driverData.BLUE_LED
             );
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void LED_DRIVER_Initialize(void)
{
    led_driverData.state = LED_DRIVER_STATE_INIT;
    DMAC_ChannelCallbackRegister(DMAC_CHANNEL_0, LED_DRIVER_DMAC_CH4_Callback, 0);
}

void LED_DRIVER_Tasks(void)
{
    switch (led_driverData.state)
    {
        case LED_DRIVER_STATE_INIT:
        {
            led_driverData.RED_LED = 128;
            led_driverData.GREEN_LED = 128;
            led_driverData.BLUE_LED = 128;
            led_driverData.state = LED_DRIVER_STATE_IDLE;
            break;
        }

        case LED_DRIVER_STATE_IDLE:
        {
            if (LED_DRIVER_Get_Task_Start_Status() == true)
            {
                led_driverData.state = LED_DRIVER_STATE_SET_COLOR;
            }
            break;
        }

        case LED_DRIVER_STATE_SET_COLOR:
        {
            LED_DRIVER_Set_Color(led_driverData.RED_LED, led_driverData.GREEN_LED, led_driverData.BLUE_LED);
            led_driverData.state = LED_DRIVER_STATE_SET_LED_STRIP_DATA;
            break;
        }

        case LED_DRIVER_STATE_SET_LED_STRIP_DATA:
        {
            LED_DRIVER_Set_LED_Strip_Data(0, led_driverData.RED_LED, led_driverData.GREEN_LED, led_driverData.BLUE_LED);
            led_driverData.state = LED_DRIVER_STATE_SEND_LED_STRIP_DATA;
            break;
        }

        case LED_DRIVER_STATE_SEND_LED_STRIP_DATA:
        {
            LED_DRIVER_Send_LED_Strip_Data();
            led_driverData.state = LED_DRIVER_STATE_SEND_LED_STRIP_DATA_WAIT_FOR_TRANSFER;
            break;
        }

        case LED_DRIVER_STATE_SEND_LED_STRIP_DATA_WAIT_FOR_TRANSFER:
        {
            if (led_driverData.DMAC_CH4_TRANSFER_STATUS)
            {
                led_driverData.DMAC_CH4_TRANSFER_STATUS = false;
                LED_DRIVER_Set_Task_Completed_Status(true);
                led_driverData.state = LED_DRIVER_STATE_IDLE;
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