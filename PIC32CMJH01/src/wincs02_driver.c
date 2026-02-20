/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    wincs02_driver.c

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

#include "wincs02_driver.h"
#include "system/wifi/sys_wincs_wifi_service.h"
#include "system/mqtt/sys_wincs_mqtt_service.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

WINCS02_DRIVER_DATA wincs02_driverData;
SYS_WINCS_WIFI_PARAM_t WIFI_CONFIG;
SYS_WINCS_MQTT_CFG_t MQTT_CONFIG;
SYS_WINCS_MQTT_FRAME_t MQTT_PUBLISH;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

SYS_WINCS_WIFI_CALLBACK_t WINCS02_DRIVER_WIFI_Callback(SYS_WINCS_WIFI_EVENT_t EVENT, SYS_WINCS_WIFI_HANDLE_t WIFI_HANDLE)
{
    switch (EVENT)
    {
        case SYS_WINCS_WIFI_REG_DOMAIN_SET_ACK:
        {
            wincs02_driverData.REG_DOMAIN_SET = true;
            break;
        }

        case SYS_WINCS_WIFI_CONNECTED:
        {
            wincs02_driverData.WIFI_CONNECT_STATUS = true;
            break;
        }

        case SYS_WINCS_WIFI_DISCONNECTED:
        {
            wincs02_driverData.WIFI_CONNECT_STATUS = false;
            wincs02_driverData.IPV4_ADDRESS_ASSIGN_STATUS = false;
            wincs02_driverData.IPV6_LOCAL_ADDRESS_ASSIGN_STATUS = false;
            wincs02_driverData.IPV6_GLOBAL_ADDRESS_ASSIGN_STATUS = false;
            wincs02_driverData.SNTP_UP_STATUS = false;
            SYS_WINCS_WIFI_SrvCtrl(SYS_WINCS_WIFI_STA_CONNECT, NULL);
            break;
        }

        case SYS_WINCS_WIFI_DHCP_IPV4_COMPLETE:
        {
            wincs02_driverData.IPV4_ADDRESS_ASSIGN_STATUS = true;
            break;
        }

        case SYS_WINCS_WIFI_DHCP_IPV6_LOCAL_COMPLETE:
        {
            wincs02_driverData.IPV6_LOCAL_ADDRESS_ASSIGN_STATUS = true;
            break;
        }

        case SYS_WINCS_WIFI_DHCP_IPV6_GLOBAL_COMPLETE:
        {
            wincs02_driverData.IPV6_GLOBAL_ADDRESS_ASSIGN_STATUS = true;
            break;
        }

        case SYS_WINCS_WIFI_SNTP_UP:
        {
            wincs02_driverData.SNTP_UP_STATUS = true;
            break;
        }

        case SYS_WINCS_WIFI_CONNECT_FAILED:
        {
            wincs02_driverData.WIFI_CONNECT_STATUS = false;
            SYS_WINCS_WIFI_SrvCtrl(SYS_WINCS_WIFI_STA_CONNECT, NULL);
            break;
        }

        case SYS_WINCS_WIFI_ERROR:
        {
            wincs02_driverData.WIFI_CONNECT_STATUS = false;
            wincs02_driverData.IPV4_ADDRESS_ASSIGN_STATUS = false;
            wincs02_driverData.IPV6_LOCAL_ADDRESS_ASSIGN_STATUS = false;
            wincs02_driverData.IPV6_GLOBAL_ADDRESS_ASSIGN_STATUS = false;
            wincs02_driverData.SNTP_UP_STATUS = false;
            break;
        }

        default:
            break;
    }
}

SYS_WINCS_MQTT_CALLBACK_t WINCS02_DRIVER_MQTT_Callback(SYS_WINCS_MQTT_EVENT_t EVENT, SYS_WINCS_MQTT_HANDLE_t MQTT_HANDLE)
{
    switch (EVENT)
    {
        case SYS_WINCS_MQTT_CONNECTED:
        {
            wincs02_driverData.MQTT_CONNECT_STATUS = true;
            break;
        }

        case SYS_WINCS_MQTT_DISCONNECTED:
        {
            wincs02_driverData.MQTT_CONNECT_STATUS = false;
            break;
        }

        case SYS_WINCS_MQTT_PUBLISH_ACK:
        {
            wincs02_driverData.MQTT_PUBLISH_COMPLETE = true;
            break;
        }

        case SYS_WINCS_MQTT_SUBCRIBE_ACK:
        {
            wincs02_driverData.MQTT_SUBSCRIBE_COMPLETE = true;
            break;
        }

        case SYS_WINCS_MQTT_ERROR:
        {
            wincs02_driverData.MQTT_CONNECT_STATUS = false;
            break;
        }

        default:
        {
            break;
        }
    }
    return SYS_WINCS_PASS;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

bool WINCS02_DRIVER_Get_Task_Start_Status(void)
{
    return (wincs02_driverData.WINCS02_TASK_START);
}

void WINCS02_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    wincs02_driverData.WINCS02_TASK_START = STATUS;
}

