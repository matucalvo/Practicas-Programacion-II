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

void probar (Lista l1, Lista l2, int esperado){
    int resultado = compararListas(l1,l2);
    printf("La lista es: %s\n", resultado == MENOR? "MENOR" : resultado == MAYOR? "MAYOR": "IGUAL");
    assert(int_eq(esperado, resultado));

}

int main() {
    imprimir_titulo("Tests para comparación de listas");
    
    int arreglo1[] = {2, 5, 7, 3};
    Lista l1 = crear_lista_desde_array(arreglo1,4);
    int arreglo2[] = {8, 20, 20, 12};
    Lista l2 = crear_lista_desde_array(arreglo2,4);
    int arreglo3[] = {1, 6, 28, 2};
    Lista l3 = crear_lista_desde_array(arreglo3,4);

    // Test 1//
    probar (l1,l2,MENOR);
    // Test 2 //
    probar (l1,l3,IGUAL);
    // Test 3 //
    probar (l2,l3,MAYOR); 

    free (l1);
    free (l2);
    free (l3);

    return 0;
}
