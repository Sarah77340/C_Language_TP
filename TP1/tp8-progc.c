// chmod u+x nccomp
// ./nccomp tp8-progc
// ./tp8-progc

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#define MAXLINES 10
#define MAXCOLS 40

typedef struct {
    char plateau[MAXLINES][MAXCOLS];
    int x;
} Plateau;

void init_plateau(Plateau * plat){
    int x, y;
    for (y = 0; y < MAXLINES; y++){
        for (x = 0; x < MAXCOLS; x++){
            plat->plateau[y][x] = '0';
        }
    }
}

void affiche_plateau(Plateau * plat){
    int x, y;
    char val;
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);

    for (y = 0; y < MAXLINES; y++){
        for (x = 0; x < MAXCOLS; x++){
            val = plat->plateau[y][x];
            if (val == '3'){
                attron(COLOR_PAIR(1));
                mvprintw(y, x, "  ");
                attroff(COLOR_PAIR(1));
            }
            else 
                mvprintw(y, x, "%c", val);
        }
    }
}

void action_case_plateau(Plateau * plat, int y, int x){
    if (plat->plateau[y][x] != '3')
        plat->plateau[y][x] += 1;
}


int main(void){
    int touche;
    int souris_x, souris_y;
    MEVENT ev;

    Plateau plateau_jeu;
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    init_plateau(&plateau_jeu);
    affiche_plateau(&plateau_jeu);

    while (1) {
        touche = getch();
        if (touche == 'q')
            break;
        if (touche == KEY_MOUSE && getmouse(&ev) == OK) {
            souris_x = ev.x;
            souris_y = ev.y;

            if (souris_y < MAXLINES && souris_x < MAXCOLS){
                action_case_plateau(&plateau_jeu, souris_y, souris_x);
                affiche_plateau(&plateau_jeu);
                refresh();
            }
        }
    }
    refresh();
    getch();
    endwin();

    return 0;
}