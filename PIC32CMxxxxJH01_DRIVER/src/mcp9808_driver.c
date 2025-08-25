/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    mcp9808_driver.c

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

#include "mcp9808_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

MCP9808_DRIVER_DATA mcp9808_driverData;

MCP9808_DRIVER_SENSOR_DATA mcp9808_sensorData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void MCP9808_DRIVER_I2C_Callback(DRV_I2C_TRANSFER_EVENT EVENT, DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE, uintptr_t CONTEXT)
{
    switch (EVENT)
    {
        case DRV_I2C_TRANSFER_EVENT_COMPLETE:
        {
            mcp9808_driverData.I2C_TRANSFER_STATUS = true;
            break;
        }

        case DRV_I2C_TRANSFER_EVENT_ERROR:
        {
            mcp9808_driverData.I2C_TRANSFER_STATUS = false;
            break;
        }

        default:
        {
            break;
        }
    }
}

void MCP9808_DRIVER_Alert(uintptr_t CONTEXT)
{
    mcp9808_driverData.MCP9808_ALERT = true;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

bool MCP9808_DRIVER_Get_Task_Start_Status(void)
{
    return (mcp9808_driverData.MCP9808_TASK_START);
}

void MCP9808_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    mcp9808_driverData.MCP9808_TASK_START = STATUS;
}

bool MCP9808_DRIVER_Get_Task_Completed_Status(void)
{
    return (mcp9808_driverData.MCP9808_TASK_COMPLETED);
}

void MCP9808_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    mcp9808_driverData.MCP9808_TASK_COMPLETED = STATUS;
}

void MCP9808_DRIVER_Set_I2C_Address(void)
{
    mcp9808_driverData.I2C_ADDRESS[0] = 0x18;
    mcp9808_driverData.I2C_ADDRESS[1] = 0x19;
    mcp9808_driverData.I2C_ADDRESS[2] = 0x1A;
    mcp9808_driverData.I2C_ADDRESS[3] = 0x1B;
    mcp9808_driverData.I2C_ADDRESS[4] = 0x1C;
    mcp9808_driverData.I2C_ADDRESS[5] = 0x1D;
    mcp9808_driverData.I2C_ADDRESS[6] = 0x1E;
    mcp9808_driverData.I2C_ADDRESS[7] = 0x1F;
}

void MCP9808_DRIVER_Get_Sensor_Config(uint8_t I2C_ADDRESS)
{
    mcp9808_driverData.I2C_DATA_TRANSMIT[0] = MCP9808_CMD_CONFIG_REGISTER;
    DRV_I2C_WriteReadTransferAdd(mcp9808_driverData.I2C_HANDLE, I2C_ADDRESS, (void *) &mcp9808_driverData.I2C_DATA_TRANSMIT, 1, (void*) &mcp9808_driverData.I2C_DATA_RECEIVE, 2, &mcp9808_driverData.I2C_TRANSFER_HANDLE);
}

void MCP9808_DRIVER_Store_Sensor_Config(void)
{
    mcp9808_sensorData.CONFIG_MSB = mcp9808_driverData.I2C_DATA_RECEIVE[0];
    mcp9808_sensorData.CONFIG_LSB = mcp9808_driverData.I2C_DATA_RECEIVE[1];
}

void MCP9808_DRIVER_Set_Sensor_Config(uint8_t I2C_ADDRESS, uint8_t CONFIG_MSB, uint8_t CONFIG_LSB)
{
    mcp9808_driverData.I2C_DATA_TRANSMIT[0] = MCP9808_CMD_CONFIG_REGISTER;
    mcp9808_driverData.I2C_DATA_TRANSMIT[1] = CONFIG_MSB;
    mcp9808_driverData.I2C_DATA_TRANSMIT[2] = CONFIG_LSB;
    DRV_I2C_WriteTransferAdd(mcp9808_driverData.I2C_HANDLE, I2C_ADDRESS, (void *) &mcp9808_driverData.I2C_DATA_TRANSMIT, 3, &mcp9808_driverData.I2C_TRANSFER_HANDLE);
}

void MCP9808_DRIVER_Get_Temperature_Values(uint8_t I2C_ADDRESS)
{
    mcp9808_driverData.I2C_DATA_TRANSMIT[0] = MCP9808_CMD_TEMPERATURE_REGISTER;
    DRV_I2C_WriteReadTransferAdd(mcp9808_driverData.I2C_HANDLE, I2C_ADDRESS, (void *) &mcp9808_driverData.I2C_DATA_TRANSMIT, 1, (void*) &mcp9808_driverData.I2C_DATA_RECEIVE, 2, &mcp9808_driverData.I2C_TRANSFER_HANDLE);
}

