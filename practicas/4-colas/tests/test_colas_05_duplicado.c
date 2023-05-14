#include <assert.h>
#include <stdio.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

int main() {
    imprimir_titulo("Tests para duplicar cola");

    int numeros[] = {1, 6, 3, 7, 4, 8, 3};
    Cola cola = crear_cola_desde_array(numeros,7);
    Cola copia1 = copia(cola);

    c_mostrar(cola);
    c_mostrar(copia1);

    return 0;
}
