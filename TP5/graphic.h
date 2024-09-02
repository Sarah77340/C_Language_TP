/*Inclusioin de modules*/
#include "monde.h"
#include "ncurses.h"

/* Declaration de types */

/* Declaration de fonctions */
int echange_color(int color);
void interface_afficher_quadrillage(Monde mon);
void interface_afficher_pomme(Pomme pom);
void interface_afficher_serpent(Serpent ser);
void interface_afficher_monde(Monde mon);
void interface_piloter(Monde *mon, int touche);
