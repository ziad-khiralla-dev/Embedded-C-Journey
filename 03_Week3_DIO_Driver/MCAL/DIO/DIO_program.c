#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"

u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction) {

    // A variable to check the ErrorState
    u8 Local_u8ErrorState = 0; // 0 --> OK / 1 --> Error

    // Check that pin number is right ( 0 -> 7 )
    if (Copy_u8Pin <= DIO_u8_PIN7) {
        // If Direction is OUTPUT
        if (Copy_u8Direction == DIO_u8_PIN_OUTPUT) {
            switch (Copy_u8Port) {
                case DIO_u8_PORTA: SET_BIT(DDRA_REG, Copy_u8Pin); break;
                case DIO_u8_PORTB: SET_BIT(DDRB_REG, Copy_u8Pin); break;
                case DIO_u8_PORTC: SET_BIT(DDRC_REG, Copy_u8Pin); break;
                case DIO_u8_PORTD: SET_BIT(DDRD_REG, Copy_u8Pin); break;
                default: Local_u8ErrorState = 1; break; // Pin number is wrong
            }
        } 
        // If Direction is INPUT
        else if (Copy_u8Direction == DIO_u8_PIN_INPUT) {
            switch (Copy_u8Port) {
                case DIO_u8_PORTA: CLR_BIT(DDRA_REG, Copy_u8Pin); break;
                case DIO_u8_PORTB: CLR_BIT(DDRB_REG, Copy_u8Pin); break;
                case DIO_u8_PORTC: CLR_BIT(DDRC_REG, Copy_u8Pin); break;
                case DIO_u8_PORTD: CLR_BIT(DDRD_REG, Copy_u8Pin); break;
                default: Local_u8ErrorState = 1; break; // Pin number is wrong
            }
        } else {
            Local_u8ErrorState = 1; // Direction is wrong
        }
    } else {
        Local_u8ErrorState = 1; // Pin number is more than 7
    }
    return Local_u8ErrorState;
}

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value) {

    // A variable to check the ErrorState
    u8 Local_u8ErrorState = 0; // 0 --> OK / 1 --> Error

    // Check that pin number is right ( 0 -> 7 )
    if (Copy_u8Pin <= DIO_u8_PIN7) {
        // If Value is 1 (HIGH)
        if (Copy_u8Value == DIO_u8_PIN_HIGH) {
            switch (Copy_u8Port) {
                case DIO_u8_PORTA: SET_BIT(PORTA_REG, Copy_u8Pin); break;
                case DIO_u8_PORTB: SET_BIT(PORTB_REG, Copy_u8Pin); break;
                case DIO_u8_PORTC: SET_BIT(PORTC_REG, Copy_u8Pin); break;
                case DIO_u8_PORTD: SET_BIT(PORTD_REG, Copy_u8Pin); break;
                default: Local_u8ErrorState = 1; break; // Port number is wrong
            }
        } 
        // If Value is 0 (LOW)
        else if (Copy_u8Value == DIO_u8_PIN_LOW) {
            switch (Copy_u8Port) {
                case DIO_u8_PORTA: CLR_BIT(PORTA_REG, Copy_u8Pin); break;
                case DIO_u8_PORTB: CLR_BIT(PORTB_REG, Copy_u8Pin); break;
                case DIO_u8_PORTC: CLR_BIT(PORTC_REG, Copy_u8Pin); break;
                case DIO_u8_PORTD: CLR_BIT(PORTD_REG, Copy_u8Pin); break;
                default: Local_u8ErrorState = 1; break; // Port number is wrong
            }
        } else {
            Local_u8ErrorState = 1; // Value is wrong
        }
    } else {
        Local_u8ErrorState = 1; // Pin number is more than 7
    }
    return Local_u8ErrorState;
}

u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8Value) {

    // A variable to check the ErrorState
    u8 Local_u8ErrorState = 0; // 0 --> OK / 1 --> Error

    // Check that Pointer is not NULL
    if (Copy_pu8Value != NULL) {
        // Check that pin number is right ( 0 -> 7 )
        if (Copy_u8Pin <= DIO_u8_PIN7) {

            switch (Copy_u8Port) {
                case DIO_u8_PORTA: *Copy_pu8Value = GET_BIT(PINA_REG, Copy_u8Pin); break;
                case DIO_u8_PORTB: *Copy_pu8Value = GET_BIT(PINB_REG, Copy_u8Pin); break;
                case DIO_u8_PORTC: *Copy_pu8Value = GET_BIT(PINC_REG, Copy_u8Pin); break;
                case DIO_u8_PORTD: *Copy_pu8Value = GET_BIT(PIND_REG, Copy_u8Pin); break;
                default: Local_u8ErrorState = 1; break; // Port number is wrong
            }

        } else {
            Local_u8ErrorState = 1; // Pin number is more than 7
        }

    } else {
        Local_u8ErrorState = 1; // Pointer is NULL
    }
    return Local_u8ErrorState;
}

u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction) {

    // A variable to check the ErrorState
    u8 Local_u8ErrorState = 0; // 0 --> OK / 1 --> Error

    switch (Copy_u8Port) {
        case DIO_u8_PORTA: DDRA_REG = Copy_u8Direction; break;
        case DIO_u8_PORTB: DDRB_REG = Copy_u8Direction; break;
        case DIO_u8_PORTC: DDRC_REG = Copy_u8Direction; break;
        case DIO_u8_PORTD: DDRD_REG = Copy_u8Direction; break;
        default: Local_u8ErrorState = 1; break; // Port number is wrong
    }

    return Local_u8ErrorState;
}

u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value) {

    // A variable to check the ErrorState
    u8 Local_u8ErrorState = 0; // 0 --> OK / 1 --> Error

    switch (Copy_u8Port) {
        case DIO_u8_PORTA: PORTA_REG = Copy_u8Value; break;
        case DIO_u8_PORTB: PORTB_REG = Copy_u8Value; break;
        case DIO_u8_PORTC: PORTC_REG = Copy_u8Value; break;
        case DIO_u8_PORTD: PORTD_REG = Copy_u8Value; break;
        default: Local_u8ErrorState = 1; break; // Port number is wrong
    }

    return Local_u8ErrorState;
}
