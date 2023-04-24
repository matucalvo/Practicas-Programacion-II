#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "../practica_listas.h"

#include "tipo_elemento.h"
#include "listas/listas.h"
#include "cadenas.h"
#include "aserciones.h"
#include "util_listas.h"


void probarEvaluar(struct Polinomio p, double x, double esperado){
    double res = evaluar(p, x);
    printf("F(%f): %f\n",x, res);

    assert(double_eq(res, esperado));

}


bool compararPuntoXY(TipoElemento este, TipoElemento otro) {
    struct PuntoXY *estePunto = (struct PuntoXY *) este->valor;
    struct PuntoXY *otroPunto = (struct PuntoXY *) otro->valor;
    return estePunto->x == otroPunto->x && estePunto->y == otroPunto->y;
}

char *toStringPuntoXY(TipoElemento te) {
    struct PuntoXY *punto = (struct PuntoXY *) te->valor;
    char *str = (char *) malloc(100 * sizeof(char));
    sprintf(str, "P(%f, %f)", punto->x, punto->y);
    return str;
}

Lista crear_lista_puntos_desde_array(struct PuntoXY puntos[], int tamano) {
    Lista lista = l_crear();
    for (int i = 0; i < tamano; i++) {
        l_agregar(lista, te_crear_con_valor(0, &puntos[i]));
    }

    return lista;
}


int main() {
    imprimir_titulo("Tests para polinomio");

    int coeficientes[] = {1, 2};
    int coeficientes1[] = {3, 1, 2};
    
    Lista lista1 = crear_lista_desde_array(coeficientes,2);
    Lista lista2 = crear_lista_desde_array(coeficientes1,3);

    struct Polinomio polinomio1 = {lista1};
    struct Polinomio polinomio2 = {lista2};

    printf("Funcion evaluar:\n");
    probarEvaluar(polinomio1, 0.5, 2.0);
    probarEvaluar(polinomio1, 1.0, 3.0);
    probarEvaluar(polinomio2, 2.0, 13.0);

    Lista listValores = valores(polinomio1, -2, 2, 0.5);
    char *lista = lista_como_string(listValores, toStringPuntoXY);
    printf("%s\n", lista);
    free(lista);


    struct PuntoXY puntos[] = {
        {-2.0, -3.0}, 
        {-1.5, -2.0}, 
        {-1.0, -1.0}, 
        {-0.5, 0.0}, 
        {0.0, 1.0}, 
        {0.5, 2.0}, 
        {1.0, 3.0}, 
        {1.5, 4.0}, 
        {2.0, 5.0}
    };

    Lista listaEsperada = crear_lista_puntos_desde_array(puntos,9);

    assert(listas_eq_fn(listValores, listaEsperada, compararPuntoXY, toStringPuntoXY));

    









    free(lista1);
    free(lista2);
    free(listaEsperada);
    free(listValores);

    return 0;
}
