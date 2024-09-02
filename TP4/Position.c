#include "Position.h"

int est_legal(Position pos, Coup coup){
    /* Vérifie que le carré que l'on souhaite manger existe 
    *  renvoie 1 si c'est vérifié
    *  renvoie 0 sinon
    */
    if(pos.t.tab[coup.x][coup.y] == 1)
        return 1;
    return 0;
}

void jouer_coup(Position *pos, Coup coup){
    /* Joue le coup à la position pos
    */
    if(est_legal(*pos, coup)){
        manger(&(pos->t), coup.x, coup.y);
        pos->j_courant = adversaire(pos->j_courant);
        afficher_joueur(pos->j_courant);
    }
}

void afficher_position(Position pos, WINDOW *w){
    /* Affiche sur la fenêtre la position pos
    */
    int i, j;
    for(i = 0; i < NB_LIGNES*COTE2; i = i + COTE2){
        for(j = 0; j < NB_COLONNES*COTE1; j = j + COTE1){
            if (pos.t.tab[i/COTE2][j/COTE1] == 1){
                w = subwin(stdscr, COTE2, COTE1, i, j);
                box(w, ACS_VLINE, ACS_HLINE);
                wrefresh(w);
            }
        }
    }
}

Coup lire_coup(Position pos){
    /* Attend un clic de l'utilisateur sur la tablette de chocolat dans la fenêtre graphique
    *  et renvoie le coup spécifié 
    */
    Coup coup;
    MEVENT ev;
    int souris_x, souris_y;
    int touche;
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    while(1){
        touche = getch();
        if (touche == KEY_MOUSE && getmouse(&ev) == OK){
            souris_x = ev.x;
            souris_y = ev.y;

            if ((souris_y < (NB_LIGNES*COTE2) - COTE2/2)
            && (souris_x < (NB_COLONNES*COTE1) - COTE1/2 + 1)){
                if (verif_coord(pos.t, souris_x, souris_y, &coup) == 1){
                    return coup;
                }
            }
        }
    }  
}

int est_jeu_termine(Position pos, Joueur *joueur_gagnant){
    /* Vérifie si la partie est terminée:  si le joueur a mangé 
    *  le carré empoisonné
    *  renvoie 1 si le jeu se termine
    *  renvoie 0 sinon
    */
    if (pos.t.nb_carrees_restants == 0){
        *joueur_gagnant = pos.j_courant;
        return 1;
    }
    return 0;
}
