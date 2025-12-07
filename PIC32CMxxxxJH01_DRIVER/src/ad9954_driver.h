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

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Initialize                                                */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Initialize

   Summary:
   Performs one‑time initialization of the AD9954 DDS driver.

   Description:
   This routine configures the SPI interface, resets all internal driver
   variables, clears status flags, and writes the default values to the
   device.  It must be called once before any other AD9954_DRIVER_*
   functions are used.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Initialize(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Tasks                                                    */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Tasks

   Summary:
   Executes periodic driver tasks; should be called repeatedly.

   Description:
   This function polls the device, updates internal state machines,
   and performs any pending register writes.  It returns immediately
   after completing all queued operations.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Tasks(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Get_Task_Start_Status                                    */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Get_Task_Start_Status

   Summary:
   Returns the current “task start” status flag.

   Description:
   The driver sets this flag to `true` when a configuration task has
   been queued and cleared it once the task begins.  This helper is
   used by application code to determine whether a new operation
   should be started.

   Parameters:
   None.

   Returns:
   @return bool - true if a task has been requested but not yet started

   Remarks:
   None.
 */
bool AD9954_DRIVER_Get_Task_Start_Status(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Set_Task_Start_Status                                    */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Set_Task_Start_Status

   Summary:
   Sets the “task start” status flag.

   Description:
   Passing `true` queues a new configuration task; passing
   `false` clears the flag.  The driver will act on this flag during
   its next call to *AD9954_DRIVER_Tasks()*.

   Parameters:
   @param STATUS - desired state of the task‑start flag

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Set_Task_Start_Status(bool STATUS);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Get_Task_Completed_Status                                */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Get_Task_Completed_Status

   Summary:
   Returns the “task completed” status flag.

   Description:
   The driver sets this flag to `true` when a queued configuration
   operation has finished.  Application code can poll this flag to
   determine when it is safe to issue another task.

   Parameters:
   None.

   Returns:
   @return bool - true if the most recent task has finished

   Remarks:
   None.
 */
bool AD9954_DRIVER_Get_Task_Completed_Status(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Set_Task_Completed_Status                                */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Set_Task_Completed_Status

   Summary:
   Sets the “task completed” status flag.

   Description:
   Passing `true` indicates that a configuration task has finished;
   passing `false` clears the flag so the next operation can be
   started.  The flag is normally cleared automatically by the driver,
   but this setter allows manual control if needed.

   Parameters:
   @param STATUS - desired state of the task‑completed flag

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Set_Task_Completed_Status(bool STATUS);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Get_CFR1_Register                                         */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Get_CFR1_Register

   Summary:
   Reads the current value of register CFR1 from the device.

   Description:
   The routine issues an SPI read for CFR1 (Control‑Frequency‑Register 1)
   and stores the 32‑bit result in an internal variable.  No return
   value is provided; use *AD9954_DRIVER_Store_CFR1_Register()* to
   persist or transmit the value if required.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   The register is read in MSB‑first order (WORD 3 … WORD 0).
 */
void AD9954_DRIVER_Get_CFR1_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Store_CFR1_Register                                       */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Store_CFR1_Register

   Summary:
   Persists the internally cached CFR1 value to non‑volatile memory.

   Description:
   The driver writes the most recently read or set value of CFR1
   into a backup location (e.g., EEPROM).  This allows recovery
   after a power cycle.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_CFR1_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Set_CFR1_Register                                         */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Set_CFR1_Register

   Summary:
   Programs register CFR1 with the supplied byte values.

   Description:
   The four `uint8_t` arguments represent WORD 3 (MSB) down to
   WORD 0 (LSB).  The function writes the assembled 32‑bit value
   over SPI and updates the internal cache.  This register controls
   frequency, amplitude, and other DDS parameters.

   Parameters:
   @param WORD_3 - most‑significant byte of CFR1
   @param WORD_2 - second‑most‑significant byte
   @param WORD_1 - third byte
   @param WORD_0 - least‑significant byte

   Returns:
   None.

   Remarks:
   The caller must ensure that the values are valid for the current
   operating mode.
 */
void AD9954_DRIVER_Set_CFR1_Register(uint8_t WORD_3, uint8_t WORD_2,
                                     uint8_t WORD_1, uint8_t WORD_0);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Get_CFR2_Register                                         */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Get_CFR2_Register

   Summary:
   Reads the current value of register CFR2 from the device.

   Description:
   CFR2 is a 16‑bit register (WORD 1 … WORD 0).  The function
   stores the result in an internal variable; use
 *AD9954_DRIVER_Store_CFR2_Register()* to persist it if needed.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   The register is read MSB‑first.
 */
void AD9954_DRIVER_Get_CFR2_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Store_CFR2_Register                                       */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Store_CFR2_Register

   Summary:
   Persists the internally cached CFR2 value to non‑volatile memory.

   Description:
   The driver writes the most recent CFR2 contents into a backup
   location (e.g., EEPROM).  Useful for restoring configuration
   after power loss.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_CFR2_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Set_CFR2_Register                                         */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Set_CFR2_Register

   Summary:
   Programs register CFR2 with the supplied byte values.

   Description:
   The two arguments correspond to WORD 1 (MSB) and WORD 0 (LSB).
   After writing over SPI, the internal cache is updated.

   Parameters:
   @param WORD_1 - most‑significant byte of CFR2
   @param WORD_0 - least‑significant byte

   Returns:
   None.

   Remarks:
   The register controls phase and amplitude scaling.
 */
void AD9954_DRIVER_Set_CFR2_Register(uint8_t WORD_1, uint8_t WORD_0);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Get_ASF_Register                                          */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Get_ASF_Register

   Summary:
   Reads the current value of register ASF (Amplitude‑Scale‑Factor).

   Description:
   The ASF register is 16 bits wide.  This function reads it over
   SPI and stores the result in an internal variable.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   The register is read MSB‑first.
 */
void AD9954_DRIVER_Get_ASF_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Store_ASF_Register                                       */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Store_ASF_Register

   Summary:
   Persists the internally cached ASF value to non‑volatile memory.

   Description:
   Writes the most recent ASF contents into a backup location.
   Useful for restoring amplitude scaling after power loss.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_ASF_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Set_ASF_Register                                          */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Set_ASF_Register

   Summary:
   Programs register ASF with the supplied byte values.

   Description:
   The two arguments are WORD 1 (MSB) and WORD 0 (LSB).  After
   writing, the internal cache is updated.

   Parameters:
   @param WORD_1 - most‑significant byte of ASF
   @param WORD_0 - least‑significant byte

   Returns:
   None.

   Remarks:
   The register controls the output amplitude.
 */
void AD9954_DRIVER_Set_ASF_Register(uint8_t WORD_1, uint8_t WORD_0);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Get_ARR_Register                                          */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Get_ARR_Register

   Summary:
   Reads the current value of register ARR (Amplitude‑Ramping Register).

   Description:
   ARR is a single byte.  This routine reads it over SPI and stores
   the result in an internal variable.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   The register is read LSB‑first (only WORD 0 exists).
 */
void AD9954_DRIVER_Get_ARR_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Store_ARR_Register                                       */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Store_ARR_Register

   Summary:
   Persists the internally cached ARR value to non‑volatile memory.

   Description:
   Stores the most recent ARR contents into a backup location.
   Useful for restoring ramping parameters after reset.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_ARR_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Set_ARR_Register                                          */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Set_ARR_Register

   Summary:
   Programs register ARR with the supplied byte value.

   Description:
   The single argument is WORD 0.  After writing over SPI, the
   internal cache is updated.

   Parameters:
   @param WORD_0 - byte to write into ARR

   Returns:
   None.

   Remarks:
   This register sets the amplitude‑ramping period.
 */
void AD9954_DRIVER_Set_ARR_Register(uint8_t WORD_0);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Get_FTW0_Register                                         */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Get_FTW0_Register

   Summary:
   Reads the current value of register FTW0 (Frequency‑Tuning Word 0).

   Description:
   FTW0 is a 32‑bit register.  The function reads it over SPI
   and stores the result in an internal variable.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Register is read MSB‑first.
 */
void AD9954_DRIVER_Get_FTW0_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Store_FTW0_Register                                       */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Store_FTW0_Register

   Summary:
   Persists the internally cached FTW0 value to non‑volatile memory.

   Description:
   Writes the most recent FTW0 contents into a backup location.
   Useful for restoring frequency after power loss.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_FTW0_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Set_FTW0_Register                                         */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Set_FTW0_Register

   Summary:
   Programs register FTW0 with the supplied byte values.

   Description:
   The four arguments are WORD 3 (MSB) … WORD 0 (LSB).  After
   writing over SPI, the internal cache is updated.  This word
   determines the output frequency component 0.

   Parameters:
   @param WORD_3 - most‑significant byte of FTW0
   @param WORD_2 - second‑most‑significant byte
   @param WORD_1 - third byte
   @param WORD_0 - least‑significant byte

   Returns:
   None.

   Remarks:
   The device interprets the word as a 32‑bit unsigned integer.
 */
void AD9954_DRIVER_Set_FTW0_Register(uint8_t WORD_3, uint8_t WORD_2,
                                     uint8_t WORD_1, uint8_t WORD_0);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Get_POW0_Register                                         */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Get_POW0_Register

   Summary:
   Reads the current value of register POW0 (Power‑Offset Word 0).

   Description:
   POW0 is a 16‑bit register.  The function reads it over SPI
   and stores the result in an internal variable.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Register is read MSB‑first.
 */
void AD9954_DRIVER_Get_POW0_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Store_POW0_Register                                       */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Store_POW0_Register

   Summary:
   Persists the internally cached POW0 value to non‑volatile memory.

   Description:
   Writes the most recent POW0 contents into a backup location.
   Useful for restoring power‑offset after reset.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_POW0_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Set_POW0_Register                                         */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Set_POW0_Register

   Summary:
   Programs register POW0 with the supplied byte values.

   Description:
   The two arguments are WORD 1 (MSB) and WORD 0 (LSB).  After
   writing, the internal cache is updated.

   Parameters:
   @param WORD_1 - most‑significant byte of POW0
   @param WORD_0 - least‑significant byte

   Returns:
   None.

   Remarks:
   This register sets the power‑offset for frequency component 0.
 */
void AD9954_DRIVER_Set_POW0_Register(uint8_t WORD_1, uint8_t WORD_0);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Get_FTW1_Register                                         */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Get_FTW1_Register

   Summary:
   Reads the current value of register FTW1 (Frequency‑Tuning Word 1).

   Description:
   FTW1 is a 32‑bit register.  The function reads it over SPI
   and stores the result in an internal variable.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Register is read MSB‑first.
 */
void AD9954_DRIVER_Get_FTW1_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Store_FTW1_Register                                       */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Store_FTW1_Register

   Summary:
   Persists the internally cached FTW1 value to non‑volatile memory.

   Description:
   Writes the most recent FTW1 contents into a backup location.
   Useful for restoring frequency after power loss.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_FTW1_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Set_FTW1_Register                                         */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Set_FTW1_Register

   Summary:
   Programs register FTW1 with the supplied byte values.

   Description:
   The four arguments are WORD 3 (MSB) … WORD 0 (LSB).  After
   writing over SPI, the internal cache is updated.  This word
   determines the output frequency component 1.

   Parameters:
   @param WORD_3 - most‑significant byte of FTW1
   @param WORD_2 - second‑most‑significant byte
   @param WORD_1 - third byte
   @param WORD_0 - least‑significant byte

   Returns:
   None.

   Remarks:
   The device interprets the word as a 32‑bit unsigned integer.
 */
void AD9954_DRIVER_Set_FTW1_Register(uint8_t WORD_3, uint8_t WORD_2,
                                     uint8_t WORD_1, uint8_t WORD_0);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Get_RSCW0_Register                                        */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Get_RSCW0_Register

   Summary:
   Reads the current value of register RSCW0 (Random‑Sequence‑Control‑Word 0).

   Description:
   RSCW0 is a 40‑bit register.  The function reads it over SPI
   and stores the result in an internal variable.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Register is read MSB‑first (WORD 4 … WORD 0).
 */
void AD9954_DRIVER_Get_RSCW0_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Store_RSCW0_Register                                      */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Store_RSCW0_Register

   Summary:
   Persists the internally cached RSCW0 value to non‑volatile memory.

   Description:
   Writes the most recent RSCW0 contents into a backup location.
   Useful for restoring random‑sequence settings after reset.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_RSCW0_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Set_RSCW0_Register                                        */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Set_RSCW0_Register

   Summary:
   Programs register RSCW0 with the supplied byte values.

   Description:
   The five arguments are WORD 4 (MSB) … WORD 0 (LSB).  After
   writing over SPI, the internal cache is updated.  RSCW0 configures
   random‑sequence parameters for DDS output component 0.

   Parameters:
   @param WORD_4 - most‑significant byte of RSCW0
   @param WORD_3 - next byte
   @param WORD_2 - third byte
   @param WORD_1 - fourth byte
   @param WORD_0 - least‑significant byte

   Returns:
   None.

   Remarks:
   The register is 40 bits wide; the upper 8 bits (WORD 4) are often
   zero depending on configuration.
 */
void AD9954_DRIVER_Set_RSCW0_Register(uint8_t WORD_4, uint8_t WORD_3,
                                      uint8_t WORD_2, uint8_t WORD_1,
                                      uint8_t WORD_0);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Get_RSCW1_Register                                        */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Get_RSCW1_Register

   Summary:
   Reads the current value of register RSCW1 (Random‑Sequence‑Control‑Word 1).

   Description:
   RSCW1 is a 40‑bit register.  The function reads it over SPI
   and stores the result in an internal variable.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Register is read MSB‑first (WORD 4 … WORD 0).
 */
void AD9954_DRIVER_Get_RSCW1_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Store_RSCW1_Register                                      */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Store_RSCW1_Register

   Summary:
   Persists the internally cached RSCW1 value to non‑volatile memory.

   Description:
   Writes the most recent RSCW1 contents into a backup location.
   Useful for restoring random‑sequence settings after reset.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_RSCW1_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Set_RSCW1_Register                                        */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Set_RSCW1_Register

   Summary:
   Programs register RSCW1 with the supplied byte values.

   Description:
   The five arguments are WORD 4 … WORD 0.  After writing over SPI,
   the internal cache is updated.  RSCW1 configures random‑sequence
   parameters for DDS output component 1.

   Parameters:
   @param WORD_4 - most‑significant byte of RSCW1
   @param WORD_3 - next byte
   @param WORD_2 - third byte
   @param WORD_1 - fourth byte
   @param WORD_0 - least‑significant byte

   Returns:
   None.

   Remarks:
   The register is 40 bits wide; the upper 8 bits (WORD 4) are often
   zero depending on configuration.
 */
void AD9954_DRIVER_Set_RSCW1_Register(uint8_t WORD_4, uint8_t WORD_3,
                                      uint8_t WORD_2, uint8_t WORD_1,
                                      uint8_t WORD_0);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Get_RSCW2_Register                                        */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Get_RSCW2_Register

   Summary:
   Reads the current value of register RSCW2 (Random‑Sequence‑Control‑Word 2).

   Description:
   RSCW2 is a 40‑bit register.  The function reads it over SPI
   and stores the result in an internal variable.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Register is read MSB‑first (WORD 4 … WORD 0).
 */
void AD9954_DRIVER_Get_RSCW2_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Store_RSCW2_Register                                      */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Store_RSCW2_Register

   Summary:
   Persists the internally cached RSCW2 value to non‑volatile memory.

   Description:
   Writes the most recent RSCW2 contents into a backup location.
   Useful for restoring random‑sequence settings after reset.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_RSCW2_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Set_RSCW2_Register                                        */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Set_RSCW2_Register

   Summary:
   Programs register RSCW2 with the supplied byte values.

   Description:
   The five arguments are WORD 4 … WORD 0.  After writing over SPI,
   the internal cache is updated.  RSCW2 configures random‑sequence
   parameters for DDS output component 2.

   Parameters:
   @param WORD_4 - most‑significant byte of RSCW2
   @param WORD_3 - next byte
   @param WORD_2 - third byte
   @param WORD_1 - fourth byte
   @param WORD_0 - least‑significant byte

   Returns:
   None.

   Remarks:
   The register is 40 bits wide; the upper 8 bits (WORD 4) are often
   zero depending on configuration.
 */
void AD9954_DRIVER_Set_RSCW2_Register(uint8_t WORD_4, uint8_t WORD_3,
                                      uint8_t WORD_2, uint8_t WORD_1,
                                      uint8_t WORD_0);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Get_RSCW3_Register                                        */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Get_RSCW3_Register

   Summary:
   Reads the current value of register RSCW3 (Random‑Sequence‑Control‑Word 3).

   Description:
   RSCW3 is a 40‑bit register.  The function reads it over SPI
   and stores the result in an internal variable.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Register is read MSB‑first (WORD 4 … WORD 0).
 */
void AD9954_DRIVER_Get_RSCW3_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Store_RSCW3_Register                                      */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Store_RSCW3_Register

   Summary:
   Persists the internally cached RSCW3 value to non‑volatile memory.

   Description:
   Writes the most recent RSCW3 contents into a backup location.
   Useful for restoring random‑sequence settings after reset.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_RSCW3_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Set_RSCW3_Register                                        */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Set_RSCW3_Register

   Summary:
   Programs register RSCW3 with the supplied byte values.

   Description:
   The five arguments are WORD 4 … WORD 0.  After writing over SPI,
   the internal cache is updated.  RSCW3 configures random‑sequence
   parameters for DDS output component 3.

   Parameters:
   @param WORD_4 - most‑significant byte of RSCW3
   @param WORD_3 - next byte
   @param WORD_2 - third byte
   @param WORD_1 - fourth byte
   @param WORD_0 - least‑significant byte

   Returns:
   None.

   Remarks:
   The register is 40 bits wide; the upper 8 bits (WORD 4) are often
   zero depending on configuration.
 */
void AD9954_DRIVER_Set_RSCW3_Register(uint8_t WORD_4, uint8_t WORD_3,
                                      uint8_t WORD_2, uint8_t WORD_1,
                                      uint8_t WORD_0);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Get_NLSCW_Register                                        */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Get_NLSCW_Register

   Summary:
   Reads the current value of register NLSCW (Noise‑Level‑Sweep‑Control‑Word).

   Description:
   NLSCW is a 40‑bit register controlling the noise‑level sweep
   parameters.  The function reads it over SPI and stores the result
   in an internal variable.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Register is read MSB‑first (WORD 4 … WORD 0).
 */
void AD9954_DRIVER_Get_NLSCW_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Store_NLSCW_Register                                      */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Store_NLSCW_Register

   Summary:
   Persists the internally cached NLSCW value to non‑volatile memory.

   Description:
   Writes the most recent NLSCW contents into a backup location.
   Useful for restoring noise‑level sweep settings after reset.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_NLSCW_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Set_NLSCW_Register                                        */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Set_NLSCW_Register

   Summary:
   Programs register NLSCW with the supplied byte values.

   Description:
   The five arguments are WORD 4 … WORD 0.  After writing over SPI,
   the internal cache is updated.  NLSCW configures the noise‑level
   sweep parameters for DDS output component 0.

   Parameters:
   @param WORD_4 - most‑significant byte of NLSCW
   @param WORD_3 - next byte
   @param WORD_2 - third byte
   @param WORD_1 - fourth byte
   @param WORD_0 - least‑significant byte

   Returns:
   None.

   Remarks:
   The register is 40 bits wide; the upper 8 bits (WORD 4) are often
   zero depending on configuration.
 */
void AD9954_DRIVER_Set_NLSCW_Register(uint8_t WORD_4, uint8_t WORD_3,
                                      uint8_t WORD_2, uint8_t WORD_1,
                                      uint8_t WORD_0);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Get_PLSCW_Register                                        */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Get_PLSCW_Register

   Summary:
   Reads the current value of register PLSCW (Phase‑Level‑Sweep‑Control‑Word).

   Description:
   PLSCW is a 40‑bit register controlling the phase‑level sweep
   parameters.  The function reads it over SPI and stores the result
   in an internal variable.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   Register is read MSB‑first (WORD 4 … WORD 0).
 */
void AD9954_DRIVER_Get_PLSCW_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Store_PLSCW_Register                                      */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Store_PLSCW_Register

   Summary:
   Persists the internally cached PLSCW value to non‑volatile memory.

   Description:
   Writes the most recent PLSCW contents into a backup location.
   Useful for restoring phase‑level sweep settings after reset.

   Parameters:
   None.

   Returns:
   None.

   Remarks:
   None.
 */
void AD9954_DRIVER_Store_PLSCW_Register(void);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Set_PLSCW_Register                                        */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Set_PLSCW_Register

   Summary:
   Programs register PLSCW with the supplied byte values.

   Description:
   The five arguments are WORD 4 … WORD 0.  After writing over SPI,
   the internal cache is updated.  PLSCW configures the phase‑level
   sweep parameters for DDS output component 0.

   Parameters:
   @param WORD_4 - most‑significant byte of PLSCW
   @param WORD_3 - next byte
   @param WORD_2 - third byte
   @param WORD_1 - fourth byte
   @param WORD_0 - least‑significant byte

   Returns:
   None.

   Remarks:
   The register is 40 bits wide; the upper 8 bits (WORD 4) are often
   zero depending on configuration.
 */
void AD9954_DRIVER_Set_PLSCW_Register(uint8_t WORD_4, uint8_t WORD_3,
                                      uint8_t WORD_2, uint8_t WORD_1,
                                      uint8_t WORD_0);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Set_Frequency                                             */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Set_Frequency

   Summary:
   Sets the DDS output frequency by programming FTW registers.

   Description:
   The supplied `FREQUENCY` (in Hz) is converted to a 32‑bit
   Frequency‑Tuning Word for each component, written into FTW0/FTW1,
   and then committed to the device.  The driver performs any necessary
   scaling (e.g., reference frequency, calibration factors).

   Parameters:
   @param FREQUENCY - desired output frequency in Hz

   Returns:
   None.

   Remarks:
   The maximum representable frequency depends on the device’s
   reference clock and word size.  Overflow results in saturation.
 */
void AD9954_DRIVER_Set_Frequency(uint32_t FREQUENCY);

/* -------------------------------------------------------------------------- */
/*  AD9954_DRIVER_Set_Linear_Sweep                                          */
/* -------------------------------------------------------------------------- */
/**
   Function:
   AD9954_DRIVER_Set_Linear_Sweep

   Summary:
   Programs linear frequency sweep parameters for the DDS.

   Description:
   The two arguments represent the positive and negative sweep
   rates. They are converted to the appropriate
   RSCW registers (or equivalent) and written to the device.
   After this call, a subsequent *AD9954_DRIVER_Tasks()* will
   start the sweep.

   Parameters:
   @param POSITIVE_LINEAR_SWEEP - forward sweep rate in Hz/s
   @param NEGATIVE_LINEAR_SWEEP - reverse sweep rate in Hz/s

   Returns:
   None.

   Remarks:
   The driver clamps values to the device’s allowable range.
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