#include "../practica_pilas.h"

#include "tipo_elemento.h"
#include "pilas/pilas.h"
#include "cadenas.h"
#include "pilas/util_pilas.h"
#include <stdio.h>
#include <assert.h>
#include "aserciones.h"
#include <stdlib.h>

void probar(Pila original, Pila esperada){
    Pila invertida = invertirPila(original);

    bool verificacion = compararPilas(invertida,esperada);

    printf("Pila invertida:\n");
    p_mostrar(invertida);

    printf("Pila esperada:\n");
    p_mostrar(esperada);

    assert(bool_true(verificacion));
}

int main() {
    imprimir_titulo("Tests para invertir pila");

    int numeros[] = {1, 6, 3, 7, 4, 8, 3};
    int invertida1[] = {3, 8, 4, 7, 3, 6, 1};

    Pila pila = crear_pila_desde_array(numeros,7);
    Pila invertida = crear_pila_desde_array(invertida1,7);

    probar(pila,invertida);

    return 0;
}
