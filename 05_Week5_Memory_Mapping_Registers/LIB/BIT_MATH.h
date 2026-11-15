#ifndef BIT_MATH_H
#define BIT_MATH_H

// Set bit to 1
#define SET_BIT(REG, BIT) ((REG)|= (1U << (BIT)))

// Clear bit to 0
#define CLR_BIT(REG, BIT) ((REG) &= ~(1U << (BIT)))

// Toogle bit state
#define TOG_BIT(REG, BIT) ((REG) ^= (1U << (BIT)))

// Get bit value ( 0 or 1 )
#define GET_BIT(REG, BIT) (((REG) >> (BIT)) & 1U)

// Write specific value ( 0 or 1 ) to a bit
#define WRITE_BIT(REG, BIT, VAL) ((VAL) ? SET_BIT(REG, BIT) : CLR_BIT(REG, BIT))

// Rotate Right ( Circular Shift Right )
#define ROR(REG, NUM_BITS) ((REG) = ((REG) >> (NUM_BITS)) | ((REG) << ((sizeof(REG) * 8) - (NUM_BITS))))

// Rotate Left ( Circular Shift Left )
#define ROL(REG, NUM_BITS) ((REG) = ((REG) << (NUM_BITS)) | ((REG) >> ((sizeof(REG) * 8) - (NUM_BITS))))

#endif