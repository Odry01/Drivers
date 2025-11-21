/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    ssd1306_driver.c

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

#include "ssd1306_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

SSD1306_DRIVER_DATA ssd1306_driverData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

bool SSD1306_DRIVER_Get_Task_Start_Status(void)
{
    return (ssd1306_driverData.SSD1306_TASK_START);
}

void SSD1306_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    ssd1306_driverData.SSD1306_TASK_START = STATUS;
}

bool SSD1306_DRIVER_Get_Task_Completed_Status(void)
{
    return (ssd1306_driverData.SSD1306_TASK_COMPLETED);
}

void SSD1306_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    ssd1306_driverData.SSD1306_TASK_COMPLETED = STATUS;
}

void SSD1306_DRIVER_Set_I2C_Address(void)
{
    ssd1306_driverData.I2C_ADDRESS[0] = 0x3C;
    ssd1306_driverData.I2C_ADDRESS[1] = 0x3D;
}

char ASCII[][5] = {
    {0x00, 0x00, 0x00, 0x00, 0x00} // 20  
    ,
    {0x00, 0x00, 0x5f, 0x00, 0x00} // 21 !
    ,
    {0x00, 0x07, 0x00, 0x07, 0x00} // 22 "
    ,
    {0x14, 0x7f, 0x14, 0x7f, 0x14} // 23 #
    ,
    {0x24, 0x2a, 0x7f, 0x2a, 0x12} // 24 $
    ,
    {0x23, 0x13, 0x08, 0x64, 0x62} // 25 %
    ,
    {0x36, 0x49, 0x55, 0x22, 0x50} // 26 &
    ,
    {0x00, 0x05, 0x03, 0x00, 0x00} // 27 '
    ,
    {0x00, 0x1c, 0x22, 0x41, 0x00} // 28 (
    ,
    {0x00, 0x41, 0x22, 0x1c, 0x00} // 29 )
    ,
    {0x14, 0x08, 0x3e, 0x08, 0x14} // 2a *
    ,
    {0x08, 0x08, 0x3e, 0x08, 0x08} // 2b +
    ,
    {0x00, 0x50, 0x30, 0x00, 0x00} // 2c ,
    ,
    {0x08, 0x08, 0x08, 0x08, 0x08} // 2d -
    ,
    {0x00, 0x60, 0x60, 0x00, 0x00} // 2e .
    ,
    {0x20, 0x10, 0x08, 0x04, 0x02} // 2f /
    ,
    {0x3e, 0x51, 0x49, 0x45, 0x3e} // 30 0
    ,
    {0x00, 0x42, 0x7f, 0x40, 0x00} // 31 1
    ,
    {0x42, 0x61, 0x51, 0x49, 0x46} // 32 2
    ,
    {0x21, 0x41, 0x45, 0x4b, 0x31} // 33 3
    ,
    {0x18, 0x14, 0x12, 0x7f, 0x10} // 34 4
    ,
    {0x27, 0x45, 0x45, 0x45, 0x39} // 35 5
    ,
    {0x3c, 0x4a, 0x49, 0x49, 0x30} // 36 6
    ,
    {0x01, 0x71, 0x09, 0x05, 0x03} // 37 7
    ,
    {0x36, 0x49, 0x49, 0x49, 0x36} // 38 8
    ,
    {0x06, 0x49, 0x49, 0x29, 0x1e} // 39 9
    ,
    {0x00, 0x36, 0x36, 0x00, 0x00} // 3a :
    ,
    {0x00, 0x56, 0x36, 0x00, 0x00} // 3b ;
    ,
    {0x08, 0x14, 0x22, 0x41, 0x00} // 3c <
    ,
    {0x14, 0x14, 0x14, 0x14, 0x14} // 3d =
    ,
    {0x00, 0x41, 0x22, 0x14, 0x08} // 3e >
    ,
    {0x02, 0x01, 0x51, 0x09, 0x06} // 3f ?
    ,
    {0x32, 0x49, 0x79, 0x41, 0x3e} // 40 @
    ,
    {0x7e, 0x11, 0x11, 0x11, 0x7e} // 41 A
    ,
    {0x7f, 0x49, 0x49, 0x49, 0x36} // 42 B
    ,
    {0x3e, 0x41, 0x41, 0x41, 0x22} // 43 C
    ,
    {0x7f, 0x41, 0x41, 0x22, 0x1c} // 44 D
    ,
    {0x7f, 0x49, 0x49, 0x49, 0x41} // 45 E
    ,
    {0x7f, 0x09, 0x09, 0x09, 0x01} // 46 F
    ,
    {0x3e, 0x41, 0x49, 0x49, 0x7a} // 47 G
    ,
    {0x7f, 0x08, 0x08, 0x08, 0x7f} // 48 H
    ,
    {0x00, 0x41, 0x7f, 0x41, 0x00} // 49 I
    ,
    {0x20, 0x40, 0x41, 0x3f, 0x01} // 4a J
    ,
    {0x7f, 0x08, 0x14, 0x22, 0x41} // 4b K
    ,
    {0x7f, 0x40, 0x40, 0x40, 0x40} // 4c L
    ,
    {0x7f, 0x02, 0x0c, 0x02, 0x7f} // 4d M
    ,
    {0x7f, 0x04, 0x08, 0x10, 0x7f} // 4e N
    ,
    {0x3e, 0x41, 0x41, 0x41, 0x3e} // 4f O
    ,
    {0x7f, 0x09, 0x09, 0x09, 0x06} // 50 P
    ,
    {0x3e, 0x41, 0x51, 0x21, 0x5e} // 51 Q
    ,
    {0x7f, 0x09, 0x19, 0x29, 0x46} // 52 R
    ,
    {0x46, 0x49, 0x49, 0x49, 0x31} // 53 S
    ,
    {0x01, 0x01, 0x7f, 0x01, 0x01} // 54 T
    ,
    {0x3f, 0x40, 0x40, 0x40, 0x3f} // 55 U
    ,
    {0x1f, 0x20, 0x40, 0x20, 0x1f} // 56 V
    ,
    {0x3f, 0x40, 0x38, 0x40, 0x3f} // 57 W
    ,
    {0x63, 0x14, 0x08, 0x14, 0x63} // 58 X
    ,
    {0x07, 0x08, 0x70, 0x08, 0x07} // 59 Y
    ,
    {0x61, 0x51, 0x49, 0x45, 0x43} // 5a Z
    ,
    {0x00, 0x7f, 0x41, 0x41, 0x00} // 5b [
    ,
    {0x02, 0x04, 0x08, 0x10, 0x20} // 5c  
    ,
    {0x00, 0x41, 0x41, 0x7f, 0x00} // 5d ]
    ,
    {0x04, 0x02, 0x01, 0x02, 0x04} // 5e ^
    ,
    {0x40, 0x40, 0x40, 0x40, 0x40} // 5f _
    ,
    {0x00, 0x01, 0x02, 0x04, 0x00} // 60 `
    ,
    {0x20, 0x54, 0x54, 0x54, 0x78} // 61 a
    ,
    {0x7f, 0x48, 0x44, 0x44, 0x38} // 62 b
    ,
    {0x38, 0x44, 0x44, 0x44, 0x20} // 63 c
    ,
    {0x38, 0x44, 0x44, 0x48, 0x7f} // 64 d
    ,
    {0x38, 0x54, 0x54, 0x54, 0x18} // 65 e
    ,
    {0x08, 0x7e, 0x09, 0x01, 0x02} // 66 f
    ,
    {0x0c, 0x52, 0x52, 0x52, 0x3e} // 67 g
    ,
    {0x7f, 0x08, 0x04, 0x04, 0x78} // 68 h
    ,
    {0x00, 0x44, 0x7d, 0x40, 0x00} // 69 i
    ,
    {0x20, 0x40, 0x44, 0x3d, 0x00} // 6a j 
    ,
    {0x7f, 0x10, 0x28, 0x44, 0x00} // 6b k
    ,
    {0x00, 0x41, 0x7f, 0x40, 0x00} // 6c l
    ,
    {0x7c, 0x04, 0x18, 0x04, 0x78} // 6d m
    ,
    {0x7c, 0x08, 0x04, 0x04, 0x78} // 6e n
    ,
    {0x38, 0x44, 0x44, 0x44, 0x38} // 6f o
    ,
    {0x7c, 0x14, 0x14, 0x14, 0x08} // 70 p
    ,
    {0x08, 0x14, 0x14, 0x18, 0x7c} // 71 q
    ,
    {0x7c, 0x08, 0x04, 0x04, 0x08} // 72 r
    ,
    {0x48, 0x54, 0x54, 0x54, 0x20} // 73 s
    ,
    {0x04, 0x3f, 0x44, 0x40, 0x20} // 74 t
    ,
    {0x3c, 0x40, 0x40, 0x20, 0x7c} // 75 u
    ,
    {0x1c, 0x20, 0x40, 0x20, 0x1c} // 76 v
    ,
    {0x3c, 0x40, 0x30, 0x40, 0x3c} // 77 w
    ,
    {0x44, 0x28, 0x10, 0x28, 0x44} // 78 x
    ,
    {0x0c, 0x50, 0x50, 0x50, 0x3c} // 79 y
    ,
    {0x44, 0x64, 0x54, 0x4c, 0x44} // 7a z
    ,
    {0x00, 0x08, 0x36, 0x41, 0x00} // 7b {
    ,
    {0x00, 0x00, 0x7f, 0x00, 0x00} // 7c |
    ,
    {0x00, 0x41, 0x36, 0x08, 0x00} // 7d }
    ,
    {0x10, 0x08, 0x08, 0x10, 0x08} // 7e ?
    ,
    {0x78, 0x46, 0x41, 0x46, 0x78} // 7f ?
};

