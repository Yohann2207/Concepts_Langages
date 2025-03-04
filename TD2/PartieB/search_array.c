#include "search_array.h"
#include <stdlib.h>

// Fonction qui recherche un élément dans un tableau avec des pointeurs
int searchArray(int *tab, int taille, int element, int **position) {
    if (tab == NULL) {
        return -1;
    }

    int *ptr = tab;  // Définition d'un pointeur pour parcourir le tableau

    // Parcours du tableau avec un pointeur
    for (; ptr < tab + taille; ptr++) {
        if (*ptr == element) {
            *position = ptr;
            return 0;
        }
    }
    return -1;
}
