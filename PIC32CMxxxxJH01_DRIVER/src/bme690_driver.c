/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    bme690_driver.c

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

#include "bme690_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

BME690_DRIVER_DATA bme690_driverData;

BME690_DRIVER_SENSOR_DATA bme690_sensorData;

BME690_DRIVER_CALIBRATION_DATA bme690_calibrationData;

BME690_DRIVER_HEATER_CONFIGURATION bme690_heaterConfig;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void BME690_DRIVER_I2C_Callback(DRV_I2C_TRANSFER_EVENT EVENT, DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE, uintptr_t CONTEXT)
{
    switch (EVENT)
    {
        case DRV_I2C_TRANSFER_EVENT_COMPLETE:
        {
            bme690_driverData.I2C_TRANSFER_STATUS = true;
            break;
        }

        case DRV_I2C_TRANSFER_EVENT_ERROR:
        {
            bme690_driverData.I2C_TRANSFER_STATUS = false;
            break;
        }

        default:
        {
            break;
        }
    }
}

void BME690_DRIVER_Alert(uintptr_t CONTEXT)
{
    bme690_driverData.BME690_ALERT = true;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

bool BME690_DRIVER_Get_Task_Start_Status(void)
{
    return (bme690_driverData.BME690_TASK_START);
}

void BME690_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    bme690_driverData.BME690_TASK_START = STATUS;
}

bool BME690_DRIVER_Get_Task_Completed_Status(void)
{
    return (bme690_driverData.BME690_TASK_COMPLETED);
}

void BME690_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    bme690_driverData.BME690_TASK_COMPLETED = STATUS;
}

void BME690_DRIVER_Write_Data(uint8_t REGISTER_ADDRESS, uint16_t VALUE, uint8_t LENGTH)
{
    if (LENGTH == 3)
    {
        bme690_driverData.I2C_DATA_TRANSMIT[0] = REGISTER_ADDRESS;
        bme690_driverData.I2C_DATA_TRANSMIT[1] = (VALUE >> 8) & 0xFF;
        bme690_driverData.I2C_DATA_TRANSMIT[2] = VALUE & 0xFF;
        DRV_I2C_WriteTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, LENGTH, &bme690_driverData.I2C_TRANSFER_HANDLE);
    }
    else
    {
        bme690_driverData.I2C_DATA_TRANSMIT[0] = REGISTER_ADDRESS;
        bme690_driverData.I2C_DATA_TRANSMIT[1] = VALUE & 0xFF;
        DRV_I2C_WriteTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, LENGTH, &bme690_driverData.I2C_TRANSFER_HANDLE);
    }
}

void BME690_DRIVER_Write_Read_Data(uint8_t REGISTER_ADDRESS, uint8_t LENGTH)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = REGISTER_ADDRESS;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, LENGTH, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Read_Data(uint8_t REGISTER_ADDRESS, uint8_t LENGTH)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = REGISTER_ADDRESS;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, LENGTH, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Get_Variant_ID(void)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_VARIANT_ID_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)
{
    SYS_CONSOLE_Print
            (
             CONSOLE_HANDLE,
             "Temperature: %.2f  C\r\n"
             "Humidity: %.2f %%\r\n",
             bme690_sensorData.TEMPERATURE,
             bme690_sensorData.HUMIDITY
             );
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void BME690_DRIVER_Initialize(void)
{
    bme690_driverData.state = BME690_DRIVER_STATE_INIT;
    bme690_driverData.I2C_HANDLE = DRV_HANDLE_INVALID;
    bme690_driverData.I2C_TRANSFER_HANDLE = DRV_I2C_TRANSFER_HANDLE_INVALID;
    bme690_driverData.I2C_TRANSFER_STATUS = false;
    EIC_CallbackRegister(EIC_PIN_0, BME690_DRIVER_Alert, 0);
}

void BME690_DRIVER_Tasks(void)
{
    switch (bme690_driverData.state)
    {
        case BME690_DRIVER_STATE_INIT:
        {
            bme690_driverData.I2C_HANDLE = DRV_I2C_Open(DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE);
            bme690_driverData.state = BME690_DRIVER_STATE_I2C_HANDLER_REGISTER;
            break;
        }

        case BME690_DRIVER_STATE_I2C_HANDLER_REGISTER:
        {
            if (bme690_driverData.I2C_HANDLE == DRV_HANDLE_INVALID)
            {
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else
            {
                DRV_I2C_TransferEventHandlerSet(bme690_driverData.I2C_HANDLE, BME690_DRIVER_I2C_Callback, (uintptr_t) & bme690_driverData.I2C_TRANSFER_STATUS);
                bme690_driverData.state = BME690_DRIVER_STATE_IDLE;
            }
            break;
        }

        case BME690_DRIVER_STATE_IDLE:
        {
            if (BME690_DRIVER_Get_Task_Start_Status() == true)
            {
                bme690_driverData.state = BME690_DRIVER_STATE_IDLE;
            }
            break;
        }

        case BME690_DRIVER_STATE_TIMER_EXPIRED:
        {
            DRV_I2C_Close(bme690_driverData.I2C_HANDLE);
            BME690_DRIVER_Set_Task_Completed_Status(true);
            bme690_driverData.state = MCP9808_DRIVER_STATE_IDLE;
            break;
        }

        case BME690_DRIVER_STATE_ERROR:
        {
            DRV_I2C_Close(bme690_driverData.I2C_HANDLE);
            BME690_DRIVER_Set_Task_Completed_Status(true);
            bme690_driverData.state = MCP9808_DRIVER_STATE_IDLE;
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