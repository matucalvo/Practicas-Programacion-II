#include "../practica_listas.h"

#include "tipo_elemento.h"
#include "listas/listas.h"
#include "cadenas.h"
#include "util_listas.h"
#include "aserciones.h"
#include <assert.h>
#include <stdlib.h>

void probar(Lista l, int valorEsperado, int ordinalEsperado){
    struct ElementoYPosicion elypos;
    elypos = menorYPosicion(l);


    l_mostrar(l);
    printf("Menor: %d; Ordinal: %d", elypos.valor, elypos.ordinal);


    assert(int_eq(elypos.valor, valorEsperado));
    assert(int_eq(elypos.ordinal, ordinalEsperado));




}

int main() {
    imprimir_titulo("Tests para calcular el menor de los datos");

    
    int arreglo[] = {7,6,8};
    Lista l = crear_lista_desde_array(arreglo,3);

    probar(l,6,2);  // llamo a probar, pasandole lo esperado, el menor valor 6 y su posicion 2

    free(l);




    return 0;
}
