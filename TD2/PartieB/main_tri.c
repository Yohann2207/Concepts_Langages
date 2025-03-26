#include <stdio.h>
#include "tri_fonctions.h"

int main() {
    int tab[] = {42, 12, 89, 23, 56};
    int taille = sizeof(tab) / sizeof(tab[0]);

    // Affichage du tableau avant le tri
    printf("Tableau original : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    tri(tab, taille, inferieur);
    printf("Tableau trie en ordre decroissant : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    int tab2[] = {42, 12, 89, 23, 56};

    tri(tab2, taille, superieur);
    printf("Tableau trie en ordre croissant : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab2[i]);
    }
    printf("\n");

    return 0;
}
