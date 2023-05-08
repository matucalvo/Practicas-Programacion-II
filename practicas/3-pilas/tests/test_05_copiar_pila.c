#include "../practica_pilas.h"

#include "tipo_elemento.h"
#include "pilas/pilas.h"
#include "cadenas.h"
#include "pilas/util_pilas.h"
#include <assert.h>
#include "aserciones.h"
#include <stdlib.h>

void probar(Pila original, Pila esperada){
    Pila copia = copiar(original);

    bool verificacion = compararPilas(copia,esperada);

    printf("Pila copiada:\n");

    p_mostrar(copia);

    printf("\nPila esperada:\n");
    p_mostrar(esperada);

    assert(bool_true(verificacion));
}

int main() {
    imprimir_titulo("Tests para copiar pila");

    int numeros[] = {1, 6, 3, 7, 4, 8, 3};
    

    Pila pila = crear_pila_desde_array(numeros,7);
    Pila copia = crear_pila_desde_array(numeros,7);

    imprimir_titulo("CASO 1");
    probar(pila, copia);





    return 0;
}
