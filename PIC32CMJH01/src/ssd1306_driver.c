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

SSD1306_DISPLAY_DATA ssd1306_displayData;

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

void SSD1306_DRIVER_Set_Display_Data(float TEMPERATURE)
{
    ssd1306_displayData.TEMPERATURE = TEMPERATURE;
}

uint8_t FONT[][5] = {
    {0x00, 0x00, 0x00, 0x00, 0x00}, // 32 - ' '
    {0x00, 0x00, 0x5F, 0x00, 0x00}, // 33 - '!'
    {0x00, 0x07, 0x00, 0x07, 0x00}, // 34 - '"'
    {0x14, 0x7F, 0x14, 0x7F, 0x14}, // 35 - '#'
    {0x24, 0x2A, 0x7F, 0x2A, 0x12}, // 36 - '$'
    {0x23, 0x13, 0x08, 0x64, 0x62}, // 37 - '%'
    {0x36, 0x49, 0x55, 0x22, 0x50}, // 38 - '&'
    {0x00, 0x05, 0x03, 0x00, 0x00}, // 39 - '''
    {0x00, 0x1C, 0x22, 0x41, 0x00}, // 40 - '('
    {0x00, 0x41, 0x22, 0x1C, 0x00}, // 41 - ')'
    {0x14, 0x08, 0x3E, 0x08, 0x14}, // 42 - '*'
    {0x08, 0x08, 0x3E, 0x08, 0x08}, // 43 - '+'
    {0x00, 0x50, 0x30, 0x00, 0x00}, // 44 - ','
    {0x08, 0x08, 0x08, 0x08, 0x08}, // 45 - '-'
    {0x00, 0x60, 0x60, 0x00, 0x00}, // 46 - '.'
    {0x20, 0x10, 0x08, 0x04, 0x02}, // 47 - '/'
    {0x3E, 0x51, 0x49, 0x45, 0x3E}, // 48 - '0'
    {0x00, 0x42, 0x7F, 0x40, 0x00}, // 49 - '1'
    {0x42, 0x61, 0x51, 0x49, 0x46}, // 50 - '2'
    {0x21, 0x41, 0x45, 0x4B, 0x31}, // 51 - '3'
    {0x18, 0x14, 0x12, 0x7F, 0x10}, // 52 - '4'
    {0x27, 0x45, 0x45, 0x45, 0x39}, // 53 - '5'
    {0x3C, 0x4A, 0x49, 0x49, 0x30}, // 54 - '6'
    {0x01, 0x71, 0x09, 0x05, 0x03}, // 55 - '7'
    {0x36, 0x49, 0x49, 0x49, 0x36}, // 56 - '8'
    {0x06, 0x49, 0x49, 0x29, 0x1E}, // 57 - '9'
    {0x00, 0x36, 0x36, 0x00, 0x00}, // 58 - ':'
    {0x00, 0x56, 0x36, 0x00, 0x00}, // 59 - ';'
    {0x08, 0x14, 0x22, 0x41, 0x00}, // 60 - '<'
    {0x14, 0x14, 0x14, 0x14, 0x14}, // 61 - '='
    {0x00, 0x41, 0x22, 0x14, 0x08}, // 62 - '>'
    {0x02, 0x01, 0x51, 0x09, 0x06}, // 63 - '?'
    {0x32, 0x49, 0x79, 0x41, 0x3E}, // 64 - '@'
    {0x7E, 0x11, 0x11, 0x11, 0x7E}, // 65 - 'A'
    {0x7F, 0x49, 0x49, 0x49, 0x36}, // 66 - 'B'
    {0x3E, 0x41, 0x41, 0x41, 0x22}, // 67 - 'C'
    {0x7F, 0x41, 0x41, 0x41, 0x3E}, // 68 - 'D'
    {0x7F, 0x49, 0x49, 0x49, 0x41}, // 69 - 'E'
    {0x7F, 0x09, 0x09, 0x09, 0x01}, // 70 - 'F'
    {0x3E, 0x41, 0x49, 0x49, 0x7A}, // 71 - 'G'
    {0x7F, 0x08, 0x08, 0x08, 0x7F}, // 72 - 'H'
    {0x00, 0x41, 0x7F, 0x41, 0x00}, // 73 - 'I'
    {0x20, 0x40, 0x41, 0x3F, 0x01}, // 74 - 'J'
    {0x7F, 0x08, 0x14, 0x22, 0x41}, // 75 - 'K'
    {0x7F, 0x40, 0x40, 0x40, 0x40}, // 76 - 'L'
    {0x7F, 0x02, 0x0C, 0x02, 0x7F}, // 77 - 'M'
    {0x7F, 0x04, 0x08, 0x10, 0x7F}, // 78 - 'N'
    {0x3E, 0x41, 0x41, 0x41, 0x3E}, // 79 - 'O'
    {0x7F, 0x09, 0x09, 0x09, 0x06}, // 80 - 'P'
    {0x3E, 0x41, 0x51, 0x21, 0x5E}, // 81 - 'Q'
    {0x7F, 0x09, 0x19, 0x29, 0x46}, // 82 - 'R'
    {0x46, 0x49, 0x49, 0x49, 0x31}, // 83 - 'S'
    {0x01, 0x01, 0x7F, 0x01, 0x01}, // 84 - 'T'
    {0x3F, 0x40, 0x40, 0x40, 0x3F}, // 85 - 'U'
    {0x1F, 0x20, 0x40, 0x20, 0x1F}, // 86 - 'V'
    {0x7F, 0x20, 0x18, 0x20, 0x7F}, // 87 - 'W'
    {0x63, 0x14, 0x08, 0x14, 0x63}, // 88 - 'X'
    {0x03, 0x04, 0x78, 0x04, 0x03}, // 89 - 'Y'
    {0x61, 0x51, 0x49, 0x45, 0x43}, // 90 - 'Z'
    {0x00, 0x7F, 0x41, 0x41, 0x00}, // 91 - '['
    {0x02, 0x04, 0x08, 0x10, 0x20}, // 92 - '\'
    {0x00, 0x41, 0x41, 0x7F, 0x00}, // 93 - ']'
    {0x04, 0x02, 0x01, 0x02, 0x04}, // 94 - '^'
    {0x80, 0x80, 0x80, 0x80, 0x80}, // 95 - '_'
    {0x00, 0x03, 0x07, 0x00, 0x00}, // 96 - '`'
    {0x20, 0x54, 0x54, 0x54, 0x78}, // 97 - 'a'
    {0x7F, 0x48, 0x44, 0x44, 0x38}, // 98 - 'b'
    {0x38, 0x44, 0x44, 0x44, 0x20}, // 99 - 'c'
    {0x38, 0x44, 0x44, 0x48, 0x7F}, // 100 - 'd'
    {0x38, 0x54, 0x54, 0x54, 0x18}, // 101 - 'e'
    {0x08, 0x7E, 0x09, 0x01, 0x02}, // 102 - 'f'
    {0x0C, 0x52, 0x52, 0x52, 0x3E}, // 103 - 'g'
    {0x7F, 0x08, 0x04, 0x04, 0x78}, // 104 - 'h'
    {0x00, 0x44, 0x7D, 0x40, 0x00}, // 105 - 'i'
    {0x20, 0x40, 0x44, 0x3D, 0x00}, // 106 - 'j'
    {0x7F, 0x10, 0x28, 0x44, 0x00}, // 107 - 'k'
    {0x00, 0x41, 0x7F, 0x40, 0x00}, // 108 - 'l'
    {0x7C, 0x04, 0x18, 0x04, 0x78}, // 109 - 'm'
    {0x7C, 0x08, 0x04, 0x04, 0x78}, // 110 - 'n'
    {0x38, 0x44, 0x44, 0x44, 0x38}, // 111 - 'o'
    {0x7C, 0x14, 0x14, 0x14, 0x08}, // 112 - 'p'
    {0x08, 0x14, 0x14, 0x18, 0x7C}, // 113 - 'q'
    {0x7C, 0x08, 0x04, 0x04, 0x08}, // 114 - 'r'
    {0x48, 0x54, 0x54, 0x54, 0x20}, // 115 - 's'
    {0x04, 0x3F, 0x44, 0x40, 0x20}, // 116 - 't'
    {0x3C, 0x40, 0x40, 0x20, 0x7C}, // 117 - 'u'
    {0x1C, 0x20, 0x40, 0x20, 0x1C}, // 118 - 'v'
    {0x3C, 0x40, 0x30, 0x40, 0x3C}, // 119 - 'w'
    {0x44, 0x28, 0x10, 0x28, 0x44}, // 120 - 'x'
    {0x0C, 0x50, 0x50, 0x50, 0x3C}, // 121 - 'y'
    {0x44, 0x64, 0x54, 0x4C, 0x44}, // 122 - 'z'
    {0x00, 0x08, 0x36, 0x41, 0x00}, // 123 - '{'
    {0x00, 0x00, 0x7F, 0x00, 0x00}, // 124 - '|'
    {0x00, 0x41, 0x36, 0x08, 0x00}, // 125 - '}'
    {0x08, 0x08, 0x2A, 0x1C, 0x08} // 126 - '~'
};

