/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    stcc4_driver.c

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

#include "stcc4_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************

STCC4_DRIVER_DATA stcc4_driverData;

STCC4_DRIVER_SENSOR_DATA stcc4_sensorData;

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

bool STCC4_DRIVER_Get_Task_Start_Status(void)
{
    return (stcc4_driverData.STCC4_TASK_START);
}

void STCC4_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    stcc4_driverData.STCC4_TASK_START = STATUS;
}

bool STCC4_DRIVER_Get_Task_Completed_Status(void)
{
    return (stcc4_driverData.STCC4_TASK_COMPLETED);
}

void STCC4_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    stcc4_driverData.STCC4_TASK_COMPLETED = STATUS;
}

void STCC4_DRIVER_Set_I2C_Address(void)
{
    stcc4_driverData.I2C_ADDRESS[0] = 0x64;
    stcc4_driverData.I2C_ADDRESS[1] = 0x65;
}

void STCC4_DRIVER_Start_Continuous_Measurement(uint8_t I2C_ADDRESS)
{
    stcc4_driverData.I2C_DATA_TRANSMIT[0] = STCC4_CMD_START_CONTINUOUS_MEASUREMENT_MSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[1] = STCC4_CMD_START_CONTINUOUS_MEASUREMENT_LSB;
    DRV_I2C_WriteTransferAdd(stcc4_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &stcc4_driverData.I2C_DATA_TRANSMIT, 1, &stcc4_driverData.I2C_TRANSFER_HANDLE);
}

void STCC4_DRIVER_Stop_Continuous_Measurement(uint8_t I2C_ADDRESS)
{
    stcc4_driverData.I2C_DATA_TRANSMIT[0] = STCC4_CMD_STOP_CONTINUOUS_MEASUREMENT_MSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[1] = STCC4_CMD_STOP_CONTINUOUS_MEASUREMENT_LSB;
    DRV_I2C_WriteTransferAdd(stcc4_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &stcc4_driverData.I2C_DATA_TRANSMIT, 1, &stcc4_driverData.I2C_TRANSFER_HANDLE);
}

void STCC4_DRIVER_Get_Measure_Values(uint8_t I2C_ADDRESS)
{
    stcc4_driverData.I2C_DATA_TRANSMIT[0] = STCC4_CMD_READ_MEASUREMENT_MSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[1] = STCC4_CMD_READ_MEASUREMENT_LSB;
    DRV_I2C_WriteReadTransferAdd(stcc4_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) stcc4_driverData.I2C_DATA_TRANSMIT, 2, (void*) stcc4_driverData.I2C_DATA_RECEIVE, 12, &stcc4_driverData.I2C_TRANSFER_HANDLE);
}

void STCC4_DRIVER_Store_Measured_Values(void)
{
    stcc4_sensorData.CO2_VALUE = (uint16_t) stcc4_driverData.I2C_DATA_RECEIVE[0] << 8 | (uint16_t) stcc4_driverData.I2C_DATA_RECEIVE[1];
    stcc4_sensorData.T_VALUE = (uint16_t) stcc4_driverData.I2C_DATA_RECEIVE[3] << 8 | (uint16_t) stcc4_driverData.I2C_DATA_RECEIVE[4];
    stcc4_sensorData.H_VALUE = (uint16_t) stcc4_driverData.I2C_DATA_RECEIVE[6] << 8 | (uint16_t) stcc4_driverData.I2C_DATA_RECEIVE[7];
    stcc4_sensorData.SENSOR_STATUS = (uint16_t) stcc4_driverData.I2C_DATA_RECEIVE[9] << 8 | (uint16_t) stcc4_driverData.I2C_DATA_RECEIVE[10];
}

void STCC4_DRIVER_Set_RHT_Compensation(uint8_t I2C_ADDRESS, uint8_t T_VALUE_MSB, uint8_t T_VALUE_LSB, uint8_t H_VALUE_MSB, uint8_t H_VALUE_LSB)
{
    stcc4_driverData.I2C_DATA_TRANSMIT[0] = STCC4_CMD_SET_RHT_COMPENSATION_MSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[1] = STCC4_CMD_SET_RHT_COMPENSATION_LSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[2] = T_VALUE_MSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[3] = T_VALUE_LSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[4] = STCC4_DRIVER_Calculation_Array_CRC(T_VALUE_MSB, T_VALUE_LSB);
    stcc4_driverData.I2C_DATA_TRANSMIT[5] = H_VALUE_MSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[6] = H_VALUE_LSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[7] = STCC4_DRIVER_Calculation_Array_CRC(H_VALUE_MSB, H_VALUE_LSB);
    DRV_I2C_WriteTransferAdd(stcc4_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &stcc4_driverData.I2C_DATA_TRANSMIT, 8, &stcc4_driverData.I2C_TRANSFER_HANDLE);
}

