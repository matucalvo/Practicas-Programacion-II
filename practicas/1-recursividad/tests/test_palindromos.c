#include <assert.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

void probar (char *c, bool esperado){
    bool resultado = esPalindromo(c);
    printf("La palabra %s es palindromo? %s\n", c, resultado == 1? "Verdadero":"Falso");
    assert(bool_eq(resultado,esperado));
}

int main() {
    imprimir_titulo("Tests para palíndromos");
    //Test propuestos (testear con letras en minuscula)
    probar("neuquen", true);
    probar("palindromo",false);

    //Test adicionales (testear con letras en minuscula)
    probar("saippuakivikauppias", true);
    probar("isosai", false);

    return 0;
}
