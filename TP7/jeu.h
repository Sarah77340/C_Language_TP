#include "dico.h"
#include <time.h>

/* Declaration de types */

typedef struct {
    char c;
    int p;
}Lettre;

typedef struct {
    char grille[4][4];
}Jeu;

/* Declaration de fonctions */

char generer_lettre_aleatoire(Lettre Tab[26]);
void init_grille(Lettre Tab[26], Jeu * j);
void afficher_grille(Jeu * jeu);
void appel_init_grille(Jeu * j);
