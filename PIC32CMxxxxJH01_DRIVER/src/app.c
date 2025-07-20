/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    app.c

  Status:
    Finished
 
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

#include "app.h"
#include "timer_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

APP_DATA appData;

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

bool APP_Get_CAN0_Error_Status(void)
{
    return (appData.CAN0_ERROR);
}

void APP_Set_CAN0_Error_Status(bool STATUS)
{
    appData.CAN0_ERROR = STATUS;
}

bool APP_Get_I2C_Error_Status(void)
{
    return (appData.I2C_ERROR);
}

void APP_Set_I2C_Error_Status(bool STATUS)
{
    appData.I2C_ERROR = STATUS;
}

bool APP_Get_SPI_Error_Status(void)
{
    return (appData.SPI_ERROR);
}

void APP_Set_SPI_Error_Status(bool STATUS)
{
    appData.SPI_ERROR = STATUS;
}

bool APP_Get_UART_Error_Status(void)
{
    return (appData.UART_ERROR);
}

void APP_Set_UART_Error_Status(bool STATUS)
{
    appData.UART_ERROR = STATUS;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void APP_Initialize(void)
{
    appData.state = APP_STATE_INIT;
    WDT_TimeoutPeriodSet(WDT_CONFIG_PER_CYC16384_Val);
}

void APP_Tasks(void)
{
    switch (appData.state)
    {
        case APP_STATE_INIT:
        {
            appData.state = APP_STATE_START_MAIN_TMR;
            break;
        }

        case APP_STATE_START_MAIN_TMR:
        {
            TIMER_DRIVER_Start_Main_TMR();
            WDT_Enable();
            appData.state = APP_STATE_IDLE;
            break;
        }

        case APP_STATE_IDLE:
        {
            if (TIMER_DRIVER_Get_Main_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Main_TMR_Status(false);
                WDT_Clear();
                appData.state = APP_STATE_HDC302X_DRIVER_OPERATION;
            }
            break;
        }

        case APP_STATE_HDC302X_DRIVER_OPERATION:
        {
            if (APP_Get_I2C_Error_Status() == false)
            {
                HDC302X_DRIVER_Set_Task_Start_Status(true);
                WDT_Clear();
                appData.state = APP_STATE_WAIT_FOR_FINISH_HDC302X_DRIVER_OPERATION;
            }
            else
            {
                WDT_Clear();
                appData.state = APP_STATE_CAN0_DRIVER_OPERATION;
            }
            break;
        }

        case APP_STATE_WAIT_FOR_FINISH_HDC302X_DRIVER_OPERATION:
        {
            if (HDC302X_DRIVER_Get_Task_Completed_Status() == true)
            {
                HDC302X_DRIVER_Set_Task_Start_Status(false);
                HDC302X_DRIVER_Set_Task_Completed_Status(false);
                WDT_Clear();
                appData.state = APP_STATE_CAN0_DRIVER_OPERATION;
            }
            break;
        }

        case APP_STATE_CAN0_DRIVER_OPERATION:
        {
            if (APP_Get_CAN0_Error_Status() == false)
            {
                CAN0_DRIVER_Set_Task_Start_Status(true);
                WDT_Clear();
                appData.state = APP_STATE_WAIT_FOR_FINISH_CAN0_DRIVER_OPERATION;
            }
            else
            {
                WDT_Clear();
                appData.state = APP_STATE_CONSOLE_DRIVER_OPERATION;
            }
            break;
        }

        case APP_STATE_WAIT_FOR_FINISH_CAN0_DRIVER_OPERATION:
        {
            if (CAN0_DRIVER_Get_Task_Completed_Status() == true)
            {
                CAN0_DRIVER_Set_Task_Start_Status(false);
                CAN0_DRIVER_Set_Task_Completed_Status(false);
                WDT_Clear();
                appData.state = APP_STATE_CONSOLE_DRIVER_OPERATION;
            }
            break;
        }

        case APP_STATE_CONSOLE_DRIVER_OPERATION:
        {
            CONSOLE_DRIVER_Set_Task_Start_Status(true);
            WDT_Clear();
            appData.state = APP_STATE_WAIT_FOR_FINISH_CONSOLE_DRIVER_OPERATION;
            break;
        }

        case APP_STATE_WAIT_FOR_FINISH_CONSOLE_DRIVER_OPERATION:
        {
            if (CONSOLE_DRIVER_Get_Task_Completed_Status() == true)
            {
                CONSOLE_DRIVER_Set_Task_Start_Status(false);
                CONSOLE_DRIVER_Set_Task_Completed_Status(false);
                TIMER_DRIVER_Start_Main_TMR();
                WDT_Clear();
                appData.state = APP_STATE_IDLE;
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