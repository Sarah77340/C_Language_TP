// chmod u+x nccomp
// ./nccomp tp3.2-progc
// ./tp3.2-progc

#include <ncurses.h>

int main() {
    int touche;
    int x, y;
    int x_prec, y_prec;
    int N;

    initscr();
    noecho();

    x = COLS / 2;
    y = LINES / 2;
    N = 1;

    mvaddch(y, x, 'o');

    while (1) {
        x_prec = x;
        y_prec = y;

        mvprintw(LINES-1, 0, "Pas : %d", N);
        touche = getch();
        if (touche == 'q' && (x - N) >= 0 )
            x -= N;
        if (touche == 'd' && (x + N) < COLS )
            x += N;
        if (touche == 'z' && (y - N) >= 0 )
            y -= N;
        if (touche == 's' && (y + N) < LINES )
            y += N;
        if (touche == 'i'){
            x = COLS / 2;
            y = LINES / 2;
        }
        if (touche == 'p')
            N += 1;
        if (touche == 'm' && (N - 1) > 0)
            N -= 1;

        mvaddch(y_prec, x_prec, ' ');
        mvaddch(y, x, 'o');
        refresh();
    }

    getch();
    endwin();
    return 0;
}