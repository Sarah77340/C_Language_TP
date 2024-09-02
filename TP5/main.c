#include "graphic.h"

int main(void){
    Monde mon;
    int touche;
    mon = monde_initialiser(20, 16, 4, 4);

    initscr();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    noecho();
    keypad(stdscr, TRUE);
    interface_afficher_monde(mon);

    while(!monde_est_mort_serpent(mon)){
        touche = getch();
        if (touche)
            interface_piloter(&mon, touche);

        monde_evoluer_serpent(&mon);
        interface_afficher_monde(mon);
        usleep(250000);
    }
    nodelay(stdscr, FALSE);
    mvprintw(3, 0, "score final: %d", mon.nb_mangees);
    refresh();
    getch();
    endwin();
    return 0;
}
