//
// TP4 : version1
// Created by Manar Nssair and Sarah Nguyen on 24/02/2022.
//

// gcc -std=gnu99 -Wall Chomp-v1.c -lncurses -lm -o Chomp-v1
// ./Chomp-v1

#include <stdlib.h>
#include <stdio.h>
#define NB_LIGNES 8
#define NB_COLONNES 16

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


void verif(Joueur j){
    if (j == JOUEUR_1){
        printf("verif: joueur 1\n");
    }
    else
        printf("verif: joueur 2\n");
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
    printf("creer_tablette: i: %d, j: %d\n", i, j);
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
    if(est_legal(*pos, coup)){
        manger(&(pos->t), coup.x, coup.y);

        printf("!!! jouer_coup: \n");
        verif(pos->j_courant);
        pos->j_courant = adversaire(pos->j_courant);
        verif(pos->j_courant);
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

void afficher(Tablette t){
    int i, j;
    for (i = 0; i < NB_LIGNES; i++){
        for (j = 0; j < NB_COLONNES; j++){
            printf("%d", t.tab[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    Position pos;
    Coup coup;
    int result;
    Joueur joueur_gagnant;
    pos.t = creer_tablette();  

    printf("main: pos.t.nb_carrees_restants %d\n", pos.t.nb_carrees_restants);
    afficher(pos.t);
    printf("__________________________________________\n");

    coup.x = 6;
    coup.y = 14;  

    jouer_coup(&pos, coup);
    result = est_jeu_termine(pos, &joueur_gagnant);
    printf("result : %d\n", result);
    printf("joueur_gagnant: %d\n", joueur_gagnant);
    printf("1 j_courant: %d\n", pos.j_courant);
    verif(pos.j_courant);
    afficher(pos.t);

    coup.x = 0;
    coup.y = 0; 
    printf("__________________________________________\n");
    jouer_coup(&pos, coup);
    result = est_jeu_termine(pos, &joueur_gagnant);
    printf("result : %d\n", result);
    printf("joueur_gagnant: %d\n", joueur_gagnant);
    printf("2 j_courant: %d\n", pos.j_courant);
    verif(pos.j_courant);
    afficher(pos.t);

    return 0;
}






