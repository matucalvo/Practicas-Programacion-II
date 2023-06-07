#include <assert.h>
#include "aserciones.h"
#include "../practica_arboles.h"
#include "arboles/util_arboles.h"
#include "cadenas.h"

int main() {
    imprimir_titulo("Tests para nodo altura rama");

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
    printf("Nivel: %d", a_nodo_altura_rama(Arbol, a_raiz(Arbol)));

    return 0;
}
