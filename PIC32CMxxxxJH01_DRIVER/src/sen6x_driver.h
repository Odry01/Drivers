/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    sen6x_driver.h

  Status:
    In development
 
  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "SEN6X_DRIVER_Initialize" and "SEN6X_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "SEN6X_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _SEN6X_DRIVER_H
#define _SEN6X_DRIVER_H

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
    
#define SEN60
#define SEN63C
#define SEN65
#define SEN65
#define SEN68
    
#define SEN6X_CMD_START_CONTINUOUS_MEASUREMENT_SEN6X_MSB        0x00
#define SEN6X_CMD_START_CONTINUOUS_MEASUREMENT_SEN6X_LSB        0x21
#define SEN6X_CMD_START_CONTINUOUS_MEASUREMENT_SEN60_MSB        0x21
#define SEN6X_CMD_START_CONTINUOUS_MEASUREMENT_SEN60_LSB        0x52
#define SEN6X_CMD_STOP_MEASUREMENT_SEN6X_MSB                    0x01
#define SEN6X_CMD_STOP_MEASUREMENT_SEN6X_LSB                    0x04
#define SEN6X_CMD_STOP_MEASUREMENT_SEN60_MSB                    0x3F
#define SEN6X_CMD_STOP_MEASUREMENT_SEN60_LSB                    0x86
#define SEN6X_CMD_GET_DATA_READY_SEN6X_MSB                      0x02
#define SEN6X_CMD_GET_DATA_READY_SEN6X_LSB                      0x02
#define SEN6X_CMD_GET_DATA_READY_SEN60_MSB                      0x4B
#define SEN6X_CMD_GET_DATA_READY_SEN60_LSB                      0x8B
#define SEN6X_CMD_READ_MEASURED_VALUES_SEN60_MSB                0xEC
#define SEN6X_CMD_READ_MEASURED_VALUES_SEN60_LSB                0x05
#define SEN6X_CMD_READ_MEASURED_VALUES_SEN63C_MSB               0x04
#define SEN6X_CMD_READ_MEASURED_VALUES_SEN63C_LSB               0x71
#define SEN6X_CMD_READ_MEASURED_VALUES_SEN65_MSB                0x04
#define SEN6X_CMD_READ_MEASURED_VALUES_SEN65_LSB                0x46
#define SEN6X_CMD_READ_MEASURED_VALUES_SEN66_MSB                0x03
#define SEN6X_CMD_READ_MEASURED_VALUES_SEN66_LSB                0x00
#define SEN6X_CMD_READ_MEASURED_VALUES_SEN68_MSB                0x04
#define SEN6X_CMD_READ_MEASURED_VALUES_SEN68_LSB                0x67
#define SEN6X_CMD_READ_RAW_VALUES_SEN63C_MSB                    0x04
#define SEN6X_CMD_READ_RAW_VALUES_SEN63C_LSB                    0x92
#define SEN6X_CMD_READ_RAW_VALUES_SEN65_SEN68_MSB               0x04
#define SEN6X_CMD_READ_RAW_VALUES_SEN65_SEN68_LSB               0x55
#define SEN6X_CMD_READ_RAW_VALUES_SEN66_MSB                     0x04
#define SEN6X_CMD_READ_RAW_VALUES_SEN66_LSB                     0x05
#define SEN6X_CMD_READ_NUMBER_CONCENTRATION_VALUES_SEN6X_MSB    0x03
#define SEN6X_CMD_READ_NUMBER_CONCENTRATION_VALUES_SEN6X_LSB    0x16
#define SEN6X_CMD_SET_TEMPERATURE_OFFSET_PARAMETERS_MSB         0x60
#define SEN6X_CMD_SET_TEMPERATURE_OFFSET_PARAMETERS_LSB         0x82
#define SEN6X_CMD_SET_TEMPERATURE_ACCELERATION_PARAMETERS_MSB   0x61
#define SEN6X_CMD_SET_TEMPERATURE_ACCELERATION_PARAMETERS_LSB   0x00
#define SEN6X_CMD_GET_PRODUCT_NAME_MSB                          0xD0
#define SEN6X_CMD_GET_PRODUCT_NAME_LSB                          0x14
#define SEN6X_CMD_GET_SERIAL_NUMBER_SEN6X_MSB                   0xD0
#define SEN6X_CMD_GET_SERIAL_NUMBER_SEN6X_LSB                   0x33
#define SEN6X_CMD_GET_SERIAL_NUMBER_SEN60_MSB                   0x36
#define SEN6X_CMD_GET_SERIAL_NUMBER_SEN60_LSB                   0x82
#define SEN6X_CMD_READ_DEVICE_STATUS_SEN6X_MSB                  0xD2
#define SEN6X_CMD_READ_DEVICE_STATUS_SEN6X_LSB                  0x06
#define SEN6X_CMD_READ_DEVICE_STATUS_SEN60_MSB                  0xE0
#define SEN6X_CMD_READ_DEVICE_STATUS_SEN60_LSB                  0x08
#define SEN6X_CMD_READ_AND_CLEAR_DEVICE_STATUS_SEN6X_MSB        0xD2
#define SEN6X_CMD_READ_AND_CLEAR_DEVICE_STATUS_SEN6X_LSB        0x10
#define SEN6X_CMD_DEVICE_RESET_SEN6X_MSB                        0xD3
#define SEN6X_CMD_DEVICE_RESET_SEN6X_LSB                        0x04
#define SEN6X_CMD_DEVICE_RESET_SEN60_MSB                        0x3F
#define SEN6X_CMD_DEVICE_RESET_SEN60_LSB                        0x8D
#define SEN6X_CMD_START_FAN_CLEANING_SEN6X_MSB                  0x56
#define SEN6X_CMD_START_FAN_CLEANING_SEN6X_LSB                  0x07
#define SEN6X_CMD_START_FAN_CLEANING_SEN60_MSB                  0x37
#define SEN6X_CMD_START_FAN_CLEANING_SEN60_LSB                  0x30
#define SEN6X_CMD_ACTIVATE_SHT_HEATER_MSB                       0x67
#define SEN6X_CMD_ACTIVATE_SHT_HEATER_LSB                       0x65
#define SEN6X_CMD_GET_VOC_ALGORITHM_TUNING_PARAMETERS_MSB       0x6D
#define SEN6X_CMD_GET_VOC_ALGORITHM_TUNING_PARAMETERS_LSB       0x00
#define SEN6X_CMD_SET_VOC_ALGORITHM_TUNING_PARAMETERS_MSB       0x6D
#define SEN6X_CMD_SET_VOC_ALGORITHM_TUNING_PARAMETERS_LSB       0x01
#define SEN6X_CMD_GET_VOC_ALGORITHM_STATE_MSB                   0x61
#define SEN6X_CMD_GET_VOC_ALGORITHM_STATE_LSB                   0x81
#define SEN6X_CMD_SET_NOX_ALGORITHM_TUNING_PARAMETERS_MSB       0x6E
#define SEN6X_CMD_SET_NOX_ALGORITHM_TUNING_PARAMETERS_LSB       0x01
#define SEN6X_CMD_GET_NOX_ALGORITHM_TUNING_PARAMETERS_MSB       0x6E
#define SEN6X_CMD_GET_NOX_ALGORITHM_TUNING_PARAMETERS_LSB       0x00
#define SEN6X_CMD_PERFORM_FORCED_CO2_RECALIBRATION_MSB          0x67
#define SEN6X_CMD_PERFORM_FORCED_CO2_RECALIBRATION_LSB          0x07
#define SEN6X_CMD_SET_CO2_SENSOR_AUTOMATIC_SELF_CALIBRATION_MSB 0x67
#define SEN6X_CMD_SET_CO2_SENSOR_AUTOMATIC_SELF_CALIBRATION_LSB 0x11
#define SEN6X_CMD_GET_AMBIENT_PRESSURE_MSB                      0x67
#define SEN6X_CMD_GET_AMBIENT_PRESSURE_LSB                      0x20
#define SEN6X_CMD_SET_AMBIENT_PRESSURE_MSB                      0x67
#define SEN6X_CMD_SET_AMBIENT_PRESSURE_LSB                      0x10
#define SEN6X_CMD_GET_SENSOR_ALTITUDE_MSB                       0x67
#define SEN6X_CMD_GET_SENSOR_ALTITUDE_LSB                       0x36
#define SEN6X_CMD_SET_SENSOR_ALTITUDE_MSB                       0x67
#define SEN6X_CMD_SET_SENSOR_ALTITUDE_LSB                       0x36

