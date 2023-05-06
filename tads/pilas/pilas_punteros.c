#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "pilas.h"

struct Nodo {
    TipoElemento datos;
    struct Nodo *siguiente;
};

struct PilaRep {
    struct Nodo *tope;
};

Pila p_crear() {
    Pila nueva_pila = (Pila) malloc(sizeof(struct PilaRep));
    nueva_pila->tope = NULL;
    return nueva_pila;
}

void p_apilar(Pila pila, TipoElemento elemento) {
    struct Nodo *nuevo_nodo = malloc(sizeof(struct Nodo));
    nuevo_nodo->datos = elemento;
    nuevo_nodo->siguiente = pila->tope;
    pila->tope = nuevo_nodo;
}

TipoElemento p_desapilar(Pila pila) {
    struct Nodo *tope_actual = pila->tope;
    TipoElemento elemento = tope_actual->datos;
    pila->tope = tope_actual->siguiente;
    free(tope_actual);
    return elemento;
}

TipoElemento p_tope(Pila pila) {
    struct Nodo *tope_actual = pila->tope;
    return tope_actual->datos;
}

bool p_es_vacia(Pila pila) {
    return pila->tope == NULL;
}

//-----------------------------------------------------------
// Rutina interna que calcula los elementos de la pila
//-----------------------------------------------------------
int longitud(Pila pila) {
    int i = 0;
    struct Nodo *nodo = pila->tope;
    while (nodo != NULL) {
        i++;
        nodo = nodo->siguiente;
    }
    return i;
}

void p_mostrar(Pila pila) {
    Pila pila_aux = p_crear();
    TipoElemento te;



    //recorro la pila desapilandola y pasandosela a la auxiliar
    while (!p_es_vacia(pila)){
        te = p_desapilar(pila);
        printf("%d ", te->clave);
        p_apilar(pila_aux, te);
        printf("\n"); 

    }

    while (!p_es_vacia(pila_aux)){
        te = p_desapilar(pila_aux);
        p_apilar(pila, te);
    }
}

char *p_to_string(Pila pila) {
    int cantidad = longitud(pila);

    char *resultado = (char *) malloc(sizeof(char) * (cantidad * 10 + 3));
    strcpy(resultado, "[");
    struct Nodo *temp = pila->tope;
    int i = 0;
    while (temp != NULL) {
        char num_str[10];
        sprintf(num_str, "%d", temp->datos->clave);
        strcat(resultado, num_str);
        if (i < (cantidad - 1)) {
            strcat(resultado, ", ");
        }
        temp = temp->siguiente;
        i++;
    }
    strcat(resultado, "]");

    return resultado;
}