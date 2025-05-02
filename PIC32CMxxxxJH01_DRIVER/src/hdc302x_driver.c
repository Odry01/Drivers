/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    hdc302x_driver.c

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

#include "hdc302x_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

HDC302X_DRIVER_DATA hdc302x_driverData;

HDC302X_DRIVER_SENSOR_DATA hdc302x_sensorData;

HDC302X_DRIVER_SENSOR_SETTINGS hdc302x_sensorSettings;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void HDC302X_DRIVER_I2C_Callback(DRV_I2C_TRANSFER_EVENT EVENT, DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE, uintptr_t CONTEXT)
{
    switch (EVENT)
    {
        case DRV_I2C_TRANSFER_EVENT_COMPLETE:
        {
            hdc302x_driverData.I2C_TRANSFER_STATUS = true;
            break;
        }

        case DRV_I2C_TRANSFER_EVENT_ERROR:
        {
            hdc302x_driverData.I2C_TRANSFER_STATUS = false;
            break;
        }

        default:
        {
            break;
        }
    }
}

void HDC302X_DRIVER_Temperature_Alert(uintptr_t CONTEXT)
{
    hdc302x_driverData.HDC302X_ALERT = true;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

bool HDC302X_DRIVER_Get_Task_Start_Status(void)
{
    return (hdc302x_driverData.HDC302X_TASK_START);
}

void HDC302X_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    hdc302x_driverData.HDC302X_TASK_START = STATUS;
}

bool HDC302X_DRIVER_Get_Task_Completed_Status(void)
{
    return (hdc302x_driverData.HDC302X_TASK_COMPLETED);
}

void HDC302X_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    hdc302x_driverData.HDC302X_TASK_COMPLETED = STATUS;
}

