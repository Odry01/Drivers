/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    fcm360w_driver.c

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

#include "fcm360w_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

FCM360W_DRIVER_DATA fcm360w_driverData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void FCM360W_DRIVER_USART_Callback(DRV_USART_BUFFER_EVENT EVENT, DRV_USART_BUFFER_HANDLE USART_BUFFER_HANDLE, uintptr_t CONTEXT)
{
    switch (EVENT)
    {
        case DRV_USART_BUFFER_EVENT_COMPLETE:
        {
            fcm360w_driverData.USART_TRANSFER_STATUS = true;
            break;
        }

        case DRV_USART_BUFFER_EVENT_ERROR:
        {
            fcm360w_driverData.USART_TRANSFER_STATUS = false;
            break;
        }

        default:
        {
            break;
        }
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

bool FCM360W_DRIVER_Get_Task_Start_Status(void)
{
    return (fcm360w_driverData.FCM360W_TASK_START);
}

void FCM360W_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    fcm360w_driverData.FCM360W_TASK_START = STATUS;
}

bool FCM360W_DRIVER_Get_Task_Completed_Status(void)
{
    return (fcm360w_driverData.FCM360W_TASK_COMPLETED);
}

void FCM360W_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    fcm360w_driverData.FCM360W_TASK_COMPLETED = STATUS;
}

