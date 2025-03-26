#include <stdio.h>

char* reverse(char* str);

int main() {
    char texte[] = "Salut c'est moi";

    printf("%s\n", texte);
    reverse(texte);
    printf("%s\n", texte);

    return 0;
}
