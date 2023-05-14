#include <assert.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

int main() {
    imprimir_titulo("Tests para eliminar elemento");

    int numeros[] = {1, 6, 3, 7, 4, 8, 3};
    Cola cola = crear_cola_desde_array(numeros,7);

    c_mostrar(cola);
    eliminarElemento(cola,3);
    eliminarElemento(cola,1);
    printf("\n");
    c_mostrar(cola);





    return 0;
}
