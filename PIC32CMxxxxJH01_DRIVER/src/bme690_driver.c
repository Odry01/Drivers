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

BME690_DRIVER_CAL_DATA bme690_calData;

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

void BME690_DRIVER_Get_VARIANT_ID_Data(void)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_VARIANT_ID_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_VARIANT_ID_Data(void)
{
    bme690_sensorData.VARIANT_ID = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_CHIP_ID_Data(void)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CHIP_ID_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_CHIP_ID_Data(void)
{
    bme690_sensorData.CHIP_ID = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Set_CONFIG_Data(uint8_t DATA)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CONFIG_REGISTER;
    bme690_driverData.I2C_DATA_TRANSMIT[1] = DATA;
    DRV_I2C_WriteTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 2, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Get_CONFIG_Data(void)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CONFIG_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_CONFIG_Data(void)
{
    bme690_sensorData.CONFIG = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Set_CTRL_MEAS_Data(uint8_t DATA)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CTRL_MEAS_REGISTER;
    bme690_driverData.I2C_DATA_TRANSMIT[1] = DATA;
    DRV_I2C_WriteTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 2, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Get_CTRL_MEAS_Data(void)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CTRL_MEAS_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_CTRL_MEAS_Data(void)
{
    bme690_sensorData.CTRL_MEAS = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Set_CTRL_HUM_Data(uint8_t DATA)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CTRL_HUM_REGISTER;
    bme690_driverData.I2C_DATA_TRANSMIT[1] = DATA;
    DRV_I2C_WriteTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 2, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Get_CTRL_HUM_Data(void)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CTRL_HUM_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_CTRL_HUM_Data(void)
{
    bme690_sensorData.CTRL_HUM = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Set_CTRL_GAS_1_Data(uint8_t DATA)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CTRL_GAS_1_REGISTER;
    bme690_driverData.I2C_DATA_TRANSMIT[1] = DATA;
    DRV_I2C_WriteTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 2, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Get_CTRL_GAS_1_Data(void)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CTRL_GAS_1_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_CTRL_GAS_1_Data(void)
{
    bme690_sensorData.CTRL_GAS_1 = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Set_CTRL_GAS_0_Data(uint8_t DATA)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CTRL_GAS_0_REGISTER;
    bme690_driverData.I2C_DATA_TRANSMIT[1] = DATA;
    DRV_I2C_WriteTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 2, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Get_CTRL_GAS_0_Data(void)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = BME690_CMD_CTRL_GAS_0_REGISTER;
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_CTRL_GAS_0_Data(void)
{
    bme690_sensorData.CTRL_GAS_0 = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_T_MSB_Data(uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.T_MSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_T_MSB_Data(uint8_t BUFFER)
{
    bme690_sensorData.T_VALUE_MSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_T_LSB_Data(uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.T_LSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_T_LSB_Data(uint8_t BUFFER)
{
    bme690_sensorData.T_VALUE_LSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_T_XLSB_Data(uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.T_XLSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_T_XLSB_Data(uint8_t BUFFER)
{
    bme690_sensorData.T_VALUE_XLSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_H_MSB_Data(uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.H_MSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_H_MSB_Data(uint8_t BUFFER)
{
    bme690_sensorData.H_VALUE_MSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_H_LSB_Data(uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.H_LSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_H_LSB_Data(uint8_t BUFFER)
{
    bme690_sensorData.H_VALUE_LSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_G_MSB_Data(uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.G_MSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_G_MSB_Data(uint8_t BUFFER)
{
    bme690_sensorData.G_VALUE_MSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_G_LSB_Data(uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.G_LSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_G_LSB_Data(uint8_t BUFFER)
{
    bme690_sensorData.G_VALUE_LSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_P_MSB_Data(uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.P_MSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_P_MSB_Data(uint8_t BUFFER)
{
    bme690_sensorData.P_VALUE_MSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_P_LSB_Data(uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.P_LSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_P_LSB_Data(uint8_t BUFFER)
{
    bme690_sensorData.P_VALUE_LSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_P_XLSB_Data(uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.P_XLSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_P_XLSB_Data(uint8_t BUFFER)
{
    bme690_sensorData.P_VALUE_XLSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_SUB_MEAS_INDEX_Data(uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.P_XLSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_SUB_MEAS_INDEX_Data(uint8_t BUFFER)
{
    bme690_sensorData.P_VALUE_XLSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

void BME690_DRIVER_Get_MEAS_STATUS_Data(uint8_t BUFFER)
{
    bme690_driverData.I2C_DATA_TRANSMIT[0] = bme690_regData.P_XLSB_REGISTER[BUFFER];
    DRV_I2C_WriteReadTransferAdd(bme690_driverData.I2C_HANDLE, BME690_I2C_ADDRESS, &bme690_driverData.I2C_DATA_TRANSMIT, 1, bme690_driverData.I2C_DATA_RECEIVE, 1, &bme690_driverData.I2C_TRANSFER_HANDLE);
}

void BME690_DRIVER_Store_MEAS_STATUS_Data(uint8_t BUFFER)
{
    bme690_sensorData.P_VALUE_XLSB[BUFFER] = bme690_driverData.I2C_DATA_RECEIVE[0];
}

/*Check calibration registers*/
void BME690_DRIVER_Get_PAR_T1_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_T1_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_T1_CAL_MSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_T1_CAL_MSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_T2_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_T2_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_T2_CAL_MSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_T2_CAL_MSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_T3_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_T3_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_H1_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_H1_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_H1_CAL_MSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_H1_CAL_MSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_H2_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_H2_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_H3_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_H3_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_H4_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_H4_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_H5_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_H5_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_H5_CAL_MSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_H5_CAL_MSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_H6_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_H6_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_P1_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_P1_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_P1_CAL_MSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_P1_CAL_MSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_P2_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_P2_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_P2_CAL_MSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_P2_CAL_MSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_P3_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_P3_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_P4_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_P4_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_P5_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_P5_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_P5_CAL_MSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_P5_CAL_MSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_P6_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_P6_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_P6_CAL_MSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_P6_CAL_MSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_P7_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_P7_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_P8_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_P8_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_P9_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_P9_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_P9_CAL_MSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_P9_CAL_MSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_P10_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_P10_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_P11_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_P11_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_G1_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_G1_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_G2_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_G2_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_G2_CAL_MSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_G2_CAL_MSB_Data(void)
{

}

void BME690_DRIVER_Get_PAR_G3_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Store_PAR_G3_CAL_LSB_Data(void)
{

}

void BME690_DRIVER_Set_Calibration_Registers(void)
{
    
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

void BME690_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)
{
    SYS_CONSOLE_Print
            (
             CONSOLE_HANDLE,
             "Temperature: %.2f Â°C\r\n"
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
//            BME690_DRIVER_Set_Register_Data();
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