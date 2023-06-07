#include <assert.h>
#include "aserciones.h"
#include "../practica_arboles.h"
#include "arboles/util_arboles.h"
#include "cadenas.h"


bool arbolLLeno_recursivo(ArbolBinario a, NodoArbol nodo, bool *condicion, int altura){
    if (nodo == NULL){
        return *condicion;
    }

    if (hijo_izquierdo(nodo) == NULL && hijo_derecho(nodo) == NULL){  //verificar que todas las hojas esten al mismo nivel
        if (a_nodo_nivel(a, nodo) != altura){
            *condicion = false;
        }
    } else if (hijo_izquierdo(nodo) == NULL || hijo_derecho(nodo) == NULL){
        *condicion = false;
    }

    arbolLLeno_recursivo(a, hijo_izquierdo(nodo), condicion, altura);
    arbolLLeno_recursivo(a, hijo_derecho(nodo), condicion, altura);

    return *condicion;

}

bool EsArbolLLeno(ArbolBinario arbol){
    int alturaA = alturaArbol(arbol);
    bool condicion = true;
    return arbolLLeno_recursivo(arbol, a_raiz(arbol), &condicion, alturaA);
}

int main() {
    imprimir_titulo("Tests para nodos terminales");

    ArbolBinario Arbol = a_crear();

    TipoElemento te = te_crear(10);

    a_establecer_raiz(Arbol, te);
    TipoElemento te1 = te_crear(5);
    a_conectar_hi(Arbol, a_raiz(Arbol), te1);
    TipoElemento te2 = te_crear(15);
    NodoArbol n = a_conectar_hd(Arbol, a_raiz(Arbol), te2);
    TipoElemento te3 = te_crear(20);
    a_conectar_hd(Arbol, n, te3);
    
    a_conectar_hi(Arbol, n, te_crear(13));
    a_conectar_hi(Arbol, hijo_izquierdo(a_raiz(Arbol)), te_crear(2));
    a_conectar_hd(Arbol, hijo_izquierdo(a_raiz(Arbol)), te_crear(7));

    mostrar_arbol_binario_ascii(a_raiz(Arbol));

    printf("Nodos terminales: ");
    l_mostrar(a_nodos_terminales(Arbol));

    EsArbolLLeno(Arbol);









    return 0;
}
