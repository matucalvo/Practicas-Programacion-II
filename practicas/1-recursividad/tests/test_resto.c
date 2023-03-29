#include <assert.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

int main() {

    imprimir_titulo("Tests para resto");

    printf("resto de 10/2 ==> %d \n", restoRecursivo(10,2));
    printf("resto de 22/3 ==> %d \n", restoRecursivo(22,3));
    printf("resto de -22/3 ==> %d \n", restoRecursivo(-22,3));
    printf("resto de -22/-3 ==> %d \n", restoRecursivo(-22,-3));
    printf("resto de 22/-3 ==> %d \n", restoRecursivo(22,-3));


    return 0;
}