void FCM360W_DRIVER_Set_QRESET_Command(uint8_t CMD_TYPE)
{
    if (CMD_TYPE == FCM360W_EXECUTION_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s\r\r", AT_QRESET);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QVERSION_Command(uint8_t CMD_TYPE)
{
    if (CMD_TYPE == FCM360W_EXECUTION_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s\r\r", AT_QVERSION);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QECHO_Command(uint8_t CMD_TYPE, uint8_t ENABLE)
{
    if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d\r\r", AT_QECHO, ENABLE);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QGETIP_Command(uint8_t CMD_TYPE, uint8_t MODE)
{
    if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d\r\r", AT_QGETIP, MODE);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QSETBAND_Command(uint8_t CMD_TYPE, uint32_t BAUD_RATE, uint8_t SAVE_STATUS)
{
    if (CMD_TYPE == FCM360W_READ_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s?\r\r", AT_QSETBAND);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%ld,%d\r\r", AT_QSETBAND, BAUD_RATE, SAVE_STATUS);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QWLANOTA_Command(uint8_t CMD_TYPE, char *URL)
{
    if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%s\r\r", AT_QWLANOTA, URL);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QWLMAC_Command(uint8_t CMD_TYPE)
{
    if (CMD_TYPE == FCM360W_EXECUTION_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s\r\r", AT_QWLMAC);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QSTAST_Command(uint8_t CMD_TYPE)
{
    if (CMD_TYPE == FCM360W_EXECUTION_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s\r\r", AT_QSTAST);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QSTADHCP_Command(uint8_t CMD_TYPE, uint8_t ENABLE)
{
    if (CMD_TYPE == FCM360W_READ_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s?\r\r", AT_QSTADHCP);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d\r\r", AT_QSTADHCP, ENABLE);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QAPSTATIC_Command(uint8_t CMD_TYPE, char *IP, char *MASK, char *GATE, char *DNS)
{
    if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%s,%s,%s,%s\r\r", AT_QAPSTATIC, IP, MASK, GATE, DNS);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QSTASTOP_Command(uint8_t CMD_TYPE)
{
    if (CMD_TYPE == FCM360W_EXECUTION_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s\r\r", AT_QSTASTOP);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QSOFTAP_Command(uint8_t CMD_TYPE, char *SSID, char *KEY)
{
    if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%s,%s\r\r", AT_QSOFTAP, SSID, KEY);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QAPSTATE_Command(uint8_t CMD_TYPE)
{
    if (CMD_TYPE == FCM360W_EXECUTION_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s\r\r", AT_QAPSTATE);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QSOFTAPSTOP_Command(uint8_t CMD_TYPE)
{
    if (CMD_TYPE == FCM360W_EXECUTION_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s\r\r", AT_QSOFTAPSTOP);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QSTAAPINFO_Command(uint8_t CMD_TYPE, char *SSID, char *PWD)
{
    if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%s,%s\r\r", AT_QSTAAPINFO, SSID, PWD);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QSTAAPINFODEF_Command(uint8_t CMD_TYPE, char *SSID, char *PWD)
{
    if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%s,%s\r\r", AT_QSTAAPINFODEF, SSID, PWD);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QGETWIFISTATE_Command(uint8_t CMD_TYPE)
{
    if (CMD_TYPE == FCM360W_EXECUTION_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s\r\r", AT_QGETWIFISTATE);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QWSCAN_Command(uint8_t CMD_TYPE)
{
    if (CMD_TYPE == FCM360W_EXECUTION_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s\r\r", AT_QWSCAN);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QIDNSCFG_Command(uint8_t CMD_TYPE, char *PRIMARY_DNS_ADDRESS, char *SECONDARY_DNS_ADDRESS)
{
    if (CMD_TYPE == FCM360W_READ_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s?\r\r", AT_QIDNSCFG);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%s,%s\r\r", AT_QIDNSCFG, PRIMARY_DNS_ADDRESS, SECONDARY_DNS_ADDRESS);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QWEBCFG_Command(uint8_t CMD_TYPE, uint8_t ENABLE)
{
    if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d\r\r", AT_QWEBCFG, ENABLE);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QSTAAPINFORMV_Command(uint8_t CMD_TYPE)
{
    if (CMD_TYPE == FCM360W_EXECUTION_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s\r\r", AT_QSTAAPINFORMV);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QBLEINIT_Command(uint8_t CMD_TYPE, uint8_t ROLE, uint8_t AUTO_ADV)
{
    if (CMD_TYPE == FCM360W_READ_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s?\r\r", AT_QBLEINIT);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d\r\r", AT_QBLEINIT, ROLE, AUTO_ADV);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QBLEADDR_Command(uint8_t CMD_TYPE)
{
    if (CMD_TYPE == FCM360W_READ_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s?\r\r", AT_QBLEADDR);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QBLENAME_Command(uint8_t CMD_TYPE, char *BLE_NAME)
{
    if (CMD_TYPE == FCM360W_READ_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s?\r\r", AT_QBLENAME);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%s\r\r", AT_QBLENAME, BLE_NAME);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QBLEADVPARAM_Command(uint8_t CMD_TYPE, uint16_t ADV_INT_MIN, uint16_t ADV_INT_MAX)
{
    if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d\r\r", AT_QBLEADVPARAM, ADV_INT_MIN, ADV_INT_MAX);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QBLEADVDATA_Command(uint8_t CMD_TYPE, char *ADV_DATA)
{
    if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%s\r\r", AT_QBLEADVDATA, ADV_DATA);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QBLEGATTSSRV_Command(uint8_t CMD_TYPE, char *SRV_UUID)
{
    if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%s\r\r", AT_QBLEGATTSSRV, SRV_UUID);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QBLEGATTSCHAR_Command(uint8_t CMD_TYPE, char *CHAR_UUID)
{
    if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%s\r\r", AT_QBLEGATTSCHAR, CHAR_UUID);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QBLEGATTSSRVDONE_Command(uint8_t CMD_TYPE)
{
    if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s\r\r", AT_QBLEGATTSSRVDONE);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QBLEADVSTART_Command(uint8_t CMD_TYPE)
{
    if (CMD_TYPE == FCM360W_EXECUTION_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s\r\r", AT_QBLEADVSTART);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QBLEADVSTOP_Command(uint8_t CMD_TYPE)
{
    if (CMD_TYPE == FCM360W_EXECUTION_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s\r\r", AT_QBLEADVSTOP);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QBLEGATTSNTFY_Command(uint8_t CMD_TYPE, char *UUID, uint32_t HEX_LENGTH, char *DATA)
{
    if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%s,%ld,%s\r\r", AT_QBLEGATTSNTFY, UUID, HEX_LENGTH, DATA);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QICFG_Command(uint8_t CMD_TYPE, uint16_t TRANS_PKT_SIZE, uint8_t TRANS_WAIT_TIME, uint8_t SEND_DATA_FORMAT, uint8_t RECV_DATA_FORMAT, uint8_t CLOSED, uint8_t STATE, uint8_t TIMEOUT, uint8_t CLOSE_MODE, uint8_t TW_ENABLE)
{
    if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=transpktsize,%d\r\r", AT_QICFG, TRANS_PKT_SIZE);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_1)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=transwaittm,%d\r\r", AT_QICFG, TRANS_WAIT_TIME);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_2)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=DATAformat,%d,%d\r\r", AT_QICFG, SEND_DATA_FORMAT, RECV_DATA_FORMAT);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_3)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=passiveclosed,%d\r\r", AT_QICFG, CLOSED);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_4)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=tcp/accept,%d\r\r", AT_QICFG, STATE);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_5)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=qisend/timeout,%d\r\r", AT_QICFG, TIMEOUT);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_6)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=close/MODE,%d\r\r", AT_QICFG, CLOSE_MODE);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_7)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=tcp/tw_cycle,%d\r\r", AT_QICFG, TW_ENABLE);
    }
    else if (CMD_TYPE == FCM360W_EXECUTION_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r\r", AT_QICFG);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QIOPEN_Command(uint8_t CMD_TYPE, uint8_t CONNECT_ID, char *service_type, char *IP_address, char *domain_name, uint16_t remote_port, uint16_t local_port, uint8_t ACCESS_MODE)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r\r", AT_QIOPEN);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%s,%s/%s,%d,%d,%d\r\r", AT_QIOPEN, CONNECT_ID, service_type, IP_address, domain_name, remote_port, local_port, ACCESS_MODE);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QICLOSE_Command(uint8_t CMD_TYPE, uint8_t CONNECT_ID, uint8_t TIMEOUT)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r\r", AT_QICLOSE);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d\r\r", AT_QICLOSE, CONNECT_ID, TIMEOUT);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QISTATE_Command(uint8_t CMD_TYPE, uint8_t CONNECT_ID)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QISTATE);
    }
    else if (CMD_TYPE == FCM360W_READ_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s?\r", AT_QISTATE);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d\r", AT_QISTATE, CONNECT_ID);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QISEND_Command(uint8_t CMD_TYPE, uint8_t CONNECT_ID, uint16_t SEND_LENGTH, char *REMOTE_IP, uint16_t REMOTE_PORT, uint16_t TOTAL_SEND_LENGTH, uint16_t ACKED_BYTES, uint16_t UNACKED_BYTES)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QISEND);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d\r", AT_QISEND, CONNECT_ID);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_1)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d\r", AT_QISEND, CONNECT_ID, SEND_LENGTH);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_2)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d,%s,%d\r", AT_QISEND, CONNECT_ID, SEND_LENGTH, REMOTE_IP, REMOTE_PORT);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_3)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,0\r", AT_QISEND, CONNECT_ID);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QIRD_Command(uint8_t CMD_TYPE, uint8_t CONNECT_ID, uint16_t READ_LENGTH)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QIRD);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d\r", AT_QIRD, CONNECT_ID, READ_LENGTH);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_1)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d\r", AT_QIRD, CONNECT_ID);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_2)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,0\r", AT_QIRD, CONNECT_ID);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QIACCEPT_Command(uint8_t CMD_TYPE, uint8_t LISTENER_SOCKET_ID, uint8_t ACCEPT, uint8_t INCOMING_SOCKET_ID)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QIACCEPT);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d,%d\r", AT_QIACCEPT, LISTENER_SOCKET_ID, ACCEPT, INCOMING_SOCKET_ID);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QISWTMD_Command(uint8_t CMD_TYPE, uint8_t CONNECT_ID, uint8_t ACCESS_MODE)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QISWTMD);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d\r", AT_QISWTMD, CONNECT_ID, ACCESS_MODE);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QIGETERROR_Command(uint8_t CMD_TYPE)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QIGETERROR);
    }
    else if (CMD_TYPE == FCM360W_EXECUTION_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s\r", AT_QIGETERROR);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_ATO_Command(uint8_t CMD_TYPE)
{
    if (CMD_TYPE == FCM360W_EXECUTION_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s\r", AT_TRANSPARENT_MODE_ENTER);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QPPPEXIT_Command(uint8_t CMD_TYPE)
{
    if (CMD_TYPE == FCM360W_EXECUTION_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s\r", AT_TRANSPARENT_MODE_EXIT);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QSSLCFG_Command(uint8_t CMD_TYPE, uint8_t SSL_CTX_ID, uint8_t SSL_VERSION, uint16_t CIPHER_SUITES, uint8_t IGNORE_L_TIME, uint8_t SECURTITY_LEVEL, uint8_t NEGOTIATE_TIME, uint8_t SNI, uint8_t SESSION_CACHE_ENABLE)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QSSLCFG);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=sslversion,%d,%d\r", AT_QSSLCFG, SSL_CTX_ID, SSL_VERSION);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_1)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=ciphersuite,%d,%X\r", AT_QSSLCFG, SSL_CTX_ID, CIPHER_SUITES);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_2)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=seclevel,%d,%d\r", AT_QSSLCFG, SSL_CTX_ID, SECURTITY_LEVEL);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_3)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=ignorelocaltime,%d,%d\r", AT_QSSLCFG, SSL_CTX_ID, IGNORE_L_TIME);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_4)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=negotiatetime,%d,%d\r", AT_QSSLCFG, SSL_CTX_ID, NEGOTIATE_TIME);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_5)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=sni,%d,%d\r", AT_QSSLCFG, SSL_CTX_ID, SNI);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_6)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=session_cache,%d,%d\r", AT_QSSLCFG, SSL_CTX_ID, SESSION_CACHE_ENABLE);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QSSLOPEN_Command(uint8_t CMD_TYPE, uint8_t SSL_CTX_ID, uint8_t CONNECT_ID, char *SERVER_ADDRESS, uint16_t SERVER_PORT, uint8_t ACCESS_MODE)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QSSLOPEN);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d,%s,%d,%d\r", AT_QSSLOPEN, SSL_CTX_ID, CONNECT_ID, SERVER_ADDRESS, SERVER_PORT, ACCESS_MODE);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QSSLSEND_Command(uint8_t CMD_TYPE, uint8_t CONNECT_ID, uint16_t SEND_LENGTH)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QSSLSEND);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d\r", AT_QSSLSEND, CONNECT_ID);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_1)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d\r", AT_QSSLSEND, CONNECT_ID, SEND_LENGTH);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QSSLRECV_Command(uint8_t CMD_TYPE, uint8_t CONNECT_ID, uint16_t SEND_LENGTH)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QSSLRECV);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d\r", AT_QSSLRECV, CONNECT_ID, SEND_LENGTH);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QSSLCLOSE_Command(uint8_t CMD_TYPE, uint8_t CONNECT_ID, uint16_t CLOSE_TIMEOUT)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QSSLCLOSE);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d\r", AT_QSSLCLOSE, CONNECT_ID, CLOSE_TIMEOUT);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QSSLSTATE_Command(uint8_t CMD_TYPE, uint8_t QUERY_TYPE, uint8_t CONNECT_ID)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QSSLSTATE);
    }
    else if (CMD_TYPE == FCM360W_QUERY_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s?\r", AT_QSSLSTATE);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d\r", AT_QSSLSTATE, QUERY_TYPE, CONNECT_ID);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_1)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d\r", AT_QSSLSTATE, QUERY_TYPE, CONNECT_ID);
    }
    else if (CMD_TYPE == FCM360W_EXECUTION_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s\r", AT_QSSLSTATE);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QMTCFG_Command(uint8_t CMD_TYPE, uint8_t CLIENT_IDX, uint8_t VSN, uint8_t SSL_ENABLE, uint8_t SSL_CTX_IDX, uint16_t KEEP_ALIVE_TIME, uint8_t CLEAN_SESSION, uint16_t PKT_TIMEOUT, uint8_t RETRY_TIMES, uint8_t TIMEOUT_NOTICE, char *WILL_TOPIC, char *WILL_MESSAGE, uint8_t WILL_FLAG, uint8_t WILL_QOS, uint8_t WILL_RETAIN, uint8_t MSG_RECV_MODE, uint8_t SEND_MODE, uint8_t RECV_MODE)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QMTCFG);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=version,%d,%d\r", AT_QMTCFG, CLIENT_IDX, VSN);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_1)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=ssl,%d,%d,%d\r", AT_QMTCFG, CLIENT_IDX, SSL_ENABLE, SSL_CTX_IDX);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_2)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=keepalive,%d,%d\r", AT_QMTCFG, CLIENT_IDX, KEEP_ALIVE_TIME);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_3)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=session,%d,%d\r", AT_QMTCFG, CLIENT_IDX, CLEAN_SESSION);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_4)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=timeout,%d,%d,%d,%d\r", AT_QMTCFG, CLIENT_IDX, PKT_TIMEOUT, RETRY_TIMES, TIMEOUT_NOTICE);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_5)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=will,%d,%d,%d,%d,%s,%s\r", AT_QMTCFG, CLIENT_IDX, WILL_FLAG, WILL_QOS, WILL_RETAIN, WILL_TOPIC, WILL_MESSAGE);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_6)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=recv/MODE,%d,%d\r", AT_QMTCFG, CLIENT_IDX, MSG_RECV_MODE);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_7)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=DATAformat,%d,%d,%d\r", AT_QMTCFG, CLIENT_IDX, SEND_MODE, RECV_MODE);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QMTOPEN_Command(uint8_t CMD_TYPE, uint8_t CLIENT_IDX, char *HOST_NAME, uint16_t PORT)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QMTOPEN);
    }
    else if (CMD_TYPE == FCM360W_READ_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s?\r", AT_QMTOPEN);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%s,%d\r", AT_QMTOPEN, CLIENT_IDX, HOST_NAME, PORT);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QMTCLOSE_Command(uint8_t CMD_TYPE, uint8_t CLIENT_IDX)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QMTCLOSE);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d\r", AT_QMTCLOSE, CLIENT_IDX);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QMTCONN_Command(uint8_t CMD_TYPE, uint8_t CLIENT_IDX, char *CLIENT_ID, char *USERNAME, char *PWD)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QMTCONN);
    }
    else if (CMD_TYPE == FCM360W_QUERY_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s?\r", AT_QMTCONN);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%s,%s,%s\r", AT_QMTCONN, CLIENT_IDX, CLIENT_ID, USERNAME, PWD);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QMTDISC_Command(uint8_t CMD_TYPE, uint8_t CLIENT_IDX)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QMTDISC);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d\r", AT_QMTDISC, CLIENT_IDX);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QMTSUB_Command(uint8_t CMD_TYPE, uint8_t CLIENT_IDX, uint8_t MESSAGE_ID, char *TOPIC, uint8_t QOS)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QMTSUB);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d,%s,%d\r", AT_QMTSUB, CLIENT_IDX, MESSAGE_ID, TOPIC, QOS);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QMTUNS_Command(int8_t CMD_TYPE, uint8_t CLIENT_IDX, uint8_t MESSAGE_ID, char *TOPIC)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QMTUNS);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d,%s\r", AT_QMTUNS, CLIENT_IDX, MESSAGE_ID, TOPIC);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QMTPUB_Command(uint8_t CMD_TYPE, uint8_t CLIENT_IDX, uint16_t MESSAGE_ID, uint8_t QOS, uint8_t RETAIN, char *TOPIC, uint16_t LENGTH)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QMTPUB);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d,%d,%d,%s,%d\r", AT_QMTPUB, CLIENT_IDX, MESSAGE_ID, QOS, RETAIN, TOPIC, LENGTH);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QMTRECV_Command(uint8_t CMD_TYPE, uint8_t CLIENT_IDX, uint16_t RECEIVE_ID)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QMTRECV);
    }
    else if (CMD_TYPE == FCM360W_QUERY_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s?\r", AT_QMTRECV);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s,%d,%d\r", AT_QMTRECV, CLIENT_IDX, RECEIVE_ID);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QHTTPCFG_Command(uint8_t CMD_TYPE, char *URL_STRING, char *HEADER_VALUE, char *USERNAME_PWD, char *NAME, char *FILE_NAME, char *CONTENT_TYPE, uint8_t SSL_CTX_ID, uint8_t RESPONSE_HEADER, uint8_t AUTO_OUTRSP, uint8_t CLOSED_INDICATION)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QHTTPCFG);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=url,%s\r", AT_QHTTPCFG, URL_STRING);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_1)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=header,%s\r", AT_QHTTPCFG, HEADER_VALUE);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_2)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=auth,%s\r", AT_QHTTPCFG, USERNAME_PWD);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_3)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=sslctxid,%d\r", AT_QHTTPCFG, SSL_CTX_ID);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_4)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=rsp/header,%d\r", AT_QHTTPCFG, RESPONSE_HEADER);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_5)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=rspout/auto,%d\r", AT_QHTTPCFG, AUTO_OUTRSP);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_6)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=closed/ind,%d\r", AT_QHTTPCFG, CLOSED_INDICATION);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_7)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=form/option,%s,%s,%s\r", AT_QHTTPCFG, NAME, FILE_NAME, CONTENT_TYPE);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_8)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=reset\r", AT_QHTTPCFG);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QHTTPGET_Command(uint8_t CMD_TYPE, uint8_t RESPONSE_TIME)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QHTTPGET);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d\r", AT_QHTTPGET, RESPONSE_TIME);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QHTTPPOST_Command(uint8_t CMD_TYPE, uint8_t DATA_LENGTH, uint16_t INPUT_TIME, uint8_t RESPONSE_TIME)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QHTTPPOST);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d,%d\r", AT_QHTTPPOST, DATA_LENGTH, INPUT_TIME, RESPONSE_TIME);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QHTTPPUT_Command(uint8_t CMD_TYPE, uint8_t DATA_LENGTH, uint16_t INPUT_TIME, uint8_t RESPONSE_TIME)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QHTTPPUT);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d,%d\r", AT_QHTTPPUT, DATA_LENGTH, INPUT_TIME, RESPONSE_TIME);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QHTTPREAD_Command(uint8_t CMD_TYPE, uint16_t WAIT_TIME)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QHTTPREAD);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d\r", AT_QHTTPREAD, WAIT_TIME);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QHTTPSTOP_Command(uint8_t CMD_TYPE)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QHTTPSTOP);
    }
    else if (CMD_TYPE == FCM360W_EXECUTION_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s\r", AT_QHTTPSTOP);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QPING_Command(uint8_t CMD_TYPE, uint8_t HOST, uint8_t TIMEOUT, uint8_t PING_NUM)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QPING);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d,%d\r", AT_QPING, HOST, TIMEOUT, PING_NUM);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QIDNSGIP_Command(uint8_t CMD_TYPE, char *HOSTNAME)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QIDNSGIP);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%s\r", AT_QIDNSGIP, HOSTNAME);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QFOPEN_Command(uint8_t CMD_TYPE, char *FILENAME, uint8_t MODE)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QFOPEN);
    }
    else if (CMD_TYPE == FCM360W_QUERY_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s?\r", AT_QFOPEN);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%s,%d\r", AT_QFOPEN, FILENAME, MODE);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QFREAD_Command(uint8_t CMD_TYPE, uint8_t FILE_HANDLE, uint8_t LENGTH)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QFREAD);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d\r", AT_QFREAD, FILE_HANDLE, LENGTH);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QFWRITE_Command(uint8_t CMD_TYPE, uint8_t FILE_HANDLE, uint8_t LENGTH, uint8_t TIMEOUT)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QFWRITE);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d,%d,%d\r", AT_QFWRITE, FILE_HANDLE, LENGTH, TIMEOUT);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QFCLOSE_Command(uint8_t CMD_TYPE, uint8_t FILE_HANDLE)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QFCLOSE);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%d\r", AT_QFCLOSE, FILE_HANDLE);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Set_QFLST_Command(uint8_t CMD_TYPE, char *NAME_PATTERN)
{
    if (CMD_TYPE == FCM360W_TEST_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=?\r", AT_QFLST);
    }
    else if (CMD_TYPE == FCM360W_WRITE_CMD_0)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s=%s\r", AT_QFLST, NAME_PATTERN);
    }
    else if (CMD_TYPE == FCM360W_EXECUTION_CMD)
    {
        sprintf(fcm360w_driverData.TX_BUFFER, "%s\r", AT_QFLST);
    }
    DRV_USART_WriteBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.TX_BUFFER, strlen(fcm360w_driverData.TX_BUFFER), &fcm360w_driverData.USART_BUFFER_HANDLE);
}

