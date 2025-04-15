/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    fcm360w_driver.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "fcm360w_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the FCM360W_DRIVER_Initialize function.

    Application strings and buffers are be defined outside this structure.
 */

FCM360W_DRIVER_DATA fcm360w_driverData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void FCM360W_DRIVER_Initialize ( void )

  Remarks:
    See prototype in fcm360w_driver.h.
 */

void FCM360W_DRIVER_Initialize(void)
{
    fcm360w_driverData.state = FCM360W_DRIVER_STATE_INIT;
}

/******************************************************************************
  Function:
    void FCM360W_DRIVER_Tasks ( void )

  Remarks:
    See prototype in fcm360w_driver.h.
 */

void FCM360W_DRIVER_Tasks(void)
{
    switch (fcm360w_driverData.state)
    {
        case FCM360W_DRIVER_STATE_INIT:
        {
            fcm360w_driverData.state = FCM360W_DRIVER_STATE_INIT;
            break;
        }

        default:
        {
            break;
        }
    }
}

/*******************************************************************************
 End of File
 */