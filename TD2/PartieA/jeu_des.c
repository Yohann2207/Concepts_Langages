#include <stdio.h>
#include <stdlib.h>
#include "jeu_des.h"

// Fonction pour jouer avec les dés
void jouer_des(int *nb_des) {
    int *des = malloc(*nb_des * sizeof(int));  // Allocation dynamique pour stocker les valeurs des dés
    int i, total = 0, relance;
    int *seuil_gagner = malloc(sizeof(int)); // Allocation dynamique pour stocker le seuil

    printf("\nVous avez choisi %d de(s)\n", *nb_des);

    // Lancer les dés une première fois
    for (i = 0; i < *nb_des; i++) {
        *(des + i) = rand_borne(1, 6);
        printf("De %d : %d\n", i, *(des + i));
    }

    // Vérifier et relancer les dés identiques
    do {
        relance = 0;
        for (i = 0; i < *nb_des - 1; i++) {
            if (*(des + i) == *(des + i + 1)) {
                printf("Des identiques relances...\n");
                *(des + i) = rand_borne(1, 6);
                *(des + i + 1) = rand_borne(1, 6);
                relance = 1;
                for (int j = 0; j < *nb_des; j++) {
                    printf("De %d : %d\n", j, *(des + j));
                }
            }
        }
    } while (relance);

    // Calculer la somme des dés
    for (i = 0; i < *nb_des; i++) {
        total += *(des + i);
    }

    // Calcul du seuil pour gagner (2/3 du max possible)
    int max_possible = (*nb_des) * 6;
    *seuil_gagner = (max_possible * 2) / 3;
    int difference = *seuil_gagner - total;

    // Afficher le résultat final
    printf("\nLa somme des %d des lances est de %d, le seuil etait de %d\n", *nb_des, total, *seuil_gagner);
    if (total >= *seuil_gagner) {
        printf("Felicitations ! Vous avez gagne !\n");
    } else {
        printf("Score inferieur de %d au seuil\n", difference);
        printf("Desole, vous avez perdu !\n");
    }

    // Libération de la mémoire
    free(des);
    free(seuil_gagner);
}
