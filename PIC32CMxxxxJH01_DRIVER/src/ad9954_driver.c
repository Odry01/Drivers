/*******************************************************************************
  MPLAB Harmony Application Source File

  Author:
    Odry01

  File Name:
    ad9954_driver.c

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

#include "ad9954_driver.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

AD9954_DRIVER_DATA ad9954_driverData;

AD9954_DRIVER_DDS_DATA ad9954_ddsData;

AD9954_DRIVER_SETTING_DATA ad9954_settingsData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

void AD9954_DRIVER_SPI_Callback(DRV_SPI_TRANSFER_EVENT EVENT, DRV_SPI_TRANSFER_HANDLE SPI_TRANSFER_HANDLE, uintptr_t CONTEXT)
{
    switch (EVENT)
    {
        case DRV_SPI_TRANSFER_EVENT_COMPLETE:
        {
            ad9954_driverData.SPI_TRANSFER_STATUS = true;
            break;
        }

        case DRV_SPI_TRANSFER_EVENT_ERROR:
        {
            ad9954_driverData.SPI_TRANSFER_STATUS = false;
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

bool AD9954_DRIVER_Get_Task_Start_Status(void)
{
    return (ad9954_driverData.AD9954_TASK_START);
}

void AD9954_DRIVER_Set_Task_Start_Status(bool STATUS)
{
    ad9954_driverData.AD9954_TASK_START = STATUS;
}

bool AD9954_DRIVER_Get_Task_Completed_Status(void)
{
    return (ad9954_driverData.AD9954_TASK_COMPLETED);
}

void AD9954_DRIVER_Set_Task_Completed_Status(bool STATUS)
{
    ad9954_driverData.AD9954_TASK_COMPLETED = STATUS;
}

void AD9954_DRIVER_Get_CFR1_Register(void)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_CFR1_ADDRESS | AD9954_RW_BIT_SET;
    DRV_SPI_WriteReadTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 1, &ad9954_driverData.SPI_DATA_RECEIVE, 4, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Store_CFR1_Register(void)
{
    ad9954_ddsData.CFR1_REGISTER_VALUE = ad9954_driverData.SPI_DATA_RECEIVE[0] << 24 | ad9954_driverData.SPI_DATA_RECEIVE[1] << 16 | ad9954_driverData.SPI_DATA_RECEIVE[2] << 8 | ad9954_driverData.SPI_DATA_RECEIVE[3];
}

void AD9954_DRIVER_Set_CFR1_Register(uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_CFR1_ADDRESS & AD9954_RW_BIT_SET;
    ad9954_driverData.SPI_DATA_TRANSMIT[1] = WORD_3;
    ad9954_driverData.SPI_DATA_TRANSMIT[2] = WORD_2;
    ad9954_driverData.SPI_DATA_TRANSMIT[3] = WORD_1;
    ad9954_driverData.SPI_DATA_TRANSMIT[4] = WORD_0;
    DRV_SPI_WriteTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 5, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Get_CFR2_Register(void)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_CFR2_ADDRESS | AD9954_RW_BIT_SET;
    DRV_SPI_WriteReadTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 1, &ad9954_driverData.SPI_DATA_RECEIVE, 2, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Store_CFR2_Register(void)
{
    ad9954_ddsData.CFR2_REGISTER_VALUE = ad9954_driverData.SPI_DATA_RECEIVE[0] << 8 | ad9954_driverData.SPI_DATA_RECEIVE[1];
}

void AD9954_DRIVER_Set_CFR2_Register(uint8_t WORD_1, uint8_t WORD_0)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_CFR2_ADDRESS & AD9954_RW_BIT_SET;
    ad9954_driverData.SPI_DATA_TRANSMIT[1] = WORD_1;
    ad9954_driverData.SPI_DATA_TRANSMIT[2] = WORD_0;
    DRV_SPI_WriteTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 3, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Get_ASF_Register(void)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_ASF_ADDRESS | AD9954_RW_BIT_SET;
    DRV_SPI_WriteReadTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 1, &ad9954_driverData.SPI_DATA_RECEIVE, 2, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Store_ASF_Register(void)
{
    ad9954_ddsData.ASF_REGISTER_VALUE = ad9954_driverData.SPI_DATA_RECEIVE[0] << 8 | ad9954_driverData.SPI_DATA_RECEIVE[1];
}

void AD9954_DRIVER_Set_ASF_Register(uint8_t WORD_1, uint8_t WORD_0)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_ASF_ADDRESS & AD9954_RW_BIT_SET;
    ad9954_driverData.SPI_DATA_TRANSMIT[1] = WORD_1;
    ad9954_driverData.SPI_DATA_TRANSMIT[2] = WORD_0;
    DRV_SPI_WriteTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 3, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Get_ARR_Register(void)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_ARR_ADDRESS | AD9954_RW_BIT_SET;
    DRV_SPI_WriteReadTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 1, &ad9954_driverData.SPI_DATA_RECEIVE, 1, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Store_ARR_Register(void)
{
    ad9954_ddsData.ARR_REGISTER_VALUE = ad9954_driverData.SPI_DATA_RECEIVE[0] << 8 | ad9954_driverData.SPI_DATA_RECEIVE[1];
}

void AD9954_DRIVER_Set_ARR_Register(uint8_t WORD_0)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_ARR_ADDRESS & AD9954_RW_BIT_SET;
    ad9954_driverData.SPI_DATA_TRANSMIT[1] = WORD_0;
    DRV_SPI_WriteTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 2, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Get_FTW0_Register(void)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_FTW0_ADDRESS | AD9954_RW_BIT_SET;
    DRV_SPI_WriteReadTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 1, &ad9954_driverData.SPI_DATA_RECEIVE, 4, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Store_FTW0_Register(void)
{
    ad9954_ddsData.FTW0_REGISTER_VALUE = ad9954_driverData.SPI_DATA_RECEIVE[0] << 24 | ad9954_driverData.SPI_DATA_RECEIVE[1] << 16 | ad9954_driverData.SPI_DATA_RECEIVE[2] << 8 | ad9954_driverData.SPI_DATA_RECEIVE[3];
}

void AD9954_DRIVER_Set_FTW0_Register(uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_FTW0_ADDRESS & AD9954_RW_BIT_SET;
    ad9954_driverData.SPI_DATA_TRANSMIT[1] = WORD_3;
    ad9954_driverData.SPI_DATA_TRANSMIT[2] = WORD_2;
    ad9954_driverData.SPI_DATA_TRANSMIT[3] = WORD_1;
    ad9954_driverData.SPI_DATA_TRANSMIT[4] = WORD_0;
    DRV_SPI_WriteTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 5, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Get_POW0_Register(void)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_POW0_ADDRESS | AD9954_RW_BIT_SET;
    DRV_SPI_WriteReadTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 1, &ad9954_driverData.SPI_DATA_RECEIVE, 2, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Store_POW0_Register(void)
{
    ad9954_ddsData.POW0_REGISTER_VALUE = ad9954_driverData.SPI_DATA_RECEIVE[0] << 8 | ad9954_driverData.SPI_DATA_RECEIVE[1];
}

void AD9954_DRIVER_Set_POW0_Register(uint8_t WORD_0, uint8_t WORD_1)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_POW0_ADDRESS & AD9954_RW_BIT_SET;
    ad9954_driverData.SPI_DATA_TRANSMIT[1] = WORD_1;
    ad9954_driverData.SPI_DATA_TRANSMIT[2] = WORD_0;
    DRV_SPI_WriteTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 3, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Get_FTW1_Register(void)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_FTW1_ADDRESS | AD9954_RW_BIT_SET;
    DRV_SPI_WriteReadTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 1, &ad9954_driverData.SPI_DATA_RECEIVE, 4, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Store_FTW1_Register(void)
{
    ad9954_ddsData.FTW1_REGISTER_VALUE = ad9954_driverData.SPI_DATA_RECEIVE[0] << 24 | ad9954_driverData.SPI_DATA_RECEIVE[1] << 16 | ad9954_driverData.SPI_DATA_RECEIVE[2] << 8 | ad9954_driverData.SPI_DATA_RECEIVE[3];
}

void AD9954_DRIVER_Set_FTW1_Register(uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_FTW1_ADDRESS & AD9954_RW_BIT_SET;
    ad9954_driverData.SPI_DATA_TRANSMIT[1] = WORD_3;
    ad9954_driverData.SPI_DATA_TRANSMIT[2] = WORD_2;
    ad9954_driverData.SPI_DATA_TRANSMIT[3] = WORD_1;
    ad9954_driverData.SPI_DATA_TRANSMIT[4] = WORD_0;
    DRV_SPI_WriteTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 5, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Get_RSCW0_Register(void)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_RSCW0_ADDRESS | AD9954_RW_BIT_SET;
    DRV_SPI_WriteReadTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 1, &ad9954_driverData.SPI_DATA_RECEIVE, 5, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Store_RSCW0_Register(void)
{
//    ad9954_ddsData.RSCW0_REGISTER_VALUE = ad9954_driverData.SPI_DATA_RECEIVE[0] << 32 | ad9954_driverData.SPI_DATA_RECEIVE[1] << 24 | ad9954_driverData.SPI_DATA_RECEIVE[2] << 16 | ad9954_driverData.SPI_DATA_RECEIVE[3] << 8 | ad9954_driverData.SPI_DATA_RECEIVE[4];
}

void AD9954_DRIVER_Set_RSCW0_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_RSCW0_ADDRESS & AD9954_RW_BIT_SET;
    ad9954_driverData.SPI_DATA_TRANSMIT[1] = WORD_4;
    ad9954_driverData.SPI_DATA_TRANSMIT[2] = WORD_3;
    ad9954_driverData.SPI_DATA_TRANSMIT[3] = WORD_2;
    ad9954_driverData.SPI_DATA_TRANSMIT[4] = WORD_1;
    ad9954_driverData.SPI_DATA_TRANSMIT[5] = WORD_0;
    DRV_SPI_WriteTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 6, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Get_RSCW1_Register(void)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_RSCW1_ADDRESS | AD9954_RW_BIT_SET;
    DRV_SPI_WriteReadTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 1, &ad9954_driverData.SPI_DATA_RECEIVE, 5, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Store_RSCW1_Register(void)
{
//    ad9954_ddsData.RSCW1_REGISTER_VALUE = ad9954_driverData.SPI_DATA_RECEIVE[0] << 32 | ad9954_driverData.SPI_DATA_RECEIVE[1] << 24 | ad9954_driverData.SPI_DATA_RECEIVE[2] << 16 | ad9954_driverData.SPI_DATA_RECEIVE[3] << 8 | ad9954_driverData.SPI_DATA_RECEIVE[4];
}

void AD9954_DRIVER_Set_RSCW1_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_RSCW1_ADDRESS & AD9954_RW_BIT_SET;
    ad9954_driverData.SPI_DATA_TRANSMIT[1] = WORD_4;
    ad9954_driverData.SPI_DATA_TRANSMIT[2] = WORD_3;
    ad9954_driverData.SPI_DATA_TRANSMIT[3] = WORD_2;
    ad9954_driverData.SPI_DATA_TRANSMIT[4] = WORD_1;
    ad9954_driverData.SPI_DATA_TRANSMIT[5] = WORD_0;
    DRV_SPI_WriteTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 6, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Get_RSCW2_Register(void)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_RSCW2_ADDRESS | AD9954_RW_BIT_SET;
    DRV_SPI_WriteReadTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 1, &ad9954_driverData.SPI_DATA_RECEIVE, 5, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Store_RSCW2_Register(void)
{
//    ad9954_ddsData.RSCW2_REGISTER_VALUE = ad9954_driverData.SPI_DATA_RECEIVE[0] << 32 | ad9954_driverData.SPI_DATA_RECEIVE[1] << 24 | ad9954_driverData.SPI_DATA_RECEIVE[2] << 16 | ad9954_driverData.SPI_DATA_RECEIVE[3] << 8 | ad9954_driverData.SPI_DATA_RECEIVE[4];
}

void AD9954_DRIVER_Set_RSCW2_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_RSCW2_ADDRESS & AD9954_RW_BIT_SET;
    ad9954_driverData.SPI_DATA_TRANSMIT[1] = WORD_4;
    ad9954_driverData.SPI_DATA_TRANSMIT[2] = WORD_3;
    ad9954_driverData.SPI_DATA_TRANSMIT[3] = WORD_2;
    ad9954_driverData.SPI_DATA_TRANSMIT[4] = WORD_1;
    ad9954_driverData.SPI_DATA_TRANSMIT[5] = WORD_0;
    DRV_SPI_WriteTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 6, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Get_RSCW3_Register(void)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_RSCW3_ADDRESS | AD9954_RW_BIT_SET;
    DRV_SPI_WriteReadTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 1, &ad9954_driverData.SPI_DATA_RECEIVE, 5, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Store_RSCW3_Register(void)
{
//    ad9954_ddsData.RSCW3_REGISTER_VALUE = ad9954_driverData.SPI_DATA_RECEIVE[0] << 32 | ad9954_driverData.SPI_DATA_RECEIVE[1] << 24 | ad9954_driverData.SPI_DATA_RECEIVE[2] << 16 | ad9954_driverData.SPI_DATA_RECEIVE[3] << 8 | ad9954_driverData.SPI_DATA_RECEIVE[4];
}

void AD9954_DRIVER_Set_RSCW3_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_RSCW3_ADDRESS & AD9954_RW_BIT_SET;
    ad9954_driverData.SPI_DATA_TRANSMIT[1] = WORD_4;
    ad9954_driverData.SPI_DATA_TRANSMIT[2] = WORD_3;
    ad9954_driverData.SPI_DATA_TRANSMIT[3] = WORD_2;
    ad9954_driverData.SPI_DATA_TRANSMIT[4] = WORD_1;
    ad9954_driverData.SPI_DATA_TRANSMIT[5] = WORD_0;
    DRV_SPI_WriteTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 6, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Get_NLSCW_Register(void)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_NLSCW_ADDRESS | AD9954_RW_BIT_SET;
    DRV_SPI_WriteReadTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 1, &ad9954_driverData.SPI_DATA_RECEIVE, 5, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Store_NLSCW_Register(void)
{
//    ad9954_ddsData.NLSCW_REGISTER_VALUE = ad9954_driverData.SPI_DATA_RECEIVE[0] << 32 | ad9954_driverData.SPI_DATA_RECEIVE[1] << 24 | ad9954_driverData.SPI_DATA_RECEIVE[2] << 16 | ad9954_driverData.SPI_DATA_RECEIVE[3] << 8 | ad9954_driverData.SPI_DATA_RECEIVE[4];
}

void AD9954_DRIVER_Set_NLSCW_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_NLSCW_ADDRESS & AD9954_RW_BIT_SET;
    ad9954_driverData.SPI_DATA_TRANSMIT[1] = WORD_4;
    ad9954_driverData.SPI_DATA_TRANSMIT[2] = WORD_3;
    ad9954_driverData.SPI_DATA_TRANSMIT[3] = WORD_2;
    ad9954_driverData.SPI_DATA_TRANSMIT[4] = WORD_1;
    ad9954_driverData.SPI_DATA_TRANSMIT[5] = WORD_0;
    DRV_SPI_WriteTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 6, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Get_PLSCW_Register(void)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_PLSCW_ADDRESS | AD9954_RW_BIT_SET;
    DRV_SPI_WriteReadTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 1, &ad9954_driverData.SPI_DATA_RECEIVE, 5, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Store_PLSCW_Register(void)
{
//    ad9954_ddsData.PLSCW_REGISTER_VALUE = ad9954_driverData.SPI_DATA_RECEIVE[0] << 32 | ad9954_driverData.SPI_DATA_RECEIVE[1] << 24 | ad9954_driverData.SPI_DATA_RECEIVE[2] << 16 | ad9954_driverData.SPI_DATA_RECEIVE[3] << 8 | ad9954_driverData.SPI_DATA_RECEIVE[4];
}

void AD9954_DRIVER_Set_PLSCW_Register(uint8_t WORD_4, uint8_t WORD_3, uint8_t WORD_2, uint8_t WORD_1, uint8_t WORD_0)
{
    ad9954_driverData.SPI_DATA_TRANSMIT[0] = AD9954_PLSCW_ADDRESS & AD9954_RW_BIT_SET;
    ad9954_driverData.SPI_DATA_TRANSMIT[1] = WORD_4;
    ad9954_driverData.SPI_DATA_TRANSMIT[2] = WORD_3;
    ad9954_driverData.SPI_DATA_TRANSMIT[3] = WORD_2;
    ad9954_driverData.SPI_DATA_TRANSMIT[4] = WORD_1;
    ad9954_driverData.SPI_DATA_TRANSMIT[5] = WORD_0;
    DRV_SPI_WriteTransferAdd(ad9954_driverData.SPI_HANDLE, &ad9954_driverData.SPI_DATA_TRANSMIT, 6, &ad9954_driverData.SPI_TRANSFER_HANDLE);
}

void AD9954_DRIVER_Set_Frequency(uint32_t FREQUENCY)
{
    ad9954_settingsData.FREQUENCY = (FREQUENCY / 4000000000) * UINT32_MAX;
}

void AD9954_DRIVER_Set_Linear_Sweep(uint32_t POSITIVE_LINEAR_SWEEP, uint32_t NEGATIVE_LINEAR_SWEEP)
{
    ad9954_settingsData.POSITIVE_LINEAR_SWEEP = (POSITIVE_LINEAR_SWEEP / 400000000) * UINT32_MAX;
    ad9954_settingsData.NEGATIVE_LINEAR_SWEEP = (NEGATIVE_LINEAR_SWEEP / 400000000) * UINT32_MAX;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

void AD9954_DRIVER_Initialize(void)
{
    ad9954_driverData.state = AD9954_DRIVER_STATE_INIT;
    ad9954_driverData.SPI_HANDLE = DRV_HANDLE_INVALID;
    ad9954_driverData.SPI_TRANSFER_HANDLE = DRV_SPI_TRANSFER_HANDLE_INVALID;
    ad9954_driverData.SPI_TRANSFER_STATUS = false;
}

void AD9954_DRIVER_Tasks(void)
{
    switch (ad9954_driverData.state)
    {
        case AD9954_DRIVER_STATE_INIT:
        {
            ad9954_driverData.SPI_HANDLE = DRV_SPI_Open(DRV_SPI_INDEX_0, DRV_IO_INTENT_READWRITE);
            ad9954_driverData.state = AD9954_DRIVER_STATE_SPI_HANDLER_REGISTER;
            break;
        }

        case AD9954_DRIVER_STATE_SPI_HANDLER_REGISTER:
        {
            if (ad9954_driverData.SPI_HANDLE == DRV_HANDLE_INVALID)
            {
                ad9954_driverData.state = AD9954_DRIVER_STATE_ERROR;
            }
            else
            {
                DRV_SPI_TransferEventHandlerSet(ad9954_driverData.SPI_HANDLE, AD9954_DRIVER_SPI_Callback, (uintptr_t) & ad9954_driverData.SPI_TRANSFER_STATUS);
                ad9954_driverData.state = AD9954_DRIVER_STATE_SET_CFR1;
            }
            break;
        }

        case AD9954_DRIVER_STATE_SET_CFR1:
        {
            AD9954_DRIVER_Set_CFR1_Register(0b00000000, 0b00100000, 0b00000000, 0b00000000);
            TIMER_DRIVER_Start_Bus_TMR();
            ad9954_driverData.state = AD9954_DRIVER_STATE_SET_CFR1_ACK;
            break;
        }

        case AD9954_DRIVER_STATE_SET_CFR1_ACK:
        {
            if (ad9954_driverData.SPI_TRANSFER_HANDLE == DRV_SPI_TRANSFER_HANDLE_INVALID)
            {
                ad9954_driverData.state = AD9954_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ad9954_driverData.state = AD9954_DRIVER_STATE_TIMER_EXPIRED;
            }
            else
            {
                ad9954_driverData.state = AD9954_DRIVER_STATE_SET_CFR1_WAIT_FOR_TRANSFER;
            }
            break;
        }

        case AD9954_DRIVER_STATE_SET_CFR1_WAIT_FOR_TRANSFER:
        {
            if (ad9954_driverData.SPI_TRANSFER_STATUS == true)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ad9954_driverData.state = AD9954_DRIVER_STATE_IDLE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ad9954_driverData.state = AD9954_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case AD9954_DRIVER_STATE_IDLE:
        {
            if (AD9954_DRIVER_Get_Task_Start_Status() == true)
            {
                ad9954_driverData.state = AD9954_DRIVER_STATE_SET_FTW0;
            }
            break;
        }

        case AD9954_DRIVER_STATE_SET_FTW0:
        {
            AD9954_DRIVER_Set_FTW0_Register(0b00100111, 0b01000000, 0b00010011, 0b01100001);
            TIMER_DRIVER_Start_Bus_TMR();
            ad9954_driverData.state = AD9954_DRIVER_STATE_SET_FTW0_ACK;
            break;
        }

        case AD9954_DRIVER_STATE_SET_FTW0_ACK:
        {
            if (ad9954_driverData.SPI_TRANSFER_HANDLE == DRV_SPI_TRANSFER_HANDLE_INVALID)
            {
                ad9954_driverData.state = AD9954_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ad9954_driverData.state = AD9954_DRIVER_STATE_TIMER_EXPIRED;
            }
            else
            {
                ad9954_driverData.state = AD9954_DRIVER_STATE_SET_FTW0_WAIT_FOR_TRANSFER;
            }
            break;
        }

        case AD9954_DRIVER_STATE_SET_FTW0_WAIT_FOR_TRANSFER:
        {
            if (ad9954_driverData.SPI_TRANSFER_STATUS == true)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ad9954_driverData.state = AD9954_DRIVER_STATE_SET_FTW1;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ad9954_driverData.state = AD9954_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case AD9954_DRIVER_STATE_SET_FTW1:
        {
            AD9954_DRIVER_Set_FTW1_Register(0b00101000, 0b00100101, 0b10101110, 0b11100110);
            TIMER_DRIVER_Start_Bus_TMR();
            ad9954_driverData.state = AD9954_DRIVER_STATE_SET_FTW1_ACK;
            break;
        }

        case AD9954_DRIVER_STATE_SET_FTW1_ACK:
        {
            if (ad9954_driverData.SPI_TRANSFER_HANDLE == DRV_SPI_TRANSFER_HANDLE_INVALID)
            {
                ad9954_driverData.state = AD9954_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ad9954_driverData.state = AD9954_DRIVER_STATE_TIMER_EXPIRED;
            }
            else
            {
                ad9954_driverData.state = AD9954_DRIVER_STATE_SET_FTW1_WAIT_FOR_TRANSFER;
            }
            break;
        }

        case AD9954_DRIVER_STATE_SET_FTW1_WAIT_FOR_TRANSFER:
        {
            if (ad9954_driverData.SPI_TRANSFER_STATUS == true)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ad9954_driverData.state = AD9954_DRIVER_STATE_SET_NLSCW;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ad9954_driverData.state = AD9954_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case AD9954_DRIVER_STATE_SET_NLSCW:
        {
            AD9954_DRIVER_Set_NLSCW_Register(0b00000001, 0b00000000, 0b00000000, 0b00011011, 0b11110100);
            TIMER_DRIVER_Start_Bus_TMR();
            ad9954_driverData.state = AD9954_DRIVER_STATE_SET_NLSCW_ACK;
            break;
        }

        case AD9954_DRIVER_STATE_SET_NLSCW_ACK:
        {
            if (ad9954_driverData.SPI_TRANSFER_HANDLE == DRV_SPI_TRANSFER_HANDLE_INVALID)
            {
                ad9954_driverData.state = AD9954_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ad9954_driverData.state = AD9954_DRIVER_STATE_TIMER_EXPIRED;
            }
            else
            {
                ad9954_driverData.state = AD9954_DRIVER_STATE_SET_NLSCW_WAIT_FOR_TRANSFER;
            }
            break;
        }

        case AD9954_DRIVER_STATE_SET_NLSCW_WAIT_FOR_TRANSFER:
        {
            if (ad9954_driverData.SPI_TRANSFER_STATUS == true)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ad9954_driverData.state = AD9954_DRIVER_STATE_IDLE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ad9954_driverData.state = AD9954_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case AD9954_DRIVER_STATE_SET_PLSCW:
        {
            AD9954_DRIVER_Set_NLSCW_Register(0b00000001, 0b00000000, 0b00000001, 0b00011011, 0b11110100);
            TIMER_DRIVER_Start_Bus_TMR();
            ad9954_driverData.state = AD9954_DRIVER_STATE_SET_PLSCW_ACK;
            break;
        }

        case AD9954_DRIVER_STATE_SET_PLSCW_ACK:
        {
            if (ad9954_driverData.SPI_TRANSFER_HANDLE == DRV_SPI_TRANSFER_HANDLE_INVALID)
            {
                ad9954_driverData.state = AD9954_DRIVER_STATE_ERROR;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ad9954_driverData.state = AD9954_DRIVER_STATE_TIMER_EXPIRED;
            }
            else
            {
                ad9954_driverData.state = AD9954_DRIVER_STATE_SET_PLSCW_WAIT_FOR_TRANSFER;
            }
            break;
        }

        case AD9954_DRIVER_STATE_SET_PLSCW_WAIT_FOR_TRANSFER:
        {
            if (ad9954_driverData.SPI_TRANSFER_STATUS == true)
            {
                TIMER_DRIVER_Stop_Bus_TMR();
                ad9954_driverData.state = AD9954_DRIVER_STATE_IDLE;
            }
            else if (TIMER_DRIVER_Get_Bus_TMR_Status() == true)
            {
                TIMER_DRIVER_Set_Bus_TMR_Status(false);
                TIMER_DRIVER_Stop_Bus_TMR();
                ad9954_driverData.state = AD9954_DRIVER_STATE_TIMER_EXPIRED;
            }
            break;
        }

        case AD9954_DRIVER_STATE_TIMER_EXPIRED:
        {
            DRV_SPI_Close(ad9954_driverData.SPI_HANDLE);
            AD9954_DRIVER_Set_Task_Completed_Status(true);
            ad9954_driverData.state = AD9954_DRIVER_STATE_IDLE;
            break;
        }

        case AD9954_DRIVER_STATE_ERROR:
        {
            DRV_SPI_Close(ad9954_driverData.SPI_HANDLE);
            AD9954_DRIVER_Set_Task_Completed_Status(true);
            ad9954_driverData.state = AD9954_DRIVER_STATE_IDLE;
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