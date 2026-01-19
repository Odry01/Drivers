/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    sen63c_driver.c

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

#include "sen63c_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

SEN63C_DRIVER_DATA sen63c_driverData;

SEN63C_SENSOR_DATA sen63c_sensorData;

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

bool SEN63C_DRIVER_Get_Task_Start_Status(void)
{
    return (sen63c_driverData.SEN63C_TASK_START);
}

void SEN63C_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    sen63c_driverData.SEN63C_TASK_START = STATUS;
}

bool SEN63C_DRIVER_Get_Task_Completed_Status(void)
{
    return (sen63c_driverData.SEN63C_TASK_COMPLETED);
}

void SEN63C_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    sen63c_driverData.SEN63C_TASK_COMPLETED = STATUS;
}

void SEN63C_DRIVER_Set_I2C_Address(void)
{
    sen63c_driverData.I2C_ADDRESS[0] = 0x6C;
}

void SEN63C_DRIVER_Start_Measurement(uint8_t I2C_ADDRESS)
{
    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_START_MEASUREMENT_MSB;
    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_START_MEASUREMENT_LSB;
    DRV_I2C_WriteTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 2, &sen63c_driverData.I2C_TRANSFER_HANDLE);
}

void SEN63C_DRIVER_Stop_Measurement(uint8_t I2C_ADDRESS)
{
    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_STOP_MEASUREMENT_MSB;
    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_STOP_MEASUREMENT_LSB;
    DRV_I2C_WriteTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 2, &sen63c_driverData.I2C_TRANSFER_HANDLE);
}

void SEN63C_DRIVER_Get_Data_Ready_Status(uint8_t I2C_ADDRESS)
{
    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_GET_DATA_READY_MSB;
    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_GET_DATA_READY_LSB;
    DRV_I2C_WriteReadTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 2, (void*) &sen63c_driverData.I2C_DATA_RECEIVE, 3, &sen63c_driverData.I2C_TRANSFER_HANDLE);
}

void SEN63C_DRIVER_Store_Data_Ready_Status(void)
{

}

void SEN63C_DRIVER_Read_Measured_Values(uint8_t I2C_ADDRESS)
{
    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_READ_MEASURED_VALUES_MSB;
    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_READ_MEASURED_VALUES_LSB;
    DRV_I2C_WriteReadTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 2, (void*) &sen63c_driverData.I2C_DATA_RECEIVE, 21, &sen63c_driverData.I2C_TRANSFER_HANDLE);
}

void SEN63C_DRIVER_Store_Measured_Values(void)
{

}

void SEN63C_DRIVER_Read_Measured_Raw_Values(uint8_t I2C_ADDRESS)
{
    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_READ_MEASURED_RAW_VALUES_MSB;
    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_READ_MEASURED_RAW_VALUES_LSB;
    DRV_I2C_WriteReadTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 2, (void*) &sen63c_driverData.I2C_DATA_RECEIVE, 6, &sen63c_driverData.I2C_TRANSFER_HANDLE);
}

void SEN63C_DRIVER_Store_Measured_Raw_Values(void)
{

}

void SEN63C_DRIVER_Read_Number_Concentration_Values(uint8_t I2C_ADDRESS)
{
    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_READ_NUMBER_CONCENTRATION_VALUES_MSB;
    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_READ_NUMBER_CONCENTRATION_VALUES_LSB;
    DRV_I2C_WriteReadTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 2, (void*) &sen63c_driverData.I2C_DATA_RECEIVE, 15, &sen63c_driverData.I2C_TRANSFER_HANDLE);
}

void SEN63C_DRIVER_Store_Number_Concentration_Values(void)
{

}

