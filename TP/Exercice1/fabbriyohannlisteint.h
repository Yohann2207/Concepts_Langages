#ifndef FABBRIYOHANNLISTEINT_H
#define FABBRIYOHANNLISTEINT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

// Structure du maillon
typedef struct maillon
{
    int val;    // La valeur stockée dans le maillon
    struct maillon *p_suiv; // Pointeur vers le prochain maillon
} maillon_int;

// Prototypes des fonctions
maillon_int *init_elt();
int ajout_tete_v3(maillon_int **p_p_tete, maillon_int *p_nv_elt);
void parcourir(maillon_int *p_tete);
void inserer2(maillon_int **prem, maillon_int *e);
void supprimer_debut(maillon_int **prem);
void detruire_liste(maillon_int **prem);
void sauver_liste(maillon_int *prem);
maillon_int *load_liste();
bool supprime_elt(maillon_int **prem, int val);

#endif
