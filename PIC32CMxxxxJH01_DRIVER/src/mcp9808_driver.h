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
    MCP9808_DRIVER_STATE_CHECK_I2C_HANDLER,
    MCP9808_DRIVER_STATE_SET_SENSOR_CONFIGURATION,
    MCP9808_DRIVER_STATE_SET_SENSOR_CONFIGURATION_WAIT_FOR_TRANSFER,
    MCP9808_DRIVER_STATE_GET_MANUFACTURER_ID,
    MCP9808_DRIVER_STATE_GET_MANUFACTURER_ID_WAIT_FOR_TRANSFER,
    MCP9808_DRIVER_STATE_STORE_MANUFACTURER_ID,
    MCP9808_DRIVER_STATE_GET_DEVICE_ID,
    MCP9808_DRIVER_STATE_GET_DEVICE_ID_WAIT_FOR_TRANSFER,
    MCP9808_DRIVER_STATE_STORE_DEVICE_ID,
    MCP9808_DRIVER_STATE_SET_RESULT_RESOLUTION,
    MCP9808_DRIVER_STATE_SET_RESULT_RESOLUTION_WAIT_FOR_TRANSFER,
    MCP9808_DRIVER_STATE_IDLE,
    MCP9808_DRIVER_STATE_GET_TEMPERATURE_VALUES,
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
    volatile bool MCP9808_TASK_START;
    volatile bool MCP9808_TASK_COMPLETED;
    volatile bool MCP9808_ALERT;
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



// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/**
   Function:
   MCP9808_DRIVER_Initialize

   Summary:
   Performs initialization of the MCP9808 driver.

   Description:
   The routine sets a default sensor address,
   and sets initial state of state machine. 

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void MCP9808_DRIVER_Initialize(void);

/**
   Function:
   MCP9808_DRIVER_Tasks

   Summary:
   Executes periodic driver tasks.

   Description:
   Function where is running state machine.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void MCP9808_DRIVER_Tasks(void);

/**
    Function:
    bool MCP9808_DRIVER_Get_Task_Start_Status(void)

    Summary:
    Retrieves the "TASK START" flag.

    Description:
    This function retrieve "TASK START" flag.

    Parameters:
    None.

    Returns:
    @return bool - true if a task has been started otherwise is not

    Remarks:
    None.
 */
bool MCP9808_DRIVER_Get_Task_Start_Status(void);

/**
    Function:
    void MCP9808_DRIVER_Set_Task_Start_Status(bool STATUS)

    Summary:
    Sets the "TASK START" flag

    Description:
    Set "TASK START" flag. It is used for start state machine in idle state.

    Parameters:
    @param STATUS - desired state of the "TASK START" flag

    Returns:
    None.

    Remarks:
    None.
 */
void MCP9808_DRIVER_Set_Task_Start_Status(bool STATUS);

/**
    Function:
    bool MCP9808_DRIVER_Get_Task_Completed_Status(void)

    Summary:
    Retrieves the "TASK COMPLETED" flag.

    Description:
    This function retrieve "TASK COMPLETED" flag.

    Parameters:
    None.

    Returns:
    @return bool - true if a task has been completed otherwise is not

    Remarks:
    None.
 */
bool MCP9808_DRIVER_Get_Task_Completed_Status(void);

/**
    Function:
    void MCP9808_DRIVER_Set_Task_Completed_Status(bool STATUS)

    Summary:
    Sets the "TASK COMPLETED" flag

    Description:
    Set "TASK COMPLETED" flag. It is used for end state machine in last state.

    Parameters:
    @param STATUS - desired state of the "TASK COMPLETED" flag

    Returns:
    None.

    Remarks:
    None.
 */
void MCP9808_DRIVER_Set_Task_Completed_Status(bool STATUS);

/**
    Function:
    void MCP9808_DRIVER_Set_I2C_Address(void)

    Summary:
    Configures the I2C slave address for all sensor version.

    Description:
    The MCP9808 can be addressed at 0x18 - 0x1F, depending on the
    configuration of ADDR pins on sensor.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    Use before performing any read or write.
 */
void MCP9808_DRIVER_Set_I2C_Address(void);

