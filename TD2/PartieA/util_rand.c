#include "util_rand.h"

// Initialise le générateur de nombres aléatoires
void init_random() {
    srand(time(NULL));
}

// Retourne un nombre aléatoire dans la plage maximale de rand
int rand_max() {
    return rand();
}

// Retourne un nombre aléatoire entre 0 et max
int rand_seuil_haut(int max) {
    return rand() % (max + 1);
}

// Retourne un nombre aléatoire entre min et max
int rand_borne(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Retourne un nombre réel entre 0 et 1
double rand_0_1() {
    return (double)rand() / RAND_MAX;
}

// Retourne un nombre réel avec deux décimales entre min et max
double rand_borne_decimale(double min, double max) {
    double scale = rand_0_1(); 
    double result = min + scale * (max - min);
    return ((int)(result * 100)) / 100.0; // Arrondi à 2 décimales
}