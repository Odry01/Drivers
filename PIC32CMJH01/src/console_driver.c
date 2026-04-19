/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    console_driver.c

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

#include "console_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************

CONSOLE_DRIVER_DATA console_driverData;
CONSOLE_PAYLOAD_DATA console_payloadData;

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

bool CONSOLE_DRIVER_Get_Task_Start_Status(void)
{
    return (console_driverData.CONSOLE_TASK_START);
}

void CONSOLE_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    console_driverData.CONSOLE_TASK_START = STATUS;
}

bool CONSOLE_DRIVER_Get_Task_Completed_Status(void)
{
    return (console_driverData.CONSOLE_TASK_COMPLETED);
}

void CONSOLE_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    console_driverData.CONSOLE_TASK_COMPLETED = STATUS;
}

void CONSOLE_DRIVER_Set_Example_Data(uint64_t EXAMPLE_TRANSMIT_DATA_0, uint64_t EXAMPLE_TRANSMIT_DATA_1, uint64_t EXAMPLE_TRANSMIT_DATA_2, uint64_t EXAMPLE_TRANSMIT_DATA_3)
{
    console_payloadData.EXAMPLE_TRANSMIT_DATA_0 = EXAMPLE_TRANSMIT_DATA_0;
    console_payloadData.EXAMPLE_TRANSMIT_DATA_1 = EXAMPLE_TRANSMIT_DATA_1;
    console_payloadData.EXAMPLE_TRANSMIT_DATA_2 = EXAMPLE_TRANSMIT_DATA_2;
    console_payloadData.EXAMPLE_TRANSMIT_DATA_3 = EXAMPLE_TRANSMIT_DATA_3;
}

void CONSOLE_DRIVER_Print_Example_Payload(void)
{
    SYS_CONSOLE_Print
            (
             console_driverData.CONSOLE_HANDLE,
             "{\"Example data\":%u,%u,%u,%u}\r\n",
             console_payloadData.EXAMPLE_TRANSMIT_DATA_0, console_payloadData.EXAMPLE_TRANSMIT_DATA_1, console_payloadData.EXAMPLE_TRANSMIT_DATA_2, console_payloadData.EXAMPLE_TRANSMIT_DATA_3
             );
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void CONSOLE_DRIVER_Initialize(void)
{
    console_driverData.state = CONSOLE_DRIVER_STATE_INIT;
}

void CONSOLE_DRIVER_Tasks(void)
{
    switch (console_driverData.state)
    {
        case CONSOLE_DRIVER_STATE_INIT:
        {
            console_driverData.state = CONSOLE_DRIVER_STATE_IDLE;
            break;
        }

        case CONSOLE_DRIVER_STATE_IDLE:
        {
            if (CONSOLE_DRIVER_Get_Task_Start_Status() == true)
            {
                console_driverData.state = CONSOLE_DRIVER_STATE_PRINT_DATA;
            }
            break;
        }

        case CONSOLE_DRIVER_STATE_PRINT_DATA:
        {
            CONSOLE_DRIVER_Print_Example_Payload();
            CONSOLE_DRIVER_Set_Task_Completed_Status(true);
            console_driverData.state = CONSOLE_DRIVER_STATE_IDLE;
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