void FCM360W_DRIVER_Read_Module_Response(void)
{
    DRV_USART_ReadBufferAdd(fcm360w_driverData.USART_HANDLE, &fcm360w_driverData.RX_BYTE, 1, &fcm360w_driverData.USART_BUFFER_HANDLE);
}

bool FCM360W_DRIVER_Get_Module_Response_Status(void)
{
    if (strstr(fcm360w_driverData.RX_BUFFER, "OK") || strstr(fcm360w_driverData.RX_BUFFER, ">"))
    {
        fcm360w_driverData.FCM360W_RESPONSE_STATUS = true;
    }
    else
    {
        fcm360w_driverData.FCM360W_RESPONSE_STATUS = false;
    }
    return (fcm360w_driverData.FCM360W_RESPONSE_STATUS);
}

void FCM360W_DRIVER_Set_Module_Response_Status(bool FCM360W_RESPONSE_STATUS)
{
    fcm360w_driverData.FCM360W_RESPONSE_STATUS = FCM360W_RESPONSE_STATUS;
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void FCM360W_DRIVER_Initialize(void)
{
    fcm360w_driverData.state = FCM360W_DRIVER_STATE_INIT;
    fcm360w_driverData.USART_HANDLE = DRV_HANDLE_INVALID;
    fcm360w_driverData.USART_BUFFER_HANDLE = DRV_USART_BUFFER_HANDLE_INVALID;
    fcm360w_driverData.USART_TRANSFER_STATUS = false;
}

void FCM360W_DRIVER_Tasks(void)
{
    switch (fcm360w_driverData.state)
    {
        case FCM360W_DRIVER_STATE_INIT:
        {
            fcm360w_driverData.USART_HANDLE = DRV_USART_Open(DRV_USART_INDEX_0, DRV_IO_INTENT_READWRITE);
            fcm360w_driverData.state = FCM360W_DRIVER_STATE_USART_HANDLER_REGISTER;
            break;
        }

        case FCM360W_DRIVER_STATE_USART_HANDLER_REGISTER:
        {
            if (fcm360w_driverData.USART_HANDLE == DRV_HANDLE_INVALID)
            {
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_ERROR;
            }
            else
            {
                DRV_USART_BufferEventHandlerSet(fcm360w_driverData.USART_HANDLE, FCM360W_DRIVER_USART_Callback, 0);
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_IDLE;
            }
            break;
        }

        case FCM360W_DRIVER_STATE_IDLE:
        {
            if (FCM360W_DRIVER_Get_Task_Start_Status() == true)
            {
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_MESSAGE_TRANSMIT;
            }
            break;
        }

        case FCM360W_DRIVER_STATE_QRST_MESSAGE_TRANSMIT:
        {
            FCM360W_DRIVER_Set_QRESET_Command(FCM360W_EXECUTION_CMD);
            TIMER_DRIVER_Start_Bus_TMR();
            fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_CHECK_MESSAGE_TX_BUFFER;
            break;
        }

        case FCM360W_DRIVER_STATE_QRST_CHECK_MESSAGE_TX_BUFFER:
        {
            if (fcm360w_driverData.USART_BUFFER_HANDLE == DRV_USART_BUFFER_HANDLE_INVALID)
            {
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_TIMER_EXPIRED;
            }
            else
            {
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_WAIT_FOR_MESSAGE_TRANSMIT;
            }
            break;
        }

        case FCM360W_DRIVER_STATE_QRST_WAIT_FOR_MESSAGE_TRANSMIT:
        {
            if (fcm360w_driverData.USART_TRANSFER_STATUS == true)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                fcm360w_driverData.USART_TRANSFER_STATUS = false;
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_READ_MODULE_RESPONSE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case FCM360W_DRIVER_STATE_QRST_READ_MODULE_RESPONSE:
        {
            FCM360W_DRIVER_Read_Module_Response();
            TIMER_DRIVER_Start_Bus_TMR();
            fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_CHECK_MESSAGE_RX_BUFFER;
            break;
        }

        case FCM360W_DRIVER_STATE_QRST_CHECK_MESSAGE_RX_BUFFER:
        {
            if (fcm360w_driverData.USART_BUFFER_HANDLE == DRV_USART_BUFFER_HANDLE_INVALID)
            {
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_TIMER_EXPIRED;
            }
            else
            {
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_WAIT_FOR_MESSAGE_RECEIVE;
            }
            break;
        }

        case FCM360W_DRIVER_STATE_QRST_WAIT_FOR_MESSAGE_RECEIVE:
        {
            if (fcm360w_driverData.USART_TRANSFER_STATUS == true)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                fcm360w_driverData.USART_TRANSFER_STATUS = false;
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_STORE_BYTE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case FCM360W_DRIVER_STATE_QRST_STORE_BYTE:
        {
            fcm360w_driverData.RX_BUFFER[fcm360w_driverData.RX_COUNT] = fcm360w_driverData.RX_BYTE;
            fcm360w_driverData.RX_COUNT++;
            fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_STORE_END_OF_LINE_COUNT;
            break;
        }

        case FCM360W_DRIVER_STATE_QRST_STORE_END_OF_LINE_COUNT:
        {
            if (fcm360w_driverData.RX_BYTE == '\n')
            {
                fcm360w_driverData.END_OF_LINE_COUNT++;
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_CHECK_CR_LF_COUNT;
            }
            else
            {
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_READ_MODULE_RESPONSE;
            }
            break;
        }

        case FCM360W_DRIVER_STATE_QRST_CHECK_CR_LF_COUNT:
        {
            if (fcm360w_driverData.END_OF_LINE_COUNT == 2)
            {
                fcm360w_driverData.RX_COUNT = 0;
                fcm360w_driverData.END_OF_LINE_COUNT = 0;
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_CHECK_MODULE_RESPONSE;
            }
            else
            {
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_QRST_READ_MODULE_RESPONSE;
            }
            break;
        }

        case FCM360W_DRIVER_STATE_QRST_CHECK_MODULE_RESPONSE:
        {
            if (FCM360W_DRIVER_Get_Module_Response_Status() == true)
            {
                FCM360W_DRIVER_Set_Module_Response_Status(false);
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_IDLE;
            }
            else
            {
                fcm360w_driverData.state = FCM360W_DRIVER_STATE_ERROR;
            }
            break;
        }

        case FCM360W_DRIVER_STATE_TIMER_EXPIRED:
        {
            DRV_USART_Close(fcm360w_driverData.USART_HANDLE);
            FCM360W_DRIVER_Set_Task_Completed_Status(true);
            fcm360w_driverData.state = FCM360W_DRIVER_STATE_IDLE;
            break;
        }

        case FCM360W_DRIVER_STATE_ERROR:
        {
            DRV_USART_Close(fcm360w_driverData.USART_HANDLE);
            FCM360W_DRIVER_Set_Task_Completed_Status(true);
            fcm360w_driverData.state = FCM360W_DRIVER_STATE_IDLE;
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