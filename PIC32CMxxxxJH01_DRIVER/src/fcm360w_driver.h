/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    fcm360w_driver.h

  Status:
    In development
 
  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "FCM360W_DRIVER_Initialize" and "FCM360W_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "FCM360W_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _FCM360W_DRIVER_H
#define _FCM360W_DRIVER_H

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

/* Commands type */
#define FCM360W_TEST_CMD                                00
#define FCM360W_QUERY_CMD                               10
#define FCM360W_READ_CMD                                20
#define FCM360W_WRITE_CMD_0                             30
#define FCM360W_WRITE_CMD_1                             31
#define FCM360W_WRITE_CMD_2                             32
#define FCM360W_WRITE_CMD_3                             33
#define FCM360W_WRITE_CMD_4                             34
#define FCM360W_WRITE_CMD_5                             35
#define FCM360W_WRITE_CMD_6                             36
#define FCM360W_WRITE_CMD_7                             37
#define FCM360W_WRITE_CMD_8                             38
#define FCM360W_EXECUTION_CMD                           40

/* Module Commands */
#define AT_QRESET                                       "AT+QRST"
#define AT_QVERSION                                     "AT+QVERSION"
#define AT_QECHO                                        "AT+QECHO"
#define AT_QGETIP                                       "AT+QGETIP"
#define AT_QSETBAND                                     "AT+QSETBAND"
#define AT_QWLANOTA                                     "AT+QWLANOTA"
#define AT_QWLMAC                                       "AT+QWLMAC"

/* Wi-Fi Commands */
#define AT_QSTAST                                       "AT+QSTAST"
#define AT_QSTADHCP                                     "AT+QSTADHCP"
#define AT_QAPSTATIC                                    "AT+QAPSTATIC"
#define AT_QSTASTOP                                     "AT+QSTASTOP"
#define AT_QSOFTAP                                      "AT+QSOFTAP"
#define AT_QAPSTATE                                     "AT+QAPSTATE"
#define AT_QSOFTAPSTOP                                  "AT+QSOFTAPSTOP"
#define AT_QSTAAPINFO                                   "AT+QSTAAPINFO"
#define AT_QSTAAPINFODEF                                "AT+QSTAAPINFODEF"
#define AT_QGETWIFISTATE                                "AT+QGETWIFISTATE"
#define AT_QWSCAN                                       "AT+QWSCAN"
#define AT_QIDNSCFG                                     "AT+QIDNSCFG"
#define AT_QWEBCFG                                      "AT+QWEBCFG"
#define AT_QSTAAPINFORMV                                "AT+QSTAAPINFORMV"

/* BLE Commands */
#define AT_QBLEINIT                                     "AT+QBLEINIT"
#define AT_QBLEADDR                                     "AT+QBLEADDR"
#define AT_QBLENAME                                     "AT+QBLENAME"
#define AT_QBLEADVPARAM                                 "AT+QBLEADVPARAM"
#define AT_QBLEADVDATA                                  "AT+QBLEADVDATA"
#define AT_QBLEGATTSSRV                                 "AT+QBLEGATTSSRV"
#define AT_QBLEGATTSCHAR                                "AT+QBLEGATTSCHAR"
#define AT_QBLEGATTSSRVDONE                             "AT+QBLEGATTSSRVDONE"
#define AT_QBLEADVSTART                                 "AT+QBLEADVSTART"
#define AT_QBLEADVSTOP                                  "AT+QBLEADVSTOP"
#define AT_QBLEGATTSNTFY                                "AT+QBLEGATTSNTFY"

/* TCP/UDP Commands */
#define AT_QICFG                                        "AT+QICFG"
#define AT_QIOPEN                                       "AT+QIOPEN"
#define AT_QICLOSE                                      "AT+QICLOSE"
#define AT_QISTATE                                      "AT+QISTATE"
#define AT_QISEND                                       "AT+QISEND"
#define AT_QIRD                                         "AT+QIRD"
#define AT_QIACCEPT                                     "AT+QIACCEPT"
#define AT_QISWTMD                                      "AT+QISWTMD"
#define AT_QIGETERROR                                   "AT+QIGETERROR"
#define AT_TRANSPARENT_MODE_ENTER                       "ATO"
#define AT_TRANSPARENT_MODE_EXIT                        "+++"

