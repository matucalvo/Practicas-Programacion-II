#include "../practica_pilas.h"

#include "tipo_elemento.h"
#include "pilas/pilas.h"
#include "cadenas.h"
#include "pilas/util_pilas.h"
#include "listas/listas.h"
#include <assert.h>
#include "aserciones.h"
#include <stdlib.h>
#include "util_listas.h"

void mostrarCartasJugadores(Lista lista){
    Iterador ite = iterador(lista);
    TipoElemento te,te1;
    int i = 0;

    while(hay_siguiente(ite)){
        te = siguiente(ite);
        i++;
        Iterador ite1 = iterador(te->valor);
        printf("Cartas jugador %d:\n", i);
        while(hay_siguiente(ite1)){
            te1 = siguiente(ite1);
            char *valor = (char*)te1->valor;
            printf("%d:%s\n",te1->clave,valor);
        }
    }
}



int main(){


    Pila mazo = crearMazo();

    mezclarMazo(mazo);

    //p_mostrarConValorChar(mazo);

    //Lista jugadores = RepartirCartas(mazo,3);

    //mostrarCartasJugadores(jugadores);

    Lista parejas = Parejas(mazo,4);










    return 0;
}