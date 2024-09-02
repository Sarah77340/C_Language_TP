// chmod u+x nccomp
// ./nccomp tp5-progc
// ./tp5-progc

#include <ncurses.h>

int echange_color(int color){
    if (color == 1)
        return 2;
    return 1;
}
int main(void){
    int x, y;
    int i, j;
    int color;
    initscr();

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_RED);
    init_pair(2, COLOR_WHITE, COLOR_GREEN);

    curs_set(FALSE);

    x = COLS / 2;
    y = LINES / 2;
    color = 1;

    for (j = 0; j < 10; j++){
        for (i = 0; i < 10; i++){
            attron(COLOR_PAIR(color));
            mvprintw(y, x, "  ");
            attroff(COLOR_PAIR(color));

            color = echange_color(color);
            x += 2;
        }
        y -= 1;
        x = COLS / 2;
        color = echange_color(color);
    }

    refresh();
    getch();
    endwin();

    return 0;
}