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
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the TIMER_DRIVER_Initialize function.

    Application strings and buffers are be defined outside this structure.
 */

TIMER_DRIVER_DATA timer_driverData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void TMR0_Callback(uintptr_t CONTEXT)
{
    timer_driverData.TMR0_EXPIRED = true;
}

void TMR1_Callback(uintptr_t CONTEXT)
{
    timer_driverData.TMR1_EXPIRED = true;
}

void TMR2_Callback(uintptr_t CONTEXT)
{
    timer_driverData.TMR2_EXPIRED = true;
}

void TMR3_Callback(uintptr_t CONTEXT)
{
    timer_driverData.TMR3_EXPIRED = true;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

bool TIMER_DRIVER_Get_TMR0_Status(void)
{
    return (timer_driverData.TMR0_EXPIRED);
}

void TIMER_DRIVER_Set_TMR0_Status(bool STATUS)
{
    timer_driverData.TMR0_EXPIRED = STATUS;
}

void TIMER_DRIVER_Start_TMR0(void)
{
    SYS_TIME_TimerStart(timer_driverData.TMR0_HANDLE);
}

void TIMER_DRIVER_Stop_TMR0(void)
{
    SYS_TIME_TimerStop(timer_driverData.TMR0_HANDLE);
}

bool TIMER_DRIVER_Get_TMR1_Status(void)
{
    return (timer_driverData.TMR1_EXPIRED);
}

void TIMER_DRIVER_Set_TMR1_Status(bool STATUS)
{
    timer_driverData.TMR1_EXPIRED = STATUS;
}

void TIMER_DRIVER_Start_TMR1(void)
{
    SYS_TIME_TimerStart(timer_driverData.TMR1_HANDLE);
}

void TIMER_DRIVER_Stop_TMR1(void)
{
    SYS_TIME_TimerStop(timer_driverData.TMR1_HANDLE);
}

bool TIMER_DRIVER_Get_TMR2_Status(void)
{
    return (timer_driverData.TMR2_EXPIRED);
}

void TIMER_DRIVER_Set_TMR2_Status(bool STATUS)
{
    timer_driverData.TMR2_EXPIRED = STATUS;
}

void TIMER_DRIVER_Start_TMR2(void)
{
    SYS_TIME_TimerStart(timer_driverData.TMR2_HANDLE);
}

void TIMER_DRIVER_Stop_TMR2(void)
{
    SYS_TIME_TimerStop(timer_driverData.TMR2_HANDLE);
}

bool TIMER_DRIVER_Get_TMR3_Status(void)
{
    return (timer_driverData.TMR3_EXPIRED);
}

void TIMER_DRIVER_Set_TMR3_Status(bool STATUS)
{
    timer_driverData.TMR3_EXPIRED = STATUS;
}

void TIMER_DRIVER_Start_TMR3(void)
{
    SYS_TIME_TimerStart(timer_driverData.TMR3_HANDLE);
}

void TIMER_DRIVER_Stop_TMR3(void)
{
    SYS_TIME_TimerStop(timer_driverData.TMR3_HANDLE);
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void TIMER_DRIVER_Initialize ( void )

  Remarks:
    See prototype in timer_driver.h.
 */

void TIMER_DRIVER_Initialize(void)
{
    timer_driverData.TMR0_HANDLE = SYS_TIME_HANDLE_INVALID;
    timer_driverData.TMR1_HANDLE = SYS_TIME_HANDLE_INVALID;
    timer_driverData.TMR2_HANDLE = SYS_TIME_HANDLE_INVALID;
    timer_driverData.TMR3_HANDLE = SYS_TIME_HANDLE_INVALID;
    timer_driverData.TMR0_EXPIRED = false;
    timer_driverData.TMR1_EXPIRED = false;
    timer_driverData.TMR2_EXPIRED = false;
    timer_driverData.TMR3_EXPIRED = false;
    timer_driverData.TMR0_HANDLE = SYS_TIME_CallbackRegisterMS(TMR0_Callback, 0, TIMER0, SYS_TIME_PERIODIC);
    timer_driverData.TMR1_HANDLE = SYS_TIME_CallbackRegisterMS(TMR1_Callback, 0, TIMER1, SYS_TIME_PERIODIC);
    timer_driverData.TMR2_HANDLE = SYS_TIME_CallbackRegisterMS(TMR2_Callback, 0, TIMER2, SYS_TIME_PERIODIC);
    timer_driverData.TMR3_HANDLE = SYS_TIME_CallbackRegisterMS(TMR3_Callback, 0, TIMER3, SYS_TIME_PERIODIC);
    TIMER_DRIVER_Stop_TMR0();
    TIMER_DRIVER_Stop_TMR1();
    TIMER_DRIVER_Stop_TMR2();
    TIMER_DRIVER_Stop_TMR3();
}

/*******************************************************************************
 End of File
 */