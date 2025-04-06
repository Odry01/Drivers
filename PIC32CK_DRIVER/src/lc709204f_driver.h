/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    lc709204f_driver.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "LC709204F_DRIVER_Initialize" and "LC709204F_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "LC709204F_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _LC709204F_DRIVER_H
#define _LC709204F_DRIVER_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"

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

#define LC709204F_I2CADDR 0x0B /// LC709204F default i2c address

#define LC709204F_REG_TIME_TO_EMPTY                        0x03 /// R - Displays estimated time to empty.
#define LC709204F_REG_BEFORE_RSOC                          0x04 /// W - Optional Command, especially for obtaining the voltage with intentional timing after power on reset.
#define LC709204F_REG_TIME_TO_FULL                         0x05 /// R - Displays estimated time to full.
#define LC709204F_REG_TSENSE1_THERMISTOR_B                 0x06 /// R/W - Sets B?constant of the TSENSE1 thermistor.
#define LC709204F_REG_INITIAL_RSOC                         0x07 /// W - Initialize RSOC with current voltage when 0xAA55 is set.
#define LC709204F_REG_CELL_TEMPERATURE_TSENSE1             0x08 /// R - Displays Cell Temperature / W - Sets Cell Temperature in I2C mode.
#define LC709204F_REG_CELL_VOLTAGE                         0x09 /// R - Displays Cell Voltage.
#define LC709204F_REG_CURRENT_DIRECTION                    0x0A /// R/W - Selects Auto/Charge/Discharge mode.
#define LC709204F_REG_APA                                  0x0B /// R/W - Sets Adjustment parameter.
#define LC709204F_REG_APT                                  0x0C /// R/W - Sets a value to adjust temperature measurement delay timing.
#define LC709204F_REG_RSOC                                 0x0D /// R/W - Displays RSOC value based on a 0?100 scale.
#define LC709204F_REG_TSENSE2_THERMISTOR_B                 0x0E /// R/W - Sets B?constant of the TSENSE2 thermistor.
#define LC709204F_REG_ITE                                  0x0F /// R - Displays RSOC value based on a 0?1000 scale.
#define LC709204F_REG_IC_VERSION                           0x11 /// R - Displays an internal management code.
#define LC709204F_REG_CHANGE_OF_THE_PARAMETER              0x12 /// R/W - Selects a battery profile.
#define LC709204F_REG_ALARM_LOW_RSOC                       0x13 /// R/W - Sets RSOC threshold to generate Alarm signal.
#define LC709204F_REG_ALARM_LOW_CELL_VOLTAGE               0x14 /// R/W - Sets voltage threshold to generate Low Cell Voltage Alarm signal.
#define LC709204F_REG_IC_POWER_MODE                        0x15 /// R/W - Selects Power mode.
#define LC709204F_REG_STATUS_BIT                           0x16 /// R/W - Controls TSENSE1 and TSENSE2 thermistors.
#define LC709204F_REG_CYCLE_COUNT                          0x17 /// R - Displays cycle count.
#define LC709204F_REG_BATTERY_STATUS                       0x19 /// R/W - Displays various kinds of alarm and estimated state of the battery.
#define LC709204F_REG_NUMBER_OF_THE_PARAMETER              0x1A /// R - Displays Battery profile code.
#define LC709204F_REG_TERMINATION_CURRENT_RATE             0x1C /// R/W - Sets termination current rate.
#define LC709204F_REG_EMPTY_CELL_VOLTAGE                   0x1D /// R/W - Sets empty cell voltage.
#define LC709204F_REG_ITE_OFFSET                           0x1E /// R/W - Sets ITE so that RSOC is 0%.
#define LC709204F_REG_ALARM_HIGH_CELL_VOLTAGE              0x1F /// R/W - Sets Voltage threshold to generate High Cell Voltage Alarm signal.
#define LC709204F_REG_ALARM_LOW_TEMPERATURE                0x20 /// R/W - Sets Voltage threshold to generate Low Temperature alarm signal.
#define LC709204F_REG_ALARM_HIGH_TEMPERATURE               0x21 /// R/W - Sets Voltage threshold to generate High Temperature alarm signal.
#define LC709204F_REG_TOTAL_RUN_TIME_LOWER_16BIT           0x24 /// R/W - Displays operating time (lower 16bit).
#define LC709204F_REG_TOTAL_RUN_TIME_HIGHER_8BIT           0x25 /// R/W - Displays operating time (higher 8bit)
#define LC709204F_REG_ACCUMULATED_TEMPERATURE_LOWER_16BIT  0x26 /// R/W - Displays accumulated temperature (lower 16bit)
#define LC709204F_REG_ACCUMULATED_TEMPERATURE_HIGHER_16BIT 0x27 /// R/W - Displays accumulated temperature (higher 16bit)
#define LC709204F_REG_ACCUMULATED_RSOC_LOWER_16BIT         0x28 /// R/W - Displays accumulated RSOCC (lower 16bit)
#define LC709204F_REG_ACCUMULATED_RSOC_HIGHER_16BIT        0x29 /// R/W - Displays accumulated RSOCC (higher 16bit)
#define LC709204F_REG_MAXIMUM_CELL_VOLTAGE                 0x2A /// R/W - Displays the maximum historical Cell Voltage.
#define LC709204F_REG_MINIMUM_CELL_VOLTAGE                 0x2B /// R/W - Displays the minimum historical Cell Voltage.
#define LC709204F_REG_MAXIMUM_CELL_TEMPERATURE_TSENSE1     0x2C /// R/W - Displays the historical maximum temperature of TSENSE1.
#define LC709204F_REG_MINIMUM_CELL_TEMPERATURE_TSENSE1     0x2D /// R/W - Displays the historical minimum temperature of TSENSE1.
#define LC709204F_REG_AMBIENT_TEMPERATURE_TSENSE2          0x30 /// R - Displays Ambient Temperature.
#define LC709204F_REG_STATE_OF_HEALTH                      0x32 /// R - Displays State of Health of a battery on a 0?100 scale.
#define LC709204F_REG_USER_ID_LOWER_16BIT                  0x36 /// R - Displays 32bit User Id (lower 16bit).
#define LC709204F_REG_USER_ID_HIGHER_16BIT                 0x37 /// R - Displays 32bit User Id (higher 16bit).

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
    /* Driver variables */
} LC709204F_DRIVER_DATA;

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

/*******************************************************************************
  Function:
    void LC709204F_DRIVER_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    LC709204F_DRIVER_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    LC709204F_DRIVER_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
 */

void LC709204F_DRIVER_Initialize(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _LC709204F_DRIVER_H */

/*******************************************************************************
 End of File
 */