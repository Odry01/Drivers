/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    hdc302x_driver.h

  Status:
    In development
 
  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "HDC302X_DRIVER_Initialize" and "HDC302X_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "HDC302X_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _HDC302X_DRIVER_H
#define _HDC302X_DRIVER_H

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

#define HDC302X_CMD_MODE_TRIG_MSB               0x24
#define HDC302X_CMD_MODE_TRIG_LPM0              0x00
#define HDC302X_CMD_MODE_TRIG_LPM1              0x0B
#define HDC302X_CMD_MODE_TRIG_LPM2              0x16
#define HDC302X_CMD_MODE_TRIG_LPM3              0xFF
#define HDC302X_CMD_MODE_A2S_MSB                0x20
#define HDC302X_CMD_MODE_A2S_LPM0               0x32
#define HDC302X_CMD_MODE_A2S_LPM1               0x24
#define HDC302X_CMD_MODE_A2S_LPM2               0x2F
#define HDC302X_CMD_MODE_A2S_LPM3               0xFF
#define HDC302X_CMD_MODE_A1HZ_MSB               0x21
#define HDC302X_CMD_MODE_A1HZ_LPM0              0x30
#define HDC302X_CMD_MODE_A1HZ_LPM1              0x26
#define HDC302X_CMD_MODE_A1HZ_LPM2              0x2D
#define HDC302X_CMD_MODE_A1HZ_LPM3              0xFF
#define HDC302X_CMD_MODE_A2HZ_MSB               0x22
#define HDC302X_CMD_MODE_A2HZ_LPM0              0x36
#define HDC302X_CMD_MODE_A2HZ_LPM1              0x20
#define HDC302X_CMD_MODE_A2HZ_LPM2              0x2B
#define HDC302X_CMD_MODE_A2HZ_LPM3              0xFF
#define HDC302X_CMD_MODE_A4HZ_MSB               0x23
#define HDC302X_CMD_MODE_A4HZ_LPM0              0x34
#define HDC302X_CMD_MODE_A4HZ_LPM1              0x22
#define HDC302X_CMD_MODE_A4HZ_LPM2              0x29
#define HDC302X_CMD_MODE_A4HZ_LPM3              0xFF
#define HDC302X_CMD_MODE_A10HZ_MSB              0x27
#define HDC302X_CMD_MODE_A10HZ_LPM0             0x37
#define HDC302X_CMD_MODE_A10HZ_LPM1             0x21
#define HDC302X_CMD_MODE_A10HZ_LPM2             0x2A
#define HDC302X_CMD_MODE_A10HZ_LPM3             0xFF
#define HDC302X_CMD_MODE_READ_MSB               0xE0
#define HDC302X_CMD_MODE_READ                   0x00
#define HDC302X_CMD_MODE_READ_MIN_T             0x02
#define HDC302X_CMD_MODE_READ_MAX_T             0x03
#define HDC302X_CMD_MODE_READ_MIN_H             0x04
#define HDC302X_CMD_MODE_READ_MAX_H             0x05
#define HDC302X_CMD_WR_ALERT_MSB                0x61
#define HDC302X_CMD_WR_ALERT_SET_LO             0x00
#define HDC302X_CMD_WR_ALERT_SET_HI             0x1D
#define HDC302X_CMD_WR_ALERT_CLR_LO             0x0B
#define HDC302X_CMD_WR_ALERT_CLR_HI             0x16
#define HDC302X_CMD_RD_ALERT_MSB                0xE1
#define HDC302X_CMD_RD_ALERT_SET_LO             0x02
#define HDC302X_CMD_RD_ALERT_SET_HI             0x1F
#define HDC302X_CMD_RD_ALERT_CLR_LO             0x09
#define HDC302X_CMD_RD_ALERT_CLR_HI             0x14
#define HDC302X_CMD_HEATER_MSB                  0x30
#define HDC302X_CMD_HEATER_ENABLE               0x6D
#define HDC302X_CMD_HEATER_DISABLE              0x66
#define HDC302X_CMD_HEATER_CFG                  0x6E
#define HDC302X_CMD_STATUS_READ_MSB             0xF3
#define HDC302X_CMD_STATUS_READ_LSB             0x2D
#define HDC302X_CMD_STATUS_CLEAR_MSB            0x30
#define HDC302X_CMD_STATUS_CLEAR_LSB            0x41
#define HDC302X_CMD_OFFSET_MSB                  0xA0
#define HDC302X_CMD_OFFSET_LSB                  0x04
#define HDC302X_CMD_SOFT_RESET_MSB              0x30
#define HDC302X_CMD_SOFT_RESET_LSB              0xA2
#define HDC302X_CMD_RD_NIST_MSB                 0x36
#define HDC302X_CMD_RD_NIST_3                   0x83
#define HDC302X_CMD_RD_NIST_2                   0x84
#define HDC302X_CMD_RD_NIST_1                   0x85
#define HDC302X_CMD_RD_MID_MSB                  0x37
#define HDC302X_CMD_RD_MID_LSB                  0x80
#define HDC302X_CMD_WR_POR_MODE_MSB             0x61
#define HDC302X_CMD_WR_POR_MODE_LSB             0xBB
#define HDC302X_CMD_POR_MODE_MSB                0x00
#define HDC302X_CMD_POR_MODE_A2S_LPM0           0x03
#define HDC302X_CMD_POR_MODE_A2S_LPM1           0x13
#define HDC302X_CMD_POR_MODE_A2S_LPM2           0x23
#define HDC302X_CMD_POR_MODE_A2S_LPM3           0x33
#define HDC302X_CMD_POR_MODE_A1HZ_LPM0          0x05
#define HDC302X_CMD_POR_MODE_A1HZ_LPM1          0x15
#define HDC302X_CMD_POR_MODE_A1HZ_LPM2          0x25
#define HDC302X_CMD_POR_MODE_A1HZ_LPM3          0x35
#define HDC302X_CMD_POR_MODE_A2HZ_LPM0          0x07
#define HDC302X_CMD_POR_MODE_A2HZ_LPM1          0x17
#define HDC302X_CMD_POR_MODE_A2HZ_LPM2          0x27
#define HDC302X_CMD_POR_MODE_A2HZ_LPM3          0x37
#define HDC302X_CMD_POR_MODE_A4HZ_LPM0          0x09
#define HDC302X_CMD_POR_MODE_A4HZ_LPM1          0x19
#define HDC302X_CMD_POR_MODE_A4HZ_LPM2          0x29
#define HDC302X_CMD_POR_MODE_A4HZ_LPM3          0x39
#define HDC302X_CMD_POR_MODE_A10HZ_LPM0         0x0B
#define HDC302X_CMD_POR_MODE_A10HZ_LPM1         0x1B
#define HDC302X_CMD_POR_MODE_A10HZ_LPM2         0x2B
#define HDC302X_CMD_POR_MODE_A10HZ_LPM3         0x3B
#define HDC302X_CMD_POR_MODE_SLEEP              0x00

