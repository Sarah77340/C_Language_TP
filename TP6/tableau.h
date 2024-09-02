/*Inclusioin de modules*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

/* Declaration de types */

typedef struct pos{
    int p;
    struct pos *next;
}Pos, *Position;

typedef struct mots{
    int occurence;
    int len;
    Position pos;
    char *mot;
    struct mots * suivant;
}Mots, *Tableau;


/* Declaration de fonctions */

Position allouer_Position(int p);
void ajouter_Position(Position * pos, int p);

Tableau allouer_Tableau(char * mot, int p);
void ajouter_mot_Tableau(Tableau * t, char * mot, int p);
int mot_appartenir_Tableau(Tableau * t, char * mot, int p);
void trie_option(Tableau debut, char option);
int trouver_len_max(Tableau t, int max);
void afficher(Tableau t, int len_max);
