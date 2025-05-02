/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    hdc302x_driver.h

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

#define HDC302X_I2C_ADDRESS                 0x44

#define HDC302X_MODE_TRIG_MSB               0x24
#define HDC302X_MODE_TRIG_LPM0              0x00
#define HDC302X_MODE_TRIG_LPM1              0x0B
#define HDC302X_MODE_TRIG_LPM2              0x16
#define HDC302X_MODE_TRIG_LPM3              0xFF
#define HDC302X_MODE_A2S_MSB                0x20
#define HDC302X_MODE_A2S_LPM0               0x32
#define HDC302X_MODE_A2S_LPM1               0x24
#define HDC302X_MODE_A2S_LPM2               0x2F
#define HDC302X_MODE_A2S_LPM3               0xFF
#define HDC302X_MODE_A1HZ_MSB               0x21
#define HDC302X_MODE_A1HZ_LPM0              0x30
#define HDC302X_MODE_A1HZ_LPM1              0x26
#define HDC302X_MODE_A1HZ_LPM2              0x2D
#define HDC302X_MODE_A1HZ_LPM3              0xFF
#define HDC302X_MODE_A2HZ_MSB               0x22
#define HDC302X_MODE_A2HZ_LPM0              0x36
#define HDC302X_MODE_A2HZ_LPM1              0x20
#define HDC302X_MODE_A2HZ_LPM2              0x2B
#define HDC302X_MODE_A2HZ_LPM3              0xFF
#define HDC302X_MODE_A4HZ_MSB               0x23
#define HDC302X_MODE_A4HZ_LPM0              0x34
#define HDC302X_MODE_A4HZ_LPM1              0x22
#define HDC302X_MODE_A4HZ_LPM2              0x29
#define HDC302X_MODE_A4HZ_LPM3              0xFF
#define HDC302X_MODE_A10HZ_MSB              0x27
#define HDC302X_MODE_A10HZ_LPM0             0x37
#define HDC302X_MODE_A10HZ_LPM1             0x21
#define HDC302X_MODE_A10HZ_LPM2             0x2A
#define HDC302X_MODE_A10HZ_LPM3             0xFF
#define HDC302X_MODE_READ_MSB               0xE0
#define HDC302X_MODE_READ                   0x00
#define HDC302X_MODE_READ_MIN_T             0x02
#define HDC302X_MODE_READ_MAX_T             0x03
#define HDC302X_MODE_READ_MIN_H             0x04
#define HDC302X_MODE_READ_MAX_H             0x05
#define HDC302X_WR_ALERT_MSB                0x61
#define HDC302X_WR_ALERT_SET_LO             0x00
#define HDC302X_WR_ALERT_SET_HI             0x1D
#define HDC302X_WR_ALERT_CLR_LO             0x0B
#define HDC302X_WR_ALERT_CLR_HI             0x16
#define HDC302X_RD_ALERT_MSB                0xE1
#define HDC302X_RD_ALERT_SET_LO             0x02
#define HDC302X_RD_ALERT_SET_HI             0x1F
#define HDC302X_RD_ALERT_CLR_LO             0x09
#define HDC302X_RD_ALERT_CLR_HI             0x14
#define HDC302X_HEATER_MSB                  0x30
#define HDC302X_HEATER_ENABLE               0x6D
#define HDC302X_HEATER_DISABLE              0x66
#define HDC302X_HEATER_CFG                  0x6E
#define HDC302X_STATUS_READ_MSB             0xF3
#define HDC302X_STATUS_READ_LSB             0x2D
#define HDC302X_STATUS_CLEAR_MSB            0x30
#define HDC302X_STATUS_CLEAR_LSB            0x41
#define HDC302X_OFFSET_MSB                  0xA0
#define HDC302X_OFFSET_LSB                  0x04
#define HDC302X_SOFT_RESET_MSB              0x30
#define HDC302X_SOFT_RESET_LSB              0xA2
#define HDC302X_RD_NIST_MSB                 0x36
#define HDC302X_RD_NIST_3                   0x83
#define HDC302X_RD_NIST_2                   0x84
#define HDC302X_RD_NIST_1                   0x85
#define HDC302X_RD_MID_MSB                  0x37
#define HDC302X_RD_MID_LSB                  0x80
#define HDC302X_WR_POR_MODE_MSB             0x61
#define HDC302X_WR_POR_MODE_LSB             0xBB
#define HDC302X_POR_MODE_MSB                0x00
#define HDC302X_POR_MODE_A2S_LPM0           0x03
#define HDC302X_POR_MODE_A2S_LPM1           0x13
#define HDC302X_POR_MODE_A2S_LPM2           0x23
#define HDC302X_POR_MODE_A2S_LPM3           0x33
#define HDC302X_POR_MODE_A1HZ_LPM0          0x05
#define HDC302X_POR_MODE_A1HZ_LPM1          0x15
#define HDC302X_POR_MODE_A1HZ_LPM2          0x25
#define HDC302X_POR_MODE_A1HZ_LPM3          0x35
#define HDC302X_POR_MODE_A2HZ_LPM0          0x07
#define HDC302X_POR_MODE_A2HZ_LPM1          0x17
#define HDC302X_POR_MODE_A2HZ_LPM2          0x27
#define HDC302X_POR_MODE_A2HZ_LPM3          0x37
#define HDC302X_POR_MODE_A4HZ_LPM0          0x09
#define HDC302X_POR_MODE_A4HZ_LPM1          0x19
#define HDC302X_POR_MODE_A4HZ_LPM2          0x29
#define HDC302X_POR_MODE_A4HZ_LPM3          0x39
#define HDC302X_POR_MODE_A10HZ_LPM0         0x0B
#define HDC302X_POR_MODE_A10HZ_LPM1         0x1B
#define HDC302X_POR_MODE_A10HZ_LPM2         0x2B
#define HDC302X_POR_MODE_A10HZ_LPM3         0x3B
#define HDC302X_POR_MODE_SLEEP              0x00

