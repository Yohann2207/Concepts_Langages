#include "somme_tableau.h"
#include <stdlib.h>
#include <stdio.h>

int sommeTableau(int *tab, int taille, int *resultat) {
    if (tab == NULL || resultat == NULL) {
        return -1;
    }

    int somme = 0;

    for (int i = 0 ; i < taille; i++) {
        somme += *tab;  // Accès à la valeur pointée
        tab++;
    }

    *resultat = somme;
    return 0;
}
