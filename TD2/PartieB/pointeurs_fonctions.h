#ifndef POINTEURS_FONCTIONS_H
#define POINTEURS_FONCTIONS_H

int fois_deux(int i);

void appliquerATableauPurPointeurs(int f(int), int* t, int n);

void appliquerATableauDeuxParam(int (*f)(int, int), int* t, int n, int valeur);

int f1(int a, int b);

int soustraction(int a, int b);

int multiplication(int a, int b);

int division(int a, int b);

#endif