void SSD1306_DRIVER_Send_Command(uint8_t I2C_ADDRESS, uint8_t CMD)
{
    ssd1306_driverData.I2C_DATA_TRANSMIT[0] = SSD1306_COMMAND;
    ssd1306_driverData.I2C_DATA_TRANSMIT[1] = CMD;
    DRV_I2C_WriteTransferAdd(ssd1306_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &ssd1306_driverData.I2C_DATA_TRANSMIT, 2, &ssd1306_driverData.I2C_TRANSFER_HANDLE);
    SYSTICK_DelayMs(100);
}

void SSD1306_DRIVER_Send_Data(uint8_t I2C_ADDRESS, uint8_t DATA)
{
    ssd1306_driverData.I2C_DATA_TRANSMIT[0] = SSD1306_DATA_CONTINUE;
    ssd1306_driverData.I2C_DATA_TRANSMIT[1] = DATA;
    DRV_I2C_WriteTransferAdd(ssd1306_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &ssd1306_driverData.I2C_DATA_TRANSMIT, 2, &ssd1306_driverData.I2C_TRANSFER_HANDLE);
    SYSTICK_DelayMs(100);
}

void SSD1306_DRIVER_Write_String(uint8_t I2C_ADDRESS, char *CHARACTERS)
{
    while (*CHARACTERS) SSD1306_DRIVER_Write_Character(I2C_ADDRESS, *CHARACTERS++);
}

