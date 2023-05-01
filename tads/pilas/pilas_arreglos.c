#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "pilas.h"

static const int TAMANIO_MAXIMO = 100;

struct PilaRep {
    TipoElemento *valores;
    unsigned int tope;
};

Pila p_crear() {
    Pila nueva_pila = (Pila) malloc(sizeof( struct PilaRep));
    nueva_pila->valores = calloc(TAMANIO_MAXIMO,sizeof(TipoElemento));
    nueva_pila->tope = 0;

    return nueva_pila;

}

bool p_es_llena(Pila pila) {
    return (pila->tope == TAMANIO_MAXIMO);
}

void p_apilar(Pila pila, TipoElemento elemento) {
    if (p_es_llena(pila)){
        return;
    }

    pila->valores[pila->tope] = elemento;
    pila->tope++;
}

TipoElemento p_desapilar(Pila pila) {
    if (p_es_vacia(pila)){
        return;
    }


    
    TipoElemento te = pila->valores[pila->tope-1];
    pila->tope--;

    return te;

}

TipoElemento p_tope(Pila pila) {
    if (p_es_vacia(pila)){
        return;
    }

    return pila->valores[pila->tope-1];
}

bool p_es_vacia(Pila pila) {
    return (pila->tope == 0);
}

void p_mostrar(Pila pila) {
    if (p_es_vacia(pila)){
        return;
    }

    Pila pila_aux = p_crear();
    TipoElemento te;

    printf("Elementos de la pila: \n");

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
    char *resultado = (char *) malloc(sizeof(char) * (pila->tope * 10 + 3));
    strcpy(resultado, "[");
    for (int i = 0; i < pila->tope; i++) {
        char num_str[10];
        sprintf(num_str, "%d", pila->valores[i]->clave);
        strcat(resultado, num_str);
        if (i < (pila->tope - 1)) {
            strcat(resultado, ", ");
        }
    }
    strcat(resultado, "]");

    return resultado;
}