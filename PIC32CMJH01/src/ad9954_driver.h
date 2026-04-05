/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    ad9954_driver.h

  Status:
    In development
 
  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "AD9954_DRIVER_Initialize" and "AD9954_DRIVER_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "AD9954_DRIVER_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

#ifndef _AD9954_DRIVER_H
#define _AD9954_DRIVER_H

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

#define AD9954_CMD_CFR1_ADDRESS     0x00
#define AD9954_CMD_CFR2_ADDRESS     0x01
#define AD9954_CMD_ASF_ADDRESS      0x02
#define AD9954_CMD_ARR_ADDRESS      0x03
#define AD9954_CMD_FTW0_ADDRESS     0x04
#define AD9954_CMD_POW0_ADDRESS     0x05
#define AD9954_CMD_FTW1_ADDRESS     0x06
#define AD9954_CMD_RSCW0_ADDRESS    0x07
#define AD9954_CMD_RSCW1_ADDRESS    0x08
#define AD9954_CMD_RSCW2_ADDRESS    0x08
#define AD9954_CMD_RSCW3_ADDRESS    0x08
#define AD9954_CMD_RAM_ADDRESS      0x0B
#define AD9954_CMD_NLSCW_ADDRESS    0x07
#define AD9954_CMD_PLSCW_ADDRESS    0x08

#define AD9954_RW_BIT               0x80

#define AD9954_SPI_DATA_RX          32
#define AD9954_SPI_DATA_TX          32

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
    AD9954_DRIVER_STATE_INIT = 0,
    AD9954_DRIVER_STATE_CHECK_SPI_HANDLER,
    AD9954_DRIVER_STATE_SET_CFR1,
    AD9954_DRIVER_STATE_SET_CFR1_WAIT_FOR_TRANSFER,
    AD9954_DRIVER_STATE_IDLE,
    AD9954_DRIVER_STATE_SET_FTW0,
    AD9954_DRIVER_STATE_SET_FTW0_WAIT_FOR_TRANSFER,
    AD9954_DRIVER_STATE_SET_FTW1,
    AD9954_DRIVER_STATE_SET_FTW1_WAIT_FOR_TRANSFER,
    AD9954_DRIVER_STATE_SET_NLSCW,
    AD9954_DRIVER_STATE_SET_NLSCW_WAIT_FOR_TRANSFER,
    AD9954_DRIVER_STATE_SET_PLSCW,
    AD9954_DRIVER_STATE_SET_PLSCW_WAIT_FOR_TRANSFER,
    AD9954_DRIVER_STATE_TIMER_EXPIRED,
    AD9954_DRIVER_STATE_ERROR,
} AD9954_DRIVER_STATES;

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
    AD9954_DRIVER_STATES state;

    /* Driver variables */
    DRV_HANDLE SPI_HANDLE;
    DRV_SPI_TRANSFER_HANDLE SPI_TRANSFER_HANDLE;
    volatile bool AD9954_TASK_START;
    volatile bool AD9954_TASK_COMPLETED;
    uint8_t SPI_DATA_RECEIVE[AD9954_SPI_DATA_RX];
    uint8_t SPI_DATA_TRANSMIT[AD9954_SPI_DATA_TX];
} AD9954_DRIVER_DATA;

typedef struct
{
    uint8_t ARR_REGISTER_VALUE;
    uint16_t CFR2_REGISTER_VALUE;
    uint16_t ASF_REGISTER_VALUE;
    uint16_t POW0_REGISTER_VALUE;
    uint32_t CFR1_REGISTER_VALUE;
    uint32_t FTW0_REGISTER_VALUE;
    uint32_t FTW1_REGISTER_VALUE;
    uint32_t RAM_REGISTER_VALUE;
    uint64_t RSCW0_REGISTER_VALUE;
    uint64_t RSCW1_REGISTER_VALUE;
    uint64_t RSCW2_REGISTER_VALUE;
    uint64_t RSCW3_REGISTER_VALUE;
    uint64_t NLSCW_REGISTER_VALUE;
    uint64_t PLSCW_REGISTER_VALUE;
} AD9954_DRIVER_DDS_DATA;

typedef struct
{
    float FREQUENCY;
    float POSITIVE_LINEAR_SWEEP;
    float NEGATIVE_LINEAR_SWEEP;
} AD9954_DRIVER_SETTING_DATA;

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

