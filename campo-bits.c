#include <stdio.h>

#define BYTE 4

union {
    float valor;
    unsigned char byte[BYTE];
}var;

int main(void) {
    var.valor = 20;

    for(unsigned char i = BYTE; i > 0; i--) {
        printf("Byte %d: %x\n", i, var.byte[i-1]);
    }

    return 0;
}