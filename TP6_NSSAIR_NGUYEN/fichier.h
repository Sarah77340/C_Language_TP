#define LEN_MAX_MOTS 20

/*Inclusion de modules*/

#include "tableau.h"

/* Declaration de types */

/* Declaration de fonctions */
FILE* ouvre_fichier(char* nom_fichier, char* mode);
void lire_fichier(FILE * df, Tableau * tab);
void lire_fichier_option_s(FILE * df, Tableau * tab, char * mot_donnee);
void lire_fichier_option_p(FILE * df, Tableau * tab, char * mot_donnee);
char * creer_expression_composee(FILE * df, int n);
void lire_fichier_option_e(FILE * df, Tableau * tab, int n);