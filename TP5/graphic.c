#include "graphic.h"

int echange_color(int color){
    if (color == 1)
        return 2;
    
    return 1;
}

void interface_afficher_quadrillage(Monde mon){
    int x, y;
    int i, j;
    int color;
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_CYAN);

    x = 0;
    y = LINES - (mon.nb_colonnes/2);
    color = 1;

    for (j = 0; j < mon.nb_lignes; j++){
        for (i = 0; i < mon.nb_colonnes; i++){
            attron(COLOR_PAIR(color));
            mvprintw(y, x, "   ");
            attroff(COLOR_PAIR(color));

            color = echange_color(color);
            x += 3;
        }
        y -= 1;
        x = 0;
        color = echange_color(color);
    }
    refresh();
}

void interface_afficher_pomme(Pomme pom){
    int color;
    if (pom != NULL){
        color = 3;
        init_pair(3, COLOR_WHITE, COLOR_RED);
        attron(COLOR_PAIR(color));
        mvprintw(LINES - (20/2) - (20 - 3 - pom->ligne) , (pom->colonne)*3, "   ");
        attroff(COLOR_PAIR(color));
        refresh();
        interface_afficher_pomme(pom->next);
    }
}

void interface_afficher_serpent(Serpent ser){
    int color;
    Case* tmp;
    tmp = ser.tete->next;;
    color = 4;

    init_pair(4, COLOR_WHITE, COLOR_YELLOW);
    init_pair(5, COLOR_WHITE, COLOR_WHITE);
    attron(COLOR_PAIR(color));
    mvprintw(LINES - (20/2) - (20 - 3 - ser.tete->ligne) , (ser.tete->colonne)*3, "   ");
    attroff(COLOR_PAIR(color));

    color = 5;
    attron(COLOR_PAIR(color));
    while (tmp != NULL){
        mvprintw(LINES - (20/2) - (20 - 3 - tmp->ligne) , (tmp->colonne)*3, "   ");
        tmp = tmp->next;
    }
    attroff(COLOR_PAIR(color));
    refresh();
}

void interface_afficher_monde(Monde mon){
    interface_afficher_quadrillage(mon);
    interface_afficher_pomme(mon.pomme);
    interface_afficher_serpent(mon.s);
}

void interface_piloter(Monde *mon, int touche){
    if(touche == KEY_UP)
        mon -> s.direction = NORD;
    
    else if(touche == KEY_DOWN)
        mon -> s.direction = SUD;
    
    else if(touche == KEY_LEFT)
        mon -> s.direction = OUEST;
    
    else if(touche == KEY_RIGHT)
        mon -> s.direction = EST;
}