/**
    Function:
    void MCP9808_DRIVER_Get_Sensor_Config(uint8_t I2C_ADDRESS)

    Summary:
    Reads the sensors configuration register.

    Description:
    Performs read of config register and get the two bytes.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void MCP9808_DRIVER_Get_Sensor_Config(uint8_t I2C_ADDRESS);

/**
    Function:
    void MCP9808_DRIVER_Store_Sensor_Config(void)

    Summary:
    Store the sensor configuration into variables.

    Description:
    Store the sensor configuration into variables. You can use it further in code.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void MCP9808_DRIVER_Store_Sensor_Config(void);

/**
    Function:
    void MCP9808_DRIVER_Set_Sensor_Config(uint8_t I2C_ADDRESS, uint8_t CONFIG_MSB, uint8_t CONFIG_LSB)

    Summary:
    Sets the sensor configuration.

    Description:
    Writes a two bytes value to the MCP9808. This is typically used after
    modifying alert thresholds or shutdown mode.

    Parameters:
    @param I2C_ADDRESS - sensor address
    @param CONFIG_MSB - most significant byte of configuration
    @param CONFIG_LSB - least significant byte

    Returns:
    None.

    Remarks:
    None.
 */
void MCP9808_DRIVER_Set_Sensor_Config(uint8_t I2C_ADDRESS, uint8_t CONFIG_MSB, uint8_t CONFIG_LSB);

/**
    Function:
    void MCP9808_DRIVER_Get_Measure_Values(uint8_t I2C_ADDRESS)

    Summary:
    Reads the current temperature from the sensor.

    Description:
    Performs read of temperature register and get the two bytes.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void MCP9808_DRIVER_Get_Measure_Values(uint8_t I2C_ADDRESS);

/**
    Function:
    void MCP9808_DRIVER_Store_Measured_Values(void)

    Summary:
    Store the raw temperature value into variables.

    Description:
    Store the raw temperature value into variables. You can use it further in code.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void MCP9808_DRIVER_Store_Measured_Values(void);

/**
    Function:
    void MCP9808_DRIVER_Calculation_Temperature(void)

    Summary:
    Converts the raw temperature to degrees Celsius.

    Description:
    Converts the raw temperature to degrees Celsius. 
    Equation is in the datasheet.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void MCP9808_DRIVER_Calculation_Temperature(void);

/**
    Function:
    void MCP9808_DRIVER_Get_Manufacturer_ID(uint8_t I2C_ADDRESS)

    Summary:
    Reads the manufacturer ID register.

    Description:
    Performs read of manufacturer ID register and get the two bytes.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void MCP9808_DRIVER_Get_Manufacturer_ID(uint8_t I2C_ADDRESS);

/**
    Function:
    void MCP9808_DRIVER_Store_Manufacturer_ID(void)

    Summary:
    Store the sensor manufacturer ID into variables.

    Description:
    Store the sensor manufacturer ID into variables. You can use it further in code.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void MCP9808_DRIVER_Store_Manufacturer_ID(void);

/**
    Function:
    void MCP9808_DRIVER_Get_Device_ID(uint8_t I2C_ADDRESS)

    Summary:
    Reads the device ID register.

    Description:
    Performs read of device ID register and get the two bytes.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void MCP9808_DRIVER_Get_Device_ID(uint8_t I2C_ADDRESS);

/**
    Function:
    void MCP9808_DRIVER_Store_Device_ID(void)

    Summary:
    Store the sensor device ID into variables.

    Description:
    Store the sensor device ID into variables. You can use it further in code.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void MCP9808_DRIVER_Store_Device_ID(void);

/**
    Function:
    void MCP9808_DRIVER_Get_Result_Resolution(uint8_t I2C_ADDRESS)

    Summary:
    Reads the resolution register.

    Description:
    Performs read of resolution register and get the two bytes.

    Parameters:
    @param I2C_ADDRESS - sensor address

    Returns:
    None.

    Remarks:
    None.
 */
void MCP9808_DRIVER_Get_Result_Resolution(uint8_t I2C_ADDRESS);

/**
    Function:
    void MCP9808_DRIVER_Store_Result_Resolution(void)

    Summary:
    Store the sensor resolution into variables.

    Description:
    Store the sensor resolution into variables. You can use it further in code.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void MCP9808_DRIVER_Store_Result_Resolution(void);

/**
    Function:
    void MCP9808_DRIVER_Set_Result_Resolution(uint8_t I2C_ADDRESS, uint8_t RESULT_RESOULUTION)

    Summary:
    Configures the temperature resolution.

    Description:
    Performs write of config temperature resolution to a sensor. 
    Bits setting you can find in datasheet.

    Parameters:
    @param I2C_ADDRESS - sensor address
    @param RESULT_RESOULUTION - desired resolution code

    Returns:
    None.

    Remarks:
    None.
 */
void MCP9808_DRIVER_Set_Result_Resolution(uint8_t I2C_ADDRESS, uint8_t RESULT_RESOULUTION);

/**
    Function:
    void MCP9808_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)

    Summary:
    Prints the text to a console.

    Description:
    Prints formatted text to console. You can use it for debug messages.

    Parameters:
    @param CONSOLE_HANDLE - console handle returned by the library

    Returns:
    None.

    Remarks:
    For reading a text use TeraTerm, CoolTerm, etc.
 */
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