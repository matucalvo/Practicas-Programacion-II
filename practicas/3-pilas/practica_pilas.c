#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "practica_pilas.h"
#include "tipo_elemento.h"
#include "pilas/pilas.h"
#include "listas/listas.h"
#include <time.h>


//// FUNCIONES AUXILIARES ////

Pila crear_pila_desde_array_valorChar(int *vectorClaves, char *Valores, int tamano) {
    Pila p = p_crear();

    for (int i = 0; i < tamano; i++) {
        p_apilar(p, te_crear_con_valor(vectorClaves[i], Valores));
    }

    return p;
}

void p_mostrarConValor(Pila pila){
    Pila pila_aux = p_crear();
    TipoElemento te;

    printf("Elementos de la pila: \n");

    //recorro la pila desapilandola y pasandosela a la auxiliar
    while (!p_es_vacia(pila)){
        te = p_desapilar(pila);
        printf("%d:%d ", te->clave,*(int*)te->valor);
        p_apilar(pila_aux, te);
        printf("\n"); 

    }

    while (!p_es_vacia(pila_aux)){
        te = p_desapilar(pila_aux);
        p_apilar(pila, te);
    }

}

void p_mostrarConValorChar(Pila pila){
    Pila pila_aux = p_crear();
    TipoElemento te;

    printf("Elementos de la pila: \n");

    //recorro la pila desapilandola y pasandosela a la auxiliar
    while (!p_es_vacia(pila)){
        te = p_desapilar(pila);
        char *valor = (char*)te->valor;
        printf("%d:%s ", te->clave,valor);
        p_apilar(pila_aux, te);
        printf("\n"); 

    }

    while (!p_es_vacia(pila_aux)){
        te = p_desapilar(pila_aux);
        p_apilar(pila, te);
    }

}

void intercambiarP(Pila pila1, Pila pila2){
    TipoElemento te;

    while (!p_es_vacia(pila1)){
        te = p_desapilar(pila1);
        p_apilar(pila2, te);
    }
}


int longitudPila(Pila pila){
    int i = 0;
    Pila pilaAux = p_crear();
    TipoElemento te;

    while(!p_es_vacia(pila)){
        te = p_desapilar(pila);
        p_apilar(pilaAux,te);
        i++;
    }

    intercambiarP(pilaAux,pila);

    return i;
}


void invertirMismaPila(Pila p) {
    Pila pilaAux = p_crear();
    Pila invertida = p_crear();
    TipoElemento te;

    while (!p_es_vacia(p)){
        te = p_desapilar(p);
        p_apilar(pilaAux,te);
        p_apilar(invertida,te);
    }

    intercambiarP(pilaAux,p);

    free(pilaAux);
 
}

char *toStringEntero(TipoElemento te) {
    int *valor = (int*) te->valor;
    char *str = (char *) malloc(100 * sizeof(char));
    sprintf(str, "%d", *valor);
    return str;
}


////////////////////////////////////////

bool buscarElemento(Pila p, TipoElemento e){
    bool condicion = false;
    TipoElemento te;
    Pila pilanew = p_crear();


    while(!p_es_vacia(p) && !condicion){

        te = p_desapilar(p);
        p_apilar(pilanew, te);  //guardo los elementos de la pila en otra pila auxiliar

        if (e->clave == te->clave){
            condicion = true;
        }
    }

    intercambiarP(pilanew, p);   //vuelgo a cargar la pila original


    return condicion;
}

void insertarElemento(Pila p, TipoElemento e, int pos) {
    Pila pilaAux = p_crear();
    TipoElemento te;

    int posicion = (longitudPila(p) - pos) + 1;

    for (int i = 1; i <= posicion; i++)
    {
        te = p_desapilar(p);   // desapilo hasta posicion
        p_apilar(pilaAux,te);   // lo guardo en otra pila para no perder los elementos
    }

    p_apilar(p,e);   // inserto el nuevo elemento

    while (!p_es_vacia(pilaAux)){
        te = p_desapilar(pilaAux);   // vuelvo a cargar la pila
        p_apilar(p,te);
    }



}

void eliminarElemento(Pila p, int clave) {
    Pila pilaAux = p_crear();
    TipoElemento te;
    bool condicion = true;

    while (!p_es_vacia(p) && condicion){
        te = p_desapilar(p);
        if (te->clave != clave){
            p_apilar(pilaAux,te);
        } else condicion = false;
    }

    intercambiarP(pilaAux,p);

}

void intercambiarElementos(Pila p, int pos1, int pos2) {
    Pila pilaAux = p_crear();
    TipoElemento te, tePos1, tePos2;
    int posicion1 = (longitudPila(p) - pos1)+1;
    int posicion2 = (longitudPila(p) - pos2)+1;
    int i = 0;

    while (!p_es_vacia(p)){
        i++;
        if (i == posicion1){
            tePos1 = p_desapilar(p);
        } else if (i == posicion2){
            tePos2 = p_desapilar(p);   
        }
        else{
        te = p_desapilar(p);
        p_apilar(pilaAux,te);
        }
    }

    intercambiarP(pilaAux,p);
    insertarElemento(p,tePos2,pos1);
    insertarElemento(p,tePos1,pos2);
    
}

