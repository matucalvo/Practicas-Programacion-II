#include "../practica_listas.h"

#include "tipo_elemento.h"
#include "listas/listas.h"
#include "cadenas.h"
#include "util_listas.h"
#include "aserciones.h"
#include <assert.h>
#include <stdlib.h>

void probar(Lista l, double promedioEsperado){
    double res = promedio(l);

    l_mostrar(l);
    printf("Promedio: %f", res);

    assert(double_eq(res, promedioEsperado)); 
}

int main() {
    imprimir_titulo("Tests para calcular el promedio de los datos de una lista");

    int arreglo[] = {7, 6, 8, 7, 8, 8, 8, 8, 6, 6};
    Lista l = crear_lista_desde_array(arreglo,10);

    probar(l, 7.2);



    return 0;
}