//void SEN63C_DRIVER_Set_Temperature_Offset_Parameters(uint8_t I2C_ADDRESS, int8_t TEMPERATURE_OFFSET_MSB, int8_t TEMPERATURE_OFFSET_LSB, int8_t SLOPE_MSB, int8_t SLOPE_LSB, uint8_t TIME_CONSTANT_MSB, uint8_t TIME_CONSTANT_LSB, uint8_t SLOT_MSB, uint8_t SLOT_LSB)
//{
//    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_SET_TEMPERATURE_OFFSET_PARAMETERS_MSB;
//    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_SET_TEMPERATURE_OFFSET_PARAMETERS_LSB;
//    sen63c_driverData.I2C_DATA_TRANSMIT[2] = TEMPERATURE_OFFSET_MSB;
//    sen63c_driverData.I2C_DATA_TRANSMIT[3] = TEMPERATURE_OFFSET_LSB;
//    sen63c_driverData.I2C_DATA_TRANSMIT[4] = SEN63C_DRIVER_Calculation_Array_CRC(sen63c_driverData.I2C_DATA_TRANSMIT[2], sen63c_driverData.I2C_DATA_TRANSMIT[3]);
//    sen63c_driverData.I2C_DATA_TRANSMIT[5] = SLOPE_MSB;
//    sen63c_driverData.I2C_DATA_TRANSMIT[6] = SLOPE_LSB;
//    sen63c_driverData.I2C_DATA_TRANSMIT[7] = SEN63C_DRIVER_Calculation_Array_CRC(sen63c_driverData.I2C_DATA_TRANSMIT[5], sen63c_driverData.I2C_DATA_TRANSMIT[6]);
//    sen63c_driverData.I2C_DATA_TRANSMIT[8] = TIME_CONSTANT_MSB;
//    sen63c_driverData.I2C_DATA_TRANSMIT[9] = TIME_CONSTANT_LSB;
//    sen63c_driverData.I2C_DATA_TRANSMIT[10] = SEN63C_DRIVER_Calculation_Array_CRC(sen63c_driverData.I2C_DATA_TRANSMIT[8], sen63c_driverData.I2C_DATA_TRANSMIT[9]);
//    sen63c_driverData.I2C_DATA_TRANSMIT[12] = SLOT_MSB;
//    sen63c_driverData.I2C_DATA_TRANSMIT[13] = SLOT_LSB;
//    sen63c_driverData.I2C_DATA_TRANSMIT[14] = SEN63C_DRIVER_Calculation_Array_CRC(sen63c_driverData.I2C_DATA_TRANSMIT[12], sen63c_driverData.I2C_DATA_TRANSMIT[13]);
//    DRV_I2C_WriteTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 15, &sen63c_driverData.I2C_TRANSFER_HANDLE);
//}

//void SEN63C_DRIVER_Set_Temperature_Acceleration_Parameters (uint8_t I2C_ADDRESS)
//{
//    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_SET_TEMPERATURE_ACCELERATION_PARAMETERS_MSB;
//    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_SET_TEMPERATURE_ACCELERATION_PARAMETERS_LSB;
//}

void SEN63C_DRIVER_Get_Product_Name(uint8_t I2C_ADDRESS)
{
    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_GET_PRODUCT_NAME_MSB;
    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_GET_PRODUCT_NAME_LSB;
    DRV_I2C_WriteReadTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 2, (void*) &sen63c_driverData.I2C_DATA_RECEIVE, 48, &sen63c_driverData.I2C_TRANSFER_HANDLE);
}

void SEN63C_DRIVER_Store_Product_Name(void)
{
    
}

void SEN63C_DRIVER_Get_Serial_Number(uint8_t I2C_ADDRESS)
{
    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_GET_SERIAL_NUMBER_MSB;
    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_GET_SERIAL_NUMBER_LSB;
    DRV_I2C_WriteReadTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 2, (void*) &sen63c_driverData.I2C_DATA_RECEIVE, 48, &sen63c_driverData.I2C_TRANSFER_HANDLE);
}

void SEN63C_DRIVER_Store_Serial_Number(void)
{

}

void SEN63C_DRIVER_Read_Device_Status(uint8_t I2C_ADDRESS)
{
    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_READ_DEVICE_STATUS_MSB;
    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_READ_DEVICE_STATUS_LSB;
    DRV_I2C_WriteReadTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 2, (void*) &sen63c_driverData.I2C_DATA_RECEIVE, 6, &sen63c_driverData.I2C_TRANSFER_HANDLE);
}

void SEN63C_DRIVER_Read_And_Clear_Device_Status(uint8_t I2C_ADDRESS)
{
    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_READ_AND_CLEAR_DEVICE_STATUS_MSB;
    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_READ_AND_CLEAR_DEVICE_STATUS_LSB;
    DRV_I2C_WriteReadTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 2, (void*) &sen63c_driverData.I2C_DATA_RECEIVE, 6, &sen63c_driverData.I2C_TRANSFER_HANDLE);
}

void SEN63C_DRIVER_Store_Device_Status(void)
{
    sen63c_sensorData.DEVICE_STATUS = sen63c_driverData.I2C_DATA_RECEIVE[0] << 8 | sen63c_driverData.I2C_DATA_RECEIVE[1];
}

