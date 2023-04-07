#include <assert.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

void probar(int n, bool esperado){
    bool resultado = esDivisiblePor7(n);
    printf("El numero %d es divisible por 7?: %s\n", n, resultado == 1? "VERDADERO" : "FALSO");
    assert(bool_eq (resultado,esperado));
}

int main() {
    imprimir_titulo("Tests para divisiblePor7");
    // Tests propuestos
    probar(32291, true);
    probar(110, false);
    probar(110, false);
    // Tests adicionales
    probar(0, true);
    probar(7, true);
    probar(10, false);
    probar(8274, true);
    probar(-7, true);
    probar(-10, false);
    probar(-32291, true);
    return 0;
}
