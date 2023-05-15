#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "practica_colas.h"
#include "tipo_elemento.h"
#include "colas/colas.h"
#include "colas/util_colas.h"


/// FUNCIONES AUXILIARES //

void intercambiarC(Cola cola1, Cola cola2){
    TipoElemento te;

    while(!c_es_vacia(cola1)){
        te = c_desencolar(cola1);
        c_encolar(cola2,te);
    }
}

int longitudC(Cola cola){
    TipoElemento te;
    Cola caux = c_crear();
    int contador = 0;

    while(!c_es_vacia(cola)){
        te = c_desencolar(cola);
        c_encolar(caux,te);
        contador++;
    }

    intercambiarC(caux,cola);
    return contador;
}

bool buscarElemEnCola(Cola cola1, Cola cola2){
    TipoElemento teC1, teC2;
    bool condicionaux = false;
    bool condicion = false;
    Cola copiaC2 = c_crear();

     while(!c_es_vacia(cola1) && !condicionaux){       
        condicion = false;
        condicionaux = false;
        teC1 = c_desencolar(cola1);
        copiaC2 = copia(cola2);
        while(!c_es_vacia(copiaC2) && !condicion){          
            teC2 = c_desencolar(copiaC2);
            if (teC1->clave == teC2->clave){    // si encuentra el elemento de la cola 1 en algun lugar de la cola 2, para y sigue buscando los otros elementos de la cola 1
                condicion = true;
        }
        }

        if (condicion == false){        // si no encontro algun elemento de la cola 1 en la cola 2, para de buscar y devuelve false, de lo contrario sigue buscando
            condicionaux = true;
        }
    }

    destruir_cola(copiaC2);

    return condicion;

}



void intercambiarP(Pila pila1, Pila pila2){
    TipoElemento te;

    while (!p_es_vacia(pila1)){
        te = p_desapilar(pila1);
        p_apilar(pila2, te);
    }
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

/// FUNCIONES AUXILIARES //


bool buscarElemento(Cola c, TipoElemento e){
    Cola caux = c_crear();
    TipoElemento te;
    bool condicion = false;

    while(!c_es_vacia(c)){
        te = c_desencolar(c);
        if (te->clave == e->clave){
            condicion = true;
        }
        c_encolar(caux, te);
    }

    intercambiarC(caux,c);

    destruir_cola(caux);

    return condicion;
}


void insertarElemento(Cola c, TipoElemento e, int pos){
    Cola caux = c_crear();
    TipoElemento te;

    intercambiarC(c,caux);

    for (int i = 1; i < pos; i++)
    {
        te = c_desencolar(caux);
        c_encolar(c,te);
    }

    c_encolar(c,e);

    intercambiarC(caux,c);

    destruir_cola(caux);
     
}


void eliminarElemento(Cola c, int clave){
    TipoElemento te;
    Cola caux = c_crear();

    while(!c_es_vacia(c)){
        te = c_desencolar(c);
        if (te->clave != clave){
            c_encolar(caux,te);
        }
    }

    intercambiarC(caux,c);

    destruir_cola(caux);

}

int tamanoCola(Cola c){
    TipoElemento te;
    Cola caux = c_crear();
    int contador = 0;

    while(!c_es_vacia(c)){
        te = c_desencolar(c);
        c_encolar(caux,te);
        contador++;
    }

    intercambiarC(caux,c);

    destruir_cola(caux);
    return contador;

}

Cola copia(Cola c){
    Cola caux = c_crear();
    Cola copia = c_crear();
    TipoElemento te;

   while(!c_es_vacia(c)){
    te = c_desencolar(c);
    c_encolar(caux,te);
    c_encolar(copia,te);
   }

   intercambiarC(caux,c);

   destruir_cola(caux);
   

    return copia;

}


Cola invertir(Cola c){
    Cola caux1 = c_crear();
    Cola caux2 = c_crear();
    Cola invertida = c_crear();
    TipoElemento te;

    caux1 = copia(c);

    while(!c_es_vacia(caux1)){
        int finalCola = tamanoCola(caux1);
        for (int i = 0; i < finalCola; i++)
        {
            te = c_desencolar(caux1);
            
            if (i==finalCola-1){
                c_encolar(invertida,te);
            } else c_encolar(caux2,te);
            
        }
        intercambiarC(caux2,caux1);
    }

    destruir_cola(caux1);
    destruir_cola(caux2);

    return invertida;
}


bool comparar(Cola c1, Cola c2){
    if (tamanoCola(c1) != tamanoCola(c2)){
        return false;
    }
    TipoElemento te1,te2;
    Cola caux1 = c_crear();
    Cola caux2 = c_crear();
    bool condicion = true;

    while(!c_es_vacia(c1)){
        te1 = c_desencolar(c1);
        te2 = c_desencolar(c2);

        if (te1->clave != te2->clave){
            condicion = false;
        }

        c_encolar(caux1,te1);
        c_encolar(caux2,te2);
    }

    intercambiarC(invertir(caux1), c1);
    intercambiarC(invertir(caux2), c2);

    destruir_cola(caux1);
    destruir_cola(caux2);


    return condicion;



    
}


bool mismosElementos(Cola c1, Cola c2){
    Cola copiaC1 = c_crear();
    Cola copiaC2 = c_crear();
    bool condicionCola1 = false;
    bool condicionCola2 = false;


    copiaC1 = copia(c1);
    copiaC2 = copia(c2);

    condicionCola1 = buscarElemEnCola(copiaC1, copiaC2);  // busco  si los elementos de la cola 1 estan en la cola 2

    copiaC1 = copia(c1);
    copiaC2 = copia(c2);

    condicionCola2 = buscarElemEnCola(copiaC2,copiaC1);  // busco si los elementos de la cola 2 estan en la cola 1


    

    if (condicionCola1 && condicionCola2 == true){   // si ambas bolas comparten elementos retorna true, si no false
        return true;
    } else return false;

    destruir_cola(copiaC1);
    destruir_cola(copiaC2);


}


Cola unicos(Cola c){
    TipoElemento te,te1;
    Cola caux1 = c_crear();
    Cola caux2 = c_crear();
    Cola unicosElementos = c_crear();
    

    caux1 = copia(c);
    

    while(!c_es_vacia(caux1)){
        caux2 = copia(c);
        int contador = 0;
        te = c_desencolar(caux1);
        while(!c_es_vacia(caux2)){
            te1 = c_desencolar(caux2);
            if (te->clave == te1->clave){
                contador++;
            }        
        }  
        if (contador < 2){
            c_encolar(unicosElementos,te);
        }
    }

    destruir_cola(caux1);
    destruir_cola(caux2);


    return unicosElementos;
}




Lista buscaRepetidos(Pila p, Cola c){
    Pila pCopia = p_crear();
    Cola cCopia = c_crear();
    Lista lista = l_crear();
    TipoElemento teC,teP;
    


    
    cCopia = copia(c);
    int i = 0;
    

    while(!c_es_vacia(cCopia)){
        teC = c_desencolar(cCopia);
        pCopia = copiar(p);
        i++;
        int j = contarElementos(p);
        while(!p_es_vacia(pCopia)){
            teP = p_desapilar(pCopia);
            if (teC->clave == teP->clave){
                struct Repetido *repetidos = malloc(sizeof(struct Repetido));
                repetidos->clave = teC->clave;
                repetidos->posicionEnCola = i;
                repetidos->posicionEnPila = j;

                l_agregar(lista, te_crear_con_valor(0,repetidos));  
            } 
            j--;
        }
    }

    destruir_cola(cCopia);
    
    return lista;


}

