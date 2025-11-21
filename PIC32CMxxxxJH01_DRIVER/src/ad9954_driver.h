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
    Initializes the AD9954 driver module.

    Description:
    This routine performs all one‑time setup required for communicating with an AD9954 DDS device.  
    It configures the SPI interface, initializes internal data structures, and clears any pending status flags so that
    AD9954_DRIVER_Tasks() can run correctly.

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
    Main task routine for the AD9954 driver.

    Description:
    This function contains the state‑machine that drives the AD9954 device.  
    It periodically checks the status flags, issues register writes/reads, and handles any errors that arise
    while keeping the DDS in a known good state.

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
    Retrieves the current “task start” flag.

    Description:
    Indicates whether a new DDS configuration task has been requested.  
    The application sets this flag via AD9954_DRIVER_Set_Task_Start_Status(true) and clears it when processing is finished.

    Parameters:
    None.

    Returns:
    @return bool – `true` if a task is pending, otherwise `false`.

    Remarks:
    None.
 */
bool AD9954_DRIVER_Get_Task_Start_Status(void);

/**
    Function:
    void AD9954_DRIVER_Set_Task_Start_Status(bool STATUS)

    Summary:
    Sets the “task start” flag.

    Description:
    Allows the application to signal that a new DDS configuration should begin.  
    The driver will act on this flag during its next call to AD9954_DRIVER_Tasks().

    Parameters:
    @param bool STATUS – Desired state of the task‑start flag (`true` = pending, `false` = cleared).

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
    Retrieves the current “task completed” flag.

    Description:
    Indicates whether the most recent DDS configuration task has finished successfully.  
    The driver sets this flag when all register writes have been confirmed.

    Parameters:
    None.

    Returns:
    @return bool – `true` if the last task is complete, otherwise `false`.

    Remarks:
    None.
 */
bool AD9954_DRIVER_Get_Task_Completed_Status(void);

/**
    Function:
    void AD9954_DRIVER_Set_Task_Completed_Status(bool STATUS)

    Summary:
    Sets the “task completed” flag.

    Description:
    Allows the driver to mark a configuration operation as finished.  
    The application may clear this flag when it is ready for another task.

    Parameters:
    @param bool STATUS – Desired state of the task‑completed flag (`true` = complete, `false` = not yet).

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
    Reads the CFR1 register from the DDS into internal storage.

    Description:
    The routine issues an SPI read of the 32‑bit Control Function Register 1 (CFR1) and copies the result
    into a local variable for later use by the driver or application.

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
    Writes the locally stored CFR1 value back to the DDS.

    Description:
    After a configuration routine has updated the internal CFR1 copy, this function sends it over SPI
    to program the hardware register.

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
    Directly programs the CFR1 register from four bytes.

    Description:
    Convenience routine that assembles a 32‑bit value from four 8‑bit words and writes it to the
    DDS.  The byte order follows the AD9954 documentation (WORD_3 = MSB).

    Parameters:
    @param uint8_t WORD_3 – Most significant byte of CFR1.
    @param uint8_t WORD_2 – Second most significant byte.
    @param uint8_t WORD_1 – Third byte.
    @param uint8_t WORD_0 – Least significant byte.

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
    Reads the CFR2 register from the DDS into internal storage.

    Description:
    The routine issues an SPI read of the 16‑bit Control Function Register 2 (CFR2) and copies the
    result into a local variable for later use.

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
    Writes the locally stored CFR2 value back to the DDS.

    Description:
    After updating the internal CFR2 copy, this function writes it over SPI to program the hardware register.

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
    void AD9954_DRIVER_Set_CFR2_Register(uint8_t WORD_0, uint8_t WORD_1)

    Summary:
    Directly programs the CFR2 register from two bytes.

    Description:
    Convenience routine that assembles a 16‑bit value from two 8‑bit words and writes it to the DDS.
    WORD_1 is the most significant byte.

    Parameters:
    @param uint8_t WORD_0 – Least significant byte of CFR2.
    @param uint8_t WORD_1 – Most significant byte of CFR2.

    Returns:
    None.

    Remarks:
    None.
 */
void AD9954_DRIVER_Set_CFR2_Register(uint8_t WORD_0, uint8_t WORD_1);

/**
    Function:
    void AD9954_DRIVER_Get_ASF_Register(void)

    Summary:
    Reads the ASF register from the DDS into internal storage.

    Description:
    The routine reads the 16‑bit Amplitude Scaling Factor (ASF) register via SPI and stores it locally.

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
    Writes the locally stored ASF value back to the DDS.

    Description:
    After a configuration routine has updated the internal ASF copy, this function sends it over SPI
    to program the hardware register.

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
    void AD9954_DRIVER_Set_ASF_Register(uint8_t WORD_0, uint8_t WORD_1)

    Summary:
    Directly programs the ASF register from two bytes.

    Description:
    Convenience routine that assembles a 16‑bit value from two 8‑bit words and writes it to the DDS.
    WORD_1 is the most significant byte.

    Parameters:
    @param uint8_t WORD_0 – Least significant byte of ASF.
    @param uint8_t WORD_1 – Most significant byte of ASF.

    Returns:
    None.

    Remarks:
    None.
 */
