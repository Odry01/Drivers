/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    timer_driver.c

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

#include "timer_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

TIMER_DRIVER_DATA timer_driverData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void Main_TMR_Callback(uintptr_t CONTEXT)
{
    timer_driverData.MAIN_TMR_EXPIRED = true;
}

void Bus_TMR_Callback(uintptr_t CONTEXT)
{
    timer_driverData.BUS_TMR_EXPIRED = true;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

bool TIMER_DRIVER_Get_Main_TMR_Status(void)
{
    return (timer_driverData.MAIN_TMR_EXPIRED);
}

void TIMER_DRIVER_Set_Main_TMR_Status(bool STATUS)
{
    timer_driverData.MAIN_TMR_EXPIRED = STATUS;
}

void TIMER_DRIVER_Start_Main_TMR(void)
{
    SYS_TIME_TimerStart(timer_driverData.MAIN_TMR);
}

void TIMER_DRIVER_Stop_Main_TMR(void)
{
    SYS_TIME_TimerStop(timer_driverData.MAIN_TMR);
}

bool TIMER_DRIVER_Get_Bus_TMR_Status(void)
{
    return (timer_driverData.BUS_TMR_EXPIRED);
}

void TIMER_DRIVER_Set_Bus_TMR_Status(bool STATUS)
{
    timer_driverData.BUS_TMR_EXPIRED = STATUS;
}

void TIMER_DRIVER_Start_Bus_TMR(void)
{
    SYS_TIME_TimerStart(timer_driverData.BUS_TMR);
}

void TIMER_DRIVER_Stop_Bus_TMR(void)
{
    SYS_TIME_TimerStop(timer_driverData.BUS_TMR);
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization
// *****************************************************************************
// *****************************************************************************

void TIMER_DRIVER_Initialize(void)
{
    timer_driverData.MAIN_TMR = SYS_TIME_HANDLE_INVALID;
    timer_driverData.BUS_TMR = SYS_TIME_HANDLE_INVALID;
    timer_driverData.MAIN_TMR_EXPIRED = false;
    timer_driverData.BUS_TMR_EXPIRED = false;
    timer_driverData.MAIN_TMR = SYS_TIME_CallbackRegisterMS(Main_TMR_Callback, 0, MAIN_TIMER, SYS_TIME_PERIODIC);
    timer_driverData.BUS_TMR = SYS_TIME_CallbackRegisterMS(Bus_TMR_Callback, 0, BUS_TIMER, SYS_TIME_PERIODIC);
    TIMER_DRIVER_Stop_Main_TMR();
    TIMER_DRIVER_Stop_Bus_TMR();
}

/*******************************************************************************
 End of File
 */