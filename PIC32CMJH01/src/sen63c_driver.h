/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    sen63c_driver.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "SEN63C_DRIVER_Initialize" and "SEN63C_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "SEN63C_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _SEN63C_DRIVER_H
#define _SEN63C_DRIVER_H

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

#define SEN63C_CMD_START_MEASUREMENT_MSB                            0x00
#define SEN63C_CMD_START_MEASUREMENT_LSB                            0x21

#define SEN63C_CMD_STOP_MEASUREMENT_MSB                             0x01
#define SEN63C_CMD_STOP_MEASUREMENT_LSB                             0x04

#define SEN63C_CMD_GET_DATA_READY_MSB                               0x02
#define SEN63C_CMD_GET_DATA_READY_LSB                               0x02

#define SEN63C_CMD_READ_MEASURED_VALUES_MSB                         0x04
#define SEN63C_CMD_READ_MEASURED_VALUES_LSB                         0x71

#define SEN63C_CMD_READ_MEASURED_RAW_VALUES_MSB                     0x04
#define SEN63C_CMD_READ_MEASURED_RAW_VALUES_LSB                     0x92

#define SEN63C_CMD_READ_NUMBER_CONCENTRATION_VALUES_MSB             0x03
#define SEN63C_CMD_READ_NUMBER_CONCENTRATION_VALUES_LSB             0x16

#define SEN63C_CMD_SET_TEMPERATURE_OFFSET_PARAMETERS_MSB            0x60
#define SEN63C_CMD_SET_TEMPERATURE_OFFSET_PARAMETERS_LSB            0xB2

#define SEN63C_CMD_SET_TEMPERATURE_ACCELERATION_PARAMETERS_MSB      0x61
#define SEN63C_CMD_SET_TEMPERATURE_ACCELERATION_PARAMETERS_LSB      0x00

#define SEN63C_CMD_GET_PRODUCT_NAME_MSB                             0xD0
#define SEN63C_CMD_GET_PRODUCT_NAME_LSB                             0x14

#define SEN63C_CMD_GET_SERIAL_NUMBER_MSB                            0xD0
#define SEN63C_CMD_GET_SERIAL_NUMBER_LSB                            0x33

#define SEN63C_CMD_READ_DEVICE_STATUS_MSB                           0xD2
#define SEN63C_CMD_READ_DEVICE_STATUS_LSB                           0x06

#define SEN63C_CMD_READ_AND_CLEAR_DEVICE_STATUS_MSB                 0xD2
#define SEN63C_CMD_READ_AND_CLEAR_DEVICE_STATUS_LSB                 0x10

#define SEN63C_CMD_GET_VERSION_MSB                                  0xD1
#define SEN63C_CMD_GET_VERSION_LSB                                  0x00

#define SEN63C_CMD_DEVICE_RESET_MSB                                 0xD3
#define SEN63C_CMD_DEVICE_RESET_LSB                                 0x04

#define SEN63C_CMD_START_FAN_CLEANING_MSB                           0x56
#define SEN63C_CMD_START_FAN_CLEANING_LSB                           0x07

#define SEN63C_CMD_ACTIVATE_SHT_HEATER_MSB                          0x67
#define SEN63C_CMD_ACTIVATE_SHT_HEATER_LSB                          0x65

#define SEN63C_CMD_GET_SHT_HEATER_MEASUREMENTS_MSB                  0x67
#define SEN63C_CMD_GET_SHT_HEATER_MEASUREMENTS_LSB                  0x90

#define SEN63C_CMD_PERFORM_FORCED_CO2_RECALIBRATION_MSB             0x67
#define SEN63C_CMD_PERFORM_FORCED_CO2_RECALIBRATION_LSB             0x07

#define SEN63C_CMD_GET_CO2_SENSOR_AUTOMATIC_SELF_CALIBRATION_MSB    0x67
#define SEN63C_CMD_GET_CO2_SENSOR_AUTOMATIC_SELF_CALIBRATION_LSB    0x11

#define SEN63C_CMD_SET_CO2_SENSOR_AUTOMATIC_SELF_CALIBRATION_MSB    0x67
#define SEN63C_CMD_SET_CO2_SENSOR_AUTOMATIC_SELF_CALIBRATION_LSB    0x11

#define SEN63C_CMD_GET_AMBIENT_PRESSURE_MSB                         0x67
#define SEN63C_CMD_GET_AMBIENT_PRESSURE_LSB                         0x20

#define SEN63C_CMD_SET_AMBIENT_PRESSURE_MSB                         0x67
#define SEN63C_CMD_SET_AMBIENT_PRESSURE_LSB                         0x20

#define SEN63C_CMD_GET_SENSOR_ALTITUDE_MSB                          0x67
#define SEN63C_CMD_GET_SENSOR_ALTITUDE_LSB                          0x36

#define SEN63C_CMD_SET_SENSOR_ALTITUDE_MSB                          0x67
#define SEN63C_CMD_SET_SENSOR_ALTITUDE_LSB                          0x36

#define SEN63C_I2C_RX_BUFFER_SIZE                                   32
#define SEN63C_I2C_TX_BUFFER_SIZE                                   32

// *****************************************************************************

/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
 */

typedef enum
{
    SEN63C_DRIVER_STATE_INIT = 0,
    SEN63C_DRIVER_STATE_CHECK_I2C_HANDLER,
    SEN63C_DRIVER_STATE_IDLE,
    SEN63C_DRIVER_STATE_TIMER_EXPIRED,
    SEN63C_DRIVER_STATE_ERROR,
} SEN63C_DRIVER_STATES;

// *****************************************************************************

/* Application Data

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
    SEN63C_DRIVER_STATES state;

    /* Driver variables */
    DRV_HANDLE I2C_HANDLE;
    DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE;
    volatile bool SEN63C_TASK_START;
    volatile bool SEN63C_TASK_COMPLETED;
    uint8_t I2C_ADDRESS[1];
    uint8_t I2C_DATA_RECEIVE[SEN63C_I2C_RX_BUFFER_SIZE];
    uint8_t I2C_DATA_TRANSMIT[SEN63C_I2C_TX_BUFFER_SIZE];
} SEN63C_DRIVER_DATA;

typedef struct
{
    char PRODUCT_NAME[32];
    char SERIAL_NUMBER[32];
    uint16_t DATA_READY_STATUS;
    uint16_t DEVICE_STATUS;
    uint16_t FW_VERSION;
    uint16_t PM10_VALUE;
    uint16_t PM25_VALUE;
    uint16_t PM40_VALUE;
    uint16_t PM100_VALUE;
    int16_t T_VALUE;
    int16_t H_VALUE;
    int16_t CO2_VALUE;
    float PM10;
    float PM25;
    float PM40;
    float PM100;
    float CELSIUS_TEMPERATURE;
    float HUMIDITY;
    float CO2;
} SEN63C_SENSOR_DATA;

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
} SEN63C_SENSOR_SETTINGS;

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

void SEN63C_DRIVER_Initialize(void);

void SEN63C_DRIVER_Tasks(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _SEN63C_DRIVER_H */

/*******************************************************************************
 End of File
 */