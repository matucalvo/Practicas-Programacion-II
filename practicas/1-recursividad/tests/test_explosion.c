#include <stdlib.h>
#include <assert.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"


void probar(int n, int b, int *esperado, int largo){
    int i;
    int size = 0;
    int *res = explosion(n,b,&size);  // guardo los fragmentos en res


    printf("fragmentos(%d,%d):", n, b);

    for (i = 0; i < size; i++)
    {
        printf(" %d ", res[i]);
    }

    int largo_esperado = largo / sizeof(esperado[0]);   //calculo el largo esperado 

    
    

    assert(int_array_eq(res,esperado,size,largo_esperado));    //testeo



    free(res);  //libero memoria reservada


}


int main() {
    imprimir_titulo("Tests del Ejercicio de Explosión saraza");
    int arreglo1[] = {4, 3, 2, 2, 1, 1, 1, 1, 5};
    int arreglo2[] = {3, 2, 1, 1, 3};

// tests propuestos



    probar(10,3,arreglo2, sizeof(arreglo2));
    printf("\n");
    probar(20,5,arreglo1, sizeof(arreglo1));
    printf("\n");
    
    

   

    

    

    

    return 0;
}
