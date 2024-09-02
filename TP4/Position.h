#ifndef __POSITION__
#define __POSITION__ 

#define NB_LIGNES 8
#define NB_COLONNES 16
#define COTE1 5
#define COTE2 3

/* Inclusion de modules*/

#include "Tablette.h"
#include "Joueur.h"


/*Declaration de types*/

typedef struct {
    Tablette t;
    Joueur j_courant;
} Position;


/*Declaration de fonctions*/

int est_legal(Position pos, Coup coup);
void jouer_coup(Position *pos, Coup coup);
void afficher_position(Position pos, WINDOW *w);
Coup lire_coup(Position pos);
int est_jeu_termine(Position pos, Joueur *joueur_gagnant);

#endif
