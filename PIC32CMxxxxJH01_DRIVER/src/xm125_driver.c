/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    xm125_driver.c

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

#include "xm125_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

XM125_DRIVER_DATA xm125_driverData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void XM125_DRIVER_Alert(uintptr_t CONTEXT)
{
    XM125_DRIVER_Set_Alert_Status(true);
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

bool XM125_DRIVER_Get_Task_Start_Status(void)
{
    return (xm125_driverData.XM125_TASK_START);
}

void XM125_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    xm125_driverData.XM125_TASK_START = STATUS;
}

bool XM125_DRIVER_Get_Task_Completed_Status(void)
{
    return (xm125_driverData.XM125_TASK_COMPLETED);
}

void XM125_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    xm125_driverData.XM125_TASK_COMPLETED = STATUS;
}

bool XM125_DRIVER_Get_Alert_Status(void)
{
    return (xm125_driverData.XM125_ALERT);
}

void XM125_DRIVER_Set_Alert_Status(bool STATUS)
{
    xm125_driverData.XM125_ALERT = STATUS;
}

void XM125_DRIVER_Set_I2C_Address(void)
{
    xm125_driverData.I2C_ADDRESS[0] = 0x51;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void XM125_DRIVER_Initialize(void)
{
    xm125_driverData.state = XM125_DRIVER_STATE_INIT;
    xm125_driverData.I2C_HANDLE = DRV_HANDLE_INVALID;
    xm125_driverData.I2C_TRANSFER_HANDLE = DRV_I2C_TRANSFER_HANDLE_INVALID;
    EIC_CallbackRegister(EIC_PIN_0, XM125_DRIVER_Alert, 0);
}

void XM125_DRIVER_Tasks(void)
{
    switch (xm125_driverData.state)
    {
        case XM125_DRIVER_STATE_INIT:
        {
            XM125_DRIVER_Set_I2C_Address();
            xm125_driverData.I2C_HANDLE = DRV_I2C_Open(DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE);
            xm125_driverData.state = XM125_DRIVER_STATE_CHECK_I2C_HANDLER;
            break;
        }

        case XM125_DRIVER_STATE_CHECK_I2C_HANDLER:
        {
            if (xm125_driverData.I2C_HANDLE == DRV_HANDLE_INVALID)
            {
                xm125_driverData.state = XM125_DRIVER_STATE_ERROR;
            }
            else
            {
                xm125_driverData.state = XM125_DRIVER_STATE_IDLE;
            }
            break;
        }

        case XM125_DRIVER_STATE_IDLE:
        {
            if (XM125_DRIVER_Get_Task_Start_Status() == true)
            {
                xm125_driverData.state = XM125_DRIVER_STATE_IDLE;
            }
            break;
        }

        case XM125_DRIVER_STATE_TIMER_EXPIRED:
        {
            DRV_I2C_Close(xm125_driverData.I2C_HANDLE);
            XM125_DRIVER_Set_Task_Completed_Status(true);
            xm125_driverData.state = MCP9808_DRIVER_STATE_IDLE;
            break;
        }

        case XM125_DRIVER_STATE_ERROR:
        {
            DRV_I2C_Close(xm125_driverData.I2C_HANDLE);
            XM125_DRIVER_Set_Task_Completed_Status(true);
            xm125_driverData.state = MCP9808_DRIVER_STATE_IDLE;
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