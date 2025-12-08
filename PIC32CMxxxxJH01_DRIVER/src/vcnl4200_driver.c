/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    vcnl4200_driver.c
 
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

#include "vcnl4200_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

VCNL4200_DRIVER_DATA vcnl4200_driverData;

VCNL4200_SENSOR_DATA vcnl4200_sensorData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void VCNL4200_DRIVER_Alert(uintptr_t CONTEXT)
{
    VCNL4200_DRIVER_Set_Alert_Status(true);
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

bool VCNL4200_DRIVER_Get_Task_Start_Status(void)
{
    return (vcnl4200_driverData.VCNL4200_TASK_START);
}

void VCNL4200_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    vcnl4200_driverData.VCNL4200_TASK_START = STATUS;
}

bool VCNL4200_DRIVER_Get_Task_Completed_Status(void)
{
    return (vcnl4200_driverData.VCNL4200_TASK_COMPLETED);
}

void VCNL4200_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    vcnl4200_driverData.VCNL4200_TASK_COMPLETED = STATUS;
}

bool VCNL4200_DRIVER_Get_Alert_Status(void)
{
    return (vcnl4200_driverData.VCNL4200_ALERT);
}

void VCNL4200_DRIVER_Set_Alert_Status(bool STATUS)
{
    vcnl4200_driverData.VCNL4200_ALERT = STATUS;
}

void VCNL4200_DRIVER_Set_I2C_Address(void)
{
    vcnl4200_driverData.I2C_ADDRESS[0] = 0x51;
}

void VCNL4200_DRIVER_Get_ALS_CFG(uint8_t I2C_ADDRESS)
{
    vcnl4200_driverData.I2C_DATA_TRANSMIT[0] = VCNL4200_CMD_ALS_THDH;
    DRV_I2C_WriteReadTransferAdd(vcnl4200_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &vcnl4200_driverData.I2C_DATA_TRANSMIT, 1, (void*) &vcnl4200_driverData.I2C_DATA_RECEIVE, 2, &vcnl4200_driverData.I2C_TRANSFER_HANDLE);
}

void VCNL4200_DRIVER_Store_ALS_CFG(void)
{
    vcnl4200_sensorData.ALS_CFG = vcnl4200_driverData.I2C_DATA_RECEIVE[1] << 8 | vcnl4200_driverData.I2C_DATA_RECEIVE[0];
}

void VCNL4200_DRIVER_Set_ALS_CFG(uint8_t I2C_ADDRESS, uint8_t MSB_VALUE, uint8_t LSB_VALUE)
{
    vcnl4200_driverData.I2C_DATA_TRANSMIT[0] = VCNL4200_CMD_ALS_CFG;
    vcnl4200_driverData.I2C_DATA_TRANSMIT[1] = LSB_VALUE;
    vcnl4200_driverData.I2C_DATA_TRANSMIT[2] = MSB_VALUE;
    DRV_I2C_WriteTransferAdd(vcnl4200_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &vcnl4200_driverData.I2C_DATA_TRANSMIT, 3, &vcnl4200_driverData.I2C_TRANSFER_HANDLE);
}

void VCNL4200_DRIVER_Get_ALS_High_Alert(uint8_t I2C_ADDRESS)
{
    vcnl4200_driverData.I2C_DATA_TRANSMIT[0] = VCNL4200_CMD_ALS_THDH;
    DRV_I2C_WriteReadTransferAdd(vcnl4200_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &vcnl4200_driverData.I2C_DATA_TRANSMIT, 1, (void*) &vcnl4200_driverData.I2C_DATA_RECEIVE, 2, &vcnl4200_driverData.I2C_TRANSFER_HANDLE);
}

void VCNL4200_DRIVER_Store_ALS_High_Alert(void)
{
    vcnl4200_sensorData.ALS_THDH = vcnl4200_driverData.I2C_DATA_RECEIVE[1] << 8 | vcnl4200_driverData.I2C_DATA_RECEIVE[0];
}

