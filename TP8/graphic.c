#include "graphic.h"

int echange_color(int color){
    if (color == 1)
        return 2;
    return 1;
}

void afficher_position_graphique(Position pos){
    int i, j, x, y, color;
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);

    x = (COLS/2) - (taille_case*4);
    y = LINES/2 - 4;
    color = 1;
    for (i = 56; i >= 0; i-= 8){
        for (j = 0; j < 8; j++){
            if (((pos.pos >> (i+j)) & 1) == 1){
                attron(COLOR_PAIR(color));
                mvprintw(y, x, " R ");
                attroff(COLOR_PAIR(color));
            }
            else {
                attron(COLOR_PAIR(color));
                mvprintw(y, x, "   ");
                mvprintw(y, x, "   ");
                attroff(COLOR_PAIR(color));
                }
            x += taille_case;
            color = echange_color(color);
        }
        x = (COLS/2) - (taille_case*8/2);
        y += 1;
        color = echange_color(color);
    }
}

Case case_par_coord(int souris_x, int souris_y){
    int x, y;
    Case c;
    x = (souris_x - ((COLS/2) - (taille_case*4))) /3;
    y = souris_y - (LINES/2 - 4);
    c = (56 - (8*y)) +  x;
    return c;
}
