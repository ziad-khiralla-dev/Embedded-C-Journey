// @brief : Implementation of GPIO driver functions for register manipulation.

#include "STD_TYPES.h"
#include "mcu_hw.h"
#include "gpio_interface.h"

// @brief  Configure the mode of a specific pin (Input, Output, etc.).
// @param  Copy_u8Port: Port identifier (GPIO_PORTA, GPIO_PORTB, GPIO_PORTC).
// @param  Copy_u8Pin: Pin number (GPIO_PIN0 to GPIO_PIN15).
// @param  Copy_u8Mode: Desired mode configuration.
// @retval None

void GPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode) {
    GPIO_RegDef_t *Local_pTempPort = NULL;

    // Select the appropriate port base address
    switch (Copy_u8Port) {
        case GPIO_PORTA:
            Local_pTempPort = GPIOA;
            break;
        case GPIO_PORTB:
            Local_pTempPort = GPIOB;
            break;
        case GPIO_PORTC:
            Local_pTempPort = GPIOC;
            break;
        default:
            // Invalid port, do nothing
            break;
    }

    if (Local_pTempPort != NULL) {
        // Each pin takes 2 bits in the MODER register
        // Clear the specific 2 bits first (Bit Masking)
        Local_pTempPort->MODER &= ~(0b11 << (Copy_u8Pin * 2));
        
        // Set the new mode value at the correct bit position
        Local_pTempPort->MODER |=  (Copy_u8Mode << (Copy_u8Pin * 2));
    }
}

// @brief  Set the output type of a specific pin (Push-Pull or Open-Drain).
// @param  Copy_u8Port: Port identifier.
// @param  Copy_u8Pin: Pin number.
// @param  Copy_u8OType: Output type configuration.
// @retval None

void GPIO_voidSetPinOutputType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8OType) {
    GPIO_RegDef_t *Local_pTempPort = NULL;

    switch (Copy_u8Port) {
        case GPIO_PORTA:
            Local_pTempPort = GPIOA;
            break;
        case GPIO_PORTB:
            Local_pTempPort = GPIOB;
            break;
        case GPIO_PORTC:
            Local_pTempPort = GPIOC;
            break;
        default:
            break;
    }

    if (Local_pTempPort != NULL) {
        // Each pin takes 1 bit in the OTYPER register
        Local_pTempPort->OTYPER &= ~(1 << Copy_u8Pin);
        Local_pTempPort->OTYPER |=  (Copy_u8OType << Copy_u8Pin);
    }
}

// @brief  Set the output value of a specific pin (High or Low).
// @param  Copy_u8Port: Port identifier.
// @param  Copy_u8Pin: Pin number.
// @param  Copy_u8Value: Output value (GPIO_HIGH or GPIO_LOW).
// @retval None

void GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value) {
    GPIO_RegDef_t *Local_pTempPort = NULL;

    switch (Copy_u8Port) {
        case GPIO_PORTA:
            Local_pTempPort = GPIOA;
            break;
        case GPIO_PORTB:
            Local_pTempPort = GPIOB;
            break;
        case GPIO_PORTC:
            Local_pTempPort = GPIOC;
            break;
        default:
            break;
    }

    if (Local_pTempPort != NULL) {
        if (Copy_u8Value == GPIO_HIGH) {
            // Set the bit in ODR to output High (1)
            Local_pTempPort->ODR |= (1 << Copy_u8Pin);
        } else {
            // Clear the bit in ODR to output Low (0)
            Local_pTempPort->ODR &= ~(1 << Copy_u8Pin);
        }
    }
}

// @brief  5. Read the logic level of a specific input pin.
// @param  Copy_u8Port: Port identifier.
// @param  Copy_u8Pin: Pin number.
// @retval u8: The state of the pin (1 for High, 0 for Low).

u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin) {
    GPIO_RegDef_t *Local_pTempPort = NULL;
    u8 Local_u8PinValue = 0;

    switch (Copy_u8Port) {
        case GPIO_PORTA:
            Local_pTempPort = GPIOA;
            break;
        case GPIO_PORTB:
            Local_pTempPort = GPIOB;
            break;
        case GPIO_PORTC:
            Local_pTempPort = GPIOC;
            break;
        default:
            break;
    }

    if (Local_pTempPort != NULL) {
        // Read from IDR, shift right by pin number, and mask with 1
        Local_u8PinValue = (u8)((Local_pTempPort->IDR >> Copy_u8Pin) & 0x01);
    }

    return Local_u8PinValue;
}