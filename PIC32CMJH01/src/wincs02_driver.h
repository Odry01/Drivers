/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    wincs02_driver.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "WINCS02_DRIVER_Initialize" and "WINCS02_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "WINCS02_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _WINCS02_DRIVER_H
#define _WINCS02_DRIVER_H

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

#define WIFI_SSID           "SSID"
#define WIFI_PASSWORD       "PWD"
#define SNTP_URL            "time.google.com"

#define MQTT_BROKER_URL     "test.mosquitto.org"
#define MQTT_BROKER_PORT    1883
#define MQTT_USERNAME       "Admin"
#define MQTT_PASSWORD       "Admin"
#define MQTT_CLIENT_ID      "WINCS02"
#define MQTT_TOPIC_NAME     "WINCS02/Out"

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
    WINCS02_DRIVER_STATE_INIT = 0,
    WINCS02_DRIVER_STATE_CHECK_DRIVER_STATUS,
    WINCS02_DRIVER_STATE_OPEN_DRIVER,
    WINCS02_DRIVER_STATE_SET_REG_DOMAIN,
    WINCS02_DRIVER_STATE_CALLBACK_REGISTER,
    WINCS02_DRIVER_STATE_WIFI_CFG,
    WINCS02_DRIVER_STATE_WIFI_CONNECT,
    WINCS02_DRIVER_STATE_WAIT_FOR_IP,
    WINCS02_DRIVER_STATE_SNTP_CFG,
    WINCS02_DRIVER_STATE_WAIT_FOR_SNTP,
    WINCS02_DRIVER_STATE_GET_SNTP_TIME,
    WINCS02_DRIVER_STATE_MQTT_CFG,
    WINCS02_DRIVER_STATE_MQTT_CONNECT,
    WINCS02_DRIVER_STATE_WAIT_FOR_MQTT_CONNECT,
    WINCS02_DRIVER_STATE_IDLE,
    WINCS02_DRIVER_STATE_SET_MQTT_PAYLOAD,
    WINCS02_DRIVER_STATE_MQTT_PUBLISH,
    WINCS02_DRIVER_STATE_WAIT_FOR_PUBLISH,
    WINCS02_DRIVER_STATE_ERROR,
} WINCS02_DRIVER_STATES;

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
    WINCS02_DRIVER_STATES state;

    /* Driver variables */
    DRV_HANDLE WINCS02_HANDLE;
        
    volatile bool WINCS02_TASK_START;
    volatile bool WINCS02_TASK_COMPLETED;
    
    volatile bool WIFI_CONNECT_STATUS;
    volatile bool IP_ADDRESS_ASSIGN_STATUS;
    volatile bool SNTP_STATUS;
    volatile bool MQTT_CONNECT_STATUS;
    volatile bool MQTT_SUBCRIBE_STATUS;
    volatile bool MQTT_PUBLISH_STATUS;
    volatile bool REG_DOMAIN_SET;

    char MQTT_TOPIC[64];
    char MQTT_PAYLOAD[1024];
} WINCS02_DRIVER_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************


void WINCS02_DRIVER_Initialize(void);

void WINCS02_DRIVER_Tasks(void);

bool WINCS02_DRIVER_Get_Task_Start_Status(void);

void WINCS02_DRIVER_Set_Task_Start_Status(bool STATUS);

bool WINCS02_DRIVER_Get_Task_Completed_Status(void);

void WINCS02_DRIVER_Set_Task_Completed_Status(bool STATUS);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _WINCS02_DRIVER_H */

/*******************************************************************************
 End of File
 */