Pila copiar(Pila p) {
    Pila pilaAux = p_crear();
    Pila copia = p_crear();
    Pila pilaAux1 = p_crear();
    TipoElemento te;

    while(!p_es_vacia(p)){
        te = p_desapilar(p);
        p_apilar(pilaAux,te);
        p_apilar(pilaAux1,te);
    }

    intercambiarP(pilaAux1,p);
    intercambiarP(pilaAux,copia);

    return copia;


}

int contarElementos(Pila p) {
     int i = 0;
    Pila pilaAux = p_crear();
    TipoElemento te;

    while(!p_es_vacia(p)){
        te = p_desapilar(p);
        p_apilar(pilaAux,te);
        i++;
    }

    intercambiarP(pilaAux,p);

    return i;
}

bool compararPilas(Pila p1, Pila p2) {
    Pila pilaAux = p_crear();
    TipoElemento te, tep1, tep2;
    int i = 0;
    bool condicion = true;
    


    if (longitudPila(p1) != longitudPila(p2)){
        return false;
    }

    while (!p_es_vacia(p1)){             // pregunto solo por 1, pq si llega a este if es pq son iguales las longitudes
        tep1 = p_desapilar(p1);
        tep2 = p_desapilar(p2);
        p_apilar(pilaAux,tep1);
        p_apilar(pilaAux,tep2);


        if (tep1->clave != tep2->clave){
            condicion = false;
        } 
    }

    while(!p_es_vacia(pilaAux)){
        i++;
        if (i % 2 != 0){
            te = p_desapilar(pilaAux);         // reconstruyo las pilas
            p_apilar(p2, te);
        } else {
            te = p_desapilar(pilaAux);
            p_apilar(p1,te);
        }

    }

    invertirMismaPila(p1);
    invertirMismaPila(p2);

    return condicion;

}

char* cambioDeBase(int numero, int base) {
    Pila pila = p_crear();
    TipoElemento te1;

    while (numero != 0){
        int resto = numero % base;  
        TipoElemento te = te_crear(resto);
        p_apilar(pila, te);
        numero /= base;
    }

    char* digitos = "0123456789ABCDEF";
    char* resultado = (char*)malloc(sizeof(char) * 100);
    int i = 0;

    while (!p_es_vacia(pila)){
        te1 = p_desapilar(pila);
        resultado[i++] = digitos[te1->clave];
    }
    resultado[i] = '\0';


    return resultado;
}

Pila invertirPila(Pila p) {
    Pila invertida = p_crear();
    Pila aux = copiar(p);
    TipoElemento te;

    while (!p_es_vacia(p)){
        te = p_desapilar(p);
        p_apilar(invertida,te);
    }

    intercambiarP(aux,p);

    
    return invertida;
}

Pila eliminarTodasOcurrencias(Pila p, int clave) {
    Pila pilaAux = p_crear();
    Pila pilaAux2 = p_crear();
    TipoElemento te;

    while (!p_es_vacia(p)){
        te = p_desapilar(p);
        if (te->clave != clave){
            p_apilar(pilaAux,te);
            p_apilar(pilaAux2,te);    
        } else p_apilar(pilaAux2,te);
    }

    intercambiarP(pilaAux2,p);

    
    return invertirPila(pilaAux);
}

Pila elementosEnComun(Pila p1, Pila p2) {
    Pila pilaAux1 = p_crear();
    Pila pilaAux2 = p_crear();
    Pila ElementosEnComun = p_crear();
    TipoElemento te1, te2;

    while (!p_es_vacia(p1)){
        te1 = p_desapilar(p1);
        p_apilar(pilaAux1,te1);
        while (!p_es_vacia(p2)){
            te2 = p_desapilar(p2);
            p_apilar(pilaAux2,te2);
            if (te1->clave == te2->clave){
            p_apilar(ElementosEnComun,te2);
        }
        }

        intercambiarP(pilaAux2,p2);
    }

    intercambiarP(pilaAux1,p1);

    return invertirPila(ElementosEnComun);
}           

Pila eliminarRepetidos(Pila p) {
    Pila pCopia = copiar(p);
    Pila SinRepetidos = p_crear();
    Pila Paux = p_crear();
    Pila original = copiar(p);
    TipoElemento teP, teC;
    

    while (!p_es_vacia(p)){
        int *cantidad = malloc(sizeof(int));
        *cantidad = 0;
        bool condicion = true;
        teP = p_desapilar(p);

        if (buscarElemento(Paux,teP) == true){   // verificar si ya se busco el elemento, de ser asi, no entra en el while
            condicion = false;
        }

        while (!p_es_vacia(pCopia) && condicion){
            teC = p_desapilar(pCopia);
            if (teP->clave == teC->clave){
                *cantidad += 1; 
                p_apilar(Paux,teP);
            }
        }
        if (condicion == true){
            TipoElemento teR = te_crear_con_valor(teP->clave,cantidad);
            p_apilar(SinRepetidos,teR);
        }
        pCopia = copiar(p);
        
    }

    

    

    return SinRepetidos;

}


