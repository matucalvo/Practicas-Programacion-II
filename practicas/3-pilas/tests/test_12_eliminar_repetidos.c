#include "../practica_pilas.h"

#include "tipo_elemento.h"
#include "pilas/pilas.h"
#include "cadenas.h"
#include <assert.h>
#include "aserciones.h"
#include <stdlib.h>
#include "pilas/util_pilas.h"

bool compararPilasValores(Pila p1, Pila p2) {
    Pila pilaAux = p_crear();
    TipoElemento te, tep1, tep2;
    int i = 0;
    bool condicion = true;
    


    if (longitudPila(p1) != longitudPila(p2)){
        return false;
    }

    while (!p_es_vacia(p1)){             // pregunto solo por 1, pq si llega a este if es pq son iguales las longitudes
        tep1 = p_desapilar(p1);
        tep2 = p_desapilar(p2);
        p_apilar(pilaAux,tep1);
        p_apilar(pilaAux,tep2);


        if ((tep1->clave != tep2->clave) && (tep1->valor != tep2->clave)){
            condicion = false;
        } 
    }

    while(!p_es_vacia(pilaAux)){
        i++;
        if (i % 2 != 0){
            te = p_desapilar(pilaAux);         // reconstruyo las pilas
            p_apilar(p2, te);
        } else {
            te = p_desapilar(pilaAux);
            p_apilar(p1,te);
        }

    }

    invertirMismaPila(p1);
    invertirMismaPila(p2);

    return condicion;

}


Pila crear_pila_desde_array_valores(int *vectorClaves, int *vectorValores, int tamano) {
    Pila p = p_crear();

    for (int i = 0; i < tamano; i++) {
        int *valor = malloc(sizeof(int));
        *valor = vectorValores[i];
        p_apilar(p, te_crear_con_valor(vectorClaves[i], valor));
    }

    return p;
}

void probar(Pila esperada, Pila real, bool condicionEsperada){
    Pila res = eliminarRepetidos(invertirPila(real));
    bool condicion = compararPilasValores(res,esperada);

    p_mostrarConValor(res);

    assert(bool_eq(condicion, condicionEsperada));





}



int main() {
    imprimir_titulo("Tests para elementos en común");


     int numeros[] = {1, 2, 1, 3, 4, 5, 2, 1, 3, 5, 5};
     //valores para pila original
     Pila pila = crear_pila_desde_array(numeros,11);
     
     int numeros1[] = {1,2,3,4,5};
     int valores[] = {3,2,2,1,3};
     //valores para pila esperada
     Pila esperada = crear_pila_desde_array_valores(numeros1,valores,5);

    //pruebo si son iguales
    probar(esperada,pila,true);


    

    return 0;
}
