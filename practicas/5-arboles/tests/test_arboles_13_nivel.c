#include <assert.h>
#include "aserciones.h"
#include "../practica_arboles.h"
#include "arboles/util_arboles.h"
#include "cadenas.h"

int main() {
    imprimir_titulo("Tests para nivel de árbol n-ario");
    ArbolBinario arbol = a_crear();

    TipoElemento te = te_crear(15);  // inserto raiz
    a_establecer_raiz(arbol, te);

    a_conectar_hi(arbol, a_raiz(arbol), te_crear(13));

    a_conectar_hi(arbol, hijo_izquierdo(a_raiz(arbol)), te_crear(10));
    a_conectar_hd(arbol, hijo_izquierdo(a_raiz(arbol)), te_crear(14));

    a_conectar_hi(arbol, hijo_izquierdo(hijo_izquierdo(a_raiz(arbol))), te_crear(7));
    a_conectar_hd(arbol, hijo_izquierdo(hijo_izquierdo(a_raiz(arbol))), te_crear(18));

    a_conectar_hd(arbol, hijo_derecho(hijo_izquierdo(a_raiz(arbol))), te_crear(16));

    a_conectar_hi(arbol, hijo_derecho(hijo_izquierdo(hijo_izquierdo(a_raiz(arbol)))), te_crear(3));
    a_conectar_hi(arbol, hijo_izquierdo(hijo_derecho(hijo_izquierdo(hijo_izquierdo(a_raiz(arbol))))), te_crear(26));

    a_conectar_hi(arbol, hijo_derecho(hijo_derecho(hijo_izquierdo(a_raiz(arbol)))), te_crear(5));
    a_conectar_hd(arbol, hijo_izquierdo(hijo_derecho(hijo_derecho(hijo_izquierdo(a_raiz(arbol))))), te_crear(8));
    a_conectar_hd(arbol, hijo_derecho(hijo_izquierdo(hijo_derecho(hijo_derecho(hijo_izquierdo(a_raiz(arbol)))))), te_crear(9));



    mostrar_arbol_binario_ascii(a_raiz(arbol));

    //printf("Nivel: %d\n", an_nivel(arbol, hijo_izquierdo(hijo_derecho(hijo_izquierdo(hijo_izquierdo(a_raiz(arbol)))))));

    ///////////////////////////

    ///////////////////////////////////////////////////

    ArbolBinario arbol1 = a_crear();

    TipoElemento te1 = te_crear(15);  // inserto raiz
    a_establecer_raiz(arbol1, te1);

    a_conectar_hi(arbol1, a_raiz(arbol1), te_crear(13));
    a_conectar_hd(arbol1, hijo_izquierdo(a_raiz(arbol1)), te_crear(14));
    a_conectar_hd(arbol1, hijo_derecho(hijo_izquierdo(a_raiz(arbol1))), te_crear(16));

    mostrar_arbol_binario_ascii(a_raiz(arbol1));
    printf("Nivel: %d", an_nivel(arbol1, hijo_izquierdo(a_raiz(arbol1))));

    return 0;
}
