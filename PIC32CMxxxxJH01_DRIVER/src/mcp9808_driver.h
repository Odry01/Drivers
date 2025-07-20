/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    mcp9808_driver.h

  Status:
    In development
 
  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "MCP9808_DRIVER_Initialize" and "MCP9808_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "MCP9808_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _MCP9808_DRIVER_H
#define _MCP9808_DRIVER_H

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

#define MCP9808_CMD_CONFIG_REGISTER             0x1
#define MCP9808_CMD_TEMPERATURE_REGISTER        0x5
#define MCP9808_CMD_MANUFACTURE_ID_REGISTER     0x6
#define MCP9808_CMD_DEVICE_ID_REGISTER          0x7
#define MCP9808_CMD_RESULT_RESOLUTION_REGISTER  0x8

#define MCP9808_I2C_RX_BUFFER_SIZE          8
#define MCP9808_I2C_TX_BUFFER_SIZE          8

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
    MCP9808_DRIVER_STATE_INIT = 0,
    MCP9808_DRIVER_STATE_I2C_HANDLER_REGISTER,
    MCP9808_DRIVER_STATE_SET_SENSOR_CONFIGURATION,
    MCP9808_DRIVER_STATE_SET_SENSOR_CONFIGURATION_ACK,
    MCP9808_DRIVER_STATE_SET_SENSOR_CONFIGURATION_WAIT_FOR_TRANSFER,
    MCP9808_DRIVER_STATE_GET_MANUFACTURER_ID,
    MCP9808_DRIVER_STATE_GET_MANUFACTURER_ID_ACK,
    MCP9808_DRIVER_STATE_GET_MANUFACTURER_ID_WAIT_FOR_TRANSFER,
    MCP9808_DRIVER_STATE_STORE_MANUFACTURER_ID,
    MCP9808_DRIVER_STATE_GET_DEVICE_ID,
    MCP9808_DRIVER_STATE_GET_DEVICE_ID_ACK,
    MCP9808_DRIVER_STATE_GET_DEVICE_ID_WAIT_FOR_TRANSFER,
    MCP9808_DRIVER_STATE_STORE_DEVICE_ID,
    MCP9808_DRIVER_STATE_SET_RESULT_RESOLUTION,
    MCP9808_DRIVER_STATE_SET_RESULT_RESOLUTION_ACK,
    MCP9808_DRIVER_STATE_SET_RESULT_RESOLUTION_WAIT_FOR_TRANSFER,
    MCP9808_DRIVER_STATE_IDLE,
    MCP9808_DRIVER_STATE_GET_TEMPERATURE_VALUES,
    MCP9808_DRIVER_STATE_GET_TEMPERATURE_VALUES_ACK,
    MCP9808_DRIVER_STATE_GET_TEMPERATURE_VALUES_WAIT_FOR_TRANSFER,
    MCP9808_DRIVER_STATE_STORE_TEMPERATURE_VALUES,
    MCP9808_DRIVER_STATE_CALCULATE_TEMPERATURE,
    MCP9808_DRIVER_STATE_STORE_TEMPERATURE,
    MCP9808_DRIVER_STATE_TIMER_EXPIRED,
    MCP9808_DRIVER_STATE_ERROR,
} MCP9808_DRIVER_STATES;

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
    MCP9808_DRIVER_STATES state;

    /* Driver variables */
    DRV_HANDLE I2C_HANDLE;
    DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE;
    bool I2C_TRANSFER_STATUS;
    bool MCP9808_TASK_START;
    bool MCP9808_TASK_COMPLETED;
    uint8_t I2C_ADDRESS[8];
    uint8_t I2C_DATA_RECEIVE[MCP9808_I2C_RX_BUFFER_SIZE];
    uint8_t I2C_DATA_TRANSMIT[MCP9808_I2C_TX_BUFFER_SIZE];
} MCP9808_DRIVER_DATA;

typedef struct
{
    uint8_t CONFIG_MSB;
    uint8_t CONFIG_LSB;
    uint8_t T_VALUE_MSB;
    uint8_t T_VALUE_LSB;
    uint8_t MANUFACTURER_ID_MSB;
    uint8_t MANUFACTURER_ID_LSB;
    uint8_t DEVICE_ID;
    uint8_t DEVICE_REVISION;
    uint8_t RESULT_RESOLUTION;
    float CELSIUS_TEMPERATURE;
} MCP9808_DRIVER_SENSOR_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

void MCP9808_DRIVER_I2C_Callback(DRV_I2C_TRANSFER_EVENT EVENT, DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE, uintptr_t CONTEXT);

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void MCP9808_DRIVER_Initialize(void);

void MCP9808_DRIVER_Tasks(void);

bool MCP9808_DRIVER_Get_Task_Start_Status(void);

void MCP9808_DRIVER_Set_Task_Start_Status(bool STATUS);

bool MCP9808_DRIVER_Get_Task_Completed_Status(void);

void MCP9808_DRIVER_Set_Task_Completed_Status(bool STATUS);

void MCP9808_DRIVER_Set_I2C_Address(void);

void MCP9808_DRIVER_Get_Sensor_Config(uint8_t I2C_ADDRESS);

void MCP9808_DRIVER_Store_Sensor_Config(void);

void MCP9808_DRIVER_Set_Sensor_Config(uint8_t I2C_ADDRESS, uint8_t CONFIG_MSB, uint8_t CONFIG_LSB);

void MCP9808_DRIVER_Get_Temperature_Values(uint8_t I2C_ADDRESS);

void MCP9808_DRIVER_Store_Temperature_Values(void);

void MCP9808_DRIVER_Calculate_Temperature(void);

void MCP9808_DRIVER_Get_Manufacturer_ID(uint8_t I2C_ADDRESS);

void MCP9808_DRIVER_Store_Manufacturer_ID(void);

void MCP9808_DRIVER_Get_Device_ID(uint8_t I2C_ADDRESS);

void MCP9808_DRIVER_Store_Device_ID(void);

void MCP9808_DRIVER_Get_Result_Resolution(uint8_t I2C_ADDRESS);

void MCP9808_DRIVER_Store_Result_Resolution(void);

void MCP9808_DRIVER_Set_Result_Resolution(uint8_t I2C_ADDRESS, uint8_t RESULT_RESOULUTION);

void MCP9808_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _MCP9808_DRIVER_H */

/*******************************************************************************
 End of File
 */