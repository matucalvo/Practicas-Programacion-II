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
    Iterador ite = iterador(l);
    TipoElemento te;

    while(hay_siguiente(ite)){
        te = siguiente(ite);
        if (te -> clave % n == 0){
            te -> clave = te -> clave/n;
            l_agregar(lista_multiplos, te);
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
                te = l_recuperar(l_reflejada, i);   // si es false, cargo la lista completa-1 invertida /
                l_agregar(l_reflejada, te);
            }  
    
}

/// EJERCICIO COMPARAR LISTAS /// 

enum Comparacion compararListas(Lista l1, Lista l2){
    Iterador ite1 = iterador(l1); // Llamo al iterador para recorrer la lista 1
    Iterador ite2 = iterador(l2); // Llamo al iterador para recorrer la lista 2
    TipoElemento te1;
    TipoElemento te2;
    int valorL1, valorL2; // Creo dos valores para guarda el valor de la clave de cada lista para luego compararlas
    int i;
    int contador1 = 0; // Creo un contador para contar la cantidad de veces que la clave de la lista 1 es mayor a la clave de la lista 2
    int contador2 = 0; // Creo un contador para contar la cantidad de veces que la clave de la lista 2 es mayor a la clave de la lista 1
    if (l_longitud(l1) == l_longitud(l2)){ // Si ambas listas son iguales, recorro las listas y comparo valor a valor
        while (hay_siguiente(ite1) && hay_siguiente(ite2)){
            te1 = siguiente(ite1);
            te2 = siguiente(ite2);
            valorL1 = te1->clave;
            valorL2 = te2->clave;
            if (valorL1 > valorL2) // Si el valor de la clave de la lista 1 es mayor al de la lista 2, aumento el contador de lista 1
                contador1++;
            else
                contador2++; // Si el valor de la clave de la lista 2 es mayor al de la lista 1, aumento el contador de lista 2
        } 
    }
    else
      printf("Error: Las listas son de distinto tamanio");
    
    if (contador1 > contador2)
        return MAYOR;
    else if (contador1 < contador2)
        return MENOR;
    else
        return IGUAL;
}


/// EJERCICIO LISTA MULTIPLOS ///

bool escalar(Lista l1, Lista l2, int *primerElemento){
    TipoElemento teL1, teL2, primerElementoL1, primerElementoL2;
    Iterador iteL1 = iterador(l1);
    Iterador iteL2 = iterador(l2);
    bool bandera = true;

    primerElementoL1 = l_recuperar(l1,1);
    primerElementoL2 = l_recuperar(l2,1);
    *primerElemento = primerElementoL2->clave / primerElementoL1->clave;    // guardo la division del primer primeros valor

    while (hay_siguiente(iteL1) && hay_siguiente(iteL2) && bandera){
        teL1 = siguiente(iteL1);
        teL2 = siguiente(iteL2);

        if ((teL2->clave/teL1->clave) == *primerElemento){
            bandera = true;
        } else bandera = false;
        
    }

    
    return bandera;

} 

bool listaEsMultiplo(Lista l1, Lista l2){
    bool condicion = true;
    TipoElemento teL1,teL2;
    Iterador iteL1 = iterador(l1);
    Iterador iteL2 = iterador(l2);
    int primerElemento = 0;

    while ((hay_siguiente(iteL1) && hay_siguiente(iteL2)) && condicion){
        teL1 = siguiente(iteL1);
        teL2 = siguiente(iteL2);
    
        if (teL2->clave % teL1->clave  == 0){
            condicion = true;
        } else condicion = false;
    }  

    if (condicion){
        if (escalar(l1,l2,&primerElemento) == true){
            printf("%d es escalar de la lista \n", primerElemento);
        }
    }


   



    return condicion;

}

/// EJERCICIO SUBLISTAS ///
bool subLista(Lista l1, Lista l2){
    Iterador ite1 = iterador(l1);
    Iterador ite2 = iterador(l2);
    TipoElemento teL1, teL2;
    int valor1, valor2;
    bool encontrado;
    while (hay_siguiente(ite2)){ // Comienzo tomando el valor de la sublista para compararlo con el valor de la lista principal
        teL2 = siguiente(ite2);
        valor2 = teL2->clave;
        while (hay_siguiente(ite1)){ // Primero recorro la lista principal en su totalidad buscando el valor obtenido de la sublista
            teL1 = siguiente(ite1);
            valor1 = teL1->clave;
            if (valor2 == valor1){
                encontrado = true;
                ite1 = iterador(l1); // Reinicio el iterador para comenzar a evaluar la lista desde la posicion inicial
                break;
            }
            else
                encontrado = false;
        }
    }
    return encontrado;
}


