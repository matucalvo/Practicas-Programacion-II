#include "../practica_pilas.h"

#include "tipo_elemento.h"
#include "pilas/pilas.h"
#include "cadenas.h"
#include "pilas/util_pilas.h"

int main() {
    imprimir_titulo("Tests para copiar pila");

    int numeros[] = {1, 6, 3, 7, 4, 8, 3};

    Pila pila = crear_pila_desde_array(numeros,7);
    Pila copia = copiar(pila);

    p_mostrar(copia);

    return 0;
}
