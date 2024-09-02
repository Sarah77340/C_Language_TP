/*#include "test.h"*/
#include "fichier.h"

int main(int argc, char * argv[]){
    Tableau tab;
    FILE * df;
    tab = NULL;
    df = ouvre_fichier(argv[1], "r");

    if (argc > 2)
        switch(argv[2][1]){
            case 's': lire_fichier_option_s(df, &tab, argv[3]); break;
            case 'p': lire_fichier_option_p(df, &tab, argv[3]); break;
            case 'e': lire_fichier_option_e(df, &tab, atoi(argv[3])); break;
            default: lire_fichier(df, &tab);
        }
    else 
        lire_fichier(df, &tab);
    trie_option(tab, argv[argc-1][1]);
    afficher(tab, trouver_len_max(tab, 0));
    
    return 0;
}
