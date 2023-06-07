#include <assert.h>
#include "aserciones.h"
#include "../practica_arboles.h"
#include "arboles/util_arboles.h"
#include "cadenas.h"

int main() {
    imprimir_titulo("Tests para equivalentes");
    ArbolBinario Arbol = a_crear();

    TipoElemento te = te_crear(10);

    a_establecer_raiz(Arbol, te);
    TipoElemento te1 = te_crear(5);
    a_conectar_hi(Arbol, a_raiz(Arbol), te1);
    TipoElemento te2 = te_crear(15);
    NodoArbol n = a_conectar_hd(Arbol, a_raiz(Arbol), te2);
    TipoElemento te3 = te_crear(20);
    a_conectar_hd(Arbol, n, te3);

    mostrar_arbol_binario_ascii(a_raiz(Arbol));
////////////////////////////////////////////////////////

    ArbolBinario Arbol1 = a_crear();

    TipoElemento tea2 = te_crear(10);

    a_establecer_raiz(Arbol1, tea2);
    TipoElemento te1a2 = te_crear(5);
    a_conectar_hi(Arbol1, a_raiz(Arbol1), te1a2);
    TipoElemento te2a2 = te_crear(15);
    NodoArbol n1 = a_conectar_hd(Arbol1, a_raiz(Arbol1), te2a2);
    TipoElemento te3a2 = te_crear(20);
    a_conectar_hd(Arbol1, n1, te3a2);

    

    mostrar_arbol_binario_ascii(a_raiz(Arbol1));

    printf("%d", a_equivalentes(Arbol,Arbol1));

    return 0;
}