void STCC4_DRIVER_Set_Pressure_Compensation(uint8_t I2C_ADDRESS, uint8_t P_VALUE_MSB, uint8_t P_VALUE_LSB)
{
    stcc4_driverData.I2C_DATA_TRANSMIT[0] = STCC4_CMD_SET_PRESSURE_COMPENSATION_MSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[1] = STCC4_CMD_SET_PRESSURE_COMPENSATION_LSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[2] = P_VALUE_MSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[3] = P_VALUE_LSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[4] = STCC4_DRIVER_Calculation_Array_CRC(P_VALUE_MSB, P_VALUE_LSB);
    DRV_I2C_WriteTransferAdd(stcc4_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &stcc4_driverData.I2C_DATA_TRANSMIT, 5, &stcc4_driverData.I2C_TRANSFER_HANDLE);
}

void STCC4_DRIVER_Single_Shot_Measurement(uint8_t I2C_ADDRESS)
{
    stcc4_driverData.I2C_DATA_TRANSMIT[0] = STCC4_CMD_MEASURE_SINGLE_SHOT_MSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[1] = STCC4_CMD_MEASURE_SINGLE_SHOT_LSB;
    DRV_I2C_WriteTransferAdd(stcc4_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &stcc4_driverData.I2C_DATA_TRANSMIT, 2, &stcc4_driverData.I2C_TRANSFER_HANDLE);
}

void STCC4_DRIVER_Enter_Sleep_Mode(uint8_t I2C_ADDRESS)
{
    stcc4_driverData.I2C_DATA_TRANSMIT[0] = STCC4_CMD_ENTER_SLEEP_MODE_MSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[1] = STCC4_CMD_ENTER_SLEEP_MODE_LSB;
    DRV_I2C_WriteTransferAdd(stcc4_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &stcc4_driverData.I2C_DATA_TRANSMIT, 2, &stcc4_driverData.I2C_TRANSFER_HANDLE);
}

void STCC4_DRIVER_Exit_Sleep_Mode(uint8_t I2C_ADDRESS)
{
    stcc4_driverData.I2C_DATA_TRANSMIT[0] = STCC4_CMD_EXIT_SLEEP_MODE;
    DRV_I2C_WriteTransferAdd(stcc4_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &stcc4_driverData.I2C_DATA_TRANSMIT, 1, &stcc4_driverData.I2C_TRANSFER_HANDLE);
}

void STCC4_DRIVER_Perform_Conditioning(uint8_t I2C_ADDRESS)
{
    stcc4_driverData.I2C_DATA_TRANSMIT[0] = STCC4_CMD_PERFORM_CONDITIONING_MSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[1] = STCC4_CMD_PERFORM_CONDITIONING_LSB;
    DRV_I2C_WriteTransferAdd(stcc4_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &stcc4_driverData.I2C_DATA_TRANSMIT, 2, &stcc4_driverData.I2C_TRANSFER_HANDLE);
}

void STCC4_DRIVER_Perform_Soft_Reset(uint8_t I2C_ADDRESS)
{
    stcc4_driverData.I2C_DATA_TRANSMIT[0] = STCC4_CMD_PERFORM_SOFT_RESET;
    DRV_I2C_WriteTransferAdd(stcc4_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &stcc4_driverData.I2C_DATA_TRANSMIT, 1, &stcc4_driverData.I2C_TRANSFER_HANDLE);
}

void STCC4_DRIVER_Perform_Factory_Reset(uint8_t I2C_ADDRESS)
{
    stcc4_driverData.I2C_DATA_TRANSMIT[0] = STCC4_CMD_PERFORM_FACTORY_RESET_MSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[1] = STCC4_CMD_PERFORM_FACTORY_RESET_LSB;
    DRV_I2C_WriteReadTransferAdd(stcc4_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &stcc4_driverData.I2C_DATA_TRANSMIT, 2, (void*) &stcc4_driverData.I2C_DATA_RECEIVE, 1, &stcc4_driverData.I2C_TRANSFER_HANDLE);
}

