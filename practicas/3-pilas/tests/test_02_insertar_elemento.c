#include "../practica_pilas.h"

#include "tipo_elemento.h"
#include "pilas/pilas.h"
#include "cadenas.h"
#include "pilas/util_pilas.h"
#include <assert.h>
#include "aserciones.h"
#include "pilas/util_pilas.h"
#include <stdlib.h>

void probar(Pila original, Pila esperada, TipoElemento elemento, int posicion){
    insertarElemento(original,elemento,posicion);

    bool verificacion = compararPilas(original,esperada);

    printf("Pila original:\n");

    p_mostrar(original);

    printf("\nPila esperada:\n");
    p_mostrar(esperada);

    assert(bool_true(verificacion));


}

int main() {
    imprimir_titulo("Tests para insertar elemento");
    int numeros[] = {1, 6, 13, 3, 7, 4, 8, 3};
    Pila pila = crear_pila_desde_array(numeros,8);

    int numeros1[] = {1, 6, 13, 3, 20, 7, 4, 8, 3};
    Pila pilaEsperada = crear_pila_desde_array(numeros1,9);

    int numeros2[] = {30, 1, 6, 13, 3, 20, 7, 4, 8, 3};
    Pila pilaEsperada1 = crear_pila_desde_array(numeros2,10);

    imprimir_titulo("CASO 1");
    TipoElemento te = te_crear(20);
    probar(pila, pilaEsperada, te, 5);
    imprimir_titulo("CASO 2");
    te = te_crear(30);
    probar(pila, pilaEsperada1, te, 1);



    return 0;
}
