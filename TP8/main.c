#include "graphic.h"

int main(){
    Position pos, tmp;
    Case c;
    MEVENT ev;
    int souris_x, souris_y, touche, cmpt;
    pos.pos = 0;
    tmp = pos;
    cmpt = 0;
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    afficher_position_graphique(pos);
    refresh();

    while(1){
        touche = getch();
        if (touche == KEY_MOUSE && getmouse(&ev) == OK){
            souris_x = ev.x;
            souris_y = ev.y;
            if ((souris_x >= (COLS/2) - (taille_case*4)) 
            && (souris_x < (COLS/2) + (taille_case*4)) 
            && (souris_y >= (LINES/2 - 4)) && (souris_y < (LINES/2 + 4))){
                c = case_par_coord(souris_x, souris_y);
                placer_dame_position(&tmp, c);
                mvprintw(LINES/2 - 6, (COLS/2) - taille_case*4, "                    ");
                refresh();
                if (est_sans_attaque_mutuelle(tmp) == 1){
                    pos = tmp;
                    cmpt += 1;
                }
                else{
                    tmp = pos;
                    mvprintw(LINES/2 - 6, (COLS/2) - taille_case*4, "impossible d'ajouter");
                }
                afficher_position_graphique(pos);
                refresh();
                
            }
        }
        if(joueur_gagne(pos, cmpt)){
            break;
        }
        refresh();
    }
    clear();
    mvprintw(LINES/2, COLS/2, "Vous avez gagné!");
    nodelay(stdscr, FALSE);
    refresh();
    getch();
    endwin();
    return 0;
}
