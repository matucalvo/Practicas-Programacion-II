#include <stdlib.h>
#include <assert.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

void probar(int n, char *esperado) {
    char *res = chinos(n);
    printf("chinos(%d): %s\n", n, res);
    assert(str_eq(res, esperado));
    free(res);
}

int main() {
    imprimir_titulo("Tests para la mafia china");

    probar(1, "(-.-)");
    probar(2, "(-.(-.-).-)");
    probar(3, "(-.(-.(-.-).-).-)");
    probar(4, "(-.(-.(-.(-.-).-).-).-)");
    probar(5, "(-.(-.(-.(-.(-.-).-).-).-).-)");
    probar(6, "(-.(-.(-.(-.(-.(-.-).-).-).-).-).-)");
    probar(7, "(-.(-.(-.(-.(-.(-.(-.-).-).-).-).-).-).-)");

    return 0;
}