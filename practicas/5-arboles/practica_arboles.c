
#include "practica_arboles.h"
#include "listas/listas.h"
#include "pilas/pilas.h"
#include "arboles/util_arboles.h"


///////////////////////////// Árboles Binarios: Analizando los árboles binarios //////////////////////////////////////////


// altura de un arbol

int altura_recursivo(NodoArbol nodo, int altura){
    if (nodo == NULL){
        return altura;
    }

    int altura_izquierda = altura_recursivo(hijo_izquierdo(nodo), altura+1);
    int altura_derecha = altura_recursivo(hijo_derecho(nodo), altura+1);

    return (altura_izquierda > altura_derecha) ? altura_izquierda : altura_derecha;
}

int alturaArbol(ArbolBinario a){
    return altura_recursivo(a_raiz(a), -1);

}

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
    if ((hijo_izquierdo(raiz) == nodo || hijo_derecho(raiz) == nodo)){
        return nivel+1;
    }

    if (raiz == nodo){
        return 0;
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

Lista a_nodos_terminales_iterativo(ArbolBinario arbol){
    Pila pila = p_crear();
    Lista lista = l_crear();

    NodoArbol nodo = a_raiz(arbol);

    while (nodo != NULL){

        if (nodo->hd == NULL && nodo->hi == NULL ){
            l_agregar(lista, recuperar_nodo_arbol(nodo));        // si es una hoja lo agrega a la lista
        }

        if (nodo->hi != NULL){
            p_apilar(pila, te_crear_con_valor(0, nodo->hi));     // si tiene hijo izquierdo el nodo, lo apila
        }

        if (nodo->hd != NULL){
            p_apilar(pila, te_crear_con_valor(0, nodo->hd));  // si tiene hijo derecho el nodo, lo apila
        }

        if (!p_es_vacia(pila)){
            TipoElemento aux = p_desapilar(pila);   
            nodo = aux->valor;
        } else nodo = NULL;
        
    }

    return lista;


}


Lista a_nodos_terminales(ArbolBinario a){
   // Lista nodos = l_crear();

    //pre_orden_ej1(nodos, a_raiz(a));

    //return nodos;

    return a_nodos_terminales_iterativo(a);
} 

////////////

Lista a_nodos_interiores_iterarivo(ArbolBinario arbol){
    Lista lista = l_crear();
    Pila pila = p_crear();

    NodoArbol nodo = a_raiz(arbol);

    while (nodo != NULL){
        if ((nodo->hi != NULL || nodo->hd != NULL) && nodo != a_raiz(arbol)){
            l_agregar(lista, recuperar_nodo_arbol(nodo));
        }

        if (nodo->hi != NULL){
            p_apilar(pila, te_crear_con_valor(0, nodo->hi));
        }

        if (nodo->hd != NULL){
            p_apilar(pila, te_crear_con_valor(0, nodo->hd));
        }


        if (!p_es_vacia(pila)){
            TipoElemento aux = p_desapilar(pila);
            nodo = aux->valor;
        } else nodo = NULL;
    }

    return lista;
}


Lista a_nodos_interiores(ArbolBinario a){
    //Lista nodos = l_crear();

    //pre_orden_ej2(nodos, a_raiz(a), a);

    //return nodos;
    return a_nodos_interiores_iterarivo(a);
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

NodoArbol recorrido_nodo_padre_iterativo(ArbolBinario arbol, NodoArbol nodo){
    Pila pila = p_crear();

    NodoArbol root = a_raiz(arbol);
    NodoArbol nodoAux = NULL;

    while (root != NULL){

        if (root->hi == nodo){
            nodoAux = root;
        } else if (root->hd == nodo){
            nodoAux = root;
        }

        if (root->hi != NULL){
            p_apilar(pila, te_crear_con_valor(0, root->hi));
        }

        if (root->hd != NULL){
            p_apilar(pila, te_crear_con_valor(0, root->hd));
        }

        if (!p_es_vacia(pila)){
            TipoElemento te = p_desapilar(pila);
            root = te->valor;
        } else root = NULL;
    }

    return nodoAux;

}


NodoArbol a_nodo_padre(ArbolBinario a, NodoArbol nodo){
    NodoArbol resultado = recorrido_nodo_padre_iterativo(a, nodo);//recorrido_nodo_padre(a,a_raiz(a),nodo);
    return resultado;

}


void cargar_hijos(Lista l, NodoArbol raiz, NodoArbol nodo){
    if (raiz == NULL){
        return;
    }

    if (raiz == nodo){
        if (hijo_derecho(raiz) != NULL){
            l_agregar(l, recuperar_nodo_arbol(hijo_derecho(raiz)));
        };
        if (hijo_izquierdo(raiz) != NULL){
            l_agregar(l, recuperar_nodo_arbol(hijo_izquierdo(raiz)));
        } else printf("\nEste nodo no posee hijos\n");
    }

    cargar_hijos(l, hijo_izquierdo(raiz),nodo);
    cargar_hijos(l, hijo_derecho(raiz),nodo);

}

Lista a_nodo_hijos(ArbolBinario a, NodoArbol nodo){
    Lista hijos = l_crear();

    cargar_hijos(hijos, a_raiz(a),nodo);

    return hijos;
}

void cargar_hermanos(Lista l, NodoArbol raiz, NodoArbol nodo){
    if (raiz == NULL){
        return;
    }

    if (hijo_izquierdo(raiz) == nodo){
        l_agregar(l, recuperar_nodo_arbol(hijo_derecho(raiz)));
    };

    if (hijo_derecho(raiz) == nodo){
        l_agregar(l, recuperar_nodo_arbol(hijo_izquierdo(raiz)));
    };

    cargar_hermanos(l, hijo_izquierdo(raiz),nodo);
    cargar_hermanos(l, hijo_derecho(raiz),nodo);


}


Lista a_nodo_hermanos(ArbolBinario a, NodoArbol nodo){
    Lista hermanos = l_crear();

    cargar_hermanos(hermanos, a_raiz(a),nodo);

    if (l_es_vacia(hermanos)){
        printf("Este nodo no posee hermanos");
    }

    return hermanos;


}

int a_nodo_nivel_recursivo(NodoArbol raiz, NodoArbol nodo, int nivel){
    if (raiz == NULL){
        return 0;
    }

    if (raiz == nodo){
        return nivel;
    }


    int recorrido_izquierda = a_nodo_nivel_recursivo(hijo_izquierdo(raiz), nodo, nivel+1);
    int recorrido_derecha = a_nodo_nivel_recursivo(hijo_derecho(raiz), nodo, nivel+1);

    return (recorrido_izquierda > recorrido_derecha) ? recorrido_izquierda:recorrido_derecha;
}



int a_nodo_nivel(ArbolBinario a, NodoArbol nodo){
    int nivel = 0;
    return a_nodo_nivel_recursivo(a_raiz(a), nodo, nivel);

}

///////

int maximo(int a, int b) {
    return (a > b) ? a : b;
}

int auxiliar_rama(NodoArbol nodo, int nivel){

    if (nodo == NULL) {
        return nivel;
    }

    int altura_izquierda = auxiliar_rama(hijo_izquierdo(nodo), nivel + 1);
    int altura_derecha = auxiliar_rama(hijo_derecho(nodo), nivel + 1);

    return maximo(altura_izquierda, altura_derecha);


}


int buscar_rama(NodoArbol raiz, NodoArbol nodo, int nivel){
    if ((hijo_izquierdo(raiz) == nodo || hijo_derecho(raiz) == nodo)){
        return (nivel-1) + auxiliar_rama(raiz,0);
    }

    if (raiz == nodo){
        return 0;
    }

    int nivel_encontrado = -1;


    if (hijo_izquierdo(raiz) != NULL){
        if (nivel_encontrado == -1){
            nivel_encontrado = buscar_rama(hijo_izquierdo(raiz),nodo,nivel+1);
        }
        
    }

    if (hijo_derecho(raiz) != NULL){
        if (nivel_encontrado == -1){
            nivel_encontrado = buscar_rama(hijo_derecho(raiz),nodo,nivel+1);
        }
    }

    return nivel_encontrado;

}

int a_nodo_altura_rama(ArbolBinario a, NodoArbol nodo){
    return buscar_rama(a_raiz(a), nodo, 0);

}

/////////////

void buscar_nodos(Lista l, NodoArbol raiz, int nivel, int nivelC){
    if (nivelC != nivel-1){ 
        buscar_nodos(l, hijo_izquierdo(raiz), nivel, nivelC+1);
        buscar_nodos(l, hijo_derecho(raiz), nivel, nivelC+1);
    }

    if (nivelC == nivel-1){
        if (hijo_izquierdo(raiz) != NULL){
        l_agregar(l, recuperar_nodo_arbol(hijo_izquierdo(raiz)));
    }

    if (hijo_derecho(raiz) != NULL){
        l_agregar(l, recuperar_nodo_arbol(hijo_derecho(raiz)));
    }
    }    
}

Lista a_nodo_mismo_nivel(ArbolBinario a, int nivel){
    Lista nodos = l_crear();

    if (nivel == 0){
        l_agregar(nodos, recuperar_nodo_arbol(a_raiz(a)));
    } else buscar_nodos(nodos, a_raiz(a), nivel,0);

    printf("Elementos del nivel %d: ", nivel);
 

    return nodos;

}



bool recorrido_equivalentes(NodoArbol raiz1, NodoArbol raiz2, bool *condicion){
    if (raiz1 == NULL || raiz2 == NULL){
        return *condicion;
    }
    if (recuperar_nodo_arbol(raiz1)->clave != recuperar_nodo_arbol(raiz2)->clave){
        return false;
    }

    bool condicion_izquierdo = recorrido_equivalentes(hijo_izquierdo(raiz1), hijo_izquierdo(raiz2), condicion);
    bool condicion_derecho = recorrido_equivalentes(hijo_derecho(raiz1), hijo_derecho(raiz2), condicion);

    if (!condicion_derecho || !condicion_izquierdo){
        *condicion = false;
    }

    return *condicion;
}


bool a_equivalentes(ArbolBinario a1, ArbolBinario a2){
    bool condicion = true;
    bool calcular_rama = auxiliar_rama(a_raiz(a2), 0) == auxiliar_rama(a_raiz(a1),0);   // auxiliar rama calcula la altura de la rama mas alta, o sea la altura del arbol
    
    if (recorrido_equivalentes(a_raiz(a1), a_raiz(a2), &condicion) == false || !calcular_rama){
        return false;
    } else return true;

} 


///// n-arios

/// altura 

int an_altura_recursivo(NodoArbol nodo, int altura){
    if (nodo == NULL){
        return altura;
    }

    int alturaIzquierda = an_altura_recursivo(hijo_izquierdo(nodo), altura+1);
    int alturaDerecha = an_altura_recursivo(hijo_derecho(nodo), altura);

    return maximo(alturaDerecha, alturaIzquierda);
}

int an_altura(ArbolBinario a){
    return an_altura_recursivo(a_raiz(a), 0) - 1;  
}

/// nivel de un nodo

int an_nivel_recursivo(NodoArbol raiz, NodoArbol nodo, int nivel){
    if (raiz == NULL){
        return nivel;
    }

    int alturaIzquierda = 0;

    if (raiz == nodo){
        return nivel;
    }

    if (hijo_izquierdo(raiz) != NULL){
        alturaIzquierda = an_nivel_recursivo(hijo_izquierdo(raiz),nodo,nivel+1);
    }

    int alturaDerecha = an_nivel_recursivo(hijo_derecho(raiz),nodo,nivel);

    return maximo(alturaDerecha, alturaIzquierda);
}

int an_nivel(ArbolBinario a, NodoArbol nodo){
    return an_nivel_recursivo(a_raiz(a), nodo, 0);
    

}


// nodos internos

void an_nodos_interiores_recursivo(ArbolBinario arbol, Lista nodos, NodoArbol nodo){
    if (nodo == NULL){
        return;
    }

    if (hijo_izquierdo(nodo) != NULL && nodo != a_raiz(arbol)){
        l_agregar(nodos, recuperar_nodo_arbol(nodo));
    }

    an_nodos_interiores_recursivo(arbol, nodos, hijo_izquierdo(nodo));
    an_nodos_interiores_recursivo(arbol, nodos, hijo_derecho(nodo));
}

Lista an_nodos_interiores(ArbolBinario a){
    Lista nodos = l_crear();

    an_nodos_interiores_recursivo(a, nodos, a_raiz(a));

    return nodos;
}

// hojas mismo nivel

bool an_hojas_misma_nivel_recursivo(ArbolBinario arbol, NodoArbol nodo, bool *condicion, int altura){
    if (nodo == NULL){
        return *condicion;
    }

    if (hijo_izquierdo(nodo) == NULL){
        if (an_nivel(arbol, nodo) != altura){
            *condicion = false;
        }
    }

     an_hojas_misma_nivel_recursivo(arbol, hijo_izquierdo(nodo), condicion, altura);
     an_hojas_misma_nivel_recursivo(arbol, hijo_derecho(nodo), condicion, altura);


    return *condicion;
}

bool an_hojas_mismo_nivel(ArbolBinario a){
    int altura = an_altura(a);
    bool condicion = true;
    return an_hojas_misma_nivel_recursivo(a,a_raiz(a), &condicion, altura);
}

// recorrido en anchura

Lista an_recorrido_anchura(ArbolBinario a){
    Lista arbol = l_crear();
    Iterador ite = iterador_bfs(a_raiz(a));

    while (hay_siguiente(ite)){
        TipoElemento te = siguiente(ite);
        l_agregar(arbol,te);
    }

    return arbol;
}


// cantidad hojas

int an_cantidad_nodos_recursivo(NodoArbol nodo, int *cantidad){

    if (nodo == NULL){
        return 0;
    }

    an_cantidad_nodos_recursivo(hijo_izquierdo(nodo), cantidad);
    an_cantidad_nodos_recursivo(hijo_derecho(nodo), cantidad);

    if (hijo_izquierdo(nodo) == NULL){
        *cantidad = *cantidad + 1;
    }

    return *cantidad;
}


int an_cantidad_nodos(ArbolBinario a){
    int cantidad = 0;
    return an_cantidad_nodos_recursivo(a_raiz(a), &cantidad); 

}

//// arbol similar

bool an_similares_recursivo(NodoArbol nodoA1, NodoArbol nodoA2, bool *condicion){

    if ((nodoA1 == NULL && nodoA2 != NULL) || (nodoA1 != NULL && nodoA2 == NULL)){
        *condicion = false;
    }

    if (nodoA1 == NULL || nodoA2 == NULL){
        return *condicion;
    }

    an_similares_recursivo(hijo_izquierdo(nodoA1), hijo_izquierdo(nodoA2), condicion);
    an_similares_recursivo(hijo_derecho(nodoA1), hijo_derecho(nodoA2), condicion);

    return *condicion;
}

bool an_similares(ArbolBinario a1, ArbolBinario a2){
    bool condicion = true;
    return an_similares_recursivo(a_raiz(a1), a_raiz(a2), &condicion);
}

// nodo padre

NodoArbol an_nodo_padre(ArbolBinario a, NodoArbol nodo){
    return NULL;
}

// lista hermanos

void hermanos_recursivo_aux(Lista l, NodoArbol nodo){
    if (hijo_derecho(nodo) != NULL){
        l_agregar(l, recuperar_nodo_arbol(hijo_derecho(nodo)));
        hermanos_recursivo_aux(l, hijo_derecho(nodo));
    }


}

void an_nodo_hermanos_recursivo(Lista l, NodoArbol raiz, NodoArbol nodo){
    if (raiz == NULL || nodo == NULL){
        return;
    }



    if (raiz == nodo){
        hermanos_recursivo_aux(l, raiz);
    }


    an_nodo_hermanos_recursivo(l, hijo_derecho(raiz), nodo);
    an_nodo_hermanos_recursivo(l, hijo_izquierdo(raiz), nodo);



}

Lista an_nodo_hermanos(ArbolBinario a, NodoArbol nodo){
    Lista hermanos = l_crear();

    an_nodo_hermanos_recursivo(hermanos, a_raiz(a), nodo);

    // ver como cargar los hermanos que quedan mas arriba


    return hermanos;

}




