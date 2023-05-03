#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "practica_pilas.h"
#include "tipo_elemento.h"
#include "pilas/pilas.h"


//// FUNCIONES AUXILIARES ////

void intercambiarP(Pila pila1, Pila pila2){
    TipoElemento te;

    while (!p_es_vacia(pila1)){
        te = p_desapilar(pila1);
        p_apilar(pila2, te);
    }
}


int longitudPila(Pila pila){
    int i = 0;
    Pila pilaAux = p_crear();
    TipoElemento te;

    while(!p_es_vacia(pila)){
        te = p_desapilar(pila);
        p_apilar(pilaAux,te);
        i++;
    }

    intercambiarP(pilaAux,pila);

    return i;
}



////////////////////////////////////////

bool buscarElemento(Pila p, TipoElemento e){
    bool condicion = false;
    TipoElemento te;
    Pila pilanew = p_crear();


    while(!p_es_vacia(p) && !condicion){

        te = p_desapilar(p);
        p_apilar(pilanew, te);  //guardo los elementos de la pila en otra pila auxiliar

        if (e->clave == te->clave){
            condicion = true;
        }
    }

    intercambiarP(pilanew, p);   //vuelgo a cargar la pila original


    return condicion;
}

void insertarElemento(Pila p, TipoElemento e, int pos) {
    Pila pilaAux = p_crear();
    TipoElemento te;

    int posicion = (longitudPila(p) - pos) + 1;

    for (int i = 1; i <= posicion; i++)
    {
        te = p_desapilar(p);   // desapilo hasta posicion
        p_apilar(pilaAux,te);   // lo guardo en otra pila para no perder los elementos
    }

    p_apilar(p,e);   // inserto el nuevo elemento

    while (!p_es_vacia(pilaAux)){
        te = p_desapilar(pilaAux);   // vuelvo a cargar la pila
        p_apilar(p,te);
    }



}

void eliminarElemento(Pila p, int clave) {
    Pila pilaAux = p_crear();
    TipoElemento te;
    bool condicion = true;

    while (!p_es_vacia(p) && condicion){
        te = p_desapilar(p);
        if (te->clave != clave){
            p_apilar(pilaAux,te);
        } else condicion = false;
    }

    intercambiarP(pilaAux,p);

}

void intercambiarElementos(Pila p, int pos1, int pos2) {
    Pila pilaAux = p_crear();
    TipoElemento te, tePos1, tePos2;
    int posicion1 = (longitudPila(p) - pos1)+1;
    int posicion2 = (longitudPila(p) - pos2)+1;
    int i = 0;

    while (!p_es_vacia(p)){
        i++;
        if (i == posicion1){
            tePos1 = p_desapilar(p);
        } else if (i == posicion2){
            tePos2 = p_desapilar(p);   
        }
        else{
        te = p_desapilar(p);
        p_apilar(pilaAux,te);
        }
    }

    intercambiarP(pilaAux,p);
    insertarElemento(p,tePos2,pos1);
    insertarElemento(p,tePos1,pos2);
    
}

Pila copiar(Pila p) {
    Pila pilaAux = p_crear();
    Pila copia = p_crear();
    TipoElemento te;

    while(!p_es_vacia(p)){
        te = p_desapilar(p);
        p_apilar(pilaAux,te);
    }

    intercambiarP(pilaAux,copia);

    return copia;


}

int contarElementos(Pila p) {
     int i = 0;
    Pila pilaAux = p_crear();
    TipoElemento te;

    while(!p_es_vacia(p)){
        te = p_desapilar(p);
        p_apilar(pilaAux,te);
        i++;
    }

    intercambiarP(pilaAux,p);

    return i;
}

bool compararPilas(Pila p1, Pila p2) {
    
}

char* cambioDeBase(int numero, int base) {
}

Pila invertirPila(Pila p) {
}

Pila eliminarTodasOcurrencias(Pila p, int clave) {
}

Pila elementosEnComun(Pila p1, Pila p2) {
}

Pila eliminarRepetidos(Pila p) {
}
