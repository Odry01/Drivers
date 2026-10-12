/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    bme690_driver.c

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

#include "bme690_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************

BME690_DRIVER_DATA bme690_driverData;

BME690_DRIVER_REGISTER_DATA bme690_regData;

BME690_DRIVER_SENSOR_DATA bme690_sensorData;

BME690_DRIVER_CALIBRATION_DATA bme690_calibrationData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

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

void BME690_DRIVER_Set_I2C_Address(void)
{
    bme690_driverData.I2C_ADDRESS[0] = 0x44;
}

void BME690_DRIVER_Get_VARIANT_ID_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_VARIANT_ID_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_VARIANT_ID_Value(void)
{
    bme690_sensorData.VARIANT_ID = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_CHIP_ID_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CHIP_ID_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_CHIP_ID_Value(void)
{
    bme690_sensorData.CHIP_ID = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Set_CONFIG_Value(uint8_t I2C_ADDRESS, uint8_t DATA)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CONFIG_REGISTER;
    bme690_driverData.I2C_DATA_TRANSMIT[1] = DATA;
    DRV_I2C_WriteTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 2, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Get_CONFIG_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CONFIG_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_CONFIG_Value(void)
{
    bme690_sensorData.CONFIG = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Set_CTRL_MEAS_Value(uint8_t I2C_ADDRESS, uint8_t DATA)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CTRL_MEAS_REGISTER;
    bme690_driverData.I2C_DATA_TRANSMIT[1] = DATA;
    DRV_I2C_WriteTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 2, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Get_CTRL_MEAS_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CTRL_MEAS_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_CTRL_MEAS_Value(void)
{
    bme690_sensorData.CTRL_MEAS = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Set_CTRL_HUM_Value(uint8_t I2C_ADDRESS, uint8_t DATA)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CTRL_HUM_REGISTER;
    bme690_driverData.I2C_DATA_TRANSMIT[1] = DATA;
    DRV_I2C_WriteTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 2, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Get_CTRL_HUM_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CTRL_HUM_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_CTRL_HUM_Value(void)
{
    bme690_sensorData.CTRL_HUM = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Set_CTRL_GAS_1_Value(uint8_t I2C_ADDRESS, uint8_t DATA)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CTRL_GAS_1_REGISTER;
    bme690_driverData.I2C_DATA_TRANSMIT[1] = DATA;
    DRV_I2C_WriteTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 2, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Get_CTRL_GAS_1_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CTRL_GAS_1_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_CTRL_GAS_1_Value(void)
{
    bme690_sensorData.CTRL_GAS_1 = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Set_CTRL_GAS_0_Value(uint8_t I2C_ADDRESS, uint8_t DATA)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CTRL_GAS_0_REGISTER;
    bme690_driverData.I2C_DATA_TRANSMIT[1] = DATA;
    DRV_I2C_WriteTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 2, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Get_CTRL_GAS_0_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CTRL_GAS_0_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_CTRL_GAS_0_Value(void)
{
    bme690_sensorData.CTRL_GAS_0 = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_T_MSB_Value(uint8_t I2C_ADDRESS, uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.T_MSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_T_MSB_Value(uint8_t BUFFER)
{
    bme690_sensorData.T_VALUE_MSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_T_LSB_Value(uint8_t I2C_ADDRESS, uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.T_LSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_T_LSB_Value(uint8_t BUFFER)
{
    bme690_sensorData.T_VALUE_LSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_T_XLSB_Value(uint8_t I2C_ADDRESS, uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.T_XLSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_T_XLSB_Value(uint8_t BUFFER)
{
    bme690_sensorData.T_VALUE_XLSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_H_MSB_Value(uint8_t I2C_ADDRESS, uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.H_MSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_H_MSB_Value(uint8_t BUFFER)
{
    bme690_sensorData.H_VALUE_MSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_H_LSB_Value(uint8_t I2C_ADDRESS, uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.H_LSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_H_LSB_Value(uint8_t BUFFER)
{
    bme690_sensorData.H_VALUE_LSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_G_MSB_Value(uint8_t I2C_ADDRESS, uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.G_MSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_G_MSB_Value(uint8_t BUFFER)
{
    bme690_sensorData.G_VALUE_MSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_G_LSB_Value(uint8_t I2C_ADDRESS, uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.G_LSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_G_LSB_Value(uint8_t BUFFER)
{
    bme690_sensorData.G_VALUE_LSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_P_MSB_Value(uint8_t I2C_ADDRESS, uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.P_MSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_P_MSB_Value(uint8_t BUFFER)
{
    bme690_sensorData.P_VALUE_MSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_P_LSB_Value(uint8_t I2C_ADDRESS, uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.P_LSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_P_LSB_Value(uint8_t BUFFER)
{
    bme690_sensorData.P_VALUE_LSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_P_XLSB_Value(uint8_t I2C_ADDRESS, uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.P_XLSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_P_XLSB_Value(uint8_t BUFFER)
{
    bme690_sensorData.P_VALUE_XLSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_SUB_MEAS_INDEX_Value(uint8_t I2C_ADDRESS, uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.P_XLSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_SUB_MEAS_INDEX_Value(uint8_t BUFFER)
{
    bme690_sensorData.P_VALUE_XLSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_MEAS_STATUS_Value(uint8_t I2C_ADDRESS, uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.P_XLSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_MEAS_STATUS_Value(uint8_t BUFFER)
{
    bme690_sensorData.P_VALUE_XLSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_T1_LSB_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_T1_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_T1_LSB_Value(void)
{
    bme690_calibrationData.PAR_T1_LSB = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_T1_MSB_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_T1_CALIBRATION_MSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_T1_MSB_Value(void)
{
    bme690_calibrationData.PAR_T1_MSB = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_T2_LSB_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_T2_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_T2_LSB_Value(void)
{
    bme690_calibrationData.PAR_T2_LSB = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_T2_MSB_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_T2_CALIBRATION_MSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_T2_MSB_Value(void)
{
    bme690_calibrationData.PAR_T2_MSB = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_T3_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_T3_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_T3_Value(void)
{
    bme690_calibrationData.PAR_T3 = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_H1_LSB_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_H1_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_H1_LSB_Value(void)
{
    bme690_calibrationData.PAR_H1_LSB = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_H1_MSB_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_H1_CALIBRATION_MSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_H1_MSB_Value(void)
{
    bme690_calibrationData.PAR_H1_MSB = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_H2_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_H2_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_H2_Value(void)
{
    bme690_calibrationData.PAR_H2 = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_H3_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_H3_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_H3_Value(void)
{
    bme690_calibrationData.PAR_H3 = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_H4_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_H4_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_H4_Value(void)
{
    bme690_calibrationData.PAR_H4 = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_H5_LSB_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_H5_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_H5_LSB_Value(void)
{
    bme690_calibrationData.PAR_H5_LSB = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_H5_MSB_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_H5_CALIBRATION_MSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_H5_MSB_Value(void)
{
    bme690_calibrationData.PAR_H5_MSB = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_H6_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_H6_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_H6_Value(void)
{
    bme690_calibrationData.PAR_H6 = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_P1_LSB_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_P1_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_P1_LSB_Value(void)
{
    bme690_calibrationData.PAR_P1_LSB = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_P1_MSB_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_P1_CALIBRATION_MSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_P1_MSB_Value(void)
{
    bme690_calibrationData.PAR_P1_MSB = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_P2_LSB_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_P2_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_P2_LSB_Value(void)
{
    bme690_calibrationData.PAR_P2_LSB = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_P2_MSB_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_P2_CALIBRATION_MSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_P2_MSB_Value(void)
{
    bme690_calibrationData.PAR_P2_MSB = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_P3_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_P3_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_P3_Value(void)
{
    bme690_calibrationData.PAR_P3 = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_P4_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_P4_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_P4_Value(void)
{
    bme690_calibrationData.PAR_P4 = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_P5_LSB_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_P5_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_P5_LSB_Value(void)
{
    bme690_calibrationData.PAR_P5_LSB = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_P5_MSB_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_P5_CALIBRATION_MSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_P5_MSB_Value(void)
{
    bme690_calibrationData.PAR_P5_MSB = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_P6_LSB_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_P6_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_P6_LSB_Value(void)
{
    bme690_calibrationData.PAR_P6_LSB = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_P6_MSB_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_P6_CALIBRATION_MSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_P6_MSB_Value(void)
{
    bme690_calibrationData.PAR_P6_MSB = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_P7_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_P7_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_P7_Value(void)
{
    bme690_calibrationData.PAR_P7 = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_P8_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_P8_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_P8_Value(void)
{
    bme690_calibrationData.PAR_P8 = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_P9_LSB_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_P9_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_P9_LSB_Value(void)
{
    bme690_calibrationData.PAR_P9_LSB = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_P9_MSB_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_P9_CALIBRATION_MSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_P9_MSB_Value(void)
{
    bme690_calibrationData.PAR_P9_MSB = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_P10_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_P10_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_P10_Value(void)
{
    bme690_calibrationData.PAR_P10 = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_P11_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_P11_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_P11_Value(void)
{
    bme690_calibrationData.PAR_P11 = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_G1_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_G1_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_G1_Value(void)
{
    bme690_calibrationData.PAR_G1 = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_G2_LSB_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_G2_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_G2_LSB_Value(void)
{
    bme690_calibrationData.PAR_G2_LSB = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_G2_MSB_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_G2_CALIBRATION_MSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_G2_MSB_Value(void)
{
    bme690_calibrationData.PAR_G2_MSB = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_PAR_G3_Value(uint8_t I2C_ADDRESS)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_PAR_G3_CALIBRATION_LSB_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, &bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_PAR_G3_Value(void)
{
    bme690_calibrationData.PAR_G3 = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Set_Calibration_Registers(void)
{
    bme690_calibrationData.PAR_T1 = (uint16_t) bme690_calibrationData.PAR_T1_MSB << 8 | (uint16_t) bme690_calibrationData.PAR_T1_LSB;
    bme690_calibrationData.PAR_T2 = (uint16_t) bme690_calibrationData.PAR_T2_MSB << 8 | (uint16_t) bme690_calibrationData.PAR_T2_LSB;
    bme690_calibrationData.PAR_H1 = (uint16_t) bme690_calibrationData.PAR_H1_MSB << 8 | (uint16_t) bme690_calibrationData.PAR_H1_LSB;
    bme690_calibrationData.PAR_H5 = (uint16_t) bme690_calibrationData.PAR_H5_MSB << 8 | (uint16_t) bme690_calibrationData.PAR_H5_LSB;
    bme690_calibrationData.PAR_P1 = (uint16_t) bme690_calibrationData.PAR_P1_MSB << 8 | (uint16_t) bme690_calibrationData.PAR_P1_LSB;
    bme690_calibrationData.PAR_P2 = (uint16_t) bme690_calibrationData.PAR_P2_MSB << 8 | (uint16_t) bme690_calibrationData.PAR_P2_LSB;
    bme690_calibrationData.PAR_P5 = (uint16_t) bme690_calibrationData.PAR_P5_MSB << 8 | (uint16_t) bme690_calibrationData.PAR_P5_LSB;
    bme690_calibrationData.PAR_P6 = (uint16_t) bme690_calibrationData.PAR_P6_MSB << 8 | (uint16_t) bme690_calibrationData.PAR_P6_LSB;
    bme690_calibrationData.PAR_P9 = (uint16_t) bme690_calibrationData.PAR_P9_MSB << 8 | (uint16_t) bme690_calibrationData.PAR_P9_LSB;
    bme690_calibrationData.PAR_G2 = (uint16_t) bme690_calibrationData.PAR_G2_MSB << 8 | (uint16_t) bme690_calibrationData.PAR_G2_LSB;
}

void BME690_DRIVER_Set_Measure_Registers(void)
{
    bme690_regData.T_MSB_REGISTER[0] = BME690_CMD_TEMP_MSB_0_REGISTER;
    bme690_regData.T_MSB_REGISTER[1] = BME690_CMD_TEMP_MSB_1_REGISTER;
    bme690_regData.T_MSB_REGISTER[2] = BME690_CMD_TEMP_MSB_2_REGISTER;
    bme690_regData.H_MSB_REGISTER[0] = BME690_CMD_HUM_MSB_0_REGISTER;
    bme690_regData.H_MSB_REGISTER[1] = BME690_CMD_HUM_MSB_1_REGISTER;
    bme690_regData.H_MSB_REGISTER[2] = BME690_CMD_HUM_MSB_2_REGISTER;
    bme690_regData.P_MSB_REGISTER[0] = BME690_CMD_PRESS_MSB_0_REGISTER;
    bme690_regData.P_MSB_REGISTER[1] = BME690_CMD_PRESS_MSB_1_REGISTER;
    bme690_regData.P_MSB_REGISTER[2] = BME690_CMD_PRESS_MSB_2_REGISTER;
    bme690_regData.G_MSB_REGISTER[0] = BME690_CMD_GAS_R_MSB_0_REGISTER;
    bme690_regData.G_MSB_REGISTER[1] = BME690_CMD_GAS_R_MSB_1_REGISTER;
    bme690_regData.G_MSB_REGISTER[2] = BME690_CMD_GAS_R_MSB_2_REGISTER;
    bme690_regData.T_LSB_REGISTER[0] = BME690_CMD_TEMP_LSB_0_REGISTER;
    bme690_regData.T_LSB_REGISTER[1] = BME690_CMD_TEMP_LSB_1_REGISTER;
    bme690_regData.T_LSB_REGISTER[2] = BME690_CMD_TEMP_LSB_2_REGISTER;
    bme690_regData.H_LSB_REGISTER[0] = BME690_CMD_HUM_LSB_0_REGISTER;
    bme690_regData.H_LSB_REGISTER[1] = BME690_CMD_HUM_LSB_1_REGISTER;
    bme690_regData.H_LSB_REGISTER[2] = BME690_CMD_HUM_LSB_2_REGISTER;
    bme690_regData.P_LSB_REGISTER[0] = BME690_CMD_PRESS_LSB_0_REGISTER;
    bme690_regData.P_LSB_REGISTER[1] = BME690_CMD_PRESS_LSB_1_REGISTER;
    bme690_regData.P_LSB_REGISTER[2] = BME690_CMD_PRESS_LSB_2_REGISTER;
    bme690_regData.G_LSB_REGISTER[0] = BME690_CMD_GAS_R_LSB_0_REGISTER;
    bme690_regData.G_LSB_REGISTER[1] = BME690_CMD_GAS_R_LSB_1_REGISTER;
    bme690_regData.G_LSB_REGISTER[2] = BME690_CMD_GAS_R_LSB_2_REGISTER;
    bme690_regData.T_XLSB_REGISTER[0] = BME690_CMD_TEMP_XLSB_0_REGISTER;
    bme690_regData.T_XLSB_REGISTER[1] = BME690_CMD_TEMP_XLSB_1_REGISTER;
    bme690_regData.T_XLSB_REGISTER[2] = BME690_CMD_TEMP_XLSB_2_REGISTER;
    bme690_regData.P_XLSB_REGISTER[0] = BME690_CMD_PRESS_XLSB_0_REGISTER;
    bme690_regData.P_XLSB_REGISTER[1] = BME690_CMD_PRESS_XLSB_1_REGISTER;
    bme690_regData.P_XLSB_REGISTER[2] = BME690_CMD_PRESS_XLSB_2_REGISTER;
    bme690_regData.SUB_MEAS_INDEX_REGISTER[0] = BME690_CMD_SUB_MEAS_INDEX_0_REGISTER;
    bme690_regData.SUB_MEAS_INDEX_REGISTER[1] = BME690_CMD_SUB_MEAS_INDEX_1_REGISTER;
    bme690_regData.SUB_MEAS_INDEX_REGISTER[2] = BME690_CMD_SUB_MEAS_INDEX_2_REGISTER;
    bme690_regData.MEAS_STATUS_REGISTER[0] = BME690_CMD_MEAS_STATUS_0_REGISTER;
    bme690_regData.MEAS_STATUS_REGISTER[1] = BME690_CMD_MEAS_STATUS_1_REGISTER;
    bme690_regData.MEAS_STATUS_REGISTER[2] = BME690_CMD_MEAS_STATUS_2_REGISTER;
}

void BME690_DRIVER_Calculate_Temperature(uint8_t BUFFER)
{
    bme690_sensorData.T_VALUE = 0;
}

void BME690_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)
{
    SYS_CONSOLE_Print
            (
             CONSOLE_HANDLE,
             "Temperature: %.2f °C\r\n"
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
    EIC_CallbackRegister(EIC_PIN_0, BME690_DRIVER_Alert, 0);
}

void BME690_DRIVER_Tasks(void)
{
    switch (bme690_driverData.state)
    {
        case BME690_DRIVER_STATE_INIT:
        {
            BME690_DRIVER_Set_I2C_Address();
            BME690_DRIVER_Set_Measure_Registers();
            bme690_driverData.I2C_HANDLE = DRV_I2C_Open(DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE);
            bme690_driverData.state = BME690_DRIVER_STATE_CHECK_I2C_HANDLER;
            break;
        }

        case BME690_DRIVER_STATE_CHECK_I2C_HANDLER:
        {
            if (bme690_driverData.I2C_HANDLE == DRV_HANDLE_INVALID)
            {
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else
            {
                bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_T1_LSB;
            }
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_T1_LSB:
        {
            BME690_DRIVER_Get_PAR_T1_LSB_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_T1_LSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_T1_LSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_T1_LSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_T1_LSB:
        {
            BME690_DRIVER_Store_PAR_T1_LSB_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_T1_MSB;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_T1_MSB:
        {
            BME690_DRIVER_Get_PAR_T1_MSB_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_T1_MSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_T1_MSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_T1_MSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_T1_MSB:
        {
            BME690_DRIVER_Store_PAR_T1_MSB_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_T2_LSB;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_T2_LSB:
        {
            BME690_DRIVER_Get_PAR_T2_LSB_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_T2_LSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_T2_LSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_T2_LSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_T2_LSB:
        {
            BME690_DRIVER_Store_PAR_T2_LSB_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_T2_MSB;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_T2_MSB:
        {
            BME690_DRIVER_Get_PAR_T2_MSB_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_T2_MSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_T2_MSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_T2_MSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_T2_MSB:
        {
            BME690_DRIVER_Store_PAR_T2_MSB_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_T3;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_T3:
        {
            BME690_DRIVER_Get_PAR_T3_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_T3_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_T3_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_T3;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_T3:
        {
            BME690_DRIVER_Store_PAR_T3_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_H1_LSB;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_H1_LSB:
        {
            BME690_DRIVER_Get_PAR_H1_LSB_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_H1_LSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_H1_LSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_H1_LSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_H1_LSB:
        {
            BME690_DRIVER_Store_PAR_H1_LSB_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_H1_MSB;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_H1_MSB:
        {
            BME690_DRIVER_Get_PAR_H1_MSB_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_H1_MSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_H1_MSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_H1_MSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_H1_MSB:
        {
            BME690_DRIVER_Store_PAR_H1_MSB_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_H2;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_H2:
        {
            BME690_DRIVER_Get_PAR_H2_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_H2_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_H2_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_H2;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_H2:
        {
            BME690_DRIVER_Store_PAR_H2_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_H3;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_H3:
        {
            BME690_DRIVER_Get_PAR_H3_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_H3_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_H3_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_H3;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_H3:
        {
            BME690_DRIVER_Store_PAR_H3_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_H4;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_H4:
        {
            BME690_DRIVER_Get_PAR_H4_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_H4_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_H4_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_H4;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_H4:
        {
            BME690_DRIVER_Store_PAR_H4_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_H5_LSB;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_H5_LSB:
        {
            BME690_DRIVER_Get_PAR_H5_LSB_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_H5_LSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_H5_LSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_H5_LSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_H5_LSB:
        {
            BME690_DRIVER_Store_PAR_H5_LSB_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_H5_MSB;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_H5_MSB:
        {
            BME690_DRIVER_Get_PAR_H5_MSB_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_H5_MSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_H5_MSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_H5_MSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_H5_MSB:
        {
            BME690_DRIVER_Store_PAR_H5_MSB_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_H6;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_H6:
        {
            BME690_DRIVER_Get_PAR_H6_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_H6_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_H6_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_H6;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_H6:
        {
            BME690_DRIVER_Store_PAR_H6_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P1_LSB;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_P1_LSB:
        {
            BME690_DRIVER_Get_PAR_P1_LSB_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P1_LSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_P1_LSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_P1_LSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_P1_LSB:
        {
            BME690_DRIVER_Store_PAR_P1_LSB_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P1_MSB;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_P1_MSB:
        {
            BME690_DRIVER_Get_PAR_P1_MSB_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P1_MSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_P1_MSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_P1_MSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_P1_MSB:
        {
            BME690_DRIVER_Store_PAR_P1_MSB_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P2_LSB;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_P2_LSB:
        {
            BME690_DRIVER_Get_PAR_P2_LSB_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P2_LSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_P2_LSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_P2_LSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_P2_LSB:
        {
            BME690_DRIVER_Store_PAR_P2_LSB_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P2_MSB;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_P2_MSB:
        {
            BME690_DRIVER_Get_PAR_P2_MSB_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P2_MSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_P2_MSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_P2_MSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_P2_MSB:
        {
            BME690_DRIVER_Store_PAR_P2_MSB_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P3;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_P3:
        {
            BME690_DRIVER_Get_PAR_P3_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P3_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_P3_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_P3;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_P3:
        {
            BME690_DRIVER_Store_PAR_P3_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P4;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_P4:
        {
            BME690_DRIVER_Get_PAR_P4_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P4_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_P4_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_P4;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_P4:
        {
            BME690_DRIVER_Store_PAR_P4_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P5_LSB;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_P5_LSB:
        {
            BME690_DRIVER_Get_PAR_P5_LSB_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P5_LSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_P5_LSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_P5_LSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_P5_LSB:
        {
            BME690_DRIVER_Store_PAR_P5_LSB_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P5_MSB;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_P5_MSB:
        {
            BME690_DRIVER_Get_PAR_P5_MSB_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P5_MSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_P5_MSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_P5_MSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_P5_MSB:
        {
            BME690_DRIVER_Store_PAR_P5_MSB_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P6_LSB;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_P6_LSB:
        {
            BME690_DRIVER_Get_PAR_P6_LSB_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P6_LSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_P6_LSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_P6_LSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_P6_LSB:
        {
            BME690_DRIVER_Store_PAR_P6_LSB_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P6_MSB;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_P6_MSB:
        {
            BME690_DRIVER_Get_PAR_P6_MSB_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P6_MSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_P6_MSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_P6_MSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_P6_MSB:
        {
            BME690_DRIVER_Store_PAR_P6_MSB_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P7;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_P7:
        {
            BME690_DRIVER_Get_PAR_P7_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P7_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_P7_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_P7;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_P7:
        {
            BME690_DRIVER_Store_PAR_P7_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P8;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_P8:
        {
            BME690_DRIVER_Get_PAR_P8_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P8_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_P8_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_P8;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_P8:
        {
            BME690_DRIVER_Store_PAR_P8_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P9_LSB;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_P9_LSB:
        {
            BME690_DRIVER_Get_PAR_P9_LSB_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P9_LSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_P9_LSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_P9_LSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_P9_LSB:
        {
            BME690_DRIVER_Store_PAR_P9_LSB_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P9_MSB;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_P9_MSB:
        {
            BME690_DRIVER_Get_PAR_P9_MSB_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P9_MSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_P9_MSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_P9_MSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_P9_MSB:
        {
            BME690_DRIVER_Store_PAR_P9_MSB_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P10;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_P10:
        {
            BME690_DRIVER_Get_PAR_P10_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P10_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_P10_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_P10;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_P10:
        {
            BME690_DRIVER_Store_PAR_P10_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P11;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_P11:
        {
            BME690_DRIVER_Get_PAR_P11_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_P11_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_P11_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_P11;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_P11:
        {
            BME690_DRIVER_Store_PAR_P11_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_G1_LSB;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_G1_LSB:
        {
            BME690_DRIVER_Get_PAR_G1_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_G1_LSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_G1_LSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_G1_LSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_G1_LSB:
        {
            BME690_DRIVER_Store_PAR_G1_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_G2_LSB;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_G2_LSB:
        {
            BME690_DRIVER_Get_PAR_G2_LSB_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_G2_LSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_G2_LSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_G2_LSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_G2_LSB:
        {
            BME690_DRIVER_Store_PAR_G2_LSB_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_G2_MSB;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_G2_MSB:
        {
            BME690_DRIVER_Get_PAR_G2_MSB_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_G2_MSB_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_G2_MSB_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_G2_MSB;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_G2_MSB:
        {
            BME690_DRIVER_Store_PAR_G2_MSB_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_G3;
            break;
        }

        case BME690_DRIVER_STATE_GET_PAR_G3:
        {
            BME690_DRIVER_Get_PAR_G3_Value(bme690_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bme690_driverData.state = BME690_DRIVER_STATE_GET_PAR_G3_WAIT_FOR_TRANSFER;
            break;
        }
        case BME690_DRIVER_STATE_GET_PAR_G3_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_STORE_PAR_G3;
            }
            else if (DRV_I2C_TransferStatusGet(bme690_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_ERROR)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bme690_driverData.state = BME690_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }
        case BME690_DRIVER_STATE_STORE_PAR_G3:
        {
            BME690_DRIVER_Store_PAR_G3_Value();
            bme690_driverData.state = BME690_DRIVER_STATE_SET_CALIBRATION_REGISTERS;
            break;
        }

        case BME690_DRIVER_STATE_SET_CALIBRATION_REGISTERS:
        {
            BME690_DRIVER_Set_Calibration_Registers();
            bme690_driverData.state = BME690_DRIVER_STATE_IDLE;
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
            APP_Set_I2C_Error_Status(true);
            BME690_DRIVER_Set_Task_Completed_Status(true);
            bme690_driverData.state = BME690_DRIVER_STATE_IDLE;
            break;
        }

        case BME690_DRIVER_STATE_ERROR:
        {
            DRV_I2C_Close(bme690_driverData.I2C_HANDLE);
            APP_Set_I2C_Error_Status(true);
            BME690_DRIVER_Set_Task_Completed_Status(true);
            bme690_driverData.state = BME690_DRIVER_STATE_IDLE;
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