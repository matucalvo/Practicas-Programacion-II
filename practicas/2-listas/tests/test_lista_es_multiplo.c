#include "../practica_listas.h"

#include "tipo_elemento.h"
#include "listas/listas.h"
#include "cadenas.h"
#include "util_listas.h"
#include "aserciones.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void probarListas(Lista l, int n, Lista listaEsperada){
    Lista l_multiplos = multiplos(l, n);

    printf("Lista suministrada: ");
    l_mostrar(l);

    printf("Lista multiplos: ");
    l_mostrar(l_multiplos);

    assert(l_multiplos, listaEsperada);

    free(l_multiplos);
}

int main() {
    imprimir_titulo("Tests para determinar si una lista es múltiplo de otra");

    return 0;
}
