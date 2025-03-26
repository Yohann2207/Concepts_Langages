#include "fabbriyohannlisteint.h"

int menu()
{
    int choix = 0;
    printf("0 Quitter\n"
           "1 Creer une liste d'entiers compris entre 0 et 20 de taille aleatoire comprise entre 1 et 20\n"
           "2 Ajouter un element entier aleatoire (compris entre 0 et 20) en tete de liste\n"
           "3 Inserer un element entier aleatoire dans sa place dans la liste suivant l'ordre croissant des premiers elements\n"
           "4 Supprimer l'element de tete\n"
           "5 Supprimer tous les maillons d'une valeur donnee\n"
           "6 Detruire liste\n"
           "7 Sauver la liste courante en binaire dans le fichier \"saveliste.bin\"\n"
           "8 Charger une liste depuis le fichier \"savelist.bin\"\n");

    scanf("%d", &choix);
    rewind(stdin);

    return choix;
}

int main()
{
    maillon_int *premier = NULL;    // pointeur sur le premier maillon de la liste
    maillon_int *nouveau;   // pointeur pour les nouveaux maillons
    int fin = 0;    // drapeau de fin de boucle
    int i, nb, valeur;  // variables de menu et de saisie

    srand((unsigned)time(NULL));    // initialise le générateur de nombres aléatoires
    while (!fin)
    {
        i = menu();
        switch (i)
        {
        case 0: // Quitter
        fin = 1;
        break;

        case 1: // Creer une liste de taille aleatoire
            detruire_liste(&premier);

            // Générer un nombre aléatoire entre 1 et 20 (taille de la liste)
            nb = 1 + rand() % 20;

            // Boucle pour créer la liste
            for (i = 0; i < nb; i++)
            {
                nouveau = init_elt();
                ajout_tete_v3(&premier, nouveau);
            }

            printf("La liste creee est : ");
            parcourir(premier);
            break;

        case 2: // Ajouter
            nouveau = init_elt();
            ajout_tete_v3(&premier, nouveau);
            printf("Ajout effectue en tete. Liste actuelle : ");
            parcourir(premier);
            break;

        case 3: // Inserer (ordre croissant)
            nouveau = init_elt();
            inserer2(&premier, nouveau);
            printf("Insertion effectuee dans l'ordre croissant. Liste actuelle : ");
            parcourir(premier);
            break;

        case 4: // Supprimer debut
            supprimer_debut(&premier);
            printf("Suppression de tete effectuee. Liste actuelle : ");
            parcourir(premier);
            break;

        case 5: // Supprimer un maillon d'une valeur donnee
            printf("Entrez la valeur a supprimer : ");
            scanf("%d", &valeur);
            rewind(stdin);
            if (!supprime_elt(&premier, valeur))
                printf("Valeur non trouvee.\n");
            else
            {
                printf("Nouvelle liste : ");
                parcourir(premier);
            }
            break;

        case 6: // detruire liste
            detruire_liste(&premier);
            printf("Liste detruite.\n");
            break;

        case 7: // Sauver liste
            sauver_liste(premier);
            break;

        case 8: // Charger liste
            detruire_liste(&premier);  // Nettoyer avant de charger
            premier = load_liste();
            printf("Liste chargee depuis le fichier. Liste actuelle : ");
            parcourir(premier);
            break;

        default:

            break;
        }
    }

    return 0;
}