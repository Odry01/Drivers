/*******************************************************************************
  System Configuration Header

  File Name:
    configuration.h

  Summary:
    Build-time configuration header for the system defined by this project.

  Description:
    An MPLAB Project may have multiple configurations.  This file defines the
    build-time options for a single configuration.

  Remarks:
    This configuration header must not define any prototypes or data
    definitions (or include any files that do).  It only provides macro
    definitions for build-time configuration options

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/*  This section Includes other configuration headers necessary to completely
    define this configuration.
*/

#include "user.h"
#include "device.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: System Configuration
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: System Service Configuration
// *****************************************************************************
// *****************************************************************************
/*----------------- WINCS Net System Service Configuration -----------------*/
#define SYS_WINCS_NET_BIND_TYPE0                SYS_WINCS_NET_BIND_REMOTE 
#define SYS_WINCS_NET_SOCK_TYPE0                SYS_WINCS_NET_SOCK_TYPE_TCP 
#define SYS_WINCS_NET_SOCK_TYPE_IPv4_0          4
#define SYS_WINCS_NET_SOCK_TYPE_IPv6_LOCAL0     0
#define SYS_WINCS_NET_SOCK_TYPE_IPv6_GLOBAL0    0
#define SYS_WINCS_NET_SOCK_SERVER_ADDR0         ""
#define SYS_WINCS_NET_SOCK_PORT0                80
#define SYS_WINCS_TLS_ENABLE0                   0
/*----------------------------------------------------------------------------*/

/* -----------------WINCS02 MQTT System Service Configuration ----------------- */

#define SYS_WINCS_MQTT_PROTO_VERSION             SYS_WINCS_MQTT_PROTO_VER_3

#define SYS_WINCS_MQTT_CLOUD_URL                 "test.mosquitto.org"
#define SYS_WINCS_MQTT_CLOUD_PORT                1883
#define SYS_WINCS_MQTT_CLIENT_ID                 "WINCS02"
#define SYS_WINCS_MQTT_CLOUD_USER_NAME           "Admin"
#define SYS_WINCS_MQTT_PASSWORD                  "Admin"
#define SYS_WINCS_MQTT_CLEAN_SESSION             true
#define SYS_WINCS_MQTT_KEEP_ALIVE_TIME           3600
#define SYS_WINCS_MQTT_SUB_TOPIC_0               "WINCS02/In"
#define SYS_WINCS_MQTT_SUB_TOPIC_0_QOS           SYS_WINCS_MQTT_QOS2


#define SYS_WINCS_MQTT_PUB_TOPIC_NAME            "WINCS02/Out"
#define SYS_WINCS_MQTT_PUB_MSG                   "Test message"
#define SYS_WINCS_MQTT_PUB_MSG_QOS_TYPE          SYS_WINCS_MQTT_QOS2
#define SYS_WINCS_MQTT_PUB_MSG_RETAIN            false
#define SYS_WINCS_MQTT_TLS_ENABLE                false
#define SYS_WINCS_MQTT_AZURE_DPS_ENABLE          false
#define SYS_WINCS_MQTT_CallbackHandler           WINCS02_DRIVER_MQTT_Callback

/*----------------------------------------------------------------------------*/

/* TIME System Service Configuration Options */
#define SYS_TIME_INDEX_0                            (0)
#define SYS_TIME_MAX_TIMERS                         (5)
#define SYS_TIME_HW_COUNTER_WIDTH                   (24)
#define SYS_TIME_TICK_FREQ_IN_HZ                    (1000)

#define SYS_CONSOLE_INDEX_0                       0




#define SYS_CONSOLE_DEVICE_MAX_INSTANCES   			(1U)
#define SYS_CONSOLE_UART_MAX_INSTANCES 	   			(1U)
#define SYS_CONSOLE_USB_CDC_MAX_INSTANCES 	   		(0U)
#define SYS_CONSOLE_PRINT_BUFFER_SIZE        		(4096U)




