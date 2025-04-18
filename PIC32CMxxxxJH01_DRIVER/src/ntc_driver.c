/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    ntc_driver.c

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

#include "ntc_driver.h"

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
    This structure should be initialized by the NTC_DRIVER_Initialize function.

    Application strings and buffers are be defined outside this structure.
 */

NTC_DRIVER_DATA ntc_driverData;

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
    void NTC_DRIVER_Initialize ( void )

  Remarks:
    See prototype in ntc_driver.h.
 */

void NTC_DRIVER_Initialize(void)
{
    ntc_driverData.state = NTC_DRIVER_STATE_INIT;
}

/******************************************************************************
  Function:
    void NTC_DRIVER_Tasks ( void )

  Remarks:
    See prototype in ntc_driver.h.
 */

void NTC_DRIVER_Tasks(void)
{
    switch (ntc_driverData.state)
    {
        case NTC_DRIVER_STATE_INIT:
        {
            ntc_driverData.state = NTC_DRIVER_STATE_SERVICE_TASKS;
            break;
        }

        case NTC_DRIVER_STATE_SERVICE_TASKS:
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