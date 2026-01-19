/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    sht4x_driver.h

  Status:
    In development
 
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
#include <stdio.h>
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

#define SHT4X_CMD_MEASURE_TEMP_HUM_HIGH_PRECISION           0xFD
#define SHT4X_CMD_MEASURE_TEMP_HUM_MEDIUM_PRECISION         0xF6
#define SHT4X_CMD_MEASURE_TEMP_HUM_LOW_PRECISION            0xF0
#define SHT4X_CMD_SERIAL_NUMBER                             0x89
#define SHT4X_CMD_SOFT_RESET                                0x94
#define SHT4X_CMD_ACTIVATE_HEATER_200mW_1s                  0x39
#define SHT4X_CMD_ACTIVATE_HEATER_200mW_100ms               0x32
#define SHT4X_CMD_ACTIVATE_HEATER_110mW_1s                  0x2F
#define SHT4X_CMD_ACTIVATE_HEATER_110mW_100ms               0x24
#define SHT4X_CMD_ACTIVATE_HEATER_20mW_1s                   0x1E
#define SHT4X_CMD_ACTIVATE_HEATER_20mW_100ms                0x15

#define SHT4X_I2C_RX_BUFFER_SIZE                            8
#define SHT4X_I2C_TX_BUFFER_SIZE                            8

// *****************************************************************************

/** Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
 */

typedef enum
{
    SHT4X_DRIVER_STATE_INIT = 0,
    SHT4X_DRIVER_STATE_CHECK_I2C_HANDLER,
    SHT4X_DRIVER_STATE_IDLE,
    SHT4X_DRIVER_STATE_START_MEASURE,
    SHT4X_DRIVER_STATE_START_MEASURE_WAIT_FOR_TRANSFER,
    SHT4X_DRIVER_STATE_START_WAIT_TIMER,
    SHT4X_DRIVER_STATE_WAIT_FOR_MEASURE,
    SHT4X_DRIVER_STATE_GET_MEASURE_DATA,
    SHT4X_DRIVER_STATE_GET_MEASURE_DATA_WAIT_FOR_TRANSFER,
    SHT4X_DRIVER_STATE_STORE_MEASURED_VALUES,
    SHT4X_DRIVER_STATE_CALCULATE_DATA,
    SHT4X_DRIVER_STATE_STORE_DATA,
    SHT4X_DRIVER_STATE_TIMER_EXPIRED,
    SHT4X_DRIVER_STATE_ERROR,
} SHT4X_DRIVER_STATES;

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
    /* The application's current state */
    SHT4X_DRIVER_STATES state;

    /* Driver variables */
    DRV_HANDLE I2C_HANDLE;
    DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE;
    volatile bool SHT4X_TASK_START;
    volatile bool SHT4X_TASK_COMPLETED;
    uint8_t I2C_ADDRESS[3];
    uint8_t I2C_DATA_RECEIVE[SHT4X_I2C_RX_BUFFER_SIZE];
    uint8_t I2C_DATA_TRANSMIT[SHT4X_I2C_TX_BUFFER_SIZE];
} SHT4X_DRIVER_DATA;

typedef struct
{
    uint16_t T_VALUE;
    uint16_t H_VALUE;
    uint32_t SERIAL_NUMBER;
    float CELSIUS_TEMPERATURE;
    float FAHRENHEIT_TEMPERATURE;
    float HUMIDITY;
} SHT4X_DRIVER_SENSOR_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/**
    Function:
    void SHT4X_DRIVER_Initialize(void)

    Summary:
    Performs initialization of driver for SHT4X sensor.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void SHT4X_DRIVER_Initialize(void);

/**
    Function:
    void SHT4X_DRIVER_Tasks(void)

    Summary:
    Executes periodic driver tasks.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void SHT4X_DRIVER_Tasks(void);

/**
    Function:
    bool SHT4X_DRIVER_Get_Task_Start_Status(void)

    Summary:
    Retrieves the "TASK_START" flag.

    Parameters:
    None.

    Returns:
    @return bool - true if a task has been started otherwise is not

    Remarks:
    None.
 */
bool SHT4X_DRIVER_Get_Task_Start_Status(void);

