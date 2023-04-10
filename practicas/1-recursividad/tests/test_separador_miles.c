#include <assert.h>
#include <stdlib.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"



void probar(char *numero, char *esperado){
    char *res = agregarSeparadorMiles(numero);

    printf("Cadena: %s --> %s", numero, res);

    assert(str_eq(res, esperado));

    free(res);

}





int main() {
    imprimir_titulo("Tests para agregarSeparadorMiles");

    char numero[] = "123456"; // numero a agregarle puntos
    char numero1[] = "12345678";
    char numero2[] = "67389219";
    char numero3[] = "567";

    char numeroConPuntos[] = "123.456"; // numero esperado
    char numeroConPuntos1[] = "12.345.678";
    char numeroConPuntos2[] = "67.389.219";
    char numeroConPuntos3[] = "567";

    probar(numero, numeroConPuntos);
    printf("\n");
    probar(numero1, numeroConPuntos1);
    printf("\n");
    probar(numero2, numeroConPuntos2);
    printf("\n");
    probar(numero3, numeroConPuntos3);

    return 0;
}
