#include "arbol-binario-busqueda.h"
#include "nodo.h"

struct ArbolBinarioBusquedaRep {
    NodoArbol raiz;
    int cantidad_elementos;
};

ArbolBinarioBusqueda abb_crear() {
    ArbolBinarioBusqueda nuevo_arbol = malloc(sizeof(struct ArbolBinarioBusquedaRep));
    nuevo_arbol->raiz = NULL;
    nuevo_arbol->cantidad_elementos = 0;
    return nuevo_arbol;
}

bool abb_es_vacio(ArbolBinarioBusqueda a) {
    return a->cantidad_elementos == 0;
}

int abb_cantidad_elementos(ArbolBinarioBusqueda a) {
    return a->cantidad_elementos;
}

NodoArbol abb_raiz(ArbolBinarioBusqueda a) {
    return a->raiz;
}


NodoArbol abb_insertar_recursivo(ArbolBinarioBusqueda a, NodoArbol pa, TipoElemento te) {

    NodoArbol nuevo_nodo = crear_nodo_arbol(te);

    if (abb_es_vacio(a)){
        a->raiz = nuevo_nodo;
        a->cantidad_elementos++;
        return nuevo_nodo;
    }

    if (te->clave < recuperar_nodo_arbol(pa)->clave){
        if (hijo_izquierdo(pa) == NULL){
            pa->hi = nuevo_nodo;
            a->cantidad_elementos++;
        } else abb_insertar_recursivo(a, hijo_izquierdo(pa),te);
    }
    else if (te->clave > recuperar_nodo_arbol(pa)->clave) {
        if (hijo_derecho(pa) == NULL){
            pa->hd = nuevo_nodo;
            a->cantidad_elementos++;
        } else abb_insertar_recursivo(a, hijo_derecho(pa),te);
    } else printf("La clave ya se encuentra en el arbol\n");
    
    return nuevo_nodo;
}

void abb_insertar(ArbolBinarioBusqueda a, TipoElemento te) {
    abb_insertar_recursivo(a, abb_raiz(a), te);
}

NodoArbol abb_buscar_minimo(NodoArbol nodoArbol) {
    NodoArbol actual = nodoArbol;

    while (actual && actual->hi != NULL)
        actual = actual->hi;

    return actual;
}

NodoArbol abb_eliminar_recursivo(ArbolBinarioBusqueda arbol, NodoArbol root, int claveABorrar) {
    if (root == NULL){
        return root;
    }
    

    if (claveABorrar > recuperar_nodo_arbol(root)->clave ){
        root->hd = abb_eliminar_recursivo(arbol,hijo_derecho(root), claveABorrar);
    } else if (claveABorrar < recuperar_nodo_arbol(root)->clave){
        root->hi = abb_eliminar_recursivo(arbol,hijo_izquierdo(root), claveABorrar);
    }


    if (recuperar_nodo_arbol(root)->clave == claveABorrar){
        arbol->cantidad_elementos--;

        if(hijo_izquierdo(root) != NULL && hijo_derecho(root) != NULL){    
            NodoArbol aux = abb_buscar_minimo(hijo_derecho(root));
            root->datos->clave = aux->datos->clave;
            root->datos->valor = aux->datos->valor;

            arbol->cantidad_elementos++; //para compensar

            root->hd = abb_eliminar_recursivo(arbol, hijo_derecho(root), aux->datos->clave);
    }   else if(hijo_izquierdo(root) == NULL && hijo_derecho(root) == NULL){ 
        root = NULL;

    }   else if(hijo_izquierdo(root) == NULL || hijo_derecho(root) == NULL){  // si tiene un solo hijo
        if (hijo_izquierdo(root) != NULL){
            root = hijo_izquierdo(root);
        } else {
            root = hijo_derecho(root);
        }
    }
    }



    return root;

}

void abb_eliminar(ArbolBinarioBusqueda a, int claveABorrar) {
    a->raiz = abb_eliminar_recursivo(a, abb_raiz(a), claveABorrar);
}

TipoElemento abb_buscar_recursivo(NodoArbol nodoArbol, int clave) {
    if (nodoArbol == NULL){
        return NULL;
    }

    TipoElemento te;

    if (clave > recuperar_nodo_arbol(nodoArbol)->clave){
        abb_buscar_recursivo(hijo_derecho(nodoArbol), clave);
    } else if (clave < recuperar_nodo_arbol(nodoArbol)->clave){
        abb_buscar_recursivo(hijo_izquierdo(nodoArbol), clave);
    } else te = recuperar_nodo_arbol(nodoArbol);

    return te;
}

TipoElemento abb_buscar(ArbolBinarioBusqueda a, int clave) {
    return abb_buscar_recursivo(abb_raiz(a), clave);
}
