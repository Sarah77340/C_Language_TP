#ifndef __TABLETTE__
#define __TABLETTE__ 

#define NB_LIGNES 8
#define NB_COLONNES 16
#define COTE1 5
#define COTE2 3

/* Inclusion de modules*/

#include "Coup.h"


/*Declaration de types*/

typedef struct tablette{
    int tab[NB_LIGNES][NB_COLONNES];
    int nb_carrees_restants;
    int taille;
} Tablette;


/*Declaration de fonctions*/

Tablette creer_tablette(void);
void manger(Tablette *tab, int x, int y);
int verif_coord(Tablette t, int x, int y, Coup * coup);

#endif
