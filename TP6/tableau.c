#include "tableau.h"


Position allouer_Position(int p){
    Pos * pos = (Pos*)malloc(sizeof(Pos));
    pos->p = p;
    pos->next = NULL;
    return pos;
}

void ajouter_Position(Position * pos, int p){
    if (*pos == NULL){
        *pos = allouer_Position(p);
        return;
    }
    ajouter_Position(&((*pos)->next), p);
}

Tableau allouer_Tableau(char * mot, int p){
    Mots * t = (Mots*)malloc(sizeof(Mots));
    t->occurence = 1;
    t->len = strlen(mot);
    t->pos = allouer_Position(p);
    t->mot = malloc(sizeof(strlen(mot)+1));
    memcpy(t -> mot, mot, strlen(mot)+1);
    t->suivant = NULL;
    return t;
}

void ajouter_mot_Tableau(Tableau * t, char * mot, int p){
    if (*t == NULL){
        *t = allouer_Tableau(mot, p);
        return;
    }
    ajouter_mot_Tableau(&((*t)->suivant), mot, p);
}

int mot_appartenir_Tableau(Tableau * t, char * mot, int p){
    if (*t!= NULL){
        if (strcmp((*t)->mot, mot) == 0) { 
            ajouter_Position(&((*t)->pos), p);
            (*t)->occurence += 1;
            return 1;
        }
        return mot_appartenir_Tableau(&((*t)->suivant), mot, p);
    }
    return 0; 
}

void trie_option(Tableau debut, char option){
    Tableau tmp, p;
    char * PR;
    int PR_occurence;
    int PR_len;
    Position PR_pos;
    int a;
    a = 0;
    if(debut != NULL){
        for(a; a < 10; a++){
            for(tmp = debut; tmp -> suivant != NULL; tmp = tmp -> suivant){
                for(p = tmp -> suivant; p != NULL; p = p -> suivant){
                    if(( (option == 'a') && (strcmp(tmp->mot, tmp->suivant->mot) > 0 ) ) ||
                     ( option == 'n' && ( (tmp->occurence < tmp->suivant->occurence) ||
                    ((tmp->occurence == tmp->suivant->occurence) && (strcmp(tmp->mot, tmp->suivant->mot) > 0 ))
                    ))){

                        PR = tmp->suivant -> mot;
                        PR_occurence = tmp->suivant->occurence;
                        PR_len = tmp->suivant->len;
                        PR_pos = tmp->suivant->pos;

                        tmp->suivant-> mot = tmp->mot;
                        tmp->suivant-> occurence = tmp->occurence;
                        tmp->suivant-> len = tmp->len;
                        tmp->suivant-> pos = tmp->pos;

                        tmp -> mot = PR;
                        tmp -> occurence = PR_occurence;
                        tmp -> len = PR_len;
                        tmp -> pos = PR_pos;
                    }
                }
            }
        }
    }
}

int trouver_len_max(Tableau t, int len_max){
    if (t == NULL)
        return len_max;
    if (len_max < t->len)
        len_max = t->len;
    return trouver_len_max(t->suivant, len_max);
}

void afficher(Tableau t, int len_max){
    int len_print;
    if (t != NULL){
        len_print = len_max - (t->len) + 1;
        printf("%s %*d\n", t->mot, len_print, t->occurence);
        afficher(t->suivant, len_max);
    }
}
