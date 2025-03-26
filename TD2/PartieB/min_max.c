#include <stdio.h>

// Fonction qui cherche le maximum dans un tableau
void trouverMax(int* tableau, int taille, int* max) {
    if (tableau == NULL) {
        printf("Paramètres invalides.\n");
        return;
    }

    *max = *tableau;

    for (int i = 1; i < taille; i++) {
        if (*(tableau + i) > *max) {
            *max = *(tableau + i);
        }
    }
}

int main() {
    int tab[] = {12, 45, 7, 89, 32, 5};
    int taille = 6;
    int max = 0;

    trouverMax(tab, taille, &max);

    printf("Le maximum du tableau est : %d\n", max);

    return 0;
}
