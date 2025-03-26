#ifndef PILE_H
#define PILE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Entier{
    int nombre;
    struct Entier *next;
} Entier;

bool estVide(Entier *e);
void empiler(Entier **e, int nombre);
void afficher(Entier *e);
int sommet(Entier *e, int *nombre);
void depiler(Entier **e, int *nombre);
void renverser(Entier **e);

#endif