void SSD1306_DRIVER_Write_Character(uint8_t I2C_ADDRESS, char CHARACTER)
{
    for (int i = 0; i < 5; i++) SSD1306_DRIVER_Send_Data(I2C_ADDRESS, (ASCII[CHARACTER - 0x20][i]));
    SSD1306_DRIVER_Send_Data(I2C_ADDRESS, 0x00);
}

void SSD1306_DRIVER_Clear_Display(uint8_t I2C_ADDRESS)
{
    SSD1306_DRIVER_Select_Page(I2C_ADDRESS, 0);

    for (uint8_t i = 0; i < SSD1306_CLEAR_SIZE; i++)
    {
        SSD1306_DRIVER_Send_Data(I2C_ADDRESS, 0x00);
    }
}

void SSD1306_DRIVER_Clear_Line(uint8_t I2C_ADDRESS, uint8_t PAGE_NUMBER)
{
    SSD1306_DRIVER_Select_Page(I2C_ADDRESS, PAGE_NUMBER);
    // Clear line of 128 pixels of current page
    for (uint8_t i = 0; i < 128; i++)
    {
        SSD1306_DRIVER_Send_Data(I2C_ADDRESS, 0x00);
    }
}

// Function to select [page] i.e. row or line number
// 128* 64 has page 0-7
// Passed page num / byte
// page 0   8 
// page 1   16
// page 2   24
// page 3   32
// page 4   40
// page 5   48
// page 6   56
// page 7   64

