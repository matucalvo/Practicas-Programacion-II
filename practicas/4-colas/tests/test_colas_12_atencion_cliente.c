
#include <assert.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

int main() {
    imprimir_titulo("Tests para atención al cliente");
    //char esperado[] = "Cliente 1 Cola 3, Cliente 1 Cola 2, Cliente 2 Cola 3, Cliente 2 Cola 2, Cliente 3 Cola 3, Cliente 1 Cola 1, Cliente 2 Cola 1, Cliente 3 Cola 1, ";

    int numeros1[] = {40, 20, 30};
    int numeros2[] = {20, 10};
    int numeros3[] = {10, 10, 10};

    Cola c1 = crear_cola_desde_array(numeros1,3);
    Cola c2 = crear_cola_desde_array(numeros2,2);
    Cola c3 = crear_cola_desde_array(numeros3,3);


    //procesar(10,c1,c2,c3);



    return 0;
}