#define HDC302X_I2C_RX_BUFFER_SIZE          8
#define HDC302X_I2C_TX_BUFFER_SIZE          8

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
    HDC302X_DRIVER_STATE_INIT = 0,
    HDC302X_DRIVER_STATE_I2C_HANDLER_REGISTER,
    HDC302X_DRIVER_STATE_IDLE,
    HDC302X_DRIVER_STATE_TIMER_EXPIRED,
    HDC302X_DRIVER_STATE_ERROR,
} HDC302X_DRIVER_STATES;

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
    HDC302X_DRIVER_STATES state;

    /* Driver variables */
    DRV_HANDLE I2C_HANDLE;
    DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE;
    bool I2C_TRANSFER_STATUS;
    bool HDC302X_TASK_START;
    bool HDC302X_TASK_COMPLETED;
    bool HDC302X_ALERT;
    uint8_t I2C_DATA_RECEIVE[HDC302X_I2C_RX_BUFFER_SIZE];
    uint8_t I2C_DATA_TRANSMIT[HDC302X_I2C_TX_BUFFER_SIZE];
} HDC302X_DRIVER_DATA;

typedef struct
{
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
    uint8_t STATUS_MSB;
    uint8_t STATUS_LSB;
    uint8_t NIST_VALUE_5;
    uint8_t NIST_VALUE_4;
    uint8_t NIST_VALUE_3;
    uint8_t NIST_VALUE_2;
    uint8_t NIST_VALUE_1;
    uint8_t NIST_VALUE_0;
    uint16_t T_VALUE;
    uint16_t H_VALUE;
    float CELSIUS_TEMPERATURE;
    float FAHRENHEIT_TEMPERATURE;
    float HUMIDITY;
} HDC302X_DRIVER_SENSOR_DATA;

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
} HDC302X_DRIVER_SENSOR_SETTINGS;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

