#include "fichier.h"

FILE* ouvre_fichier(char* nom_fichier, char* mode){
    FILE* fichier = NULL;
    fichier = fopen(nom_fichier, mode);
    if (fichier == NULL){
        fprintf(stderr, "probleme d'ouverture");
        exit(1);
    }
    return fichier;
}

void lire_fichier(FILE * df, Tableau * tab){
    char mot[10];
    char * tmp;
    int i_pos, mot_ignore;
    i_pos = 0;

    while (fscanf(df, "%s", mot) == 1) { 
        tmp = mot;
        mot_ignore = 0;
        while(*tmp != '\0'){
            if ('A' <= *tmp && *tmp <= 'Z')
                *tmp = (tolower(*tmp));
            else if (isalpha(*tmp) == 0){
                mot_ignore = 1;
                break;
            }
            tmp ++;
        }
        if (mot_ignore == 0){
            if (mot_appartenir_Tableau(tab, mot, i_pos) == 0)
                ajouter_mot_Tableau(tab, mot, i_pos);
        }
        i_pos +=1;
	}
}

void lire_fichier_option_s(FILE * df, Tableau * tab, char * mot_donnee){
    char mot[10];
    int i_pos, detecte;;
    i_pos = 0;
    detecte = 0;

    while (fscanf(df, "%s", mot) == 1) { 
        if (detecte == 1){
            if(mot_appartenir_Tableau(tab, mot, i_pos) == 0)
                ajouter_mot_Tableau(tab, mot, i_pos);
            i_pos +=1;
            detecte = 0;
        }
        if(strcmp(mot, mot_donnee) == 0)
            detecte = 1;
    }
}

void lire_fichier_option_p(FILE * df, Tableau * tab, char * mot_donnee){
    char mot1[10], mot2[10];
    int i_pos;
    i_pos = 0;
    fscanf(df, "%s", mot1);
    while (fscanf(df, "%s", mot2) == 1) {
        if(strcmp(mot2, mot_donnee) == 0){
            if(mot_appartenir_Tableau(tab, mot1, i_pos) == 0){
                ajouter_mot_Tableau(tab, mot1, i_pos);
                i_pos +=1;
            }                
        }
        strcpy(mot1, mot2);
    }
}

char * creer_expression_composee(FILE * df, int n){
    int i, len_fseek;
    char mot[10];
    char * e;
    len_fseek = 0;
    
    e = (char*) malloc(sizeof(char));
    for (i = 0; i < n; i++){
        if (fscanf(df, "%s", mot) != 1)
            return NULL;
        if (i > 0){
            len_fseek += strlen(mot) + 1;
        }
        strcat(e, mot);
        strcat(e, " ");
    }
    fseek(df, 1 - len_fseek, SEEK_CUR);
    return e;
}

void lire_fichier_option_e(FILE * df, Tableau * tab, int n){
    char * e;
    int i_pos;
    i_pos = 0;

    while(1){
        e = creer_expression_composee(df, n);
        if (e == NULL)
            return;
        if (mot_appartenir_Tableau(tab, e, i_pos) == 0)
                ajouter_mot_Tableau(tab, e, i_pos);
        i_pos +=1;
    }
}

