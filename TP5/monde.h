/*Inclusioin de modules*/

#include "type.h"

/* Declaration de types */

typedef struct{
    int nb_lignes;
    int nb_colonnes;
    Serpent s;
    Pomme pomme;
    int nb_mangees;
}Monde;

/* Declaration de fonctions */

int case_valide(Case* cell, Case * serp_pom);
void monde_ajouter_pomme(Monde *mon);
void monde_supprimer_pomme(Monde *mon, int ligne, int colonne);

Monde monde_initialiser(int nb_lignes, int nb_colonnes, int taille_serpent, int nb_pommes);
int monde_est_mort_serpent(Monde mon);
int monde_insere_tete_serpent(Monde * mon, int ligne, int colonne);
void monde_evoluer_serpent(Monde *mon);
