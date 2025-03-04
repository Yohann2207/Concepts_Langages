#include <stdio.h>
#include <stdlib.h>
#include "somme_tableau.h"

int main() {

    int resultat;
    int tab_stat[] = {1, 2, 3, 4, 5};
    int taille_stat = sizeof(tab_stat) / sizeof(tab_stat[0]);

    if (sommeTableau(tab_stat, taille_stat, &resultat) == 0) {
        printf("Somme du tableau statique : %d\n", resultat);
    } else {
        printf("Erreur : Pointeur NULL pour le tableau statique.\n");
    }

    int *tab_null = NULL;
    if (sommeTableau(tab_null, 5, &resultat) == -1) {
        printf("Erreur : Pointeur NULL detecte pour le tableau dynamique.\n");
    }
    
    int taille;

    printf("Entrez la taille du tableau : ");
    scanf("%d", &taille);

    // Allocation dynamique du tableau
    int *tab = malloc(taille * sizeof(int));

    for (int i = 0; i < taille; i++) {
        printf("Element %d : ", i + 1);
        scanf("%d", tab + i);  
    }

    sommeTableau(tab, taille, &resultat);
    printf("Somme des elements : %d\n", resultat);

    // Libération de la mémoire
    free(tab);

    return 0;
}
