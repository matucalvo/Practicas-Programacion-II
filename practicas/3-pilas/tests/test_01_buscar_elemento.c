#include "../practica_pilas.h"

#include "tipo_elemento.h"
#include "pilas/pilas.h"
#include "cadenas.h"
#include <stdio.h>
#include <assert.h>
#include "aserciones.h"



Pila crear_pila_desde_array(int *vector, int tamano) {
    Pila p = p_crear();

    for (int i = 0; i < tamano; i++) {
        p_apilar(p, te_crear(vector[i]));
    }

    return p;
}

void probar (Pila p, TipoElemento te, bool Esperado){
    bool res = buscarElemento(p,te);
    
    printf("Clave a buscar: %d \n", te->clave);
    p_mostrar(p);



    assert(bool_eq(res, Esperado));
}



int main() {
    imprimir_titulo("Tests para buscar elemento");
    

    
    int numeros[] = {1, 6, 3, 7, 4, 8, 3};

    Pila pila = crear_pila_desde_array(numeros,7);
    TipoElemento te = te_crear(1);
    probar(pila,te,true);
    te = te_crear(13);
    printf("\n");
    probar(pila,te,false);

    

    
    

    return 0;
}
