/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    sht4x_driver.c

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

#include "sht4x_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

SHT4X_DRIVER_DATA sht4x_driverData;

SHT4X_DRIVER_SENSOR_DATA sht4x_sensorData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void SHT4X_DRIVER_I2C_Callback(DRV_I2C_TRANSFER_EVENT EVENT, DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE, uintptr_t CONTEXT)
{
    switch (EVENT)
    {
        case DRV_I2C_TRANSFER_EVENT_COMPLETE:
        {
            sht4x_driverData.I2C_TRANSFER_STATUS = true;
            break;
        }

        case DRV_I2C_TRANSFER_EVENT_ERROR:
        {
            sht4x_driverData.I2C_TRANSFER_STATUS = false;
            break;
        }

        default:
        {
            break;
        }
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

bool SHT4X_DRIVER_Get_Task_Start_Status(void)
{
    return (sht4x_driverData.SHT4X_TASK_START);
}

void SHT4X_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    sht4x_driverData.SHT4X_TASK_START = STATUS;
}

bool SHT4X_DRIVER_Get_Task_Completed_Status(void)
{
    return (sht4x_driverData.SHT4X_TASK_COMPLETED);
}

void SHT4X_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    sht4x_driverData.SHT4X_TASK_COMPLETED = STATUS;
}

void SHT4X_DRIVER_Start_Measurement(uint8_t I2C_ADDRESS, uint8_t SHT4X_REGISTER)
{
    sht4x_driverData.I2C_DATA_TRANSMIT[0] = SHT4X_REGISTER;
    DRV_I2C_WriteTransferAdd(sht4x_driverData.I2C_HANDLE, I2C_ADDRESS, &sht4x_driverData.I2C_DATA_TRANSMIT, 1, &sht4x_driverData.I2C_TRANSFER_HANDLE);
}

void SHT4X_DRIVER_Get_Measure_Values(uint8_t I2C_ADDRESS)
{
    DRV_I2C_ReadTransferAdd(sht4x_driverData.I2C_HANDLE, I2C_ADDRESS, &sht4x_driverData.I2C_DATA_RECEIVE, 6, &sht4x_driverData.I2C_TRANSFER_HANDLE);
}

void SHT4X_DRIVER_Store_Measure_Values(void)
{
    sht4x_sensorData.T_VALUE = sht4x_driverData.I2C_DATA_RECEIVE[0] << 8 | sht4x_driverData.I2C_DATA_RECEIVE[1];
    sht4x_sensorData.H_VALUE = sht4x_driverData.I2C_DATA_RECEIVE[3] << 8 | sht4x_driverData.I2C_DATA_RECEIVE[4];
}

void SHT4X_DRIVER_Read_Serial_Number(uint8_t I2C_ADDRESS)
{
    sht4x_driverData.I2C_DATA_TRANSMIT[0] = SHT4X_SERIAL_NUMBER;
    DRV_I2C_WriteReadTransferAdd(sht4x_driverData.I2C_HANDLE, I2C_ADDRESS, &sht4x_driverData.I2C_DATA_TRANSMIT, 1, &sht4x_driverData.I2C_DATA_RECEIVE, 6, &sht4x_driverData.I2C_TRANSFER_HANDLE);
}

void SHT4X_DRIVER_Store_Serial_Number(void)
{
    sht4x_sensorData.SERIAL_NUMBER = sht4x_driverData.I2C_DATA_RECEIVE[0] << 24 | sht4x_driverData.I2C_DATA_RECEIVE[1] << 16 | sht4x_driverData.I2C_DATA_RECEIVE[3] << 8 | sht4x_driverData.I2C_DATA_RECEIVE[4];
}

void SHT4X_DRIVER_Soft_Reset(uint8_t I2C_ADDRESS)
{
    sht4x_driverData.I2C_DATA_TRANSMIT[0] = SHT4X_SOFT_RESET;
    DRV_I2C_WriteTransferAdd(sht4x_driverData.I2C_HANDLE, I2C_ADDRESS, &sht4x_driverData.I2C_DATA_TRANSMIT, 1, &sht4x_driverData.I2C_TRANSFER_HANDLE);
}

void SHT4X_DRIVER_Calculation_Temperature(uint16_t T_VALUE)
{
    sht4x_sensorData.CELSIUS_TEMPERATURE = -45 + 175 * ((float) T_VALUE / 65535);
    sht4x_sensorData.FAHRENHEIT_TEMPERATURE = -49 + 315 * ((float) T_VALUE / 65535);
}

void SHT4X_DRIVER_Calculation_Humidity(uint16_t H_VALUE)
{
    sht4x_sensorData.HUMIDITY = -6 + 125 * ((float) H_VALUE / 65535);
}

