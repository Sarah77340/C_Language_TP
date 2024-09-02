#include "Joueur.h"

Joueur adversaire(Joueur joueur){
    /* Renvoie l'adversaire de joueur */
    if (joueur == JOUEUR_1)
        return JOUEUR_2;
    return JOUEUR_1;
}

void afficher_joueur(Joueur j){
    /* Affiche dans la fenêtre le tour du joueur
    */
    if (j == JOUEUR_1){
        mvprintw(0, COLS - 25, "joueur 1 à toi de jouer");
    }
    else
        mvprintw(0, COLS - 25, "joueur 2 à toi de jouer");
}
