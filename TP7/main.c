#include "graphic.h"

int main(int argc, char *argv[]){
    FILE *df ;
    ATR A;
    Joueur * j; 
    Jeu jeu;
    A = NULL;

    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    srand(time(NULL));

    df = ouvre_fichier(argv[1]);
    j = allouer_joueur();
    remplir_ATR(df, &A);
    fclose(df);

    appel_init_grille(&jeu);
    selectioner_mot(jeu, j, A);
    liberer_ATR(&A);

    refresh();
    getch();
    endwin();

    return 0;
}
