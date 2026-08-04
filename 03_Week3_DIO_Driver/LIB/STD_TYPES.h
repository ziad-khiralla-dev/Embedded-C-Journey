#ifndef STD_TYPES_H
#define STD_TYPES_H

// Unsigned Data Types (Positive only)
typedef unsigned char u8; // -------> 1 Byte : 0 to 255
typedef unsigned short int u16; // -> 2 Bytes : 0 to 65535
typedef unsigned long int u32; // --> 4 Bytes : 0 to 4294967295
typedef unsigned long long u64; // -> 8 Bytes

// Signed Data Types (Positive & Negative)
typedef signed char s8; // ---------> 1 Byte : -128 to 127
typedef signed short int s16; // ---> 2 Bytes : -32768 to 32767 
typedef signed long int s32; // ----> 4 Bytes : -2147483648 to 2147483647
typedef signed long long s64; // ---> 8 Bytes

// Float Data Types
typedef float f32;  // -------------> 4 Bytes
typedef double f64; // -------------> 8 Bytes

// Boolean Values
#define TRUE  1
#define FALSE 0

// NULL Pointer Definition
#ifndef NULL
#define NULL ((void*)0)
#endif

// Standard Error Status for Functions
typedef enum {
    OK,
    NOT_OK,
    NULL_POINTER
} ErrorStatus;

#endif