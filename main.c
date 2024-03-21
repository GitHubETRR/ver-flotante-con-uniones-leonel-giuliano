// Printear partes del flotante y pedir que sea insertado

#include <stdio.h>

#define signo format.sign
#define exponente format.exp
#define mantiza format.mant

#define MENU_INSERT 1
#define MENU_SIGN 2
#define MENU_EXPO 3
#define MENU_MANT 4
#define MENU_NUM 5
#define MENU_END 6

#define EXPO_INIT 127
#define EXPO exponente - EXPO_INIT

typedef union {
    struct {
        unsigned int mant : 23;
        unsigned int exp : 8;
        unsigned int sign : 1;
    }format;
    
    float varF;
}data_t;

void ingresarDato(data_t *);
void datoSigno(data_t);

int main(void) {
    data_t dataFloat;

    printf("Bienvenido al programa\n\n");

    ingresarDato(&dataFloat);
    datoSigno(dataFloat);
    printf("El numero se multiplica por 10^%u en notacion cientifica\n", dataFloat.EXPO);
    printf("La matriz del numero es: %X\n", dataFloat.mantiza);
    printf("El numero completo es %X%X%X\n",
        dataFloat.signo,
        dataFloat.exponente,
        dataFloat.mantiza);
    
    return 0;
}

void ingresarDato(data_t *dataFloat) {
    printf("Inserte su float: ");
    scanf("%f", &dataFloat->varF);
}

void datoSigno(data_t dataFloat) {
    printf("El signo del numero es ");

    if (dataFloat.signo) printf("negativo");
    else printf("positivo");

    printf("\n");
}