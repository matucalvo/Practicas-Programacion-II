#include "../practica_listas.h"

#include "tipo_elemento.h"
#include "listas/listas.h"
#include "cadenas.h"
#include "util_listas.h"
#include "aserciones.h"
#include <assert.h>
#include <stdlib.h>



int main() {
    imprimir_titulo("Tests para generar números al azar únicos en una lista");
    srand(getpid());

    Lista l = numerosAlAzar(3);


    l_mostrar(l);

    free(l);


    


    return 0;
}