void AD9954_DRIVER_Set_ASF_Register(uint8_t WORD_0, uint8_t WORD_1);

/**
    Function:
    void AD9954_DRIVER_Get_ARR_Register(void)

    Summary:
    Reads the ARR register from the DDS into internal storage.

    Description:
    The routine issues an SPI read of the 8‑bit Amplitude Reference Register (ARR) and copies it locally.

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
    Writes the locally stored ARR value back to the DDS.

    Description:
    After updating the internal ARR copy, this function writes it over SPI to program the hardware register.

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
    Directly programs the ARR register from a single byte.

    Description:
    Convenience routine that writes an 8‑bit value to the DDS.  WORD_0 is the full register content.

    Parameters:
    @param uint8_t WORD_0 – Value for the ARR register (0‑255).

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
    Reads the FTW0 register from the DDS into internal storage.

    Description:
    The routine reads the 32‑bit Frequency Tuning Word 0 (FTW0) via SPI and stores it locally for later use.

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
    Writes the locally stored FTW0 value back to the DDS.

    Description:
    After updating the internal FTW0 copy, this function writes it over SPI to program the hardware register.

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
    Directly programs the FTW0 register from four bytes.

    Description:
    Convenience routine that assembles a 32‑bit value from four 8‑bit words and writes it to the DDS.
    WORD_3 is the most significant byte.

    Parameters:
    @param uint8_t WORD_3 – Most significant byte of FTW0.
    @param uint8_t WORD_2 – Second MSB.
    @param uint8_t WORD_1 – Third byte.
    @param uint8_t WORD_0 – Least significant byte.

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
    Reads the POW0 register from the DDS into internal storage.

    Description:
    The routine reads the 16‑bit Power Output Word 0 (POW0) via SPI and stores it locally.

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
    Writes the locally stored POW0 value back to the DDS.

    Description:
    After updating the internal POW0 copy, this function writes it over SPI to program the hardware register.

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
    void AD9954_DRIVER_Set_POW0_Register(uint8_t WORD_0, uint8_t WORD_1)

    Summary:
    Directly programs the POW0 register from two bytes.

    Description:
    Convenience routine that assembles a 16‑bit value from two 8‑bit words and writes it to the DDS.
    WORD_1 is the most significant byte.

    Parameters:
    @param uint8_t WORD_0 – Least significant byte of POW0.
    @param uint8_t WORD_1 – Most significant byte of POW0.

    Returns:
    None.

    Remarks:
    None.
 */
void AD9954_DRIVER_Set_POW0_Register(uint8_t WORD_0, uint8_t WORD_1);

