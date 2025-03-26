#include "horaires.h"

bool ajouterHoraire(MaillonHoraire **tete, char *villeDep, char *villeArr, char *heureDep, char *heureArr, int distance) {
    MaillonHoraire *nouveau = malloc(sizeof(MaillonHoraire));

    strcpy(nouveau->villeDepart, villeDep);
    strcpy(nouveau->villeArrivee, villeArr);
    strcpy(nouveau->heureDepart, heureDep);
    strcpy(nouveau->heureArrivee, heureArr);
    nouveau->distance = distance;

    nouveau->next = *tete;
    *tete = nouveau;

    printf("Ajout de l'horaire : %s -> %s (%s -> %s), %d km\n", villeDep, villeArr, heureDep, heureArr, distance);

    return true;
}

void afficherHoraires(MaillonHoraire *tete) {
    if (tete == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    printf("Horaires de trains :\n");
    while (tete != NULL) {
        printf("%s -> %s | Depart : %s | Arrivee : %s | Distance : %d km\n",tete->villeDepart, tete->villeArrivee, tete->heureDepart, tete->heureArrivee, tete->distance);
        tete = tete->next;
    }
}

bool afficherTrainsDepart(MaillonHoraire *tete, char *villeDepart) {
    if (tete == NULL) {
        printf("La liste est vide.\n");
        return false;
    }

    bool trouve = false;
    printf("Trains au depart de %s :\n", villeDepart);
    while (tete != NULL) {
        if (strcmp(tete->villeDepart, villeDepart) == 0) {
            printf("%s -> %s | Depart : %s | Arrivee : %s | Distance : %d km\n", tete->villeDepart, tete->villeArrivee, tete->heureDepart, tete->heureArrivee, tete->distance);
            trouve = true;
        }
        tete = tete->next;
    }

    if (!trouve)
        printf("Aucun train trouve.\n");

    return trouve;
}

void afficherTrajetVitesseMax(MaillonHoraire *tete) {
    if (tete == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    MaillonHoraire *trajetPlusRapide = NULL;
    int vitesseMax = 0;

    while (tete != NULL) {
        int depHeure, depMinute, arrHeure, arrMinute;
        
        sscanf(tete->heureDepart, "%2dh%2d", &depHeure, &depMinute);
        sscanf(tete->heureArrivee, "%2dh%2d", &arrHeure, &arrMinute);

        int departMin = depHeure * 60 + depMinute;
        int arriveeMin = arrHeure * 60 + arrMinute;

        int duree = arriveeMin - departMin;

        int vitesseMoyenne = tete->distance / duree * 60;
        if (vitesseMoyenne > vitesseMax) {
            vitesseMax = vitesseMoyenne;
            trajetPlusRapide = tete;
        }

        tete = tete->next;
    }

    if (trajetPlusRapide != NULL) {
        printf("\nTrajet avec la vitesse moyenne la plus elevee :\n");
        printf("%s -> %s | Depart : %s | Arrivee : %s | Distance : %d km\n",trajetPlusRapide->villeDepart, trajetPlusRapide->villeArrivee, trajetPlusRapide->heureDepart, trajetPlusRapide->heureArrivee, trajetPlusRapide->distance);
        printf("Vitesse moyenne : %d km/h\n", vitesseMax);
    }
}

void trierHorairesParHeureDepart(MaillonHoraire **tete) {
    if (*tete == NULL || (*tete)->next == NULL) {
        return;
    }

    MaillonHoraire *listeTriee = NULL;

    while (*tete != NULL) {
        MaillonHoraire *tmp = *tete;
        *tete = (*tete)->next;

        int tmpHeure, tmpMinute;
        sscanf(tmp->heureDepart, "%2dh%2d", &tmpHeure, &tmpMinute);
        int tmpMinutes = tmpHeure * 60 + tmpMinute;

        if (listeTriee == NULL) {
            tmp->next = NULL;
            listeTriee = tmp;
        } else {
            int teteTrieeHeure, teteTrieeMinute;
            sscanf(listeTriee->heureDepart, "%2dh%2d", &teteTrieeHeure, &teteTrieeMinute);
            int teteTrieeMinutes = teteTrieeHeure * 60 + teteTrieeMinute;

            if (tmpMinutes < teteTrieeMinutes) {
                tmp->next = listeTriee;
                listeTriee = tmp;
            } else {
                MaillonHoraire *p = listeTriee;
                while (p->next != NULL) {
                    int nextHeure, nextMinute;
                    sscanf(p->next->heureDepart, "%2dh%2d", &nextHeure, &nextMinute);
                    int nextMinutes = nextHeure * 60 + nextMinute;

                    if (tmpMinutes < nextMinutes){
                        break;
                    }
                    p = p->next;
                }
                tmp->next = p->next; //Element après
                p->next = tmp; //Element avant
            }
        }
    }

    *tete = listeTriee;
}



