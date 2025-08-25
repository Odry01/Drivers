/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    vcnl4200_driver.h
 
  Status:
    In development

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "VCNL4200_DRIVER_Initialize" and "VCNL4200_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "VCNL4200_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _VCNL4200_DRIVER_H
#define _VCNL4200_DRIVER_H

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

#define VCNL4200_CMD_ALS_CFG            0x0
#define VCNL4200_CMD_ALS_THDH           0x1
#define VCNL4200_CMD_ALS_THDL           0x2
#define VCNL4200_CMD_PS_CFG1            0x3    /**/
#define VCNL4200_CMD_PS_CFG2            0x3    /**/
#define VCNL4200_CMD_PS_CFG3            0x4    /**/
#define VCNL4200_CMD_PS_MS              0x4    /**/
#define VCNL4200_CMD_PS_CANC            0x5
#define VCNL4200_CMD_PS_THDL            0x6
#define VCNL4200_CMD_PS_THDH            0x7
#define VCNL4200_CMD_PS_DATA            0x8
#define VCNL4200_CMD_ALS_DATA           0x9
#define VCNL4200_CMD_WHITE_DATA         0xA
#define VCNL4200_CMD_INT_FLAG           0xD
#define VCNL4200_CMD_ID                 0xE

#define VCNL4200_I2C_RX_BUFFER_SIZE     8
#define VCNL4200_I2C_TX_BUFFER_SIZE     8

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
    VCNL4200_DRIVER_STATE_INIT = 0,
    VCNL4200_DRIVER_STATE_I2C_HANDLER_REGISTER,
    VCNL4200_DRIVER_STATE_IDLE,
    VCNL4200_DRIVER_STATE_TIMER_EXPIRED,
    VCNL4200_DRIVER_STATE_ERROR,
} VCNL4200_DRIVER_STATES;

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
    VCNL4200_DRIVER_STATES state;

    /* Driver variables */
    DRV_HANDLE I2C_HANDLE;
    DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE;
    volatile bool I2C_TRANSFER_STATUS;
    volatile bool VCNL4200_TASK_START;
    volatile bool VCNL4200_TASK_COMPLETED;
    volatile bool VCNL4200_ALERT;
    uint8_t I2C_ADDRESS[1];
    uint8_t I2C_DATA_RECEIVE[VCNL4200_I2C_RX_BUFFER_SIZE];
    uint8_t I2C_DATA_TRANSMIT[VCNL4200_I2C_TX_BUFFER_SIZE];
} VCNL4200_DRIVER_DATA;

typedef struct
{
    uint8_t ALS_CFG;
    uint8_t ALS_THDH_MSB;
    uint8_t ALS_THDH_LSB;
    uint8_t ALS_THDL_MSB;
    uint8_t ALS_THDL_LSB;
    uint8_t PS_CFG1;
    uint8_t PS_CFG2;
    uint8_t PS_CFG3;
    uint8_t PS_MS;
    uint8_t PS_CANC_MSB;
    uint8_t PS_CANC_LSB;
    uint8_t PS_THDH_MSB;
    uint8_t PS_THDH_LSB;
    uint8_t PS_THDL_MSB;
    uint8_t PS_THDL_LSB;
    uint8_t INT_FLAG;
    uint16_t ALS_THDH;
    uint16_t ALS_THDL;
    uint16_t PS_THDH;
    uint16_t PS_THDL;
    uint16_t PS_DATA;
    uint16_t ALS_DATA;
    uint16_t WHITE_DATA;
    uint16_t ID;
} VCNL4200_SENSOR_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

void VCNL4200_DRIVER_I2C_Callback(DRV_I2C_TRANSFER_EVENT EVENT, DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE, uintptr_t CONTEXT);

void VCNL4200_DRIVER_Alert(uintptr_t CONTEXT);

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void VCNL4200_DRIVER_Initialize(void);

void VCNL4200_DRIVER_Tasks(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _VCNL4200_DRIVER_H */

/*******************************************************************************
 End of File
 */