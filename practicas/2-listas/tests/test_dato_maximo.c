#include "../practica_listas.h"

#include "tipo_elemento.h"
#include "listas/listas.h"
#include "cadenas.h"
#include "util_listas.h"
#include "aserciones.h"
#include <assert.h>
#include <stdlib.h>

void probar(Lista l, int valorEsperado, int ocurrenciaEsperada){
    struct ElementoYOcurrencias elyocu;
    elyocu = mayorYOcurrencias(l);

    l_mostrar(l);
    printf("Mayor: %d; Ocurrencias: %d", elyocu.valor, elyocu.ocurrencias);

    assert(int_eq(elyocu.valor, valorEsperado));
    assert(int_eq(elyocu.ocurrencias, ocurrenciaEsperada));
}

int main() {
    imprimir_titulo("Tests para calcular el dato máximo y la cantidad de ocurrencias");

    int arreglo[] = {7, 6, 8, 7, 8, 8, 8, 8, 6};
    Lista l = crear_lista_desde_array(arreglo,9);
    int arreglo1[] = {1,2,3,4,5};
    Lista l1 = crear_lista_desde_array(arreglo1,5);

    probar(l, 8, 5);
    printf("\n");
    probar(l1, 5, 1);


    free(l);
    free(l1);



    return 0;
}
