#include "puissance.h"

// Récursivité classique
int puissance_classique(int n, int p) {
    if (p == 0) {
        return 1;
    }
    return n * puissance_classique(n, p - 1);
}

// Récursivité terminale
int puissance_terminal(int n, int p, int accumulateur) {
    if (p == 0) {
        return accumulateur;
    }
    return puissance_terminal(n, p - 1, n * accumulateur);
}