void VCNL4200_DRIVER_Set_ALS_High_Alert(uint8_t I2C_ADDRESS, uint8_t MSB_VALUE, uint8_t LSB_VALUE)
{
    vcnl4200_driverData.I2C_DATA_TRANSMIT[0] = VCNL4200_CMD_ALS_THDH;
    vcnl4200_driverData.I2C_DATA_TRANSMIT[1] = LSB_VALUE;
    vcnl4200_driverData.I2C_DATA_TRANSMIT[2] = MSB_VALUE;
    DRV_I2C_WriteTransferAdd(vcnl4200_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &vcnl4200_driverData.I2C_DATA_TRANSMIT, 3, &vcnl4200_driverData.I2C_TRANSFER_HANDLE);
}

void VCNL4200_DRIVER_Get_ALS_Low_Alert(uint8_t I2C_ADDRESS)
{
    vcnl4200_driverData.I2C_DATA_TRANSMIT[0] = VCNL4200_CMD_ALS_THDL;
    DRV_I2C_WriteReadTransferAdd(vcnl4200_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &vcnl4200_driverData.I2C_DATA_TRANSMIT, 1, (void*) &vcnl4200_driverData.I2C_DATA_RECEIVE, 2, &vcnl4200_driverData.I2C_TRANSFER_HANDLE);
}

void VCNL4200_DRIVER_Store_ALS_Low_Alert(void)
{
    vcnl4200_sensorData.ALS_THDL = vcnl4200_driverData.I2C_DATA_RECEIVE[1] << 8 | vcnl4200_driverData.I2C_DATA_RECEIVE[0];
}

void VCNL4200_DRIVER_Set_ALS_Low_Alert(uint8_t I2C_ADDRESS, uint8_t MSB_VALUE, uint8_t LSB_VALUE)
{
    vcnl4200_driverData.I2C_DATA_TRANSMIT[0] = VCNL4200_CMD_ALS_THDL;
    vcnl4200_driverData.I2C_DATA_TRANSMIT[1] = LSB_VALUE;
    vcnl4200_driverData.I2C_DATA_TRANSMIT[2] = MSB_VALUE;
    DRV_I2C_WriteTransferAdd(vcnl4200_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &vcnl4200_driverData.I2C_DATA_TRANSMIT, 3, &vcnl4200_driverData.I2C_TRANSFER_HANDLE);
}

void VCNL4200_DRIVER_Get_PS_Cancellation(uint8_t I2C_ADDRESS)
{
    vcnl4200_driverData.I2C_DATA_TRANSMIT[0] = VCNL4200_CMD_PS_CANC;
    DRV_I2C_WriteReadTransferAdd(vcnl4200_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &vcnl4200_driverData.I2C_DATA_TRANSMIT, 1, (void*) &vcnl4200_driverData.I2C_DATA_RECEIVE, 2, &vcnl4200_driverData.I2C_TRANSFER_HANDLE);
}

void VCNL4200_DRIVER_Store_PS_Cancellation(void)
{
    vcnl4200_sensorData.PS_CANC_LSB = vcnl4200_driverData.I2C_DATA_RECEIVE[0];
    vcnl4200_sensorData.PS_CANC_MSB = vcnl4200_driverData.I2C_DATA_RECEIVE[1];
}

void VCNL4200_DRIVER_Set_PS_Cancellation(uint8_t I2C_ADDRESS, uint8_t MSB_VALUE, uint8_t LSB_VALUE)
{
    vcnl4200_driverData.I2C_DATA_TRANSMIT[0] = VCNL4200_CMD_PS_CANC;
    vcnl4200_driverData.I2C_DATA_TRANSMIT[1] = LSB_VALUE;
    vcnl4200_driverData.I2C_DATA_TRANSMIT[2] = MSB_VALUE;
    DRV_I2C_WriteTransferAdd(vcnl4200_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &vcnl4200_driverData.I2C_DATA_TRANSMIT, 3, &vcnl4200_driverData.I2C_TRANSFER_HANDLE);
}

void VCNL4200_DRIVER_Get_PS_High_Alert(uint8_t I2C_ADDRESS)
{
    vcnl4200_driverData.I2C_DATA_TRANSMIT[0] = VCNL4200_CMD_PS_THDH;
    DRV_I2C_WriteReadTransferAdd(vcnl4200_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &vcnl4200_driverData.I2C_DATA_TRANSMIT, 1, (void*) &vcnl4200_driverData.I2C_DATA_RECEIVE, 2, &vcnl4200_driverData.I2C_TRANSFER_HANDLE);
}

