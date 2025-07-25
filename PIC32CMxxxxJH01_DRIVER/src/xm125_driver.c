/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    xm125_driver.c

  Status:
    In development
 
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

#include "xm125_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

XM125_DRIVER_DATA xm125_driverData;

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

void XM125_DRIVER_Initialize(void)
{
    xm125_driverData.state = XM125_DRIVER_STATE_INIT;
}

void XM125_DRIVER_Tasks(void)
{
    switch (xm125_driverData.state)
    {
        case XM125_DRIVER_STATE_INIT:
        {

            xm125_driverData.state = XM125_DRIVER_STATE_SERVICE_TASKS;
            break;
        }

        case XM125_DRIVER_STATE_SERVICE_TASKS:
        {

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
