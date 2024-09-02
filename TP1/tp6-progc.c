#include <ncurses.h>

int main() {
    int entier;
    int i, j;
    initscr();
    do{
        mvscanw(0, 0, "%d", &entier);
    }while(entier < 0);
    for(i = 0; i < entier; i++){
        for(j = 0; j <= i; j++){
            mvprintw(1 + i, j, "*");
        }
    }
    refresh();
    getch();
    endwin();
    return 0;
}