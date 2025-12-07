/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    timer_driver.h

  Status:
    In development
 
  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "TIMER_DRIVER_Initialize" and "TIMER_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "TIMER_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _TIMER_DRIVER_H
#define _TIMER_DRIVER_H

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

#define START_UP_TIMER      10000
#define MAIN_TIMER          5000
#define BUS_TIMER           500
#define WAIT_TIMER          10

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
    /* Driver variables */
    SYS_TIME_HANDLE START_UP_TMR;
    SYS_TIME_HANDLE MAIN_TMR;
    SYS_TIME_HANDLE BUS_TMR;
    SYS_TIME_HANDLE WAIT_TMR;
    volatile bool START_UP_TMR_EXPIRED;
    volatile bool MAIN_TMR_EXPIRED;
    volatile bool BUS_TMR_EXPIRED;
    volatile bool WAIT_TMR_EXPIRED;
} TIMER_DRIVER_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

void Start_Up_TMR_Callback(uintptr_t CONTEXT);

void Main_TMR_Callback(uintptr_t CONTEXT);

void Bus_TMR_Callback(uintptr_t CONTEXT);

void Wait_TMR_Callback(uintptr_t CONTEXT);

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/**
    Function:
    void TIMER_DRIVER_Initialize(void)

    Summary:
    Performs initialization of the timer subsystem.

    Description:
    Initialize all defined timers, configure callbacks for each timer,
    and set the timer periods. Finally, stop all defined timers.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void TIMER_DRIVER_Initialize(void);

/**
    Function:
    bool TIMER_DRIVER_Get_Start_Up_TMR_Status(void)

    Summary:
    Retrieves the current status of the start-up timer.

    Description:
    Returns "true" if the start-up timer is finished, otherwise returns "false".

    Parameters:
    None.

    Returns:
    @return bool - true if the start-up timer is finished otherwise false

    Remarks:
    Use this timer after MCU boot. You can wait for initialize peripheral. 
 */
bool TIMER_DRIVER_Get_Start_Up_TMR_Status(void);

/**
    Function:
    void TIMER_DRIVER_Set_Start_Up_TMR_Status(bool STATUS)

    Summary:
    Sets the status flag for the start-up timer.

    Description:
    When start-up timer didn't finished function return "false", 
    after timer expired function return "true".

    Parameters:
    @param STATUS - status of start-up timer

    Returns:
    None.

    Remarks:
    Use this timer after MCU boot. You can wait for initialize peripheral.
 */
void TIMER_DRIVER_Set_Start_Up_TMR_Status(bool STATUS);

/**
    Function:
    void TIMER_DRIVER_Start_Start_Up_TMR(void)

    Summary:
    Starts the start-up timer.

    Description:
    Starts the start-up timer for desired time.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    Use this timer after MCU boot. You can wait for initialize peripheral. 
 */
void TIMER_DRIVER_Start_Start_Up_TMR(void);

/**
    Function:
    void TIMER_DRIVER_Stop_Start_Up_TMR(void)

    Summary:
    Stops the start-up timer.

    Description:
    Stops the start-up timer. 

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    When the timer is not stopped, timer will be renewed.
    Use this timer after MCU boot. You can wait for initialize peripheral. 
 */
void TIMER_DRIVER_Stop_Start_Up_TMR(void);

/**
    Function:
    bool TIMER_DRIVER_Get_Main_TMR_Status(void)

    Summary:
    Retrieves the current status of the main timer.

    Description:
    Returns "true" if the main timer is finished, otherwise returns "false".

    Parameters:
    None.

    Returns:
    @return bool - true if the main timer is finished otherwise false

    Remarks:
    None.
 */
bool TIMER_DRIVER_Get_Main_TMR_Status(void);

/**
    Function:
    void TIMER_DRIVER_Set_Main_TMR_Status(bool STATUS)

    Summary:
    Sets the status flag for the main timer.

    Description:
    When main timer didn't finished function return "false", 
    after timer expired function return "true".

    Parameters:
    @param STATUS - status of main timer

    Returns:
    None.

    Remarks:
    None.
 */
