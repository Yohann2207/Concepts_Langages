#include "tri_fonctions.h"

// Fonction de comparaison : renvoie 1 si a > b, 0 si a == b, -1 sinon
int superieur(int a, int b) {
    return (a > b) ? 1 : (a < b) ? -1 : 0;
}

// Fonction de comparaison : renvoie 1 si a < b, 0 si a == b, -1 sinon
int inferieur(int a, int b) {
    return (a < b) ? 1 : (a > b) ? -1 : 0;
}

// Fonction de tri utilisant un pointeur de fonction pour la comparaison
void tri(int* t, int n, int (*compare)(int, int)) {
    int i, j, i_min, tmp;

    for (i = 0; i < n - 1; i++) {
        i_min = i;
        for (j = i + 1; j < n; j++) {
            if (compare(t[j], t[i_min]) < 0) {
                i_min = j;
            }
        }
        if (i_min != i) {
            tmp = t[i];
            t[i] = t[i_min];
            t[i_min] = tmp;
        }
    }
}
