
#include "practica_arboles.h"
#include "listas/listas.h"
#include "arboles/util_arboles.h"


///////////////////////////// Árboles Binarios: Analizando los árboles binarios //////////////////////////////////////////

/// recorrido para buscar hojas
void pre_orden_ej1(Lista l, NodoArbol nodo){
    if (nodo == NULL){
        return;
    }

    if (hijo_izquierdo(nodo) == NULL && hijo_derecho(nodo) == NULL){
        l_agregar(l,nodo->datos);  
    }
    pre_orden_ej1(l,hijo_izquierdo(nodo));
    pre_orden_ej1(l,hijo_derecho(nodo));
}
///

/// recorrido para buscar nodos interiores
void pre_orden_ej2(Lista l, NodoArbol nodo, ArbolBinario arbol){   // le paso el arbol para poder excluir la raiz de los nodos interiores
    if (nodo == NULL){
        return;
    }

    if(hijo_derecho(nodo) != NULL || hijo_izquierdo(nodo) != NULL){
        if (nodo != a_raiz(arbol)){
            TipoElemento te = recuperar_nodo_arbol(nodo);
            l_agregar(l,te);
        }
    }

    pre_orden_ej2(l,hijo_izquierdo(nodo),arbol);
    pre_orden_ej2(l,hijo_derecho(nodo),arbol);
}
///

/// contar altura de un nodo
int nivel_nodo(NodoArbol raiz, NodoArbol nodo, int nivel){
    if (hijo_izquierdo(raiz) == nodo || hijo_derecho(raiz) == nodo){
        return nivel+1;
    }

    int nivel_encontrado = -1;


    if (hijo_izquierdo(raiz) != NULL){
        if (nivel_encontrado == -1){
            nivel_encontrado = nivel_nodo(hijo_izquierdo(raiz),nodo,nivel+1);
        }
        
    }

    if (hijo_derecho(raiz) != NULL){
        if (nivel_encontrado == -1){
            nivel_encontrado = nivel_nodo(hijo_derecho(raiz),nodo,nivel+1);
        }
    }

    return nivel_encontrado;

}

/// recorrido para saber si las hojas estan a la misma altura

bool pre_orden_ej3(ArbolBinario arbol, NodoArbol nodo, bool *condicion, int *nivel, int *comparar_nivel){
    if (nodo == NULL){
        return *condicion;
    }

    if (hijo_izquierdo(nodo) == NULL && hijo_derecho(nodo) == NULL){
        int altura = nivel_nodo(a_raiz(arbol),nodo,*nivel);
        if (*comparar_nivel == -1){
            *comparar_nivel = altura;
        } else if (*comparar_nivel != altura){
            *condicion = false;
        }    
    }

    pre_orden_ej3(arbol,hijo_izquierdo(nodo),condicion,nivel,comparar_nivel);
    pre_orden_ej3(arbol,hijo_derecho(nodo),condicion,nivel,comparar_nivel);



    return *condicion;

    



}

void pre_orden_ej4(Lista l, NodoArbol nodo, int clave){
    if (nodo == NULL){
        return;
    }

    TipoElemento te = recuperar_nodo_arbol(nodo);
    if (te->clave == clave){
        l_agregar(l,te);
    }

    pre_orden_ej4(l,hijo_izquierdo(nodo),clave);
    pre_orden_ej4(l,hijo_derecho(nodo),clave);
}

//////////////////////


Lista a_nodos_terminales(ArbolBinario a){
    Lista nodos = l_crear();

    pre_orden_ej1(nodos, a_raiz(a));

    return nodos;
}


Lista a_nodos_interiores(ArbolBinario a){
    Lista nodos = l_crear();

    pre_orden_ej2(nodos, a_raiz(a), a);

    return nodos;
}


bool a_hojas_mismo_nivel(ArbolBinario a){
    int nivel = 1;
    int comparar_nivel = -1;
    bool condicion = true;

    return pre_orden_ej3(a, a_raiz(a), &condicion, &nivel, &comparar_nivel);

}



Lista a_posiciones_ocurrencias(ArbolBinario a, int clave){
    Lista ocurrencias = l_crear();

    pre_orden_ej4(ocurrencias,a_raiz(a),clave);

    return ocurrencias;

}

///////////////////////////// Árboles Binarios: Analizando los árboles binarios //////////////////////////////////////////


//////////////////////////// Árboles Binarios: Conociendo los nodos  //////////////////////////////////////////////////

NodoArbol recorrido_nodo_padre(ArbolBinario a, NodoArbol raiz, NodoArbol nodo){
    if (raiz == NULL){
        return NULL;
    }

    if (hijo_izquierdo(raiz) == nodo || hijo_derecho(raiz) == nodo){
        return raiz;
    }

    NodoArbol nodo_padre_izquierdo = recorrido_nodo_padre(a, hijo_izquierdo(raiz), nodo);
    if (nodo_padre_izquierdo != NULL) {
        return nodo_padre_izquierdo;
    }

    NodoArbol nodo_padre_derecho = recorrido_nodo_padre(a, hijo_derecho(raiz), nodo);
    if (nodo_padre_derecho != NULL) {
        return nodo_padre_derecho;
    }


    return NULL;
}


NodoArbol a_nodo_padre(ArbolBinario a, NodoArbol nodo){
    NodoArbol resultado = recorrido_nodo_padre(a,a_raiz(a),nodo);
    return resultado;

}
