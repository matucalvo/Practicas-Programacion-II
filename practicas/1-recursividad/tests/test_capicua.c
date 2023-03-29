#include <assert.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

int main() {
    imprimir_titulo("Tests para Capicua");

    printf("161 ==> %d \n", esCapicua(161));
    printf("2992 ==> %d \n", esCapicua(2992));
    printf("19341 ==> %d \n", esCapicua(19341));

    return 0;
}
