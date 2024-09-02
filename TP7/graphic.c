#include "graphic.h"

void afficher_grille_graph(Jeu jeu, int i_lettre, int j_lettre){
    int i, j;
    int x, y;

    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);

    x = (COLS /2) - 4;
    y = (LINES /2) - 2;
    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){
            if (i == i_lettre && j == j_lettre){
                attron(COLOR_PAIR(1));
                mvprintw(y, x, "%c", jeu.grille[i][j]);
                attroff(COLOR_PAIR(1));
            }
            else{
                attron(COLOR_PAIR(2));
                mvprintw(y, x, "%c", jeu.grille[i][j]);
                attroff(COLOR_PAIR(2));
            }
            x += 2;
        }
        y += 1;
        x = (COLS /2) - 4;
    }
    
}

int cases_voisines(int col, int li, int x, int y){
    int i, k;
    if (col == x && li == y)
        return 0;
    for(i = col-1; i <= col+1; i++){
        for(k = li-1; k <= li+1; k++){
            if ((i == x) && (k == y)){
                return 1;
            }
        }
    }
    return 0;
}
    
void selectioner_mot(Jeu jeu, Joueur * joueur, ATR A){
    int touche, col, li, i, j;
    char c;
    i = 0;
    j = 0;
    col = -5;
    li = -5;

    while(1){
        afficher_grille_graph(jeu, i, j);
        calcul_score(joueur);

        mvprintw(2, 1, "score %d        nombres de tentatives restantes: %d", joueur->score, joueur->nb_tentatives);
        mvprintw(5, 1, "Mot selectionné: %s", joueur->mot_selec);

        mvprintw(7, 1, "Mots trouvés:");
        mvprintw(8, 2, "- %s", joueur->mots_trouves[0]);
        mvprintw(9, 2, "- %s", joueur->mots_trouves[1]);
        mvprintw(10, 2, "- %s", joueur->mots_trouves[2]);
        mvprintw(11, 2, "- %s", joueur->mots_trouves[3]);
        refresh();

        if(joueur -> nb_tentatives == 0){
            clear();
            mvprintw(LINES/2, 2, "Vous avez utilisé toutes les tentatives, votre score est %d", joueur -> score);
            break;
        }

        touche = getch();

        switch(touche){
            case KEY_UP: 
                if (i > 0) i -= 1; 
                break;
            case KEY_DOWN: 
                if (i < 3) i += 1; 
                break;
            case KEY_RIGHT: 
                if (j < 3) j += 1; 
                break;
            case KEY_LEFT:
                if (j > 0) j -= 1; 
                break;
            case 'a':
                supprimer_fin_chaine(joueur); break;
            case ' ':
                c = jeu.grille[i][j];
                if ((cases_voisines(col, li, i, j) == 1) || (col == -5 && li == -5)){
                    ajouter_c_mot_selec(joueur, c);
                    col = i;
                    li = j;
                }
                break;
            case '\n':
                valider_mot_selec(joueur, A);
                i = 0; j = 0; col = -5; li = -5;
                break;
        }
        clear();
    }
}