#define HDC302X_I2C_RX_BUFFER_SIZE              8
#define HDC302X_I2C_TX_BUFFER_SIZE              8

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
    HDC302X_DRIVER_STATE_INIT = 0,
    HDC302X_DRIVER_STATE_CHECK_I2C_HANDLER,
    HDC302X_DRIVER_STATE_SET_CONFIGURATION,
    HDC302X_DRIVER_STATE_ENTER_AUTO_MEASUREMENT_MODE,
    HDC302X_DRIVER_STATE_ENTER_AUTO_MEASUREMENT_MODE_WAIT_FOR_TRANSFER,
    HDC302X_DRIVER_STATE_IDLE,
    HDC302X_DRIVER_STATE_GET_AUTO_MEASURE_VALUES,
    HDC302X_DRIVER_STATE_GET_AUTO_MEASURE_VALUES_WAIT_FOR_TRANSFER,
    HDC302X_DRIVER_STATE_STORE_MEASURE_VALUES,
    HDC302X_DRIVER_STATE_CALCULATE_DATA,
    HDC302X_DRIVER_STATE_STORE_VALUES,
    HDC302X_DRIVER_STATE_TIMER_EXPIRED,
    HDC302X_DRIVER_STATE_ERROR,
} HDC302X_DRIVER_STATES;

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
    HDC302X_DRIVER_STATES state;

    /* Driver variables */
    DRV_HANDLE I2C_HANDLE;
    DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE;
    volatile bool HDC302X_TASK_START;
    volatile bool HDC302X_TASK_COMPLETED;
    volatile bool HDC302X_ALERT;
    uint8_t I2C_ADDRESS[4];
    uint8_t I2C_DATA_RECEIVE[HDC302X_I2C_RX_BUFFER_SIZE];
    uint8_t I2C_DATA_TRANSMIT[HDC302X_I2C_TX_BUFFER_SIZE];
} HDC302X_DRIVER_DATA;

