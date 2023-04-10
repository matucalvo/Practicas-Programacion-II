#include <assert.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

void prueba (int m, int n, int esperado){
    int resultado = productoRecursivo(m,n);
    printf("El resultado del producto entre %d y %d es: %d\n", m, n, resultado);
    assert(int_eq(resultado, esperado));
}

int main() {
    imprimir_titulo("Tests para producto");
    // Tests propuestos
    prueba(3, 2, 6);
    prueba(5, -2, -10);
    prueba(-5, 2, -10);
    prueba(-5, -2, 10);
    // Tests adicionales
    prueba(2, -10, -20);
    prueba(10, 100, 1000);
    prueba(-10, 5, -50);

    return 0;
}
