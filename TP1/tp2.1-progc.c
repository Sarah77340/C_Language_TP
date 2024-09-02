// chmod u+x nccomp
// ./nccomp tp2.1-progc
// ./tp2.1-progc

#include <ncurses.h>
#include <unistd.h>

#define DELAI 50000

/*int main() {
    int x, y;

    initscr();

    x = 0;
    y = 0;

    while(1) {
        clear();
        mvaddch(y, x, 'o');
        //refresh();

        usleep(DELAI);
        x = (x + 1) % COLS;
        y = (y + 1) % LINES;
    }

    endwin();
    return 0;
}*/


int main() {
    int x, y;

    initscr();

    x = 0;
    y = 0;

    /*** solution question (b) ***/
    /*
    mvaddch(0, 0, '*');
    mvaddch(0, COLS - 1, '*');
    mvaddch(LINES - 1, 0, '*');
    mvaddch(LINES - 1, COLS - 1, '*');

    while(1) {
        //clear();        
        mvaddch(y, x, 'o');
        refresh();
        usleep(DELAI);
        mvaddch(y, x, ' ');
        x = (x + 1) % COLS;
        y = (y + 1) % LINES;
    }
    */


    /*** solution question (c) ***/
    
    mvaddch(0, 0, '*');
    mvaddch(0, COLS - 1, '*');
    mvaddch(LINES - 1, 0, '*');
    mvaddch(LINES - 1, COLS - 1, '*');

    while(1) {
        //clear();     
        mvaddch(y, x, 'o');
        refresh();

        usleep(DELAI);
        mvdelch(y, x);
        x = (x + 1) % COLS;
        y = (y + 1) % LINES;
    }


    endwin();
    return 0;
}