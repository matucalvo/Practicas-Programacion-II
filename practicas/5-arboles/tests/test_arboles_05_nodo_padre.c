#include <assert.h>
#include "aserciones.h"
#include "../practica_arboles.h"
#include "arboles/util_arboles.h"
#include "cadenas.h"

void probar(ArbolBinario arbol, NodoArbol nodo, NodoArbol nodoEsperado){
    NodoArbol res = a_nodo_padre(arbol, nodo);

    TipoElemento nodote = recuperar_nodo_arbol(nodo);
    printf("Elemento a buscar el padre: %d\n", nodote->clave);

    

    TipoElemento NodoResultado = recuperar_nodo_arbol(res);
    printf("Nodo padre resultante: %d\n", NodoResultado->clave);
    TipoElemento NodoEsperado = recuperar_nodo_arbol(nodoEsperado);
    printf("\nNodo padre esperado: %d\n", NodoEsperado->clave);

    assert(te_eq(NodoResultado, NodoEsperado));


}

int main() {
    imprimir_titulo("Tests para nodo padre");

    ArbolBinario Arbol = a_crear();

    TipoElemento te = te_crear(10);

    a_establecer_raiz(Arbol, te);
    TipoElemento te1 = te_crear(5);
    a_conectar_hi(Arbol, a_raiz(Arbol), te1);
    TipoElemento te2 = te_crear(15);
    NodoArbol n = a_conectar_hd(Arbol, a_raiz(Arbol), te2);
    TipoElemento te3 = te_crear(20);
    NodoArbol x = a_conectar_hd(Arbol, n, te3);
    TipoElemento te4 = te_crear(22);
    a_conectar_hd(Arbol, x, te4);

    probar(Arbol, x, n);

    mostrar_arbol_binario_ascii(a_raiz(Arbol));

    return 0;
}
