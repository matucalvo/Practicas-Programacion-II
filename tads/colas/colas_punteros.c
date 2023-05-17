#include "colas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static const int TAMANIO_MAXIMO = 20;

struct Nodo {
    TipoElemento datos;
    struct Nodo *siguiente;
};

struct ColaRep {
    struct Nodo *frente;
    struct Nodo *final;
};

int longitud(Cola cola) {
    int i = 0;
    struct Nodo *nodo = cola->frente;
    while (nodo != NULL) {
        i++;
        nodo = nodo->siguiente;
    }
    return i;
}

bool c_es_llena(Cola cola){
    return (longitud(cola) == TAMANIO_MAXIMO);
}

bool c_es_vacia(Cola cola){
    return (cola->frente == NULL);
}

Cola c_crear(){
    Cola nueva_cola = malloc(sizeof(struct ColaRep));
    nueva_cola->final = NULL;
    nueva_cola->frente = NULL;
    return nueva_cola;
}

void c_encolar(Cola cola, TipoElemento elemento){
    if (c_es_llena(cola)){
        return;
    }

    struct Nodo *nuevo_nodo = malloc(sizeof(struct Nodo));
    nuevo_nodo->datos = elemento;
    nuevo_nodo->siguiente = NULL;

    if (c_es_vacia(cola)){
        cola->frente = nuevo_nodo;
    } else cola->final->siguiente = nuevo_nodo;

    cola->final = nuevo_nodo;
}

TipoElemento c_desencolar(Cola cola){
    if (c_es_vacia(cola)){
        return NULL;
    }

    struct Nodo *inicio = cola->frente;
    TipoElemento te = inicio->datos;
    cola->frente = inicio->siguiente;

    free(inicio);
    return te;
}

TipoElemento c_recuperar(Cola cola){
    if (c_es_vacia(cola)){
        return NULL;
    }

    TipoElemento te = cola->frente->datos;
    return te;
}

void c_mostrar(Cola cola){
    if (c_es_vacia(cola)){
        printf("Cola vacia\n");
        return;
    }

    Cola caux = c_crear();
    TipoElemento te;

    while(!c_es_vacia(cola)){
        te = c_desencolar(cola);
        printf("%d ", te->clave);
        c_encolar(caux,te);
    }

    while(!c_es_vacia(caux)){
        te = c_desencolar(caux);
        c_encolar(cola, te);
    }
    printf("\n");
}


char *c_to_string(Cola cola) {
    int cantidad = longitud(cola);

    char *resultado = (char *) malloc(sizeof(char) * (cantidad * 10 + 3));
    strcpy(resultado, "[");
    struct Nodo *temp = cola->frente;
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
