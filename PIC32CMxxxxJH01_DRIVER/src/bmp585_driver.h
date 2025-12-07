/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    bmp585_driver.h

  Status:
    In development
 
  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "BMP585_DRIVER_Initialize" and "BMP585_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "BMP585_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _BMP585_DRIVER_H
#define _BMP585_DRIVER_H

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

#define BMP585_CMD_CHIP_ID                          0x01
#define BMP585_CMD_REV_ID                           0x02
#define BMP585_CMD_CHIP_STATUS                      0x11
#define BMP585_CMD_DRIVE_CONFIG                     0x13
#define BMP585_CMD_INT_CONFIG                       0x14
#define BMP585_CMD_INT_SOURCE                       0x15
#define BMP585_CMD_FIFO_CONFIG                      0x16
#define BMP585_CMD_FIFO_COUNT                       0x17
#define BMP585_CMD_FIFO_SEL                         0x18
#define BMP585_CMD_TEMP_DATA_XLSB                   0x1D
#define BMP585_CMD_TEMP_DATA_LSB                    0x1E
#define BMP585_CMD_TEMP_DATA_MSB                    0x1F
#define BMP585_CMD_PRESS_DATA_XLSB                  0x20
#define BMP585_CMD_PRESS_DATA_LSB                   0x21
#define BMP585_CMD_PRESS_DATA_MSB                   0x22
#define BMP585_CMD_INT_STATUS                       0x27
#define BMP585_CMD_STATUS                           0x28
#define BMP585_CMD_FIFO_DATA                        0x29
#define BMP585_CMD_NVM_ADDR                         0x2B
#define BMP585_CMD_NVM_DATA_LSB                     0x2C
#define BMP585_CMD_NVM_DATA_MSB                     0x2D
#define BMP585_CMD_DSP_CONFIG                       0x30
#define BMP585_CMD_DSP_IIR                          0x31
#define BMP585_CMD_OOR_THR_P_LSB                    0x32
#define BMP585_CMD_OOR_THR_P_MSB                    0x33
#define BMP585_CMD_OOR_RANGE                        0x34
#define BMP585_CMD_OOR_CONFIG                       0x35
#define BMP585_CMD_OSR_CONFIG                       0x36
#define BMP585_CMD_ODR_CONFIG                       0x37
#define BMP585_CMD_OSR_EFF                          0x38
#define BMP585_CMD_COMMAND                          0x7E

#define BMP585_I2C_RX_BUFFER_SIZE                   8
#define BMP585_I2C_TX_BUFFER_SIZE                   8

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
    BMP585_DRIVER_STATE_INIT = 0,
    BMP585_DRIVER_STATE_CHECK_I2C_HANDLER,
    BMP585_DRIVER_STATE_IDLE,
    BMP585_DRIVER_STATE_TIMER_EXPIRED,
    BMP585_DRIVER_STATE_ERROR,
} BMP585_DRIVER_STATES;

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
    BMP585_DRIVER_STATES state;

    /* Driver variables */
    DRV_HANDLE I2C_HANDLE;
    DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE;
    volatile bool BMP585_TASK_START;
    volatile bool BMP585_TASK_COMPLETED;
    volatile bool BMP585_ALERT;
    uint8_t I2C_ADDRESS[2];
    uint8_t I2C_DATA_RECEIVE[BMP585_I2C_RX_BUFFER_SIZE];
    uint8_t I2C_DATA_TRANSMIT[BMP585_I2C_TX_BUFFER_SIZE];
} BMP585_DRIVER_DATA;

typedef struct
{
    uint8_t CHIP_ID;
    uint8_t CHIP_REVISION;
    uint8_t CHIP_STATUS;
    uint8_t DRIVE_CFG;
    uint8_t INT_CFG;
    uint8_t INT_SOURCE;
    uint8_t FIFO_CFG;
    uint8_t FIFO_COUNT;
    uint8_t FIFO_SELECT;
    uint8_t T_VALUE_XLSB;
    uint8_t T_VALUE_LSB;
    uint8_t T_VALUE_MSB;
    uint8_t P_VALUE_XLSB;
    uint8_t P_VALUE_LSB;
    uint8_t P_VALUE_MSB;
    uint8_t INT_STATUS;
    uint8_t STATUS;
    uint8_t FIFO_DATA;
    uint8_t NVM_ADDRESS;
    uint8_t NVM_DATA_LSB;
    uint8_t NVM_DATA_MSB;
    uint8_t DSP_CFG;
    uint8_t DSP_IIR;
    uint8_t OOR_THR_P_LSB;
    uint8_t OOR_THR_P_MSB;
    uint8_t OOR_RANGE;
    uint8_t OOR_CFG;
    uint8_t OSB_CFG;
    uint8_t ODR_CFG;
    uint8_t OSR_EFF;
    float CELSIUS_TEMPERATURE;
    float PA_PRESSURE;
} BMP585_SENSOR_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

void BMP585_DRIVER_Alert(uintptr_t CONTEXT);

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void BMP585_DRIVER_Initialize(void);

void BMP585_DRIVER_Tasks(void);

bool BMP585_DRIVER_Get_Task_Start_Status(void);

void BMP585_DRIVER_Set_Task_Start_Status(bool STATUS);

