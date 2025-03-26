#include <stdio.h>

// Fonction d'addition : additionne a et b, stocke le résultat dans c
void add(int a, int b, int* c) {
    *c = a + b;
}

int main() {
    int x = 3;
    int y = 8;
    int resultat;

    add(x, y, &resultat);

    printf("La somme de %d et %d est : %d\n", x, y, resultat);

    return 0;
}
