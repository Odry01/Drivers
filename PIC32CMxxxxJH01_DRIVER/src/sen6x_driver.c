/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    sen6x_driver.c

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

#include "sen6x_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

SEN6X_DRIVER_DATA sen6x_driverData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void SEN6X_DRIVER_I2C_Callback(DRV_I2C_TRANSFER_EVENT EVENT, DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE, uintptr_t CONTEXT)
{
    switch (EVENT)
    {
        case DRV_I2C_TRANSFER_EVENT_COMPLETE:
        {
            sen6x_driverData.I2C_TRANSFER_STATUS = true;
            break;
        }

        case DRV_I2C_TRANSFER_EVENT_ERROR:
        {
            sen6x_driverData.I2C_TRANSFER_STATUS = false;
            break;
        }

        default:
        {
            break;
        }
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

bool SEN6X_DRIVER_Get_Task_Start_Status(void)
{
    return (sen6x_driverData.SEN6X_TASK_START);
}

void SEN6X_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    sen6x_driverData.SEN6X_TASK_START = STATUS;
}

bool SEN6X_DRIVER_Get_Task_Completed_Status(void)
{
    return (sen6x_driverData.SEN6X_TASK_COMPLETED);
}

void SEN6X_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    sen6x_driverData.SEN6X_TASK_COMPLETED = STATUS;
}

void SEN6X_DRIVER_Set_I2C_Address(void)
{
    sen6x_driverData.I2C_ADDRESS[0] = 0x6C;
    sen6x_driverData.I2C_ADDRESS[1] = 0x6F;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void SEN6X_DRIVER_Initialize(void)
{
    sen6x_driverData.state = SEN6X_DRIVER_STATE_INIT;
    sen6x_driverData.I2C_HANDLE = DRV_HANDLE_INVALID;
    sen6x_driverData.I2C_TRANSFER_HANDLE = DRV_I2C_TRANSFER_HANDLE_INVALID;
    sen6x_driverData.I2C_TRANSFER_STATUS = false;
}

void SEN6X_DRIVER_Tasks(void)
{
    switch (sen6x_driverData.state)
    {
        case SEN6X_DRIVER_STATE_INIT:
        {
            sen6x_driverData.I2C_HANDLE = DRV_I2C_Open(DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE);
            sen6x_driverData.state = SEN6X_DRIVER_STATE_I2C_HANDLER_REGISTER;
            break;
        }

        case SEN6X_DRIVER_STATE_I2C_HANDLER_REGISTER:
        {
            if (sen6x_driverData.I2C_HANDLE == DRV_HANDLE_INVALID)
            {
                sen6x_driverData.state = SEN6X_DRIVER_STATE_ERROR;
            }
            else
            {
                DRV_I2C_TransferEventHandlerSet(sen6x_driverData.I2C_HANDLE, SEN6X_DRIVER_I2C_Callback, (uintptr_t) & sen6x_driverData.I2C_TRANSFER_STATUS);
                sen6x_driverData.state = SEN6X_DRIVER_STATE_IDLE;
            }
            break;
        }

        case SEN6X_DRIVER_STATE_IDLE:
        {
            if (SEN6X_DRIVER_Get_Task_Start_Status() == true)
            {
                sen6x_driverData.state = SEN6X_DRIVER_STATE_IDLE;
            }
            break;
        }

        case SEN6X_DRIVER_STATE_TIMER_EXPIRED:
        {
            DRV_I2C_Close(sen6x_driverData.I2C_HANDLE);
            SEN6X_DRIVER_Set_Task_Completed_Status(true);
            sen6x_driverData.state = MCP9808_DRIVER_STATE_IDLE;
            break;
        }

        case SEN6X_DRIVER_STATE_ERROR:
        {
            DRV_I2C_Close(sen6x_driverData.I2C_HANDLE);
            SEN6X_DRIVER_Set_Task_Completed_Status(true);
            sen6x_driverData.state = MCP9808_DRIVER_STATE_IDLE;
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