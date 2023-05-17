#include <assert.h>
#include <stdio.h>

#include "colas/util_colas.h"
#include "../practica_colas.h"
#include "cadenas.h"
#include "aserciones.h"

void probar(Cola cola, Cola esperado, int pos, TipoElemento te){
    insertarElemento(cola,te,pos);
    

    bool condicion = comparar(cola,esperado);
    c_mostrar(esperado);
    

    c_mostrar(cola);

    assert(bool_true(condicion));

}

int main() {
    imprimir_titulo("Tests para colarse");
    int numeros[] = {1, 6, 3, 7, 4, 8, 3};
    int numerosEsperados[] = {1, 6, 3, 7, 20, 4, 8, 3};
    int numerosEsperados1[] = {30, 1, 6, 3, 7, 20, 4, 8, 3};

    Cola cola = crear_cola_desde_array(numeros,7);
    Cola colaEsperada1 = crear_cola_desde_array(numerosEsperados,8);
    Cola colaEsperada2 = crear_cola_desde_array(numerosEsperados1,9);

    TipoElemento te = te_crear(20);
    imprimir_titulo("\nCASO 1\n");
    probar(cola, colaEsperada1, 5, te);
    
    


    imprimir_titulo("\nCASO 2\n");
    te = te_crear(30);
    probar(cola, colaEsperada2, 1 ,te);
    
    

    return 0;
}
