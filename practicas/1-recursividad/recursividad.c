#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "recursividad.h"

bool esCapicua(int numero);

bool esPalindromo(char *palabra);

int productoRecursivo(int m, int n);

int terminoSerieDeFibonacci(int n);

bool esDivisiblePor7(int n);

void explosionRecursiva(int n, int b, int *result, int *size);

int *explosion(int n, int b, int *size);

char *chinos(unsigned int nivel);

char* agregarSeparadoresRecursivo(char* numero, int indice, int contador);

char* agregarSeparadorMiles(char* numero);

int restoRecursivo(int dividendo, int divisor);


// ---------- FUNCIONES AUXILIARES ---------------

bool esCapicuaAux(char *numero, int inicio, int final);

bool esPalindromoAux(char *palabra, int inicio, int fin);

int explosionAux(int n, int b, int *size, int **arr);

//  --------------------------------------------------




// ------------- PUNTO 1 ---------------- //

bool esCapicua(int numero){
    char num[10];
    int inicio, final;
    bool resultado;

    sprintf(num, "%i", numero);

    final = strlen(num)-1;
    inicio = 0;

    resultado = esCapicuaAux(num, inicio, final);

    return resultado;




}

bool esCapicuaAux(char *numero, int inicio, int final){
    bool resultado;


    if (inicio >= final){
        resultado = true;
    } else if (numero[inicio] == numero[final]){
        resultado = esCapicuaAux(numero, inicio+1, final-1);
    } else resultado = false;

    return resultado;


}


// ------------- PUNTO 1 ---------------- //




// ------------- PUNTO 2 ---------------- //


bool esPalindromo(char *palabra){
    bool resultado;
    int fin = strlen(palabra)-1;
    int inicio = 0;

    resultado = esPalindromoAux(palabra, inicio, fin);

    return resultado;

    
}

bool esPalindromoAux(char *palabra, int inicio, int fin){
    bool resultado;

    if (inicio >= fin){
        resultado = true;
    } else if (palabra[inicio] == palabra[fin]){
        resultado = esCapicuaAux(palabra, inicio+1, fin-1);
    } else resultado = false;

    return resultado;

}

// ------------- PUNTO 2 ---------------- //




// ------------- PUNTO 3 ---------------- //


int productoRecursivo(int m, int n){
    int resultado;
   

    if (n==0){
        resultado = 0;
    } else if(n<0){
        resultado = -m + productoRecursivo(m, n+1);
    } else resultado = m + productoRecursivo(m, n-1);


    return resultado;
}

// ------------- PUNTO 3 ---------------- //



// ------------- PUNTO 4 ---------------- //

int terminoSerieDeFibonacci(int n){
   int resultado = 0;
    if (n <= 1){
        resultado = n;
    } else resultado = terminoSerieDeFibonacci(n-1) + terminoSerieDeFibonacci(n-2);


    return resultado; 
}


// ------------- PUNTO 4 ---------------- //


// ------------- PUNTO 5 ---------------- //


int restoRecursivo(int dividendo, int divisor){


    int resultado = 0;
    int signo = 1;

    if (divisor == 0){                                                          // si divisor es 0 tira error
        printf("Error no se puede dividir por cero \n");      
    } else if (dividendo < 0){                                           // si el dividendo es negativo, guarda el signo y despues lo convierte en positivo para hacer la resta
        signo = -signo; 
        resultado = -restoRecursivo(-dividendo, divisor);    
    } else if (divisor < 0){                                             // si el divisor es negativo, guarda el signo y despues lo convierte en positivo para hacer la resta
        signo = -signo;
        resultado = -restoRecursivo(dividendo, -divisor);
    } else if (dividendo < divisor){                                   // caso base, cuando el dividendo sea menor que el divisor para la resta
     resultado = dividendo;
    } else resultado = signo * restoRecursivo(dividendo-divisor, divisor);          // recursion, multiplicando el signo que corresponde 

    return resultado;
    
}


// ------------- PUNTO 5 ---------------- //

// ------------ PUNTO 7 ---------------- //

char *chinos(unsigned int nivel)
{
    // char *chino = malloc (sizeof(char)*nivel);
    if (nivel == 0)
    {
        printf("No asistió ningun chino\n");
    }
    if (nivel == 1)
    {
        printf("(-.-)");
    }
    if (nivel > 1)
    {
        printf("(-.");
        *chinos(nivel - 1);
        printf(".-)");
    }
}

// ---------- PUNTO 7 ---------------- //




// ---------- PUNTO 10 ---------------- //
int *explosion(int n, int b, int *size){
    int i;
    int *arreglo = malloc(sizeof(int));

    
    explosionAux(n,b,&size, &arreglo);

    for (int i = 0; i < size; i++) {
        printf("%d ", arreglo[i]);
    }




    free(arreglo);

    return arreglo;
}

int explosionAux(int n, int b, int *size, int **arr){
     int c = 0;
 
    

    if (n <= b){
        (*size)++;
        *arr = realloc(*arr, (*size) * sizeof(int));
        (*arr)[*size - 1] = b;
        c = b;
    } else { 
        (*size)++;
        c = n/b;
        *arr = realloc(*arr, (*size) * sizeof(int));
        (*arr)[*size - 1] = c;
        explosionAux(n-c, b, size, arr);
    }

    return c;
}


// ---------- PUNTO 10 ---------------- //