void SSD1306_DRIVER_Select_Page(uint8_t I2C_ADDRESS, uint8_t PAGE_NUMBER)
{
    uint8_t RESULT = 0xB0 | PAGE_NUMBER;
    SSD1306_DRIVER_Send_Command(I2C_ADDRESS, RESULT);
    SSD1306_DRIVER_Send_Command(I2C_ADDRESS, SSD1306_CMD_SET_LOWER_COLUMN);
    SSD1306_DRIVER_Send_Command(I2C_ADDRESS, SSD1306_CMD_SET_HIGHER_COLUMN);
}

void SSD1306_DrawBitmap(uint8_t I2C_ADDRESS, uint8_t* bitmap)
{
    uint16_t byteIndex = 0;
    for (uint8_t row = 0; row < 8; row++)
    {
        for (uint8_t col = 0; col < 128; col++)
        {
            SSD1306_DRIVER_Send_Data(I2C_ADDRESS, bitmap[byteIndex]);

            byteIndex++;
        }
    }

    SSD1306_DRIVER_Send_Data(I2C_ADDRESS, 0x00);
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void SSD1306_DRIVER_Initialize(void)
{
    ssd1306_driverData.state = SSD1306_DRIVER_STATE_INIT;
    ssd1306_driverData.I2C_HANDLE = DRV_HANDLE_INVALID;
    ssd1306_driverData.I2C_TRANSFER_HANDLE = DRV_I2C_TRANSFER_HANDLE_INVALID;
}

void SSD1306_DRIVER_Tasks(void)
{
    switch (ssd1306_driverData.state)
    {
        case SSD1306_DRIVER_STATE_INIT:
        {
            SSD1306_DRIVER_Set_I2C_Address();
            ssd1306_driverData.I2C_HANDLE = DRV_I2C_Open(DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE);
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_CHECK_I2C_HANDLER;
            break;
        }

        case SSD1306_DRIVER_STATE_CHECK_I2C_HANDLER:
        {
            if (ssd1306_driverData.I2C_HANDLE == DRV_HANDLE_INVALID)
            {
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_ERROR;
            }
            else
            {
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_DISPLAY_OFF;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_DISPLAY_OFF:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_DISPLAY_OFF);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_DISPLAY_OFF_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_DISPLAY_OFF_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_DISPLAY_CLOCK;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_DISPLAY_CLOCK:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_SET_DISPLAY_CLOCK_DIV_RATIO);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_DISPLAY_CLOCK_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_DISPLAY_CLOCK_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_DISPLAY_CLOCK_VALUE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_DISPLAY_CLOCK_VALUE:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], 0x80);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_DISPLAY_CLOCK_VALUE_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_DISPLAY_CLOCK_VALUE_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_MULTIPLEX_RATIO;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_MULTIPLEX_RATIO:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_SET_MULTIPLEX_RATIO);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_MULTIPLEX_RATIO_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_MULTIPLEX_RATIO_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_LCD_HEIGHT;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_LCD_HEIGHT:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_LCD_HEIGHT - 1);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_LCD_HEIGHT_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_LCD_HEIGHT_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_DISPLAY_OFFSET;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_DISPLAY_OFFSET:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_SET_DISPLAY_OFFSET);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_DISPLAY_OFFSET_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_DISPLAY_OFFSET_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_DISPLAY_OFFSET_VALUE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_DISPLAY_OFFSET_VALUE:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], 0x00);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_DISPLAY_OFFSET_VALUE_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_DISPLAY_OFFSET_VALUE_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_START_LINE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_START_LINE:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_SET_START_LINE | 0x00);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_START_LINE_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_START_LINE_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_CHARGE_PUMP;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_CHARGE_PUMP:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_CHARGE_PUMP);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_CHARGE_PUMP_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_CHARGE_PUMP_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_CHARGE_PUMP_VALUE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_CHARGE_PUMP_VALUE:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], 0x14);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_CHARGE_PUMP_VALUE_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_CHARGE_PUMP_VALUE_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_MEMORY_ADDRESS_MODE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_MEMORY_ADDRESS_MODE:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_MEMORY_ADDR_MODE);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_MEMORY_ADDRESS_MODE_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_MEMORY_ADDRESS_MODE_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_MEMORY_ADDRESS_MODE_VALUE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_MEMORY_ADDRESS_MODE_VALUE:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], 0x00);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_MEMORY_ADDRESS_MODE_VALUE_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_MEMORY_ADDRESS_MODE_VALUE_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_SEGMENT_REMAP;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_SEGMENT_REMAP:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_SET_SEGMENT_REMAP | 0x1);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_SEGMENT_REMAP_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_SEGMENT_REMAP_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_COM_SCAN_DIR_DEC;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_COM_SCAN_DIR_DEC:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_COM_SCAN_DIR_DEC);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_COM_SCAN_DIR_DEC_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_COM_SCAN_DIR_DEC_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_COM_PINS;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_COM_PINS:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_SET_COM_PINS);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_COM_PINS_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_COM_PINS_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_COM_PINS_VALUE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_COM_PINS_VALUE:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], 0x2);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_COM_PINS_VALUE_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_COM_PINS_VALUE_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_CONTRAST_CONTROL;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_CONTRAST_CONTROL:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_SET_CONTRAST_CONTROL);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_CONTRAST_CONTROL_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_CONTRAST_CONTROL_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_CONTRAST_CONTROL_VALUE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_CONTRAST_CONTROL_VALUE:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], 0x8F);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_CONTRAST_CONTROL_VALUE_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_CONTRAST_CONTROL_VALUE_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_PRECHARGE_PERIOD;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_PRECHARGE_PERIOD:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_SET_PRECHARGE_PERIOD);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_PRECHARGE_PERIOD_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_PRECHARGE_PERIOD_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_PRECHARGE_PERIOD_VALUE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_PRECHARGE_PERIOD_VALUE:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], 0xF1);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_PRECHARGE_PERIOD_VALUE_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_PRECHARGE_PERIOD_VALUE_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_VCOM_DESELECT;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_VCOM_DESELECT:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_SET_VCOM_DESELECT);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_VCOM_DESELECT_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_VCOM_DESELECT_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_VCOM_DESELECT_VALUE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_VCOM_DESELECT_VALUE:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], 0x40);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_VCOM_DESELECT_VALUE_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_VCOM_DESELECT_VALUE_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_DISPLAY_ALL_ON_RESUME;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_DISPLAY_ALL_ON_RESUME:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_DISPLAY_ALL_ON_RESUME);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_DISPLAY_ALL_ON_RESUME_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_DISPLAY_ALL_ON_RESUME_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_NORMAL_DISPLAY;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_NORMAL_DISPLAY:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_NORMAL_DISPLAY);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_NORMAL_DISPLAY_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_NORMAL_DISPLAY_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_DEACTIVATE_SCROLL;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_DEACTIVATE_SCROLL:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_DEACTIVATE_SCROLL);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_DEACTIVATE_SCROLL_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_DEACTIVATE_SCROLL_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_DISPLAY_ON;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_DISPLAY_ON:
        {
            SSD1306_DRIVER_Send_Command(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_DISPLAY_ON);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_DISPLAY_ON_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_DISPLAY_ON_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_PRINT_TEXT;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_PRINT_TEXT:
        {
            SSD1306_DRIVER_Write_String(ssd1306_driverData.I2C_ADDRESS[1], "Humidity: 50 %");
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_PRINT_TEXT_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_PRINT_TEXT_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_IDLE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_IDLE:
        {
            if (SSD1306_DRIVER_Get_Task_Start_Status() == true)
            {
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_IDLE;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_TIMER_EXPIRED:
        {
            DRV_I2C_Close(ssd1306_driverData.I2C_HANDLE);
            SSD1306_DRIVER_Set_Task_Completed_Status(true);
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_IDLE;
            break;
        }

        case SSD1306_DRIVER_STATE_ERROR:
        {
            DRV_I2C_Close(ssd1306_driverData.I2C_HANDLE);
            SSD1306_DRIVER_Set_Task_Completed_Status(true);
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_IDLE;
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