/**
    Function:
    void AD9954_DRIVER_Initialize(void)

    Summary:
    Performs initialization of driver for console.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void AD9954_DRIVER_Initialize(void);

/**
    Function:
    void AD9954_DRIVER_Tasks(void)

    Summary:
    Executes periodic tasks.

    Parameters:
    None.

    Returns:
    None.

    Remarks:
    None.
 */
void AD9954_DRIVER_Tasks(void);

/**
    Function:
    bool AD9954_DRIVER_Get_Task_Start_Status(void)

    Summary:
    Retrieves the "TASK_START" flag.

    Parameters:
    None.

    Returns:
    @return bool - true if a task has been started otherwise is not

    Remarks:
    None.
 */
bool AD9954_DRIVER_Get_Task_Start_Status(void);

/**
    Function:
    void AD9954_DRIVER_Set_Task_Start_Status(bool STATUS)

    Summary:
    Sets the "TASK_START" flag

    Parameters:
    @param STATUS - desired state of the "TASK_START" flag

    Returns:
    None.

    Remarks:
    None.
 */
void AD9954_DRIVER_Set_Task_Start_Status(bool STATUS);

/**
    Function:
    bool AD9954_DRIVER_Get_Task_Completed_Status(void)

    Summary:
    Retrieves the "TASK_COMPLETED" flag.

    Parameters:
    None.

    Returns:
    @return bool - true if a task has been completed otherwise is not

    Remarks:
    None.
 */
bool AD9954_DRIVER_Get_Task_Completed_Status(void);

/**
    Function:
    void AD9954_DRIVER_Set_Task_Completed_Status(bool STATUS)

    Summary:
    Sets the "TASK_COMPLETED" flag

    Parameters:
    @param STATUS - desired state of the "TASK_COMPLETED" flag

    Returns:
    None.

    Remarks:
    None.
 */
void AD9954_DRIVER_Set_Task_Completed_Status(bool STATUS);

