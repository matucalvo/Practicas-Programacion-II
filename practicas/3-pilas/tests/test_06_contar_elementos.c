#include "../practica_pilas.h"

#include "tipo_elemento.h"
#include "pilas/pilas.h"
#include "cadenas.h"
#include "pilas/util_pilas.h"
#include <stdio.h>
#include <assert.h>
#include "aserciones.h"
#include <stdlib.h>

void probar(Pila original, int cantidadEsperada){
    int res = contarElementos(original);

    printf("Cantidad de elementos calculada: %d \n", res);

    printf("Cantidad de elementos esperada: %d", cantidadEsperada);


    assert(int_eq(res,cantidadEsperada));

}

int main() {
    imprimir_titulo("Tests para contar elementos");

    int numeros[] = {1, 6, 3, 7, 4, 8, 3};

    Pila pila = crear_pila_desde_array(numeros,7);

    probar(pila, 7);

    return 0;
}
