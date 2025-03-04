#include "factorielle.h"

// Récursivité classique
int produit_classique(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * produit_classique(n - 1);
}

// Récursivité terminale
int produit_terminal(int n, int accumulateur) {
    if (n <= 1) {
        return accumulateur;
    }
    return produit_terminal(n - 1, n * accumulateur);
}
