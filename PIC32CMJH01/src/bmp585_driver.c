/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    bmp585_driver.c

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

#include "bmp585_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************

BMP585_DRIVER_DATA bmp585_driverData;

BMP585_SENSOR_DATA bmp585_sensorData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void BMP585_DRIVER_Alert(uintptr_t CONTEXT)
{
    BMP585_DRIVER_Set_Alert_Status(true);
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

bool BMP585_DRIVER_Get_Task_Start_Status(void)
{
    return (bmp585_driverData.BMP585_TASK_START);
}

void BMP585_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    bmp585_driverData.BMP585_TASK_START = STATUS;
}

bool BMP585_DRIVER_Get_Task_Completed_Status(void)
{
    return (bmp585_driverData.BMP585_TASK_COMPLETED);
}

void BMP585_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    bmp585_driverData.BMP585_TASK_COMPLETED = STATUS;
}

bool BMP585_DRIVER_Get_Alert_Status(void)
{
    return (bmp585_driverData.BMP585_ALERT);
}

void BMP585_DRIVER_Set_Alert_Status(bool STATUS)
{
    bmp585_driverData.BMP585_ALERT = STATUS;
}

void BMP585_DRIVER_Set_I2C_Address(void)
{
    bmp585_driverData.I2C_ADDRESS[0] = 0x46;
    bmp585_driverData.I2C_ADDRESS[1] = 0x47;
}