// *****************************************************************************
// *****************************************************************************
// Section: Driver Configuration
// *****************************************************************************
// *****************************************************************************
/* I2C Driver Instance 0 Configuration Options */
#define DRV_I2C_INDEX_0                       0
#define DRV_I2C_CLIENTS_NUMBER_IDX0           1
#define DRV_I2C_QUEUE_SIZE_IDX0               8
#define DRV_I2C_CLOCK_SPEED_IDX0              100

/*** WiFi WINC Driver Configuration ***/
#define WDRV_WINC_EIC_SOURCE
#define WDRV_WINC_DEBUG_LEVEL               WDRV_WINC_DEBUG_TYPE_NONE
#define WDRV_WINC_DEV_RX_BUFF_SZ            1024
#define WINC_SOCK_SLAB_ALLOC_MODE           1
#define WDRV_WINC_DEV_SOCK_SLAB_NUM         16
#define WDRV_WINC_DEV_SOCK_SLAB_SZ          1024
#define WINC_SOCK_NUM_SOCKETS               1
#define WINC_SOCK_BUF_RX_SZ                 4096
#define WINC_SOCK_BUF_TX_SZ                 4096
#define WINC_SOCK_BUF_RX_PKT_BUF_NUM        5
#define WINC_SOCK_BUF_TX_PKT_BUF_NUM        5
#define WDRV_WINC_MOD_DISABLE_SYSLOG

/* I2C Driver Common Configuration Options */
#define DRV_I2C_INSTANCES_NUMBER              (1U)


/* SPI Driver Common Configuration Options */
#define DRV_SPI_INSTANCES_NUMBER              (1U)

/* SPI Driver Instance 0 Configuration Options */
#define DRV_SPI_INDEX_0                       0
#define DRV_SPI_CLIENTS_NUMBER_IDX0           1
#define DRV_SPI_DMA_MODE
#define DRV_SPI_XMIT_DMA_CH_IDX0              SYS_DMA_CHANNEL_2
#define DRV_SPI_RCV_DMA_CH_IDX0               SYS_DMA_CHANNEL_3
#define DRV_SPI_QUEUE_SIZE_IDX0               8

/* USART Driver Instance 0 Configuration Options */
#define DRV_USART_INDEX_0                  0
#define DRV_USART_CLIENTS_NUMBER_IDX0      1
#define DRV_USART_XMIT_DMA_CH_IDX0         SYS_DMA_CHANNEL_0
#define DRV_USART_RCV_DMA_CH_IDX0          SYS_DMA_CHANNEL_1
#define DRV_USART_QUEUE_SIZE_IDX0          8

/* USART Driver Global Configuration Options */
#define DRV_USART_INSTANCES_NUMBER         1


// *****************************************************************************
// *****************************************************************************
// Section: Middleware & Other Library Configuration
// *****************************************************************************
// *****************************************************************************
/* WINCS02  WIFI System Service Configuration Options */

#define SYS_WINCS_WIFI_DEVMODE        		SYS_WINCS_WIFI_MODE_STA

#define SYS_WINCS_WIFI_STA_SSID				"Admin"
#define SYS_WINCS_WIFI_STA_PWD        		"Admin"
#define SYS_WINCS_WIFI_STA_SECURITY			SYS_WINCS_WIFI_SECURITY_OPEN
#define SYS_WINCS_WIFI_STA_AUTOCONNECT   	true


#define SYS_WINCS_WIFI_COUNTRYCODE          "GEN"
#define SYS_WINCS_WIFI_SNTP_ADDRESS          "162.159.200.123"


#define SYS_WINCS_WIFI_CallbackHandler	     WINCS02_DRIVER_WIFI_Callback


// *****************************************************************************
// *****************************************************************************
// Section: Application Configuration
// *****************************************************************************
// *****************************************************************************


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // CONFIGURATION_H
/*******************************************************************************
 End of File
*/
