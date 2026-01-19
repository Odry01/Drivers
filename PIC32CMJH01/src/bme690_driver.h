/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    bme690_driver.h

  Status:
    In development
 
  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "BME690_DRIVER_Initialize" and "BME690_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "BME690_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _BME690_DRIVER_H
#define _BME690_DRIVER_H

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

#define BME690_CMD_STATUS_REGISTER                          0x73
#define BME690_CMD_VARIANT_ID_REGISTER                      0xF0
#define BME690_CMD_RESET_REGISTER                           0xE0
#define BME690_CMD_CHIP_ID_REGISTER                         0xD0
#define BME690_CMD_CONFIG_REGISTER                          0x75
#define BME690_CMD_CTRL_MEAS_REGISTER                       0x74
#define BME690_CMD_CTRL_HUM_REGISTER                        0x72
#define BME690_CMD_CTRL_GAS_1_REGISTER                      0x71
#define BME690_CMD_CTRL_GAS_0_REGISTER                      0x70
#define BME690_CMD_GAS_WAIT_SHARED_REGISTER                 0x6E
#define BME690_CMD_GAS_WAIT_X_REGISTER                      0x6D
#define BME690_CMD_RES_HEAT_X_REGISTER                      0x63
#define BME690_CMD_IDAC_HEAT_X_REGISTER                     0x59
#define BME690_CMD_GAS_R_LSB_2_REGISTER                     0x4F
#define BME690_CMD_GAS_R_MSB_2_REGISTER                     0x4E
#define BME690_CMD_HUM_LSB_2_REGISTER                       0x48
#define BME690_CMD_HUM_MSB_2_REGISTER                       0x47
#define BME690_CMD_TEMP_XLSB_2_REGISTER                     0x46
#define BME690_CMD_TEMP_LSB_2_REGISTER                      0x45
#define BME690_CMD_TEMP_MSB_2_REGISTER                      0x44
#define BME690_CMD_PRESS_XLSB_2_REGISTER                    0x43
#define BME690_CMD_PRESS_LSB_2_REGISTER                     0x42
#define BME690_CMD_PRESS_MSB_2_REGISTER                     0x41
#define BME690_CMD_SUB_MEAS_INDEX_2_REGISTER                0x40
#define BME690_CMD_MEAS_STATUS_2_REGISTER                   0x3F
#define BME690_CMD_GAS_R_LSB_1_REGISTER                     0x3E
#define BME690_CMD_GAS_R_MSB_1_REGISTER                     0x3D
#define BME690_CMD_HUM_LSB_1_REGISTER                       0x37
#define BME690_CMD_HUM_MSB_1_REGISTER                       0x36
#define BME690_CMD_TEMP_XLSB_1_REGISTER                     0x35
#define BME690_CMD_TEMP_LSB_1_REGISTER                      0x34
#define BME690_CMD_TEMP_MSB_1_REGISTER                      0x33
#define BME690_CMD_PRESS_XLSB_1_REGISTER                    0x32
#define BME690_CMD_PRESS_LSB_1_REGISTER                     0x31
#define BME690_CMD_PRESS_MSB_1_REGISTER                     0x30
#define BME690_CMD_SUB_MEAS_INDEX_1_REGISTER                0x2F
#define BME690_CMD_MEAS_STATUS_1_REGISTER                   0x2E
#define BME690_CMD_GAS_R_LSB_0_REGISTER                     0x2D
#define BME690_CMD_GAS_R_MSB_0_REGISTER                     0x2C
#define BME690_CMD_HUM_LSB_0_REGISTER                       0x26
#define BME690_CMD_HUM_MSB_0_REGISTER                       0x25
#define BME690_CMD_TEMP_XLSB_0_REGISTER                     0x24
#define BME690_CMD_TEMP_LSB_0_REGISTER                      0x23
#define BME690_CMD_TEMP_MSB_0_REGISTER                      0x22
#define BME690_CMD_PRESS_XLSB_0_REGISTER                    0x21
#define BME690_CMD_PRESS_LSB_0_REGISTER                     0x20
#define BME690_CMD_PRESS_MSB_0_REGISTER                     0x1F
#define BME690_CMD_SUB_MEAS_INDEX_0_REGISTER                0x1E
#define BME690_CMD_MEAS_STATUS_0_REGISTER                   0x1D

