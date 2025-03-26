#include "horaires.h"

int main() {
    MaillonHoraire *tete = NULL;

    ajouterHoraire(&tete, "Lille", "Paris", "08h00", "08h59", 237);
    ajouterHoraire(&tete, "Lille", "Lyon", "07h00", "10h00", 709);
    ajouterHoraire(&tete, "Lille", "Calais", "15h19", "18h34", 110);
    ajouterHoraire(&tete, "Paris", "Marseille", "12h00", "18h00", 900);
    ajouterHoraire(&tete, "Lyon", "Marseille", "10h07", "15h01", 450);
    ajouterHoraire(&tete, "Lyon", "Marseille", "11h50", "17h00", 450);

    afficherHoraires(tete);

    afficherTrainsDepart(tete, "Lille");
    afficherTrainsDepart(tete, "Paris");

    afficherTrajetVitesseMax(tete);

    trierHorairesParHeureDepart(&tete);

    afficherHoraires(tete);

    return 0;
}
