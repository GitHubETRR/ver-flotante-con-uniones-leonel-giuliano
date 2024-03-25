#include <stdio.h>

#define DESPLAZAMIENTO sizeof(varF) / sizeof(*pfloat) - 1
/*
    Sirve para que el codigo funcione aunque se cambie el tipo de variable
    del pointer, ya comprobados con 'char' o 'short/long int'
*/

void ingresarDato(float *);

int main(void) {
    float varF;
    unsigned char *pfloat = &varF;
    pfloat += DESPLAZAMIENTO;

    ingresarDato(&varF);
    printf("El numero en hexadecimal es: 0x");

    for (unsigned char i = 0; i <= DESPLAZAMIENTO; i++) {
        printf("%X", *pfloat--);
    }
}

void ingresarDato(float *varF) {
    printf("Inserte un float: ");
    scanf("%f", varF);
}