bool WINCS02_DRIVER_Get_Task_Completed_Status(void)
{
    return (wincs02_driverData.WINCS02_TASK_COMPLETED);
}

void WINCS02_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    wincs02_driverData.WINCS02_TASK_COMPLETED = STATUS;
}

void WINCS02_DRIVER_WIFI_Config(void)
{
    WIFI_CONFIG.mode = SYS_WINCS_WIFI_DEVMODE;
    WIFI_CONFIG.ssid = SYS_WINCS_WIFI_STA_SSID;
    WIFI_CONFIG.passphrase = SYS_WINCS_WIFI_STA_PWD;
    WIFI_CONFIG.security = SYS_WINCS_WIFI_STA_SECURITY;
    WIFI_CONFIG.autoConnect = SYS_WINCS_WIFI_STA_AUTOCONNECT;
    WIFI_CONFIG.channel = 0;
    WIFI_CONFIG.ssidVisibility = true;
}

void WINCS02_DRIVER_MQTT_Config(void)
{
    MQTT_CONFIG.url = SYS_WINCS_MQTT_CLOUD_URL;
    MQTT_CONFIG.port = SYS_WINCS_MQTT_CLOUD_PORT;
    MQTT_CONFIG.clientId = SYS_WINCS_MQTT_CLIENT_ID;
    MQTT_CONFIG.username = SYS_WINCS_MQTT_CLOUD_USER_NAME;
    MQTT_CONFIG.password = SYS_WINCS_MQTT_PASSWORD;
    MQTT_CONFIG.tlsIdx = false;
    MQTT_CONFIG.protoVer = SYS_WINCS_MQTT_PROTO_VERSION;
    MQTT_CONFIG.cleanSession = SYS_WINCS_MQTT_CLEAN_SESSION;
    MQTT_CONFIG.keepAliveTime = SYS_WINCS_MQTT_KEEP_ALIVE_TIME;
}

