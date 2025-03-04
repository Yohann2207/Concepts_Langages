#include <stdio.h>
#include "util_rand.h"

int main() {
    init_random();

    printf("Nombre aleatoire max: %d\n", rand_max());
    printf("Nombre aleatoire entre 0 et 10: %d\n", rand_seuil_haut(10));
    printf("Nombre aleatoire entre 5 et 15: %d\n", rand_borne(5, 15));
    printf("Nombre reel entre 0 et 1: %f\n", rand_0_1());
    printf("Nombre reel entre 1.5 et 4.5 avec 2 decimales: %.2f\n", rand_borne_decimale(1.5, 4.5));

    return 0;
}
