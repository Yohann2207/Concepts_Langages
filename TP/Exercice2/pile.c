#include "pile.h"

/* Question 1 :
Pour l’implémentation d'une Pile j’ai choisi d’utiliser une liste chaînée simple. Ce choix s’explique par la nature même de la 
pile, où les opérations se font uniquement au sommet. La liste chaînée simple permet une gestion dynamique de la mémoire, sans avoir à 
définir de taille maximale à l’avance, contrairement à un tableau statique qui impose une capacité fixe. Elle offre également des opérations 
d’ajout (empiler) et de suppression (dépiler) de complexité O(1), ce qui garantit une bonne performance. J’ai écarté l’option du tableau 
dynamique, car bien qu’il permette d’ajouter des éléments de façon flexible, il nécessite des réallocations (realloc()) coûteuses en cas de 
dépassement de capacité. De même, je n’ai pas choisis la liste doublement chaînée, car la navigation dans les deux sens est inutile pour une 
pile et alourdirait la structure avec des pointeurs supplémentaires. La liste chaînée simple est donc la solution la plus adaptée 
à l’implémentation d’une pile d’entiers.
*/

bool estVide(Entier *pile) {
    return pile == NULL;
}

void empiler(Entier **pile, int valeur) {
    Entier *nouveau = malloc(sizeof(Entier));
    nouveau->nombre = valeur;
    nouveau->next = *pile; 
    *pile = nouveau; 
}

void afficher(Entier *pile) {
    while(pile != NULL) {
        printf("%d -> ", pile->nombre);
        pile = pile->next;
    }
    printf("NULL\n");
}


int sommet(Entier *pile, int *val) {
    if(estVide(pile)){
        printf("pile vide.");
        return -1;
    }
    else{
        *val = pile->nombre;
    }
}

void depiler(Entier **pile, int *valeur) {
    if (estVide(*pile)) {
        printf("la pile est vide.\n");
    }

    *valeur = (*pile)->nombre;

    Entier *temp = *pile;
    *pile = (*pile)->next;
    free(temp);
}

void renverser(Entier **pile) {
    Entier *pileInverse = NULL;
    int valeur = 0;

    while (*pile != NULL) {
        depiler(pile, &valeur);          
        empiler(&pileInverse, valeur);   
    }

    *pile = pileInverse;
}
