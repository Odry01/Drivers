/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    bme690_driver.h

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

#define BME690_I2C_ADDRESS                              0x44    

#define BME690_STATUS_REGISTER                          0x73
#define BME690_VARIANT_ID_REGISTER                      0xF0
#define BME690_RESET_REGISTER                           0xE0
#define BME690_CHIP_ID_REGISTER                         0xD0
#define BME690_CONFIG_REGISTER                          0x75
#define BME690_CTRL_MEAS_REGISTER                       0x74
#define BME690_CTRL_HUM_REGISTER                        0x72
#define BME690_CTRL_GAS_1_REGISTER                      0x71
#define BME690_CTRL_GAS_0_REGISTER                      0x70
#define BME690_GAS_WAIT_SHARED_REGISTER                 0x6E
#define BME690_GAS_WAIT_X_REGISTER                      0x6D
#define BME690_RES_HEAT_X_REGISTER                      0x63
#define BME690_IDAC_HEAT_X_REGISTER                     0x59
#define BME690_GAS_LSB_2_REGISTER                       0x4F
#define BME690_GAS_MSB_2_REGISTER                       0x4E
#define BME690_HUM_LSB_2_REGISTER                       0x48
#define BME690_HUM_MSB_2_REGISTER                       0x47
#define BME690_TEMP_XLSB_2_REGISTER                     0x46
#define BME690_TEMP_LSB_2_REGISTER                      0x45
#define BME690_TEMP_MSB_2_REGISTER                      0x44
#define BME690_PRESS_XLSB_2_REGISTER                    0x43
#define BME690_PRESS_LSB_2_REGISTER                     0x42
#define BME690_PRESS_MSB_2_REGISTER                     0x41
#define BME690_SUB_MEAS_INDEX_2_REGISTER                0x40
#define BME690_MEAS_STATUS_2_REGISTER                   0x3F
#define BME690_GAS_R_LSB_1_REGISTER                     0x3E
#define BME690_GAS_R_MSB_1_REGISTER                     0x3D
#define BME690_HUM_LSB_1_REGISTER                       0x37
#define BME690_HUM_MSB_1_REGISTER                       0x36
#define BME690_TEMP_XLSB_1_REGISTER                     0x35
#define BME690_TEMP_LSB_1_REGISTER                      0x34
#define BME690_TEMP_MSB_1_REGISTER                      0x33
#define BME690_PRESS_XLSB_1_REGISTER                    0x32
#define BME690_PRESS_LSB_1_REGISTER                     0x31
#define BME690_PRESS_MSB_1_REGISTER                     0x30
#define BME690_SUB_MEAS_INDEX_1_REGISTER                0x2F
#define BME690_MEAS_STATUS_1_REGISTER                   0x2E
#define BME690_GAS_R_LSB_0_REGISTER                     0x2D
#define BME690_GAS_R_MSB_0_REGISTER                     0x2C
#define BME690_HUM_LSB_0_REGISTER                       0x26
#define BME690_HUM_MSB_0_REGISTER                       0x25
#define BME690_TEMP_XLSB_0_REGISTER                     0x24
#define BME690_TEMP_LSB_0_REGISTER                      0x23
#define BME690_TEMP_MSB_0_REGISTER                      0x22
#define BME690_PRESS_XLSB_0_REGISTER                    0x21
#define BME690_PRESS_LSB_0_REGISTER                     0x20
#define BME690_PRESS_MSB_0_REGISTER                     0x1F
#define BME690_SUB_MEAS_INDEX_0_REGISTER                0x1E
#define BME690_MEAS_STATUS_0_REGISTER                   0x1D

#define BME690_PAR_T1_CALIBRATION_LSB_REGISTER          0xEA
#define BME690_PAR_T1_CALIBRATION_MSB_REGISTER          0xE9
#define BME690_PAR_T2_CALIBRATION_LSB_REGISTER          0x8B
#define BME690_PAR_T2_CALIBRATION_MSB_REGISTER          0x8A
#define BME690_PAR_T3_CALIBRATION_LSB_REGISTER          0x8C

#define BME690_PAR_H1_CALIBRATION_LSB_REGISTER          0xE3
#define BME690_PAR_H1_CALIBRATION_MSB_REGISTER          0xE2
#define BME690_PAR_H2_CALIBRATION_LSB_REGISTER          0xE4    
#define BME690_PAR_H3_CALIBRATION_LSB_REGISTER          0xE6
#define BME690_PAR_H4_CALIBRATION_LSB_REGISTER          0xE5
#define BME690_PAR_H5_CALIBRATION_LSB_REGISTER          0xE1
#define BME690_PAR_H5_CALIBRATION_MSB_REGISTER          0xE2
#define BME690_PAR_H6_CALIBRATION_LSB_REGISTER          0xE7

