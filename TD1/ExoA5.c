#include <stdio.h>

#define pscanf(message, format, var) \
    printf("%s", message); \
    scanf(format, var);

int main() {
    int age;
    float taille;

    pscanf("Entrez votre age : ", "%d", &age);
    pscanf("Entrez votre taille en metres : ", "%f", &taille);

    printf("Vous avez %d ans, mesurez %.2f metres", age, taille);
}