void SSD1306_DRIVER_Write_CMD(uint8_t I2C_ADDRESS, uint8_t CMD)
{
    ssd1306_driverData.I2C_DATA_TRANSMIT[0] = SSD1306_CMD_COMMAND;
    ssd1306_driverData.I2C_DATA_TRANSMIT[1] = CMD;
    DRV_I2C_WriteTransferAdd(ssd1306_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &ssd1306_driverData.I2C_DATA_TRANSMIT, 2, &ssd1306_driverData.I2C_TRANSFER_HANDLE);
}

void SSD1306_DRIVER_Update_Screen(uint8_t I2C_ADDRESS)
{
    ssd1306_driverData.I2C_DATA_TRANSMIT[0] = SSD1306_CMD_DATA_CONTINUE;
    memcpy(&ssd1306_driverData.I2C_DATA_TRANSMIT[1], &ssd1306_driverData.FRAME_BUFFER[ssd1306_driverData.ROW_INDEX * SSD1306_OLED_WIDTH], SSD1306_OLED_WIDTH);
    DRV_I2C_WriteTransferAdd(ssd1306_driverData.I2C_HANDLE, I2C_ADDRESS, (void*) &ssd1306_driverData.I2C_DATA_TRANSMIT, 129, &ssd1306_driverData.I2C_TRANSFER_HANDLE);
}

