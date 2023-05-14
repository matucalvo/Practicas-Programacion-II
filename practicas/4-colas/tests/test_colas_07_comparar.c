
#include <assert.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

int main() {
    imprimir_titulo("Tests para comparar colas");
    int numeros[] = {1, 6, 3, 7, 4, 8, 3};
    int numeros1[] = {1, 6, 3, 7, 4, 8};
    int numeros2[] = {6, 1, 3, 7, 4, 8, 5};
    Cola cola = crear_cola_desde_array(numeros,7);
    Cola cola1 = crear_cola_desde_array(numeros,7);
    Cola cola2 = crear_cola_desde_array(numeros1,6);
    Cola cola3 = crear_cola_desde_array(numeros2,7);

    bool encontrado = comparar(cola,cola2);

    printf(encontrado ? "\ntrue\n" : "\nfalse\n");

    return 0;
}
