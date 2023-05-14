
#include <assert.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

int main() {
    imprimir_titulo("Tests para mismos elementos");

    int numeros[] = {1, 6, 3, 7, 4, 8, 3};
    int numeros1[] = {6, 6, 3, 6, 1, 7, 4, 8, 3};
    int numeros2[] = {6, 3, 7, 4, 8};
    Cola cola1 = crear_cola_desde_array(numeros,7);
    Cola cola2 = crear_cola_desde_array(numeros1,9);
    Cola cola3 = crear_cola_desde_array(numeros2,5);


    bool condicion = mismosElementos(cola3,cola1);

    printf(condicion ? "\ntrue\n" : "\nfalse\n");
    

    return 0;
}
