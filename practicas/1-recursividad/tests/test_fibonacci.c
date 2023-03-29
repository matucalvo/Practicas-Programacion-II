#include <assert.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

int main() {
    imprimir_titulo("Tests para término de Fibonacci");

    printf(" 3 ==> %d \n", terminoSerieDeFibonacci(3));
    printf(" 6 ==> %d \n", terminoSerieDeFibonacci(6));
    printf(" 1 ==> %d \n", terminoSerieDeFibonacci(1));
    printf(" 2 ==> %d \n", terminoSerieDeFibonacci(2));

    return 0;
}
