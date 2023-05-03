#include "../practica_pilas.h"

#include "tipo_elemento.h"
#include "pilas/pilas.h"
#include "cadenas.h"

Pila crear_pila_desde_array(int *vector, int tamano) {
    Pila p = p_crear();

    for (int i = 0; i < tamano; i++) {
        p_apilar(p, te_crear(vector[i]));
    }

    return p;
}

int main() {
    imprimir_titulo("Tests para intercambiar elementos");

    int numeros[] = {1, 6, 3, 7, 4, 8, 3};

    Pila pila = crear_pila_desde_array(numeros,7);

    intercambiarElementos(pila, 2, 6);
    intercambiarElementos(pila, 1, 5);
    p_mostrar(pila);


    return 0;
}