/* SSL Commands */
#define AT_QSSLCFG                                      "AT+QSSLCFG"
#define AT_QSSLOPEN                                     "AT+QSSLOPEN"
#define AT_QSSLSEND                                     "AT+QSSLSEND"
#define AT_QSSLRECV                                     "AT+QSSLRECV"
#define AT_QSSLCLOSE                                    "AT+QSSLCLOSE"
#define AT_QSSLSTATE                                    "AT+QSSLSTATE"

/* MQTT Commands */
#define AT_QMTCFG                                       "AT+QMTCFG"
#define AT_QMTOPEN                                      "AT+QMTOPEN"
#define AT_QMTCLOSE                                     "AT+QMTCLOSE"
#define AT_QMTCONN                                      "AT+QMTCONN"
#define AT_QMTDISC                                      "AT+QMTDISC"
#define AT_QMTSUB                                       "AT+QMTSUB"
#define AT_QMTUNS                                       "AT+QMTUNS"
#define AT_QMTPUB                                       "AT+QMTPUB"
#define AT_QMTRECV                                      "AT+QMTRECV"

/* HTTP Commands */
#define AT_QHTTPCFG                                     "AT+QHTTPCFG"
#define AT_QHTTPGET                                     "AT+QHTTPGET"
#define AT_QHTTPPOST                                    "AT+QHTTPPOST"
#define AT_QHTTPPUT                                     "AT+QHTTPPUT"
#define AT_QHTTPREAD                                    "AT+QHTTPREAD"
#define AT_QHTTPSTOP                                    "AT+QHTTPSTOP"

/* Ping Commands */
#define AT_QPING                                        "AT+QPING"

/* DNS Commands */
#define AT_QIDNSGIP                                     "AT+QIDNSGIP"

/* File System Commands */
#define AT_QFOPEN                                       "AT+QFOPEN"
#define AT_QFCLOSE                                      "AT+QFCLOSE"
#define AT_QFREAD                                       "AT+QFREAD"
#define AT_QFWRITE                                      "AT+QFWRITE"
#define AT_QFLST                                        "AT+QFDEL"

#define FCM360W_RX_DATA_SIZE                            256
#define FCM360W_TX_DATA_SIZE                            256

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
    FCM360W_DRIVER_STATE_INIT = 0,
    FCM360W_DRIVER_STATE_USART_HANDLER_REGISTER,
    FCM360W_DRIVER_STATE_QRST_MESSAGE_TRANSMIT,
    FCM360W_DRIVER_STATE_QRST_CHECK_MESSAGE_TX_BUFFER,
    FCM360W_DRIVER_STATE_QRST_WAIT_FOR_MESSAGE_TRANSMIT,
    FCM360W_DRIVER_STATE_QRST_READ_MODULE_RESPONSE,
    FCM360W_DRIVER_STATE_QRST_CHECK_MESSAGE_RX_BUFFER,
    FCM360W_DRIVER_STATE_QRST_WAIT_FOR_MESSAGE_RECEIVE,
    FCM360W_DRIVER_STATE_QRST_STORE_BYTE,
    FCM360W_DRIVER_STATE_QRST_STORE_END_OF_LINE_COUNT,
    FCM360W_DRIVER_STATE_QRST_CHECK_CR_LF_COUNT,
    FCM360W_DRIVER_STATE_QRST_CHECK_MODULE_RESPONSE,
    FCM360W_DRIVER_STATE_IDLE,
    FCM360W_DRIVER_STATE_TIMER_EXPIRED,
    FCM360W_DRIVER_STATE_ERROR,
} FCM360W_DRIVER_STATES;

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
    FCM360W_DRIVER_STATES state;

    /* Driver variables */
    DRV_HANDLE USART_HANDLE;
    DRV_USART_BUFFER_HANDLE USART_BUFFER_HANDLE;
    volatile bool USART_TRANSFER_STATUS;
    volatile bool FCM360W_TASK_START;
    volatile bool FCM360W_TASK_COMPLETED;
    volatile bool FCM360W_RESPONSE_STATUS;
    char RX_BYTE;
    char RX_BUFFER[FCM360W_RX_DATA_SIZE];
    char TX_BUFFER[FCM360W_TX_DATA_SIZE];
    uint8_t RX_COUNT;
    uint8_t END_OF_LINE_COUNT;
} FCM360W_DRIVER_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

void FCM360W_DRIVER_USART_Callback(DRV_USART_BUFFER_EVENT EVENT, DRV_USART_BUFFER_HANDLE USART_BUFFER_HANDLE, uintptr_t CONTEXT);

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void FCM360W_DRIVER_Initialize(void);