void WINCS02_DRIVER_Set_MQTT_Publish_Payload(void)
{
    MQTT_PUBLISH.topic = SYS_WINCS_MQTT_PUB_TOPIC_NAME;
    MQTT_PUBLISH.message = SYS_WINCS_MQTT_PUB_MSG;
    MQTT_PUBLISH.qos = SYS_WINCS_MQTT_PUB_MSG_QOS_TYPE;
    MQTT_PUBLISH.retain = SYS_WINCS_MQTT_PUB_MSG_RETAIN;
    MQTT_PUBLISH.protoVer = SYS_WINCS_MQTT_PROTO_VERSION;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void WINCS02_DRIVER_Initialize(void)
{
    wincs02_driverData.state = WINCS02_DRIVER_STATE_INIT;
    wincs02_driverData.WINCS02_HANDLE = DRV_HANDLE_INVALID;
}

void WINCS02_DRIVER_Tasks(void)
{
    switch (wincs02_driverData.state)
    {
        case WINCS02_DRIVER_STATE_INIT:
        {
            WINCS02_DRIVER_WIFI_Config();
            WINCS02_DRIVER_MQTT_Config();
            wincs02_driverData.state = WINCS02_DRIVER_STATE_CHECK_DRIVER_STATUS;
            break;
        }

        case WINCS02_DRIVER_STATE_CHECK_DRIVER_STATUS:
        {
            if (SYS_WINCS_WIFI_SrvCtrl(SYS_WINCS_WIFI_GET_DRV_STATUS, &wincs02_driverData.WINCS02_STATUS) == SYS_WINCS_PASS)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_OPEN_DRIVER;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_OPEN_DRIVER:
        {
            if (SYS_WINCS_WIFI_SrvCtrl(SYS_WINCS_WIFI_OPEN_DRIVER, &wincs02_driverData.WINCS02_HANDLE) == SYS_WINCS_PASS)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_WIFI_CALLBACK_REGISTER;
            }
            else
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_ERROR;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_WIFI_CALLBACK_REGISTER:
        {
            if (SYS_WINCS_WIFI_SrvCtrl(SYS_WINCS_WIFI_SET_CALLBACK, SYS_WINCS_WIFI_CallbackHandler) == SYS_WINCS_PASS)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_MQTT_CALLBACK_REGISTER;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_MQTT_CALLBACK_REGISTER:
        {
            if (SYS_WINCS_MQTT_SrvCtrl(SYS_WINCS_MQTT_SET_CALLBACK, SYS_WINCS_MQTT_CallbackHandler) == SYS_WINCS_PASS)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_SET_SNTP_SERVER;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_SET_SNTP_SERVER:
        {
            if (SYS_WINCS_WIFI_SrvCtrl(SYS_WINCS_WIFI_SET_SNTP, SYS_WINCS_WIFI_SNTP_ADDRESS) == SYS_WINCS_PASS)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_WIFI_CFG;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_WIFI_CFG:
        {
            if (SYS_WINCS_WIFI_SrvCtrl(SYS_WINCS_WIFI_SET_PARAMS, &WIFI_CONFIG) == SYS_WINCS_PASS)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_WAIT_FOR_IPV4;
            }
            else
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_ERROR;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_WAIT_FOR_IPV4:
        {
            if (wincs02_driverData.IPV4_ADDRESS_ASSIGN_STATUS == true)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_WAIT_FOR_IPV6_LOCAL;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_WAIT_FOR_IPV6_LOCAL:
        {
            if (wincs02_driverData.IPV6_LOCAL_ADDRESS_ASSIGN_STATUS == true)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_WAIT_FOR_IPV6_GLOBAL;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_WAIT_FOR_IPV6_GLOBAL:
        {
            if (wincs02_driverData.IPV6_GLOBAL_ADDRESS_ASSIGN_STATUS == true)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_GET_TIME;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_GET_TIME:
        {
            if (SYS_WINCS_WIFI_SrvCtrl(SYS_WINCS_WIFI_GET_TIME, NULL) == SYS_WINCS_PASS)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_WAIT_FOR_TIME;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_WAIT_FOR_TIME:
        {
            if (wincs02_driverData.SNTP_UP_STATUS == true)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_MQTT_CFG;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_MQTT_CFG:
        {
            if (SYS_WINCS_MQTT_SrvCtrl(SYS_WINCS_MQTT_CONFIG, &MQTT_CONFIG) == SYS_WINCS_PASS)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_MQTT_CONNECT;
            }
            else
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_ERROR;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_MQTT_CONNECT:
        {
            if (SYS_WINCS_MQTT_SrvCtrl(SYS_WINCS_MQTT_CONNECT, &MQTT_CONFIG) == SYS_WINCS_PASS)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_WAIT_FOR_MQTT_CONNECT;
            }
            else
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_ERROR;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_WAIT_FOR_MQTT_CONNECT:
        {
            if (wincs02_driverData.MQTT_CONNECT_STATUS == true)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_IDLE;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_IDLE:
        {
            if (WINCS02_DRIVER_Get_Task_Start_Status() == true)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_SET_MQTT_PUBLISH_PAYLOAD;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_SET_MQTT_PUBLISH_PAYLOAD:
        {
            WINCS02_DRIVER_Set_MQTT_Publish_Payload();
            wincs02_driverData.state = WINCS02_DRIVER_STATE_MQTT_PUBLISH;
            break;
        }

        case WINCS02_DRIVER_STATE_MQTT_PUBLISH:
        {
            if (SYS_WINCS_MQTT_SrvCtrl(SYS_WINCS_MQTT_PUBLISH, &MQTT_PUBLISH) == SYS_WINCS_PASS)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_WAIT_FOR_PUBLISH;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_WAIT_FOR_PUBLISH:
        {
            if (wincs02_driverData.MQTT_PUBLISH_COMPLETE == true)
            {
                wincs02_driverData.MQTT_PUBLISH_COMPLETE = false;
                WINCS02_DRIVER_Set_Task_Completed_Status(true);
                wincs02_driverData.state = WINCS02_DRIVER_STATE_IDLE;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_ERROR:
        {
            wincs02_driverData.state = WINCS02_DRIVER_STATE_IDLE;
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