#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "practica_pilas.h"
#include "tipo_elemento.h"
#include "pilas/pilas.h"


//// FUNCIONES AUXILIARES ////
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
}

Pila invertirPila(Pila p) {
    Pila invertida = p_crear();
    TipoElemento te;

    while (!p_es_vacia(p)){
        te = p_desapilar(p);
        p_apilar(invertida,te);
    }

    
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
    TipoElemento teP, teC;


    

    while (!p_es_vacia(p)){
        int cantidad = 0;
        bool condicion = true;
        teP = p_desapilar(p);

        if (buscarElemento(Paux,teP) == true){
            condicion = false;
        }

        while (!p_es_vacia(pCopia) && condicion){
            teC = p_desapilar(pCopia);
            if (teP->clave == teC->clave){
                cantidad += 1; 
                p_apilar(Paux,teP);
            }
        }
        if (condicion == true){
            TipoElemento teR = te_crear_con_valor(teP->clave,&cantidad);
            //printf("%d:%d\n", teR->clave, *(int*)teR->valor);
            p_mostrarConValor(SinRepetidos);
            
            p_apilar(SinRepetidos,teR);
        }
        pCopia = copiar(p);
    }

    

    

    return SinRepetidos;

}



