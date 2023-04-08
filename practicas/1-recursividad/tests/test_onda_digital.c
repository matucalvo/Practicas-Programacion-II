#include <stdlib.h>
#include <assert.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

void probar(char *cadena, char *esperado){
    char *res = ondaDigital(cadena);

    printf("Cadena: %s --> %s", cadena, res);

    assert(str_eq(res, esperado));

    free(res);

}







int main() {
    imprimir_titulo("Tests del Ejercicio de Onda Digital");

    char cadenaAconvertir[] = "HL"; // cadena para transformar a onda digital
    char cadenaAconvertir1[] = "LH";
    char cadenaAconvertir2[] = "HLHL";
    char cadenaAconvertir3[] = "HLLHHL";

    char ondaDigital[] = "-|_"; // onda digital esperada
    char ondaDigital1[] = "_|-";
    char ondaDigital2[] = "-|_|-|_";
    char ondaDigital3[] = "-|__|--|_";



    probar(cadenaAconvertir, ondaDigital);
    printf("\n");
    probar(cadenaAconvertir1, ondaDigital1);
    printf("\n");
    probar(cadenaAconvertir2, ondaDigital2);
    printf("\n");
    probar(cadenaAconvertir3, ondaDigital3);


    

    return 0;
}
