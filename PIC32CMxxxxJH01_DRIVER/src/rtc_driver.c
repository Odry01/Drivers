/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    rtc_driver.c

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

#include "rtc_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

RTC_DRIVER_DATA rtc_driverData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void RTC_DRIVER_Alarm_Callback(RTC_CLOCK_INT_MASK INT, uintptr_t CONTEXT)
{
    if ((INT & RTC_CLOCK_INT_MASK_ALARM0) == RTC_CLOCK_INT_MASK_ALARM0)
    {
        rtc_driverData.RTC_ALARM = true;
    }
}

void RTC_DRIVER_XOSC32K_Alert_Callback(uintptr_t CONTEXT)
{
    rtc_driverData.RTC_XOSC32K_ALERT = true;
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

bool RTC_DRIVER_Get_Alarm_Status(void)
{
    return (rtc_driverData.RTC_ALARM);
}

void RTC_DRIVER_Set_Alarm_Status(bool STATUS)
{
    rtc_driverData.RTC_ALARM = STATUS;
}

void RTC_DRIVER_Set_Init_Time(void)
{
    rtc_driverData.INIT_TIME.tm_hour = 00;
    rtc_driverData.INIT_TIME.tm_min = 00;
    rtc_driverData.INIT_TIME.tm_sec = 00;
    rtc_driverData.INIT_TIME.tm_mday = 1;
    rtc_driverData.INIT_TIME.tm_mon = 1;
    rtc_driverData.INIT_TIME.tm_year = 125;
    RTC_RTCCTimeSet(&rtc_driverData.INIT_TIME);
}

void RTC_DRIVER_Set_Alarm_Time(void)
{
    rtc_driverData.ALARM_TIME.tm_hour = 0;
    rtc_driverData.ALARM_TIME.tm_min = 0;
    rtc_driverData.ALARM_TIME.tm_sec = 0;
    rtc_driverData.ALARM_TIME.tm_mday = 0;
    rtc_driverData.ALARM_TIME.tm_mon = 0;
    rtc_driverData.ALARM_TIME.tm_year = 0;
    RTC_RTCCAlarmSet(&rtc_driverData.ALARM_TIME, RTC_ALARM_MASK_SS);
}

void RTC_DRIVER_Get_System_Time()
{
    RTC_RTCCTimeGet(&rtc_driverData.SYSTEM_TIME);
}

void RTC_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)
{
    SYS_CONSOLE_Print
            (
             CONSOLE_HANDLE,
             "Time: %d:%d:%d\r\n"
             "Date: %d.%d.%d\r\n",
             rtc_driverData.SYSTEM_TIME.tm_hour, rtc_driverData.SYSTEM_TIME.tm_min, rtc_driverData.SYSTEM_TIME.tm_sec,
             rtc_driverData.SYSTEM_TIME.tm_mday, (rtc_driverData.SYSTEM_TIME.tm_mon + 1), (1900 + rtc_driverData.SYSTEM_TIME.tm_year)
             );
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void RTC_DRIVER_Initialize(void)
{
    rtc_driverData.state = RTC_DRIVER_STATE_INIT;
    RTC_RTCCCallbackRegister(RTC_DRIVER_Alarm_Callback, 0);
    OSC32KCTRL_CallbackRegister(RTC_DRIVER_XOSC32K_Alert_Callback, 0);
}

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

        case RTC_DRIVER_STATE_CHECK_XOSC32K_ALERT:
        {
            if (rtc_driverData.RTC_XOSC32K_ALERT == true)
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
            RTC_DRIVER_Get_System_Time();
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