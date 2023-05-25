#include <stdlib.h>
#include <string.h>
#include "arbol-binario.h"
#include "nodo.h"

struct ArbolBinarioRep {
    NodoArbol raiz;
    int cantidad_elementos;
};

ArbolBinario a_crear() {
    ArbolBinario nuevo_arbol = (ArbolBinario) malloc(sizeof(struct ArbolBinarioRep));
    nuevo_arbol->raiz = NULL;
    nuevo_arbol->cantidad_elementos = 0;
    return nuevo_arbol;
}

bool a_es_vacio(ArbolBinario a) {
    return a->raiz == NULL;
}

int a_cantidad_elementos(ArbolBinario a) {
    return a->cantidad_elementos;
}

bool a_es_rama_nula(NodoArbol pa) {
    return pa == NULL;
}

NodoArbol a_raiz(ArbolBinario a) {
    return a->raiz;


}

NodoArbol a_establecer_raiz(ArbolBinario a, TipoElemento te) {
    if (a->raiz != NULL){
        printf("\nEl arbol ya tiene raiz\n");
        return a->raiz;
    }

    NodoArbol nuevo_nodo = malloc(sizeof(struct NodoArbolRep));
    nuevo_nodo = crear_nodo_arbol(te);
    a->raiz = nuevo_nodo;
    a->cantidad_elementos++;
    return nuevo_nodo;
}

NodoArbol a_conectar_hi(ArbolBinario a, NodoArbol pa, TipoElemento te) {
    // TODO Acá tenemos que chequear que la posición árbol efectivamente esté en el árbol
    if (pa == NULL){
        printf("Error\n");
        return NULL;
    }
    // TODO Chequeamos que la posición árbol no tenga ya la rama que están solicitando insertar
    if (pa->hi != NULL) {
        printf("Este nodo ya tiene un hijo izquierdo\n");
        return pa->hi;
        // TODO Deberíamos devolver error
    }

    NodoArbol nuevo_nodo = crear_nodo_arbol(te);
    pa->hi = nuevo_nodo;
    a->cantidad_elementos++;
    return nuevo_nodo;
}

NodoArbol a_conectar_hd(ArbolBinario a, NodoArbol pa, TipoElemento te) {
    // TODO Acá tenemos que chequear que la posición árbol efectivamente esté en el árbol
    if (pa == NULL){
        printf("Error\n");
        return NULL;
    }
    // TODO Chequeamos que la posición árbol no tenga ya la rama que están solicitando insertar
    if (pa->hd != NULL) {
        printf("Este nodo ya tiene un hijo izquierdo\n");
        return pa->hd;
        // TODO Deberíamos devolver error
    }

    NodoArbol nuevo_nodo = crear_nodo_arbol(te);
    pa->hd = nuevo_nodo;
    a->cantidad_elementos++;
    return nuevo_nodo;
}


