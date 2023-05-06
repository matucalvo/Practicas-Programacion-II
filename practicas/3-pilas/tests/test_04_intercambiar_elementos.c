#include "../practica_pilas.h"

#include "tipo_elemento.h"
#include "pilas/pilas.h"
#include "cadenas.h"
#include "pilas/util_pilas.h"
#include <assert.h>
#include "aserciones.h"
#include "pilas/util_pilas.h"
#include <stdlib.h>

void probar(Pila original, Pila esperada, int pos1, int pos2){
    intercambiarElementos(original,pos1,pos2);

    bool verificacion = compararPilas(original,esperada);

    printf("Pila original:\n");

    p_mostrar(original);

    printf("\nPila esperada:\n");
    p_mostrar(esperada);

    assert(bool_true(verificacion));
}


int main() {
    imprimir_titulo("Tests para intercambiar elementos");

    int numeros[] = {1, 6, 3, 7, 4, 8, 3};
    Pila pila = crear_pila_desde_array(numeros,7);

    int numeros1[] = {1, 8, 3, 7, 4, 6, 3};
    Pila pilaEsperada = crear_pila_desde_array(numeros1,7);

    int numeros2[] = {4, 8, 3, 7, 1, 6, 3};
    Pila pilaEsperada1 = crear_pila_desde_array(numeros2,7);

    imprimir_titulo("CASO 1");
    probar(pila, pilaEsperada, 2, 6);
    imprimir_titulo("CASO 2");
    probar(pila, pilaEsperada1, 1, 5);


    return 0;
}
