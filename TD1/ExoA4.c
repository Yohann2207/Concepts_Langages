#include <stdio.h>
#include <ncurses.h>

int main() {
    char c1, c2, c3;

    printf("Entrez trois caracteres : ");
    scanf("%c %c %c", &c1, &c2, &c3);
    printf("Vous avez saisi : %c, %c, %c", c1, c2, c3);
}