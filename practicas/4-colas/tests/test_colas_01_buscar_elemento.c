#include <assert.h>
#include <stdlib.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

int main() {
    imprimir_titulo("Tests para buscar elemento");

    int numeros[] = {1, 6, 3, 7, 4, 8, 3};
    Cola cola = crear_cola_desde_array(numeros,7);
    printf("\n");

    TipoElemento te = te_crear(3);
    bool encontrado = buscarElemento(cola,te);

    c_mostrar(cola);

    printf(encontrado ? "\ntrue\n" : "\nfalse\n");
    return 0;
}
