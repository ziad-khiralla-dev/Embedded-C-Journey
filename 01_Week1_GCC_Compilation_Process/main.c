#include <stdio.h>

// A simple function to print status in Binary
void print_binary(unsigned char num) {
    printf("0b");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main(void) {
    printf("Hello! gcc compiler is working perfectly.\n");
    // Bitwise Test
    unsigned char status = 0x01; // -> 0b00000001
    status |= (1 << 3); // -> Set Bit 3
    printf("Bitwise Test Result in Hex: 0x%02X\n", status); // -> 0x09
    printf("Bitwise Test Result in Bin: ");
    print_binary(status); // -> 0b00001001
    return 0;
}