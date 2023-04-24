#include "../practica_listas.h"

#include "tipo_elemento.h"
#include "listas/listas.h"
#include "cadenas.h"
#include "util_listas.h"
#include "aserciones.h"
#include <assert.h>
#include <stdlib.h>

void probar(Lista l1, Lista l2, bool esperado){
    bool res = listaEsMultiplo(l1, l2);

    if (bool_eq(res,esperado)){
        if (res == true){
            printf("true \n");
        } else printf("false \n");
    }



    assert(bool_eq(res,esperado));

    
        

}

int main() {
    imprimir_titulo("Tests para retornar una lista con números múltiplos de un escalar");

    int arreglo1[] = {2, 5, 7, 3};
    Lista lista1 = crear_lista_desde_array(arreglo1, 4);
    int arreglo2[] = {8, 20, 28, 12};
    Lista lista2 = crear_lista_desde_array(arreglo2, 4);
    int arreglo3[] = {8, 21, 28, 12};
    Lista lista3 = crear_lista_desde_array(arreglo3, 4);

    probar(lista1,lista2,true);
    printf("\n");
    probar(lista1,lista3,false);


    free(lista1);
    free(lista2);
    free(lista3);


    return 0;
}

