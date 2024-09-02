//
// Exercice 2: CarreClic.c
// Created by Manar Nssair and Sarah Nguyen on 10/02/2022.
//

// gcc -std=c17 -Wall CarreClic.c -lncurses -lm -o CarreClic
// ./CarreClic

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

int echange_coor(int color){
    if (color == 1)
        return 2;
    return 1;
}

void dessine_carre(int largeur, int color){
    int i, j;
    int x, y;
    start_color();

    init_pair(1, COLOR_WHITE, COLOR_RED);
    init_pair(2, COLOR_WHITE, COLOR_BLUE);

    attron(COLOR_PAIR(color));

    x = COLS/2;
    y = LINES/2;

    for (i = 0; i < (largeur/2) + 1; i++){
        for (j = 0; j < largeur + 1; j++){
            mvprintw(y+i, x+j, " ");
            mvprintw(y+i, x-j, " ");
            mvprintw(y-i, x+j, " ");
            mvprintw(y-i, x-j, " ");
        }

    }
    attroff(COLOR_PAIR(color));
}

int main(void){
    int touche;
    int largeur;
    int souris_x, souris_y;
    int color;
    MEVENT ev;

    initscr();
    noecho();
    keypad(stdscr, TRUE);

    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    largeur = 7;
    color = 1;

    dessine_carre(largeur, color);
    while(1){
        touche = getch();
        if (touche == KEY_MOUSE && getmouse(&ev) == OK){
            souris_x = ev.x;
            souris_y = ev.y;

            if (souris_x < (COLS/2) + largeur && souris_x > (COLS/2) - largeur 
            && souris_y < (LINES/2) + largeur && souris_y > (LINES/2) - largeur){
                color = echange_coor(color);
                dessine_carre(largeur, color);
                refresh();

            }
        }
    }
    
    refresh();
    getch();
    endwin();

    return 0;
}
