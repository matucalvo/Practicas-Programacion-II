#include "../practica_listas.h"

#include "tipo_elemento.h"
#include "listas/listas.h"
#include "cadenas.h"
#include "util_listas.h"
#include "aserciones.h"
#include <assert.h>
#include <stdlib.h>
<<<<<<< HEAD
=======
#include <stdio.h>

void probarListas(Lista l, int n, Lista listaEsperada){
    Lista l_multiplos = multiplos(l, n);

    printf("Lista suministrada: ");
    l_mostrar(l);

    printf("Lista multiplos: ");
    l_mostrar(l_multiplos);

    assert(listas_eq(l_multiplos, listaEsperada));

    free(l_multiplos);
}
>>>>>>> 749508f0d18d05b822eef7fa8119b7a8021b051e

int main() {
    imprimir_titulo("Tests para determinar si una lista es múltiplo de otra");

<<<<<<< HEAD
    int arreglo[] = {21, 18, 24, 3};
    Lista l = crear_lista_desde_array(arreglo,4);

    l_mostrar(multiplos(l,3));
=======
    int arreglo[] = {7, 6, 8, 1};
    Lista l = crear_lista_desde_array(arreglo, 4);

    int arreglo_esperado[] = {21, 18, 24, 3};
    Lista listaEsperada = crear_lista_desde_array(arreglo_esperado, 4);

    int multiplo = 3;

    probarListas(l, multiplo, listaEsperada);

    free(l);
    free(listaEsperada);
>>>>>>> 749508f0d18d05b822eef7fa8119b7a8021b051e

    return 0;
}
