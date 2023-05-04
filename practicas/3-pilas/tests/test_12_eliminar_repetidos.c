#include "../practica_pilas.h"

#include "tipo_elemento.h"
#include "pilas/pilas.h"
#include "cadenas.h"
#include <assert.h>
#include "aserciones.h"
#include <stdlib.h>


Pila crear_pila_desde_array(int *vector, int tamano) {
    Pila p = p_crear();

    for (int i = 0; i < tamano; i++) {
        p_apilar(p, te_crear(vector[i]));
    }

    return p;
}



int main() {
    imprimir_titulo("Tests para elementos en común");


     int numeros[] = {1, 2, 1, 3, 4, 5, 2, 1, 3, 5, 5};


    Pila pila = crear_pila_desde_array(numeros,11);

    Pila p = eliminarRepetidos(pila);
    p_mostrarConValor(p);

    return 0;
}
