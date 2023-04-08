#include <assert.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

void probar (int n, int esperado){
    int resultado = terminoSerieDeFibonacci(n);
    printf("En la posicion %d de la serie de Fibonacci se encuentra el numero %d\n", n, resultado);
    assert(int_eq(resultado, esperado));
}
int main() {
    imprimir_titulo("Tests para término de Fibonacci");
    //Test propuestos
    probar(6,8);
    probar(1,1);
    //Test adicionales
    probar(3,2);
    probar(2,1);
    probar(10,55);
    return 0;
}
