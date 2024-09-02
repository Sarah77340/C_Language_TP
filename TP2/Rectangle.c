//
// Exercice 2: Rectangle.c
// Created by Manar Nssair and Sarah Nguyen on 10/02/2022.
//

// gcc -std=c17 -Wall Rectangle.c -lncurses -lm -o Rectangle
// ./Rectangle

#include <ncurses.h>
#include <string.h>

int main(){
    initscr();
    int hauteur, largeur, i, j, centre_x, centre_y;
    hauteur = 3;
    largeur = 15;
    centre_x = COLS / 2;
    centre_y = LINES / 2;
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_RED);
    curs_set(FALSE);

    for(j = centre_y - hauteur / 2; j <= centre_y + hauteur / 2; j++){
        for(i = centre_x - largeur / 2; i <= centre_x + largeur / 2; i ++){
            attron(COLOR_PAIR(1));
            mvaddch(j, i,' ');
            attroff(COLOR_PAIR(1));
            refresh();
        }
    }
    refresh();
    getch();
    endwin();
    return 0;
}