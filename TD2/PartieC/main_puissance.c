#include <stdio.h>
#include "puissance.h"

int main() {
    int n, p;

    printf("Entrez un nombre et un exposant : ");
    scanf("%d %d", &n, &p);

    printf("Classique = %d^%d = %d\n", n, p, puissance_classique(n, p));
    printf("Terminal = %d^%d = %d\n", n, p, puissance_terminal(n, p, 1));

    return 0;
}
