/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    max17335_driver.c

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

#include "max17335_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************

MAX17335_DRIVER_DATA max17335_driverData;

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

bool MAX17335_DRIVER_Get_Task_Start_Status(void)
{
    return (max17335_driverData.MAX17335_TASK_START);
}

void MAX17335_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    max17335_driverData.MAX17335_TASK_START = STATUS;
}

bool MAX17335_DRIVER_Get_Task_Completed_Status(void)
{
    return (max17335_driverData.MAX17335_TASK_COMPLETED);
}

void MAX17335_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    max17335_driverData.MAX17335_TASK_COMPLETED = STATUS;
}

void MAX17335_DRIVER_Set_I2C_Address(void)
{
    max17335_driverData.I2C_ADDRESS[0] = 0x64;
}

bool MAX17335_DRIVER_Get_Alert_Status(void)
{
    return (max17335_driverData.MAX17335_ALERT);
}

void MAX17335_DRIVER_Set_Alert_Status(bool STATUS)
{
    max17335_driverData.MAX17335_ALERT = STATUS;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void MAX17335_DRIVER_Initialize(void)
{
    max17335_driverData.state = MAX17335_DRIVER_STATE_INIT;
    max17335_driverData.I2C_HANDLE = DRV_HANDLE_INVALID;
    max17335_driverData.I2C_TRANSFER_HANDLE = DRV_I2C_TRANSFER_HANDLE_INVALID;
}

void MAX17335_DRIVER_Tasks(void)
{
    switch (max17335_driverData.state)
    {
        case MAX17335_DRIVER_STATE_INIT:
        {
            max17335_driverData.state = MAX17335_DRIVER_STATE_SERVICE_TASKS;
            break;
        }

        case MAX17335_DRIVER_STATE_SERVICE_TASKS:
        {
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