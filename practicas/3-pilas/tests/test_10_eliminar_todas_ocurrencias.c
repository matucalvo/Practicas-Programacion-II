#include "../practica_pilas.h"

#include "tipo_elemento.h"
#include "pilas/pilas.h"
#include "cadenas.h"
#include <assert.h>
#include "aserciones.h"
#include "pilas/util_pilas.h"
#include <stdlib.h>

void probar(Pila pila , Pila esperada, int numero){
    Pila res = eliminarTodasOcurrencias(pila,numero);

    bool verificacion = compararPilas(res,esperada);

    p_mostrar(res);
    p_mostrar(esperada);

    

    assert(bool_true(verificacion));

}

int main() {
    imprimir_titulo("Tests para eliminar todas las ocurrencias");

    int numeros[] = {1, 5, 7, 1, 3, 1, 8};
    int numerosEsperados[] = {5, 7, 3, 8};
    int numerosEsperados1[] = {1, 5, 7, 1, 3, 1};


    Pila pila = crear_pila_desde_array(numeros,7);
    Pila pilaEsperada = crear_pila_desde_array(numerosEsperados,4);
    Pila pilaEsperada1 = crear_pila_desde_array(numerosEsperados1,6);

    probar(pila, pilaEsperada, 1);

    printf("---------------------------------------------------------\n");


    probar(pila, pilaEsperada1, 8);

    destruir_pila(pila);
    destruir_pila(pilaEsperada);
    destruir_pila(pilaEsperada1);

    return 0;
}
