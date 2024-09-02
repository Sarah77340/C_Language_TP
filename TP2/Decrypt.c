//
// Exercice 4: Decrypt.c
// Created by Manar Nssair and Sarah Nguyen on 16/02/2022.
//

// gcc -std=c17 -Wall Decrypt.c -lncurses -lm -o Decrypt
// ./Decrypt 3 Ohv WS gh surjudppdwlrq vrqw vxshu ! 

#include <stdio.h>
#include <stdlib.h>

int bon_modulo(int a, int b){
    int calcul;
    calcul = a % b;
    printf("%d", calcul);
    if (calcul < 0)
        return calcul + b;
    return calcul;
}

int main(int argc, char* argv[]){
    int result;
    int i, j;
    int k;
    char *p;

    k = strtol(argv[1], &p, 10);

    for (i = 2; i < argc; i++){
        for (j = 0; argv[i][j] != '\0'; j++){
           if ((argv[i][j] >= 'a' && argv[i][j] <= 'z') || 
           (argv[i][j] >= 'A' && argv[i][j] <= 'Z')){
               //printf("%c", bon_modulo(argv[i][j] - k, 26));
               printf("%c", (argv[i][j] - k));
           }
           else
                printf("%c", argv[i][j]);
       }
       printf(" ");

    }

    
    //result = bon_modulo(-9, 5);
    //printf("%d", result);

    return 0;
}