#define BME690_PAR_P1_CALIBRATION_LSB_REGISTER          0x95
#define BME690_PAR_P1_CALIBRATION_MSB_REGISTER          0x94
#define BME690_PAR_P2_CALIBRATION_LSB_REGISTER          0x97
#define BME690_PAR_P2_CALIBRATION_MSB_REGISTER          0x96
#define BME690_PAR_P3_CALIBRATION_LSB_REGISTER          0x98
#define BME690_PAR_P4_CALIBRATION_LSB_REGISTER          0x99
#define BME690_PAR_P5_CALIBRATION_LSB_REGISTER          0x8F
#define BME690_PAR_P5_CALIBRATION_MSB_REGISTER          0x8E
#define BME690_PAR_P6_CALIBRATION_LSB_REGISTER          0x91
#define BME690_PAR_P6_CALIBRATION_MSB_REGISTER          0x90
#define BME690_PAR_P7_CALIBRATION_LSB_REGISTER          0x92
#define BME690_PAR_P8_CALIBRATION_LSB_REGISTER          0x93
#define BME690_PAR_P9_CALIBRATION_LSB_REGISTER          0x9D
#define BME690_PAR_P9_CALIBRATION_MSB_REGISTER          0x9C 
#define BME690_PAR_P10_CALIBRATION_LSB_REGISTER         0x9E
#define BME690_PAR_P11_CALIBRATION_LSB_REGISTER         0x9F

#define BME690_PAR_G1_CALIBRATION_LSB_REGISTER          0xED
#define BME690_PAR_G2_CALIBRATION_LSB_REGISTER          0xEB
#define BME690_PAR_G2_CALIBRATION_MSB_REGISTER          0xEC
#define BME690_PAR_G3_CALIBRATION_LSB_REGISTER          0xEE

#define BME690_I2C_RX_BUFFER_SIZE                       8
#define BME690_I2C_TX_BUFFER_SIZE                       8

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
    /* Application's state machine's initial state. */
    BME690_DRIVER_STATE_INIT = 0,
    BME690_DRIVER_STATE_SERVICE_TASKS,
    /* TODO: Define states used by the application state machine. */

} BME690_DRIVER_STATES;


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
    BME690_DRIVER_STATES state;

    /* Driver variables */
    DRV_HANDLE I2C_HANDLE;
    DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE;
    bool I2C_TRANSFER_STATUS;
    bool BME690_TASK_START;
    bool BME690_TASK_COMPLETED;
    bool BME690_ALERT;
    uint8_t I2C_DATA_RECEIVE[BME690_I2C_RX_BUFFER_SIZE];
    uint8_t I2C_DATA_TRANSMIT[BME690_I2C_TX_BUFFER_SIZE];
} BME690_DRIVER_DATA;

typedef struct
{
    uint8_t CONFIG;
    uint8_t VARIANT_ID;
    uint8_t CHIP_ID;
    uint32_t T_VALUE;
    uint32_t H_VALUE;
    uint32_t P_VALUE;
    uint32_t G_VALUE;
    uint8_t STATUS;
    uint8_t GAS_INDEX;
    uint8_t MEASUREMENT_INDEX;
    uint8_t RESISTOR_HEAT;
    uint8_t IDAC;
    uint8_t GAS_WAIT;
    float TEMPERATURE;
    float HUMIDITY;
    float PRESSURE;
    float GAS_RESISTANCE;
} BME690_DRIVER_SENSOR_DATA;

typedef struct
{
    int16_t PAR_H1;
    int8_t PAR_H2;
    uint8_t PAR_H3;
    int8_t PAR_H4;
    int16_t PAR_H5;
    uint8_t PAR_H6;
    int8_t PAR_G1;
    int16_t PAR_G2;
    int8_t PAR_G3;
    uint16_t PAR_T1;
    uint16_t PAR_T2;
    int8_t PAR_T3;
    uint16_t PAR_P1;
    uint16_t PAR_P2;
    int8_t PAR_P3;
    int8_t PAR_P4;
    int16_t PAR_P5;
    int16_t PAR_P6;
    int8_t PAR_P7;
    int8_t PAR_P8;
    int16_t PAR_P9;
    int8_t PAR_P10;
    int8_t PAR_P11;
    float T_FINE;
    uint8_t RES_HEAT_RANGE;
    int8_t RES_HEAT_VALUE;
    int8_t RANGE_SW_ERROR;
} BME690_DRIVER_CALIBRATION_DATA;

