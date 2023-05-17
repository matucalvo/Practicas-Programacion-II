
#include <assert.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"
void probar(Cola cola1, Cola cola2, bool esperado){
    bool res = mismosElementos(cola1, cola2);

    printf("\n Condicion esperada: \n");


    printf(esperado ? "\ntrue\n" : "\nfalse\n");

    printf("\n Condicion recibida: \n");


    printf(res ? "\ntrue\n" : "\nfalse\n");





    assert(bool_eq(res,esperado));

}

int main() {
    imprimir_titulo("Tests para mismos elementos");
    int numeros[] = {1, 6, 3, 7, 4, 8, 3};
    int numeros1[] = {6, 6, 3, 6, 1, 7, 4, 8, 3};
    int numeros2[] = {6, 3, 7, 4, 8};
    Cola cola1 = crear_cola_desde_array(numeros,7);
    Cola cola2 = crear_cola_desde_array(numeros1,9);
    Cola cola3 = crear_cola_desde_array(numeros2,5);


    imprimir_titulo("\n CASO 1 \n");
    probar(cola1,cola2,true);
    imprimir_titulo("\n CASO 2 \n");
    probar(cola2,cola1,true);
    imprimir_titulo("\n CASO 3 \n");
    probar(cola1,cola3,false);
    imprimir_titulo("\n CASO 4 \n");
    probar(cola3,cola1,false);

    


    

    return 0;
}


