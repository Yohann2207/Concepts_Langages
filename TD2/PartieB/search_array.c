#include "search_array.h"
#include <stdlib.h>

// Fonction qui recherche un élément dans un tableau avec des pointeurs
int searchArray(int *tab, int taille, int element, int **position) {
    if (tab == NULL) {  
        return -1;  
    }

    for (int i = 0; i < taille; i++) {
        if (*tab == element) {
            *position = tab;  
            return 0;  
        }
        tab++;
    }
    return -1;
}


