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
void menu(data_t);

int main(void) {
    data_t dataFloat;

    printf("Bienvenido al programa, se encarga de");

    menu(dataFloat);

    return 0;
}

void ingresarDato(data_t *dataFloat) {
    printf("Inserte su float: ");
    scanf("%f", &dataFloat->varF);
}

void menu(data_t dataFloat) {
    unsigned char option;

    printf("Inserte una opcion: ");
    do {
        scanf("%c", &option);

        if (option > MENU_END) printf("Por favor, inserte una opcion valida: ");
    } while (option > MENU_END);

    while (option != MENU_END) {
        switch (option) {
            case MENU_INSERT:
                ingresarDato(&dataFloat);
                break;

            case MENU_SIGN:
                printf("El signo del numero insertado es ");

                if(dataFloat.signo) printf("negativo");
                else printf("positivo");

                break;

            case MENU_EXPO:
                printf("El numero en notacion cinetifica se multiplica por 10^%i",
                    dataFloat.EXPO);
                break;

            case MENU_MANT:
                printf("La mantiza del numero es: %i", dataFloat.mantiza);
                break;

            case MENU_NUM:
                unsigned char signoText = (dataFloat.signo) '-' : '';

                printf("El numero es: %c%i*10^%i",
                    signoText,
                    dataFloat.mantiza,
                    dataFloat.EXPO);
                break;
        }
    }

    printf("Hasta luego!");
}