void TIMER_DRIVER_Set_Main_TMR_Status(bool STATUS);

/**
    Function:
    void TIMER_DRIVER_Start_Main_TMR(void)

    Summary:
    Starts the main timer.

    Description:
    Starts the main timer for desired time.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void TIMER_DRIVER_Start_Main_TMR(void);

/**
    Function:
    void TIMER_DRIVER_Stop_Main_TMR(void)

    Summary:
    Stops the main timer.

    Description:
    Stops the main timer. 

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    When the timer is not stopped, timer will be renewed.
 */
void TIMER_DRIVER_Stop_Main_TMR(void);

/**
    Function:
    bool TIMER_DRIVER_Get_Bus_TMR_Status(void)

    Summary:
    Retrieves the current status of the bus timer.

    Description:
    Returns "true" if the bus timer is finished, otherwise returns "false".

    Parameters:
    None.

    Returns:
    @return bool - true if the bus timer is finished

    Remarks:
    Use this timer when you start communication on UART/SPI/I2C.
 */
bool TIMER_DRIVER_Get_Bus_TMR_Status(void);

/**
    Function:
    void TIMER_DRIVER_Set_Bus_TMR_Status(bool STATUS)

    Summary:
    Sets the status flag for the bus communication timer.

    Description:
    When bus timer didn't finished function return "false", 
    after timer expired function return "true".

    Parameters:
    @param STATUS - desired state of the bus timer flag

    Returns:
    None.

    Remarks:
    Use this timer when you start communication on UART/SPI/I2C.
 */
void TIMER_DRIVER_Set_Bus_TMR_Status(bool STATUS);

/**
    Function:
    void TIMER_DRIVER_Start_Bus_TMR(void)

    Summary:
    Starts the bus communication timer.

    Description:
    Starts the bus timer for desired time.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    Use this timer when you start communication on UART/SPI/I2C.
 */
void TIMER_DRIVER_Start_Bus_TMR(void);

/**
    Function:
    void TIMER_DRIVER_Stop_Bus_TMR(void)

    Summary:
    Stops the bus timer.

    Description:
    Stops the bus timer. 

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    Use this timer when you start communication on UART/SPI/I2C. 
    When the timer is not stopped, timer will be renewed.
 */
void TIMER_DRIVER_Stop_Bus_TMR(void);

/**
    Function:
    bool TIMER_DRIVER_Get_Wait_TMR_Status(void)

    Summary:
    Indicate the current status of the wait timer.

    Description:
    Returns "true" if the wait timer is finished, otherwise returns "false".

    Parameters:
    None.

    Returns:
    @return bool - true if the wait timer is finished

    Remarks:
    Use when you won't use delay function.
 */
bool TIMER_DRIVER_Get_Wait_TMR_Status(void);

/**
    Function:
    void TIMER_DRIVER_Set_Wait_TMR_Status(bool STATUS)

    Summary:
    Sets the status flag for the wait timer.

    Description:
    When wait timer didn't finished function return "false", 
    after timer expired function return "true".

    Parameters:
    @param STATUS - desired state of the wait timer flag

    Returns:
    None.

    Remarks:
    Use when you won't use delay function.
 */
void TIMER_DRIVER_Set_Wait_TMR_Status(bool STATUS);

/**
    Function:
    void TIMER_DRIVER_Start_Wait_TMR(void)

    Summary:
    Starts the wait timer.

    Description:
    Starts the wait timer for desired time.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    Use when you won't use delay function.
 */
void TIMER_DRIVER_Start_Wait_TMR(void);

/**
    Function:
    void TIMER_DRIVER_Stop_Wait_TMR(void)

    Summary:
    Stops the wait timer.

    Description:
    Stops the main timer.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    Use when you won't use delay function.
    When the timer is not stopped, timer will be renewed.
 */
void TIMER_DRIVER_Stop_Wait_TMR(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _TIMER_DRIVER_H */

/*******************************************************************************
 End of File
 */