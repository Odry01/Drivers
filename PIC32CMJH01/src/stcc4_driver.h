/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    stcc4_driver.h

  Status:
    In development
 
  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "STCC4_DRIVER_Initialize" and "STCC4_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "STCC4_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _STCC4_DRIVER_H
#define _STCC4_DRIVER_H

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

#define STCC4_CMD_START_CONTINUOUS_MEASUREMENT_MSB  0x21
#define STCC4_CMD_START_CONTINUOUS_MEASUREMENT_LSB  0x8B
#define STCC4_CMD_STOP_CONTINUOUS_MEASUREMENT_MSB   0x3F
#define STCC4_CMD_STOP_CONTINUOUS_MEASUREMENT_LSB   0x86
#define STCC4_CMD_READ_MEASUREMENT_MSB              0xEC
#define STCC4_CMD_READ_MEASUREMENT_LSB              0x05
#define STCC4_CMD_SET_RHT_COMPENSATION_MSB          0xE0
#define STCC4_CMD_SET_RHT_COMPENSATION_LSB          0x00
#define STCC4_CMD_SET_PRESSURE_COMPENSATION_MSB     0xE0
#define STCC4_CMD_SET_PRESSURE_COMPENSATION_LSB     0x16
#define STCC4_CMD_MEASURE_SINGLE_SHOT_MSB           0x21
#define STCC4_CMD_MEASURE_SINGLE_SHOT_LSB           0x9D
#define STCC4_CMD_ENTER_SLEEP_MODE_MSB              0x36
#define STCC4_CMD_ENTER_SLEEP_MODE_LSB              0x50
#define STCC4_CMD_EXIT_SLEEP_MODE                   0x00
#define STCC4_CMD_PERFORM_CONDITIONING_MSB          0x29
#define STCC4_CMD_PERFORM_CONDITIONING_LSB          0xBC
#define STCC4_CMD_PERFORM_SOFT_RESET                0x6
#define STCC4_CMD_PERFORM_FACTORY_RESET_MSB         0x36
#define STCC4_CMD_PERFORM_FACTORY_RESET_LSB         0x32
#define STCC4_CMD_PERFORM_SELF_TEST_MSB             0x27
#define STCC4_CMD_PERFORM_SELF_TEST_LSB             0x8C
#define STCC4_CMD_ENABLE_TESTING_MODE_MSB           0x3F
#define STCC4_CMD_ENABLE_TESTING_MODE_LSB           0xBC
#define STCC4_CMD_DISABLE_TESTING_MODE_MSB          0x3F
#define STCC4_CMD_DISABLE_TESTING_MODE_LSB          0x3D
#define STCC4_CMD_PERFORM_FORCED_RECALIBRATION_MSB  0x36
#define STCC4_CMD_PERFORM_FORCED_RECALIBRATION_LSB  0x2F
#define STCC4_CMD_GET_PRODUCT_ID_MSB                0x36
#define STCC4_CMD_GET_PRODUCT_ID_LSB                0x5B

#define STCC4_I2C_RX_BUFFER_SIZE                    32
#define STCC4_I2C_TX_BUFFER_SIZE                    32

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
    STCC4_DRIVER_STATE_INIT = 0,
    STCC4_DRIVER_STATE_CHECK_I2C_HANDLER,
    STCC4_DRIVER_STATE_GET_PRODUCT_ID,
    STCC4_DRIVER_STATE_GET_PRODUCT_ID_WAIT_FOR_TRANSFER,
    STCC4_DRIVER_STATE_STORE_PRODUCT_ID,
    STCC4_DRIVER_STATE_IDLE,
    STCC4_DRIVER_STATE_START_SINGLE_SHOT_MEASUREMENT,
    STCC4_DRIVER_STATE_START_SINGLE_SHOT_MEASUREMENT_WAIT_FOR_TRANSFER,
    STCC4_DRIVER_STATE_START_WAIT_TIMER,
    STCC4_DRIVER_STATE_WAIT_FOR_MEASURE,
    STCC4_DRIVER_STATE_GET_MEASURED_VALUES,
    STCC4_DRIVER_STATE_GET_MEASURED_VALUES_WAIT_FOR_TRANSFER,
    STCC4_DRIVER_STATE_STORE_MEASURED_VALUES,
    STCC4_DRIVER_STATE_CALCULATE_DATA,
    STCC4_DRIVER_STATE_STORE_DATA,
    STCC4_DRIVER_STATE_TIMER_EXPIRED,
    STCC4_DRIVER_STATE_ERROR,
} STCC4_DRIVER_STATES;

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
    STCC4_DRIVER_STATES state;

    /* Driver variables */
    DRV_HANDLE I2C_HANDLE;
    DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE;
    volatile bool STCC4_TASK_START;
    volatile bool STCC4_TASK_COMPLETED;
    uint8_t I2C_ADDRESS[2];
    uint8_t I2C_DATA_RECEIVE[STCC4_I2C_RX_BUFFER_SIZE];
    uint8_t I2C_DATA_TRANSMIT[STCC4_I2C_TX_BUFFER_SIZE];
} STCC4_DRIVER_DATA;

