#include "../practica_pilas.h"

#include "tipo_elemento.h"
#include "pilas/pilas.h"
#include "cadenas.h"
#include <assert.h>
#include "aserciones.h"
#include "pilas/util_pilas.h"
#include <stdlib.h>

void probar(Pila pila1 , Pila pila2, Pila esperada){
    Pila res = elementosEnComun(pila1,pila2);

    bool verificacion = compararPilas(res,esperada);

    p_mostrar(res);
    p_mostrar(esperada);

    

    assert(bool_true(verificacion));

}

int main() {
    imprimir_titulo("Tests para eliminar todas las ocurrencias");

    int numeros[] = {1, 4, 7, 9, 8};
    int numero1[] = {4, 1, 6, 9, 3};

    int esperado[] = {1, 4, 9};


    Pila pila1 = crear_pila_desde_array(numeros,5);
    Pila pila2 = crear_pila_desde_array(numero1,5);

    Pila pilaEsperada = crear_pila_desde_array(esperado,3);

    probar(pila1, pila2, pilaEsperada);


    destruir_pila(pila1);
    destruir_pila(pila2);
    destruir_pila(pilaEsperada);

    return 0;
}
