/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    timer_driver.h

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

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************
    
#define TIMER0  1000
#define TIMER1  1000
#define TIMER2  1000
#define TIMER3  1000

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
    SYS_TIME_HANDLE TMR0_HANDLE;
    SYS_TIME_HANDLE TMR1_HANDLE;
    SYS_TIME_HANDLE TMR2_HANDLE;
    SYS_TIME_HANDLE TMR3_HANDLE;
    bool TMR0_EXPIRED;
    bool TMR1_EXPIRED;
    bool TMR2_EXPIRED;
    bool TMR3_EXPIRED;
} TIMER_DRIVER_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

void TMR0_Callback(uintptr_t CONTEXT);

void TMR1_Callback(uintptr_t CONTEXT);

void TMR2_Callback(uintptr_t CONTEXT);

void TMR3_Callback(uintptr_t CONTEXT);

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void TIMER_DRIVER_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    TIMER_DRIVER_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    TIMER_DRIVER_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void TIMER_DRIVER_Initialize ( void );

bool TIMER_DRIVER_Get_TMR0_Status(void);

void TIMER_DRIVER_Set_TMR0_Status(bool STATUS);

void TIMER_DRIVER_Start_TMR0(void);

void TIMER_DRIVER_Stop_TMR0(void);

bool TIMER_DRIVER_Get_TMR1_Status(void);

void TIMER_DRIVER_Set_TMR1_Status(bool STATUS);

void TIMER_DRIVER_Start_TMR1(void);

void TIMER_DRIVER_Stop_TMR1(void);

bool TIMER_DRIVER_Get_TMR2_Status(void);

void TIMER_DRIVER_Set_TMR2_Status(bool STATUS);

void TIMER_DRIVER_Start_TMR2(void);

void TIMER_DRIVER_Stop_TMR2(void);

bool TIMER_DRIVER_Get_TMR3_Status(void);

void TIMER_DRIVER_Set_TMR3_Status(bool STATUS);

void TIMER_DRIVER_Start_TMR3(void);

void TIMER_DRIVER_Stop_TMR3(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _TIMER_DRIVER_H */

/*******************************************************************************
 End of File
 */