#include <assert.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

int main() {
    imprimir_titulo("Tests para producto");

    printf("3 x 2 ==> %d \n", productoRecursivo(3,2));
    printf("5 x -2 ==> %d \n", productoRecursivo(5,-2));
    printf("-5 x 2 ==> %d \n", productoRecursivo(-5,2));
    printf("-5 x -2 ==> %d \n", productoRecursivo(-5,-2));


    return 0;
}
