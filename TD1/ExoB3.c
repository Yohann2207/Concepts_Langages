#include <stdio.h>
#include <stdlib.h>

int main() {
    char *c = NULL;
    int *i = NULL;
    float *f = NULL;
    char reponse;

    do {
        c = (char*)malloc(sizeof(char));
        i = (int*)malloc(sizeof(int));
        f = (float*)malloc(sizeof(float));

        if (c == NULL || i == NULL || f == NULL) {
            printf("Erreur d'allocation mémoire.\n");
            free(c);
            free(i);
            free(f);
            return 1;
        }

        printf("Entrez un caractere : ");
        scanf("%c", c);  

        printf("Entrez un entier : ");
        scanf("%d", i);

        printf("Entrez un float : ");
        scanf("%f", f);

        printf("char = '%c', int = %d, float = %.2f\n", *c, *i, *f);

        free(c);
        free(i);
        free(f);

        printf("Voulez-vous recommencer ? (o/n) : ");
        scanf("%c", &reponse);

    } while (reponse == 'o');

    return 0;
}