void HDC302X_DRIVER_Set_Offset_Values(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_OFFSET_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_OFFSET_LSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[2] = hdc302x_sensorSettings.OFFSET_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[3] = hdc302x_sensorSettings.OFFSET_LSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[4] = HDC302X_DRIVER_Calculation_Array_CRC(hdc302x_driverData.I2C_DATA_TRANSMIT[2], hdc302x_driverData.I2C_DATA_TRANSMIT[3]);
    DRV_I2C_WriteTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 5, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Set_Set_High_Alert(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_WR_ALERT_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_WR_ALERT_SET_HI;
    hdc302x_driverData.I2C_DATA_TRANSMIT[2] = hdc302x_sensorSettings.SET_HIGH_ALERT_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[3] = hdc302x_sensorSettings.SET_HIGH_ALERT_LSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[4] = HDC302X_DRIVER_Calculation_Array_CRC(hdc302x_driverData.I2C_DATA_TRANSMIT[2], hdc302x_driverData.I2C_DATA_TRANSMIT[3]);
    DRV_I2C_WriteTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 5, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Set_Clear_High_Alert(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_WR_ALERT_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_WR_ALERT_CLR_HI;
    hdc302x_driverData.I2C_DATA_TRANSMIT[2] = hdc302x_sensorSettings.CLEAR_HIGH_ALERT_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[3] = hdc302x_sensorSettings.CLEAR_HIGH_ALERT_LSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[4] = HDC302X_DRIVER_Calculation_Array_CRC(hdc302x_driverData.I2C_DATA_TRANSMIT[2], hdc302x_driverData.I2C_DATA_TRANSMIT[3]);
    DRV_I2C_WriteTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 5, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Set_Set_Low_Alert(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_WR_ALERT_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_WR_ALERT_SET_LO;
    hdc302x_driverData.I2C_DATA_TRANSMIT[2] = hdc302x_sensorSettings.SET_LOW_ALERT_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[3] = hdc302x_sensorSettings.SET_LOW_ALERT_LSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[4] = HDC302X_DRIVER_Calculation_Array_CRC(hdc302x_driverData.I2C_DATA_TRANSMIT[2], hdc302x_driverData.I2C_DATA_TRANSMIT[3]);
    DRV_I2C_WriteTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 5, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Set_Clear_Low_Alert(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_WR_ALERT_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_WR_ALERT_CLR_LO;
    hdc302x_driverData.I2C_DATA_TRANSMIT[2] = hdc302x_sensorSettings.CLEAR_LOW_ALERT_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[3] = hdc302x_sensorSettings.CLEAR_LOW_ALERT_LSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[4] = HDC302X_DRIVER_Calculation_Array_CRC(hdc302x_driverData.I2C_DATA_TRANSMIT[2], hdc302x_driverData.I2C_DATA_TRANSMIT[3]);
    DRV_I2C_WriteTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 5, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Get_Offset_Values(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_OFFSET_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_OFFSET_LSB;
    DRV_I2C_WriteReadTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 2, &hdc302x_driverData.I2C_DATA_RECEIVE, 3, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Store_Offset_Values(void)
{
    hdc302x_sensorData.OFFSET_MSB = hdc302x_driverData.I2C_DATA_RECEIVE[0];
    hdc302x_sensorData.OFFSET_LSB = hdc302x_driverData.I2C_DATA_RECEIVE[1];
}

void HDC302X_DRIVER_Get_Set_High_Alert(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_RD_ALERT_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_RD_ALERT_SET_HI;
    DRV_I2C_WriteReadTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 2, &hdc302x_driverData.I2C_DATA_RECEIVE, 3, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Store_Set_High_Alert(void)
{
    hdc302x_sensorData.SET_HIGH_ALERT_MSB = hdc302x_driverData.I2C_DATA_RECEIVE[0];
    hdc302x_sensorData.SET_HIGH_ALERT_LSB = hdc302x_driverData.I2C_DATA_RECEIVE[1];
}

void HDC302X_DRIVER_Get_Clear_High_Alert(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_RD_ALERT_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_RD_ALERT_CLR_HI;
    DRV_I2C_WriteReadTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 2, &hdc302x_driverData.I2C_DATA_RECEIVE, 3, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Store_Clear_High_Alert(void)
{
    hdc302x_sensorData.CLEAR_HIGH_ALERT_MSB = hdc302x_driverData.I2C_DATA_RECEIVE[0];
    hdc302x_sensorData.CLEAR_HIGH_ALERT_LSB = hdc302x_driverData.I2C_DATA_RECEIVE[1];
}

void HDC302X_DRIVER_Get_Set_Low_Alert(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_RD_ALERT_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_RD_ALERT_SET_LO;
    DRV_I2C_WriteReadTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 2, &hdc302x_driverData.I2C_DATA_RECEIVE, 3, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Store_Set_Low_Alert(void)
{
    hdc302x_sensorData.SET_LOW_ALERT_MSB = hdc302x_driverData.I2C_DATA_RECEIVE[0];
    hdc302x_sensorData.SET_LOW_ALERT_LSB = hdc302x_driverData.I2C_DATA_RECEIVE[1];
}

void HDC302X_DRIVER_Get_Clear_Low_Alert(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_RD_ALERT_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_RD_ALERT_CLR_LO;
    DRV_I2C_WriteReadTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 2, &hdc302x_driverData.I2C_DATA_RECEIVE, 3, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Store_Clear_Low_Alert(void)
{
    hdc302x_sensorData.CLEAR_LOW_ALERT_MSB = hdc302x_driverData.I2C_DATA_RECEIVE[0];
    hdc302x_sensorData.CLEAR_LOW_ALERT_LSB = hdc302x_driverData.I2C_DATA_RECEIVE[1];
}

void HDC302X_DRIVER_Enter_Auto_Measurement_Mode(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = hdc302x_sensorSettings.MODE_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = hdc302x_sensorSettings.MODE_LSB;
    DRV_I2C_WriteTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 2, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Exit_Auto_Measurement_Mode(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = hdc302x_sensorSettings.MODE_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = hdc302x_sensorSettings.MODE_LSB;
    DRV_I2C_WriteTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 2, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Start_Manual_Measurement(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = hdc302x_sensorSettings.MODE_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = hdc302x_sensorSettings.MODE_LSB;
    DRV_I2C_WriteTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 2, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Get_Manual_Measure_Values(uint8_t I2C_ADDRESS)
{
    DRV_I2C_ReadTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_RECEIVE, 6, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Get_Auto_Measure_Values(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_MODE_READ_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_MODE_READ;
    DRV_I2C_WriteReadTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 2,&hdc302x_driverData.I2C_DATA_RECEIVE, 6, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Store_Measurement_Values(void)
{
    hdc302x_sensorData.T_VALUE = hdc302x_driverData.I2C_DATA_RECEIVE[0] << 8 | hdc302x_driverData.I2C_DATA_RECEIVE[1];
    hdc302x_sensorData.H_VALUE = hdc302x_driverData.I2C_DATA_RECEIVE[3] << 8 | hdc302x_driverData.I2C_DATA_RECEIVE[4];
}

void HDC302X_DRIVER_Get_Minimum_Temperature_Value(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_MODE_READ_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_MODE_READ_MIN_T;
    DRV_I2C_WriteReadTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 2, &hdc302x_driverData.I2C_DATA_RECEIVE, 3, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Store_Minimum_Temperature_Value(void)
{
    hdc302x_sensorData.T_VALUE = hdc302x_driverData.I2C_DATA_RECEIVE[0] << 8 | hdc302x_driverData.I2C_DATA_RECEIVE[1];
}

void HDC302X_DRIVER_Get_Maximum_Temperature_Value(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_MODE_READ_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_MODE_READ_MAX_T;
    DRV_I2C_WriteReadTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 2, &hdc302x_driverData.I2C_DATA_RECEIVE, 3, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Store_Maximum_Temperature_Value(void)
{
    hdc302x_sensorData.T_VALUE = hdc302x_driverData.I2C_DATA_RECEIVE[0] << 8 | hdc302x_driverData.I2C_DATA_RECEIVE[1];
}

void HDC302X_DRIVER_Get_Minimum_Humidity_Value(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_MODE_READ_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_MODE_READ_MIN_H;
    DRV_I2C_WriteReadTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 2, &hdc302x_driverData.I2C_DATA_RECEIVE, 3, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Store_Minimum_Humidity_Value(void)
{
    hdc302x_sensorData.H_VALUE = hdc302x_driverData.I2C_DATA_RECEIVE[0] << 8 | hdc302x_driverData.I2C_DATA_RECEIVE[1];
}

void HDC302X_DRIVER_Get_Maximum_Humidity_Value(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_MODE_READ_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_MODE_READ_MAX_H;
    DRV_I2C_WriteReadTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 2, &hdc302x_driverData.I2C_DATA_RECEIVE, 3, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Store_Maximum_Humidity_Value(void)
{
    hdc302x_sensorData.H_VALUE = hdc302x_driverData.I2C_DATA_RECEIVE[0] << 8 | hdc302x_driverData.I2C_DATA_RECEIVE[1];
}

void HDC302X_DRIVER_Calculation_Temperature(uint16_t T_VALUE)
{
    hdc302x_sensorData.CELSIUS_TEMPERATURE = -45 + 175 * ((float) T_VALUE / 65535);
    hdc302x_sensorData.FAHRENHEIT_TEMPERATURE = -49 + 315 * ((float) T_VALUE / 65535);
}

void HDC302X_DRIVER_Calculation_Humidity(uint16_t H_VALUE)
{
    hdc302x_sensorData.HUMIDITY = ((float) H_VALUE / 65535) * 100;
}

void HDC302X_DRIVER_Get_Sensor_Status(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_STATUS_READ_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_STATUS_READ_LSB;
    DRV_I2C_WriteReadTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 2, &hdc302x_driverData.I2C_DATA_RECEIVE, 3, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Store_Sensor_Status(void)
{
    hdc302x_sensorData.STATUS_MSB = hdc302x_driverData.I2C_DATA_RECEIVE[0];
    hdc302x_sensorData.STATUS_LSB = hdc302x_driverData.I2C_DATA_RECEIVE[1];
}

void HDC302X_DRIVER_Get_NIST_3(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_RD_NIST_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_RD_NIST_3;
    DRV_I2C_WriteReadTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 2, &hdc302x_driverData.I2C_DATA_RECEIVE, 3, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Store_NIST_3(void)
{
    hdc302x_sensorData.NIST_VALUE_5 = hdc302x_driverData.I2C_DATA_RECEIVE[0];
    hdc302x_sensorData.NIST_VALUE_4 = hdc302x_driverData.I2C_DATA_RECEIVE[1];
}

void HDC302X_DRIVER_Get_NIST_2(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_RD_NIST_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_RD_NIST_2;
    DRV_I2C_WriteReadTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 2, &hdc302x_driverData.I2C_DATA_RECEIVE, 3, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Store_NIST_2(void)
{
    hdc302x_sensorData.NIST_VALUE_3 = hdc302x_driverData.I2C_DATA_RECEIVE[0];
    hdc302x_sensorData.NIST_VALUE_2 = hdc302x_driverData.I2C_DATA_RECEIVE[1];
}

void HDC302X_DRIVER_Get_NIST_1(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_RD_NIST_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_RD_NIST_1;
    DRV_I2C_WriteReadTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 2, &hdc302x_driverData.I2C_DATA_RECEIVE, 3, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Store_NIST_1(void)
{
    hdc302x_sensorData.NIST_VALUE_1 = hdc302x_driverData.I2C_DATA_RECEIVE[0];
    hdc302x_sensorData.NIST_VALUE_0 = hdc302x_driverData.I2C_DATA_RECEIVE[1];
}

void HDC302X_DRIVER_Soft_Reset(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_SOFT_RESET_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_SOFT_RESET_LSB;
    DRV_I2C_WriteTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 2, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Enable_Heater(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_HEATER_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_HEATER_ENABLE;
    DRV_I2C_WriteTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 2, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Disable_Heater(uint8_t I2C_ADDRESS)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_HEATER_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_HEATER_DISABLE;
    DRV_I2C_WriteTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 2, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

void HDC302X_DRIVER_Configuration_Heater(uint8_t I2C_ADDRESS, uint8_t CURRENT_MSB, uint8_t CURRENT_LSB)
{
    hdc302x_driverData.I2C_DATA_TRANSMIT[0] = HDC302X_HEATER_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[1] = HDC302X_HEATER_CFG;
    hdc302x_driverData.I2C_DATA_TRANSMIT[2] = CURRENT_MSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[3] = CURRENT_LSB;
    hdc302x_driverData.I2C_DATA_TRANSMIT[4] = HDC302X_DRIVER_Calculation_Array_CRC(hdc302x_driverData.I2C_DATA_TRANSMIT[2], hdc302x_driverData.I2C_DATA_TRANSMIT[3]);
    DRV_I2C_WriteTransferAdd(hdc302x_driverData.I2C_HANDLE, I2C_ADDRESS, &hdc302x_driverData.I2C_DATA_TRANSMIT, 5, &hdc302x_driverData.I2C_TRANSFER_HANDLE);
}

uint8_t HDC302X_DRIVER_Calculation_CRC(uint8_t MESSAGE[], uint8_t MESSAGE_LENGTH)
{
    uint8_t CRC = 0xFF;
    uint8_t BIT;
    for (uint8_t BYTE = 0; BYTE < MESSAGE_LENGTH; BYTE++)
    {
        CRC ^= MESSAGE[BYTE];
        for (BIT = 0; BIT < 8; BIT++)
        {
            if (CRC & 0x80)
            {
                CRC = (CRC << 1) ^ 0x31;
            }
            else
            {
                CRC = (CRC << 1);
            }
        }
    }
    return CRC;
}

uint8_t HDC302X_DRIVER_Calculation_Array_CRC(uint8_t MESSAGE_0, uint8_t MESSAGE_1)
{
    uint8_t MESSAGE[2] = {MESSAGE_0, MESSAGE_1};
    return HDC302X_DRIVER_Calculation_CRC(MESSAGE, 2);
}

uint16_t HDC302X_DRIVER_Set_Offset_Code(uint16_t TEMPERATURE, uint16_t HUMIDITY)
{
    uint16_t MASK = 0x8080;
    if (TEMPERATURE < 0)
    {
        TEMPERATURE *= -1;
        MASK &= 0xFF7F;
    }
    if (HUMIDITY < 0)
    {
        HUMIDITY *= -1;
        MASK &= 0x7FFF;
    }
    uint16_t T_CODE = TEMPERATURE * 65535 / 175;
    uint16_t H_CODE = HUMIDITY * 65535 / 100;
    return ((H_CODE << 1) & 0x7F00) | ((T_CODE >> 6) & 0x7F) | MASK;
}

uint16_t HDC302X_DRIVER_Set_ALERT_Code(uint16_t TEMPERATURE, uint16_t HUMIDITY)
{
    uint16_t T_CODE = (TEMPERATURE + 45) * 65535 / 175;
    uint16_t H_CODE = HUMIDITY * 65535 / 100;
    return (H_CODE & 0xFE00) | ((T_CODE >> 7) & 0x1FF);
}

void HDC302X_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)
{
    SYS_CONSOLE_Print
            (
             CONSOLE_HANDLE,
             "Temperature: %.2f °C\r\n"
             "Temperature: %.2f °F\r\n"
             "Humidity: %.2f %%\r\n",
             hdc302x_sensorData.CELSIUS_TEMPERATURE,
             hdc302x_sensorData.FAHRENHEIT_TEMPERATURE,
             hdc302x_sensorData.HUMIDITY
             );
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void HDC302X_DRIVER_Initialize(void)
{
    hdc302x_driverData.state = HDC302X_DRIVER_STATE_INIT;
    hdc302x_driverData.I2C_HANDLE = DRV_HANDLE_INVALID;
    hdc302x_driverData.I2C_TRANSFER_HANDLE = DRV_I2C_TRANSFER_HANDLE_INVALID;
    hdc302x_driverData.I2C_TRANSFER_STATUS = false;
}

void HDC302X_DRIVER_Tasks(void)
{
    switch (hdc302x_driverData.state)
    {
        case HDC302X_DRIVER_STATE_INIT:
        {
            hdc302x_driverData.I2C_HANDLE = DRV_I2C_Open(DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE);
            hdc302x_driverData.state = HDC302X_DRIVER_STATE_I2C_HANDLER_REGISTER;
            break;
        }

        case HDC302X_DRIVER_STATE_I2C_HANDLER_REGISTER:
        {
            if (hdc302x_driverData.I2C_HANDLE == DRV_HANDLE_INVALID)
            {
                hdc302x_driverData.state = HDC302X_DRIVER_STATE_ERROR;
            }
            else
            {
                DRV_I2C_TransferEventHandlerSet(hdc302x_driverData.I2C_HANDLE, HDC302X_DRIVER_I2C_Callback, (uintptr_t) &hdc302x_driverData.I2C_TRANSFER_STATUS);
                hdc302x_driverData.state = HDC302X_DRIVER_STATE_IDLE;
            }
            break;
        }

        case HDC302X_DRIVER_STATE_IDLE:
        {
            if (HDC302X_DRIVER_Get_Task_Start_Status() == true)
            {
                hdc302x_driverData.state = HDC302X_DRIVER_STATE_IDLE;
            }
            break;
        }
        
        case HDC302X_DRIVER_STATE_TIMER_EXPIRED:
        {
            DRV_I2C_Close(hdc302x_driverData.I2C_HANDLE);
            HDC302X_DRIVER_Set_Task_Completed_Status(true);
            hdc302x_driverData.state = MCP9808_DRIVER_STATE_IDLE;
            break;
        }

        case HDC302X_DRIVER_STATE_ERROR:
        {
            DRV_I2C_Close(hdc302x_driverData.I2C_HANDLE);
            HDC302X_DRIVER_Set_Task_Completed_Status(true);
            hdc302x_driverData.state = MCP9808_DRIVER_STATE_IDLE;
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