#include "nodo.h"
#include "arbol-avl.h"

struct ArbolAVLRep {
    NodoArbol raiz;
    int cantidad_elementos;
};


NodoArbol avl_rotar_derecha(NodoArbol nodo);

NodoArbol avl_rotar_izquierda(NodoArbol nodo);

int avl_altura_izq(NodoArbol nodo);

int avl_altura_der(NodoArbol nodo);

int avl_max(int a, int b);

enum Balanceo {
    DESBALANCEADO_DERECHA,
    APENAS_DESBALANCEADO_DERECHA,
    BALANCEADO,
    APENAS_DESBALANCEADO_IZQUIERDA,
    DESBALANCEADO_IZQUIERDA
};

ArbolAVL avl_crear() {
    ArbolAVL nuevo_arbol = malloc(sizeof(struct ArbolAVLRep));
    nuevo_arbol->raiz = NULL;
    nuevo_arbol->cantidad_elementos = 0;
    return nuevo_arbol;
}

bool avl_es_vacio(ArbolAVL a) {
    return a->cantidad_elementos == 0;
}

int avl_cantidad_elementos(ArbolAVL a) {
    return a->cantidad_elementos;
}

NodoArbol avl_raiz(ArbolAVL a) {
    return a->raiz;
}

enum Balanceo avl_calcular_balanceo(NodoArbol nodo) {
    int diferenciaAltura = + avl_altura_izq(nodo) - avl_altura_der(nodo);
    switch (diferenciaAltura) {
        case -2:
            return DESBALANCEADO_DERECHA;
        case -1:
            return APENAS_DESBALANCEADO_DERECHA;
        case 1:
            return APENAS_DESBALANCEADO_IZQUIERDA;
        case 2:
            return DESBALANCEADO_IZQUIERDA;
        default:
            return BALANCEADO;
    }
}

NodoArbol avl_insertar_recursivo(ArbolAVL a, TipoElemento te, NodoArbol pa) {
    NodoArbol nuevo_nodo = crear_nodo_arbol(te);

    if (avl_es_vacio(a)){
        a->raiz = nuevo_nodo;
        a->cantidad_elementos++;
        return nuevo_nodo;
    }

    if (te->clave < recuperar_nodo_arbol(pa)->clave){
        if (hijo_izquierdo(pa) == NULL){
            pa->hi = nuevo_nodo;
            a->cantidad_elementos++;
        } else avl_insertar_recursivo(a, te, hijo_izquierdo(pa));
    }
    else if (te->clave > recuperar_nodo_arbol(pa)->clave) {
        if (hijo_derecho(pa) == NULL){
            pa->hd = nuevo_nodo;
            a->cantidad_elementos++;
        } else avl_insertar_recursivo(a, te, hijo_derecho(pa));
    } else printf("La clave ya se encuentra en el arbol\n");

    pa->altura = avl_max(avl_altura_izq(pa), avl_altura_der(pa)) ;   // guardo altura nodo
    enum Balanceo fe = avl_calcular_balanceo(pa);   // calculo fe

    if (fe == DESBALANCEADO_IZQUIERDA) {
        if (te->clave < pa->hi->datos->clave) {
            // Caso rotación derecha
            pa = avl_rotar_derecha(pa);
        } else {
            // Caso rotación izquierda-derecha
            pa->hi = avl_rotar_izquierda(pa->hi);
            return avl_rotar_derecha(pa);
        }
    }

    if (fe == DESBALANCEADO_DERECHA) {
        if (te->clave > pa->hd->datos->clave) {
            // Caso rotación izquierda
            pa = avl_rotar_izquierda(pa);
        } else {
            // Caso rotación derecha-izquierda
            pa->hd = avl_rotar_derecha(pa->hd);
            return avl_rotar_izquierda(pa);
        }
    }


    return nuevo_nodo;
}

void avl_insertar(ArbolAVL a, TipoElemento te) {
    avl_insertar_recursivo(a, te, avl_raiz(a));
}

NodoArbol avl_buscar_minimo(NodoArbol nodoArbol) {
}

NodoArbol avl_eliminar_recursivo(ArbolAVL arbol, NodoArbol nodoArbol, int claveABorrar) {
}

void avl_eliminar(ArbolAVL a, int claveABorrar) {
    a->raiz = avl_eliminar_recursivo(a, avl_raiz(a), claveABorrar);
}

TipoElemento avl_buscar_recursivo(NodoArbol nodoArbol, int clave) {
}

TipoElemento avl_buscar(ArbolAVL a, int clave) {
    return avl_buscar_recursivo(avl_raiz(a), clave);
}


////////////////////////////////////
///  Funciones para el balanceo  ///
////////////////////////////////////

int avl_altura_izq(NodoArbol nodo) {
    if (nodo->hi == NULL) {
        return -1;
    }
    return nodo->hi->altura;
}

int avl_altura_der(NodoArbol nodo) {
    if (nodo->hd == NULL) {
        return -1;
    }
    return nodo->hd->altura;
}

int avl_max(int a, int b) {
    return a > b ? a : b;
}

/**
 *  * Rotación izquierda
 *   a                                     b
 *  / \                                   / \
 * c   b  -> a.avl_rotar_izquierda() ->  a   e
 *    / \                               / \
 *   d   e                             c   d
 */
NodoArbol avl_rotar_izquierda(NodoArbol nodo) {
    NodoArbol otro = nodo->hd;
    nodo->hd = otro->hi;
    otro->hi = nodo;
    nodo->altura = avl_max(avl_altura_izq(nodo), avl_altura_der(nodo)) + 1;
    otro->altura = avl_max(avl_altura_der(otro), nodo->altura) + 1;

    return otro;
}

/** 
 * Rotación derecha
 *     b                                 a
 *    / \                               / \
 *   a   e -> b.avl_rotar_derecha() -> c   b
 *  / \                                   / \
 * c   d                                 d   e
 */
NodoArbol avl_rotar_derecha(NodoArbol nodo) {
    NodoArbol otro = nodo->hi;
    nodo->hi = otro->hd;
    otro->hd = nodo;
    nodo->altura = avl_max(avl_altura_izq(nodo), avl_altura_der(nodo)) + 1;
    otro->altura = avl_max(avl_altura_izq(otro), nodo->altura) + 1;

    return otro;
}
