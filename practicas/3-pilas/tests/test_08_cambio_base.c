#include "../practica_pilas.h"

#include "tipo_elemento.h"
#include "pilas/pilas.h"
#include "cadenas.h"
#include <stdio.h>
#include <assert.h>
#include "aserciones.h"
#include <stdlib.h>
#include "pilas/util_pilas.h"

void probar(char *esperado, int numero, int base){
    char *res = cambioDeBase(numero,base);

    printf("%s\n", res);

    assert(str_eq(res,esperado));

}

int main() {
    imprimir_titulo("Tests para cambio de base");

    probar("1010", 10, 2);
    probar("101", 10, 3);
    probar("121", 16, 3);
    probar("237", 567, 16);
    probar("2F7", 759, 16);


    return 0;
}