typedef struct
{
    uint8_t NIST_VALUE_5;
    uint8_t NIST_VALUE_4;
    uint8_t NIST_VALUE_3;
    uint8_t NIST_VALUE_2;
    uint8_t NIST_VALUE_1;
    uint8_t NIST_VALUE_0;
    uint16_t OFFSET;
    uint16_t SET_HIGH_ALERT;
    uint16_t CLEAR_HIGH_ALERT;
    uint16_t SET_LOW_ALERT;
    uint16_t CLEAR_LOW_ALERT;
    uint16_t STATUS;
    uint16_t T_VALUE;
    uint16_t H_VALUE;
    float CELSIUS_TEMPERATURE;
    float FAHRENHEIT_TEMPERATURE;
    float HUMIDITY;
} HDC302X_SENSOR_DATA;

typedef struct
{
    uint8_t MODE_MSB;
    uint8_t MODE_LSB;
    uint8_t OFFSET_MSB;
    uint8_t OFFSET_LSB;
    uint8_t SET_HIGH_ALERT_MSB;
    uint8_t SET_HIGH_ALERT_LSB;
    uint8_t CLEAR_HIGH_ALERT_MSB;
    uint8_t CLEAR_HIGH_ALERT_LSB;
    uint8_t SET_LOW_ALERT_MSB;
    uint8_t SET_LOW_ALERT_LSB;
    uint8_t CLEAR_LOW_ALERT_MSB;
    uint8_t CLEAR_LOW_ALERT_LSB;
} HDC302X_SENSOR_SETTINGS;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

void HDC302X_DRIVER_Alert(uintptr_t CONTEXT);

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/**
    Function:
    void HDC302X_DRIVER_Initialize(void)

    Summary:
    Performs initialization of driver for HDC302X sensor.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Initialize(void);

/**
    Function:
    void HDC302X_DRIVER_Tasks(void)

    Summary:
    Executes periodic tasks.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Tasks(void);

/**
    Function:
    bool HDC302X_DRIVER_Get_Task_Start_Status(void)

    Summary:
    Retrieves the "TASK_START" flag.

    Parameters:
    None.

    Returns:
    @return bool - true if a task has been started otherwise is not

    Remarks:
    None.
 */
bool HDC302X_DRIVER_Get_Task_Start_Status(void);

/**
    Function:
    void HDC302X_DRIVER_Set_Task_Start_Status(bool STATUS)

    Summary:
    Sets the "TASK_START" flag

    Parameters:
    @param STATUS - desired state of the "TASK_START" flag

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Set_Task_Start_Status(bool STATUS);

/**
    Function:
    bool HDC302X_DRIVER_Get_Task_Completed_Status(void)

    Summary:
    Retrieves the "TASK_COMPLETED" flag.

    Parameters:
    None.

    Returns:
    @return bool - true if a task has been completed otherwise is not

    Remarks:
    None.
 */
bool HDC302X_DRIVER_Get_Task_Completed_Status(void);

/**
    Function:
    void HDC302X_DRIVER_Set_Task_Completed_Status(bool STATUS)

    Summary:
    Sets the "TASK_COMPLETED" flag

    Parameters:
    @param STATUS - desired state of the "TASK_COMPLETED" flag

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Set_Task_Completed_Status(bool STATUS);

/**
    Function:
    bool HDC302X_DRIVER_Get_Alert_Status(void)

    Summary:
    Retrieves the "HDC302X_ALERT" flag.

    Parameters:
    None.

    Returns:
    @return bool - true if a alert has been ocured otherwise is not

    Remarks:
    None.
 */
