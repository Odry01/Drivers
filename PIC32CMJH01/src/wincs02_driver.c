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
#include "system/net/sys_wincs_net_service.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

WINCS02_DRIVER_DATA wincs02_driverData;

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
            if (wincs02_driverData.REG_DOMAIN_SET == false)
            {
                wincs02_driverData.REG_DOMAIN_SET = true;
                wincs02_driverData.state = WINCS02_DRIVER_STATE_WIFI_CFG;
            }
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
            wincs02_driverData.IP_ADDRESS_ASSIGN_STATUS = false;
            wincs02_driverData.SNTP_STATUS = false;
            break;
        }

        case SYS_WINCS_WIFI_DHCP_IPV4_COMPLETE:
        {
            wincs02_driverData.IP_ADDRESS_ASSIGN_STATUS = true;
            break;
        }

        case SYS_WINCS_WIFI_SNTP_UP:
        {
            wincs02_driverData.SNTP_STATUS = true;
            break;
        }

        case SYS_WINCS_WIFI_CONNECT_FAILED:
        {
            wincs02_driverData.WIFI_CONNECT_STATUS = false;
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
            wincs02_driverData.MQTT_PUBLISH_STATUS = true;
            break;
        }

        case SYS_WINCS_MQTT_SUBCRIBE_ACK:
        {
            wincs02_driverData.MQTT_SUBCRIBE_STATUS = true;
            break;
        }

        default:
            break;
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
    wincs02_driverData.WIFI_CONFIG.mode = SYS_WINCS_WIFI_MODE_STA;
    wincs02_driverData.WIFI_CONFIG.ssid = WIFI_SSID;
    wincs02_driverData.WIFI_CONFIG.passphrase = WIFI_PASSWORD;
    wincs02_driverData.WIFI_CONFIG.security = SYS_WINCS_WIFI_SECURITY_WPA2;
    wincs02_driverData.WIFI_CONFIG.autoConnect = 0;
    wincs02_driverData.WIFI_CONFIG.channel = 0;
    wincs02_driverData.WIFI_CONFIG.ssidVisibility = true;
}