void FCM360W_DRIVER_Tasks(void);

bool FCM360W_DRIVER_Get_Task_Start_Status_Get(void);

void FCM360W_DRIVER_Set_Task_Start_Status(bool STATUS);

bool FCM360W_DRIVER_Get_Task_Completed_Status(void);

void FCM360W_DRIVER_Set_Task_Completed_Status(bool STATUS);

void FCM360W_DRIVER_Set_QRESET_Command(uint8_t CMD_TYPE);

void FCM360W_DRIVER_Set_QVERSION_Command(uint8_t CMD_TYPE);

void FCM360W_DRIVER_Set_QECHO_Command(uint8_t CMD_TYPE, uint8_t ENABLE);

void FCM360W_DRIVER_Set_QGETIP_Command(uint8_t CMD_TYPE, uint8_t MODE);

void FCM360W_DRIVER_Set_QSETBAND_Command(uint8_t CMD_TYPE, uint32_t BAUD_RATE, uint8_t SAVE_STATUS);

void FCM360W_DRIVER_Set_QWLANOTA_Command(uint8_t CMD_TYPE, char *URL);

void FCM360W_DRIVER_Set_QWLMAC_Command(uint8_t CMD_TYPE);

void FCM360W_DRIVER_Set_QSTAST_Command(uint8_t CMD_TYPE);

void FCM360W_DRIVER_Set_QSTADHCP_Command(uint8_t CMD_TYPE, uint8_t ENABLE);

void FCM360W_DRIVER_Set_QAPSTATIC_Command(uint8_t CMD_TYPE, char *IP, char *MASK, char *GATE, char *DNS);

void FCM360W_DRIVER_Set_QSTASTOP_Command(uint8_t CMD_TYPE);

void FCM360W_DRIVER_Set_QSOFTAP_Command(uint8_t CMD_TYPE, char *SSID, char *KEY);

void FCM360W_DRIVER_Set_QAPSTATE_Command(uint8_t CMD_TYPE);

void FCM360W_DRIVER_Set_QSOFTAPSTOP_Command(uint8_t CMD_TYPE);

void FCM360W_DRIVER_Set_QSTAAPINFO_Command(uint8_t CMD_TYPE, char *SSID, char *PWD);

void FCM360W_DRIVER_Set_QSTAAPINFODEF_Command(uint8_t CMD_TYPE, char *SSID, char *PWD);

void FCM360W_DRIVER_Set_QGETWIFISTATE_Command(uint8_t CMD_TYPE);

void FCM360W_DRIVER_Set_QWSCAN_Command(uint8_t CMD_TYPE);

void FCM360W_DRIVER_Set_QIDNSCFG_Command(uint8_t CMD_TYPE, char *PRIMARY_DNS_ADDRESS, char *SECONDARY_DNS_ADDRESS);

void FCM360W_DRIVER_Set_QWEBCFG_Command(uint8_t CMD_TYPE, uint8_t ENABLE);

void FCM360W_DRIVER_Set_QSTAAPINFORMV_Command(uint8_t CMD_TYPE);

void FCM360W_DRIVER_Set_QBLEINIT_Command(uint8_t CMD_TYPE, uint8_t ROLE, uint8_t AUTO_ADV);

void FCM360W_DRIVER_Set_QBLEADDR_Command(uint8_t CMD_TYPE);

void FCM360W_DRIVER_Set_QBLENAME_Command(uint8_t CMD_TYPE, char *BLE_NAME);

void FCM360W_DRIVER_Set_QBLEADVPARAM_Command(uint8_t CMD_TYPE, uint16_t ADV_INT_MIN, uint16_t ADV_INT_MAX);

void FCM360W_DRIVER_Set_QBLEADVDATA_Command(uint8_t CMD_TYPE, char *ADV_DATA);

void FCM360W_DRIVER_Set_QBLEGATTSSRV_Command(uint8_t CMD_TYPE, char *SRV_UUID);

void FCM360W_DRIVER_Set_QBLEGATTSCHAR_Command(uint8_t CMD_TYPE, char *CHAR_UUID);

void FCM360W_DRIVER_Set_QBLEGATTSSRVDONE_Command(uint8_t CMD_TYPE);

void FCM360W_DRIVER_Set_QBLEADVSTART_Command(uint8_t CMD_TYPE);

void FCM360W_DRIVER_Set_QBLEADVSTOP_Command(uint8_t CMD_TYPE);