void HDC302X_DRIVER_I2C_Callback(DRV_I2C_TRANSFER_EVENT EVENT, DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE, uintptr_t CONTEXT);

void HDC302X_DRIVER_Temperature_Alert(uintptr_t CONTEXT);

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void HDC302X_DRIVER_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    HDC302X_DRIVER_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    HDC302X_DRIVER_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
 */

void HDC302X_DRIVER_Initialize(void);

/*******************************************************************************
  Function:
    void HDC302X_DRIVER_Tasks ( void )

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
    HDC302X_DRIVER_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void HDC302X_DRIVER_Tasks(void);

bool HDC302X_DRIVER_Get_Task_Start_Status(void);

void HDC302X_DRIVER_Set_Task_Start_Status(bool STATUS);

bool HDC302X_DRIVER_Get_Task_Completed_Status(void);

void HDC302X_DRIVER_Set_Task_Completed_Status(bool STATUS);

void HDC302X_DRIVER_Set_Offset_Values(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Set_Set_High_Alert(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Set_Clear_High_Alert(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Set_Set_Low_Alert(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Set_Clear_Low_Alert(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Get_Offset_Values(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Store_Offset_Values(void);

void HDC302X_DRIVER_Get_Set_High_Alert(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Store_Set_High_Alert(void);

void HDC302X_DRIVER_Get_Clear_High_Alert(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Store_Clear_High_Alert(void);

void HDC302X_DRIVER_Get_Set_Low_Alert(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Store_Set_Low_Alert(void);

void HDC302X_DRIVER_Get_Clear_Low_Alert(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Store_Clear_Low_Alert(void);

void HDC302X_DRIVER_Enter_Auto_Measurement_Mode(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Exit_Auto_Measurement_Mode(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Start_Manual_Measurement(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Get_Manual_Measure_Values(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Get_Auto_Measure_Values(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Store_Measurement_Values(void);

void HDC302X_DRIVER_Get_Minimum_Temperature_Value(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Store_Minimum_Temperature_Value(void);

void HDC302X_DRIVER_Get_Maximum_Temperature_Value(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Store_Maximum_Temperature_Value(void);

void HDC302X_DRIVER_Get_Minimum_Humidity_Value(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Store_Minimum_Humidity_Value(void);

void HDC302X_DRIVER_Get_Maximum_Humidity_Value(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Store_Maximum_Humidity_Value(void);

void HDC302X_DRIVER_Calculation_Temperature(uint16_t T_VALUE);

void HDC302X_DRIVER_Calculation_Humidity(uint16_t H_VALUE);

void HDC302X_DRIVER_Get_Sensor_Status(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Store_Sensor_Status(void);

void HDC302X_DRIVER_Get_NIST_3(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Store_NIST_3(void);

void HDC302X_DRIVER_Get_NIST_2(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Store_NIST_2(void);

void HDC302X_DRIVER_Get_NIST_1(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Store_NIST_1(void);

void HDC302X_DRIVER_Soft_Reset(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Enable_Heater(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Disable_Heater(uint8_t I2C_ADDRESS);

void HDC302X_DRIVER_Configuration_Heater(uint8_t I2C_ADDRESS, uint8_t CURRENT_MSB, uint8_t CURRENT_LSB);

uint8_t HDC302X_DRIVER_Calculation_CRC(uint8_t MESSAGE[], uint8_t MESSAGE_LENGTH);

uint8_t HDC302X_DRIVER_Calculation_Array_CRC(uint8_t MESSAGE_0, uint8_t MESSAGE_1);

uint16_t HDC302X_DRIVER_Set_Offset_Code(uint16_t TEMPERATURE, uint16_t HUMIDITY);

uint16_t HDC302X_DRIVER_Set_ALERT_Code(uint16_t TEMPERATURE, uint16_t HUMIDITY);

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