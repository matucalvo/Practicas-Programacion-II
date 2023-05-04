#include "../practica_pilas.h"

#include "tipo_elemento.h"
#include "pilas/pilas.h"
#include "cadenas.h"
#include <stdio.h>
#include <assert.h>
#include "aserciones.h"
#include "pilas/util_pilas.h"
#include <stdlib.h>

void probar(Pila pila1, Pila pila2, bool esperado){
    bool res = compararPilas(pila1,pila2);

    assert(bool_eq(res, esperado));

}

int main() {
    imprimir_titulo("Tests para comparar pilas");

    int numeros[] = {1, 6, 3, 7, 4, 8, 3};
    int numeros1[] = {6, 1, 3, 7, 4, 8, 3};
    int numeros2[] = {5, 6, 3, 7, 4, 8, 3};
    Pila pila1 = crear_pila_desde_array(numeros,7);
    Pila pila2 = crear_pila_desde_array(numeros,7);
    Pila pila3 = crear_pila_desde_array(numeros1,7);
    Pila pila4 = crear_pila_desde_array(numeros2,7);
    

    probar(pila1,pila2,true);
    probar(pila2,pila1,true);
    probar(pila1,pila3,false);
    probar(pila1,pila4,false);
    probar(pila2,pila3,false);
    probar(pila3,pila4,false);


    printf("Verificacion de que las pilas no fueron destruidas:\n");
    p_mostrar(pila1);
    p_mostrar(pila2);
    p_mostrar(pila3);
    p_mostrar(pila4);

    free(pila1);
    free(pila2);
    free(pila3);
    free(pila4);

    

    return 0;
}
