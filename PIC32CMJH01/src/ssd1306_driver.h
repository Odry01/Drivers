/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    ssd1306_driver.h

  Status:
    In development

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "SSD1306_DRIVER_Initialize" and "SSD1306_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "SSD1306_DRIVER_STATES" definition). Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _SSD1306_DRIVER_H
#define _SSD1306_DRIVER_H

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

#define SSD1306_CMD_COMMAND                                 0x00
#define SSD1306_CMD_DATA                                    0xC0
#define SSD1306_CMD_DATA_CONTINUE                           0x40

#define SSD1306_CMD_SET_LOWER_COLUM                         0x00
#define SSD1306_CMD_SET_HIGHER_COLUM                        0x10
#define SSD1306_CMD_MEMORY_ADDR_MODE                        0x20
#define SSD1306_CMD_SET_COLUM_ADDRESS                       0x21
#define SSD1306_CMD_SET_ROW_ADDRESS                         0x22
#define SSD1306_CMD_SET_START_LINE                          0x40
#define SSD1306_CMD_SET_CONTRAST_CONTROL                    0x81
#define SSD1306_CMD_SET_SEGMENT_REMAP                       0xA1
#define SSD1306_CMD_DISPLAY_ALL_ON_RESUME                   0xA4
#define SSD1306_CMD_DISPLAY_ALL_ON                          0xA5    
#define SSD1306_CMD_NORMAL_DISPLAY                          0xA6
#define SSD1306_CMD_INVERT_DISPLAY                          0xA7
#define SSD1306_CMD_SET_MULTIPLEX_RATIO                     0xA8
#define SSD1306_CMD_DISPLAY_OFF                             0xAE
#define SSD1306_CMD_DISPLAY_ON                              0xAF
#define SSD1306_CMD_                                        0xB0
#define SSD1306_CMD_COM_SCAN_DIR_INC                        0xC0
#define SSD1306_CMD_COM_SCAN_DIR_DEC                        0xC8
#define SSD1306_CMD_SET_DISPLAY_OFFSET                      0xD3
#define SSD1306_CMD_SET_DISPLAY_CLOCK_DIV_RATIO             0xD5
#define SSD1306_CMD_SET_PRECHARGE_PERIOD                    0xD9
#define SSD1306_CMD_SET_COM_PINS                            0xDA
#define SSD1306_CMD_SET_VCOM_DESELECT                       0xDB
#define SSD1306_CMD_NOP                                     0xE3
#define SSD1306_CMD_HORIZONTAL_SCROLL_RIGHT                 0x26
#define SSD1306_CMD_HORIZONTAL_SCROLL_LEFT                  0x27
#define SSD1306_CMD_HORIZONTAL_SCROLL_VERTICAL_AND_RIGHT    0x29
#define SSD1306_CMD_HORIZONTAL_SCROLL_VERTICAL_AND_LEFT     0x2A
#define SSD1306_CMD_DEACTIVATE_SCROLL                       0x2E
#define SSD1306_CMD_ACTIVATE_SCROLL                         0x2F
#define SSD1306_CMD_SET_VERTICAL_SCROLL_AREA                0xA3
#define SSD1306_CMD_CHARGE_PUMP                             0x8D

