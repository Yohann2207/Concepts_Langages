#include <stdio.h>

// Tableau des valeurs romaines et leurs équivalents en chiffres arabes
typedef struct {
    int valeur;
    char *symbole;
} Roman;

void convertToRoman(int num) {
    Roman romains[] = {
        {1000, "M"}, {500, "D"}, {100, "C"}, {50, "L"}, 
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    int i = 0; 

    while (num > 0) {
        // Tant que le nombre est supérieur ou égal à la valeur actuelle, on soustrait et affiche
        while (num >= romains[i].valeur) {
            printf("%s", romains[i].symbole);
            num -= romains[i].valeur;
        }
        i++; 
    }
}

int main() {
    int number;
    
    printf("Entrez un nombre entier : ");
    scanf("%d", &number);
    
    if (number <= 0) {
        printf("Les nombres romains commencent à 1 !\n");
    } else {
        printf("En notation romaine moderne : ");
        convertToRoman(number);
        printf("\n");
    }
    
    return 0;
}
