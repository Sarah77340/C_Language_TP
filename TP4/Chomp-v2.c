//
// TP4 : version2
// Created by Manar Nssair and Sarah Nguyen on 24/02/2022.
//

// gcc -std=gnu99 -Wall Chomp-v2.c -lncurses -lm -o Chomp-v2
// ./Chomp-v2

#include <ncurses.h>
#define NB_LIGNES 8
#define NB_COLONNES 16
#define COTE1 5
#define COTE2 3

typedef struct tablette{
    int tab[NB_LIGNES][NB_COLONNES];
    int nb_carrees_restants;
    int taille;
} Tablette;

typedef enum {
    JOUEUR_1,
    JOUEUR_2
} Joueur;

typedef struct {
    Tablette t;
    Joueur j_courant;
} Position;

typedef struct {
    int x;
    int y;
} Coup;


void afficher_joueur(Joueur j){
    /* Affiche dans la fenêtre le tour du joueur
    */
    if (j == JOUEUR_1){
        mvprintw(0, COLS - 25, "joueur 1 à toi de jouer");
    }
    else
        mvprintw(0, COLS - 25, "joueur 2 à toi de jouer");
}

void afficher_position(Position pos, WINDOW *w){
    /* Affiche sur la fenêtre la position pos
    */
    int i, j;
    for(i = 0; i < NB_LIGNES*COTE2; i = i + COTE2){
        for(j = 0; j < NB_COLONNES*COTE1; j = j + COTE1){
            if (pos.t.tab[i/COTE2][j/COTE1] == 1){
                w = subwin(stdscr, COTE2, COTE1, i, j);
                box(w, ACS_VLINE, ACS_HLINE);
                wrefresh(w);
            }
        }
    }
}

Joueur adversaire(Joueur joueur){
    /* Renvoie l'adversaire de joueur */
    if (joueur == JOUEUR_1)
        return JOUEUR_2;
    return JOUEUR_1;
}

Tablette creer_tablette(void){
    /* Créer une tablette de dimension NB_LIGNES x NB_COLONNES 
    *  1: le carré existe
    *  0: le carré a été mangé
    */
    Tablette t;
    int i, j;
    for (i=0; i < NB_LIGNES; i++){
        for (j=0; j < NB_COLONNES; j++){
            t.tab[i][j] = 1;
        }
    }
    t.taille = NB_LIGNES * NB_COLONNES;
    t.nb_carrees_restants = NB_LIGNES * NB_COLONNES;
    return t;
}

void manger(Tablette *tab, int x, int y){
    /* Modife la tablette de chocolat avec le carré mangé ainsi
    *  que ceux en dessous et à sa droite
    */
    int i, j;
    for (i = NB_LIGNES-1; i >= x; i--){
        for (j = NB_COLONNES-1; j >= y; j--){
            if (tab->tab[i][j] == 1){
                tab->tab[i][j] = 0;
                tab->nb_carrees_restants -= 1;
            }
        }
    }
}

int est_legal(Position pos, Coup coup){
    /* Vérifie que le carré que l'on souhaite manger existe 
    *  renvoie 1 si c'est vérifié
    *  renvoie 0 sinon
    */
    if(pos.t.tab[coup.x][coup.y] == 1)
        return 1;
    return 0;
}

void jouer_coup(Position *pos, Coup coup){
    /* Joue le coup à la position pos
    */
    if(est_legal(*pos, coup)){
        manger(&(pos->t), coup.x, coup.y);
        pos->j_courant = adversaire(pos->j_courant);
        afficher_joueur(pos->j_courant);
    }
}


int est_jeu_termine(Position pos, Joueur *joueur_gagnant){
    /* Vérifie si la partie est terminée:  si le joueur a mangé 
    *  le carré empoisonné
    *  renvoie 1 si le jeu se termine
    *  renvoie 0 sinon
    */
    if (pos.t.nb_carrees_restants == 0){
        *joueur_gagnant = pos.j_courant;
        return 1;
    }
    return 0;
}

int verif_coord(Tablette t, int x, int y, Coup * coup){
    /* Verifie si les coordonées entrées correspondent à un carré
    *  et attribue à coup les valeurs du carré correspondant
    *  renvoie 1 s'il correspond à un carré
    *  renvoie 0 sinon
    */
    int i, j;
    int tab_x, tab_y;
    tab_x = 0;
    tab_y = 0;

    for (i = 0; i < NB_LIGNES; i++){
        tab_y = (COTE2 * (i+1)) - 1;
        for (j = 0; j < NB_COLONNES; j++){
            tab_x = (COTE1 * (j+1)) - 1;

            if ((tab_x - 4) <= x && x < tab_x && (tab_y - 2) <= y && y < tab_y
            && t.tab[i][j] == 1){
                //mvprintw((NB_LIGNES*COTE2) + 5 + j, (COLS/2)+ 10, "i: %d, j: %d", i, j);
                //refresh();
                coup->y = j;
                coup->x = i;
                return 1;
            }
        }
    }
    return 0;
}

Coup lire_coup(Position pos){
    /* Attend un clic de l'utilisateur sur la tablette de chocolat dans la fenêtre graphique
    *  et renvoie le coup spécifié 
    */
    Coup coup;
    MEVENT ev;
    int souris_x, souris_y;
    int touche;
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    while(1){
        touche = getch();
        if (touche == KEY_MOUSE && getmouse(&ev) == OK){
            souris_x = ev.x;
            souris_y = ev.y;

            if ((souris_y < (NB_LIGNES*COTE2) - COTE2/2)
            && (souris_x < (NB_COLONNES*COTE1) - COTE1/2 + 1)){
                if (verif_coord(pos.t, souris_x, souris_y, &coup) == 1){
                    return coup;
                }
            }
        }
    }  
}

int main(void){
    WINDOW *w;
    Position pos;
    Coup coup;
    Joueur joueur_gagnant;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    w = subwin(stdscr, LINES/2, COLS/2, 0, 0);
    pos.t = creer_tablette();
    pos.j_courant = JOUEUR_1;

    afficher_joueur(pos.j_courant);
    afficher_position(pos, w);
    wrefresh(w);
    
    while(1){
        coup = lire_coup(pos);
        clear();
        jouer_coup(&pos, coup);
        afficher_position(pos, w);
        refresh();

        if (est_jeu_termine(pos, &joueur_gagnant) == 1){
            clear();
            mvprintw(0, 0, "Le joueur n°%d a gagné la partie!", joueur_gagnant+1);
            refresh();
            usleep(900000);
            break;
        }
    }

    endwin();
    return 0;
}