void FCM360W_DRIVER_Set_QBLEGATTSNTFY_Command(uint8_t CMD_TYPE, char *UUID, uint32_t HEX_LENGTH, char *DATA);

void FCM360W_DRIVER_Set_QICFG_Command(uint8_t CMD_TYPE, uint16_t TRANS_PKT_SIZE, uint8_t TRANS_WAIT_TIME, uint8_t SEND_DATA_FORMAT, uint8_t RECV_DATA_FORMAT, uint8_t CLOSED, uint8_t STATE, uint8_t TIMEOUT, uint8_t CLOSE_MODE, uint8_t TW_ENABLE);

void FCM360W_DRIVER_Set_QIOPEN_Command(uint8_t CMD_TYPE, uint8_t CONNECT_ID, char *SERVICE_TYPE, char *IP_ADDRESS, char *DOMAIN_NAME, uint16_t REMOTE_PORT, uint16_t local_PORT, uint8_t ACCESS_MODE);

void FCM360W_DRIVER_Set_QICLOSE_Command(uint8_t CMD_TYPE, uint8_t CONNECT_ID, uint8_t TIMEOUT);

void FCM360W_DRIVER_Set_QISTATE_Command(uint8_t CMD_TYPE, uint8_t CONNECT_ID);

void FCM360W_DRIVER_Set_QISEND_Command(uint8_t CMD_TYPE, uint8_t CONNECT_ID, uint16_t SEND_LENGTH, char *REMOTE_IP, uint16_t REMOTE_PORT, uint16_t TOTAL_SEND_LENGTH, uint16_t ACKED_BYTES, uint16_t UNACKED_BYTES);

void FCM360W_DRIVER_Set_QIRD_Command(uint8_t CMD_TYPE, uint8_t CONNECT_ID, uint16_t READ_LENGTH);

void FCM360W_DRIVER_Set_QIACCEPT_Command(uint8_t CMD_TYPE, uint8_t LISTENER_SOCKET_ID, uint8_t ACCEPT, uint8_t INCOMING_SOCKET_ID);

void FCM360W_DRIVER_Set_QISWTMD_Command(uint8_t CMD_TYPE, uint8_t CONNECT_ID, uint8_t ACCESS_MODE);

void FCM360W_DRIVER_Set_QIGETERROR_Command(uint8_t CMD_TYPE);

void FCM360W_DRIVER_Set_ATO_Command(uint8_t CMD_TYPE);

void FCM360W_DRIVER_Set_QPPPEXIT_Command(uint8_t CMD_TYPE);

void FCM360W_DRIVER_Set_QSSLCFG_Command(uint8_t CMD_TYPE, uint8_t SSL_CTX_ID, uint8_t SSL_VERSION, uint16_t CIPHER_SUITES, uint8_t IGNORE_L_TIME, uint8_t SECURTITY_LEVEL, uint8_t NEGOTIATE_TIME, uint8_t SNI, uint8_t SESSION_CACHE_ENABLE);

void FCM360W_DRIVER_Set_QSSLOPEN_Command(uint8_t CMD_TYPE, uint8_t SSL_CTX_ID, uint8_t CONNECT_ID, char *SERVER_ADDRESS, uint16_t SERVER_PORT, uint8_t ACCESS_MODE);

void FCM360W_DRIVER_Set_QSSLSEND_Command(uint8_t CMD_TYPE, uint8_t CONNECT_ID, uint16_t SEND_LENGTH);

void FCM360W_DRIVER_Set_QSSLRECV_Command(uint8_t CMD_TYPE, uint8_t CONNECT_ID, uint16_t SEND_LENGTH);

void FCM360W_DRIVER_Set_QSSLCLOSE_Command(uint8_t CMD_TYPE, uint8_t CONNECT_ID, uint16_t CLOSE_TIMEOUT);

void FCM360W_DRIVER_Set_QSSLSTATE_Command(uint8_t CMD_TYPE, uint8_t QUERY_TYPE, uint8_t CONNECT_ID);

void FCM360W_DRIVER_Set_QMTCFG_Command(uint8_t CMD_TYPE, uint8_t CLIENT_IDX, uint8_t VSN, uint8_t SSL_ENABLE, uint8_t SSL_CTX_IDX, uint16_t KEEP_ALIVE_TIME, uint8_t CLEAN_SESSION, uint16_t PKT_TIMEOUT, uint8_t RETRY_TIMES, uint8_t TIMEOUT_NOTICE, char *WILL_TOPIC, char *WILL_MESSAGE, uint8_t WILL_FLAG, uint8_t WILL_QOS, uint8_t WILL_RETAIN, uint8_t MSG_RECV_MODE, uint8_t SEND_MODE, uint8_t RECV_MODE);