void SSD1306_DRIVER_Clear_Display(void)
{
    memset(ssd1306_driverData.FRAME_BUFFER, 0x00, sizeof (ssd1306_driverData.FRAME_BUFFER));
    ssd1306_driverData.CURSOL_COLUM = 0;
    ssd1306_driverData.CURSOR_ROW = 0;
}

void SSD1306_DRIVER_Set_Cursor(uint8_t COLUM, uint8_t ROW)
{
    ssd1306_driverData.CURSOL_COLUM = COLUM;
    ssd1306_driverData.CURSOR_ROW = ROW;
}

void SSD1306_DRIVER_Write_Character(char CHARACTER)
{
    if (CHARACTER < 0x20 || CHARACTER > 0x7E) return;

    if (ssd1306_driverData.CURSOL_COLUM + 6 > SSD1306_OLED_WIDTH)
    {
        ssd1306_driverData.CURSOL_COLUM = 0;
        ssd1306_driverData.CURSOR_ROW++;
    }
    if (ssd1306_driverData.CURSOR_ROW >= SSD1306_OLED_HEIGHT / 8) return;

    uint8_t *GLYPH = FONT[CHARACTER - 0x20];
    for (uint8_t i = 0; i < 5; i++)
    {
        ssd1306_driverData.FRAME_BUFFER[ssd1306_driverData.CURSOR_ROW * SSD1306_OLED_WIDTH + ssd1306_driverData.CURSOL_COLUM + i] = GLYPH[i];
    }
    ssd1306_driverData.FRAME_BUFFER[ssd1306_driverData.CURSOR_ROW * SSD1306_OLED_WIDTH + ssd1306_driverData.CURSOL_COLUM + 5] = 0x00;
    ssd1306_driverData.CURSOL_COLUM += 6;
}

void SSD1306_DRIVER_Write_String(char *STRING)
{
    while (*STRING) SSD1306_DRIVER_Write_Character(*STRING++);
}

