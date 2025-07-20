/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    fan_driver.c

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

#include "fan_driver.h"

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
    This structure should be initialized by the FAN_DRIVER_Initialize function.

    Application strings and buffers are be defined outside this structure.
 */

FAN_DRIVER_DATA fan_driverData;

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

void FAN_DRIVER_Initialize(void)
{
    fan_driverData.state = FAN_DRIVER_STATE_INIT;
}

void FAN_DRIVER_Tasks(void)
{
    switch (fan_driverData.state)
    {
        case FAN_DRIVER_STATE_INIT:
        {
            fan_driverData.state = FAN_DRIVER_STATE_SERVICE_TASKS;
            break;
        }

        case FAN_DRIVER_STATE_SERVICE_TASKS:
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