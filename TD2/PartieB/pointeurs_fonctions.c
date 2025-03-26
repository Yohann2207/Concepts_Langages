#include "pointeurs_fonctions.h"

// Fonction qui multiplie un entier par 2
int fois_deux(int i) {
    return i * 2;
}

// Applique une transformation à un tableau
void appliquerATableauPurPointeurs(int f(int), int* t, int n) {
    int *ptr = t;
    for (; ptr < t + n; ptr++) {
        *ptr = f(*ptr);
    }
}

// Applique une transformation avec deux paramètres
void appliquerATableauDeuxParam(int (*f)(int, int), int* t, int n, int valeur) {
    int *ptr = t;
    for (; ptr < t + n; ptr++) {
        *ptr = f(*ptr, valeur);
    }
}

int f1(int a, int b) { 
    return a + b; 
}

int soustraction(int a, int b) { 
    return a - b; 
}

int multiplication(int a, int b) { 
    return a * b; 
}

int division(int a, int b) {
    if( b!= 0){
        return a / b;
    }
    else{
        return 0; 
    }
}
