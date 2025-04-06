/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    sht4x_driver.c

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
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the SHT4X_DRIVER_Initialize function.

    Application strings and buffers are be defined outside this structure.
 */

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

void SHT4X_DRIVER_Measurement_Readout_Write(uint8_t I2C_ADDRESS, uint8_t SHT4X_REGISTER)
{
    sht4x_driverData.I2C_DATA_TRANSMIT[0] = SHT4X_REGISTER;
    DRV_I2C_WriteTransferAdd(sht4x_driverData.I2C_HANDLE, I2C_ADDRESS, &sht4x_driverData.I2C_DATA_TRANSMIT, 1, &sht4x_driverData.I2C_TRANSFER_HANDLE);
}

void SHT4X_DRIVER_Measurement_Readout_Read(uint8_t I2C_ADDRESS)
{
    DRV_I2C_ReadTransferAdd(sht4x_driverData.I2C_HANDLE, I2C_ADDRESS, &sht4x_driverData.I2C_DATA_RECEIVE, 6, &sht4x_driverData.I2C_TRANSFER_HANDLE);
}

void SHT4X_DRIVER_Measurement_Readout_Store_Values(void)
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

void SHT4X_DRIVER_Temperature_Calculation(void)
{
    sht4x_driverData.CELSIUS_TEMPERATURE = -45 + 175 * ((float) sht4x_sensorData.T_VALUE / 65535);
    sht4x_driverData.FAHRENHEIT_TEMPERATURE = -49 + 315 * ((float) sht4x_sensorData.T_VALUE / 65535);
}

void SHT4X_DRIVER_Humidity_Calculation(void)
{
    sht4x_driverData.HUMIDITY = -6 + 125 * ((float) sht4x_sensorData.H_VALUE / 65535);
}

void SHT4X_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)
{
    SYS_CONSOLE_Print
            (
             CONSOLE_HANDLE,
             "Temperature: %.2f  C\r\n"
             "Temperature: %.2f  F\r\n"
             "Humidity: %.2f %%\r\n",
             sht4x_driverData.CELSIUS_TEMPERATURE,
             sht4x_driverData.FAHRENHEIT_TEMPERATURE,
             sht4x_driverData.HUMIDITY
             );
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void SHT4X_DRIVER_Initialize ( void )

  Remarks:
    See prototype in sht4x_driver.h.
 */

void SHT4X_DRIVER_Initialize(void)
{
    sht4x_driverData.I2C_HANDLE = DRV_HANDLE_INVALID;
    sht4x_driverData.I2C_TRANSFER_HANDLE = DRV_I2C_TRANSFER_HANDLE_INVALID;
    sht4x_driverData.I2C_TRANSFER_STATUS = false;
}

/*******************************************************************************
 End of File
 */