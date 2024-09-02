#include "Position.h"

int main(void){
    WINDOW *w;
    Position pos;
    Coup coup;
    Joueur joueur_gagnant;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    w = subwin(stdscr, LINES/2, COLS/2, 0, 0);
    pos.t = creer_tablette();
    pos.j_courant = JOUEUR_1;

    afficher_joueur(pos.j_courant);
    afficher_position(pos, w);
    wrefresh(w);
    
    while(1){
        coup = lire_coup(pos);
        clear();
        jouer_coup(&pos, coup);
        afficher_position(pos, w);
        refresh();

        if (est_jeu_termine(pos, &joueur_gagnant) == 1){
            clear();
            mvprintw(0, 0, "Le joueur n°%d a gagné la partie!", joueur_gagnant+1);
            refresh();
            usleep(900000);
            break;
        }
    }

    endwin();
    return 0;
}