/**
    Function:
    void SHT4X_DRIVER_Set_Task_Start_Status(bool STATUS)

    Summary:
    Sets the "TASK_START" flag

    Parameters:
    @param STATUS - desired state of the "TASK_START" flag

    Returns:
    None.

    Remarks:
    None.
 */
void SHT4X_DRIVER_Set_Task_Start_Status(bool STATUS);

/**
    Function:
    bool SHT4X_DRIVER_Get_Task_Completed_Status(void)

    Summary:
    Retrieves the "TASK_COMPLETED" flag.

    Parameters:
    None.

    Returns:
    @return bool - true if a task has been completed otherwise is not

    Remarks:
    None.
 */
bool SHT4X_DRIVER_Get_Task_Completed_Status(void);

/**
    Function:
    void SHT4X_DRIVER_Set_Task_Completed_Status(bool STATUS)

    Summary:
    Sets the "TASK_COMPLETED" flag

    Parameters:
    @param STATUS - desired state of the "TASK_COMPLETED" flag

    Returns:
    None.

    Remarks:
    None.
 */
void SHT4X_DRIVER_Set_Task_Completed_Status(bool STATUS);

/**
    Function:
    void SHT4X_DRIVER_Set_I2C_Address(void)

    Summary:
    Configures the I2C slave address for all sensor version.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    Use before performing any read or write.
 */
void SHT4X_DRIVER_Set_I2C_Address(void);

/**
    Function:
    void SHT4X_DRIVER_Start_Measurement(uint8_t I2C_ADDRESS, uint8_t SHT4X_REGISTER)

    Summary:
    Initiates a measurement by writing the desired command register.

    Parameters:
    @param I2C_ADDRESS - sensor address
    @param SHT4X_REGISTER - command byte for select measurement mode

    Returns:
    None.

    Remarks:
    Use delay before reading measured values.
 */
void SHT4X_DRIVER_Start_Measurement(uint8_t I2C_ADDRESS, uint8_t SHT4X_REGISTER);

/**
    Function:
    void SHT4X_DRIVER_Get_Measure_Values(uint8_t I2C_ADDRESS)

    Summary:
    Reads the raw temperature and humidity data from the sensor.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void SHT4X_DRIVER_Get_Measure_Values(uint8_t I2C_ADDRESS);

/**
    Function:
    void SHT4X_DRIVER_Store_Measured_Values(void)

    Summary:
    Store the raw values to variables.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    Use when a new measurement has been performed.
 */
void SHT4X_DRIVER_Store_Measured_Values(void);

/**
    Function:
    void SHT4X_DRIVER_Read_Serial_Number(uint8_t I2C_ADDRESS)

    Summary:
    Reads the serial number of the sensor.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void SHT4X_DRIVER_Read_Serial_Number(uint8_t I2C_ADDRESS);

/**
    Function:
    void SHT4X_DRIVER_Store_Serial_Number(void)

    Summary:
    Store a serial number into variable.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void SHT4X_DRIVER_Store_Serial_Number(void);

/**
    Function:
    void SHT4X_DRIVER_Soft_Reset(uint8_t I2C_ADDRESS)

    Summary:
    Perform a soft reset to the sensor.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void SHT4X_DRIVER_Soft_Reset(uint8_t I2C_ADDRESS);

/**
    Function:
    void SHT4X_DRIVER_Calculation_Temperature(uint16_t T_VALUE)

    Summary:
    Converts the raw temperature value to degrees Celsius and degrees Fahrenheit.

    Parameters:
    @param T_VALUE - raw temperature value from the sensor

    Returns:
    None.

    Remarks:
    Equation is in the datasheet.
 */
void SHT4X_DRIVER_Calculation_Temperature(uint16_t T_VALUE);

/**
    Function:
    void SHT4X_DRIVER_Calculation_Humidity(uint16_t H_VALUE)

    Summary:
    Converts the raw humidity value to percent.

    Parameters:
    @param T_VALUE - raw temperature value from the sensor

    Returns:
    None.

    Remarks:
    Equation is in the datasheet.
 */
void SHT4X_DRIVER_Calculation_Humidity(uint16_t H_VALUE);

/**
    Function:
    void SHT4X_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)

    Summary:
    Prints the text to a console.

    Parameters:
    @param CONSOLE_HANDLE - console handle returned by the library

    Returns:
    None.

    Remarks:
    For reading a text use TeraTerm, CoolTerm, etc.
 */
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