void SEN63C_DRIVER_Get_FW_Version(uint8_t I2C_ADDRESS)
{
    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_GET_VERSION_MSB;
    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_GET_VERSION_LSB;
    DRV_I2C_WriteReadTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 2, (void*) &sen63c_driverData.I2C_DATA_RECEIVE, 12, &sen63c_driverData.I2C_TRANSFER_HANDLE);
}

void SEN63C_DRIVER_Store_FW_Version(void)
{
sen63c_sensorData.FW_VERSION = sen63c_driverData.I2C_DATA_RECEIVE[0] << 8 | sen63c_driverData.I2C_DATA_RECEIVE[1];
}

void SEN63C_DRIVER_Reset_Device(uint8_t I2C_ADDRESS)
{
    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_DEVICE_RESET_MSB;
    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_DEVICE_RESET_LSB;
    DRV_I2C_WriteTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 2, &sen63c_driverData.I2C_TRANSFER_HANDLE);
}

void SEN63C_DRIVER_Start_Fan_Cleaning(uint8_t I2C_ADDRESS)
{
    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_START_FAN_CLEANING_MSB;
    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_START_FAN_CLEANING_LSB;
    DRV_I2C_WriteTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 2, &sen63c_driverData.I2C_TRANSFER_HANDLE);
}

void SEN63C_DRIVER_Activate_Heater(uint8_t I2C_ADDRESS)
{
    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_ACTIVATE_SHT_HEATER_MSB;
    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_ACTIVATE_SHT_HEATER_LSB;
    DRV_I2C_WriteTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 2, &sen63c_driverData.I2C_TRANSFER_HANDLE);
}

void SEN63C_DRIVER_Get_Heater_Measurement(uint8_t I2C_ADDRESS)
{
    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_GET_SHT_HEATER_MEASUREMENTS_MSB;
    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_GET_SHT_HEATER_MEASUREMENTS_MSB;
    DRV_I2C_WriteReadTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 2, (void*) &sen63c_driverData.I2C_DATA_RECEIVE, 6, &sen63c_driverData.I2C_TRANSFER_HANDLE);
}

void SEN63C_DRIVER_Store_Heater_Measurement(void)
{
    sen63c_sensorData.T_VALUE = sen63c_driverData.I2C_DATA_RECEIVE[0] << 8 | sen63c_driverData.I2C_DATA_RECEIVE[1];
    sen63c_sensorData.H_VALUE = sen63c_driverData.I2C_DATA_RECEIVE[3] << 8 | sen63c_driverData.I2C_DATA_RECEIVE[4];
}

//void SEN63C_DRIVER_Perform_Forced_CO2_Recalibration(uint8_t I2C_ADDRESS)
//{
//    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_PERFORM_FORCED_CO2_RECALIBRATION_MSB;
//    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_PERFORM_FORCED_CO2_RECALIBRATION_MSB;
//    DRV_I2C_WriteReadTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 5, (void*) &sen63c_driverData.I2C_DATA_RECEIVE, 3, &sen63c_driverData.I2C_TRANSFER_HANDLE);
//}
//
//void SEN63C_DRIVER_Store_Forced_CO2_Recalibration(void)
//{
//
//}

void SEN63C_DRIVER_Get_CO2_Sensor_Automatic_Self_Calibration(uint8_t I2C_ADDRESS)
{
    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_GET_CO2_SENSOR_AUTOMATIC_SELF_CALIBRATION_MSB;
    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_GET_CO2_SENSOR_AUTOMATIC_SELF_CALIBRATION_MSB;
    DRV_I2C_WriteReadTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 2, (void*) &sen63c_driverData.I2C_DATA_RECEIVE, 3, &sen63c_driverData.I2C_TRANSFER_HANDLE);
}

void SEN63C_DRIVER_Store_CO2_Sensor_Automatic_Self_Calibration(void)
{

}

//void SEN63C_DRIVER_Set_CO2_Sensor_Automatic_Self_Calibration(uint8_t I2C_ADDRESS)
//{
//    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_SET_CO2_SENSOR_AUTOMATIC_SELF_CALIBRATION_MSB;
//    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_SET_CO2_SENSOR_AUTOMATIC_SELF_CALIBRATION_MSB;
//    DRV_I2C_WriteTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 5, &sen63c_driverData.I2C_TRANSFER_HANDLE);
//}

void SEN63C_DRIVER_Get_Ambient_Pressure(uint8_t I2C_ADDRESS)
{
    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_GET_AMBIENT_PRESSURE_MSB;
    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_GET_AMBIENT_PRESSURE_LSB;
    DRV_I2C_WriteReadTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 2, (void*) &sen63c_driverData.I2C_DATA_RECEIVE, 3, &sen63c_driverData.I2C_TRANSFER_HANDLE);
}

