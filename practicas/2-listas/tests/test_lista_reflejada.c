#include "../practica_listas.h"

#include "tipo_elemento.h"
#include "listas/listas.h"
#include "cadenas.h"
#include "util_listas.h"
#include "aserciones.h"
#include <assert.h>
#include <stdlib.h>

void probarTrue(Lista l, Lista listaEsperadaInvertidaTrue){
    Lista res = reflejarLista(l,true);

    printf("                   TRUE  \n");

    printf("Lista a reflejar: ");
    l_mostrar(l);
    printf("\n");
    printf("Lista reflejada: ");
    l_mostrar(res);

    assert(listas_eq(res, listaEsperadaInvertidaTrue));

    free(res);

}

void probarFalse(Lista l, Lista listaEsperadaInvertidaFalse){
    Lista res = reflejarLista(l,false);

    printf("                   FALSE  \n");

    printf("Lista a reflejar: ");
    l_mostrar(l);
    printf("\n");
    printf("Lista reflejada: ");
    l_mostrar(res);

    assert(listas_eq(res, listaEsperadaInvertidaFalse));

    free(res);

}



int main() {
    imprimir_titulo("Tests para reflejar o espejar una lista");


    int arreglo[] = {6,7,8};
    int arregloInvertidoTrue[] = {6, 7, 8, 8, 7, 6};
    int arregloInvertidoFalse[] = {6, 7, 8, 7, 6};

    Lista l = crear_lista_desde_array(arreglo,3);
    Lista l_invertidaTrue = crear_lista_desde_array(arregloInvertidoTrue,6);
    Lista l_invertidaFalse = crear_lista_desde_array(arregloInvertidoFalse,5);

    probarTrue(l,l_invertidaTrue);
    printf("\n");
    probarFalse(l,l_invertidaFalse);

    free(l);
    free(l_invertidaFalse);
    free(l_invertidaTrue);


    

    return 0;
}
