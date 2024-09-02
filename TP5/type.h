/*Inclusioin de modules*/

#include <stdio.h>
#include <stdlib.h>

/* Declaration de types */

typedef struct cell{
    int ligne;
    int colonne;
    struct cell *next;
}Case, *Pomme;

typedef enum{
    NORD,
    SUD,
    EST,
    OUEST
}Direction;

typedef struct{
    Direction direction;
    Case* tete;
}Serpent;


/* Declaration de fonctions */

int case_initialiser(int colonne, int ligne, Case * c, int taille);
Pomme pomme_aleatoire(int nb_lignes, int nb_colonnes);

Serpent serpent_initialiser(int nb_lignes, int nb_colonnes, int taille);
Case serpent_case_visee(Serpent serp);
int toucher_tete_serpent(int ligne_visee, int colonne_visee, Case * c);
void corps_serpent_avance(Case * c, int ligne, int colonne);
