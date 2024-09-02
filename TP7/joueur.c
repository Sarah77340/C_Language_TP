#include "joueur.h"
#include <math.h>

Joueur * allouer_joueur(){
    int i;
    Joueur * j = (Joueur*)malloc(sizeof(Joueur));
    if(j == NULL){
        printf("pb d'alloc");
        return NULL;
    }
    j -> score = 0;
    j -> nb_tentatives = 4;
    j -> mot_selec[0] = '\0';
    for (i = 0; i < 4; i++){
        j -> mots_trouves[i] = NULL;
    }
    return j;
}

void calcul_score(Joueur * j){
    int i;
    j->score = 0;
    for (i = 0; i < 4; i++){
        if (j->mots_trouves[i] == NULL)
            return;
        else if(strlen(j->mots_trouves[i]) >= 3)
            j->score += (int) pow(2, strlen(j->mots_trouves[i]) - 3);
    }
}

void ajouter_c_mot_selec(Joueur * joueur, char c){
    int i;
    for (i = 0; i < 20; i++){
        if (joueur->mot_selec[i] == '\0'){
            joueur->mot_selec[i] = tolower(c);
            return;
        }
    }
}

void supprimer_fin_chaine(Joueur * joueur){
    int i = 0;
    while(joueur->mot_selec[i] != '\0'){
        if(joueur->mot_selec[i+1] == '\0'){
            joueur->mot_selec[i] = '\0';
        }
        i++;
    }
}

void ajouter_mots_trouves(Joueur * j, char * mot_selec){
    int i;
    for (i = 0; i < 4; i++){
        if (j->mots_trouves[i] == NULL){
            j->mots_trouves[i] = malloc( strlen(mot_selec)+1);
            memcpy(j->mots_trouves[i], mot_selec, strlen(mot_selec)+1);
            return;
        }
    }
}

int valider_mot_selec(Joueur * j, ATR t){
    int result, i;
    i = 0;
    if (appartient_dico(t, j -> mot_selec) == 1){
        while(j -> mots_trouves[i] != NULL){
            if(strcmp(j -> mots_trouves[i], j -> mot_selec) == 0)
                result = 0;
            i++;
        }
        if (result != 0){
            ajouter_mots_trouves(j, j -> mot_selec);
            result = 1;
        }
    }
    else 
        result = 0;
    j -> nb_tentatives -= 1;
    while(j->mot_selec[0] != '\0')
        supprimer_fin_chaine(j);
    return result;
}
