/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    ntc_driver.c

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

#include "ntc_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

NTC_DRIVER_DATA ntc_driverData;

NTC_DRIVER_SENSOR_DATA ntc_sensorData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void NTC_DRIVER_Callback(ADC_STATUS STATUS, uintptr_t CONTEXT)
{
    if ((STATUS & ADC_STATUS_RESRDY) == true)
    {
        ntc_driverData.ADC0_RESULT_READY = true;
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

bool NTC_DRIVER_Get_Task_Start_Status(void)
{
    return (ntc_driverData.NTC_TASK_START);
}

void NTC_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    ntc_driverData.NTC_TASK_START = STATUS;
}

bool NTC_DRIVER_Get_Task_Completed_Status(void)
{
    return (ntc_driverData.NTC_TASK_COMPLETED);
}

void NTC_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    ntc_driverData.NTC_TASK_COMPLETED = STATUS;
}

void NTC_DRIVER_Calculation_Temperature(uint16_t T_VALUE)
{
    ntc_sensorData.CELSIUS_TEMPERATURE = (float) T_VALUE / 100;
}

void NTC_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)
{
    SYS_CONSOLE_Print
            (
             CONSOLE_HANDLE,
             "NTC temperature: %.2f °C\r\n",
             ntc_sensorData.CELSIUS_TEMPERATURE
             );
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void NTC_DRIVER_Initialize(void)
{
    ntc_driverData.state = NTC_DRIVER_STATE_INIT;
    ADC0_CallbackRegister(NTC_DRIVER_Callback, 0);
    ADC0_Enable();
}

void NTC_DRIVER_Tasks(void)
{
    switch (ntc_driverData.state)
    {
        case NTC_DRIVER_STATE_INIT:
        {
            ntc_driverData.state = NTC_DRIVER_STATE_IDLE;
            break;
        }

        case NTC_DRIVER_STATE_IDLE:
        {
            if (NTC_DRIVER_Get_Task_Start_Status() == true)
            {
                ntc_driverData.state = NTC_DRIVER_STATE_START_MEASUREMENT;
            }
            break;
        }

        case NTC_DRIVER_STATE_START_MEASUREMENT:
        {
            ADC0_ConversionStart();
            ntc_driverData.state = NTC_DRIVER_STATE_WAIT_FOR_MEASUREMENT;
            break;
        }

        case NTC_DRIVER_STATE_WAIT_FOR_MEASUREMENT:
        {
            if (ntc_driverData.ADC0_RESULT_READY == true)
            {
                ntc_driverData.ADC0_RESULT_READY = false;
                ntc_driverData.state = NTC_DRIVER_STATE_GET_RESULT;
            }
            break;
        }

        case NTC_DRIVER_STATE_GET_RESULT:
        {
            ntc_sensorData.T_VALUE = ADC0_ConversionResultGet();
            ntc_driverData.state = NTC_DRIVER_STATE_CALCULATION_TEMPERATURE;
            break;
        }

        case NTC_DRIVER_STATE_CALCULATION_TEMPERATURE:
        {
            NTC_DRIVER_Calculation_Temperature(ntc_sensorData.T_VALUE);
            ntc_driverData.state = NTC_DRIVER_STATE_STORE_DATA;
            break;
        }

        case NTC_DRIVER_STATE_STORE_DATA:
        {
            /* Add function for storing temperature */
            NTC_DRIVER_Set_Task_Completed_Status(true);
            ntc_driverData.state = NTC_DRIVER_STATE_IDLE;
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