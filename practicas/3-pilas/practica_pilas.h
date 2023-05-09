#ifndef PRACTICA_PILAS_H
#define PRACTICA_PILAS_H

#include "pilas/pilas.h"
#include "listas/listas.h"

bool buscarElemento(Pila p, TipoElemento e);

void insertarElemento(Pila p, TipoElemento e, int pos);

void eliminarElemento(Pila p, int clave);

void intercambiarElementos(Pila p, int pos1, int pos2);

Pila copiar(Pila p);

int contarElementos(Pila p);

bool compararPilas(Pila p1, Pila p2);

char* cambioDeBase(int numero, int base);

Pila invertirPila(Pila p);

Pila eliminarTodasOcurrencias(Pila p, int clave);

Pila elementosEnComun(Pila p1, Pila p2);

Pila eliminarRepetidos(Pila p);


// funciones auxiliares

bool compararPilasValores(Pila p1, Pila p2);

Pila crear_pila_desde_array_valores(int *vectorClaves, int *vectorValores, int tamano);

Pila crear_pila_desde_array_valorChar(int *vectorClaves, char *Valores, int tamano);

int longitudPila(Pila pila);

void invertirMismaPila(Pila p);

void p_mostrarConValor(Pila pila);

void p_mostrarConValorChar(Pila pila);

char *toStringEntero(TipoElemento te);




/// TAD MAZO ///

Pila crearMazo();

Lista RepartirCartas(Pila mazo, int n);

void mezclarMazo(Pila Mazo);



#endif // PRACTICA_PILAS_H
