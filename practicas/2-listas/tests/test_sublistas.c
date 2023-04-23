#include "../practica_listas.h"

#include "tipo_elemento.h"
#include "listas/listas.h"
#include "cadenas.h"
#include "util_listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "aserciones.h"

void probar (Lista l1, Lista l2, bool esperado){
    bool resultado = subLista(l1,l2);
    printf("%s\n", resultado==1?"Es sublista" : "No es sublista");
    assert(bool_eq(resultado,esperado));
}


int main() {
    imprimir_titulo("Tests para determinar si una lista es sublista de otra");
    int lista[] = {1, 2, 3, 4, 5, 6, 7};
    Lista l1 = crear_lista_desde_array(lista,7); // Se pasa el arreglo y su tamaño para crear la lista
    int sublista[] = {5, 1, 4, 6}; 
    Lista l2 = crear_lista_desde_array(sublista,4);
    int sublista2[] = {7, 4, 10};
    Lista l3 = crear_lista_desde_array(sublista2,3);

    probar(l1,l2,true);
    probar(l1,l3,false);

    free (l1);
    free (l2);
    free (l3);
    return 0;
}
