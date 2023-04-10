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

char* ondaDigital(char *onda);


// ---------- FUNCIONES AUXILIARES ---------------

bool esCapicuaAux(char *numero, int inicio, int final);

bool esPalindromoAux(char *palabra, int inicio, int fin);

int explosionAux(int n, int b, int *size, int **arr);

char* ondaDigitalAux(char *onda, int *size, char **ondaAux);

int cant_caracteres(char* onda);

void agregarSeparadorMilesAux(char *numero, int largo, char* numeroAux, int* contadorCadenaAux, int* contadorCadenaOriginal, int *largoaux);

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


// ------------- PUNTO 6 ---------------- //


char *agregarSeparadorMiles(char *numero){
    int largo;
    int *contadorCadenaAux = 0;
    int *contadorCadenaOriginal = 0;
    int *largoaux = 0;
    int largo_total = largo + (largo/3);

    largo = strlen(numero);

    char *numeroAux = (char*) malloc(sizeof(char) * (largo + (largo/3)));

    

    agregarSeparadorMilesAux(numero,largo, numeroAux,&contadorCadenaAux,&contadorCadenaOriginal,&largoaux);


    return numeroAux;
}

void agregarSeparadorMilesAux(char *numero, int largo, char* numeroAux, int* contadorCadenaAux, int* contadorCadenaOriginal, int *largoaux){

    
   if (largo > 3) {    // si el largo del numero es mayor a 3, se necesita poner puntos
       agregarSeparadorMilesAux(numero, largo - 3, numeroAux,contadorCadenaAux,contadorCadenaOriginal,largoaux);   // llamada recursiva restandole 3 al largo hasta q sea menor que 3
       numeroAux[*contadorCadenaAux] ='.';
       *contadorCadenaAux += 1;    //contador para saber el final de la cadena que voy cargando
       *largoaux += 1;  // contador para saber cuantos puntos se le agrego a la cadena
        largo = largo + *largoaux;       
    }
   for (int i = *contadorCadenaAux; i < largo; i++) {         // una vez q es menor que 3, carga los numeros hasta q se tenga q poner un punto
        numeroAux[i] = numero[*contadorCadenaOriginal];       // asigno a la nueva cadena los elementos de la anterior
        *contadorCadenaOriginal += 1;                 //contador para saber la posicion exacta del numero q tengo que cargar de la cadena original
        *contadorCadenaAux += 1;           //contador para saber el final de la cadena que voy cargando
   }
} 

// ------------- PUNTO 6 ---------------- //

// ------------ PUNTO 7 ---------------- //

char *chinos(unsigned int nivel)
{
    if (nivel == 1)
    {
        char* result;
        result = (char*) malloc (sizeof(char)*6);
        strcpy (result, "(-.-)");
        return result;

    }
    else 
    {
        char* nivelAnterior = chinos (nivel - 1);
        char* result = (char *) malloc (sizeof(char) * (6 + 1 + strlen(nivelAnterior))); //
        sprintf (result, "(-.%s.-)", nivelAnterior);
        free (nivelAnterior);
        return result;
    }
}

// ---------- PUNTO 7 ---------------- //
// ---------- PUNTO 8 ---------------- //


char* ondaDigital(char *onda){
    int tamano_maximo;
    tamano_maximo = cant_caracteres(onda);
    char* ondaAux = (char*) malloc(((tamano_maximo) * sizeof(char)) + 1);
    int size = 0;


    ondaDigitalAux(onda, &size, &ondaAux);

    return ondaAux;

}



char* ondaDigitalAux(char *onda, int *size, char **ondaAux){

    if (*onda == '\0'){
        (*ondaAux)[*size] = '\0';
        return ondaAux;
    }else if (*onda == 'H'){
        if (*(onda+1) == 'L'){
            *size += 2;
            (*ondaAux)[*size - 2] = '-';
            (*ondaAux)[*size - 1] = '|';
            return ondaDigitalAux(onda+1, size, ondaAux);
        } else  *size += 1;
                 (*ondaAux)[*size - 1] = '-';
                 return ondaDigitalAux(onda+1, size, ondaAux); }
    else if (*onda == 'L'){
        if (*(onda+1) == 'H'){
            *size += 2;
            (*ondaAux)[*size - 2] = '_';
            (*ondaAux)[*size - 1] = '|';
            return ondaDigitalAux(onda+1, size, ondaAux);
        } else  *size += 1;
                (*ondaAux)[*size - 1] = '_';
                return ondaDigitalAux(onda+1, size, ondaAux); }

}


int cant_caracteres(char* onda){                   // funcion que cuenta los caracteres que va a tener la onda convertida
    int contador = 0;
    int i;

    for (i = 0; i < strlen(onda); i++)
    {
        if (onda[i] == 'H'){
        if (onda[i+1] == 'L'){
            contador += 2;
        } else contador++;       
    } else if (onda[i] == 'L'){
        if (onda[i+1] == 'H'){
            contador += 2;
        }else contador++;
    } 
    }

    return contador;

}

// ---------- PUNTO 8 ---------------- //

// ---------- PUNTO 9 ---------------- //

bool esDivisiblePor7(int n){
    int ultimoDigito = n % 10; //Obtiene el ultimo digito del numero
    int resto = n / 10; //Se obtiene el resto del numero, menos el ultimo digito

    if (n % 7 == 0 || n == 7)
        return true;
    else if (n < 10)
        return false;
    else
        return esDivisiblePor7(resto - 2 * ultimoDigito);

}

// ---------- PUNTO 9 ---------------- //

// ---------- PUNTO 10 ---------------- //
int *explosion(int n, int b, int *size){
    int i;
    int *arreglo = malloc(sizeof(int));

    
    explosionAux(n,b,size, &arreglo);

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