//
// TP3 : ChronoMoyen.c
// Created by Manar Nssair and Sarah Nguyen on 17/02/2022.
//

// gcc -std=gnu99 -Wall ChronoMoyen.c -lncurses -lm -o ChronoMoyen
// ./ChronoMoyen

#include <sys/time.h>
#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>
#define RAFRAICHISSEMENT 1000

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

int inverser(int n){
    if(n == 0)
        return 1;
    return 0;
}

void affiche_chrono(int interval, int affichage){
    int c, s, m, h;
    c = nb_ms_vers_centiemes(interval);
    s = nb_ms_vers_secondes(interval);
    m = nb_ms_vers_minutes(interval);
    h = nb_ms_vers_heures(interval);

    if (affichage == 1)
        mvprintw(2, 0, " chronomètre: %02d : %02d : %02d : %02d", h, m, s, c);
    else 
        mvprintw(0, 0, "durée totale: %02d : %02d : %02d : %02d", h, m, s, c);
    refresh();
}

int main(void){
    struct timeval temps_debut, temps_fin, temps_debut2;
    int interval_chrono, interval;
    int chrono_actif;
    int touche;
    int duree_totale;

    initscr();
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    noecho();
    chrono_actif = 0;
    duree_totale = 0;
    interval_chrono = 0;

    gettimeofday(&temps_debut2, NULL);

    mvprintw(2, 0, "Cliquer sur la barre espace");

    while(1){
          
        touche = getch();
        refresh();

        gettimeofday(&temps_fin, NULL);
        duree_totale = intervalle_ms(temps_debut2, temps_fin);
        affiche_chrono(duree_totale, 0);
        usleep(RAFRAICHISSEMENT);

        if(touche == ' '){
            if (chrono_actif == 0)
                gettimeofday(&temps_debut, NULL);
            else
                interval_chrono = interval;
            chrono_actif = inverser(chrono_actif);
        }
        if(chrono_actif == 1){
            interval = intervalle_ms(temps_debut, temps_fin);
            interval += interval_chrono;
            affiche_chrono(interval, 1);
        }   
    }
    refresh();
    getch();
    endwin();
    return 0;
}