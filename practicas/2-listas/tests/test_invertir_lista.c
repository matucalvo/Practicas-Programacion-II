#include <assert.h>
#include <stdlib.h>
#include "../practica_listas.h"

#include "listas/listas.h"
#include "util_listas.h"
#include "cadenas.h"
#include "aserciones.h"

void probar(Lista listaAinvertir, Lista ListaEsperada){
    Lista res = invertirLista(listaAinvertir);

    printf("Lista a invertir: ");
    l_mostrar(listaAinvertir);
    printf("\n");
    printf("Lista invertida: ");
    l_mostrar(res);
    
    


    assert(listas_eq(res, ListaEsperada));
}


int main() {
    imprimir_titulo("Tests para invertir listas");

    ///// CASO 1 //////
    int arreglo[] = {1,2,3,4,5};
    int arregloEsperado[] = {5,4,3,2,1};
    Lista listaAinvertir = crear_lista_desde_array(arreglo, 5);
    Lista listaInvertida = crear_lista_desde_array(arregloEsperado, 5);
    ///// CASO 2 //////
    int arreglo1[] = {6,7,8};
    int arregloEsperado1[] = {8,7,6};
    Lista listaAinvertir1 = crear_lista_desde_array(arreglo1, 3);
    Lista listaInvertida1 = crear_lista_desde_array(arregloEsperado1, 3);


 


    probar(listaAinvertir, listaInvertida);
    printf("\n");
    probar(listaAinvertir1, listaInvertida1);





    return 0;
}


