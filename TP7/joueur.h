#include "jeu.h"
#include <ctype.h>

/* Declaration de types */

typedef struct {
    int score;
    int nb_tentatives;
    char mot_selec[20];
    char * mots_trouves[4];
}Joueur;

/* Declaration de fonctions */

Joueur * allouer_joueur();
void calcul_score(Joueur * j);
void ajouter_c_mot_selec(Joueur * joueur, char c);
void supprimer_fin_chaine(Joueur * joueur);
void ajouter_mots_trouves(Joueur * j, char * mot);
int valider_mot_selec(Joueur * j, ATR t);
