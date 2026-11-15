/**************************************************************************************************
@brief :
This file contains the interface for the GPIO driver,providing function prototypes and macros 
for configuring and controlling GPIO pins on the microcontroller.
**************************************************************************************************/ 

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "STD_TYPES.h"

// Port Identifiers
#define GPIO_PORTA      0U
#define GPIO_PORTB      1U
#define GPIO_PORTC      2U

// Pin Identifiers
#define GPIO_PIN0       0U
#define GPIO_PIN1       1U
#define GPIO_PIN2       2U
#define GPIO_PIN3       3U
#define GPIO_PIN4       4U
#define GPIO_PIN5       5U
#define GPIO_PIN6       6U
#define GPIO_PIN7       7U
#define GPIO_PIN8       8U
#define GPIO_PIN9       9U
#define GPIO_PIN10      10U
#define GPIO_PIN11      11U
#define GPIO_PIN12      12U
#define GPIO_PIN13      13U
#define GPIO_PIN14      14U
#define GPIO_PIN15      15U

// Pin Modes
#define GPIO_MODE_INPUT      0U
#define GPIO_MODE_OUTPUT     1U
#define GPIO_MODE_ALT_FUNC   2U
#define GPIO_MODE_ANALOG     3U

// Output Types
#define GPIO_OTYPE_PUSHPULL  0U
#define GPIO_OTYPE_OPENDRAIN 1U

// Output Speeds
#define GPIO_SPEED_LOW       0U
#define GPIO_SPEED_MEDIUM    1U
#define GPIO_SPEED_HIGH      2U
#define GPIO_SPEED_VERY_HIGH 3U

// Pin States (High / Low)
#define GPIO_HIGH            1U
#define GPIO_LOW             0U

// Public Function Prototypes

// @brief  Configure the mode of a specific pin (Input, Output, etc.).
// @param  Copy_u8Port: Port identifier (GPIO_PORTA, GPIO_PORTB, GPIO_PORTC).
// @param  Copy_u8Pin: Pin number (GPIO_PIN0 to GPIO_PIN15).
// @param  Copy_u8Mode: Desired mode configuration.
// @retval None
void GPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);

// @brief  Set the output type of a specific pin (Push-Pull or Open-Drain).
// @param  Copy_u8Port: Port identifier.
// @param  Copy_u8Pin: Pin number.
// @param  Copy_u8OType: Output type configuration.
// @retval None
void GPIO_voidSetPinOutputType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8OType);

// @brief  Set the output value of a specific pin (High or Low).
// @param  Copy_u8Port: Port identifier.
// @param  Copy_u8Pin: Pin number.
// @param  Copy_u8Value: Output value (GPIO_HIGH or GPIO_LOW).
// @retval None
void GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

// @brief  Read the logic level of a specific input pin.
// @param  Copy_u8Port: Port identifier.
//  @param  Copy_u8Pin: Pin number.
// @retval u8: The state of the pin (1 for High, 0 for Low).
u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

#endif // GPIO_INTERFACE_H