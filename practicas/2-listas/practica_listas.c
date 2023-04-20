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

/// EJERCICIO ENCONTRAR MENOR DE LA LISTA ///

struct ElementoYPosicion menorYPosicion(Lista l){

    
    int posicion = 0;

    Iterador ite = iterador(l);
    TipoElemento te;

    struct ElementoYPosicion elypos;

    elypos.valor = 1000;


    while (hay_siguiente(ite)){
        te = siguiente(ite);
        posicion++;
        if (te->clave < elypos.valor){
            elypos.valor = te->clave;
            elypos.ordinal = posicion;
        }

    }

    return elypos;

}

/// EJERCICIO ENCONTRAR MAYOR DE LA LISTA ///

int Ocurrencias(Lista l, int valor){
    int ocurrencias = 0;
    Iterador ite = iterador(l);
    TipoElemento te;

    while (hay_siguiente(ite)){
        te = siguiente(ite);
        if (te->clave == valor){
            ocurrencias++;
        }
    }
    return ocurrencias;
}

struct ElementoYOcurrencias mayorYOcurrencias(Lista l){
    int ocurrencias = 0;

    Iterador ite = iterador(l);   // llamo al iterador pasandole la lista
    TipoElemento te;

    struct ElementoYOcurrencias elyocu;

    elyocu.valor = 0;

    while (hay_siguiente(ite)){
        te = siguiente(ite);
        if (te->clave > elyocu.valor){
            elyocu.valor = te->clave;
        }
    }

    elyocu.ocurrencias = Ocurrencias(l, elyocu.valor);

    return elyocu;

}

/// EJERCICIO PROMEDIO LISTA ///


double promedio(Lista l){
    Iterador ite = iterador(l);
    TipoElemento te;
    double prom = 0.0, suma = 0.0;

    while (hay_siguiente(ite)){
        te = siguiente(ite);
        suma += te->clave;
    }

    prom = suma / l_longitud(l);

    return prom;
}

/// EJERCICIO CALCULAR MÚLTIPLOS///


Lista multiplos(Lista l, int n){
    Lista lista_multiplos = l_crear();

    for (int i=0; i <= l_longitud(l); i++) {
        if (l[i] % n == 0) {
            l_agregar(lista_multiplos, l[i]);
        }
    }
    return lista_multiplos;
}


/// EJERCICIO LISTA AL AZAR ///

Lista numerosAlAzar(int cantidad){
    Lista l = l_crear();
    TipoElemento te;

    srand(time(NULL));

    for (int i = 0; i < cantidad; i++)
    {
        te = te_crear(rand() % 100);
        l_agregar(l, te);
    }

    return l;
    
}

/// EJERCICIO ESPEJITO ///

Lista reflejarLista(Lista l, bool ultimoDoble){
    Lista l_reflejada = l_crear();
    TipoElemento te;
    Iterador ite = iterador(l);

        while (hay_siguiente(ite)){     //primero agrego los elementos de la lista original, a la q voy a reflejar
            te = siguiente(ite);
            l_agregar(l_reflejada, te);
        }

        int FinLista = (l_longitud(l_reflejada));

        if (ultimoDoble == true){
            for (int i = FinLista; i >= 1; i--)              // si es true, cargo la lista completa invertida 
            {
                te = l_recuperar(l_reflejada, i);
                l_agregar(l_reflejada, te);
            }   
        } else 
            for (int i = FinLista-1; i >= 1; i--)
            {
                te = l_recuperar(l_reflejada, i);   // si es false, cargo la lista completa-1 invertida
                l_agregar(l_reflejada, te);
            }  
    
}

