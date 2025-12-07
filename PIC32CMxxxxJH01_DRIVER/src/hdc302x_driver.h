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
    HDC302X_DRIVER_STATE_IDLE,
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
void HDC302X_DRIVER_Initialize(void);

/**
    Function:
    void HDC302X_DRIVER_Tasks(void)

    Summary:
    Executes periodic tasks.

    Description:
    Function where is running state machine.

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
bool HDC302X_DRIVER_Get_Task_Start_Status(void);

/**
    Function:
    void HDC302X_DRIVER_Set_Task_Start_Status(bool STATUS)

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
void HDC302X_DRIVER_Set_Task_Start_Status(bool STATUS);

/**
    Function:
    bool HDC302X_DRIVER_Get_Task_Completed_Status(void)

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
bool HDC302X_DRIVER_Get_Task_Completed_Status(void);

/**
    Function:
    void HDC302X_DRIVER_Set_Task_Completed_Status(bool STATUS)

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
void HDC302X_DRIVER_Set_Task_Completed_Status(bool STATUS);

/**
   Function:
   HDC302X_DRIVER_Set_I2C_Address

   Summary:
   Configures the I²C slave address used for all subsequent
   sensor transactions.

   Description:
   The sensor supports two addresses (0x40 and 0x41).  This routine
   writes the chosen value into an internal variable that is read by
   every I²C helper function.  Changing the address does **not**
   alter any hardware registers; it simply updates the driver’s
   view of where to talk to the sensor.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   The caller must call this routine before performing any read or write.
 */
void HDC302X_DRIVER_Set_I2C_Address(void);

/**
   Function:
   HDC302X_DRIVER_Get_Offset_Values

   Summary:
   Reads the temperature and humidity offset registers from the sensor.

   Description:
   The routine issues two I²C reads (one for each offset) at
   `I2C_ADDRESS` and stores the 16‑bit values in an internal cache.
   These offsets are used by the driver’s calibration functions
   when converting raw data to physical units.

   Parameters:
   @param I2C_ADDRESS - sensor address from which to read

   Returns:
   None.

   Remarks:
   The values are cached; call *HDC302X_DRIVER_Store_Offset_Values()*
   if you wish to persist them in non‑volatile memory.
 */