void STCC4_DRIVER_Store_Factory_Reset_Result(void)
{
    stcc4_sensorData.FACTORY_RESET_RESULT = stcc4_driverData.I2C_DATA_RECEIVE[0];
}

void STCC4_DRIVER_Perform_Self_Test(uint8_t I2C_ADDRESS)
{
    stcc4_driverData.I2C_DATA_TRANSMIT[0] = STCC4_CMD_PERFORM_SELF_TEST_MSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[1] = STCC4_CMD_PERFORM_SELF_TEST_LSB;
    DRV_I2C_WriteReadTransferAdd(stcc4_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &stcc4_driverData.I2C_DATA_TRANSMIT, 2, (void*) &stcc4_driverData.I2C_DATA_RECEIVE, 2, &stcc4_driverData.I2C_TRANSFER_HANDLE);
}

void STCC4_DRIVER_Store_Self_Test_Result(void)
{
    stcc4_sensorData.SELF_TEST_RESULT = (uint16_t) stcc4_driverData.I2C_DATA_RECEIVE[0] << 8 | (uint16_t) stcc4_driverData.I2C_DATA_RECEIVE[1];
}

void STCC4_DRIVER_Enable_Testing_Mode(uint8_t I2C_ADDRESS)
{
    stcc4_driverData.I2C_DATA_TRANSMIT[0] = STCC4_CMD_ENABLE_TESTING_MODE_MSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[1] = STCC4_CMD_ENABLE_TESTING_MODE_LSB;
    DRV_I2C_WriteTransferAdd(stcc4_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &stcc4_driverData.I2C_DATA_TRANSMIT, 2, &stcc4_driverData.I2C_TRANSFER_HANDLE);
}

void STCC4_DRIVER_Disable_Testing_Mode(uint8_t I2C_ADDRESS)
{
    stcc4_driverData.I2C_DATA_TRANSMIT[0] = STCC4_CMD_DISABLE_TESTING_MODE_MSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[1] = STCC4_CMD_DISABLE_TESTING_MODE_LSB;
    DRV_I2C_WriteTransferAdd(stcc4_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &stcc4_driverData.I2C_DATA_TRANSMIT, 2, &stcc4_driverData.I2C_TRANSFER_HANDLE);
}

void STCC4_DRIVER_Perform_Forced_Recalibration(uint8_t I2C_ADDRESS, uint8_t CO2_TARGET_MSB, uint8_t CO2_TARGET_LSB)
{
    stcc4_driverData.I2C_DATA_TRANSMIT[0] = STCC4_CMD_PERFORM_FORCED_RECALIBRATION_MSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[1] = STCC4_CMD_PERFORM_FORCED_RECALIBRATION_LSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[2] = CO2_TARGET_MSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[3] = CO2_TARGET_LSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[4] = STCC4_DRIVER_Calculation_Array_CRC(CO2_TARGET_MSB, CO2_TARGET_LSB);
    DRV_I2C_WriteReadTransferAdd(stcc4_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &stcc4_driverData.I2C_DATA_TRANSMIT, 2, (void*) &stcc4_driverData.I2C_DATA_RECEIVE, 3, &stcc4_driverData.I2C_TRANSFER_HANDLE);
}

void STCC4_DRIVER_Store_Forced_Recalibration_Result(void)
{
    stcc4_sensorData.FORCED_RECALIBRATION_RESULT = (uint16_t) stcc4_driverData.I2C_DATA_RECEIVE[0] << 8 | (uint16_t) stcc4_driverData.I2C_DATA_RECEIVE[1];
}

void STCC4_DRIVER_Get_Product_ID(uint8_t I2C_ADDRESS)
{
    stcc4_driverData.I2C_DATA_TRANSMIT[0] = STCC4_CMD_GET_PRODUCT_ID_MSB;
    stcc4_driverData.I2C_DATA_TRANSMIT[1] = STCC4_CMD_GET_PRODUCT_ID_LSB;
    DRV_I2C_WriteReadTransferAdd(stcc4_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) stcc4_driverData.I2C_DATA_TRANSMIT, 2, (void*) stcc4_driverData.I2C_DATA_RECEIVE, 18, &stcc4_driverData.I2C_TRANSFER_HANDLE);
}

