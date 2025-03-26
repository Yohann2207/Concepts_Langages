#include "fabbriyohannlisteint.h"

/*
    Crée un nouveau maillon d'une liste d'entiers, avec une valeur aléatoire comprise entre 0 et 20.

    @input  : aucun
    @output : maillon_int * (pointeur sur le nouveau maillon alloué)

    @precondition :
        - L'environnement doit permettre l'allocation mémoire dynamique.
        - La fonction srand() doit avoir été appelée au préalable pour initialiser le générateur aléatoire (fait dans main).

    @postcondition :
        - Retourne un pointeur sur un maillon nouvellement alloué avec :
            * un champ val entre 0 et 20 inclus
            * un pointeur p_suiv initialisé à NULL.
*/
maillon_int *init_elt()
{
    maillon_int *p_nv_elt = malloc(sizeof(maillon_int));
    p_nv_elt->val = rand() % 21;
    p_nv_elt->p_suiv = NULL;
    return p_nv_elt;
}

/*
    Ajoute un maillon en tête d'une liste d'entiers.

    @input :
        - maillon_int **p_p_tete : adresse du pointeur sur le premier maillon de la liste
        - maillon_int *p_nv_elt  : pointeur sur le nouveau maillon à insérer

    @output :
        - int : code de retour
            * 0  si l'ajout est réussi
            * -1 si p_nv_elt est NULL (ajout impossible)

    @precondition :
        - *p_p_tete peut être NULL (liste vide) ou pointer sur une liste valide
        - p_nv_elt doit être alloué et valide (différent de NULL)

    @postcondition :
        - Le nouveau maillon devient le premier de la liste
        - La liste est correctement chaînée avec l'ancien premier maillon en deuxième position
*/
int ajout_tete_v3(maillon_int **p_p_tete, maillon_int *p_nv_elt)
{
    int errorCode = -1;
    if (p_nv_elt != NULL)
    {
        p_nv_elt->p_suiv = *p_p_tete;
        *p_p_tete = p_nv_elt;
        errorCode = 0;
    }
    return errorCode;
}

/*
    Parcourt et affiche les valeurs contenues dans une liste d'entiers.

    @input :
        - maillon_int *p_tete : pointeur sur le premier maillon de la liste.

    @output : void

    @precondition :
        - p_tete peut être NULL (liste vide) ou pointer sur une liste d'entiers.

    @postcondition :
        - Les valeurs de chaque maillon sont affichées dans l'ordre.
        - Si la liste est vide, un message est affiché.
*/
void parcourir(maillon_int *p_tete)
{
    // Cas : liste vide
    if (p_tete == NULL)
        printf("Liste vide\n");
    else
    {
        // Parcours de chaque maillon
        while (p_tete != NULL)
        {
            printf("%d--", p_tete->val); // affiche la valeur courante
            p_tete = p_tete->p_suiv;     // passe au suivant
        }
        putchar('\n'); // fin d'affichage
    }
}

/*
    Insère un maillon dans une liste d'entiers triée en ordre croissant.

    @input :
        - maillon_int **prem : adresse du pointeur sur le premier élément de la liste
        - maillon_int *e : pointeur sur le maillon à insérer dans la liste

    @output : void

    @precondition :
        - Le pointeur *prem peut être NULL (liste vide) ou pointer sur la tête d'une liste triée.
        - Le maillon *e est valide et correctement alloué.

    @postcondition :
        - Le maillon *e est inséré à la bonne position pour respecter l’ordre croissant.
        - La liste reste triée après l’opération.
*/
void inserer2(maillon_int **prem, maillon_int *e)
{
    maillon_int *n, *prec;
    if (*prem == NULL || e->val <= (*prem)->val)
    {
        e->p_suiv = *prem;
        *prem = e;
    }
    else
    {
        n = prec = *prem;
        while (n != NULL && e->val > n->val)
        {
            prec = n;
            n = n->p_suiv;
        }
        e->p_suiv = n; // Element après
        prec->p_suiv = e; // Element avant
    }
}

/*
    Supprime le premier élément d'une liste d'entiers si elle n'est pas vide.

    @input :
        - maillon_int **prem : adresse du pointeur sur le premier maillon de la liste.

    @output : void

    @precondition :
        - *prem peut être NULL (liste vide) ou pointer sur une liste d'entiers.

    @postcondition :
        - Si la liste n'était pas vide, le premier maillon est supprimé et la tête est mise à jour.
        - La mémoire de l'ancien premier maillon est libérée.
*/
void supprimer_debut(maillon_int **prem)
{
    maillon_int *n;

    // Vérification : liste non vide
    if (*prem != NULL)
    {
        n = *prem;             // stocke le premier maillon
        *prem = (*prem)->p_suiv; // met à jour la tête de liste
        free(n);               // libère l'ancien premier maillon
    }
}

