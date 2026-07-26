#include <stdio.h>
#include "STD_TYPES.h" // Calling STD_TYPES.h File
#include "BIT_MATH.h" // Calling BIT_MATH.h File

// A simple function to print reg in Binary

void printBinary(u8 num) {
        for(s8 i = 7; i >=0 ;i--) {
            printf("%d", (num >> i) & 1);
            if(i == 4) {
                printf(" ");
            }    
        }
    }

int main(void) {

    // Testing STD_TYPES.h File

    printf("\n---> 1.Testing STD_TYPES.h Data Types\n\n");
    
    printf("[ Unsigned Types ]\n");
    printf("Size of u8  : %d Byte(s)\n", (int)sizeof(u8)); // ----> 1
    printf("Size of u16 : %d Byte(s)\n", (int)sizeof(u16)); // ---> 2
    printf("Size of u32 : %d Byte(s)\n", (int)sizeof(u32)); // ---> 4
    printf("Size of u64 : %d Byte(s)\n\n", (int)sizeof(u64)); // -> 8
    
    printf("[ Signed Types ]\n");
    printf("Size of s8  : %d Byte(s)\n", (int)sizeof(s8)); // ----> 1
    printf("Size of s16 : %d Byte(s)\n", (int)sizeof(s16)); // ---> 2
    printf("Size of s32 : %d Byte(s)\n", (int)sizeof(s32)); // ---> 4
    printf("Size of s64 : %d Byte(s)\n\n", (int)sizeof(s64)); // -> 8
    
    printf("[ Float Types ]\n");
    printf("Size of f32 : %d Byte(s)\n", (int)sizeof(f32)); // ---> 4
    printf("Size of f64 : %d Byte(s)\n\n", (int)sizeof(f64)); // -> 8
    
    printf("[ Macros & Enums ]\n");
    printf("TRUE value  : %d\n", TRUE); // -----------------------> 1
    printf("FALSE value : %d\n\n", FALSE); // --------------------> 0
    
    ErrorStatus status = OK;
    if(status == OK) {
        printf("ErrorStatus Enum Working Perfectly !\n\n");
    }
    
    printf("====================================");

    // Testing BIT_MATH.h File

    printf("\n\n---> 2.Testing BIT_MATH.h\n\n");

    u8 reg = 0; // -----------------------------------------------> reg in binary: 0000 0000

    printf("Start Value        : ");
    printBinary(reg); // -----------------------------------------> 0000 0000
    printf("\n");
    
    printf("1. SET_BIT(3)      : ");
    SET_BIT(reg, 3);
    printBinary(reg); // -----------------------------------------> 0000 1000
    printf("\n");
    
    printf("2. TOG_BIT(0)      : ");
    TOG_BIT(reg, 0);
    printBinary(reg); // -----------------------------------------> 0000 1001
    printf("\n");
    
    u8 b2 = GET_BIT(reg, 2);
    u8 b3 = GET_BIT(reg, 3);
    printf("3. GET_BIT(2)      = %d\n", b2); // ------------------> 0
    printf("   GET_BIT(3)      = %d\n", b3); // ------------------> 1
    
    printf("4. CLR_BIT(3)      : ");
    CLR_BIT(reg, 3);
    printBinary(reg); // -----------------------------------------> 0000 0001
    printf("\n");
    
    printf("5. WRITE_BIT(5, 1) : ");
    WRITE_BIT(reg, 5, 1);
    printBinary(reg); // -----------------------------------------> 0010 0001
    printf("\n");

    printf("6. ROR(1)          : ");
    ROR(reg, 1);
    printBinary(reg); // -----------------------------------------> 1001 0000
    printf("\n");
    
    printf("7. ROL(1)          : ");
    ROL(reg, 1);
    printBinary(reg); // -----------------------------------------> 0010 0001
    printf("\n\n");

    return 0;

}