void STCC4_DRIVER_Store_Product_ID(void)
{
    stcc4_sensorData.PRODUCT_ID = (uint32_t) stcc4_driverData.I2C_DATA_RECEIVE[0] << 24 | (uint32_t) stcc4_driverData.I2C_DATA_RECEIVE[1] << 16 | (uint32_t) stcc4_driverData.I2C_DATA_RECEIVE[3] << 8 | (uint32_t) stcc4_driverData.I2C_DATA_RECEIVE[4];
    stcc4_sensorData.SERIAL_NUMBER = (uint64_t) stcc4_driverData.I2C_DATA_RECEIVE[6] << 56 | (uint64_t) stcc4_driverData.I2C_DATA_RECEIVE[7] << 48 | (uint64_t) stcc4_driverData.I2C_DATA_RECEIVE[9] << 40 | (uint64_t) stcc4_driverData.I2C_DATA_RECEIVE[10] << 32 | (uint64_t) stcc4_driverData.I2C_DATA_RECEIVE[12] << 24 | (uint64_t) stcc4_driverData.I2C_DATA_RECEIVE[13] << 16 | (uint64_t) stcc4_driverData.I2C_DATA_RECEIVE[15] << 8 | (uint64_t) stcc4_driverData.I2C_DATA_RECEIVE[16];
}

void STCC4_DRIVER_Calculation_Temperature(uint16_t T_VALUE)
{
    stcc4_sensorData.CELSIUS_TEMPERATURE = -45 + 175 * ((float) T_VALUE / 65535);
    stcc4_sensorData.FAHRENHEIT_TEMPERATURE = -49 + 315 * ((float) T_VALUE / 65535);
}

void STCC4_DRIVER_Calculation_Humidity(uint16_t H_VALUE)
{
    stcc4_sensorData.HUMIDITY = -6 + 125 * ((float) H_VALUE / 65535);
}

void STCC4_DRIVER_Calculation_CO2(uint16_t CO2_VALUE)
{
    stcc4_sensorData.CO2_PPM = (float) CO2_VALUE;
}

uint8_t STCC4_DRIVER_Calculation_CRC(uint8_t MESSAGE[], uint8_t MESSAGE_LENGTH)
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

uint8_t STCC4_DRIVER_Calculation_Array_CRC(uint8_t MESSAGE_0, uint8_t MESSAGE_1)
{
    uint8_t MESSAGE[2] = {MESSAGE_0, MESSAGE_1};
    return HDC302X_DRIVER_Calculation_CRC(MESSAGE, 2);
}