void HDC302X_DRIVER_Get_Offset_Values(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Store_Offset_Values

   Summary:
   Persists the internally cached offset values to non‑volatile memory.

   Description:
   After a successful *Get_Offset_Values()* call, this routine
   writes the cached offsets into EEPROM/flash so that they survive
   power cycles.  It does not perform any I²C transaction.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Call this only after *Get_Offset_Values()* has been executed.
 */
void HDC302X_DRIVER_Store_Offset_Values(void);

/**
   Function:
   HDC302X_DRIVER_Set_Offset_Values

   Summary:
   Writes the internally cached offset values back to the sensor.

   Description:
   The routine takes the 16‑bit offsets stored in the driver’s
   internal cache and writes them to the corresponding registers
   at `I2C_ADDRESS`.  This is typically used after a calibration
   routine has updated the cache.

   Parameters:
   @param I2C_ADDRESS - sensor address where offsets are written

   Returns:
   None.

   Remarks:
   The sensor will apply these offsets immediately to all subsequent readings.
 */
void HDC302X_DRIVER_Set_Offset_Values(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Get_Set_High_Alert

   Summary:
   Reads the high‑alert threshold registers from the sensor.

   Description:
   The routine performs two I²C reads (temperature and humidity
   thresholds) at `I2C_ADDRESS` and stores them in an internal cache.
   These values are used to generate alerts when the measured
   temperature or humidity rises above the configured limits.

   Parameters:
   @param I2C_ADDRESS - sensor address from which to read

   Returns:
   None.

   Remarks:
   The cached thresholds can be persisted with *Store_Set_High_Alert()*.
 */
void HDC302X_DRIVER_Get_Set_High_Alert(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Store_Set_High_Alert

   Summary:
   Persists the internally cached high‑alert thresholds to
   non‑volatile memory.

   Description:
   After *Get_Set_High_Alert()* has filled the cache, this routine
   writes those values into EEPROM/flash.  No I²C transaction occurs.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Call only after a successful read.
 */
void HDC302X_DRIVER_Store_Set_High_Alert(void);

/**
   Function:
   HDC302X_DRIVER_Set_Set_High_Alert

   Summary:
   Writes the high‑alert threshold registers to the sensor.

   Description:
   The routine takes the cached thresholds and writes them
   back to the device at `I2C_ADDRESS`.  This is used after a
   calibration or configuration change.

   Parameters:
   @param I2C_ADDRESS - sensor address where thresholds are written

   Returns:
   None.

   Remarks:
   The sensor will start generating alerts as soon as the new
   limits are programmed.
 */
void HDC302X_DRIVER_Set_Set_High_Alert(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Get_Clear_High_Alert

   Summary:
   Reads the clear‑high‑alert threshold registers from the sensor.

   Description:
   Similar to *Get_Set_High_Alert()* but for the thresholds
   that must be reached to clear an active high alert.
   The routine caches the two 16‑bit values locally.

   Parameters:
   @param I2C_ADDRESS - sensor address

   Returns:
   None.

   Remarks:
   Cached values can be stored with *Store_Clear_High_Alert()*.
 */
void HDC302X_DRIVER_Get_Clear_High_Alert(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Store_Clear_High_Alert

   Summary:
   Persists the clear‑high‑alert thresholds to non‑volatile memory.

   Description:
   Writes the cached values into EEPROM/flash.  No I²C is performed.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Call only after *Get_Clear_High_Alert()* has read the registers.
 */
void HDC302X_DRIVER_Store_Clear_High_Alert(void);

/**
   Function:
   HDC302X_DRIVER_Set_Clear_High_Alert

   Summary:
   Writes the clear‑high‑alert thresholds to the sensor.

   Description:
   The routine takes the cached values and writes them
   back to the device at `I2C_ADDRESS`.

   Parameters:
   @param I2C_ADDRESS - sensor address where thresholds are written

   Returns:
   None.

   Remarks:
   The sensor will clear any active high alert when the measured values
   drop below these limits.
 */
void HDC302X_DRIVER_Set_Clear_High_Alert(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Get_Set_Low_Alert

   Summary:
   Reads the low‑alert threshold registers from the sensor.

   Description:
   The routine reads temperature and humidity low‑alert
   thresholds at `I2C_ADDRESS` and caches them locally.
   These values trigger alerts when readings fall below
   the configured limits.

   Parameters:
   @param I2C_ADDRESS - sensor address

   Returns:
   None.

   Remarks:
   Persist with *Store_Set_Low_Alert()* if desired.
 */
void HDC302X_DRIVER_Get_Set_Low_Alert(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Store_Set_Low_Alert

   Summary:
   Persists the low‑alert thresholds to non‑volatile memory.

   Description:
   Writes the cached values into EEPROM/flash.
   No I²C transaction occurs.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Call only after *Get_Set_Low_Alert()* has succeeded.
 */
void HDC302X_DRIVER_Store_Set_Low_Alert(void);

/**
   Function:
   HDC302X_DRIVER_Set_Set_Low_Alert

   Summary:
   Writes the low‑alert thresholds to the sensor.

   Description:
   The routine writes the cached temperature and humidity
   low‑alert codes back to the device at `I2C_ADDRESS`.

   Parameters:
   @param I2C_ADDRESS - sensor address where thresholds are written

   Returns:
   None.

   Remarks:
   Alerts will be generated when readings fall below these limits.
 */
void HDC302X_DRIVER_Set_Set_Low_Alert(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Get_Clear_Low_Alert

   Summary:
   Reads the clear‑low‑alert threshold registers from the sensor.

   Description:
   Similar to *Get_Set_Low_Alert()* but for thresholds that
   must be crossed to clear an active low alert.
   The values are cached locally.

   Parameters:
   @param I2C_ADDRESS - sensor address

   Returns:
   None.

   Remarks:
   Persist with *Store_Clear_Low_Alert()* if required.
 */
void HDC302X_DRIVER_Get_Clear_Low_Alert(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Store_Clear_Low_Alert

   Summary:
   Persists the clear‑low‑alert thresholds to non‑volatile memory.

   Description:
   Writes the cached values into EEPROM/flash.  No I²C occurs.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Call only after *Get_Clear_Low_Alert()* has read the registers.
 */
void HDC302X_DRIVER_Store_Clear_Low_Alert(void);

/**
   Function:
   HDC302X_DRIVER_Set_Clear_Low_Alert

   Summary:
   Writes the clear‑low‑alert thresholds to the sensor.

   Description:
   The routine writes the cached low‑alert codes back
   to the device at `I2C_ADDRESS`.

   Parameters:
   @param I2C_ADDRESS - sensor address where thresholds are written

   Returns:
   None.

   Remarks:
   Alerts will be cleared when measurements rise above these limits.
 */
void HDC302X_DRIVER_Set_Clear_Low_Alert(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Enter_Auto_Measurement_Mode

   Summary:
   Configures the sensor to perform continuous, automatic
   temperature and humidity measurements.

   Description:
   The routine writes the appropriate mode register at
   `I2C_ADDRESS` so that the device samples its internal
   sensors every 1 s (or as configured).  Once entered,
   readings can be retrieved via *Get_Auto_Measure_Values()*.

   Parameters:
   @param I2C_ADDRESS - sensor address to configure

   Returns:
   None.

   Remarks:
   The sensor will automatically generate alerts while in
   auto‑measurement mode.
 */
void HDC302X_DRIVER_Enter_Auto_Measurement_Mode(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Exit_Auto_Measurement_Mode

   Summary:
   Stops automatic sampling and returns the sensor to
   manual‑measurement mode.

   Description:
   The routine writes the mode register at `I2C_ADDRESS`
   so that subsequent measurements must be requested manually.
   This conserves power when continuous data is not needed.

   Parameters:
   @param I2C_ADDRESS - sensor address

   Returns:
   None.

   Remarks:
   No alerts are generated while the device is idle.
 */
void HDC302X_DRIVER_Exit_Auto_Measurement_Mode(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Start_Manual_Measurement

   Summary:
   Triggers a single temperature/humidity measurement.

   Description:
   The routine writes the “trigger” command to the sensor at
   `I2C_ADDRESS`.  Once completed, the data can be read via
 *Get_Manual_Measure_Values()* or automatically stored by the driver.

   Parameters:
   @param I2C_ADDRESS - sensor address

   Returns:
   None.

   Remarks:
   The device takes ~1 s to complete a measurement.
 */
void HDC302X_DRIVER_Start_Manual_Measurement(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Get_Manual_Measure_Values

   Summary:
   Reads the raw temperature and humidity values from a
   manual measurement.

   Description:
   The routine performs two I²C reads at `I2C_ADDRESS` – one for
   temperature and one for humidity – and stores the 16‑bit results
   in an internal cache.  These values can later be converted to
   physical units with *Calculation_Temperature()* / *Calculation_Humidity()*.

   Parameters:
   @param I2C_ADDRESS - sensor address

   Returns:
   None.

   Remarks:
   Call only after *Start_Manual_Measurement()* has completed.
 */
void HDC302X_DRIVER_Get_Manual_Measure_Values(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Get_Auto_Measure_Values

   Summary:
   Retrieves the most recent measurement taken in auto‑mode.

   Description:
   The routine reads the temperature and humidity registers
   at `I2C_ADDRESS` and caches the 16‑bit results.
   This is typically called by *HDC302X_DRIVER_Tasks()* after a
   new sample becomes available.

   Parameters:
   @param I2C_ADDRESS - sensor address

   Returns:
   None.

   Remarks:
   The data are ready to be converted or stored.
 */
void HDC302X_DRIVER_Get_Auto_Measure_Values(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Store_Measurement_Values

   Summary:
   Persists the latest temperature and humidity measurement
   to non‑volatile memory.

   Description:
   After a successful *Get_* call, this routine writes the cached
   values into EEPROM/flash.  No I²C is performed during the write.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Call only after a new measurement has been read.
 */
void HDC302X_DRIVER_Store_Measurement_Values(void);

/**
   Function:
   HDC302X_DRIVER_Get_Minimum_Temperature_Value

   Summary:
   Reads the sensor’s minimum‑temperature register.

   Description:
   The routine performs an I²C read at `I2C_ADDRESS` and caches
   the 16‑bit value.  This register holds the lowest temperature
   that has been measured since power‑up or since the last reset.

   Parameters:
   @param I2C_ADDRESS - sensor address

   Returns:
   None.

   Remarks:
   Persist with *Store_Minimum_Temperature_Value()* if needed.
 */
void HDC302X_DRIVER_Get_Minimum_Temperature_Value(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Store_Minimum_Temperature_Value

   Summary:
   Persists the cached minimum‑temperature value to non‑volatile memory.

   Description:
   Writes the value read by *Get_* into EEPROM/flash.
   No I²C transaction occurs during this write.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Call only after a successful read.
 */
void HDC302X_DRIVER_Store_Minimum_Temperature_Value(void);

/**
   Function:
   HDC302X_DRIVER_Get_Maximum_Temperature_Value

   Summary:
   Reads the sensor’s maximum‑temperature register.

   Description:
   The routine performs an I²C read at `I2C_ADDRESS` and caches
   the 16‑bit value.  This register holds the highest temperature
   that has been measured since power‑up or since the last reset.

   Parameters:
   @param I2C_ADDRESS - sensor address

   Returns:
   None.

   Remarks:
   Persist with *Store_Maximum_Temperature_Value()* if required.
 */
void HDC302X_DRIVER_Get_Maximum_Temperature_Value(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Store_Maximum_Temperature_Value

   Summary:
   Persists the cached maximum‑temperature value to non‑volatile memory.

   Description:
   Writes the value read by *Get_* into EEPROM/flash.
   No I²C occurs during this write.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Call only after a successful read.
 */
void HDC302X_DRIVER_Store_Maximum_Temperature_Value(void);

/**
   Function:
   HDC302X_DRIVER_Get_Minimum_Humidity_Value

   Summary:
   Reads the sensor’s minimum‑humidity register.

   Description:
   The routine performs an I²C read at `I2C_ADDRESS` and caches
   the 16‑bit value.  This register holds the lowest relative
   humidity measured since power‑up or since the last reset.

   Parameters:
   @param I2C_ADDRESS - sensor address

   Returns:
   None.

   Remarks:
   Persist with *Store_Minimum_Humidity_Value()* if desired.
 */
void HDC302X_DRIVER_Get_Minimum_Humidity_Value(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Store_Minimum_Humidity_Value

   Summary:
   Persists the cached minimum‑humidity value to non‑volatile memory.

   Description:
   Writes the value read by *Get_* into EEPROM/flash.
   No I²C transaction occurs during this write.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Call only after a successful read.
 */
void HDC302X_DRIVER_Store_Minimum_Humidity_Value(void);

/**
   Function:
   HDC302X_DRIVER_Get_Maximum_Humidity_Value

   Summary:
   Reads the sensor’s maximum‑humidity register.

   Description:
   The routine performs an I²C read at `I2C_ADDRESS` and caches
   the 16‑bit value.  This register holds the highest relative
   humidity measured since power‑up or since the last reset.

   Parameters:
   @param I2C_ADDRESS - sensor address

   Returns:
   None.

   Remarks:
   Persist with *Store_Maximum_Humidity_Value()* if needed.
 */
void HDC302X_DRIVER_Get_Maximum_Humidity_Value(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Store_Maximum_Humidity_Value

   Summary:
   Persists the cached maximum‑humidity value to non‑volatile memory.

   Description:
   Writes the value read by *Get_* into EEPROM/flash.
   No I²C transaction occurs during this write.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Call only after a successful read.
 */
void HDC302X_DRIVER_Store_Maximum_Humidity_Value(void);

/**
   Function:
   HDC302X_DRIVER_Calculation_Temperature

   Summary:
   Converts a raw temperature register value to degrees Celsius.

   Description:
   The TI datasheet specifies the linear conversion:

         T(°C) = (raw / 65536.0 * 165.0) - 40.0

   The routine applies this formula and stores the result in an
   internal variable for later retrieval or printing.

   Parameters:
   @param T_VALUE - raw 16‑bit temperature reading from the sensor

   Returns:
   None.

   Remarks:
   Call after *Get_* functions have populated `T_VALUE`.
 */
void HDC302X_DRIVER_Calculation_Temperature(uint16_t T_VALUE);

/**
   Function:
   HDC302X_DRIVER_Calculation_Humidity

   Summary:
   Converts a raw humidity register value to percent relative humidity.

   Description:
   The TI datasheet specifies the linear conversion:

         RH(%) = (raw / 65536.0 * 100.0)

   The routine applies this formula and stores the result in an
   internal variable for later use.

   Parameters:
   @param H_VALUE - raw 16‑bit humidity reading from the sensor

   Returns:
   None.

   Remarks:
   Call after *Get_* functions have populated `H_VALUE`.
 */
void HDC302X_DRIVER_Calculation_Humidity(uint16_t H_VALUE);

/**
   Function:
   HDC302X_DRIVER_Get_Sensor_Status

   Summary:
   Reads the sensor’s status register.

   Description:
   The routine performs an I²C read at `I2C_ADDRESS` and caches
   the 8‑bit status byte.  Bits in this register indicate
   e.g., alert state, measurement completion, or fault conditions.

   Parameters:
   @param I2C_ADDRESS - sensor address

   Returns:
   None.

   Remarks:
   Persist with *Store_Sensor_Status()* if required.
 */
void HDC302X_DRIVER_Get_Sensor_Status(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Store_Sensor_Status

   Summary:
   Persists the cached sensor status byte to non‑volatile memory.

   Description:
   Writes the value read by *Get_* into EEPROM/flash.
   No I²C transaction occurs during this write.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Call only after *Get_Sensor_Status()* has succeeded.
 */
void HDC302X_DRIVER_Store_Sensor_Status(void);

/**
   Function:
   HDC302X_DRIVER_Get_NIST_3

   Summary:
   Reads the third NIST calibration register from the sensor.

   Description:
   The TI device stores three calibration values (NIST1‑NIST3)
   that can be used for advanced temperature/humidity
   compensation.  This routine reads NIST3 at `I2C_ADDRESS`
   and caches it locally.

   Parameters:
   @param I2C_ADDRESS - sensor address

   Returns:
   None.

   Remarks:
   Persist with *Store_NIST_3()* if needed.
 */
void HDC302X_DRIVER_Get_NIST_3(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Store_NIST_3

   Summary:
   Persists the cached NIST3 value to non‑volatile memory.

   Description:
   Writes the value read by *Get_* into EEPROM/flash.
   No I²C transaction occurs during this write.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Call only after a successful read.
 */
void HDC302X_DRIVER_Store_NIST_3(void);

/**
   Function:
   HDC302X_DRIVER_Get_NIST_2

   Summary:
   Reads the second NIST calibration register from the sensor.

   Description:
   See *Get_NIST_3()* for details; this routine targets
   the NIST2 register instead.

   Parameters:
   @param I2C_ADDRESS - sensor address

   Returns:
   None.

   Remarks:
   Persist with *Store_NIST_2()* if required.
 */
void HDC302X_DRIVER_Get_NIST_2(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Store_NIST_2

   Summary:
   Persists the cached NIST2 value to non‑volatile memory.

   Description:
   Writes the value read by *Get_* into EEPROM/flash.
   No I²C transaction occurs during this write.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Call only after a successful read.
 */
void HDC302X_DRIVER_Store_NIST_2(void);

/**
   Function:
   HDC302X_DRIVER_Get_NIST_1

   Summary:
   Reads the first NIST calibration register from the sensor.

   Description:
   See *Get_NIST_3()* for details; this routine targets
   the NIST1 register instead.

   Parameters:
   @param I2C_ADDRESS - sensor address

   Returns:
   None.

   Remarks:
   Persist with *Store_NIST_1()* if needed.
 */
void HDC302X_DRIVER_Get_NIST_1(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Store_NIST_1

   Summary:
   Persists the cached NIST1 value to non‑volatile memory.

   Description:
   Writes the value read by *Get_* into EEPROM/flash.
   No I²C transaction occurs during this write.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Call only after a successful read.
 */
void HDC302X_DRIVER_Store_NIST_1(void);

/**
   Function:
   HDC302X_DRIVER_Soft_Reset

   Summary:
   Sends the soft‑reset command to the sensor.

   Description:
   The routine writes the reset register (0xE7) at
   `I2C_ADDRESS`.  After this call the device reboots and all
   registers return to their factory defaults.  A short delay is
   required before any subsequent I²C operation can be performed.

   Parameters:
   @param I2C_ADDRESS - sensor address

   Returns:
   None.

   Remarks:
   Use only when the device becomes unresponsive.
 */
void HDC302X_DRIVER_Soft_Reset(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Enable_Heater

   Summary:
   Activates the on‑chip heater.

   Description:
   The routine writes the heater enable bit at `I2C_ADDRESS`.
   The device will then draw a small current (up to 200 mA) to
   raise its temperature, which can be useful for calibration or
   moisture removal in humid environments.

   Parameters:
   @param I2C_ADDRESS - sensor address

   Returns:
   None.

   Remarks:
   The heater should only be left on for short periods to avoid
   damaging the device.
 */
void HDC302X_DRIVER_Enable_Heater(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Disable_Heater

   Summary:
   Deactivates the on‑chip heater.

   Description:
   The routine clears the heater enable bit at `I2C_ADDRESS`,
   allowing normal operation to resume and saving power.

   Parameters:
   @param I2C_ADDRESS - sensor address

   Returns:
   None.

   Remarks:
   Call after the heater has served its purpose.
 */
void HDC302X_DRIVER_Disable_Heater(uint8_t I2C_ADDRESS);

/**
   Function:
   HDC302X_DRIVER_Configuration_Heater

   Summary:
   Configures the heater current by writing two bytes.

   Description:
   The routine writes `CURRENT_MSB` and `CURRENT_LSB` to
   the heater‑current register at `I2C_ADDRESS`.  These values
   determine the output current (up to ~200 mA) in a linear scale.
   The sensor then uses this setting while the heater is enabled.

   Parameters:
   @param I2C_ADDRESS   - sensor address
   @param CURRENT_MSB   - most‑significant byte of desired current
   @param CURRENT_LSB   - least‑significant byte of desired current

   Returns:
   None.

   Remarks:
   Ensure that the combined value is within the device’s limits.
 */
void HDC302X_DRIVER_Configuration_Heater(uint8_t I2C_ADDRESS,
                                         uint8_t CURRENT_MSB,
                                         uint8_t CURRENT_LSB);

/**
   Function:
   HDC302X_DRIVER_Calculation_CRC

   Summary:
   Computes the 8‑bit CRC for a message buffer.

   Description:
   The TI sensor uses an 8‑bit CRC (polynomial 0x31, initial
   value 0xFF) over all bytes except the last.  This routine
   accepts an array `MESSAGE` and its length `MESSAGE_LENGTH`,
   applies the algorithm defined in the datasheet, and returns
   the resulting CRC byte.

   Parameters:
   @param MESSAGE         - pointer to message buffer
   @param MESSAGE_LENGTH  - number of bytes over which to compute CRC

   Returns:
   @return uint8_t - calculated CRC value

   Remarks:
   The returned CRC is typically appended to a write command
   before transmitting it over I²C.
 */
uint8_t HDC302X_DRIVER_Calculation_CRC(uint8_t MESSAGE[],
                                       uint8_t MESSAGE_LENGTH);

/**
   Function:
   HDC302X_DRIVER_Calculation_Array_CRC

   Summary:
   Computes the CRC for a two‑byte message.

   Description:
   A convenience wrapper that takes two individual bytes
   (`MESSAGE_0`, `MESSAGE_1`), places them in a temporary array,
   and calls *Calculation_CRC()*.  This is useful when only a
   short command needs a checksum.

   Parameters:
   @param MESSAGE_0 - first byte of the message
   @param MESSAGE_1 - second byte of the message

   Returns:
   @return uint8_t - calculated CRC value

   Remarks:
   The function internally creates a 2‑byte array and reuses
 *Calculation_CRC()*.
 */
uint8_t HDC302X_DRIVER_Calculation_Array_CRC(uint8_t MESSAGE_0,
                                             uint8_t MESSAGE_1);

/**
   Function:
   HDC302X_DRIVER_Set_Offset_Code

   Summary:
   Converts temperature and humidity values into offset codes.

   Description:
   The sensor’s internal offset registers expect a code that
   represents the desired calibration.  This routine takes a
   raw temperature (`TEMPERATURE`) and humidity (`HUMIDITY`)
   (both 16‑bit) and applies the manufacturer’s mapping to
   produce a 16‑bit offset code that can be written to the
   sensor’s offset registers.

   Parameters:
   @param TEMPERATURE - raw temperature value (typically from *Get_* routine)
   @param HUMIDITY   - raw humidity value

   Returns:
   @return uint16_t - computed offset code

   Remarks:
   The exact conversion formula is defined in the TI datasheet.
 */
uint16_t HDC302X_DRIVER_Set_Offset_Code(uint16_t TEMPERATURE,
                                        uint16_t HUMIDITY);

/**
   Function:
   HDC302X_DRIVER_Set_Alert_Code

   Summary:
   Converts temperature and humidity values into alert codes.

   Description:
   The sensor’s alert threshold registers expect a code that
   represents the desired limit.  This routine takes a raw
   temperature (`TEMPERATURE`) and humidity (`HUMIDITY`)
   (both 16‑bit) and applies the manufacturer’s mapping to
   produce a 16‑bit alert code suitable for writing to the
   sensor’s alert registers.

   Parameters:
   @param TEMPERATURE - raw temperature value
   @param HUMIDITY   - raw humidity value

   Returns:
   @return uint16_t - computed alert code

   Remarks:
   The conversion follows the algorithm specified in the datasheet.
 */
uint16_t HDC302X_DRIVER_Set_Alert_Code(uint16_t TEMPERATURE,
                                       uint16_t HUMIDITY);

/**
    Function:
    void HDC302X_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)

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