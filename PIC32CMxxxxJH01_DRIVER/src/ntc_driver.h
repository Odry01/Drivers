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
    NTC_DRIVER_Initialize

    Summary:
    Performs initialization of driver for NTC temperature sensor.

    Description:
    The routine register ADC callback and enable ADC peripheral.

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
    NTC_DRIVER_Tasks

    Summary:
    Executes periodic driver tasks.

    Description:
    The routine measure temperature via ADC peripheral. It use a state machine
    for performing measurement.

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
bool NTC_DRIVER_Get_Task_Start_Status(void);

/**
    Function:
    void NTC_DRIVER_Set_Task_Start_Status(bool STATUS)

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
void NTC_DRIVER_Set_Task_Start_Status(bool STATUS);

/**
    Function:
    bool NTC_DRIVER_Get_Task_Completed_Status(void)

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
bool NTC_DRIVER_Get_Task_Completed_Status(void);

/**
    Function:
    void NTC_DRIVER_Set_Task_Completed_Status(bool STATUS)

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
void NTC_DRIVER_Set_Task_Completed_Status(bool STATUS);

/**
    Function:
    void NTC_DRIVER_Calculation_Temperature(uint16_t T_VALUE)

    Summary:
    Converts the raw temperature value to degrees Celsius.

    Description:
    Converts the raw temperature value to degrees Celsius.
    Equation you will find in NTC datasheet.

    Parameters:
    @param T_VALUE - raw ADC value from the NTC sensor

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