bool HDC302X_DRIVER_Get_Alert_Status(void);

/**
    Function:
    void HDC302X_DRIVER_Set_Alert_Status(bool STATUS)

    Summary:
    Sets the "HDC302X_ALERT" flag

    Parameters:
    @param STATUS - desired state of the "HDC302X_ALERT" flag

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Set_Alert_Status(bool STATUS);

/**
    Function:
    void HDC302X_DRIVER_Set_I2C_Address(void)

    Summary:
    Configures the I2C slave address for all sensor version.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    Use before performing any read or write.
 */
void HDC302X_DRIVER_Set_I2C_Address(void);

/**
    Function:
    void HDC302X_DRIVER_Get_Offset_Values(uint8_t I2C_ADDRESS)

    Summary:
    Reads the temperature and humidity offset registers from the sensor.

    Parameters:
    @param I2C_ADDRESS - sensor address from which to read

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Get_Offset_Values(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Store_Offset_Values(void)

    Summary:
    Stores the offset values into variables.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Store_Offset_Values(void);

/**
    Function:
    void HDC302X_DRIVER_Set_Offset_Values(uint8_t I2C_ADDRESS)

    Summary:
    Writes offset values to sensor.

    Parameters:
    @param I2C_ADDRESS - sensor address where offsets are written

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Set_Offset_Values(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Get_Set_High_Alert(uint8_t I2C_ADDRESS)

    Summary:
    Reads the high alert threshold from the sensor.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Get_Set_High_Alert(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Store_Set_High_Alert(void)

    Summary:
    Stores the high alert threshold.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Store_Set_High_Alert(void);

/**
    Function:
    void HDC302X_DRIVER_Set_Set_High_Alert(uint8_t I2C_ADDRESS)

    Summary:
    Writes the high alert threshold to the sensor.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Set_Set_High_Alert(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Get_Clear_High_Alert(uint8_t I2C_ADDRESS)

    Summary:
    Reads the clear high alert threshold from the sensor.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Get_Clear_High_Alert(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Store_Clear_High_Alert(void)

    Summary:
    Stores the clear high alert threshold from the sensor.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Store_Clear_High_Alert(void);

/**
    Function:
    void HDC302X_DRIVER_Set_Clear_High_Alert(uint8_t I2C_ADDRESS)

    Summary:
    Writes the clear high alert threshold to the sensor.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Set_Clear_High_Alert(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Get_Set_Low_Alert(uint8_t I2C_ADDRESS)

    Summary:
    Reads the low alert threshold from the sensor.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Get_Set_Low_Alert(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Store_Set_Low_Alert(void)

    Summary:
    Stores the low alert threshold from the sensor.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Store_Set_Low_Alert(void);

/**
    Function:
    void HDC302X_DRIVER_Set_Set_Low_Alert(uint8_t I2C_ADDRESS)

    Summary:
    Writes the low alert threshold to the sensor.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Set_Set_Low_Alert(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Get_Clear_Low_Alert(uint8_t I2C_ADDRESS)

    Summary:
    Reads the clear low alert threshold from the sensor.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Get_Clear_Low_Alert(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Store_Clear_Low_Alert(void)

    Summary:
    Stores the clear alert threshold from the sensor.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Store_Clear_Low_Alert(void);

/**
    Function:
    void HDC302X_DRIVER_Set_Clear_Low_Alert(uint8_t I2C_ADDRESS)

    Summary:
    Writes the clear‑low‑alert thresholds to the sensor.

    Parameters:
    @param I2C_ADDRESS - sensor address where thresholds are written

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Set_Clear_Low_Alert(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Enter_Auto_Measurement_Mode(uint8_t I2C_ADDRESS)

    Summary:
    Configures the sensor to perform continuous, automatic
    temperature and humidity measurements.

    Parameters:
    @param I2C_ADDRESS - sensor address to configure

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Enter_Auto_Measurement_Mode(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Exit_Auto_Measurement_Mode(uint8_t I2C_ADDRESS)

    Summary:
    Stops automatic sampling and returns the sensor to
    manual‑measurement mode.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Exit_Auto_Measurement_Mode(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Start_Manual_Measurement(uint8_t I2C_ADDRESS)

    Summary:
    Triggers a single temperature/humidity measurement.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Start_Manual_Measurement(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Get_Manual_Measure_Values(uint8_t I2C_ADDRESS)

    Summary:
    Reads the raw temperature and humidity values from a
    manual measurement.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Get_Manual_Measure_Values(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Get_Auto_Measure_Values(uint8_t I2C_ADDRESS)

    Summary:
    Retrieves the most recent measurement taken in auto‑mode.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Get_Auto_Measure_Values(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Store_Measurement_Values(void)

    Summary:
    Persists the latest temperature and humidity measurement
    to non‑volatile memory.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Store_Measurement_Values(void);

/**
    Function:
    void HDC302X_DRIVER_Get_Minimum_Temperature_Value(uint8_t I2C_ADDRESS)

    Summary:
    Reads the sensor’s minimum‑temperature register.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Get_Minimum_Temperature_Value(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Store_Minimum_Temperature_Value(void)

    Summary:
    Persists the cached minimum‑temperature value to non‑volatile memory.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Store_Minimum_Temperature_Value(void);

/**
    Function:
    void HDC302X_DRIVER_Get_Maximum_Temperature_Value(uint8_t I2C_ADDRESS)

    Summary:
    Reads the sensor’s maximum‑temperature register.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Get_Maximum_Temperature_Value(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Store_Maximum_Temperature_Value(void)

    Summary:
    Persists the cached maximum‑temperature value to non‑volatile memory.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Store_Maximum_Temperature_Value(void);

/**
    Function:
    void HDC302X_DRIVER_Get_Minimum_Humidity_Value(uint8_t I2C_ADDRESS)

    Summary:
    Reads the sensor’s minimum‑humidity register.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Get_Minimum_Humidity_Value(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Store_Minimum_Humidity_Value(void)

    Summary:
    Persists the cached minimum‑humidity value to non‑volatile memory.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Store_Minimum_Humidity_Value(void);

/**
    Function:
    void HDC302X_DRIVER_Get_Maximum_Humidity_Value(uint8_t I2C_ADDRESS)

    Summary:
    Reads the sensor’s maximum‑humidity register.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Get_Maximum_Humidity_Value(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Store_Maximum_Humidity_Value(void)

    Summary:
    Persists the cached maximum‑humidity value to non‑volatile memory.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Store_Maximum_Humidity_Value(void);

/**
    Function:
    void HDC302X_DRIVER_Calculation_Temperature(uint16_t T_VALUE)

    Summary:
    Converts a raw temperature register value to degrees Celsius.

    Parameters:
    @param T_VALUE - raw 16‑bit temperature reading from the sensor

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Calculation_Temperature(uint16_t T_VALUE);

/**
    Function:
    void HDC302X_DRIVER_Calculation_Humidity(uint16_t H_VALUE)

    Summary:
    Converts a raw humidity register value to percent relative humidity.

    Parameters:
    @param H_VALUE - raw 16 bit humidity reading from the sensor

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Calculation_Humidity(uint16_t H_VALUE);

/**
    Function:
    void HDC302X_DRIVER_Get_Sensor_Status(uint8_t I2C_ADDRESS)

    Summary:
    Reads the sensor’s status register.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Get_Sensor_Status(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Store_Sensor_Status(void)

    Summary:
    Persists the cached sensor status byte to non‑volatile memory.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Store_Sensor_Status(void);

/**
    Function:
    void HDC302X_DRIVER_Get_NIST_3(uint8_t I2C_ADDRESS)

    Summary:
    Reads the third NIST calibration register from the sensor.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Get_NIST_3(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Store_NIST_3(void)

    Summary:
    Persists the cached NIST3 value to non‑volatile memory.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Store_NIST_3(void);

/**
    Function:
    void HDC302X_DRIVER_Get_NIST_2(uint8_t I2C_ADDRESS)

    Summary:
    Reads the second NIST calibration register from the sensor.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Get_NIST_2(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Store_NIST_2(void)

    Summary:
    Persists the cached NIST2 value to non‑volatile memory.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Store_NIST_2(void);

/**
    Function:
    void HDC302X_DRIVER_Get_NIST_1(uint8_t I2C_ADDRESS)

    Summary:
    Reads the first NIST calibration register from the sensor.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Get_NIST_1(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Store_NIST_1(void)

    Summary:
    Persists the cached NIST1 value to non‑volatile memory.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Store_NIST_1(void);

/**
    Function:
    void HDC302X_DRIVER_Soft_Reset(uint8_t I2C_ADDRESS)

    Summary:
    Sends the soft‑reset command to the sensor.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Soft_Reset(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Enable_Heater(uint8_t I2C_ADDRESS)

    Summary:
    Activates the on‑chip heater.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Enable_Heater(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Disable_Heater(uint8_t I2C_ADDRESS)

    Summary:
    Deactivates the on‑chip heater.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Disable_Heater(uint8_t I2C_ADDRESS);

/**
    Function:
    void HDC302X_DRIVER_Configuration_Heater(uint8_t I2C_ADDRESS, uint8_t CURRENT_MSB, uint8_t CURRENT_LSB)

    Summary:
    Configures the heater current by writing two bytes.

    Parameters:
    @param I2C_ADDRESS   - sensor address
    @param CURRENT_MSB   - most‑significant byte of desired current
    @param CURRENT_LSB   - least‑significant byte of desired current

    Returns:
    None.

    Remarks:
    None.
 */
