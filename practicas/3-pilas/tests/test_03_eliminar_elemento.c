#include "../practica_pilas.h"

#include "tipo_elemento.h"
#include "pilas/pilas.h"
#include "cadenas.h"
#include "pilas/util_pilas.h"
#include <assert.h>
#include "aserciones.h"
#include "pilas/util_pilas.h"
#include <stdlib.h>

void probar(Pila original, Pila esperada, int elemento){
    eliminarElemento(original,elemento);
    

    bool verificacion = compararPilas(original,esperada);

    printf("Pila original:\n");

    p_mostrar(original);

    printf("\nPila esperada:\n");
    p_mostrar(esperada);

    assert(bool_true(verificacion));


}

int main() {
    imprimir_titulo("Tests para eliminar elemento");
    int numeros[] = {1, 6, 3, 7, 4, 8, 3};
    Pila pila = crear_pila_desde_array(numeros,7);

    int numeros1[] = {1, 6, 3, 7, 4, 8};
    Pila pilaEsperada = crear_pila_desde_array(numeros1,6);

    int numeros2[] = {1, 6, 7, 4, 8};
    Pila pilaEsperada1 = crear_pila_desde_array(numeros2,5);

    int numeros3[] = {6, 7, 4, 8};
    Pila pilaEsperada2 = crear_pila_desde_array(numeros3,4);

    imprimir_titulo("CASO 1");
    probar(pila, pilaEsperada, 3);
    imprimir_titulo("CASO 2");
    probar(pila, pilaEsperada1, 3);
    imprimir_titulo("CASO 3");
    probar(pila, pilaEsperada2, 1);



    return 0;
}

