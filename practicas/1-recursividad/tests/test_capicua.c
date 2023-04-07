#include <assert.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

void probar (int n, bool esperado){
    bool resultado = esCapicua(n);
    printf("El numero %d ==> %s\n",n,resultado==1?"Es capicua":"No es capicua");
    assert(bool_eq(resultado,esperado));
}

int main() {
    imprimir_titulo("Tests para Capicua");
    //Tests propuestos
    probar(161,true);
    probar(2992,true);
    probar(2993,false);
    //Tests adicionales
    probar(19341,false);

    return 0;
}
