
#include <assert.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

void probar(Cola cola, Cola esperada){
    Cola res = unicos(cola);

    bool verificacion = comparar(res,esperada);

    printf("\nCola esperada\n");
    c_mostrar(esperada);
    printf("\nCola resultante\n");
    c_mostrar(res);

    assert(bool_true(verificacion));


}

int main() {
    imprimir_titulo("Tests para elementos únicos");
    int numeros[] = {1, 6, 3, 7, 4, 8, 3};
    int numerosEsperado[] = {1, 6, 7, 4, 8};
    int numeros1[] = {12, 6, 8, 5, 8, 12, 12};
    int numerosEsperado1[] = {6, 5};
    Cola cola = crear_cola_desde_array(numeros,7);
    Cola colaEsperada = crear_cola_desde_array(numerosEsperado,5);
    Cola cola1 = crear_cola_desde_array(numeros1,7);
    Cola colaEsperada1 = crear_cola_desde_array(numerosEsperado1,2);

    imprimir_titulo("\n CASO 1 \n");
    probar(cola,colaEsperada);
    imprimir_titulo("\n CASO 2 \n");
    probar(cola1,colaEsperada1);


    
    

    return 0;
}