void SEN63C_DRIVER_Store_Ambient_Pressure(void)
{

}

//void SEN63C_DRIVER_Set_Ambient_Pressure(uint8_t I2C_ADDRESS)
//{
//    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_SET_AMBIENT_PRESSURE_MSB;
//    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_SET_AMBIENT_PRESSURE_LSB;
//    DRV_I2C_WriteTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 5, &sen63c_driverData.I2C_TRANSFER_HANDLE);
//}

void SEN63C_DRIVER_Get_Sensor_Altitude(uint8_t I2C_ADDRESS)
{
    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_GET_SENSOR_ALTITUDE_MSB;
    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_GET_SENSOR_ALTITUDE_LSB;
    DRV_I2C_WriteReadTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 2, (void*) &sen63c_driverData.I2C_DATA_RECEIVE, 3, &sen63c_driverData.I2C_TRANSFER_HANDLE);
}

void SEN63C_DRIVER_Store_Sensor_Altitude(void)
{

}

//void SEN63C_DRIVER_Set_Sensor_Altitude(uint8_t I2C_ADDRESS)
//{
//    sen63c_driverData.I2C_DATA_TRANSMIT[0] = SEN63C_CMD_SET_SENSOR_ALTITUDE_MSB;
//    sen63c_driverData.I2C_DATA_TRANSMIT[1] = SEN63C_CMD_SET_SENSOR_ALTITUDE_LSB;
//    DRV_I2C_WriteTransferAdd(sen63c_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &sen63c_driverData.I2C_DATA_TRANSMIT, 5, &sen63c_driverData.I2C_TRANSFER_HANDLE);
//}

uint8_t SEN63C_DRIVER_Calculation_CRC(uint8_t MESSAGE[], uint8_t NUMBER_OF_BYTES)
{
    uint8_t CRC = 0xFF;
    uint8_t BIT;

    for (uint8_t BYTE = 0; BYTE < NUMBER_OF_BYTES; BYTE++)
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

uint8_t SEN63C_DRIVER_Calculation_Array_CRC(uint8_t BYTE_0, uint8_t BYTE_1)
{
    uint8_t ARRAY[2] = {BYTE_0, BYTE_1};
    return SEN63C_DRIVER_Calculation_CRC(ARRAY, 2);
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void SEN63C_DRIVER_Initialize(void)
{
    sen63c_driverData.state = SEN63C_DRIVER_STATE_INIT;
    sen63c_driverData.I2C_HANDLE = DRV_HANDLE_INVALID;
    sen63c_driverData.I2C_TRANSFER_HANDLE = DRV_I2C_TRANSFER_HANDLE_INVALID;
}

void SEN63C_DRIVER_Tasks(void)
{
    switch (sen63c_driverData.state)
    {
        case SEN63C_DRIVER_STATE_INIT:
        {
            SEN63C_DRIVER_Set_I2C_Address();
            sen63c_driverData.I2C_HANDLE = DRV_I2C_Open(DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE);
            sen63c_driverData.state = SEN63C_DRIVER_STATE_CHECK_I2C_HANDLER;
            break;
        }

        case SEN63C_DRIVER_STATE_CHECK_I2C_HANDLER:
        {
            if (sen63c_driverData.I2C_HANDLE == DRV_HANDLE_INVALID)
            {
                sen63c_driverData.state = SEN63C_DRIVER_STATE_ERROR;
            }
            else
            {
                sen63c_driverData.state = SEN63C_DRIVER_STATE_IDLE;
            }
            break;
        }

        case SEN63C_DRIVER_STATE_IDLE:
        {
            if (SEN63C_DRIVER_Get_Task_Start_Status() == true)
            {
                sen63c_driverData.state = SEN63C_DRIVER_STATE_IDLE;
            }
            break;
        }

        case SEN63C_DRIVER_STATE_TIMER_EXPIRED:
        {
            DRV_I2C_Close(sen63c_driverData.I2C_HANDLE);
            SEN63C_DRIVER_Set_Task_Completed_Status(true);
            sen63c_driverData.state = MCP9808_DRIVER_STATE_IDLE;
            break;
        }

        case SEN63C_DRIVER_STATE_ERROR:
        {
            DRV_I2C_Close(sen63c_driverData.I2C_HANDLE);
            SEN63C_DRIVER_Set_Task_Completed_Status(true);
            sen63c_driverData.state = MCP9808_DRIVER_STATE_IDLE;
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