void VCNL4200_DRIVER_Store_PS_High_Alert(void)
{
    vcnl4200_sensorData.PS_THDH = vcnl4200_driverData.I2C_DATA_RECEIVE[1] << 8 | vcnl4200_driverData.I2C_DATA_RECEIVE[0];
}

void VCNL4200_DRIVER_Set_PS_High_Alert(uint8_t I2C_ADDRESS, uint8_t MSB_VALUE, uint8_t LSB_VALUE)
{
    vcnl4200_driverData.I2C_DATA_TRANSMIT[0] = VCNL4200_CMD_PS_THDH;
    vcnl4200_driverData.I2C_DATA_TRANSMIT[1] = LSB_VALUE;
    vcnl4200_driverData.I2C_DATA_TRANSMIT[2] = MSB_VALUE;
    DRV_I2C_WriteTransferAdd(vcnl4200_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &vcnl4200_driverData.I2C_DATA_TRANSMIT, 3, &vcnl4200_driverData.I2C_TRANSFER_HANDLE);
}

void VCNL4200_DRIVER_Get_PS_Low_Alert(uint8_t I2C_ADDRESS)
{
    vcnl4200_driverData.I2C_DATA_TRANSMIT[0] = VCNL4200_CMD_PS_THDL;
    DRV_I2C_WriteReadTransferAdd(vcnl4200_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &vcnl4200_driverData.I2C_DATA_TRANSMIT, 1, (void*) &vcnl4200_driverData.I2C_DATA_RECEIVE, 2, &vcnl4200_driverData.I2C_TRANSFER_HANDLE);
}

void VCNL4200_DRIVER_Store_PS_Low_Alert(void)
{
    vcnl4200_sensorData.PS_THDL = vcnl4200_driverData.I2C_DATA_RECEIVE[1] << 8 | vcnl4200_driverData.I2C_DATA_RECEIVE[0];
}

void VCNL4200_DRIVER_Set_PS_Low_Alert(uint8_t I2C_ADDRESS, uint8_t MSB_VALUE, uint8_t LSB_VALUE)
{
    vcnl4200_driverData.I2C_DATA_TRANSMIT[0] = VCNL4200_CMD_PS_THDL;
    vcnl4200_driverData.I2C_DATA_TRANSMIT[1] = LSB_VALUE;
    vcnl4200_driverData.I2C_DATA_TRANSMIT[2] = MSB_VALUE;
    DRV_I2C_WriteTransferAdd(vcnl4200_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &vcnl4200_driverData.I2C_DATA_TRANSMIT, 3, &vcnl4200_driverData.I2C_TRANSFER_HANDLE);
}

void VCNL4200_DRIVER_Get_PS_Data(uint8_t I2C_ADDRESS)
{
    vcnl4200_driverData.I2C_DATA_TRANSMIT[0] = VCNL4200_CMD_PS_DATA;
    DRV_I2C_WriteReadTransferAdd(vcnl4200_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &vcnl4200_driverData.I2C_DATA_TRANSMIT, 1, (void*) &vcnl4200_driverData.I2C_DATA_RECEIVE, 2, &vcnl4200_driverData.I2C_TRANSFER_HANDLE);
}

void VCNL4200_DRIVER_Store_PS_Data(void)
{
    vcnl4200_sensorData.PS_DATA = vcnl4200_driverData.I2C_DATA_RECEIVE[1] << 8 | vcnl4200_driverData.I2C_DATA_RECEIVE[0];
}

void VCNL4200_DRIVER_Get_ALS_Data(uint8_t I2C_ADDRESS)
{
    vcnl4200_driverData.I2C_DATA_TRANSMIT[0] = VCNL4200_CMD_ALS_DATA;
    DRV_I2C_WriteReadTransferAdd(vcnl4200_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &vcnl4200_driverData.I2C_DATA_TRANSMIT, 1, (void*) &vcnl4200_driverData.I2C_DATA_RECEIVE, 2, &vcnl4200_driverData.I2C_TRANSFER_HANDLE);
}

