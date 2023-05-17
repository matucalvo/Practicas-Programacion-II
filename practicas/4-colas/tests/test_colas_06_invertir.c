#include <assert.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

void probar(Cola cola, Cola colaEsperada){
    Cola res = invertir(cola);
    printf("\n Cola esperada: \n");
    c_mostrar(colaEsperada);

    printf("\n Cola invertida: \n");
    c_mostrar(res);

    bool verificacion = comparar(res,colaEsperada);

    assert(bool_true(verificacion));
}

int main() {
    imprimir_titulo("Tests para duplicar cola");

    int numeros[] = {1, 6, 3, 7, 4, 8, 3};
    int numerosInvertido[] = {3, 8, 4 ,7 ,3 ,6 ,1};
    Cola cola = crear_cola_desde_array(numeros,7);
    Cola colaEsperada = crear_cola_desde_array(numerosInvertido,7);

    probar(cola,colaEsperada);




    

    return 0;
}
