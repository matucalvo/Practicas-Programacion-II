#include <assert.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../recursividad.h"

int main() {
    imprimir_titulo("Tests para palíndromos");

    printf(" 'saippuakivikauppias' ==> %d \n", esPalindromo("saippuakivikauppias"));
    printf(" 'palindromo' ==> %d \n", esPalindromo("palindromo"));
    printf(" 'isosai' ==> %d \n", esPalindromo("isosai"));

    return 0;
}