/*
    Détruit complètement une liste d'entiers chaînée en libérant la mémoire de chaque maillon.

    @input :
        - maillon_int **prem : adresse du pointeur sur le premier maillon de la liste

    @output :
        - void

    @precondition :
        - *prem peut être NULL (liste vide) ou pointer sur une liste valide

    @postcondition :
        - Tous les maillons de la liste sont libérés
        - *prem est mis à NULL (liste vide après destruction)
*/
void detruire_liste(maillon_int **prem)
{
    maillon_int *n;
    while (*prem != NULL)
    {
        n = *prem;
        *prem = (*prem)->p_suiv;
        free(n);
    }
}

/* Permet la sérialisation format binaire dans le fichier
"saveliste.bin" de la liste d'entier (maillon_int) dont
le pointeur sur le premier élément est passé en paramètre
@input : maillon_int * prem, pointeur sur l'élément de tête de la liste à sérialiser
@output : void
@precondition : le répertoire courant et le processus père permettent l'écriture
                le pointeur prem, est soit NULL (aucune action) soit pointe sur
                le premier élément d'une liste d'entiers
@postcondition : le fichier saveliste.bin contient les éléments de la liste
                dont le premier élément est pointé par prem.
                Nota : il n'y a pas de libération de la mémoire occupée par la
                liste. Il faut donc la détruire avant d'éventuellement la recharger.
*/
void sauver_liste(maillon_int *prem)
{
    // ouvrir un fichier binaire en écriture : suffixe b
    FILE *f = fopen("saveliste.bin", "wb");
    printf("Ouvertude du fichier %p\n", f);
    // si liste non vide
    if (prem != NULL)
    {
        if (f == NULL)
            fprintf(stderr, "erreur création fichier :%i\n", errno);
        else // parcourir la liste jusque fin
            while (prem != NULL)
            {
                // écrire chaque maillon en binaire
                if (1 != fwrite(prem, sizeof(maillon_int), 1, f))
                    fprintf(stderr, "Erreur d'écriture du maillon %p\n", prem);
                else
                    // passer au maillon suivant
                    prem = prem->p_suiv;
            }
        fclose(f); // fermer le fichier
    }
    else
        fprintf(stderr, "pas de sauvegarde pour une liste vide\n");
}

/*
    Charge une liste d'entiers chaînée depuis un fichier binaire "saveliste.bin".

    @input :
        - aucun (le fichier "saveliste.bin" doit exister dans le répertoire courant)

    @output :
        - maillon_int * : pointeur sur le premier maillon de la liste chargée
            * NULL si le fichier n'existe pas ou si une erreur survient lors du chargement

    @precondition :
        - Le fichier "saveliste.bin" doit avoir été correctement créé par sauver_liste()
        - La structure de la liste dans le fichier est conforme à celle de maillon_int

    @postcondition :
        - Retourne un pointeur vers la liste recréée en mémoire
        - La mémoire de chaque maillon est correctement allouée et chaînée
*/
maillon_int *load_liste()
{
    FILE *f;
    maillon_int *prem = NULL, *p, e;
    if ((f = fopen("saveliste.bin", "rb")) != NULL)
    {
        prem = malloc(sizeof(maillon_int));
        fread(prem, sizeof(maillon_int), 1, f);
        p = prem;
        while (fread(&e, sizeof(maillon_int), 1, f))
        {
            p->p_suiv = malloc(sizeof(maillon_int));
            p = p->p_suiv;
            *p = e;
            p->p_suiv = NULL;
        }
        fclose(f);
    }
    else
        printf("erreur ou fichier inexistant");
    return prem;
}

/*
    Supprime tous les maillons d'une liste ayant une valeur égale à val.

    @input :
        - maillon_int **prem : adresse du pointeur sur la tête de liste.
        - int val : valeur à rechercher et à supprimer.

    @output :
        - bool : true si au moins un maillon a été supprimé, false sinon.

    @precondition :
        - *prem peut être NULL (liste vide) ou pointer sur une liste valide.

    @postcondition :
        - Tous les maillons dont la valeur est val sont supprimés.
        - La mémoire de ces maillons est libérée.
*/
bool supprime_elt(maillon_int **premier, int val)
{
    bool trouve = false;
    maillon_int *courant = *premier; //pointeur sur le maillon qu’on est en train de lire
    maillon_int *prec = NULL; //le maillon précédent pour relier les maillons entre eux quand on supprime

    while (courant != NULL)
    {
        if (courant->val == val)
        {
            maillon_int *tmp = courant;

            if (prec == NULL) {
                // Suppression si premier
                *premier = courant->p_suiv;
                courant = *premier;
            } else {
                // Suppression si milieu ou fin
                prec->p_suiv = courant->p_suiv;
                courant = prec->p_suiv;
            }

            free(tmp);
            trouve = true;
        }
        else
        {
            prec = courant;
            courant = courant->p_suiv;
        }
    }

    return trouve;
}