/**
    Function:
    void AD9954_DRIVER_Get_FTW1_Register(void)

    Summary:
    Reads the FTW1 register from the DDS into internal storage.

    Description:
    The routine reads the 32‑bit Frequency Tuning Word 1 (FTW1) via SPI and stores it locally for later use.

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
    Writes the locally stored FTW1 value back to the DDS.

    Description:
    After updating the internal FTW1 copy, this function writes it over SPI to program the hardware register.

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
    Directly programs the FTW1 register from four bytes.

    Description:
    Convenience routine that assembles a 32‑bit value from four 8‑bit words and writes it to the DDS.
    WORD_3 is the most significant byte.

    Parameters:
    @param uint8_t WORD_3 – Most significant byte of FTW1.
    @param uint8_t WORD_2 – Second MSB.
    @param uint8_t WORD_1 – Third byte.
    @param uint8_t WORD_0 – Least significant byte.

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
    Reads the RSCW0 register from the DDS into internal storage.

    Description:
    The routine reads the 40‑bit Rate/Scale Control Word 0 (RSCW0) via SPI and stores it locally.

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
    Writes the locally stored RSCW0 value back to the DDS.

    Description:
    After updating the internal RSCW0 copy, this function writes it over SPI to program the hardware register.

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
    Directly programs the RSCW0 register from five bytes.

    Description:
    Convenience routine that assembles a 40‑bit value from five 8‑bit words and writes it to the DDS.
    WORD_4 is the most significant byte.

    Parameters:
    @param uint8_t WORD_4 – Most significant byte of RSCW0.
    @param uint8_t WORD_3 – Second MSB.
    @param uint8_t WORD_2 – Middle byte.
    @param uint8_t WORD_1 – Second LSB.
    @param uint8_t WORD_0 – Least significant byte.

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
    Reads the RSCW1 register from the DDS into internal storage.

    Description:
    The routine reads the 40‑bit Rate/Scale Control Word 1 (RSCW1) via SPI and stores it locally.

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
    Writes the locally stored RSCW1 value back to the DDS.

    Description:
    After updating the internal RSCW1 copy, this function writes it over SPI to program the hardware register.

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
    Directly programs the RSCW1 register from five bytes.

    Description:
    Convenience routine that assembles a 40‑bit value from five 8‑bit words and writes it to the DDS.
    WORD_4 is the most significant byte.

    Parameters:
    @param uint8_t WORD_4 – Most significant byte of RSCW1.
    @param uint8_t WORD_3 – Second MSB.
    @param uint8_t WORD_2 – Middle byte.
    @param uint8_t WORD_1 – Second LSB.
    @param uint8_t WORD_0 – Least significant byte.

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
    Reads the RSCW2 register from the DDS into internal storage.

    Description:
    The routine reads the 40‑bit Rate/Scale Control Word 2 (RSCW2) via SPI and stores it locally.

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
    Writes the locally stored RSCW2 value back to the DDS.

    Description:
    After updating the internal RSCW2 copy, this function writes it over SPI to program the hardware register.

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
    Directly programs the RSCW2 register from five bytes.

    Description:
    Convenience routine that assembles a 40‑bit value from five 8‑bit words and writes it to the DDS.
    WORD_4 is the most significant byte.

    Parameters:
    @param uint8_t WORD_4 – Most significant byte of RSCW2.
    @param uint8_t WORD_3 – Second MSB.
    @param uint8_t WORD_2 – Middle byte.
    @param uint8_t WORD_1 – Second LSB.
    @param uint8_t WORD_0 – Least significant byte.

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
    Reads the RSCW3 register from the DDS into internal storage.

    Description:
    The routine reads the 40‑bit Rate/Scale Control Word 3 (RSCW3) via SPI and stores it locally.

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
    Writes the locally stored RSCW3 value back to the DDS.

    Description:
    After updating the internal RSCW3 copy, this function writes it over SPI to program the hardware register.

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
    Directly programs the RSCW3 register from five bytes.

    Description:
    Convenience routine that assembles a 40‑bit value from five 8‑byte words and writes it to the DDS.
    WORD_4 is the most significant byte.

    Parameters:
    @param uint8_t WORD_4 – Most significant byte of RSCW3.
    @param uint8_t WORD_3 – Second MSB.
    @param uint8_t WORD_2 – Middle byte.
    @param uint8_t WORD_1 – Second LSB.
    @param uint8_t WORD_0 – Least significant byte.

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
    Reads the NLSCW register from the DDS into internal storage.

    Description:
    The routine reads the 40‑bit Non‑Linear Sweep Control Word (NLSCW) via SPI and stores it locally.

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
    Writes the locally stored NLSCW value back to the DDS.

    Description:
    After updating the internal NLSCW copy, this function writes it over SPI to program the hardware register.

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
    Directly programs the NLSCW register from five bytes.

    Description:
    Convenience routine that assembles a 40‑bit value from five 8‑byte words and writes it to the DDS.
    WORD_4 is the most significant byte.

    Parameters:
    @param uint8_t WORD_4 – Most significant byte of NLSCW.
    @param uint8_t WORD_3 – Second MSB.
    @param uint8_t WORD_2 – Middle byte.
    @param uint8_t WORD_1 – Second LSB.
    @param uint8_t WORD_0 – Least significant byte.

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
    Reads the PLSCW register from the DDS into internal storage.

    Description:
    The routine reads the 40‑bit Phase Linear Sweep Control Word (PLSCW) via SPI and stores it locally.

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
    Writes the locally stored PLSCW value back to the DDS.

    Description:
    After updating the internal PLSCW copy, this function writes it over SPI to program the hardware register.

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
    Directly programs the PLSCW register from five bytes.

    Description:
    Convenience routine that assembles a 40‑bit value from five 8‑byte words and writes it to the DDS.
    WORD_4 is the most significant byte.

    Parameters:
    @param uint8_t WORD_4 – Most significant byte of PLSCW.
    @param uint8_t WORD_3 – Second MSB.
    @param uint8_t WORD_2 – Middle byte.
    @param uint8_t WORD_1 – Second LSB.
    @param uint8_t WORD_0 – Least significant byte.

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
    Sets the DDS output frequency.

    Description:
    Calculates and programs all registers necessary to generate a single‑tone output at the specified
    frequency (in Hz).  The routine handles the division of the desired frequency into the appropriate
    FTW0/1, RSCW, ASF, etc., then writes them over SPI.

    Parameters:
    @param uint32_t FREQUENCY – Desired output frequency in hertz (Hz).

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
    Programs a linear frequency sweep.

    Description:
    Sets up the DDS to perform a continuous linear sweep from
    NEGATIVE_LINEAR_SWEEP (Hz) up to POSITIVE_LINEAR_SWEEP (Hz).  
    The routine calculates the required sweep parameters and writes them to
    the appropriate registers (e.g., NLSCW, PLSCW, RSCW, etc.) so that the AD9954 performs
    a smooth frequency ramp.

    Parameters:
    @param uint32_t POSITIVE_LINEAR_SWEEP – Upper bound of the sweep in hertz.
    @param uint32_t NEGATIVE_LINEAR_SWEEP – Lower bound of the sweep in hertz.

    Returns:
    None.

    Remarks:
    None.
 */
void AD9954_DRIVER_Set_Linear_Sweep(uint32_t POSITIVE_LINEAR_SWEEP, uint32_t NEGATIVE_LINEAR_SWEEP);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _AD9954_DRIVER_H */

/*******************************************************************************
 End of File
 */