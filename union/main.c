#include <stdio.h>

union numeros{
    float var;
    unsigned char varByte[4];
}numeros_1;

int main(void) {
    scanf("%f", &numeros_1.var);

    for (short int i = 3; i >= 0; i--) {
        printf("%x", numeros.varByte[i]);
    }

    return 0;
}