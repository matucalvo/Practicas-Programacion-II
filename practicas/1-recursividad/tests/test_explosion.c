#include <stdlib.h>
#include <assert.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"


void probar(int n, int b, int *esperado){
    int i;
    int size = 0;
    int * res = explosion(n,b,&size);
    printf("fragmentos(%d,%d): ", n, b);

    for (i = 0; i < size; i++)
    {
        printf("%d", res[i]);
    }
    

    int_array_eq(res,esperado,sizeof(res),sizeof(esperado));



    free(res);


}


int main() {
    imprimir_titulo("Tests del Ejercicio de Explosión saraza");
    int arreglo1[] = {4, 3, 2, 2, 1, 1, 1, 1, 5};
    int arreglo2[] = {3, 2, 1, 1, 3};


    probar(20,5,arreglo1);
    printf("\n");
    probar(10,3,arreglo2);
    

    

    

    return 0;
}