void STCC4_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)
{
    SYS_CONSOLE_Print
            (
             CONSOLE_HANDLE,
             "CO2: %.0f ppm\r\n"
             "Temperature: %.2f °C\r\n"
             "Humidity: %.2f %%\r\n"
             "Status: 0x%X\r\n",
             stcc4_sensorData.CO2_PPM,
             stcc4_sensorData.CELSIUS_TEMPERATURE,
             stcc4_sensorData.HUMIDITY,
             stcc4_sensorData.SENSOR_STATUS
             );
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void STCC4_DRIVER_Initialize(void)
{
    stcc4_driverData.state = STCC4_DRIVER_STATE_INIT;
    stcc4_driverData.I2C_HANDLE = DRV_HANDLE_INVALID;
    stcc4_driverData.I2C_TRANSFER_HANDLE = DRV_I2C_TRANSFER_HANDLE_INVALID;
}

void STCC4_DRIVER_Tasks(void)
{
    switch (stcc4_driverData.state)
    {
        case STCC4_DRIVER_STATE_INIT:
        {
            STCC4_DRIVER_Set_I2C_Address();
            stcc4_driverData.I2C_HANDLE = DRV_I2C_Open(DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE);
            stcc4_driverData.state = STCC4_DRIVER_STATE_CHECK_I2C_HANDLER;
            break;
        }

        case STCC4_DRIVER_STATE_CHECK_I2C_HANDLER:
        {
            if (stcc4_driverData.I2C_HANDLE == DRV_HANDLE_INVALID)
            {
                stcc4_driverData.state = STCC4_DRIVER_STATE_ERROR;
            }
            else
            {
                stcc4_driverData.state = STCC4_DRIVER_STATE_GET_PRODUCT_ID;
            }
            break;
        }

        case STCC4_DRIVER_STATE_GET_PRODUCT_ID:
        {
            STCC4_DRIVER_Get_Product_ID(stcc4_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            stcc4_driverData.state = STCC4_DRIVER_STATE_GET_PRODUCT_ID_WAIT_FOR_TRANSFER;
            break;
        }

        case STCC4_DRIVER_STATE_GET_PRODUCT_ID_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(stcc4_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                stcc4_driverData.state = STCC4_DRIVER_STATE_START_WAIT_TIMER;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                stcc4_driverData.state = STCC4_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case STCC4_DRIVER_STATE_STORE_PRODUCT_ID:
        {
            STCC4_DRIVER_Store_Product_ID();
            stcc4_driverData.state = STCC4_DRIVER_STATE_IDLE;
            break;
        }

        case STCC4_DRIVER_STATE_IDLE:
        {
            if (STCC4_DRIVER_Get_Task_Start_Status() == true)
            {
                stcc4_driverData.state = STCC4_DRIVER_STATE_START_SINGLE_SHOT_MEASUREMENT;
            }
            break;
        }

        case STCC4_DRIVER_STATE_START_SINGLE_SHOT_MEASUREMENT:
        {
            STCC4_DRIVER_Single_Shot_Measurement(stcc4_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            stcc4_driverData.state = STCC4_DRIVER_STATE_START_SINGLE_SHOT_MEASUREMENT_WAIT_FOR_TRANSFER;
            break;
        }

        case STCC4_DRIVER_STATE_START_SINGLE_SHOT_MEASUREMENT_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(stcc4_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                stcc4_driverData.state = STCC4_DRIVER_STATE_START_WAIT_TIMER;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                stcc4_driverData.state = STCC4_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case STCC4_DRIVER_STATE_START_WAIT_TIMER:
        {
            TIMER_DRIVER_Start_Wait_TMR();
            stcc4_driverData.state = STCC4_DRIVER_STATE_WAIT_FOR_MEASURE;
            break;
        }

        case STCC4_DRIVER_STATE_WAIT_FOR_MEASURE:
        {
            if (TIMER_DRIVER_Get_Wait_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Wait_TMR_Status(false);
                TIMER_DRIVER_Stop_Wait_TMR();
                stcc4_driverData.state = STCC4_DRIVER_STATE_GET_MEASURED_VALUES;
            }
            break;
        }

        case STCC4_DRIVER_STATE_GET_MEASURED_VALUES:
        {
            STCC4_DRIVER_Get_Measure_Values(stcc4_driverData.I2C_ADDRESS[0]);
            TIMER_DRIVER_Start_Bus_TMR();
            stcc4_driverData.state = STCC4_DRIVER_STATE_GET_MEASURED_VALUES_WAIT_FOR_TRANSFER;
            break;
        }

        case STCC4_DRIVER_STATE_GET_MEASURED_VALUES_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(stcc4_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                stcc4_driverData.state = STCC4_DRIVER_STATE_STORE_MEASURED_VALUES;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                stcc4_driverData.state = STCC4_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case STCC4_DRIVER_STATE_STORE_MEASURED_VALUES:
        {
            STCC4_DRIVER_Store_Measured_Values();
            stcc4_driverData.state = STCC4_DRIVER_STATE_CALCULATE_DATA;
            break;
        }

        case STCC4_DRIVER_STATE_CALCULATE_DATA:
        {
            STCC4_DRIVER_Calculation_CO2(stcc4_sensorData.CO2_VALUE);
            STCC4_DRIVER_Calculation_Temperature(stcc4_sensorData.T_VALUE);
            STCC4_DRIVER_Calculation_Humidity(stcc4_sensorData.H_VALUE);
            stcc4_driverData.state = STCC4_DRIVER_STATE_STORE_DATA;
            break;
        }

        case STCC4_DRIVER_STATE_STORE_DATA:
        {
            /* Add function for storing data */
            STCC4_DRIVER_Set_Task_Completed_Status(true);
            stcc4_driverData.state = STCC4_DRIVER_STATE_IDLE;
            break;
        }

        case STCC4_DRIVER_STATE_TIMER_EXPIRED:
        {
            DRV_I2C_Close(stcc4_driverData.I2C_HANDLE);
            STCC4_DRIVER_Set_Task_Completed_Status(true);
            stcc4_driverData.state = STCC4_DRIVER_STATE_IDLE;
            break;
        }

        case STCC4_DRIVER_STATE_ERROR:
        {
            DRV_I2C_Close(stcc4_driverData.I2C_HANDLE);
            STCC4_DRIVER_Set_Task_Completed_Status(true);
            stcc4_driverData.state = STCC4_DRIVER_STATE_IDLE;
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