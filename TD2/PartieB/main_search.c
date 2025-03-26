#include <stdio.h>
#include <stdlib.h>
#include "search_array.h"

int main() {
    int element;
    int *position;

    // Test avec un tableau statique
    int tab_stat[] = {3, 7, 12, 5, 9};
    int taille_stat = sizeof(tab_stat) / sizeof(tab_stat[0]);

    printf("\nEntrez l'element a rechercher dans le tableau statique : ");
    scanf("%d", &element);

    if (searchArray(tab_stat, taille_stat, element, &position) == 0) {
        printf("Element trouve dans le tableau statique a l'adresse %p, valeur : %d\n", (void *)position, *position);
    } else {
        printf("Element non trouve dans le tableau statique.\n");
    }

    //Test avec un tableau dynamique
    int taille_dyn;
    printf("\nEntrez la taille du tableau dynamique : ");
    scanf("%d", &taille_dyn);

    int *tab_dyn = malloc(taille_dyn * sizeof(int));
    if (tab_dyn == NULL) {
        printf("Erreur d'allocation memoire !\n");
        return 1;
    }

    // Remplissage du tableau avec arithmétique des pointeurs
    printf("Entrez les %d elements du tableau dynamique :\n", taille_dyn);
    int *ptr_dyn = tab_dyn;
    for (int i = 0; i < taille_dyn; i++) {
        printf("Element : ");
        scanf("%d", ptr_dyn);
        ptr_dyn++;
    }

    printf("\nEntrez l'element a rechercher dans le tableau dynamique : ");
    scanf("%d", &element);

    if (searchArray(tab_dyn, taille_dyn, element, &position) == 0) {
        printf("Element trouve dans le tableau dynamique a l'adresse %p, valeur : %d\n", (void *)position, *position);
    } else {
        printf("Element non trouve dans le tableau dynamique.\n");
    }

    // Libération de la mémoire
    free(tab_dyn);

    return 0;
}
