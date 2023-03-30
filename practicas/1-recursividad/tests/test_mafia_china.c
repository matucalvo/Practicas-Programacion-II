#include <stdlib.h>
#include <assert.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"


int main() {
    imprimir_titulo("Tests para la mafia china");
    chinos(4); // Test propuesto
    printf("\n");
    chinos(0); //Test adicional
    printf("\n");
    chinos(1); //Test adicional
    printf("\n");
    chinos(10); //Test adicional
    printf("\n");
    chinos (15); //Test adicional
    printf("\n");
    return 0;
}
