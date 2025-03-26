#include <stdio.h>
#include "factorielle.h"

int main() {
    int n;

    printf("Entrez un entier : ");
    scanf("%d", &n);

    printf("Classique : %d! = %d\n", n, produit_classique(n));
    printf("Terminal : %d! = %d\n", n, produit_terminal(n, 1));

    return 0;
}