void SHT4X_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)
{
    SYS_CONSOLE_Print
            (
             CONSOLE_HANDLE,
             "Temperature: %.2f  C\r\n"
             "Temperature: %.2f  F\r\n"
             "Humidity: %.2f %%\r\n",
             sht4x_sensorData.CELSIUS_TEMPERATURE,
             sht4x_sensorData.FAHRENHEIT_TEMPERATURE,
             sht4x_sensorData.HUMIDITY
             );
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void SHT4X_DRIVER_Initialize(void)
{
    sht4x_driverData.state = SHT4X_DRIVER_STATE_INIT;
    sht4x_driverData.I2C_HANDLE = DRV_HANDLE_INVALID;
    sht4x_driverData.I2C_TRANSFER_HANDLE = DRV_I2C_TRANSFER_HANDLE_INVALID;
    sht4x_driverData.I2C_TRANSFER_STATUS = false;
}

void SHT4X_DRIVER_Tasks(void)
{
    switch (sht4x_driverData.state)
    {
        case SHT4X_DRIVER_STATE_INIT:
        {
            sht4x_driverData.I2C_HANDLE = DRV_I2C_Open(DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE);
            sht4x_driverData.state = SHT4X_DRIVER_STATE_I2C_HANDLER_REGISTER;
            break;
        }

        case SHT4X_DRIVER_STATE_I2C_HANDLER_REGISTER:
        {
            if (sht4x_driverData.I2C_HANDLE == DRV_HANDLE_INVALID)
            {
                sht4x_driverData.state = SHT4X_DRIVER_STATE_ERROR;
            }
            else
            {
                DRV_I2C_TransferEventHandlerSet(sht4x_driverData.I2C_HANDLE, SHT4X_DRIVER_I2C_Callback, (uintptr_t) & sht4x_driverData.I2C_TRANSFER_STATUS);
                sht4x_driverData.state = SHT4X_DRIVER_STATE_IDLE;
            }
            break;
        }

        case SHT4X_DRIVER_STATE_IDLE:
        {
            if (SHT4X_DRIVER_Get_Task_Start_Status() == true)
            {
                sht4x_driverData.state = SHT4X_DRIVER_STATE_START_MEASURE;
            }
            break;
        }

        case SHT4X_DRIVER_STATE_START_MEASURE:
        {
            SHT4X_DRIVER_Start_Measurement(SHT4X_I2C_ADDRESS, SHT4X_MEASURE_TEMP_HUM_HIGH_PRECISION);
            TIMER_DRIVER_Start_Bus_TMR();
            sht4x_driverData.state = SHT4X_DRIVER_STATE_START_MEASURE_ACK;
            break;
        }

        case SHT4X_DRIVER_STATE_START_MEASURE_ACK:
        {
            if (sht4x_driverData.I2C_TRANSFER_HANDLE == DRV_I2C_TRANSFER_HANDLE_INVALID)
            {
                sht4x_driverData.state = SHT4X_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                sht4x_driverData.state = SHT4X_DRIVER_STATE_TIMER_EXPIRED;
            }
            else
            {
                sht4x_driverData.state = SHT4X_DRIVER_STATE_START_MEASURE_WAIT_FOR_TRANSFER;
            }
            break;
        }

        case SHT4X_DRIVER_STATE_START_MEASURE_WAIT_FOR_TRANSFER:
        {
            if (sht4x_driverData.I2C_TRANSFER_STATUS == true)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                TIMER_DRIVER_Start_Wait_TMR();
                sht4x_driverData.I2C_TRANSFER_STATUS = false;
                sht4x_driverData.state = SHT4X_DRIVER_STATE_WAIT_FOR_MEASURE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                sht4x_driverData.state = SHT4X_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SHT4X_DRIVER_STATE_WAIT_FOR_MEASURE:
        {
            if (TIMER_DRIVER_Get_Wait_TMR_Status() == true)
            {
                sht4x_driverData.state = SHT4X_DRIVER_STATE_GET_MEASURE_DATA;
            }
            break;
        }

        case SHT4X_DRIVER_STATE_GET_MEASURE_DATA:
        {
            SHT4X_DRIVER_Get_Measure_Values(SHT4X_I2C_ADDRESS);
            TIMER_DRIVER_Start_Bus_TMR();
            sht4x_driverData.state = SHT4X_DRIVER_STATE_GET_MEASURE_DATA_ACK;
            break;
        }

        case SHT4X_DRIVER_STATE_GET_MEASURE_DATA_ACK:
        {
            if (sht4x_driverData.I2C_TRANSFER_HANDLE == DRV_I2C_TRANSFER_HANDLE_INVALID)
            {
                sht4x_driverData.state = SHT4X_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                sht4x_driverData.state = SHT4X_DRIVER_STATE_TIMER_EXPIRED;
            }
            else
            {
                sht4x_driverData.state = SHT4X_DRIVER_STATE_GET_MEASURE_DATA_WAIT_FOR_TRANSFER;
            }
            break;
        }

        case SHT4X_DRIVER_STATE_GET_MEASURE_DATA_WAIT_FOR_TRANSFER:
        {
            if (sht4x_driverData.I2C_TRANSFER_STATUS == true)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                sht4x_driverData.I2C_TRANSFER_STATUS = false;
                sht4x_driverData.state = SHT4X_DRIVER_STATE_CALCULATE_DATA;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                sht4x_driverData.state = SHT4X_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SHT4X_DRIVER_STATE_CALCULATE_DATA:
        {
            SHT4X_DRIVER_Calculation_Temperature(sht4x_sensorData.T_VALUE);
            SHT4X_DRIVER_Calculation_Humidity(sht4x_sensorData.H_VALUE);
            sht4x_driverData.state = SHT4X_DRIVER_STATE_STORE_DATA;
            break;
        }

        case SHT4X_DRIVER_STATE_STORE_DATA:
        {
            /* Add function for storing temperature */
            SHT4X_DRIVER_Set_Task_Completed_Status(true);
            sht4x_driverData.state = SHT4X_DRIVER_STATE_IDLE;
            break;
        }

        case SHT4X_DRIVER_STATE_TIMER_EXPIRED:
        {
            DRV_I2C_Close(sht4x_driverData.I2C_HANDLE);
            SHT4X_DRIVER_Set_Task_Completed_Status(true);
            sht4x_driverData.state = MCP9808_DRIVER_STATE_IDLE;
            break;
        }

        case SHT4X_DRIVER_STATE_ERROR:
        {
            DRV_I2C_Close(sht4x_driverData.I2C_HANDLE);
            SHT4X_DRIVER_Set_Task_Completed_Status(true);
            sht4x_driverData.state = MCP9808_DRIVER_STATE_IDLE;
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