
#include <assert.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

int main() {
    imprimir_titulo("Tests para elementos únicos");
    int numeros[] = {1, 6, 3, 7, 4, 8, 3};
    int numeros1[] = {12, 6, 8, 5, 8, 12, 12};
    Cola cola = crear_cola_desde_array(numeros,7);
    Cola cola1 = crear_cola_desde_array(numeros1,7);

    Cola unica = unicos(cola);
    Cola unica1 = unicos(cola1);

    
    c_mostrar(unica);
    c_mostrar(unica1);
    

    return 0;
}
