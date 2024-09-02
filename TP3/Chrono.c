//
// TP3 : exerice 2: Chrono2.c
// Created by Manar Nssair and Sarah Nguyen on 17/02/2022.
//

// gcc -std=gnu99 -Wall Chrono.c -lncurses -lm -o Chrono
// ./Chrono

#include <stdlib.h>

#include <sys/time.h>
#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>
#define RAFRAICHISSEMENT 1000
#define N 6

typedef struct chronometre{
    int etat_chrono;
    int duree_totale;
    int avertissement_ms;
    int indice_dernier_tour;
    int indice_nb_tour;
    int tab_ms[N];
} Chronometre;

Chronometre initialiser_chronometre(void){
    Chronometre chrono;
    chrono.etat_chrono = 0; 
    chrono.duree_totale = 0;
    chrono.avertissement_ms = 0;
    chrono.indice_dernier_tour = 0;
    chrono.indice_nb_tour = 0;
    chrono.tab_ms[0] = 0;
    return chrono;
}

int intervalle_ms(struct timeval debut, struct timeval fin){
    return ((fin.tv_usec - debut.tv_usec) / 1000) + ((fin.tv_sec - debut.tv_sec) * 1000);
}

int nb_ms_vers_centiemes(int nb_ms){
    return (nb_ms / 10) % 100;
}

int nb_ms_vers_secondes(int nb_ms){
    return (nb_ms / 1000) % 60;
}

int nb_ms_vers_minutes(int nb_ms){
    return (nb_ms / (1000 * 60)) % 60;
}

int nb_ms_vers_heures(int nb_ms){
    return (nb_ms / (1000 * 60 * 60)) % 100;
}

void ajouter_tour(Chronometre *chrono){
    int i;
    if ((chrono)->indice_nb_tour < N){
        (chrono)->indice_dernier_tour += 1;
        (chrono)->indice_nb_tour += 1;

        for (i=chrono->indice_nb_tour-1; i > 0 ; i--){
            chrono->tab_ms[i] = chrono->tab_ms[i-1];
        }
        chrono->tab_ms[0] = chrono->duree_totale;
    }
}

int inverser(int n){
    if(n == 0)
        return 1;
    return 0;
}

void afficher_flash(){
    int i, j, couleur;
    init_pair(1, COLOR_RED, COLOR_WHITE);
    init_pair(2, COLOR_BLUE, COLOR_GREEN);
    couleur = 1;
    for(i = 0; i < COLS; i++){
        for(j = 0; j < LINES; j++){
            attron(COLOR_PAIR(couleur));
            mvaddch(j, i,'*');
            attroff(COLOR_PAIR(couleur));
            couleur = inverser(couleur - 1) + 1;
        }
    }
}

void afficher_duree(int y, int x, int nb_ms){
    int c, s, m, h;
    c = nb_ms_vers_centiemes(nb_ms);
    s = nb_ms_vers_secondes(nb_ms);
    m = nb_ms_vers_minutes(nb_ms);
    h = nb_ms_vers_heures(nb_ms);

    mvprintw(y, x, "%02d : %02d : %02d : %02d", h, m, s, c);
    refresh();
}

void afficher_interface(Chronometre chrono){
    int y;
    int i, j;
    y = (LINES/2) - 5;


    mvprintw(0, (COLS/2)-8, "== Chronometre ==");

    for (j = chrono.indice_nb_tour-1; j >= 0; j--){
        mvprintw(y-j-1, (COLS/2)-24, "Tour %d :", chrono.indice_nb_tour-j);
        afficher_duree(y-j-1, (COLS/2)-8, chrono.tab_ms[j]);
    }

    mvprintw(y+1, (COLS/2)-24, "Avertissement :");
    afficher_duree(y+1, (COLS/2)-8, chrono.avertissement_ms);

    for (i=0; i < COLS; i++ ){
        mvprintw(y+2, i, "-");
    }

    mvprintw(y+3, 0, "Espace : lancer / mettre en pause");
    mvprintw(y+4, 0, "r      : reinitialiser\nt      : marquer tour");
    mvprintw(y+6, 0, "F1/F2  : incrementer / decrementer heure avertissement");
    mvprintw(y+7, 0, "F3/F4  : incrementer / decrementer minute avertissement");
    mvprintw(y+8, 0, "F5/F6  : incrementer / decrementer seconde avertissement");
    mvprintw(y+9, 0, "q      : quitter");
}

int main(void){
    Chronometre chrono;
    struct timeval temps_debut, temps_fin;
    int interval_chrono;
    int touche;

    initscr();
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    noecho();
    start_color();

    if(COLS < 58 || LINES < 14){
        mvprintw(2, 0, "Il faut une fenêtre plus grande.");
        refresh();
        usleep(5000000);
        endwin(); return 0;
    }

    chrono = initialiser_chronometre();
    interval_chrono = 0;
    gettimeofday(&temps_debut, NULL);

    chrono.avertissement_ms = 3000;
    afficher_interface(chrono);
    while(1){
        touche = getch();
        refresh();

        gettimeofday(&temps_fin, NULL);
        usleep(RAFRAICHISSEMENT);
        if (touche == ' '){
            if(chrono.etat_chrono == 0)
                        gettimeofday(&temps_debut, NULL);
                    else
                        interval_chrono = chrono.duree_totale;
                    chrono.etat_chrono = inverser(chrono.etat_chrono);
        }
        switch(touche){
            case 't':
                    ajouter_tour(&chrono);
                    afficher_interface(chrono);
                    break;
            case 'r':
                    gettimeofday(&temps_debut, NULL); break;
            case 'q':
                    endwin(); return 0;
            case KEY_F(1):
                    chrono.avertissement_ms += 3600000; break;
            case KEY_F(2):
                    chrono.avertissement_ms -= 3600000; break;
            case KEY_F(3):
                    chrono.avertissement_ms += 60000; break;
            case KEY_F(4):
                    chrono.avertissement_ms -= 60000; break;
            case KEY_F(5):
                    chrono.avertissement_ms += 1000; break;
            case KEY_F(6):
                    chrono.avertissement_ms -= 1000; break;
        }

        if(chrono.etat_chrono == 1){
            chrono.duree_totale = intervalle_ms(temps_debut, temps_fin);
            chrono.duree_totale += interval_chrono;
            afficher_duree((LINES/2) - 5, (COLS/2)-8, chrono.duree_totale);
            afficher_interface(chrono);
        }   

        /*if (chrono.duree_totale == chrono.avertissement_ms){
            afficher_flash();
        }*/
        if (chrono.duree_totale == chrono.avertissement_ms){
            clear();
            afficher_flash();
            refresh();
            usleep(1000000);
            clear();
        }
    }
    endwin();
    return 0;
}