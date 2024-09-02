// chmod u+x nccomp
// ./nccomp tp3.1-progc
// ./tp3.1-progc

#include <ncurses.h>

int main() {
    char chaine[128];
    int entier, coord;

    initscr();

    //getstr(chaine);
    //mvprintw(3, 0, "Chaine␣lue␣:␣%s", chaine);

    //mvscanw(10, 0, "%d", &entier);
    //mvprintw(11, 0, "Entier␣lu␣:␣%d", entier);

    /*** programme question (b) ***/
    //mvscanw(2, 4, "%s", chaine);
    /*
    move(2, 4);
    getstr(chaine);
    mvprintw(0, 0, "Chaine lue : %s", chaine);
    */

    /*** programme question (c) ***/
    coord = 0;
    do {
        mvscanw(coord, coord, "%d", &entier);
        coord ++;
    } while(entier != 0);
    

    refresh();
    getch();
    endwin();
    return 0;
}