void FCM360W_DRIVER_Set_QMTOPEN_Command(uint8_t CMD_TYPE, uint8_t CLIENT_IDX, char *HOST_NAME, uint16_t PORT);

void FCM360W_DRIVER_Set_QMTCLOSE_Command(uint8_t CMD_TYPE, uint8_t CLIENT_IDX);

void FCM360W_DRIVER_Set_QMTCONN_Command(uint8_t CMD_TYPE, uint8_t CLIENT_IDX, char *CLIENT_ID, char *USERNAME, char *PWD);

void FCM360W_DRIVER_Set_QMTDISC_Command(uint8_t CMD_TYPE, uint8_t CLIENT_IDX);

void FCM360W_DRIVER_Set_QMTSUB_Command(uint8_t CMD_TYPE, uint8_t CLIENT_IDX, uint8_t MESSAGE_ID, char *TOPIC, uint8_t QOS);

void FCM360W_DRIVER_Set_QMTUNS_Command(int8_t CMD_TYPE, uint8_t CLIENT_IDX, uint8_t MESSAGE_ID, char *TOPIC);

void FCM360W_DRIVER_Set_QMTPUB_Command(uint8_t CMD_TYPE, uint8_t CLIENT_IDX, uint16_t MESSAGE_ID, uint8_t QOS, uint8_t RETAIN, char *TOPIC, uint16_t LENGTH);

void FCM360W_DRIVER_Set_QMTRECV_Command(uint8_t CMD_TYPE, uint8_t CLIENT_IDX, uint16_t RECEIVE_ID);

void FCM360W_DRIVER_Set_QHTTPCFG_Command(uint8_t CMD_TYPE, char *URL_STRING, char *HEADER_VALUE, char *USERNAME_PWD, char *NAME, char *FILE_NAME, char *CONTENT_TYPE, uint8_t SSL_CTX_ID, uint8_t RESPONSE_HEADER, uint8_t AUTO_OUTRSP, uint8_t CLOSED_INDICATION);

void FCM360W_DRIVER_Set_QHTTPGET_Command(uint8_t CMD_TYPE, uint8_t RESPONSE_TIME);

void FCM360W_DRIVER_Set_QHTTPPOST_Command(uint8_t CMD_TYPE, uint8_t DATA_LENGTH, uint16_t INPUT_TIME, uint8_t RESPONSE_TIME);

void FCM360W_DRIVER_Set_QHTTPPUT_Command(uint8_t CMD_TYPE, uint8_t DATA_LENGTH, uint16_t INPUT_TIME, uint8_t RESPONSE_TIME);

void FCM360W_DRIVER_Set_QHTTPREAD_Command(uint8_t CMD_TYPE, uint16_t WAIT_TIME);

void FCM360W_DRIVER_Set_QHTTPSTOP_Command(uint8_t CMD_TYPE);

void FCM360W_DRIVER_Set_QPING_Command(uint8_t CMD_TYPE, uint8_t HOST, uint8_t TIMEOUT, uint8_t PING_NUM);

void FCM360W_DRIVER_Set_QIDNSGIP_Command(uint8_t CMD_TYPE, char *HOSTNAME);

void FCM360W_DRIVER_Set_QFOPEN_Command(uint8_t CMD_TYPE, char *FILE_NAME, uint8_t MODE);

void FCM360W_DRIVER_Set_QFREAD_Command(uint8_t CMD_TYPE, uint8_t FILE_HANDLE, uint8_t LENGTH);

void FCM360W_DRIVER_Set_QFWRITE_Command(uint8_t CMD_TYPE, uint8_t FILE_HANDLE, uint8_t LENGTH, uint8_t TIMEOUT);

void FCM360W_DRIVER_Set_QFCLOSE_Command(uint8_t CMD_TYPE, uint8_t FILE_HANDLE);

void FCM360W_DRIVER_Set_QFLST_Command(uint8_t CMD_TYPE, char *NAME_PATTERN);

void FCM360W_DRIVER_Read_Module_Response(void);

bool FCM360W_DRIVER_Get_Module_Response_Status(void);

void FCM360W_DRIVER_Set_Module_Response_Status(bool FCM360W_RESPONSE_STATUS);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _FCM360W_DRIVER_H */

/*******************************************************************************
 End of File
 */