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

#define MAIN_TIMER          5000
#define BUS_TIMER           250
#define WAIT_TIMER          25

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
    SYS_TIME_HANDLE MAIN_TMR;
    SYS_TIME_HANDLE BUS_TMR;
    SYS_TIME_HANDLE WAIT_TMR;
    volatile bool MAIN_TMR_EXPIRED;
    volatile bool BUS_TMR_EXPIRED;
    volatile bool WAIT_TMR_EXPIRED;
} TIMER_DRIVER_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

void Main_TMR_Callback(uintptr_t CONTEXT);

void Bus_TMR_Callback(uintptr_t CONTEXT);

void Wait_TMR_Callback(uintptr_t CONTEXT);

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void TIMER_DRIVER_Initialize(void);

bool TIMER_DRIVER_Get_Main_TMR_Status(void);

void TIMER_DRIVER_Set_Main_TMR_Status(bool STATUS);

void TIMER_DRIVER_Start_Main_TMR(void);

void TIMER_DRIVER_Stop_Main_TMR(void);

bool TIMER_DRIVER_Get_Bus_TMR_Status(void);

void TIMER_DRIVER_Set_Bus_TMR_Status(bool STATUS);

void TIMER_DRIVER_Start_Bus_TMR(void);

void TIMER_DRIVER_Stop_Bus_TMR(void);

bool TIMER_DRIVER_Get_Wait_TMR_Status(void);

void TIMER_DRIVER_Set_Wait_TMR_Status(bool STATUS);

void TIMER_DRIVER_Start_Wait_TMR(void);

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