void HDC302X_DRIVER_Configuration_Heater(uint8_t I2C_ADDRESS, uint8_t CURRENT_MSB, uint8_t CURRENT_LSB);

/**
    Function:
    uint8_t HDC302X_DRIVER_Calculation_CRC(uint8_t MESSAGE[], uint8_t MESSAGE_LENGTH)

    Summary:
    Computes the 8‑bit CRC for a message buffer.

    Parameters:
    @param MESSAGE         - pointer to message buffer
    @param MESSAGE_LENGTH  - number of bytes over which to compute CRC

    Returns:
    @return uint8_t - calculated CRC value

    Remarks:
    None.
 */
uint8_t HDC302X_DRIVER_Calculation_CRC(uint8_t MESSAGE[], uint8_t MESSAGE_LENGTH);

/**
    Function:
    uint8_t HDC302X_DRIVER_Calculation_Array_CRC(uint8_t MESSAGE_0, uint8_t MESSAGE_1)

    Summary:
    Computes the CRC for a two byte message.

    Parameters:
    @param MESSAGE_0 - first byte of the message
    @param MESSAGE_1 - second byte of the message

    Returns:
    @return uint8_t - calculated CRC value

    Remarks:
    None.
 */
uint8_t HDC302X_DRIVER_Calculation_Array_CRC(uint8_t MESSAGE_0, uint8_t MESSAGE_1);

