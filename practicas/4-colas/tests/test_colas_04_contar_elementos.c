#include <assert.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

void probar(Cola cola, int esperado){
    int res = tamanoCola(cola);
    printf("Cantidad de elementos de la cola: %d", res);

    assert(int_eq(res,esperado));
}

int main() {
    imprimir_titulo("Tests para contar elementos");

    int numeros[] = {1, 6, 3, 7, 4, 8, 3};
    Cola cola = crear_cola_desde_array(numeros,7);

    probar(cola,7);

    return 0;
}
