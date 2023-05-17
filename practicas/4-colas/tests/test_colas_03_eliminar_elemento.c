#include <assert.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

void probar(Cola cola, Cola esperado, int clave){
    eliminarElemento(cola,clave);
    

    bool condicion = comparar(cola,esperado);
    c_mostrar(esperado);
    

    c_mostrar(cola);

    assert(bool_true(condicion));

}

int main() {
    imprimir_titulo("Tests para eliminar elemento");

    int numeros[] = {1, 6, 3, 7, 4, 8, 3};
    int numerosEsperado[] = {1, 6, 7, 4, 8};
    Cola cola = crear_cola_desde_array(numeros,7);
    Cola colaEsperada = crear_cola_desde_array(numerosEsperado,5);

    int numerosEsperado1[] = {6,7,4,8};
    Cola colaEsperada1 = crear_cola_desde_array(numerosEsperado1,4);

    imprimir_titulo("\nCASO 1\n");


    probar(cola,colaEsperada,3);

    imprimir_titulo("\nCASO 2\n");

    probar(cola,colaEsperada1,1);
    





    return 0;
}
