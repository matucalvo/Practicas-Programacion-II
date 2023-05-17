#include <assert.h>
#include <stdlib.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

void probar(Cola cola, bool esperado, TipoElemento te){
    bool res = buscarElemento(cola,te);

    printf(res ? "\ntrue\n" : "\nfalse\n");

    assert(bool_eq(res,esperado));

}

int main() {
    imprimir_titulo("Tests para buscar elemento");

    int numeros[] = {1, 6, 3, 7, 4, 8, 3};
    Cola cola = crear_cola_desde_array(numeros,7);
    

    TipoElemento te = te_crear(3);

    probar(cola, true, te);

    destruir_cola(cola);
    

    
    return 0;
}
