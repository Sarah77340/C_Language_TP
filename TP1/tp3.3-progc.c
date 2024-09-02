// chmod u+x nccomp
// ./nccomp tp3.3-progc
// ./tp3.3-progc

#include <ncurses.h>
#include <unistd.h>

int main() {
    int touche, val, delai;

    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    val = 0;
    delai = 1000000;

    mvprintw(0, 0, "Valeur : ");
    attron(A_BOLD);
    mvprintw(0, 9, "%3d", val);
    attroff(A_BOLD);
    while (1) {
        touche = getch();
        if (touche != ERR) {
            if (touche == 'q')
            break;
            if (touche == 'r')
            val = 0;
            //if (touche == 'b')
            if (touche == KEY_UP)
            delai /= 2;
            //if (touche == 't')
            if (touche == KEY_DOWN)
            delai *= 2;
        }
        //mvprintw(0, 0, "Valeur : %3d", val);
        attron(A_BOLD);
        mvprintw(0, 9, "%3d", val);
        attroff(A_BOLD);
        refresh();

        val = (val + 1) % 128;
        usleep(delai);
    }

    getch();
    endwin();
    return 0;

}