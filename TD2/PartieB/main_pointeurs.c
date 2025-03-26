#include <stdio.h>
#include "pointeurs_fonctions.h"

int main() {
    int tab[] = {1, 2, 3, 4};
    int taille = sizeof(tab) / sizeof(tab[0]);
    int valeur;

    printf("Tableau original : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    appliquerATableauDeuxParam(f1, tab, taille, 10);

    printf("Tableau apres f1 : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    // Demande d'une valeur à ajouter/soustraire/multiplier/diviser
    printf("Entrez une valeur pour les transformations : ");
    scanf("%d", &valeur);

    // Appliquer différentes opérations mathématiques
    int (*operations[4])(int, int) = {f1, soustraction, multiplication, division};
    char *noms_operations[] = {"Addition", "Soustraction", "Multiplication", "Division"};

    for (int i = 0; i < 4; i++) {
        appliquerATableauDeuxParam(operations[i], tab, taille, valeur);
        printf("Tableau apres %s : ", noms_operations[i]);
        for (int j = 0; j < taille; j++) {
            printf("%d ", tab[j]);
        }
        printf("\n");
    }

    return 0;
}
