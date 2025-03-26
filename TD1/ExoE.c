#include <stdio.h>
#include <string.h>

// Cela peut corrompre des données voisines, provoquer des crashs ou bien meme permettre a un attaquant d'exécuter du code malveilllant (injection)

int main() {
    char buffer[5];

    printf("Entrez une chaine de caracteres : ");
    gets(buffer);

    printf("Vous avez tape : %s\n", buffer);

    return 0;
}