void SSD1306_DRIVER_Set_Display_Payload(void)
{
    SSD1306_DRIVER_Set_Cursor(0, 0);
    SSD1306_DRIVER_Write_String("---------------------");

    SSD1306_DRIVER_Set_Cursor(0, 4);
    snprintf(ssd1306_driverData.PAYLOAD, sizeof (ssd1306_driverData.PAYLOAD), "Temperature: %.2f  C", ssd1306_displayData.TEMPERATURE);
    SSD1306_DRIVER_Write_String(ssd1306_driverData.PAYLOAD);

    SSD1306_DRIVER_Set_Cursor(0, 7);
    SSD1306_DRIVER_Write_String("---------------------");
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
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_DISPLAY_OFF;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_DISPLAY_OFF:
        {
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_DISPLAY_OFF);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_DISPLAY_OFF_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_DISPLAY_OFF_WAIT_FOR_TRANSFER:
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_SET_DISPLAY_CLOCK_DIV_RATIO);
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], 0x80);
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_SET_MULTIPLEX_RATIO);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_MULTIPLEX_RATIO_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_MULTIPLEX_RATIO_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_MULTIPLEX_RATIO_VALUE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_MULTIPLEX_RATIO_VALUE:
        {
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], 0x3F);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_MULTIPLEX_RATIO_VALUE_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_MULTIPLEX_RATIO_VALUE_WAIT_FOR_TRANSFER:
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_SET_DISPLAY_OFFSET);
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], 0x00);
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_SET_START_LINE);
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_CHARGE_PUMP);
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], 0x14);
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_MEMORY_ADDR_MODE);
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], 0x00);
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_SET_SEGMENT_REMAP);
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_COM_SCAN_DIR_DEC);
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_SET_COM_PINS);
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], 0x12);
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_SET_CONTRAST_CONTROL);
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], 0xCF);
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_SET_PRECHARGE_PERIOD);
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], 0xF1);
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_SET_VCOM_DESELECT);
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], 0x40);
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_DISPLAY_ALL_ON_RESUME);
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
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_NORMAL_DISPLAY);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_NORMAL_DISPLAY_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_NORMAL_DISPLAY_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_DISPLAY_ON;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_SET_DISPLAY_ON:
        {
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_DISPLAY_ON);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_DISPLAY_ON_WAIT_FOR_TRANSFER;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_DISPLAY_ON_WAIT_FOR_TRANSFER:
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
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_CLEAR_DISPLAY;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_CLEAR_DISPLAY:
        {
            SSD1306_DRIVER_Clear_Display();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_SET_DISPLAY_PAYLOAD;
            break;
        }

        case SSD1306_DRIVER_STATE_SET_DISPLAY_PAYLOAD:
        {
            SSD1306_DRIVER_Set_Display_Payload();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_COLUM_ADDRESS;
            break;
        }

        case SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_COLUM_ADDRESS:
        {
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_SET_COLUM_ADDRESS);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_COLUM_ADDRESS_WAIT_FOR_TRANSFER;
            break;
        }
        case SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_COLUM_ADDRESS_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_COLUM_START;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_COLUM_START:
        {
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], 0x00);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_COLUM_START_WAIT_FOR_TRANSFER;
            break;
        }
        case SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_COLUM_START_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_COLUM_END;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_COLUM_END:
        {
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], 0x7F);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_COLUM_END_WAIT_FOR_TRANSFER;
            break;
        }
        case SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_COLUM_END_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_ROW_ADDRESS;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_ROW_ADDRESS:
        {
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], SSD1306_CMD_SET_ROW_ADDRESS);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_ROW_ADDRESS_WAIT_FOR_TRANSFER;
            break;
        }
        case SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_ROW_ADDRESS_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_ROW_START;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_ROW_START:
        {
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], 0x00);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_ROW_START_WAIT_FOR_TRANSFER;
            break;
        }
        case SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_ROW_START_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_ROW_END;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_ROW_END:
        {
            SSD1306_DRIVER_Write_CMD(ssd1306_driverData.I2C_ADDRESS[1], 0x07);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_ROW_END_WAIT_FOR_TRANSFER;
            break;
        }
        case SSD1306_DRIVER_STATE_UPDATE_SCREEN_SET_ROW_END_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_UPDATE_SCREEN_SEND_DATA;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_UPDATE_SCREEN_SEND_DATA:
        {
            SSD1306_DRIVER_Update_Screen(ssd1306_driverData.I2C_ADDRESS[1]);
            TIMER_DRIVER_Start_Bus_TMR();
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_UPDATE_SCREEN_SEND_DATA_WAIT_FOR_TRANSFER;
            break;
        }
        case SSD1306_DRIVER_STATE_UPDATE_SCREEN_SEND_DATA_WAIT_FOR_TRANSFER:
        {
            if (DRV_I2C_TransferStatusGet(ssd1306_driverData.I2C_TRANSFER_HANDLE) == DRV_I2C_TRANSFER_EVENT_COMPLETE)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.ROW_INDEX++;
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_CHECK_ROW_INDEX;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_CHECK_ROW_INDEX:
        {
            if (ssd1306_driverData.ROW_INDEX < 8)
            {
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_UPDATE_SCREEN_SEND_DATA;
            }
            else
            {
                ssd1306_driverData.state = SSD1306_DRIVER_STATE_UPDATE_SCREEN_DONE;
            }
            break;
        }

        case SSD1306_DRIVER_STATE_UPDATE_SCREEN_DONE:
        {
            ssd1306_driverData.ROW_INDEX = 0;
            SSD1306_DRIVER_Set_Task_Completed_Status(true);
            ssd1306_driverData.state = SSD1306_DRIVER_STATE_IDLE;
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