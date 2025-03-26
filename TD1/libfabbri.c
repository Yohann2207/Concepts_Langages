#include <stdio.h>
#include <string.h>

// Fonction qui renverse une chaîne en place
char* reverse(char* c) {
    if (c == NULL){
        return NULL;
    }
    
    int debut = 0;
    int fin = strlen(c) - 1;

    while (debut < fin) {
        char temp = c[debut];
        c[debut] = c[fin];
        c[fin] = temp;

        debut++;
        fin--;
    }

    return c;
}
