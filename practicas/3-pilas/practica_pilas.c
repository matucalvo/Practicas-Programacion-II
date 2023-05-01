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
}

void eliminarElemento(Pila p, int clave) {
}

void intercambiarElementos(Pila p, int pos1, int pos2) {
}

Pila copiar(Pila p) {
}

int contarElementos(Pila p) {
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