/// TAD MAZO ///

////////////////////////// funciones auxiliares ////////////////////////////////
Pila cargarPorPalo(char *palo, int *numerosCartas){
    return crear_pila_desde_array_valorChar(numerosCartas, palo, 12);       
}

Pila JuntarCartas(Pila Basto, Pila Espada, Pila Copa, Pila Oro){
    Pila MazoEntero = p_crear();
    TipoElemento te;

    while(!p_es_vacia(Basto)){
        te = p_desapilar(Oro);
        p_apilar(MazoEntero,te);

        te = p_desapilar(Copa);
        p_apilar(MazoEntero,te);

        te = p_desapilar(Espada);
        p_apilar(MazoEntero,te);

        te = p_desapilar(Basto);
        p_apilar(MazoEntero,te);
    }

    return MazoEntero;
}
////////////////////////////////////////////////////////////////////////////////

Pila crearMazo(){
    int numeros[] = {1,2,3,4,5,6,7,8,9,10,11,12};   //vector con cantidad de cartas

    char *basto = "Basto";
    char *espada = "Espada";            // creo los char palos
    char *copa = "Copa";
    char *oro = "Oro";

    Pila Basto = cargarPorPalo(basto, numeros);
    Pila Espada = cargarPorPalo(espada,numeros);        //creo una pila por palo
    Pila Copa = cargarPorPalo(copa, numeros);
    Pila Oro = cargarPorPalo(oro,numeros);

    Pila Mazo = JuntarCartas(Basto,Espada,Copa,Oro);        //juntos los 4 palos

    //p_mostrarConValorChar(Mazo);

    return Mazo;
}



void mezclarMazo(Pila Mazo){
    Pila mezclada = p_crear();
    Pila auxiliar = p_crear();
    TipoElemento te;
    srand(time(NULL));
    int tamano = longitudPila(Mazo);

    while (!p_es_vacia(Mazo)){
        int random = rand() % tamano;

        for (int i = 0; i < random; i++)
        {
            te = p_desapilar(Mazo);
            p_apilar(auxiliar, te);
            tamano--;
        }

        te = p_desapilar(Mazo);
        p_apilar(mezclada, te);
        tamano--;
    }

    while (!p_es_vacia(auxiliar)){
        te = p_desapilar(auxiliar);
        p_apilar(mezclada,te);
    }

    
    intercambiarP(mezclada,Mazo);
}



// n es la cantidad de jugadores

Lista RepartirCartas(Pila mazo, int n){
    Lista cartas = l_crear();
    TipoElemento carta1,carta2;

    for (int i = 0; i < n; i++)
    {
        carta1 = p_desapilar(mazo);
        carta2 = p_desapilar(mazo);

        Lista jugador = l_crear();

        l_agregar(jugador,carta1);
        l_agregar(jugador,carta2);

        TipoElemento te = te_crear_con_valor(0,jugador);
        l_agregar(cartas,te);
    }

    return cartas;
    
}

Lista Parejas4(Lista lista, Pila mazo, int n){
    Lista parejas = l_crear();
    TipoElemento teL,teP;
    int i = 0;
    Pila pareja1 = p_crear();
    Pila pareja2 = p_crear();
    
    
    while(!p_es_vacia(mazo) && (i == 2)){
        Iterador ite = iterador(lista);
        int numJug = 0;
        while(hay_siguiente(ite) && i == 2){
            teL = siguiente(ite);
            teP = p_desapilar(mazo);
            numJug++;
            p_apilar(teL->valor,teP);
            if (teP->clave == 12){
                i++;
                TipoElemento jugador = te_crear_con_valor(numJug,teL->valor);
                p_apilar(pareja1,jugador);
                l_eliminar(lista,numJug);
            }
        }
    }
// segunda pareja 
    Iterador ite = iterador(lista);
    while(hay_siguiente(ite)){
        teL = siguiente(ite);
        p_apilar(pareja2,teL);
    }

   
        TipoElemento equipo1 = te_crear_con_valor(1,pareja1);
        TipoElemento equipo2 = te_crear_con_valor(2,pareja2);
        l_agregar(parejas, equipo1);
        l_agregar(parejas, equipo2);

        return parejas;

    }


Lista Parejas(Pila mazo, int n){
    Lista parejas = l_crear();
    int i = 0;
    Lista parejasfinal;

    if (n == 4){
        while (i < n){
            Pila jugador = p_crear();
            TipoElemento te = te_crear_con_valor(0,jugador);
            l_agregar(parejas,te);
            i++;
            Lista parejasfinal = Parejas4(parejas,mazo,n);
        }
        Lista parejasfinal = Parejas4(parejas,mazo,n);
    } else if (n == 6){
        while (i < n){
            Pila jugador = p_crear();
            TipoElemento te = te_crear_con_valor(0,jugador);
            l_agregar(parejas,te);
            i++;
        }
    }

    return parejasfinal;

}