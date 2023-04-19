#include "../practica_listas.h"

#include "tipo_elemento.h"
#include "listas/listas.h"
#include "cadenas.h"
#include "util_listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    imprimir_titulo("Tests para comparación de listas");

    int numeros[] = {1,2,3,4,5};
    Lista listanew = crear_lista_desde_array(numeros,5);
    TipoElemento te = te_crear(1);

    l_agregar(listanew, te);
    

   


    l_insertar(listanew, te, 3);

   

    l_mostrar(listanew);

    



    


    return 0;
}
