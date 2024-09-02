// chmod u+x nccomp
// ./nccomp tp1.1-progc
// ./tp1.1-progc

#include <ncurses.h>

int main() {
    initscr();

    /*** version 1 ***/
    /*
    move(8, 4);
    addch('4');
    addch('!');
    addch('+');
    addch('2');
    addch('!');
    */

    /*** version 2 ***/
    /*
    mvaddch(8, 4, '4');
    mvaddch(8, 5, '!');
    mvaddch(8, 6, '+');
    mvaddch(8, 7, '2');
    mvaddch(8, 8, '!');
    */

    /*** version 3 ***/
    mvprintw(3, 3, "4!+2!");


    refresh();
    getch();
    endwin();
    return 0;
}