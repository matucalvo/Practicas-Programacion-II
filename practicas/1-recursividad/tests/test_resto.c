#include <assert.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

void probar (int dividendo, int divisor, int esperado){
    int resultado = restoRecursivo(dividendo,divisor);
    printf("El resto de dividir %d y %d es: %d\n", dividendo, divisor, resultado);
    assert(int_eq(resultado,esperado));
}

int main() {

    imprimir_titulo("Tests para resto");
    //Tests propuestos
    probar(10,2,0);
    probar(22,3,1);
    probar(-22,3,-1);
    probar(-22,-3,1);
    probar(22,-3,-1);


    return 0;
}
