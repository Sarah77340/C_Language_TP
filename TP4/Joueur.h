#ifndef __JOUEUR__
#define __JOUEUR__ 

#include <ncurses.h>

/*Declaration de types*/

typedef enum {
    JOUEUR_1,
    JOUEUR_2
} Joueur;


/*Declaration de fonctions*/

Joueur adversaire(Joueur joueur);
void afficher_joueur(Joueur j);

#endif