void MCP9808_DRIVER_Store_Temperature_Values(void)
{
    mcp9808_sensorData.T_VALUE_MSB = mcp9808_driverData.I2C_DATA_RECEIVE[0];
    mcp9808_sensorData.T_VALUE_LSB = mcp9808_driverData.I2C_DATA_RECEIVE[1];
}

void MCP9808_DRIVER_Calculate_Temperature(void)
{
    mcp9808_sensorData.T_VALUE_MSB = mcp9808_sensorData.T_VALUE_MSB & 0xF;
    if ((mcp9808_sensorData.T_VALUE_MSB & 0x10) == 0x10)
    {
        mcp9808_sensorData.CELSIUS_TEMPERATURE = 256.00 - (((float) mcp9808_sensorData.T_VALUE_MSB * 16.00) + ((float) mcp9808_sensorData.T_VALUE_LSB / 16.00));
    }
    else
    {
        mcp9808_sensorData.CELSIUS_TEMPERATURE = (((float) mcp9808_sensorData.T_VALUE_MSB * 16.00) + ((float) mcp9808_sensorData.T_VALUE_LSB / 16.00));
    }
}

void MCP9808_DRIVER_Get_Manufacturer_ID(uint8_t I2C_ADDRESS)
{
    mcp9808_driverData.I2C_DATA_TRANSMIT[0] = MCP9808_CMD_MANUFACTURE_ID_REGISTER;
    DRV_I2C_WriteReadTransferAdd(mcp9808_driverData.I2C_HANDLE, I2C_ADDRESS, (void *) &mcp9808_driverData.I2C_DATA_TRANSMIT, 1, (void*) &mcp9808_driverData.I2C_DATA_RECEIVE, 2, &mcp9808_driverData.I2C_TRANSFER_HANDLE);
}

void MCP9808_DRIVER_Store_Manufacturer_ID(void)
{
    mcp9808_sensorData.MANUFACTURER_ID_MSB = mcp9808_driverData.I2C_DATA_RECEIVE[0];
    mcp9808_sensorData.MANUFACTURER_ID_LSB = mcp9808_driverData.I2C_DATA_RECEIVE[1];
}

void MCP9808_DRIVER_Get_Device_ID(uint8_t I2C_ADDRESS)
{
    mcp9808_driverData.I2C_DATA_TRANSMIT[0] = MCP9808_CMD_DEVICE_ID_REGISTER;
    DRV_I2C_WriteReadTransferAdd(mcp9808_driverData.I2C_HANDLE, I2C_ADDRESS, (void *) &mcp9808_driverData.I2C_DATA_TRANSMIT, 1, (void*) &mcp9808_driverData.I2C_DATA_RECEIVE, 2, &mcp9808_driverData.I2C_TRANSFER_HANDLE);
}

void MCP9808_DRIVER_Store_Device_ID(void)
{
    mcp9808_sensorData.DEVICE_ID = mcp9808_driverData.I2C_DATA_RECEIVE[0];
    mcp9808_sensorData.DEVICE_REVISION = mcp9808_driverData.I2C_DATA_RECEIVE[1];
}

void MCP9808_DRIVER_Get_Result_Resolution(uint8_t I2C_ADDRESS)
{
    mcp9808_driverData.I2C_DATA_TRANSMIT[0] = MCP9808_CMD_RESULT_RESOLUTION_REGISTER;
    DRV_I2C_WriteReadTransferAdd(mcp9808_driverData.I2C_HANDLE, I2C_ADDRESS, (void *) &mcp9808_driverData.I2C_DATA_TRANSMIT, 1, (void*) &mcp9808_driverData.I2C_DATA_RECEIVE, 1, &mcp9808_driverData.I2C_TRANSFER_HANDLE);
}

void MCP9808_DRIVER_Store_Result_Resolution(void)
{
    mcp9808_sensorData.RESULT_RESOLUTION = mcp9808_driverData.I2C_DATA_RECEIVE[0];
}

void MCP9808_DRIVER_Set_Result_Resolution(uint8_t I2C_ADDRESS, uint8_t RESULT_RESOULUTION)
{
    mcp9808_driverData.I2C_DATA_TRANSMIT[0] = MCP9808_CMD_RESULT_RESOLUTION_REGISTER;
    mcp9808_driverData.I2C_DATA_TRANSMIT[1] = RESULT_RESOULUTION;
    DRV_I2C_WriteTransferAdd(mcp9808_driverData.I2C_HANDLE, I2C_ADDRESS, (void *) &mcp9808_driverData.I2C_DATA_TRANSMIT, 2, &mcp9808_driverData.I2C_TRANSFER_HANDLE);
}

