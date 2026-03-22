/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    rstc_driver.c

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

#include "rstc_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************

RSTC_DRIVER_DATA rstc_driverData;

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

bool RSTC_DRIVER_Get_Task_Start_Status(void)
{
    return (rstc_driverData.RSTC_TASK_START);
}

void RSTC_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    rstc_driverData.RSTC_TASK_START = STATUS;
}

bool RSTC_DRIVER_Get_Task_Completed_Status(void)
{
    return (rstc_driverData.RSTC_TASK_COMPLETED);
}

void RSTC_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    rstc_driverData.RSTC_TASK_COMPLETED = STATUS;
}

void RSTC_DRIVER_Set_Reset_Reason(char *RESET_REASON)
{
    sprintf(rstc_driverData.RESET_REASON, "%s", RESET_REASON);
}

void RSTC_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)
{
    SYS_CONSOLE_Print
            (
             CONSOLE_HANDLE,
             "Reset reason: %s\r\n",
             rstc_driverData.RESET_REASON
             );
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void RSTC_DRIVER_Initialize(void)
{
    rstc_driverData.state = RSTC_DRIVER_STATE_INIT;
}

void RSTC_DRIVER_Tasks(void)
{
    switch (rstc_driverData.state)
    {
        case RSTC_DRIVER_STATE_INIT:
        {
            rstc_driverData.state = RSTC_DRIVER_STATE_IDLE;
            break;
        }

        case RSTC_DRIVER_STATE_IDLE:
        {
            if (RSTC_DRIVER_Get_Task_Start_Status() == true)
            {
                rstc_driverData.state = RSTC_DRIVER_STATE_CHECK_POR_RESET;
            }
            break;
        }

        case RSTC_DRIVER_STATE_CHECK_POR_RESET:
        {
            if (RSTC_ResetCauseGet() == RSTC_RESET_CAUSE_POR_RESET)
            {
                RSTC_DRIVER_Set_Reset_Reason("Power On Reset");
                RSTC_DRIVER_Set_Task_Completed_Status(true);
                rstc_driverData.state = RSTC_DRIVER_STATE_IDLE;
            }
            else
            {
                RSTC_DRIVER_Set_Reset_Reason("None");
                rstc_driverData.state = RSTC_DRIVER_STATE_CHECK_BODCORE_RESET;
            }
            break;
        }

        case RSTC_DRIVER_STATE_CHECK_BODCORE_RESET:
        {
            if (RSTC_ResetCauseGet() == RSTC_RESET_CAUSE_BODCORE_RESET)
            {
                RSTC_DRIVER_Set_Reset_Reason("Brown Out CORE Detector Reset");
                RSTC_DRIVER_Set_Task_Completed_Status(true);
                rstc_driverData.state = RSTC_DRIVER_STATE_IDLE;
            }
            else
            {
                RSTC_DRIVER_Set_Reset_Reason("None");
                rstc_driverData.state = RSTC_DRIVER_STATE_CHECK_BODVDD_RESET;
            }
            break;
        }

        case RSTC_DRIVER_STATE_CHECK_BODVDD_RESET:
        {
            if (RSTC_ResetCauseGet() == RSTC_RESET_CAUSE_BODVDD_RESET)
            {
                RSTC_DRIVER_Set_Reset_Reason("Brown Out VDD Detector Reset");
                rstc_driverData.state = RSTC_DRIVER_STATE_IDLE;
            }
            else
            {
                RSTC_DRIVER_Set_Reset_Reason("None");
                rstc_driverData.state = RSTC_DRIVER_STATE_CHECK_EXT_RESET;
            }
            break;
        }

        case RSTC_DRIVER_STATE_CHECK_EXT_RESET:
        {
            if (RSTC_ResetCauseGet() == RSTC_RESET_CAUSE_EXT_RESET)
            {
                RSTC_DRIVER_Set_Reset_Reason("External Reset");
                RSTC_DRIVER_Set_Task_Completed_Status(true);
                rstc_driverData.state = RSTC_DRIVER_STATE_IDLE;
            }
            else
            {
                RSTC_DRIVER_Set_Reset_Reason("None");
                rstc_driverData.state = RSTC_DRIVER_STATE_CHECK_WDT_RESET;
            }
            break;
        }

        case RSTC_DRIVER_STATE_CHECK_WDT_RESET:
        {
            if (RSTC_ResetCauseGet() == RSTC_RESET_CAUSE_WDT_RESET)
            {
                RSTC_DRIVER_Set_Reset_Reason("Watchdog Reset");
                RSTC_DRIVER_Set_Task_Completed_Status(true);
                rstc_driverData.state = RSTC_DRIVER_STATE_IDLE;
            }
            else
            {
                RSTC_DRIVER_Set_Reset_Reason("None");
                rstc_driverData.state = RSTC_DRIVER_STATE_CHECK_SYST_RESET;
            }
            break;
        }

        case RSTC_DRIVER_STATE_CHECK_SYST_RESET:
        {
            if (RSTC_ResetCauseGet() == RSTC_RESET_CAUSE_SYST_RESET)
            {
                RSTC_DRIVER_Set_Reset_Reason("System Reset Request");
                RSTC_DRIVER_Set_Task_Completed_Status(true);
                rstc_driverData.state = RSTC_DRIVER_STATE_IDLE;
            }
            else
            {
                RSTC_DRIVER_Set_Reset_Reason("None");
                rstc_driverData.state = RSTC_DRIVER_STATE_IDLE;
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