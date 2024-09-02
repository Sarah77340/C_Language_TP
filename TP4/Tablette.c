#include "Tablette.h"

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
                coup->y = j;
                coup->x = i;
                return 1;
            }
        }
    }
    return 0;
}

