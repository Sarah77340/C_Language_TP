//
// Exercice 2: Rebond.c
// Created by Manar Nssair and Sarah Nguyen on 10/02/2022.
//

// gcc -std=c17 -Wall Rebond.c -lncurses -lm -o Rebond
// ./Rebond

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

#define TPS_ATTENTE 1000000

void efface_carre(int largeur, int y, int x){
    int i, j;
    start_color();
    init_pair(3, COLOR_WHITE, COLOR_WHITE);

    attron(COLOR_PAIR(3));
    for (i = 0; i < (largeur/2) + 1; i++){
        for (j = 0; j < largeur + 1; j++){
            mvprintw(y+i, x+j, " ");
            mvprintw(y+i, x-j, " ");
            mvprintw(y-i, x+j, " ");
            mvprintw(y-i, x-j, " ");
        }

    }
    attroff(COLOR_PAIR(3));
}

void dessine_carre(int largeur, int y, int x){
    int i, j;
    start_color();
    init_pair(2, COLOR_WHITE, COLOR_BLUE);

    attron(COLOR_PAIR(2));
    for (i = 0; i < (largeur/2) + 1; i++){
        for (j = 0; j < largeur + 1; j++){
            mvprintw(y+i, x+j, " ");
            mvprintw(y+i, x-j, " ");
            mvprintw(y-i, x+j, " ");
            mvprintw(y-i, x-j, " ");
        }

    }
    attroff(COLOR_PAIR(2));
}

void dessine_rectangle(int hauteur, int largeur){
    int i, j;
    int x, y;
    start_color();

    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    attron(COLOR_PAIR(1));

    x = COLS/2;
    y = LINES/2;

    for (i = 0; i < (hauteur/2) + 1; i++){
        for (j = 0; j < largeur + 1; j++){
            mvprintw(y+i, x+j, " ");
            mvprintw(y+i, x-j, " ");
            mvprintw(y-i, x+j, " ");
            mvprintw(y-i, x-j, " ");
        }
    }
    attroff(COLOR_PAIR(1));
}

int main(void){
    int touche;
    int hauteur, largeur, longeur_carre;
    int x, y;
    int deplacement_x, deplacement_y;
    int pas;

    initscr();
    noecho();
    keypad(stdscr, TRUE);

    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    hauteur = 15;
    largeur = 51;
    longeur_carre = 3;
    x = COLS/2;
    y = LINES/2;
    pas = 2;
    deplacement_x = pas;
    deplacement_y = -pas;

    dessine_rectangle(hauteur, largeur);
    dessine_carre(longeur_carre, y, x);
    refresh();

    while(1){
        touche = getch();
        if (touche == '\n'){
            while(1){
                touche = getch();

                if (touche == '\n')
                    break;
                
                efface_carre(longeur_carre, y, x);
                refresh();
                
                x += deplacement_x;
                y += deplacement_y;
                dessine_carre(longeur_carre, y, x);
                refresh();
                usleep(TPS_ATTENTE);

                if (y + deplacement_y < ((LINES/2) - hauteur/2)) //sors par le haut
                    deplacement_y = pas;

                if (y + deplacement_y > ((LINES/2) + hauteur/2)) //sors par le bas
                    deplacement_y = -pas;

                if ((x - longeur_carre + deplacement_x) < ((COLS/2) - largeur)) //sors par la gauche
                    deplacement_x = pas;
                    
                if ((x + longeur_carre + deplacement_x) > ((COLS/2) + largeur)) //sors par la droite
                    deplacement_x = -pas;
                    
            }
            break;
        
        }
    
    }
    

    refresh();
    getch();
    endwin();

    return 0;
}
