#include <assert.h>
#include "aserciones.h"
#include "../practica_arboles.h"
#include "arboles/util_arboles.h"
#include "cadenas.h"

int main() {
    imprimir_titulo("Tests para hojas en el mismo nivel");

    ArbolBinario Arbol = a_crear();

    TipoElemento te = te_crear(10);

    a_establecer_raiz(Arbol, te);
    TipoElemento te1 = te_crear(5);
    NodoArbol x = a_conectar_hi(Arbol, a_raiz(Arbol), te1);
    TipoElemento te2 = te_crear(15);
    NodoArbol n = a_conectar_hd(Arbol, a_raiz(Arbol), te2);
    TipoElemento te3 = te_crear(20);
    NodoArbol t = a_conectar_hd(Arbol, n, te3);
    TipoElemento te4 = te_crear(7);
    NodoArbol k = a_conectar_hd(Arbol,x,te4);
    TipoElemento te5 = te_crear(3);
    NodoArbol q = a_conectar_hi(Arbol,x,te5);
    TipoElemento te6 = te_crear(21);
    a_conectar_hd(Arbol,t,te6);
    TipoElemento te7 = te_crear(2);
    a_conectar_hi(Arbol,q,te7);
    TipoElemento te8 = te_crear(6);
    a_conectar_hi(Arbol,k,te8);

    mostrar_arbol_binario_ascii(a_raiz(Arbol));

   // printf("%d", nivel_nodo(a_raiz(Arbol), c, 1));

   printf("%d", a_hojas_mismo_nivel(Arbol));

    return 0;
}
