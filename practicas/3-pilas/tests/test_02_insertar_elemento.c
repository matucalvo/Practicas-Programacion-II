#include "../practica_pilas.h"

#include "tipo_elemento.h"
#include "pilas/pilas.h"
#include "cadenas.h"
#include "pilas/util_pilas.h"

int main() {
    imprimir_titulo("Tests para insertar elemento");
    int numeros[] = {1, 6, 13, 3, 7, 4, 8, 3};

    Pila pila = crear_pila_desde_array(numeros,8);

    
    TipoElemento te = te_crear(20);
    insertarElemento(pila, te, 5);
    p_mostrar(pila);

    te = te_crear(30);
    insertarElemento(pila, te, 1);
    p_mostrar(pila);


    return 0;
}
