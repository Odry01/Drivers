/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    rtc_driver.c

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

#include "rtc_driver.h"

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
    This structure should be initialized by the RTC_DRIVER_Initialize function.

    Application strings and buffers are be defined outside this structure.
 */

RTC_DRIVER_DATA rtc_driverData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void RTC_DRIVER_XOSC32K_Failure_Callback(uintptr_t CONTEXT)
{
    rtc_driverData.RTC_XOSC32K_FAILURE = true;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

bool RTC_DRIVER_Get_Task_Start_Status(void)
{
    return (rtc_driverData.RTC_TASK_START);
}

void RTC_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    rtc_driverData.RTC_TASK_START = STATUS;
}

bool RTC_DRIVER_Get_Task_Completed_Status(void)
{
    return (rtc_driverData.RTC_TASK_COMPLETED);
}

void RTC_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    rtc_driverData.RTC_TASK_COMPLETED = STATUS;
}

void RTC_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)
{
    SYS_CONSOLE_Print
            (
             CONSOLE_HANDLE,
             "Time from start: %ld seconds\r\n",
             rtc_driverData.TIME
             );
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void RTC_DRIVER_Initialize ( void )

  Remarks:
    See prototype in rtc_driver.h.
 */

void RTC_DRIVER_Initialize(void)
{
    rtc_driverData.state = RTC_DRIVER_STATE_INIT;
    OSC32KCTRL_CallbackRegister(RTC_DRIVER_XOSC32K_Failure_Callback, 0);
    RTC_Timer32Start();
}

/******************************************************************************
  Function:
    void RTC_DRIVER_Tasks ( void )

  Remarks:
    See prototype in rtc_driver.h.
 */

void RTC_DRIVER_Tasks(void)
{
    switch (rtc_driverData.state)
    {
        case RTC_DRIVER_STATE_INIT:
        {
            rtc_driverData.state = RTC_DRIVER_STATE_IDLE;
            break;
        }

        case RTC_DRIVER_STATE_IDLE:
        {
            if (RTC_DRIVER_Get_Task_Start_Status() == true)
            {
                rtc_driverData.state = RTC_DRIVER_STATE_GET_TIME;
            }
            break;
        }

        case RTC_DRIVER_STATE_CHECK_XOSC32K_FAILURE:
        {
            if (rtc_driverData.RTC_XOSC32K_FAILURE == true)
            {
                rtc_driverData.state = RTC_DRIVER_STATE_ERROR;
            }
            else
            {
                rtc_driverData.state = RTC_DRIVER_STATE_GET_TIME;
            }
            break;
        }

        case RTC_DRIVER_STATE_GET_TIME:
        {
            rtc_driverData.TIME = RTC_Timer32CounterGet();
            rtc_driverData.state = RTC_DRIVER_STATE_STORE_TIME_VALUE;
            break;
        }

        case RTC_DRIVER_STATE_STORE_TIME_VALUE:
        {
            RTC_DRIVER_Set_Task_Completed_Status(true);
            rtc_driverData.state = RTC_DRIVER_STATE_IDLE;
            break;
        }

        case RTC_DRIVER_STATE_ERROR:
        {
            RTC_DRIVER_Set_Task_Completed_Status(true);
            rtc_driverData.state = RTC_DRIVER_STATE_IDLE;
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