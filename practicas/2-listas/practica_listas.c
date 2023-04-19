#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "practica_listas.h"
#include "tipo_elemento.h"
#include "listas/listas.h"






///   EJERCICIO INVERTIR LISTA ///

Lista invertirLista(Lista l){
    int FinLista = (l_longitud(l)); //guardo final de la lista
    TipoElemento te;

    Lista ListaInvertida = l_crear();

    for (int i = FinLista; i >= 1; i--)    //recorro lista desde el final hasta el principio
    {
        te = l_recuperar(l, i);
        l_agregar(ListaInvertida,te);
    }

    return ListaInvertida;


}