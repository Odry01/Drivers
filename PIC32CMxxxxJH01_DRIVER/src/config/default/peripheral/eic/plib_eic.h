/******************************************************************************* External Interrupt Controller (EIC) PLIB

  Company
    Microchip Technology Inc.

  File Name
    plib_eic.h

  Summary
    EIC PLIB Header File.

  Description
    This file defines the interface to the EIC peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:
    None.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

/* Guards against multiple inclusion */
#ifndef PLIB_EIC_H
#define PLIB_EIC_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/* This section lists the other files that are included in this file.
*/

#include "device.h"
#include <stdbool.h>
#include <stddef.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
/* The following data type definitions are used by the functions in this
    interface and should be considered part of it.
*/

/* EIC Pin Count */
#define EXTINT_COUNT                        (16U)

// *****************************************************************************
/* EIC Pins

  Summary:
    Identifies the available EIC pins.

  Description:
    This enumeration identifies all the available EIC pins. Not all pins will be
    implemented in a device. The pins described here are for documentation
    purposes only. The MHC will generate this enumeration with the enabled EIC
    pins only. The application should not use the constant value that are
    assigned to enumeration constants as this may vary between devices.

  Remarks:
    None.
*/


    /* External Interrupt Controller Pin 0 */
#define    EIC_PIN_0   (0U)

    /* External Interrupt Controller Pin 1 */
#define    EIC_PIN_1   (1U)

    /* External Interrupt Controller Pin 2 */
#define    EIC_PIN_2   (2U)

    /* External Interrupt Controller Pin 3 */
#define    EIC_PIN_3   (3U)

    /* External Interrupt Controller Pin 4 */
#define    EIC_PIN_4   (4U)

    /* External Interrupt Controller Pin 5 */
#define    EIC_PIN_5   (5U)

    /* External Interrupt Controller Pin 6 */
#define    EIC_PIN_6   (6U)

    /* External Interrupt Controller Pin 7 */
#define    EIC_PIN_7   (7U)

    /* External Interrupt Controller Pin 8 */
#define    EIC_PIN_8   (8U)

    /* External Interrupt Controller Pin 9 */
#define    EIC_PIN_9   (9U)

    /* External Interrupt Controller Pin 10 */
#define    EIC_PIN_10   (10U)

    /* External Interrupt Controller Pin 11 */
#define    EIC_PIN_11   (11U)

    /* External Interrupt Controller Pin 12 */
#define    EIC_PIN_12   (12U)

    /* External Interrupt Controller Pin 13 */
#define    EIC_PIN_13   (13U)

    /* External Interrupt Controller Pin 14 */
#define    EIC_PIN_14   (14U)

    /* External Interrupt Controller Pin 15 */
#define    EIC_PIN_15   (15U)

#define    EIC_PIN_MAX  (16U)

typedef uint16_t EIC_PIN;

// *****************************************************************************
/* EIC Interrupt Pin Callback Function Pointer Type

  Summary:
    Defines the data type and function signature of the EIC peripheral callback
    function.

  Description:
    This data type defines the function signature for the EIC peripheral
    callback function. The EIC peripheral will call back the client's function
    with this signature when an interrupt condition has been sensed on the pin.
    The EIC library allows the application to register a callback function for
    each enabled external interrupt.

  Function:
    void (*EIC_CALLBACK)(uintptr_t context )

  Precondition:
    EIC_Initialize must have been called for the given EIC
    peripheral instance and EIC_CallbackRegister must have been
    called to set the function to be called.

  Parameters:
    context - Allows the caller to provide a context value (usually a pointer
    to the callers context for multi-instance clients).

  Returns:
    None.

  Example:
    <code>

    void EIC_Pin0Callback (uintptr_t context)
    {
        This means an interrupt condition has been sensed on EIC Pin 0.
    }

    EIC_CallbackRegister(EIC_PIN_0, EIC_Pin0Callback, 0);
    </code>

  Remarks:
    None.
*/

typedef void (*EIC_CALLBACK) (uintptr_t context);

typedef struct
{
    /* External Interrupt Pin Callback Handler */
    EIC_CALLBACK    callback;

    /* External Interrupt Pin Client context */
    uintptr_t       context;

    /* External Interrupt Pin number */
    EIC_PIN         eicPinNo;

} EIC_CALLBACK_OBJ;


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************
/* The following functions make up the methods (set of possible operations) of
    this interface.
*/

// *****************************************************************************
/* Function:
    void EIC_Initialize (void);

  Summary:
    Initializes given instance of EIC peripheral.

  Description:
    This function initializes given instance of EIC peripheral of the device
    with the values configured in MHC GUI.

  Precondition:
    MHC GUI should be configured with the right values.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    EIC_Initialize();
    </code>

  Remarks:
    This function should only be called once during system initialization
    before any other EIC function is called.
*/

void EIC_Initialize (void);

// *****************************************************************************
/* Function:
    void EIC_InterruptEnable (EIC_PIN pin)

  Summary:
    Enables interrupts on a pin.

  Description
    This function enables interrupts on an external interrupt pin.
    When enabled, the interrupt pin sense will be configured as per the
    configuration set in MHC.

   Precondition:
    EIC_Initialize() function must have been called for the
    associated instance.

   Parameters:
    pin - EIC Pin number

   Returns:
    None

   Example:
    <code>
    EIC_Initialize();
    EIC_InterruptEnable(EIC_PIN_3);
    </code>

  Remarks:
    None.
*/
void EIC_InterruptEnable (EIC_PIN pin);

// *****************************************************************************
/* Function:
    void EIC_InterruptDisable (EIC_PIN pin)

  Summary:
    Disables interrupts on a pin.

  Description
    This function disables interrupts on an external interrupt pin.

   Precondition:
    EIC_Initialize() function must have been called for the
    associated instance.

   Parameters:
    pin - EIC Pin number.

   Returns:
    None

   Example:
    <code>
    EIC_Initialize();
    EIC_InterruptDisable(EIC_PIN_3);
    </code>

  Remarks:
    None.
*/

void EIC_InterruptDisable (EIC_PIN pin);

// *****************************************************************************
/* Function:
    void EIC_CallbackRegister (EIC_PIN pin, EIC_CALLBACK callback
                                            uintptr_t context);

  Summary:
    Registers the function to be called when an interrupt condition has been
    sensed on the pin.

  Description
    This function registers the callback function to be called when an interrupt
    condition has been sensed on the pin. A unique callback function can be
    registered for each pin.

    When an interrupt condition has been sensed on the pin, the library will
    call the registered callback function and will then clear the interrupt
    condition when the callback function exits.

  Precondition:
    EIC_Initialize() must have been called first for the associated
    instance.

  Parameters:
    pin - EIC Pin number

    callback - callback function pointer. Setting this to NULL will disable the
    callback feature.

    context - An application defined context value that will be passed to the
    callback function.

  Returns:
    None.

  Example:
    <code>
     Refer to the description of the EIC_CALLBACK data type for details on API
     usage.
    </code>

  Remarks:
    Context value can be set to NULL, if not required.
*/

void EIC_CallbackRegister(EIC_PIN pin, EIC_CALLBACK callback, uintptr_t context);



#ifdef __cplusplus // Provide C++ Compatibility
}
#endif
#endif /* PLIB_EIC_H */