/**
   Function:
   void AD9954_DRIVER_Get_CFR1_Register(void)

   Summary:
   Reads the current value of register CFR1 value.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Get_CFR1_Register(void);

/**
   Function:
   void AD9954_DRIVER_Store_CFR1_Register(void)

   Summary:
   Store the CFR1 register value into variables.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_CFR1_Register(void);

/**
   Function:
   void AD9954_DRIVER_Set_CFR1_Register(uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0)

   Summary:
   Sets the value of register CFR1 value.

   Parameters:
   @param WORD_3 - first byte of CFR1
   @param WORD_2 - second byte of CFR1
   @param WORD_1 - third byte of CFR1
   @param WORD_0 - fourth byte of CFR1

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Set_CFR1_Register(uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0);

/**
   Function:
   void AD9954_DRIVER_Get_CFR2_Register(void)

   Summary:
   Reads the current value of register CFR2 value.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Get_CFR2_Register(void);

/**
   Function:
   void AD9954_DRIVER_Store_CFR2_Register(void)

   Summary:
   Store the CFR2 register value into variables.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_CFR2_Register(void);

/**
   Function:
   void AD9954_DRIVER_Set_CFR2_Register(uint8_t WORD_1, uint8_t WORD_0)

   Summary:
   Sets the value of register CFR1 value.

   Parameters:
   @param WORD_1 - first byte of CFR1
   @param WORD_0 - second byte of CFR1

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Set_CFR2_Register(uint8_t WORD_1, uint8_t WORD_0);

/**
   Function:
   void AD9954_DRIVER_Get_ASF_Register(void)

   Summary:
   Reads the current value of register ASF value.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Get_ASF_Register(void);

/**
   Function:
   void AD9954_DRIVER_Store_ASF_Register(void)

   Summary:
   Store the ASF register value into variables.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_ASF_Register(void);

/**
   Function:
   void AD9954_DRIVER_Set_ASF_Register(uint8_t WORD_1, uint8_t WORD_0)

   Summary:
   Sets the value of register ASF value.

   Parameters:
   @param WORD_1 - first byte of ASF
   @param WORD_0 - second byte of ASF

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Set_ASF_Register(uint8_t WORD_1, uint8_t WORD_0);

/**
   Function:
   void AD9954_DRIVER_Get_ARR_Register(void)

   Summary:
   Reads the current value of register ARR value.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Get_ARR_Register(void);

/**
   Function:
   void AD9954_DRIVER_Store_ARR_Register(void)

   Summary:
   Store the ARR register value into variables.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_ARR_Register(void);

/**
   Function:
   void AD9954_DRIVER_Set_ARR_Register(uint8_t WORD_0)

   Summary:
   Sets the value of register ARR value.

   Parameters:
   @param WORD_0 - byte of ARR

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Set_ARR_Register(uint8_t WORD_0);

/**
   Function:
   void AD9954_DRIVER_Get_FTW0_Register(void)

   Summary:
   Reads the current value of register FTW0 value.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Get_FTW0_Register(void);

/**
   Function:
   void AD9954_DRIVER_Store_FTW0_Register(void)

   Summary:
   Store the FTW0 register value into variables.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_FTW0_Register(void);

/**
   Function:
   void AD9954_DRIVER_Set_FTW0_Register(uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0)

   Summary:
   Sets the value of register FTW0 value.

   Parameters:
   @param WORD_3 - first byte of FTW0
   @param WORD_2 - second byte of FTW0
   @param WORD_1 - third byte of FTW0
   @param WORD_0 - fourth byte of FTW0

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Set_FTW0_Register(uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0);

/**
   Function:
   void AD9954_DRIVER_Get_POW0_Register(void)

   Summary:
   Reads the current value of register POW0 value.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Get_POW0_Register(void);

/**
   Function:
   void AD9954_DRIVER_Store_POW0_Register(void)

   Summary:
   Store the POW0 register value into variables.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_POW0_Register(void);

/**
   Function:
   void AD9954_DRIVER_Set_POW0_Register(uint8_t WORD_1, uint8_t WORD_0)

   Summary:
   Sets the value of register POW0 value.

   Parameters:
   @param WORD_1 - third byte of POW0
   @param WORD_0 - fourth byte of POW0

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Set_POW0_Register(uint8_t WORD_1, uint8_t WORD_0);

/**
   Function:
   void AD9954_DRIVER_Get_FTW1_Register(void)

   Summary:
   Reads the current value of register FTW1 value.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Get_FTW1_Register(void);

/**
   Function:
   void AD9954_DRIVER_Store_FTW1_Register(void)

   Summary:
   Store the FTW1 register value into variables.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_FTW1_Register(void);

/**
   Function:
   void AD9954_DRIVER_Set_FTW1_Register(uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0)

   Summary:
   Sets the value of register FTW1 value.

   Parameters:
   @param WORD_3 - first byte of FTW1
   @param WORD_2 - second byte of FTW1
   @param WORD_1 - third byte of FTW1
   @param WORD_0 - fourth byte of FTW1

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Set_FTW1_Register(uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0);

/**
   Function:
   void AD9954_DRIVER_Get_RSCW0_Register(void)

   Summary:
   Reads the current value of register RSCW0 value.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Get_RSCW0_Register(void);

/**
   Function:
   void AD9954_DRIVER_Store_RSCW0_Register(void)

   Summary:
   Store the RSCW0 register value into variables.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_RSCW0_Register(void);

/**
   Function:
   void AD9954_DRIVER_Set_RSCW0_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0)

   Summary:
   Sets the value of register RSCW0 value.

   Parameters:
   @param WORD_4 - first byte of RSCW0
   @param WORD_3 - second byte of RSCW0
   @param WORD_2 - third byte of RSCW0
   @param WORD_1 - fourth byte of RSCW0
   @param WORD_0 - fifth byte of RSCW0

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Set_RSCW0_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0);

/**
   Function:
   void AD9954_DRIVER_Get_RSCW1_Register(void)

   Summary:
   Reads the current value of register RSCW1 value.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Get_RSCW1_Register(void);

/**
   Function:
   void AD9954_DRIVER_Store_RSCW1_Register(void)

   Summary:
   Store the RSCW1 register value into variables.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_RSCW1_Register(void);

/**
   Function:
   void AD9954_DRIVER_Set_RSCW1_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0)

   Summary:
   Sets the value of register RSCW1 value.

   Parameters:
   @param WORD_4 - first byte of RSCW1
   @param WORD_3 - second byte of RSCW1
   @param WORD_2 - third byte of RSCW1
   @param WORD_1 - fourth byte of RSCW1
   @param WORD_0 - fifth byte of RSCW1

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Set_RSCW1_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0);

/**
   Function:
   void AD9954_DRIVER_Get_RSCW2_Register(void)

   Summary:
   Reads the current value of register RSCW2 value.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Get_RSCW2_Register(void);

/**
   Function:
   void AD9954_DRIVER_Store_RSCW2_Register(void)

   Summary:
   Store the RSCW2 register value into variables.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_RSCW2_Register(void);

/**
   Function:
   void AD9954_DRIVER_Set_RSCW2_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0)

   Summary:
   Sets the value of register RSCW2 value.

   Parameters:
   @param WORD_4 - first byte of RSCW2
   @param WORD_3 - second byte of RSCW2
   @param WORD_2 - third byte of RSCW2
   @param WORD_1 - fourth byte of RSCW2
   @param WORD_0 - fifth byte of RSCW2

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Set_RSCW2_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0);

/**
   Function:
   void AD9954_DRIVER_Get_RSCW3_Register(void)

   Summary:
   Reads the current value of register RSCW3 value.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Get_RSCW3_Register(void);

/**
   Function:
   void AD9954_DRIVER_Store_RSCW3_Register(void)

   Summary:
   Store the RSCW3 register value into variables.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_RSCW3_Register(void);

/**
   Function:
   void AD9954_DRIVER_Set_RSCW3_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0)

   Summary:
   Sets the value of register RSCW3 value.

   Parameters:
   @param WORD_4 - first byte of RSCW3
   @param WORD_3 - second byte of RSCW3
   @param WORD_2 - third byte of RSCW3
   @param WORD_1 - fourth byte of RSCW3
   @param WORD_0 - fifth byte of RSCW3

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Set_RSCW3_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0);

/**
   Function:
   void AD9954_DRIVER_Get_NLSCW_Register(void)

   Summary:
   Reads the current value of register NLSCW value.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Get_NLSCW_Register(void);

/**
   Function:
   void AD9954_DRIVER_Store_NLSCW_Register(void)

   Summary:
   Store the NLSCW register value into variables.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_NLSCW_Register(void);

/**
   Function:
   void AD9954_DRIVER_Set_NLSCW_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0)

   Summary:
   Sets the value of register NLSCW value.

   Parameters:
   @param WORD_4 - first byte of NLSCW
   @param WORD_3 - second byte of NLSCW
   @param WORD_2 - third byte of NLSCW
   @param WORD_1 - fourth byte of NLSCW
   @param WORD_0 - fifth byte of NLSCW

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Set_NLSCW_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0);

/**
   Function:
   void AD9954_DRIVER_Get_PLSCW_Register(void)

   Summary:
   Reads the current value of register PLSCW value.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Get_PLSCW_Register(void);

/**
   Function:
   void AD9954_DRIVER_Store_PLSCW_Register(void)

   Summary:
   Store the PLSCW register value into variables.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_PLSCW_Register(void);

/**
   Function:
   void AD9954_DRIVER_Set_PLSCW_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0)

   Summary:
   Sets the value of register PLSCW value.

   Parameters:
   @param WORD_4 - first byte of RSCW0
   @param WORD_3 - second byte of RSCW0
   @param WORD_2 - third byte of RSCW0
   @param WORD_1 - fourth byte of RSCW0
   @param WORD_0 - fifth byte of RSCW0

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Set_PLSCW_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0);

/**
   Function:
   void AD9954_DRIVER_Set_Frequency(uint32_t FREQUENCY)

   Summary:
   Sets the output frequency to FTW register.

   Parameters:
   @param FREQUENCY - desired output frequency in Hz

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Set_Frequency(uint32_t FREQUENCY);

/**
   Function:
   void AD9954_DRIVER_Set_Linear_Sweep(uint32_t POSITIVE_LINEAR_SWEEP, uint32_t NEGATIVE_LINEAR_SWEEP)

   Summary:
   Programs linear frequency sweep parameters for the DDS.

   Parameters:
   @param POSITIVE_LINEAR_SWEEP - forward sweep rate in Hz/s
   @param NEGATIVE_LINEAR_SWEEP - reverse sweep rate in Hz/s

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Set_Linear_Sweep(uint32_t POSITIVE_LINEAR_SWEEP, uint32_t NEGATIVE_LINEAR_SWEEP);

/**
    Function:
    void AD9954_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE)

    Summary:
    Prints the text to a console.

    Parameters:
    @param CONSOLE_HANDLE - console handle returned by the library

    Returns:
    None.

    Remarks:
    For reading a text use TeraTerm, CoolTerm, etc.
 */
void AD9954_DRIVER_Print_Data(SYS_CONSOLE_HANDLE CONSOLE_HANDLE);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _AD9954_DRIVER_H */

/*******************************************************************************
 End of File
 */