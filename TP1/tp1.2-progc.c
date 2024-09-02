// chmod u+x nccomp
// ./nccomp tp1.2-progc
// ./tp1.2-progc

#include <ncurses.h>

/*int main() {
    initscr();

    attron(A_NORMAL);
    printw("Normal␣␣␣␣␣␣␣␣␣␣␣␣␣␣:␣ABCabc012\n");

    attron(A_REVERSE);
    printw("Inverse␣␣␣␣␣␣␣␣␣␣␣␣␣:␣ABCabc012\n");
    attroff(A_REVERSE);

    attron(A_BOLD);
    printw("Gras␣␣␣␣␣␣␣␣␣␣␣␣␣␣␣␣:␣ABCabc012\n");
    attroff(A_BOLD);

    attron(A_UNDERLINE);
    printw("Souligne␣␣␣␣␣␣␣␣␣␣␣␣:␣ABCabc012\n");
    attroff(A_UNDERLINE);

    attron(A_REVERSE | A_BOLD);
    printw("Inverse␣et␣souligne␣:␣ABCabc012\n");
    attron(A_NORMAL);

    refresh();
    getch();
    endwin();

    return 0;

}*/

int main() {
    initscr();

    attron(A_UNDERLINE | A_BOLD);
    printw("*10*");

    refresh();
    getch();
    endwin();
    return 0;

}
