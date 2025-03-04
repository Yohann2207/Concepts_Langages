#include "somme_tableau.h"
#include <stdlib.h>

int sommeTableau(int *tab, int taille, int *resultat) {
    if (tab == NULL || resultat == NULL) {
        return -1;
    }

    int somme = 0;
    int *ptr = tab;  // Pointeur qui commence au début du tableau
    int *fin = tab + taille;  // Adresse après la dernière case du tableau

    for (; ptr < fin; ptr++) {
        somme += *ptr;  // Accès à la valeur pointée
    }

    *resultat = somme;
    return 0;
}