#define SSD1306_OLED_WIDTH                                  128
#define SSD1306_OLED_HEIGHT                                 64
#define SSD1306_PIXEL_COUNT                                 1024
#define SSD1306_DISPLAY_PAYLOAD                             256
#define SSD1306_I2C_RX_BUFFER_SIZE                          256
#define SSD1306_I2C_TX_BUFFER_SIZE                          256

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
    SSD1306_DRIVER_STATE_INIT = 0,
    SSD1306_DRIVER_STATE_CHECK_I2C_HANDLER,
    SSD1306_DRIVER_STATE_SET_DISPLAY_OFF,
    SSD1306_DRIVER_STATE_SET_DISPLAY_OFF_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_DISPLAY_CLOCK,
    SSD1306_DRIVER_STATE_SET_DISPLAY_CLOCK_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_DISPLAY_CLOCK_VALUE,
    SSD1306_DRIVER_STATE_SET_DISPLAY_CLOCK_VALUE_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_MULTIPLEX_RATIO,
    SSD1306_DRIVER_STATE_SET_MULTIPLEX_RATIO_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_MULTIPLEX_RATIO_VALUE,
    SSD1306_DRIVER_STATE_SET_MULTIPLEX_RATIO_VALUE_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_DISPLAY_OFFSET,
    SSD1306_DRIVER_STATE_SET_DISPLAY_OFFSET_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_DISPLAY_OFFSET_VALUE,
    SSD1306_DRIVER_STATE_SET_DISPLAY_OFFSET_VALUE_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_START_LINE,
    SSD1306_DRIVER_STATE_SET_START_LINE_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_CHARGE_PUMP,
    SSD1306_DRIVER_STATE_SET_CHARGE_PUMP_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_CHARGE_PUMP_VALUE,
    SSD1306_DRIVER_STATE_SET_CHARGE_PUMP_VALUE_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_MEMORY_ADDRESS_MODE,
    SSD1306_DRIVER_STATE_SET_MEMORY_ADDRESS_MODE_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_MEMORY_ADDRESS_MODE_VALUE,
    SSD1306_DRIVER_STATE_SET_MEMORY_ADDRESS_MODE_VALUE_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_SEGMENT_REMAP,
    SSD1306_DRIVER_STATE_SET_SEGMENT_REMAP_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_COM_SCAN_DIR_DEC,
    SSD1306_DRIVER_STATE_SET_COM_SCAN_DIR_DEC_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_COM_PINS,
    SSD1306_DRIVER_STATE_SET_COM_PINS_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_COM_PINS_VALUE,
    SSD1306_DRIVER_STATE_SET_COM_PINS_VALUE_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_CONTRAST_CONTROL,
    SSD1306_DRIVER_STATE_SET_CONTRAST_CONTROL_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_CONTRAST_CONTROL_VALUE,
    SSD1306_DRIVER_STATE_SET_CONTRAST_CONTROL_VALUE_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_PRECHARGE_PERIOD,
    SSD1306_DRIVER_STATE_SET_PRECHARGE_PERIOD_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_PRECHARGE_PERIOD_VALUE,
    SSD1306_DRIVER_STATE_SET_PRECHARGE_PERIOD_VALUE_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_VCOM_DESELECT,
    SSD1306_DRIVER_STATE_SET_VCOM_DESELECT_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_VCOM_DESELECT_VALUE,
    SSD1306_DRIVER_STATE_SET_VCOM_DESELECT_VALUE_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_DISPLAY_ALL_ON_RESUME,
    SSD1306_DRIVER_STATE_SET_DISPLAY_ALL_ON_RESUME_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_NORMAL_DISPLAY,
    SSD1306_DRIVER_STATE_SET_NORMAL_DISPLAY_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_SET_DISPLAY_ON,
    SSD1306_DRIVER_STATE_SET_DISPLAY_ON_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_IDLE,
    SSD1306_DRIVER_STATE_CLEAR_DISPLAY,
    SSD1306_DRIVER_STATE_SET_DISPLAY_PAYLOAD,
    SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_COLUM_ADDRESS,
    SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_COLUM_ADDRESS_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_COLUM_START,
    SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_COLUM_START_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_COLUM_END,
    SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_COLUM_END_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_ROW_ADDRESS,
    SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_ROW_ADDRESS_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_ROW_START,
    SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_ROW_START_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_ROW_END,
    SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_ROW_END_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_UPDATE_SCREEN_SEND_DATA,
    SSD1306_DRIVER_STATE_UPDATE_SCREEN_SEND_DATA_WAIT_FOR_TRANSFER,
    SSD1306_DRIVER_STATE_CHECK_ROW_INDEX,
    SSD1306_DRIVER_STATE_UPDATE_SCREEN_DONE,
    SSD1306_DRIVER_STATE_TIMER_EXPIRED,
    SSD1306_DRIVER_STATE_ERROR,
} SSD1306_DRIVER_STATES;

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
    SSD1306_DRIVER_STATES state;

    /* Driver variables */
    DRV_HANDLE I2C_HANDLE;
    DRV_I2C_TRANSFER_HANDLE I2C_TRANSFER_HANDLE;
    volatile bool SSD1306_TASK_START;
    volatile bool SSD1306_TASK_COMPLETED;
    char PAYLOAD[SSD1306_DISPLAY_PAYLOAD];
    uint8_t CURSOL_COLUM;
    uint8_t CURSOR_ROW;
    uint8_t ROW_INDEX;
    uint8_t I2C_ADDRESS[2];
    uint8_t I2C_DATA_RECEIVE[SSD1306_I2C_RX_BUFFER_SIZE];
    uint8_t I2C_DATA_TRANSMIT[SSD1306_I2C_TX_BUFFER_SIZE];
    uint8_t FRAME_BUFFER[SSD1306_PIXEL_COUNT];
} SSD1306_DRIVER_DATA;

typedef struct
{
    float TEMPERATURE;
} SSD1306_DISPLAY_DATA;

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

void SSD1306_DRIVER_Initialize(void);

void SSD1306_DRIVER_Tasks(void);

bool SSD1306_DRIVER_Get_Task_Start_Status(void);

void SSD1306_DRIVER_Set_Task_Start_Status(bool STATUS);

bool SSD1306_DRIVER_Get_Task_Completed_Status(void);

void SSD1306_DRIVER_Set_Task_Completed_Status(bool STATUS);

void SSD1306_DRIVER_Set_I2C_Address(void);

void SSD1306_DRIVER_Set_Display_Data(float TEMPERATURE);

void SSD1306_DRIVER_Write_CMD(uint8_t I2C_ADDRESS, uint8_t CMD);

void SSD1306_DRIVER_Update_Screen(uint8_t I2C_ADDRESS);

void SSD1306_DRIVER_Clear_Display(void);

void SSD1306_DRIVER_Set_Cursor(uint8_t COLUM, uint8_t ROW);

void SSD1306_DRIVER_Write_Character(char CHARACTER);

void SSD1306_DRIVER_Write_String(char *STRING);

void SSD1306_DRIVER_Set_Display_Payload(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _SSD1306_DRIVER_H */

/*******************************************************************************
 End of File
 */