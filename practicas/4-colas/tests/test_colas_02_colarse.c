#include <assert.h>
#include <stdio.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

int main() {
    imprimir_titulo("Tests para colarse");
    int numeros[] = {1, 6, 3, 7, 4, 8, 3};
    Cola cola = crear_cola_desde_array(numeros,7);

    TipoElemento te = te_crear(20);
    c_mostrar(cola);
    printf("\n");
    insertarElemento(cola,te,5);
    te = te_crear(30);
    insertarElemento(cola,te,1);
    c_mostrar(cola);

    return 0;
}
