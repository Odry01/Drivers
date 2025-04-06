/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    sht4x_driver.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "SHT4X_DRIVER_Initialize" and "SHT4X_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "SHT4X_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _SHT4X_DRIVER_H
#define _SHT4X_DRIVER_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"
#include "definitions.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C"
{

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

#define SHT4X_I2C_ADDRESS                               0x44
#define SHT4X_MEASURE_TEMP_HUM_HIGH_PRECISION           0xFD
#define SHT4X_MEASURE_TEMP_HUM_MEDIUM_PRECISION         0xF6
#define SHT4X_MEASURE_TEMP_HUM_LOW_PRECISION            0xF0
#define SHT4X_SERIAL_NUMBER                             0x89
#define SHT4X_SOFT_RESET                                0x94
#define SHT4X_ACTIVATE_HEATER_200mW_1s                  0x39
#define SHT4X_ACTIVATE_HEATER_200mW_100ms               0x32
#define SHT4X_ACTIVATE_HEATER_110mW_1s                  0x2F
#define SHT4X_ACTIVATE_HEATER_110mW_100ms               0x24
#define SHT4X_ACTIVATE_HEATER_20mW_1s                   0x1E
#define SHT4X_ACTIVATE_HEATER_20mW_100ms                0x15
#define SHT4X_I2C_RX_BUFFER_SIZE                        8
#define SHT4X_I2C_TX_BUFFER_SIZE                        8

// *****************************************************************************

/** Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* Driver variables */
    DRV_HANDLE I2C_HANDLE;
    DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE;
    bool I2C_TRANSFER_STATUS;
    bool SHT4X_TASK_START;
    bool SHT4X_TASK_COMPLETED;
    uint8_t I2C_DATA_RECEIVE[SHT4X_I2C_RX_BUFFER_SIZE];
    uint8_t I2C_DATA_TRANSMIT[SHT4X_I2C_TX_BUFFER_SIZE];
    float CELSIUS_TEMPERATURE;
    float FAHRENHEIT_TEMPERATURE;
    float HUMIDITY;
} SHT4X_DRIVER_DATA;

typedef struct
{
    uint16_t T_VALUE;
    uint16_t H_VALUE;
    uint32_t SERIAL_NUMBER;
} SHT4X_DRIVER_SENSOR_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

void SHT4X_DRIVER_I2C_Callback(DRV_I2C_TRANSFER_EVENT EVENT, DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE, uintptr_t CONTEXT);

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/** SHT4X_DRIVER_Initialize

Summary:
Initialize the SHT4X sensor driver.

Description:
This function initializes the SHT4X sensor driver, configuring it for sensor communication.

Parameters:
None.

Remarks:
Call this function once at the start of the application to prepare the SHT4X sensor for use.
 */
void SHT4X_DRIVER_Initialize(void);

bool SHT4X_DRIVER_Get_Task_Start_Status(void);

void SHT4X_DRIVER_Set_Task_Start_Status(bool STATUS);

bool SHT4X_DRIVER_Get_Task_Completed_Status(void);

void SHT4X_DRIVER_Set_Task_Completed_Status(bool STATUS);

void SHT4X_DRIVER_Measurement_Readout_Write(uint8_t I2C_ADDRESS, uint8_t SHT4X_REGISTER);

void SHT4X_DRIVER_Measurement_Readout_Read(uint8_t I2C_ADDRESS);

void SHT4X_DRIVER_Measurement_Readout_Store_Values(void);

void SHT4X_DRIVER_Read_Serial_Number(uint8_t I2C_ADDRESS);

void SHT4X_DRIVER_Store_Serial_Number(void);

void SHT4X_DRIVER_Soft_Reset(uint8_t I2C_ADDRESS);

void SHT4X_DRIVER_Temperature_Calculation(void);

void SHT4X_DRIVER_Humidity_Calculation(void);

void SHT4X_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _SHT4X_DRIVER_H */

/*******************************************************************************
 End of File
 */