void BMP585_DRIVER_Get_Chip_ID(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_CHIP_ID;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_Chip_ID(void)
{
    bmp585_sensorData.CHIP_ID = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Get_Revision_ID(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_REV_ID;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_Revision_ID(void)
{
    bmp585_sensorData.CHIP_REVISION = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Get_Chip_Status(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_CHIP_STATUS;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_Chip_Status(void)
{
    bmp585_sensorData.CHIP_STATUS = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Get_Drive_Config(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_DRIVE_CONFIG;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_Drive_Config(void)
{
    bmp585_sensorData.DRIVE_CFG = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Set_Drive_Config(uint8_t I2C_ADDRESS, uint8_t CONFIG)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_DRIVE_CONFIG;
    bmp585_driverData.I2C_DATA_TRANSMIT[1] = CONFIG;
    DRV_I2C_WriteTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 2, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Get_INT_Config(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_INT_CONFIG;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_INT_Config(void)
{
    bmp585_sensorData.INT_CFG = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Set_INT_Config(uint8_t I2C_ADDRESS, uint8_t CONFIG)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_INT_CONFIG;
    bmp585_driverData.I2C_DATA_TRANSMIT[1] = CONFIG;
    DRV_I2C_WriteTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 2, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Get_INT_Source(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_INT_SOURCE;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_INT_Source(void)
{
    bmp585_sensorData.INT_SOURCE = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Set_INT_Source(uint8_t I2C_ADDRESS, uint8_t SOURCE)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_INT_SOURCE;
    bmp585_driverData.I2C_DATA_TRANSMIT[1] = SOURCE;
    DRV_I2C_WriteTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 2, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Get_FIFO_Config(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_FIFO_CONFIG;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_FIFO_Config(void)
{
    bmp585_sensorData.FIFO_CFG = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Set_FIFO_Config(uint8_t I2C_ADDRESS, uint8_t CONFIG)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_FIFO_CONFIG;
    bmp585_driverData.I2C_DATA_TRANSMIT[1] = CONFIG;
    DRV_I2C_WriteTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 2, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Get_FIFO_Count(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_FIFO_COUNT;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_FIFO_Count(void)
{
    bmp585_sensorData.FIFO_COUNT = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Get_FIFO_Select(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_FIFO_SEL;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_FIFO_Select(void)
{
    bmp585_sensorData.FIFO_SELECT = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Set_FIFO_Select(uint8_t I2C_ADDRESS, uint8_t SELECT)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_FIFO_SEL;
    bmp585_driverData.I2C_DATA_TRANSMIT[1] = SELECT;
    DRV_I2C_WriteTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 2, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Get_Measured_Values(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_TEMP_DATA_XLSB;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 6, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_Measured_Values(void)
{
    bmp585_sensorData.T_VALUE_XLSB = bmp585_driverData.I2C_DATA_RECEIVE[0];
    bmp585_sensorData.T_VALUE_LSB = bmp585_driverData.I2C_DATA_RECEIVE[1];
    bmp585_sensorData.T_VALUE_MSB = bmp585_driverData.I2C_DATA_RECEIVE[2];
    bmp585_sensorData.P_VALUE_XLSB = bmp585_driverData.I2C_DATA_RECEIVE[3];
    bmp585_sensorData.P_VALUE_LSB = bmp585_driverData.I2C_DATA_RECEIVE[4];
    bmp585_sensorData.P_VALUE_MSB = bmp585_driverData.I2C_DATA_RECEIVE[5];
}

void BMP585_DRIVER_Get_INT_Status(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_INT_STATUS;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_INT_Status(void)
{
    bmp585_sensorData.INT_STATUS = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Get_Status(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_STATUS;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_Status(void)
{
    bmp585_sensorData.STATUS = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Get_FIFO_Data(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_FIFO_DATA;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_FIFO_Data(void)
{
    bmp585_sensorData.FIFO_DATA = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Get_NVM_Address(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_NVM_ADDR;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_NVM_Address(void)
{
    bmp585_sensorData.NVM_ADDRESS = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Set_NVM_Address(uint8_t I2C_ADDRESS, uint8_t ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_NVM_ADDR;
    bmp585_driverData.I2C_DATA_TRANSMIT[1] = ADDRESS;
    DRV_I2C_WriteTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 2, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Get_NVM_Data_LSB(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_NVM_DATA_LSB;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_NVM_Data_LSB(void)
{
    bmp585_sensorData.NVM_DATA_LSB = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Set_NVM_Data_LSB(uint8_t I2C_ADDRESS, uint8_t DATA)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_NVM_DATA_LSB;
    bmp585_driverData.I2C_DATA_TRANSMIT[1] = DATA;
    DRV_I2C_WriteTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 2, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Get_NVM_Data_MSB(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_NVM_DATA_MSB;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_NVM_Data_MSB(void)
{
    bmp585_sensorData.NVM_DATA_MSB = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Set_NVM_Data_MSB(uint8_t I2C_ADDRESS, uint8_t DATA)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_NVM_DATA_MSB;
    bmp585_driverData.I2C_DATA_TRANSMIT[1] = DATA;
    DRV_I2C_WriteTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 2, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Get_DSP_Config(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_DSP_CONFIG;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_DSP_Config(void)
{
    bmp585_sensorData.DSP_CFG = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Set_DSP_Config(uint8_t I2C_ADDRESS, uint8_t CONFIG)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_DSP_CONFIG;
    bmp585_driverData.I2C_DATA_TRANSMIT[1] = CONFIG;
    DRV_I2C_WriteTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 2, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Get_DSP_IIR(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_DSP_IIR;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_DSP_IIR(void)
{
    bmp585_sensorData.DSP_IIR = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Set_DSP_IIR(uint8_t I2C_ADDRESS, uint8_t IIR)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_DSP_IIR;
    bmp585_driverData.I2C_DATA_TRANSMIT[1] = IIR;
    DRV_I2C_WriteTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 2, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Get_OOR_P_LSB(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_OOR_THR_P_LSB;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_OOR_P_LSB(void)
{
    bmp585_sensorData.OOR_THR_P_LSB = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Set_OOR_P_LSB(uint8_t I2C_ADDRESS, uint8_t OOR)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_OOR_THR_P_LSB;
    bmp585_driverData.I2C_DATA_TRANSMIT[1] = OOR;
    DRV_I2C_WriteTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 2, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Get_OOR_P_MSB(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_OOR_THR_P_MSB;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_OOR_P_MSB(void)
{
    bmp585_sensorData.OOR_THR_P_MSB = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Set_OOR_P_MSB(uint8_t I2C_ADDRESS, uint8_t OOR)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_OOR_THR_P_MSB;
    bmp585_driverData.I2C_DATA_TRANSMIT[1] = OOR;
    DRV_I2C_WriteTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 2, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Get_OOR_Range(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_OOR_RANGE;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_OOR_Range(void)
{
    bmp585_sensorData.OOR_RANGE = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Set_OOR_Range(uint8_t I2C_ADDRESS, uint8_t RANGE)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_OOR_RANGE;
    bmp585_driverData.I2C_DATA_TRANSMIT[1] = RANGE;
    DRV_I2C_WriteTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 2, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Get_OOR_Config(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_OOR_CONFIG;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_OOR_Config(void)
{
    bmp585_sensorData.OOR_CFG = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Set_OOR_Config(uint8_t I2C_ADDRESS, uint8_t CONFIG)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_OOR_CONFIG;
    bmp585_driverData.I2C_DATA_TRANSMIT[1] = CONFIG;
    DRV_I2C_WriteTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 2, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Get_OSR_Config(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_OSR_CONFIG;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_OSR_Config(void)
{
    bmp585_sensorData.OSB_CFG = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Set_OSR_Config(uint8_t I2C_ADDRESS, uint8_t CONFIG)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_OSR_CONFIG;
    bmp585_driverData.I2C_DATA_TRANSMIT[1] = CONFIG;
    DRV_I2C_WriteTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 2, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Get_ODR_Config(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_ODR_CONFIG;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_ODR_Config(void)
{
    bmp585_sensorData.ODR_CFG = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Set_ODR_Config(uint8_t I2C_ADDRESS, uint8_t CONFIG)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_ODR_CONFIG;
    bmp585_driverData.I2C_DATA_TRANSMIT[1] = CONFIG;
    DRV_I2C_WriteTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 2, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Get_OSR_Eff(uint8_t I2C_ADDRESS)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_OSR_EFF;
    DRV_I2C_WriteReadTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 1, (void*) &bmp585_driverData.I2C_DATA_RECEIVE, 1, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Store_OSR_Eff(void)
{
    bmp585_sensorData.OSR_EFF = bmp585_driverData.I2C_DATA_RECEIVE[0];
}

void BMP585_DRIVER_Set_OSR_Eff(uint8_t I2C_ADDRESS, uint8_t EFF)
{
    bmp585_driverData.I2C_DATA_TRANSMIT[0] = BMP585_CMD_OSR_EFF;
    bmp585_driverData.I2C_DATA_TRANSMIT[1] = EFF;
    DRV_I2C_WriteTransferAdd(bmp585_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &bmp585_driverData.I2C_DATA_TRANSMIT, 2, &bmp585_driverData.I2C_TRANSFER_HANDLE);
}

void BMP585_DRIVER_Calculate_Temperature(void)
{
    bmp585_sensorData.T_VALUE = (int32_t) bmp585_sensorData.T_VALUE_MSB << 16 | (int32_t) bmp585_sensorData.T_VALUE_LSB << 8 | (int32_t) bmp585_sensorData.T_VALUE_XLSB;
    bmp585_sensorData.CELSIUS_TEMPERATURE = ((float) bmp585_sensorData.T_VALUE) / 65536;
}

void BMP585_DRIVER_Calculate_Pressure(void)
{
    bmp585_sensorData.P_VALUE = (uint32_t) bmp585_sensorData.P_VALUE_MSB << 16 | (uint32_t) bmp585_sensorData.P_VALUE_LSB << 8 | (uint32_t) bmp585_sensorData.P_VALUE_XLSB;
    bmp585_sensorData.PA_PRESSURE = ((float) bmp585_sensorData.P_VALUE) / 64;
}

void BMP585_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)
{
    SYS_CONSOLE_Print
            (
             CONSOLE_HANDLE,
             "Temperature: %.2f °C\r\n"
             "Pressure: %.2f Pa\r\n",
             bmp585_sensorData.CELSIUS_TEMPERATURE,
             bmp585_sensorData.PA_PRESSURE
             );
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void BMP585_DRIVER_Initialize(void)
{
    bmp585_driverData.state = BMP585_DRIVER_STATE_INIT;
    bmp585_driverData.I2C_HANDLE = DRV_HANDLE_INVALID;
    bmp585_driverData.I2C_TRANSFER_HANDLE = DRV_I2C_TRANSFER_HANDLE_INVALID;
    EIC_CallbackRegister(EIC_PIN_0, BMP585_DRIVER_Alert, 0);
}

void BMP585_DRIVER_Tasks(void)
{
    switch (bmp585_driverData.state)
    {
        case BMP585_DRIVER_STATE_INIT:
        {
            BMP585_DRIVER_Set_I2C_Address();
            bmp585_driverData.I2C_HANDLE = DRV_I2C_Open(DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE);
            bmp585_driverData.state = BMP585_DRIVER_STATE_CHECK_I2C_HANDLER;
            break;
        }

        case BMP585_DRIVER_STATE_CHECK_I2C_HANDLER:
        {
            if (bmp585_driverData.I2C_HANDLE == DRV_HANDLE_INVALID)
            {
                bmp585_driverData.state = BMP585_DRIVER_STATE_ERROR;
            }
            else
            {
                bmp585_driverData.state = BMP585_DRIVER_STATE_GET_CHIP_ID;
            }
            break;
        }

        case BMP585_DRIVER_STATE_GET_CHIP_ID:
        {
            BMP585_DRIVER_Get_Chip_ID(bmp585_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bmp585_driverData.state = BMP585_DRIVER_STATE_GET_CHIP_ID_WAIT_FOR_TRANSFER;
            break;
        }

        case BMP585_DRIVER_STATE_GET_CHIP_ID_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bmp585_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bmp585_driverData.state = BMP585_DRIVER_STATE_STORE_CHIP_ID;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bmp585_driverData.state = BMP585_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case BMP585_DRIVER_STATE_STORE_CHIP_ID:
        {
            BMP585_DRIVER_Store_Chip_ID();
            bmp585_driverData.state = BMP585_DRIVER_STATE_GET_REVISION_ID;
            break;
        }

        case BMP585_DRIVER_STATE_GET_REVISION_ID:
        {
            BMP585_DRIVER_Get_Revision_ID(bmp585_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bmp585_driverData.state = BMP585_DRIVER_STATE_GET_REVISION_ID_WAIT_FOR_TRANSFER;
            break;
        }

        case BMP585_DRIVER_STATE_GET_REVISION_ID_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bmp585_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bmp585_driverData.state = BMP585_DRIVER_STATE_STORE_REVISION_ID;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bmp585_driverData.state = BMP585_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case BMP585_DRIVER_STATE_STORE_REVISION_ID:
        {
            BMP585_DRIVER_Store_Revision_ID();
            bmp585_driverData.state = BMP585_DRIVER_STATE_SET_INT_SOURCE;
            break;
        }

        case BMP585_DRIVER_STATE_SET_INT_SOURCE:
        {
            BMP585_DRIVER_Set_INT_Source(bmp585_driverData.I2C_ADDRESS[0], 0b00000001);
            TIMER_DRIVER_Start_Bus_TMR();
            bmp585_driverData.state = BMP585_DRIVER_STATE_SET_INT_SOURCE_WAIT_FOR_TRANSFER;
            break;
        }

        case BMP585_DRIVER_STATE_SET_INT_SOURCE_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bmp585_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bmp585_driverData.state = BMP585_DRIVER_STATE_SET_OSR_CFG;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bmp585_driverData.state = BMP585_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case BMP585_DRIVER_STATE_SET_OSR_CFG:
        {
            BMP585_DRIVER_Set_OSR_Config(bmp585_driverData.I2C_ADDRESS[0], 0b01000000);
            TIMER_DRIVER_Start_Bus_TMR();
            bmp585_driverData.state = BMP585_DRIVER_STATE_SET_OSR_CFG_WAIT_FOR_TRANSFER;
            break;
        }

        case BMP585_DRIVER_STATE_SET_OSR_CFG_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bmp585_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bmp585_driverData.state = BMP585_DRIVER_STATE_IDLE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bmp585_driverData.state = BMP585_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case BMP585_DRIVER_STATE_IDLE:
        {
            if (BMP585_DRIVER_Get_Task_Start_Status() == true)
            {
                bmp585_driverData.state = BMP585_DRIVER_STATE_START_MEASUREMENT;
            }
            break;
        }

        case BMP585_DRIVER_STATE_START_MEASUREMENT:
        {
            BMP585_DRIVER_Set_ODR_Config(bmp585_driverData.I2C_ADDRESS[0], 0b00000010);
            TIMER_DRIVER_Start_Bus_TMR();
            bmp585_driverData.state = BMP585_DRIVER_STATE_START_MEASUREMENT_WAIT_FOR_TRANSFER;
            break;
        }

        case BMP585_DRIVER_STATE_START_MEASUREMENT_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bmp585_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bmp585_driverData.state = BMP585_DRIVER_STATE_GET_INT_STATUS;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bmp585_driverData.state = BMP585_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case BMP585_DRIVER_STATE_GET_INT_STATUS:
        {
            BMP585_DRIVER_Get_INT_Status(bmp585_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bmp585_driverData.state = BMP585_DRIVER_STATE_GET_INT_STATUS_WAIT_FOR_TRANSFER;
            break;
        }

        case BMP585_DRIVER_STATE_GET_INT_STATUS_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bmp585_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bmp585_driverData.state = BMP585_DRIVER_STATE_STORE_INT_STATUS;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bmp585_driverData.state = BMP585_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case BMP585_DRIVER_STATE_STORE_INT_STATUS:
        {
            BMP585_DRIVER_Store_INT_Status();
            bmp585_driverData.state = BMP585_DRIVER_STATE_CHECK_INT_STATUS;
            break;
        }

        case BMP585_DRIVER_STATE_CHECK_INT_STATUS:
        {
            if (bmp585_sensorData.INT_STATUS == 1)
            {
                bmp585_driverData.state = BMP585_DRIVER_STATE_GET_MEASURED_VALUES;
            }
            else
            {
                bmp585_driverData.state = BMP585_DRIVER_STATE_GET_INT_STATUS;
            }
            break;
        }

        case BMP585_DRIVER_STATE_GET_MEASURED_VALUES:
        {
            BMP585_DRIVER_Get_Measured_Values(bmp585_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            bmp585_driverData.state = BMP585_DRIVER_STATE_GET_MEASURED_VALUES_WAIT_FOR_TRANSFER;
            break;
        }

        case BMP585_DRIVER_STATE_GET_MEASURED_VALUES_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(bmp585_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                bmp585_driverData.state = BMP585_DRIVER_STATE_STORE_MEASURED_VALUES;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                bmp585_driverData.state = BMP585_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case BMP585_DRIVER_STATE_STORE_MEASURED_VALUES:
        {
            BMP585_DRIVER_Store_Measured_Values();
            bmp585_driverData.state = BMP585_DRIVER_STATE_CALCULATE_DATA;
            break;
        }

        case BMP585_DRIVER_STATE_CALCULATE_DATA:
        {
            BMP585_DRIVER_Calculate_Temperature();
            BMP585_DRIVER_Calculate_Pressure();
            bmp585_driverData.state = BMP585_DRIVER_STATE_STORE_DATA;
            break;
        }

        case BMP585_DRIVER_STATE_STORE_DATA:
        {
            /* Add function for storing temperature */
            BMP585_DRIVER_Set_Task_Completed_Status(true);
            bmp585_driverData.state = BMP585_DRIVER_STATE_IDLE;
            break;
        }

        case BMP585_DRIVER_STATE_TIMER_EXPIRED:
        {
            DRV_I2C_Close(bmp585_driverData.I2C_HANDLE);
            BMP585_DRIVER_Set_Task_Completed_Status(true);
            bmp585_driverData.state = BMP585_DRIVER_STATE_IDLE;
            break;
        }

        case BMP585_DRIVER_STATE_ERROR:
        {
            DRV_I2C_Close(bmp585_driverData.I2C_HANDLE);
            BMP585_DRIVER_Set_Task_Completed_Status(true);
            bmp585_driverData.state = BMP585_DRIVER_STATE_IDLE;
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