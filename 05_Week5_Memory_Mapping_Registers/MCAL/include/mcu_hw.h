// @brief : This file contains the memory mapping of the microcontroller's hardware registers.

#ifndef MCU_HW_H
#define MCU_HW_H

// Include standard data types library
#include "STD_TYPES.h"

// Base Addresses for Memories and Buses
#define PERIPH_BASE          (0x40000000UL) // Base address of all peripherals 
#define AHB1PERIPH_OFFSET    (0x00020000UL) // Offset for AHB1 bus peripherals
#define AHB1PERIPH_BASE      (PERIPH_BASE + AHB1PERIPH_OFFSET)

// Base Addresses for GPIO Peripherals
#define GPIOA_BASE           (AHB1PERIPH_BASE + 0x0000UL) // GPIO Port A Base Address
#define GPIOB_BASE           (AHB1PERIPH_BASE + 0x0400UL) // GPIO Port B Base Address
#define GPIOC_BASE           (AHB1PERIPH_BASE + 0x0800UL) // GPIO Port C Base Address

// GPIO Register Definition Structure
// Maps the exact memory layout of GPIO registers as per Reference Manual
typedef struct {
    volatile u32 MODER;    // GPIO port mode register
    volatile u32 OTYPER;   // GPIO port output type register
    volatile u32 OSPEEDR;  // GPIO port output speed register
    volatile u32 PUPDR;    // GPIO port pull-up/pull-down register
    volatile u32 IDR;      // GPIO port input data register
    volatile u32 ODR;      // GPIO port output data register
    volatile u32 BSRR;     // GPIO port bit set/reset register
    volatile u32 LCKR;     // GPIO port configuration lock register
    volatile u32 AFR[2];   // GPIO alternate function registers (AFRL, AFRH)
} GPIO_RegDef_t;

// Peripheral Definitions (Pointer Casting to Struct)
// Allows accessing registers using dot notation like: GPIOA->ODR = 1;
#define GPIOA ((GPIO_RegDef_t *)GPIOA_BASE)
#define GPIOB ((GPIO_RegDef_t *)GPIOB_BASE)
#define GPIOC ((GPIO_RegDef_t *)GPIOC_BASE)

#endif // MCU_HW_H 