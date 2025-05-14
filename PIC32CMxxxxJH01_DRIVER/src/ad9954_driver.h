/*******************************************************************************
  MPLAB Harmony Application Header File

  Author:
    Odry01

  File Name:
    ad9954_driver.h

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

#define AD9954_CFR1_ADDRESS     0x00
#define AD9954_CFR2_ADDRESS     0x01
#define AD9954_ASF_ADDRESS      0x02
#define AD9954_ARR_ADDRESS      0x03
#define AD9954_FTW0_ADDRESS     0x04
#define AD9954_POW0_ADDRESS     0x05
#define AD9954_FTW1_ADDRESS     0x06
#define AD9954_RSCW0_ADDRESS    0x07
#define AD9954_RSCW1_ADDRESS    0x08
#define AD9954_RSCW2_ADDRESS    0x08
#define AD9954_RSCW3_ADDRESS    0x08
#define AD9954_RAM_ADDRESS      0x0B
#define AD9954_NLSCW_ADDRESS    0x07
#define AD9954_PLSCW_ADDRESS    0x08

#define AD9954_RW_BIT_SET       0x80

#define AD9954_SPI_DATA_RX      32
#define AD9954_SPI_DATA_TX      32

// *****************************************************************************

/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
 */

typedef enum
{
    AD9954_DRIVER_STATE_INIT = 0,
    AD9954_DRIVER_STATE_SPI_HANDLER_REGISTER,
    AD9954_DRIVER_STATE_SET_CFR1,
    AD9954_DRIVER_STATE_SET_CFR1_ACK,
    AD9954_DRIVER_STATE_SET_CFR1_WAIT_FOR_TRANSFER,
    AD9954_DRIVER_STATE_IDLE,
    AD9954_DRIVER_STATE_SET_FTW0,
    AD9954_DRIVER_STATE_SET_FTW0_ACK,
    AD9954_DRIVER_STATE_SET_FTW0_WAIT_FOR_TRANSFER,
    AD9954_DRIVER_STATE_SET_FTW1,
    AD9954_DRIVER_STATE_SET_FTW1_ACK,
    AD9954_DRIVER_STATE_SET_FTW1_WAIT_FOR_TRANSFER,
    AD9954_DRIVER_STATE_SET_NLSCW,
    AD9954_DRIVER_STATE_SET_NLSCW_ACK,
    AD9954_DRIVER_STATE_SET_NLSCW_WAIT_FOR_TRANSFER,
    AD9954_DRIVER_STATE_SET_PLSCW,
    AD9954_DRIVER_STATE_SET_PLSCW_ACK,
    AD9954_DRIVER_STATE_SET_PLSCW_WAIT_FOR_TRANSFER,
    AD9954_DRIVER_STATE_TIMER_EXPIRED,
    AD9954_DRIVER_STATE_ERROR,
} AD9954_DRIVER_STATES;

// *****************************************************************************

/* Application Data

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
    bool SPI_TRANSFER_STATUS;
    bool AD9954_TASK_START;
    bool AD9954_TASK_COMPLETED;
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

void AD9954_DRIVER_SPI_Callback(DRV_SPI_TRANSFER_EVENT EVENT, DRV_SPI_TRANSFER_HANDLE SPI_TRANSFER_HANDLE, uintptr_t CONTEXT);

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void AD9954_DRIVER_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    AD9954_DRIVER_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    AD9954_DRIVER_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
 */

void AD9954_DRIVER_Initialize(void);

/*******************************************************************************
  Function:
    void AD9954_DRIVER_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    AD9954_DRIVER_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void AD9954_DRIVER_Tasks(void);

bool AD9954_DRIVER_Get_Task_Start_Status(void);

void AD9954_DRIVER_Set_Task_Start_Status(bool STATUS);

bool AD9954_DRIVER_Get_Task_Completed_Status(void);

void AD9954_DRIVER_Set_Task_Completed_Status(bool STATUS);

void AD9954_DRIVER_Get_CFR1_Register(void);

void AD9954_DRIVER_Store_CFR1_Register(void);

void AD9954_DRIVER_Set_CFR1_Register(uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0);

void AD9954_DRIVER_Get_CFR2_Register(void);

void AD9954_DRIVER_Store_CFR2_Register(void);

void AD9954_DRIVER_Set_CFR2_Register(uint8_t WORD_0, uint8_t WORD_1);

void AD9954_DRIVER_Get_ASF_Register(void);

void AD9954_DRIVER_Store_ASF_Register(void);

void AD9954_DRIVER_Set_ASF_Register(uint8_t WORD_0, uint8_t WORD_1);

void AD9954_DRIVER_Get_ARR_Register(void);

void AD9954_DRIVER_Store_ARR_Register(void);

void AD9954_DRIVER_Set_ARR_Register(uint8_t WORD_0);

void AD9954_DRIVER_Get_FTW0_Register(void);

void AD9954_DRIVER_Store_FTW0_Register(void);

void AD9954_DRIVER_Set_FTW0_Register(uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0);

void AD9954_DRIVER_Get_POW0_Register(void);

void AD9954_DRIVER_Store_POW0_Register(void);

void AD9954_DRIVER_Set_POW0_Register(uint8_t WORD_0, uint8_t WORD_1);

void AD9954_DRIVER_Get_FTW1_Register(void);

void AD9954_DRIVER_Store_FTW1_Register(void);

void AD9954_DRIVER_Set_FTW1_Register(uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0);

void AD9954_DRIVER_Get_RSCW0_Register(void);

void AD9954_DRIVER_Store_RSCW0_Register(void);

void AD9954_DRIVER_Set_RSCW0_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0);

void AD9954_DRIVER_Get_RSCW1_Register(void);

void AD9954_DRIVER_Store_RSCW1_Register(void);

void AD9954_DRIVER_Set_RSCW1_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0);

void AD9954_DRIVER_Get_RSCW2_Register(void);

void AD9954_DRIVER_Store_RSCW2_Register(void);

void AD9954_DRIVER_Set_RSCW2_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0);

void AD9954_DRIVER_Get_RSCW3_Register(void);

void AD9954_DRIVER_Store_RSCW3_Register(void);

void AD9954_DRIVER_Set_RSCW3_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0);

void AD9954_DRIVER_Get_NLSCW_Register(void);

void AD9954_DRIVER_Store_NLSCW_Register(void);

void AD9954_DRIVER_Set_NLSCW_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0);

void AD9954_DRIVER_Get_PLSCW_Register(void);

void AD9954_DRIVER_Store_PLSCW_Register(void);

void AD9954_DRIVER_Set_PLSCW_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0);

void AD9954_DRIVER_Set_Frequency(uint32_t FREQUENCY);

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