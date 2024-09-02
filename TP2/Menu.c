//
// Exercice 2: Menu.c
// Created by Manar Nssair and Sarah Nguyen on 16/02/2022.
//

// gcc -std=c17 -Wall Menu.c -lncurses -lm -o Menu
// ./Menu

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#define NB_CHOIX 4
#define TPS_ATTENTE 1000000
#define PAS 2


/****** rebond functions ****************/

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

void efface_rectangle(int hauteur, int largeur){
    int i, j;
    int x, y;
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
}

int rebond(void){
    int touche;
    int hauteur, largeur, longeur_carre;
    int x, y;
    int deplacement_x, deplacement_y;

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
    deplacement_x = PAS;
    deplacement_y = -PAS;

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
                    deplacement_y = PAS;

                if (y + deplacement_y > ((LINES/2) + hauteur/2)) //sors par le bas
                    deplacement_y = -PAS;

                if ((x - longeur_carre + deplacement_x) < ((COLS/2) - largeur)) //sors par la gauche
                    deplacement_x = PAS;
                    
                if ((x + longeur_carre + deplacement_x) > ((COLS/2) + largeur)) //sors par la droite
                    deplacement_x = -PAS;
            }
            break;
        }
    }
    efface_rectangle(hauteur, largeur);
    refresh();
    getch();
    endwin();
    return 0;
}


/****** other functions ****************/

void calcul_vitesse(void){
    mvprintw(LINES/2, COLS/2, "attente: %d pas/seconde", PAS /(TPS_ATTENTE/1000000));
}

void credit(void){
    mvprintw(LINES/3, COLS/2, "Auteurs: Manar Nssair et Sarah Nguyen");
    mvprintw(LINES/3 + 1, COLS/2, "Affiliation: L2 informatique à Gustave Eiffel");
    mvprintw(LINES/3 + 2, COLS/2, "Date édition: 16.02.2022");
}

void affiche_menu(int choix, char * lst[NB_CHOIX]){
    int i;
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    
    for (i= 0; i < NB_CHOIX; i++){
        if (choix == i){
            attron(COLOR_PAIR(1));
            mvprintw(i, 0, "%s", lst[i]);
            attroff(COLOR_PAIR(1));
        }
        else 
            mvprintw(i, 0, "%s", lst[i]);
    }
}


int main(void){
    int choix;
    int touche;
    char * lst[NB_CHOIX];

    initscr();
    noecho();
    keypad(stdscr, TRUE);

    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    choix = 0;
    lst[0] = "Démarrer";
    lst[1] = "Options";
    lst[2] = "Credits";
    lst[3] = "Quitter";

    affiche_menu(choix, lst);
    refresh();

    while(1){
        touche = getch();
        switch(touche){
            case KEY_UP : 
                if ((choix - 1) >= 0){
                    choix -= 1;
                } break;
            case KEY_DOWN : 
                if ((choix + 1) <= NB_CHOIX - 1){
                    choix += 1;
                } break;

            case '\n' :
                if (choix == 0) 
                    rebond(); 

                if (choix == 1) 
                    calcul_vitesse(); 
                
                if (choix == 2) 
                    credit(); 

                if (choix == 3){
                    endwin(); 
                    return 0;
                }
                break;

            case '1': rebond(); break;

            case '2': calcul_vitesse(); break;

            case '3': credit(); break;

            case '4': endwin(); return 0;

        }
        affiche_menu(choix, lst);
        refresh();
        
    }
    refresh();
    getch();
    endwin();

    return 0;
}