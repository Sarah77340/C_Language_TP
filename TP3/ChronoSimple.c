//
// TP3 : ChronoSimple.c
// Created by Manar Nssair and Sarah Nguyen on 17/02/2022.
//

// gcc -std=gnu99 -Wall ChronoSimple.c -lncurses -lm -o ChronoSimple
// ./ChronoSimple

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

int main(void){
    struct timeval temps_debut, temps_fin;
    int interval;
    int c, s, m, h;

    initscr();
    gettimeofday(&temps_debut, NULL);
    noecho();
    refresh();
    while(1){
        gettimeofday(&temps_fin, NULL);

        interval = intervalle_ms(temps_debut, temps_fin);
        c = nb_ms_vers_centiemes(interval);
        s = nb_ms_vers_secondes(interval);
        m = nb_ms_vers_minutes(interval);
        h = nb_ms_vers_heures(interval);

        mvprintw(1, 0, "%02d : %02d : %02d : %02d", h, m, s, c);
        refresh();
        usleep(RAFRAICHISSEMENT);
    }
    
    refresh();
    getch();
    endwin();
    return 0;
}