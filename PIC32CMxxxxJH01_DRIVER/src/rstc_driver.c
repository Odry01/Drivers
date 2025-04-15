/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    rstc_driver.c

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
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the RSTC_DRIVER_Initialize function.

    Application strings and buffers are be defined outside this structure.
 */

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

void RSTC_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)
{
    SYS_CONSOLE_Print
            (
             CONSOLE_HANDLE,
             "Reset reason: %d\r\n",
             rstc_driverData.RESET_REASON
             );
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void RSTC_DRIVER_Initialize ( void )

  Remarks:
    See prototype in rstc_driver.h.
 */

void RSTC_DRIVER_Initialize(void)
{
    rstc_driverData.state = RSTC_DRIVER_STATE_INIT;
}

/******************************************************************************
  Function:
    void RSTC_DRIVER_Tasks ( void )

  Remarks:
    See prototype in rstc_driver.h.
 */

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
                rstc_driverData.RESET_REASON = 1;
                RSTC_DRIVER_Set_Task_Completed_Status(true);
                rstc_driverData.state = RSTC_DRIVER_STATE_IDLE;
            }
            else
            {
                rstc_driverData.RESET_REASON = 0;
                RSTC_DRIVER_Set_Task_Completed_Status(false);
                rstc_driverData.state = RSTC_DRIVER_STATE_CHECK_BODCORE_RESET;
            }
            break;
        }

        case RSTC_DRIVER_STATE_CHECK_BODCORE_RESET:
        {
            if (RSTC_ResetCauseGet() == RSTC_RESET_CAUSE_BODCORE_RESET)
            {
                rstc_driverData.RESET_REASON = 2;
                RSTC_DRIVER_Set_Task_Completed_Status(true);
                rstc_driverData.state = RSTC_DRIVER_STATE_IDLE;
            }
            else
            {
                rstc_driverData.RESET_REASON = 0;
                RSTC_DRIVER_Set_Task_Completed_Status(false);
                rstc_driverData.state = RSTC_DRIVER_STATE_CHECK_BODVDD_RESET;
            }
            break;
        }

        case RSTC_DRIVER_STATE_CHECK_BODVDD_RESET:
        {
            if (RSTC_ResetCauseGet() == RSTC_RESET_CAUSE_BODVDD_RESET)
            {
                rstc_driverData.RESET_REASON = 3;
                RSTC_DRIVER_Set_Task_Completed_Status(true);
                rstc_driverData.state = RSTC_DRIVER_STATE_IDLE;
            }
            else
            {
                rstc_driverData.RESET_REASON = 0;
                RSTC_DRIVER_Set_Task_Completed_Status(false);
                rstc_driverData.state = RSTC_DRIVER_STATE_CHECK_EXT_RESET;
            }
            break;
        }

        case RSTC_DRIVER_STATE_CHECK_EXT_RESET:
        {
            if (RSTC_ResetCauseGet() == RSTC_RESET_CAUSE_EXT_RESET)
            {
                rstc_driverData.RESET_REASON = 4;
                RSTC_DRIVER_Set_Task_Completed_Status(true);
                rstc_driverData.state = RSTC_DRIVER_STATE_IDLE;
            }
            else
            {
                rstc_driverData.RESET_REASON = 0;
                RSTC_DRIVER_Set_Task_Completed_Status(false);
                rstc_driverData.state = RSTC_DRIVER_STATE_CHECK_WDT_RESET;
            }
            break;
        }

        case RSTC_DRIVER_STATE_CHECK_WDT_RESET:
        {
            if (RSTC_ResetCauseGet() == RSTC_RESET_CAUSE_WDT_RESET)
            {
                rstc_driverData.RESET_REASON = 5;
                RSTC_DRIVER_Set_Task_Completed_Status(true);
                rstc_driverData.state = RSTC_DRIVER_STATE_IDLE;
            }
            else
            {
                rstc_driverData.RESET_REASON = 0;
                RSTC_DRIVER_Set_Task_Completed_Status(false);
                rstc_driverData.state = RSTC_DRIVER_STATE_CHECK_SYST_RESET;
            }
            break;
        }

        case RSTC_DRIVER_STATE_CHECK_SYST_RESET:
        {
            if (RSTC_ResetCauseGet() == RSTC_RESET_CAUSE_SYST_RESET)
            {
                rstc_driverData.RESET_REASON = 6;
                RSTC_DRIVER_Set_Task_Completed_Status(true);
                rstc_driverData.state = RSTC_DRIVER_STATE_IDLE;
            }
            else
            {
                rstc_driverData.RESET_REASON = 0;
                RSTC_DRIVER_Set_Task_Completed_Status(true);
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