#define SEN6X_I2C_RX_BUFFER_SIZE                                8
#define SEN6X_I2C_TX_BUFFER_SIZE                                8

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
    SEN6X_DRIVER_STATE_INIT = 0,
    SEN6X_DRIVER_STATE_I2C_HANDLER_REGISTER,
    SEN6X_DRIVER_STATE_IDLE,
    SEN6X_DRIVER_STATE_TIMER_EXPIRED,
    SEN6X_DRIVER_STATE_ERROR,
} SEN6X_DRIVER_STATES;

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
    SEN6X_DRIVER_STATES state;
    
    /* Driver variables */
    DRV_HANDLE I2C_HANDLE;
    DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE;
    bool I2C_TRANSFER_STATUS;
    bool SEN6X_TASK_START;
    bool SEN6X_TASK_COMPLETED;
    uint8_t I2C_ADDRESS[2];
    uint8_t I2C_DATA_RECEIVE[SEN6X_I2C_RX_BUFFER_SIZE];
    uint8_t I2C_DATA_TRANSMIT[SEN6X_I2C_TX_BUFFER_SIZE];
} SEN6X_DRIVER_DATA;

typedef struct
{
    
} SEN6X_DRIVER_SENSOR_DATA;

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

void SEN6X_DRIVER_Initialize(void);

void SEN6X_DRIVER_Tasks(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _SEN6X_DRIVER_H */

/*******************************************************************************
 End of File
 */