#define BME690_CMD_PAR_T1_CALIBRATION_LSB_REGISTER          0xEA
#define BME690_CMD_PAR_T1_CALIBRATION_MSB_REGISTER          0xE9
#define BME690_CMD_PAR_T2_CALIBRATION_LSB_REGISTER          0x8B
#define BME690_CMD_PAR_T2_CALIBRATION_MSB_REGISTER          0x8A
#define BME690_CMD_PAR_T3_CALIBRATION_LSB_REGISTER          0x8C

#define BME690_CMD_PAR_H1_CALIBRATION_LSB_REGISTER          0xE3
#define BME690_CMD_PAR_H1_CALIBRATION_MSB_REGISTER          0xE2
#define BME690_CMD_PAR_H2_CALIBRATION_LSB_REGISTER          0xE4    
#define BME690_CMD_PAR_H3_CALIBRATION_LSB_REGISTER          0xE6
#define BME690_CMD_PAR_H4_CALIBRATION_LSB_REGISTER          0xE5
#define BME690_CMD_PAR_H5_CALIBRATION_LSB_REGISTER          0xE1
#define BME690_CMD_PAR_H5_CALIBRATION_MSB_REGISTER          0xE2
#define BME690_CMD_PAR_H6_CALIBRATION_LSB_REGISTER          0xE7

#define BME690_CMD_PAR_P1_CALIBRATION_LSB_REGISTER          0x95
#define BME690_CMD_PAR_P1_CALIBRATION_MSB_REGISTER          0x94
#define BME690_CMD_PAR_P2_CALIBRATION_LSB_REGISTER          0x97
#define BME690_CMD_PAR_P2_CALIBRATION_MSB_REGISTER          0x96
#define BME690_CMD_PAR_P3_CALIBRATION_LSB_REGISTER          0x98
#define BME690_CMD_PAR_P4_CALIBRATION_LSB_REGISTER          0x99
#define BME690_CMD_PAR_P5_CALIBRATION_LSB_REGISTER          0x8F
#define BME690_CMD_PAR_P5_CALIBRATION_MSB_REGISTER          0x8E
#define BME690_CMD_PAR_P6_CALIBRATION_LSB_REGISTER          0x91
#define BME690_CMD_PAR_P6_CALIBRATION_MSB_REGISTER          0x90
#define BME690_CMD_PAR_P7_CALIBRATION_LSB_REGISTER          0x92
#define BME690_CMD_PAR_P8_CALIBRATION_LSB_REGISTER          0x93
#define BME690_CMD_PAR_P9_CALIBRATION_LSB_REGISTER          0x9D
#define BME690_CMD_PAR_P9_CALIBRATION_MSB_REGISTER          0x9C 
#define BME690_CMD_PAR_P10_CALIBRATION_LSB_REGISTER         0x9E
#define BME690_CMD_PAR_P11_CALIBRATION_LSB_REGISTER         0x9F

#define BME690_CMD_PAR_G1_CALIBRATION_LSB_REGISTER          0xED
#define BME690_CMD_PAR_G2_CALIBRATION_LSB_REGISTER          0xEB
#define BME690_CMD_PAR_G2_CALIBRATION_MSB_REGISTER          0xEC
#define BME690_CMD_PAR_G3_CALIBRATION_LSB_REGISTER          0xEE

