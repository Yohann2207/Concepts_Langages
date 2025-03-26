#include "pile.h"

int main() {
    Entier *mapile = NULL;
    int val = 0;

    empiler(&mapile, 10);
    empiler(&mapile, 20);
    empiler(&mapile, 30);
    empiler(&mapile, 40);
    empiler(&mapile, 50);
    empiler(&mapile, 60);

    sommet(mapile, &val);

    printf("Sommet de la pile : %d\n", val);

    afficher(mapile);

    depiler(&mapile, &val);
    printf("Valeur depilee : %d\n", val);

    afficher(mapile);

    renverser(&mapile);

    afficher(mapile);

    renverser(&mapile);

    afficher(mapile);

    return 0;
}