typedef struct
{
    uint8_t FACTORY_RESET_RESULT;
    uint16_t T_VALUE;
    uint16_t H_VALUE;
    uint16_t CO2_VALUE;
    uint16_t SENSOR_STATUS;
    uint16_t SELF_TEST_RESULT;
    uint16_t FORCED_RECALIBRATION_RESULT;
    uint32_t PRODUCT_ID;
    float CELSIUS_TEMPERATURE;
    float FAHRENHEIT_TEMPERATURE;
    float HUMIDITY;
    float CO2_PPM;
    uint64_t SERIAL_NUMBER;
} STCC4_DRIVER_SENSOR_DATA;

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

void STCC4_DRIVER_Initialize(void);

void STCC4_DRIVER_Tasks(void);

bool STCC4_DRIVER_Get_Task_Start_Status(void);

void STCC4_DRIVER_Set_Task_Start_Status(bool STATUS);

bool STCC4_DRIVER_Get_Task_Completed_Status(void);

void STCC4_DRIVER_Set_Task_Completed_Status(bool STATUS);

void STCC4_DRIVER_Set_I2C_Address(void);

void STCC4_DRIVER_Start_Continuous_Measurement(uint8_t I2C_ADDRESS);

void STCC4_DRIVER_Stop_Continuous_Measurement(uint8_t I2C_ADDRESS);

void STCC4_DRIVER_Get_Measure_Values(uint8_t I2C_ADDRESS);

void STCC4_DRIVER_Store_Measured_Values(void);

void STCC4_DRIVER_Set_RHT_Compensation(uint8_t I2C_ADDRESS, uint8_t T_VALUE_MSB, uint8_t T_VALUE_LSB, uint8_t H_VALUE_MSB, uint8_t H_VALUE_LSB);

void STCC4_DRIVER_Set_Pressure_Compensation(uint8_t I2C_ADDRESS, uint8_t P_VALUE_MSB, uint8_t P_VALUE_LSB);

void STCC4_DRIVER_Single_Shot_Measurement(uint8_t I2C_ADDRESS);

void STCC4_DRIVER_Enter_Sleep_Mode(uint8_t I2C_ADDRESS);

void STCC4_DRIVER_Exit_Sleep_Mode(uint8_t I2C_ADDRESS);

void STCC4_DRIVER_Perform_Conditioning(uint8_t I2C_ADDRESS);

void STCC4_DRIVER_Perform_Soft_Reset(uint8_t I2C_ADDRESS);

void STCC4_DRIVER_Perform_Factory_Reset(uint8_t I2C_ADDRESS);

void STCC4_DRIVER_Store_Factory_Reset_Result(void);

void STCC4_DRIVER_Perform_Self_Test(uint8_t I2C_ADDRESS);

void STCC4_DRIVER_Store_Self_Test_Result(void);

void STCC4_DRIVER_Enable_Testing_Mode(uint8_t I2C_ADDRESS);

void STCC4_DRIVER_Disable_Testing_Mode(uint8_t I2C_ADDRESS);

void STCC4_DRIVER_Perform_Forced_Recalibration(uint8_t I2C_ADDRESS, uint8_t CO2_TARGET_MSB, uint8_t CO2_TARGET_LSB);

void STCC4_DRIVER_Store_Forced_Recalibration_Result(void);

void STCC4_DRIVER_Get_Product_ID(uint8_t I2C_ADDRESS);

void STCC4_DRIVER_Store_Product_ID(void);

void STCC4_DRIVER_Calculation_Temperature(uint16_t T_VALUE);

void STCC4_DRIVER_Calculation_Humidity(uint16_t H_VALUE);

void STCC4_DRIVER_Calculation_CO2(uint16_t CO2_VALUE);

uint8_t STCC4_DRIVER_Calculation_CRC(uint8_t MESSAGE[], uint8_t MESSAGE_LENGTH);

uint8_t STCC4_DRIVER_Calculation_Array_CRC(uint8_t MESSAGE_0, uint8_t MESSAGE_1);

void STCC4_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _STCC4_DRIVER_H */

/*******************************************************************************
 End of File
 */