#include "position.h"

#include <ncurses.h>

#define taille_case 3

int echange_color(int color);
void afficher_position_graphique(Position pos);
Case case_par_coord(int souris_x, int souris_y);
