#ifndef HORAIRES_H
#define HORAIRES_H

#include <stdio.h>
#include <stdbool.h>  
#include <string.h>
#include <stdlib.h>

typedef struct MaillonHoraire {
    char villeDepart[50];    
    char villeArrivee[50];   
    char heureDepart[6];     // (format "HHhMM")
    char heureArrivee[6];    // (format "HHhMM")
    int distance;           
    struct MaillonHoraire *next;
} MaillonHoraire;

bool ajouterHoraire(MaillonHoraire **tete, char *villeDep, char *villeArr, char *heureDep, char *heureArr, int distance);
void afficherHoraires(MaillonHoraire *tete);
bool afficherTrainsDepart(MaillonHoraire *tete, char *villeDepart);
void afficherTrajetVitesseMax(MaillonHoraire *tete);
void trierHorairesParHeureDepart(MaillonHoraire **tete);

#endif 
