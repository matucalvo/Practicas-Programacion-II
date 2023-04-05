
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

    char ondaDigital[] = "‾|_"; // onda digital esperada

    probar(cadenaAconvertir, ondaDigital);


    

    return 0;
}
