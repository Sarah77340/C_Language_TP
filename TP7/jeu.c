#include "jeu.h"

char generer_lettre_aleatoire(Lettre Tab[26]){
    int p, i;
    p = rand() % 100;
    for (i = 0; i < 26; i++){
        if ((Tab[i]).p  > p)
            return (Tab[i-1]).c;
    }
    return '\0';
}

void init_grille(Lettre Tab[26], Jeu * jeu){
    int i, j;
    char c;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            do {
                c = generer_lettre_aleatoire(Tab);
            }while(c == '\0');
            jeu->grille[i][j] = c;
        }
    }
}

void afficher_grille(Jeu * jeu){
    int i, j;
    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){
            printf("%c", jeu->grille[i][j]);
        }
        printf("\n");
    }
}

void appel_init_grille(Jeu * j){
    Lettre Tab[26] = {{'E', 0}, {'T', 11}, {'A', 19}, {'I', 26}, {'N', 33}, {'O', 40}, {'S', 47},
    {'R', 54}, {'H', 60}, {'D', 65}, {'L', 69}, {'C', 73}, {'M', 76}, {'U', 79}, {'B', 82},
    {'F', 84}, {'G', 86}, {'P', 88}, {'W', 90}, {'Y', 92}, {'J', 94}, {'K', 95}, {'Q', 96},
    {'V', 97}, {'X', 98}, {'Z', 99}};

    init_grille(Tab, j);
}
