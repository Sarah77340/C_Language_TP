#include "joueur.h"
#include <ncurses.h>

/* Declaration de fonctions */

void afficher_grille_graph(Jeu jeu, int i_lettre, int j_lettre);
int cases_voisines(int col, int li, int x, int y);
void selectioner_mot(Jeu jeu, Joueur * joueur, ATR A);