void MCP9808_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)
{
    SYS_CONSOLE_Print
            (
             CONSOLE_HANDLE,
             "Manufacturer ID: %X%X\r\n"
             "Device ID: %X\r\n"
             "Device version: %d\r\n"
             "Temperature: %.2f\r\n",
             mcp9808_sensorData.MANUFACTURER_ID_MSB, mcp9808_sensorData.MANUFACTURER_ID_LSB,
             mcp9808_sensorData.DEVICE_ID, mcp9808_sensorData.DEVICE_REVISION,
             mcp9808_sensorData.CELSIUS_TEMPERATURE
             );
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void MCP9808_DRIVER_Initialize(void)
{
    mcp9808_driverData.state = MCP9808_DRIVER_STATE_INIT;
    mcp9808_driverData.I2C_HANDLE = DRV_HANDLE_INVALID;
    mcp9808_driverData.I2C_TRANSFER_HANDLE = DRV_I2C_TRANSFER_HANDLE_INVALID;
    mcp9808_driverData.I2C_TRANSFER_STATUS = false;
}

void MCP9808_DRIVER_Tasks(void)
{
    switch (mcp9808_driverData.state)
    {
        case MCP9808_DRIVER_STATE_INIT:
        {
            mcp9808_driverData.I2C_HANDLE = DRV_I2C_Open(DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE);
            MCP9808_DRIVER_Set_I2C_Address();
            mcp9808_driverData.state = MCP9808_DRIVER_STATE_I2C_HANDLER_REGISTER;
            break;
        }

        case MCP9808_DRIVER_STATE_I2C_HANDLER_REGISTER:
        {
            if (mcp9808_driverData.I2C_HANDLE == DRV_HANDLE_INVALID)
            {
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_ERROR;
            }
            else
            {
                DRV_I2C_TransferEventHandlerSet(mcp9808_driverData.I2C_HANDLE, MCP9808_DRIVER_I2C_Callback, (uintptr_t) & mcp9808_driverData.I2C_TRANSFER_STATUS);
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_GET_MANUFACTURER_ID;
            }
            break;
        }

        case MCP9808_DRIVER_STATE_GET_MANUFACTURER_ID:
        {
            MCP9808_DRIVER_Get_Manufacturer_ID(mcp9808_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            mcp9808_driverData.state = MCP9808_DRIVER_STATE_GET_MANUFACTURER_ID_ACK;
            break;
        }

        case MCP9808_DRIVER_STATE_GET_MANUFACTURER_ID_ACK:
        {
            if (mcp9808_driverData.I2C_TRANSFER_HANDLE == DRV_I2C_TRANSFER_HANDLE_INVALID)
            {
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_TIMER_EXPIRED;
            }
            else
            {
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_GET_MANUFACTURER_ID_WAIT_FOR_TRANSFER;
            }
            break;
        }

        case MCP9808_DRIVER_STATE_GET_MANUFACTURER_ID_WAIT_FOR_TRANSFER:
        {
            if (mcp9808_driverData.I2C_TRANSFER_STATUS == true)
            {
                mcp9808_driverData.I2C_TRANSFER_STATUS = false;
                TIMER_DRIVER_Stop_Bus_TMR();
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_STORE_MANUFACTURER_ID;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case MCP9808_DRIVER_STATE_STORE_MANUFACTURER_ID:
        {
            MCP9808_DRIVER_Store_Manufacturer_ID();
            mcp9808_driverData.state = MCP9808_DRIVER_STATE_GET_DEVICE_ID;
            break;
        }

        case MCP9808_DRIVER_STATE_GET_DEVICE_ID:
        {
            MCP9808_DRIVER_Get_Device_ID(mcp9808_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            mcp9808_driverData.state = MCP9808_DRIVER_STATE_GET_DEVICE_ID_ACK;
            break;
        }

        case MCP9808_DRIVER_STATE_GET_DEVICE_ID_ACK:
        {
            if (mcp9808_driverData.I2C_TRANSFER_HANDLE == DRV_I2C_TRANSFER_HANDLE_INVALID)
            {
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_TIMER_EXPIRED;
            }
            else
            {
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_GET_DEVICE_ID_WAIT_FOR_TRANSFER;
            }
            break;
        }

        case MCP9808_DRIVER_STATE_GET_DEVICE_ID_WAIT_FOR_TRANSFER:
        {
            if (mcp9808_driverData.I2C_TRANSFER_STATUS == true)
            {
                mcp9808_driverData.I2C_TRANSFER_STATUS = false;
                TIMER_DRIVER_Stop_Bus_TMR();
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_STORE_DEVICE_ID;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case MCP9808_DRIVER_STATE_STORE_DEVICE_ID:
        {
            MCP9808_DRIVER_Store_Device_ID();
            mcp9808_driverData.state = MCP9808_DRIVER_STATE_SET_RESULT_RESOLUTION;
            break;
        }

        case MCP9808_DRIVER_STATE_SET_RESULT_RESOLUTION:
        {
            MCP9808_DRIVER_Set_Result_Resolution(mcp9808_driverData.I2C_ADDRESS[0], 0b00000001);
            TIMER_DRIVER_Start_Bus_TMR();
            mcp9808_driverData.state = MCP9808_DRIVER_STATE_SET_RESULT_RESOLUTION_ACK;
            break;
        }

        case MCP9808_DRIVER_STATE_SET_RESULT_RESOLUTION_ACK:
        {
            if (mcp9808_driverData.I2C_TRANSFER_HANDLE == DRV_I2C_TRANSFER_HANDLE_INVALID)
            {
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_TIMER_EXPIRED;
            }
            else
            {
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_SET_RESULT_RESOLUTION_WAIT_FOR_TRANSFER;
            }
            break;
        }

        case MCP9808_DRIVER_STATE_SET_RESULT_RESOLUTION_WAIT_FOR_TRANSFER:
        {
            if (mcp9808_driverData.I2C_TRANSFER_STATUS == true)
            {
                mcp9808_driverData.I2C_TRANSFER_STATUS = false;
                TIMER_DRIVER_Stop_Bus_TMR();
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_IDLE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case MCP9808_DRIVER_STATE_IDLE:
        {
            if (MCP9808_DRIVER_Get_Task_Start_Status() == true)
            {
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_GET_TEMPERATURE_VALUES;
            }
            break;
        }

        case MCP9808_DRIVER_STATE_GET_TEMPERATURE_VALUES:
        {
            MCP9808_DRIVER_Get_Temperature_Values(mcp9808_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            mcp9808_driverData.state = MCP9808_DRIVER_STATE_GET_TEMPERATURE_VALUES_ACK;
            break;
        }

        case MCP9808_DRIVER_STATE_GET_TEMPERATURE_VALUES_ACK:
        {
            if (mcp9808_driverData.I2C_TRANSFER_HANDLE == DRV_I2C_TRANSFER_HANDLE_INVALID)
            {
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_TIMER_EXPIRED;
            }
            else
            {
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_GET_TEMPERATURE_VALUES_WAIT_FOR_TRANSFER;
            }
            break;
        }

        case MCP9808_DRIVER_STATE_GET_TEMPERATURE_VALUES_WAIT_FOR_TRANSFER:
        {
            if (mcp9808_driverData.I2C_TRANSFER_STATUS == true)
            {
                mcp9808_driverData.I2C_TRANSFER_STATUS = false;
                TIMER_DRIVER_Stop_Bus_TMR();
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_STORE_TEMPERATURE_VALUES;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                mcp9808_driverData.state = MCP9808_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case MCP9808_DRIVER_STATE_STORE_TEMPERATURE_VALUES:
        {
            MCP9808_DRIVER_Store_Temperature_Values();
            mcp9808_driverData.state = MCP9808_DRIVER_STATE_CALCULATE_TEMPERATURE;
            break;
        }

        case MCP9808_DRIVER_STATE_CALCULATE_TEMPERATURE:
        {
            MCP9808_DRIVER_Calculate_Temperature();
            mcp9808_driverData.state = MCP9808_DRIVER_STATE_STORE_TEMPERATURE;
            break;
        }

        case MCP9808_DRIVER_STATE_STORE_TEMPERATURE:
        {
            /* Add function for storing temperature */
            MCP9808_DRIVER_Set_Task_Completed_Status(true);
            mcp9808_driverData.state = MCP9808_DRIVER_STATE_IDLE;
            break;
        }

        case MCP9808_DRIVER_STATE_TIMER_EXPIRED:
        {
            DRV_I2C_Close(mcp9808_driverData.I2C_HANDLE);
            MCP9808_DRIVER_Set_Task_Completed_Status(true);
            mcp9808_driverData.state = MCP9808_DRIVER_STATE_IDLE;
            break;
        }

        case MCP9808_DRIVER_STATE_ERROR:
        {
            DRV_I2C_Close(mcp9808_driverData.I2C_HANDLE);
            MCP9808_DRIVER_Set_Task_Completed_Status(true);
            mcp9808_driverData.state = MCP9808_DRIVER_STATE_IDLE;
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