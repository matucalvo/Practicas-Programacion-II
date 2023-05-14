#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "colas.h"

static const int TAMANIO_MAXIMO = 100;

struct ColaRep {
    TipoElemento *valores;
    int frente;
    int final;
};

Cola c_crear() {
    Cola nueva_cola = (Cola) malloc(sizeof(struct ColaRep));
    nueva_cola->valores = calloc(TAMANIO_MAXIMO,sizeof(TipoElemento));
    nueva_cola->frente = 0;
    nueva_cola->final = 0;

    return nueva_cola;
}

bool c_es_llena(Cola cola) {
    return cola->final == TAMANIO_MAXIMO;
}

void c_encolar(Cola cola, TipoElemento elemento) {
    if (c_es_llena(cola)){
        return;
    }

    cola->final++;
    cola->valores[cola->final] = elemento;

    if (c_es_vacia(cola)){
        cola->frente = cola->final;
    }
}

TipoElemento c_desencolar(Cola cola) {
    if (c_es_vacia(cola)){
        return NULL;
    }

    TipoElemento te = cola->valores[cola->frente];

    for (int i=cola->frente; i<=(cola->final-1); i++) {
        cola->valores[i] = cola->valores[i + 1];
    }

    cola->final--;
    // Controlo la condicion de cola vacia
    if (cola->final < cola->frente) {
        cola->frente = 0;
        cola->final = 0;
    }

    return te;
}

bool c_es_vacia(Cola cola) {
    return cola->frente <= 0;
}

TipoElemento c_recuperar(Cola cola) {
    if (c_es_vacia(cola)){
        return NULL;
    }

    TipoElemento te = cola->valores[cola->frente];
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
    char *resultado = (char *) malloc(sizeof(char) * (cola->final * 10 + 3));
    strcpy(resultado, "[");
    for (int i = 0; i < cola->final; i++) {
        char num_str[10];
        sprintf(num_str, "%d", cola->valores[i]->clave);
        strcat(resultado, num_str);
        if (i < (cola->final - 1)) {
            strcat(resultado, ", ");
        }
    }
    strcat(resultado, "]");

    return resultado;
}
