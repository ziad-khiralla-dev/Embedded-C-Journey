//@brief : Main program body for testing GPIO driver (Blink LED).

#include <stdio.h>
#include "./STD_TYPES.h"
#include "mcu_hw.h"
#include "gpio_interface.h"

// Simple delay function for demonstration
void delay(volatile u32 count) {
    while (count--) {
        __asm("nop"); // No operation, just wasting CPU cycles
    }
}

int main(void) {
   
    // STEP 1: System & Peripheral Clock Enable
    // (Normally done via RCC driver, but conceptually: enabling GPIOA Clock)
    // Note: In a complete project, you would write: RCC_voidEnablePeripheralClock(RCC_AHB1, RCC_EN_GPIOA);
    
    // STEP 2: Pin Configuration (Initialization)
    // Configure Pin 5 on Port A as an Output Pin
    GPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN5, GPIO_MODE_OUTPUT);
    
    // Configure Pin 5 output type as Push-Pull
    GPIO_voidSetPinOutputType(GPIO_PORTA, GPIO_PIN5, GPIO_OTYPE_PUSHPULL);

    // STEP 3: Super Loop (The Infinite Loop)
    // Continuous application logic execution
    while (1) {

        // Turn ON the LED (Set Pin 5 High)
        GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_HIGH);
        delay(1000000); // Wait / Delay

        // Turn OFF the LED (Set Pin 5 Low)
        GPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_LOW);
        delay(1000000); // Wait / Delay
        
    }

    return 0;
}