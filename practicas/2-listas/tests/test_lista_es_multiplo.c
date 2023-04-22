#include "../practica_listas.h"

#include "tipo_elemento.h"
#include "listas/listas.h"
#include "cadenas.h"
#include "util_listas.h"
#include "aserciones.h"
#include <assert.h>
#include <stdlib.h>

int main() {
    imprimir_titulo("Tests para determinar si una lista es múltiplo de otra");

    int arreglo[] = {21, 18, 24, 3};
    Lista l = crear_lista_desde_array(arreglo,4);

    l_mostrar(multiplos(l,3));

    return 0;
}
