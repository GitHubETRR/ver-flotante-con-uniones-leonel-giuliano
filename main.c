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
char datoSigno(data_t);

int main(void) {
    data_t dataFloat;

    printf("Bienvenido al programa, se encarga de");

    ingresarDato(&dataFloat);
    char signText = datoSigno(dataFloat);
    printf("El numero se multiplica por 10^%i en notacion cientifica\n", dataFloat.EXPO);
    printf("La matriz del numero es: %i", dataFloat.mantiza);
    printf("El numero completo es: %c%i*10^%i",
        signText,
        dataFloat.mantiza,
        dataFloat.EXPO);

    return 0;
}

void ingresarDato(data_t *dataFloat) {
    printf("Inserte su float: ");
    scanf("%f", &dataFloat->varF);
}

char datoSigno(data_t dataFloat) {
    char signText = ' ';

    printf("El signo del numero es ");

    if (dataFloat.signo) {
        printf("negativo");
        signText = '-';
    }
    else printf("positivo");

    printf("\n");

    return signText;
}