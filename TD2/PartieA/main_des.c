#include <stdio.h>
#include "jeu_des.h"

int main() {
    int choix;
    init_random();
    do {
        printf("1. Jouer avec 1 de\n");
        printf("2. Jouer avec 2 des\n");
        printf("3. Jouer avec 3 des\n");
        printf("4. Jouer avec 4 des\n");
        printf("5. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        if (choix >= 1 && choix <= 4) {
            jouer_des(&choix);
        }
    } while (choix != 5);
    return 0;
}