typedef struct
{
    uint8_t ENABLE;
    uint16_t HEATER_TEMPERATURE;
    uint16_t HEATER_DURATION;
    uint16_t *HEATER_TEMPERATURE_PROFILE;
    uint16_t *HEATER_DURATION_PROFILE;
    uint8_t PROFILE_LENGTH;
    uint16_t SHARED_HEATER_DURATION;
} BME690_DRIVER_HEATER_CONFIGURATION;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

void BME690_DRIVER_I2C_Callback(DRV_I2C_TRANSFER_EVENT EVENT, DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE, uintptr_t CONTEXT);

void BME690_DRIVER_Alert(uintptr_t CONTEXT);

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void BME690_DRIVER_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    BME690_DRIVER_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    BME690_DRIVER_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
 */

void BME690_DRIVER_Initialize(void);

/*******************************************************************************
  Function:
    void BME690_DRIVER_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    BME690_DRIVER_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void BME690_DRIVER_Tasks(void);

void BME690_DRIVER_Get_Variant_ID(void);

void BME690_DRIVER_Store_Variant_ID(void);

void BME690_DRIVER_Reset_BME690(void);

void BME690_DRIVER_Get_Chip_ID(void);

void BME690_DRIVER_Store_Chip_ID(void);

void BME690_DRIVER_Get_Config(void);

void BME690_DRIVER_Store_Config(void);

void BME690_DRIVER_Set_Config(uint8_t CONFIG);

void BME690_DRIVER_Get_Control_Measurement(void);

void BME690_DRIVER_Store_Control_Measurement(void);

void BME690_DRIVER_Set_Control_Measurement(uint8_t CONFIG);

void BME690_DRIVER_Get_Control_Humidity(void);

void BME690_DRIVER_Store_Control_Humidity(void);

void BME690_DRIVER_Set_Control_Humidity(uint8_t CONFIG);

void BME690_DRIVER_Get_Control_Gas_1(void);

void BME690_DRIVER_Set_Control_Gas_1(uint8_t CONFIG);

void BME690_DRIVER_Get_Control_Gas_0(void);

void BME690_DRIVER_Set_Control_Gas_0(uint8_t CONFIG);

void BME690_DRIVER_Get_Gas_Wait_Shared(void);

void BME690_DRIVER_Set_Gas_Wait_Shared(uint8_t CONFIG);

void BME690_DRIVER_Get_Gas_Wait(uint8_t REGISTER);

void BME690_DRIVER_Set_Gas_Wait(uint8_t REGISTER, uint8_t CONFIG);

void BME690_DRIVER_Get_Res_Heat(void);

void BME690_DRIVER_Set_Res_Heat(uint8_t REGISTER, uint8_t CONFIG);

void BME690_DRIVER_Get_Idac_Heat(void);

void BME690_DRIVER_Set_Idac_Heat(uint8_t REGISTER, uint8_t CONFIG);

void BME690_DRIVER_Get_Gas_LSB(uint8_t REGISTER);

void BME690_DRIVER_Store_Gas_LSB(void);

void BME690_DRIVER_Get_Gas_MSB(uint8_t REGISTER);

void BME690_DRIVER_Store_Gas_MSB(void);

void BME690_DRIVER_Get_Humidity_LSB(uint8_t REGISTER);

void BME690_DRIVER_Store_Humidity_LSB(void);

void BME690_DRIVER_Get_Humidity_MSB(uint8_t REGISTER);

void BME690_DRIVER_Store_Humidity_MSB(void);

void BME690_DRIVER_Get_Temperature_XLSB(uint8_t REGISTER);

void BME690_DRIVER_Store_Temperature_XLSB(void);

void BME690_DRIVER_Get_Temperature_LSB(uint8_t REGISTER);

void BME690_DRIVER_Store_Temperature_LSB(void);

void BME690_DRIVER_Get_Temperature_MSB(uint8_t REGISTER);

void BME690_DRIVER_Store_Temperature_MSB(void);

void BME690_DRIVER_Get_Pressure_XLSB(uint8_t REGISTER);

void BME690_DRIVER_Store_Pressure_XLSB(void);

void BME690_DRIVER_Get_Pressure_LSB(uint8_t REGISTER);

void BME690_DRIVER_Store_Pressure_LSB(void);

void BME690_DRIVER_Get_Pressure_MSB(uint8_t REGISTER);

void BME690_DRIVER_Store_Pressure_MSB(void);

void BME690_DRIVER_Get_Sub_Measurement_Status(uint8_t REGISTER);

void BME690_DRIVER_Get_Measurement_Status(uint8_t REGISTER);

void BME690_DRIVER_Get_Calibration_Register_Value(uint8_t REGISTER);

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