void VCNL4200_DRIVER_Store_ALS_Data(void)
{
    vcnl4200_sensorData.ALS_DATA = vcnl4200_driverData.I2C_DATA_RECEIVE[1] << 8 | vcnl4200_driverData.I2C_DATA_RECEIVE[0];
}

void VCNL4200_DRIVER_Get_White_Data(uint8_t I2C_ADDRESS)
{
    vcnl4200_driverData.I2C_DATA_TRANSMIT[0] = VCNL4200_CMD_WHITE_DATA;
    DRV_I2C_WriteReadTransferAdd(vcnl4200_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &vcnl4200_driverData.I2C_DATA_TRANSMIT, 1, (void*) &vcnl4200_driverData.I2C_DATA_RECEIVE, 2, &vcnl4200_driverData.I2C_TRANSFER_HANDLE);
}

void VCNL4200_DRIVER_Store_White_Data(void)
{
    vcnl4200_sensorData.WHITE_DATA = vcnl4200_driverData.I2C_DATA_RECEIVE[1] << 8 | vcnl4200_driverData.I2C_DATA_RECEIVE[0];
}

void VCNL4200_DRIVER_Get_INT_Flag(uint8_t I2C_ADDRESS)
{
    vcnl4200_driverData.I2C_DATA_TRANSMIT[0] = VCNL4200_CMD_INT_FLAG;
    DRV_I2C_WriteReadTransferAdd(vcnl4200_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &vcnl4200_driverData.I2C_DATA_TRANSMIT, 1, (void*) &vcnl4200_driverData.I2C_DATA_RECEIVE, 2, &vcnl4200_driverData.I2C_TRANSFER_HANDLE);
}

void VCNL4200_DRIVER_Store_INT_Flag(void)
{
    vcnl4200_sensorData.INT_FLAG = vcnl4200_driverData.I2C_DATA_RECEIVE[1];
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void VCNL4200_DRIVER_Initialize(void)
{
    vcnl4200_driverData.state = VCNL4200_DRIVER_STATE_INIT;
    vcnl4200_driverData.I2C_HANDLE = DRV_HANDLE_INVALID;
    vcnl4200_driverData.I2C_TRANSFER_HANDLE = DRV_I2C_TRANSFER_HANDLE_INVALID;
    EIC_CallbackRegister(EIC_PIN_0, VCNL4200_DRIVER_Alert, 0);
}

void VCNL4200_DRIVER_Tasks(void)
{
    switch (vcnl4200_driverData.state)
    {
        case VCNL4200_DRIVER_STATE_INIT:
        {
            VCNL4200_DRIVER_Set_I2C_Address();
            vcnl4200_driverData.I2C_HANDLE = DRV_I2C_Open(DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE);
            vcnl4200_driverData.state = VCNL4200_DRIVER_STATE_CHECK_I2C_HANDLER;
            break;
        }

        case VCNL4200_DRIVER_STATE_CHECK_I2C_HANDLER:
        {
            if (vcnl4200_driverData.I2C_HANDLE == DRV_HANDLE_INVALID)
            {
                vcnl4200_driverData.state = VCNL4200_DRIVER_STATE_ERROR;
            }
            else
            {
                vcnl4200_driverData.state = VCNL4200_DRIVER_STATE_IDLE;
            }
            break;
        }

        case VCNL4200_DRIVER_STATE_IDLE:
        {
            if (VCNL4200_DRIVER_Get_Task_Start_Status() == true)
            {
                vcnl4200_driverData.state = VCNL4200_DRIVER_STATE_IDLE;
            }
            break;
        }

        case VCNL4200_DRIVER_STATE_TIMER_EXPIRED:
        {
            DRV_I2C_Close(vcnl4200_driverData.I2C_HANDLE);
            VCNL4200_DRIVER_Set_Task_Completed_Status(true);
            vcnl4200_driverData.state = MCP9808_DRIVER_STATE_IDLE;
            break;
        }

        case VCNL4200_DRIVER_STATE_ERROR:
        {
            DRV_I2C_Close(vcnl4200_driverData.I2C_HANDLE);
            VCNL4200_DRIVER_Set_Task_Completed_Status(true);
            vcnl4200_driverData.state = MCP9808_DRIVER_STATE_IDLE;
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