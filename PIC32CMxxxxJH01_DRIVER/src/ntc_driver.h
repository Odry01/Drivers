/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    ntc_driver.h

  Status:
    In development
 
  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "NTC_DRIVER_Initialize" and "NTC_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "NTC_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _NTC_DRIVER_H
#define _NTC_DRIVER_H

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
    NTC_DRIVER_STATE_INIT = 0,
    NTC_DRIVER_STATE_IDLE,
    NTC_DRIVER_STATE_START_MEASUREMENT,
    NTC_DRIVER_STATE_WAIT_FOR_MEASUREMENT,
    NTC_DRIVER_STATE_GET_RESULT,
    NTC_DRIVER_STATE_CALCULATION_TEMPERATURE,
    NTC_DRIVER_STATE_STORE_DATA,
} NTC_DRIVER_STATES;

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
    NTC_DRIVER_STATES state;

    /* Driver variables */
    volatile bool NTC_TASK_START;
    volatile bool NTC_TASK_COMPLETED;
    volatile bool ADC0_RESULT_READY;
} NTC_DRIVER_DATA;

typedef struct
{
    uint16_t T_VALUE;
    float CELSIUS_TEMPERATURE;
} NTC_DRIVER_SENSOR_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

void NTC_DRIVER_Callback(ADC_STATUS STATUS, uintptr_t CONTEXT);

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/**
    Function:
    void NTC_DRIVER_Initialize(void)

    Summary:
    Initializes the NTC driver module.

    Description:
    This routine performs all one‑time configuration required for the
    NTC thermistor interface (typically an ADC channel).  It sets up the
    hardware registers, configures sample buffers, and clears any pending
    status flags so that NTC_DRIVER_Tasks() can operate correctly.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
*/
void NTC_DRIVER_Initialize(void);

/**
    Function:
    void NTC_DRIVER_Tasks(void)

    Summary:
    Main task routine for the NTC driver.

    Description:
    This function contains the state‑machine that handles all NTC
    operations.  It polls the ADC, triggers conversions, updates
    status flags and performs any necessary error handling.
    It is intended to be called repeatedly from the application loop.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
*/
void NTC_DRIVER_Tasks(void);

/**
    Function:
    bool NTC_DRIVER_Get_Task_Start_Status(void)

    Summary:
    Retrieves the current “task start” flag for the NTC driver.

    Description:
    Indicates whether a new temperature measurement has been requested.  
    The application sets this flag via NTC_DRIVER_Set_Task_Start_Status(true)
    and clears it when processing is finished.

    Parameters:
    None.

    Returns:
    @return bool – `true` if a task is pending, otherwise `false`.

    Remarks:
    None.
*/
bool NTC_DRIVER_Get_Task_Start_Status(void);

/**
    Function:
    void NTC_DRIVER_Set_Task_Start_Status(bool STATUS)

    Summary:
    Sets the “task start” flag for the NTC driver.

    Description:
    Allows the application to signal that a new temperature measurement should begin.  
    The driver will act on this flag during its next call to
    NTC_DRIVER_Tasks().

    Parameters:
    @param bool STATUS – Desired state of the task‑start flag (`true` = pending, `false` = cleared).

    Returns:
    None.

    Remarks:
    None.
*/
void NTC_DRIVER_Set_Task_Start_Status(bool STATUS);

/**
    Function:
    bool NTC_DRIVER_Get_Task_Completed_Status(void)

    Summary:
    Retrieves the current “task completed” flag for the NTC driver.

    Description:
    Indicates whether the most recent temperature measurement has finished
    successfully.  The driver sets this flag when the ADC conversion is complete and the result
    has been processed.

    Parameters:
    None.

    Returns:
    @return bool – `true` if the last task is complete, otherwise `false`.

    Remarks:
    None.
*/
bool NTC_DRIVER_Get_Task_Completed_Status(void);

/**
    Function:
    void NTC_DRIVER_Set_Task_Completed_Status(bool STATUS)

    Summary:
    Sets the “task completed” flag for the NTC driver.

    Description:
    Allows the driver to mark a temperature measurement as finished.  
    The application may clear this flag when it is ready for another
    measurement.

    Parameters:
    @param bool STATUS – Desired state of the task‑completed flag (`true` = complete, `false` = not yet).

    Returns:
    None.

    Remarks:
    None.
*/
void NTC_DRIVER_Set_Task_Completed_Status(bool STATUS);

/**
    Function:
    void NTC_DRIVER_Calculation_Temperature(uint16_t T_VALUE)

    Summary:
    Calculates temperature from a raw ADC value.

    Description:
    The routine applies the Steinhart–Hart or lookup‑table algorithm to
    convert the 12/10‑bit `T_VALUE` (raw ADC reading) into a temperature
    in degrees Celsius.  The result is stored in an internal variable that
    can be retrieved by other parts of the application.

    Parameters:
    @param uint16_t T_VALUE – Raw ADC value from the NTC sensor channel.

    Returns:
    None.

    Remarks:
    None.
*/
void NTC_DRIVER_Calculation_Temperature(uint16_t T_VALUE);

/**
    Function:
    void NTC_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)

    Summary:
    Prints the current state of the NTC driver to a console.

    Description:
    The routine writes human‑readable information – such as the last
    raw ADC value, the computed temperature, and any error counters –
    to the specified `SYS_CONSOLE_HANDLE`.  It is intended for debugging
    and diagnostic purposes only.

    Parameters:
    @param SYS_CONSOLE_HANDLE CONSOLE_HANDLE – Handle to an MPLAB Harmony console object.

    Returns:
    None.

    Remarks:
    None.
*/
void NTC_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _NTC_DRIVER_H */

/*******************************************************************************
 End of File
 */