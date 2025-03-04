#include <stdio.h>
#include <stdlib.h>
#include "stat_rand.h"

void test_stat_rand(int nb_tirages) {
    int occurrences[6] = {0}; // Tableau pour stocker le nombre d'apparitions de chaque valeur
    int i, valeur;

    // Réaliser les tirages
    for (i = 0; i < nb_tirages; i++) {
        valeur = rand_seuil_haut(5);
        occurrences[valeur]++;
    }

    // Affichage des résultats
    printf("\nResultat :\n");
    for (i = 0; i < 6; i++) {
        double pourcentage = ((double)occurrences[i] / nb_tirages) * 100;
        printf("Valeur %d : %d occurrences (%.2f%%)\n", i, occurrences[i], pourcentage);
    }
}
