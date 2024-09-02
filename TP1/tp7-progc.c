#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


void deplace_o(int *x, int *y){
    int haut_bas, drotie_gauche;
    haut_bas = rand()%2;
    drotie_gauche = rand()%2;

    mvprintw(*x, *y, "x");

    if (drotie_gauche == 1) {

        if (haut_bas % 2 == 1) {
            *y = (*y - (rand() % COLS - *y));
        } else {
            *y = (*y + (rand() % COLS - *y));
        }
    }
    else {
        if (haut_bas % 2 == 1) {
            *x = (*x - (rand() % LINES - *x));
        } else {
            *x = (*x + (rand() % LINES - *x));
        }
    }
    mvprintw(*x, *y, "o");
}

int main (){
    srand(time(NULL));
    int x, y, delai, touche;
    initscr();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    noecho();
    x = LINES / 2;
    y = COLS / 2;
    delai = 1000000;
    mvprintw(x, y, "o");
    refresh();
    while (1) {
        touche = getch();
        if (touche != ERR) {
            if (touche == '\n')
                while (1) {
                    touche = getch();
                    if (touche == '\n')
                        break;
                }
            if (touche == KEY_UP)
                delai /= 2;
            if (touche == KEY_DOWN)
                delai *= 2;
            if (touche == 'q')
                return 1;
        }
        usleep(delai);
        deplace_o(&x, &y);
        refresh();
    }
}