#define BME690_I2C_RX_BUFFER_SIZE                       8
#define BME690_I2C_TX_BUFFER_SIZE                       8

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
    BME690_DRIVER_STATE_INIT = 0,
    BME690_DRIVER_STATE_CHECK_I2C_HANDLER,
    BME690_DRIVER_STATE_IDLE,
    BME690_DRIVER_STATE_TIMER_EXPIRED,
    BME690_DRIVER_STATE_ERROR,
} BME690_DRIVER_STATES;

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
    BME690_DRIVER_STATES state;

    /* Driver variables */
    DRV_HANDLE I2C_HANDLE;
    DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE;
    volatile bool BME690_TASK_START;
    volatile bool BME690_TASK_COMPLETED;
    volatile bool BME690_ALERT;
    uint8_t I2C_ADDRESS[1];
    uint8_t I2C_DATA_RECEIVE[BME690_I2C_RX_BUFFER_SIZE];
    uint8_t I2C_DATA_TRANSMIT[BME690_I2C_TX_BUFFER_SIZE];
} BME690_DRIVER_DATA;

typedef struct
{
    uint8_t T_MSB_REGISTER[3];
    uint8_t H_MSB_REGISTER[3];
    uint8_t P_MSB_REGISTER[3];
    uint8_t G_MSB_REGISTER[3];
    uint8_t T_LSB_REGISTER[3];
    uint8_t H_LSB_REGISTER[3];
    uint8_t P_LSB_REGISTER[3];
    uint8_t G_LSB_REGISTER[3];
    uint8_t T_XLSB_REGISTER[3];
    uint8_t P_XLSB_REGISTER[3];
    uint8_t SUB_MEAS_INDEX_REGISTER[3];
    uint8_t MEAS_STATUS_REGISTER[3];
} BME690_DRIVER_REGISTER_DATA;

typedef struct
{
    uint8_t VARIANT_ID;
    uint8_t CHIP_ID;
    uint8_t CONFIG;
    uint8_t CTRL_MEAS;
    uint8_t CTRL_HUM;
    uint8_t CTRL_GAS_0;
    uint8_t CTRL_GAS_1;
    uint8_t T_VALUE_MSB[3];
    uint8_t H_VALUE_MSB[3];
    uint8_t P_VALUE_MSB[3];
    uint8_t G_VALUE_MSB[3];
    uint8_t T_VALUE_LSB[3];
    uint8_t H_VALUE_LSB[3];
    uint8_t P_VALUE_LSB[3];
    uint8_t G_VALUE_LSB[3];
    uint8_t T_VALUE_XLSB[3];
    uint8_t P_VALUE_XLSB[3];
    uint32_t T_VALUE;
    uint32_t H_VALUE;
    uint32_t P_VALUE;
    uint32_t G_VALUE;
    float TEMPERATURE;
    float HUMIDITY;
    float PRESSURE;
    float GAS_RESISTANCE;
} BME690_DRIVER_SENSOR_DATA;

typedef struct
{
    uint8_t PAR_T1_MSB;
    uint8_t PAR_T1_LSB;
    uint16_t PAR_T1;
    uint8_t PAR_T2_MSB;
    uint8_t PAR_T2_LSB;
    uint16_t PAR_T2;
    uint8_t PAR_T3;
    uint16_t PAR_H1;
    uint8_t PAR_H2;
    uint8_t PAR_H3;
    uint8_t PAR_H4;
    uint16_t PAR_H5;
    uint8_t PAR_H6;
    uint16_t PAR_P1;
    uint16_t PAR_P2;
    uint8_t PAR_P3;
    uint8_t PAR_P4;
    uint16_t PAR_P5;
    uint16_t PAR_P6;
    uint8_t PAR_P7;
    uint8_t PAR_P8;
    uint16_t PAR_P9;
    uint8_t PAR_P10;
    uint8_t PAR_P11;
    uint8_t PAR_G1;
    uint16_t PAR_G2;
    uint8_t PAR_G3;
} BME690_DRIVER_CAL_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

void BME690_DRIVER_Alert(uintptr_t CONTEXT);

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void BME690_DRIVER_Initialize(void);

void BME690_DRIVER_Tasks(void);

void BME690_DRIVER_Set_I2C_Address(void);

void BME690_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _BME690_DRIVER_H */

/*******************************************************************************
 End of File
 */