/**
    Function:
    HDC302X_DRIVER_Set_Offset_Code

    Summary:
    Converts temperature and humidity values into offset codes.

    Parameters:
    @param TEMPERATURE - raw temperature value
    @param HUMIDITY   - raw humidity value

    Returns:
    @return uint16_t - computed offset code

    Remarks:
    None.
 */
uint16_t HDC302X_DRIVER_Set_Offset_Code(uint16_t TEMPERATURE, uint16_t HUMIDITY);

/**
    Function:
    uint16_t HDC302X_DRIVER_Set_Alert_Code(uint16_t TEMPERATURE, uint16_t HUMIDITY)

    Summary:
    Converts temperature and humidity values into alert codes.

    Parameters:
    @param TEMPERATURE - raw temperature value
    @param HUMIDITY   - raw humidity value

    Returns:
    @return uint16_t - computed alert code

    Remarks:
    None.
 */
uint16_t HDC302X_DRIVER_Set_Alert_Code(uint16_t TEMPERATURE, uint16_t HUMIDITY);

/**
    Function:
    void HDC302X_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)

    Summary:
    Prints the text to a console.

    Parameters:
    @param CONSOLE_HANDLE - console handle returned by the library

    Returns:
    None.

    Remarks:
    For reading a text use TeraTerm, CoolTerm, etc.
 */
void HDC302X_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _HDC302X_DRIVER_H */

/*******************************************************************************
 End of File
 */