bool BMP585_DRIVER_Get_Task_Completed_Status(void);

void BMP585_DRIVER_Set_Task_Completed_Status(bool STATUS);

void BMP585_DRIVER_Get_Chip_ID(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_Chip_ID(void);

void BMP585_DRIVER_Get_Revision_ID(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_Revision_ID(void);

void BMP585_DRIVER_Get_Chip_Status(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_Chip_Status(void);

void BMP585_DRIVER_Get_Drive_Config(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_Drive_Config(void);

void BMP585_DRIVER_Set_Drive_Config(uint8_t I2C_ADDRESS, uint8_t CONFIG);

void BMP585_DRIVER_Get_INT_Config(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_INT_Config(void);

void BMP585_DRIVER_Set_INT_Config(uint8_t I2C_ADDRESS, uint8_t CONFIG);

void BMP585_DRIVER_Get_INT_Source(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_INT_Source(void);

void BMP585_DRIVER_Set_INT_Source(uint8_t I2C_ADDRESS, uint8_t SOURCE);

void BMP585_DRIVER_Get_FIFO_Config(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_FIFO_Config(void);

void BMP585_DRIVER_Set_FIFO_Config(uint8_t I2C_ADDRESS, uint8_t CONFIG);

void BMP585_DRIVER_Get_FIFO_Count(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_FIFO_Count(void);

void BMP585_DRIVER_Get_FIFO_Select(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_FIFO_Select(void);

void BMP585_DRIVER_Set_FIFO_Select(uint8_t I2C_ADDRESS, uint8_t SELECT);

void BMP585_DRIVER_Get_Temperature_Value_XLSB(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_Temperature_Value_XLSB(void);

void BMP585_DRIVER_Get_Temperature_Value_LSB(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_Temperature_Value_LSB(void);

void BMP585_DRIVER_Get_Temperature_Value_MSB(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_Temperature_Value_MSB(void);

void BMP585_DRIVER_Get_Pressure_Value_XLSB(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_Pressure_Value_XLSB(void);

void BMP585_DRIVER_Get_Pressure_Value_LSB(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_Pressure_Value_LSB(void);

void BMP585_DRIVER_Get_Pressure_Value_MSB(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_Pressure_Value_MSB(void);

void BMP585_DRIVER_Get_INT_Status(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_INT_Status(void);

void BMP585_DRIVER_Get_Status(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_Status(void);

void BMP585_DRIVER_Get_FIFO_Data(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_FIFO_Data(void);

void BMP585_DRIVER_Get_NVM_Address(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_NVM_Address(void);

void BMP585_DRIVER_Set_NVM_Address(uint8_t I2C_ADDRESS, uint8_t ADDRESS);

void BMP585_DRIVER_Get_NVM_Data_LSB(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_NVM_Data_LSB(void);

void BMP585_DRIVER_Set_NVM_Data_LSB(uint8_t I2C_ADDRESS, uint8_t DATA);

void BMP585_DRIVER_Get_NVM_Data_MSB(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_NVM_Data_MSB(void);

void BMP585_DRIVER_Set_NVM_Data_MSB(uint8_t I2C_ADDRESS, uint8_t DATA);

void BMP585_DRIVER_Get_DSP_Config(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_DSP_Config(void);

void BMP585_DRIVER_Set_DSP_Config(uint8_t I2C_ADDRESS, uint8_t CONFIG);

void BMP585_DRIVER_Get_DSP_IIR(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_DSP_IIR(void);

void BMP585_DRIVER_Set_DSP_IIR(uint8_t I2C_ADDRESS, uint8_t IIR);

void BMP585_DRIVER_Get_OOR_P_LSB(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_OOR_P_LSB(void);

void BMP585_DRIVER_Set_OOR_P_LSB(uint8_t I2C_ADDRESS, uint8_t OOR);

void BMP585_DRIVER_Get_OOR_P_MSB(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_OOR_P_MSB(void);

void BMP585_DRIVER_Set_OOR_P_MSB(uint8_t I2C_ADDRESS, uint8_t OOR);

void BMP585_DRIVER_Get_OOR_Range(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_OOR_Range(void);

void BMP585_DRIVER_Set_OOR_Range(uint8_t I2C_ADDRESS, uint8_t RANGE);

void BMP585_DRIVER_Get_OOR_Config(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_OOR_Config(void);

void BMP585_DRIVER_Set_OOR_Config(uint8_t I2C_ADDRESS, uint8_t CONFIG);

void BMP585_DRIVER_Get_OSR_Config(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_OSR_Config(void);

void BMP585_DRIVER_Set_OSR_Config(uint8_t I2C_ADDRESS, uint8_t CONFIG);

void BMP585_DRIVER_Get_ODR_Config(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_ODR_Config(void);

void BMP585_DRIVER_Set_ODR_Config(uint8_t I2C_ADDRESS, uint8_t CONFIG);

void BMP585_DRIVER_Get_OSR_Eff(uint8_t I2C_ADDRESS);

void BMP585_DRIVER_Store_OSR_Eff(void);

void BMP585_DRIVER_Set_OSR_Eff(uint8_t I2C_ADDRESS, uint8_t EFF);

void BMP585_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _BMP585_DRIVER_H */

/*******************************************************************************
 End of File
 */