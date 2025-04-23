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

void BME690_DRIVER_Get_Variant_ID(void)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_VARIANT_ID_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_Variant_ID(void)
{
    bme690_sensorData.VARIANT_ID = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Reset_BME690(void)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_VARIANT_ID_REGISTER;
    bme690_driverData.I2C_DATA_TRANSMIT[1] = 0xFF;
    DRV_I2C_WriteTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, bme690_driverData.I2C_DATA_TRANSMIT, 2, &bme690_driverData.I2C_TRANSFER_HANDLE);

}

void BME690_DRIVER_Get_Chip_ID(void)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CHIP_ID_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_Chip_ID(void)
{
    bme690_sensorData.CHIP_ID = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_Config(void)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CONFIG_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_Config(void)
{
    bme690_sensorData.CONFIG = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Set_Config(uint8_t CONFIG)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CONFIG_REGISTER;
    bme690_driverData.I2C_DATA_TRANSMIT[1] = CONFIG;
    DRV_I2C_WriteTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, bme690_driverData.I2C_DATA_TRANSMIT, 2, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Get_Control_Measurement(void)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CTRL_MEAS_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_Control_Measurement(void)
{

}

void BME690_DRIVER_Set_Control_Measurement(uint8_t CONFIG)
{

}

void BME690_DRIVER_Get_Control_Humidity(void)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CTRL_HUM_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_Control_Humidity(void)
{

}

void BME690_DRIVER_Set_Control_Humidity(uint8_t CONFIG)
{

}

void BME690_DRIVER_Get_Control_Gas_1(void)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CTRL_GAS_1_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Set_Control_Gas_1(uint8_t CONFIG)
{

}

void BME690_DRIVER_Get_Control_Gas_0(void)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CTRL_GAS_0_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Set_Control_Gas_0(uint8_t CONFIG)
{

}

void BME690_DRIVER_Get_Gas_Wait_Shared(void)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_GAS_WAIT_SHARED_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Set_Gas_Wait_Shared(uint8_t CONFIG)
{

}

void BME690_DRIVER_Get_Gas_Wait(uint8_t REGISTER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_GAS_WAIT_X_REGISTER + REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Set_Gas_Wait(uint8_t REGISTER, uint8_t CONFIG)
{

}

void BME690_DRIVER_Get_Res_Heat(void)
{

}

void BME690_DRIVER_Set_Res_Heat(uint8_t REGISTER, uint8_t CONFIG)
{

}

void BME690_DRIVER_Get_Idac_Heat(void)
{

}

void BME690_DRIVER_Set_Idac_Heat(uint8_t REGISTER, uint8_t CONFIG)
{

}

void BME690_DRIVER_Get_Gas_LSB(uint8_t REGISTER)
{

}

void BME690_DRIVER_Store_Gas_LSB(void)
{

}

void BME690_DRIVER_Get_Gas_MSB(uint8_t REGISTER)
{

}

void BME690_DRIVER_Store_Gas_MSB(void)
{

}

void BME690_DRIVER_Get_Humidity_LSB(uint8_t REGISTER)
{

}

void BME690_DRIVER_Store_Humidity_LSB(void)
{

}

void BME690_DRIVER_Get_Humidity_MSB(uint8_t REGISTER)
{

}

void BME690_DRIVER_Store_Humidity_MSB(void)
{

}

void BME690_DRIVER_Get_Temperature_XLSB(uint8_t REGISTER)
{

}

void BME690_DRIVER_Store_Temperature_XLSB(void)
{

}

void BME690_DRIVER_Get_Temperature_LSB(uint8_t REGISTER)
{

}

void BME690_DRIVER_Store_Temperature_LSB(void)
{

}

void BME690_DRIVER_Get_Temperature_MSB(uint8_t REGISTER)
{

}

void BME690_DRIVER_Store_Temperature_MSB(void)
{

}

void BME690_DRIVER_Get_Pressure_XLSB(uint8_t REGISTER)
{

}

void BME690_DRIVER_Store_Pressure_XLSB(void)
{

}

void BME690_DRIVER_Get_Pressure_LSB(uint8_t REGISTER)
{

}

void BME690_DRIVER_Store_Pressure_LSB(void)
{

}

void BME690_DRIVER_Get_Pressure_MSB(uint8_t REGISTER)
{

}

void BME690_DRIVER_Store_Pressure_MSB(void)
{

}

void BME690_DRIVER_Get_Sub_Measurement_Status(uint8_t REGISTER)
{

}

void BME690_DRIVER_Get_Measurement_Status(uint8_t REGISTER)
{

}

void BME690_DRIVER_Get_Calibration_Register_Value(uint8_t REGISTER)
{

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
            bme690_driverData.state = BME690_DRIVER_STATE_SERVICE_TASKS;
            break;
        }

        case BME690_DRIVER_STATE_SERVICE_TASKS:
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