void WINCS02_DRIVER_MQTT_Config(void)
{
    wincs02_driverData.MQTT_CONFIG.url = MQTT_BROKER_URL;
    wincs02_driverData.MQTT_CONFIG.port = MQTT_BROKER_PORT;
    wincs02_driverData.MQTT_CONFIG.clientId = MQTT_CLIENT_ID;
    wincs02_driverData.MQTT_CONFIG.username = MQTT_USERNAME;
    wincs02_driverData.MQTT_CONFIG.password = MQTT_PASSWORD;
    wincs02_driverData.MQTT_CONFIG.tlsIdx = false;
    wincs02_driverData.MQTT_CONFIG.protoVer = SYS_WINCS_MQTT_PROTO_VER_3;
    wincs02_driverData.MQTT_CONFIG.cleanSession = true;
    wincs02_driverData.MQTT_CONFIG.keepAliveTime = 3600;
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
            SYS_STATUS status;
            if (SYS_WINCS_WIFI_SrvCtrl(SYS_WINCS_WIFI_GET_DRV_STATUS, &status) == SYS_STATUS_READY)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_OPEN_DRIVER;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_OPEN_DRIVER:
        {
            if (SYS_WINCS_WIFI_SrvCtrl(SYS_WINCS_WIFI_OPEN_DRIVER, &wincs02_driverData.WINCS02_HANDLE) == SYS_WINCS_PASS)
            {
                SYS_WINCS_WIFI_SrvCtrl(SYS_WINCS_WIFI_GET_DRV_HANDLE, &wincs02_driverData.WINCS02_HANDLE);
                wincs02_driverData.state = WINCS02_DRIVER_STATE_SET_REG_DOMAIN;
            }
            else
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_ERROR;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_SET_REG_DOMAIN:
        {
            if (SYS_WINCS_WIFI_SrvCtrl(SYS_WINCS_WIFI_SET_REG_DOMAIN, "EMEA") == SYS_WINCS_PASS)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_CALLBACK_REGISTER;
            }
            else
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_ERROR;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_CALLBACK_REGISTER:
        {
            SYS_WINCS_WIFI_SrvCtrl(SYS_WINCS_WIFI_SET_CALLBACK, WINCS02_DRIVER_WIFI_Callback);
            SYS_WINCS_MQTT_SrvCtrl(SYS_WINCS_MQTT_SET_CALLBACK, WINCS02_DRIVER_MQTT_Callback);
            wincs02_driverData.state = WINCS02_DRIVER_STATE_WIFI_CFG;
            break;
        }

        case WINCS02_DRIVER_STATE_WIFI_CFG:
        {


            if (SYS_WINCS_WIFI_SrvCtrl(SYS_WINCS_WIFI_SET_PARAMS, &wincs02_driverData.WIFI_CONFIG) == SYS_WINCS_PASS)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_WIFI_CONNECT;
            }
            else
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_ERROR;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_WIFI_CONNECT:
        {
            if (SYS_WINCS_WIFI_SrvCtrl(SYS_WINCS_WIFI_STA_CONNECT, NULL) == SYS_WINCS_PASS)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_WAIT_FOR_IP;
            }
            else
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_ERROR;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_WAIT_FOR_IP:
        {
            if (wincs02_driverData.IP_ADDRESS_ASSIGN_STATUS == true)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_MQTT_CONNECT;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_SNTP_CFG:
        {
            if (SYS_WINCS_WIFI_SrvCtrl(SYS_WINCS_WIFI_SET_SNTP, SNTP_URL) == SYS_WINCS_PASS)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_WAIT_FOR_SNTP;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_WAIT_FOR_SNTP:
        {
            if (wincs02_driverData.SNTP_STATUS == true)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_GET_SNTP_TIME;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_GET_SNTP_TIME:
        {
            if (SYS_WINCS_WIFI_SrvCtrl(SYS_WINCS_WIFI_GET_TIME, NULL) == SYS_WINCS_PASS)
            {
                wincs02_driverData.state = WINCS02_DRIVER_STATE_MQTT_CFG;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_MQTT_CFG:
        {
            SYS_WINCS_MQTT_SrvCtrl(SYS_WINCS_MQTT_CONFIG, &wincs02_driverData.MQTT_CONFIG);
            wincs02_driverData.state = WINCS02_DRIVER_STATE_MQTT_CONNECT;
            break;
        }

        case WINCS02_DRIVER_STATE_MQTT_CONNECT:
        {
            SYS_WINCS_MQTT_SrvCtrl(SYS_WINCS_MQTT_CONNECT, &wincs02_driverData.MQTT_CONFIG);
            wincs02_driverData.state = WINCS02_DRIVER_STATE_WAIT_FOR_MQTT_CONNECT;
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
                wincs02_driverData.state = WINCS02_DRIVER_STATE_SET_MQTT_PAYLOAD;
            }
            break;
        }

        case WINCS02_DRIVER_STATE_SET_MQTT_PAYLOAD:
        {
            wincs02_driverData.state = WINCS02_DRIVER_STATE_MQTT_PUBLISH;
            break;
        }

        case WINCS02_DRIVER_STATE_MQTT_PUBLISH:
        {
            SYS_WINCS_MQTT_FRAME_t mqttFrame = {
                .topic = MQTT_TOPIC_NAME,
                .message = wincs02_driverData.MQTT_PAYLOAD,
                .qos = SYS_WINCS_MQTT_QOS2,
                .retain = false,
                .protoVer = SYS_WINCS_MQTT_PROTO_VER_3
            };

            SYS_WINCS_MQTT_SrvCtrl(SYS_WINCS_MQTT_PUBLISH, &mqttFrame);
            wincs02_driverData.state = WINCS02_DRIVER_STATE_WAIT_FOR_PUBLISH;
            break;
        }

        case WINCS02_DRIVER_STATE_WAIT_FOR_PUBLISH:
        {
            if (wincs02_driverData.MQTT_PUBLISH_STATUS == true)
            {
                wincs02_driverData.MQTT_PUBLISH_STATUS = false;
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