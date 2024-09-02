#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    if(argc != 4){
        printf("Ce programme dois avoir exactement 3 arguments.\n");
        exit(1);
    }
    if(!IsNumeric(argv[2]) || !IsNumeric(argv[3])){
        printf("Il faut des valeurs numériques\n");
        exit(1);
    }
    if (strcmp(argv[1], "+") == 0)
        printf("Le résultat est %d\n", atoi(argv[2]) + atoi(argv[3]));
    else if(strcmp(argv[1], "-") == 0)
        printf("Le résultat est %d\n", atoi(argv[2]) - atoi(argv[3]));
    else if(strcmp(argv[1], "x") == 0)
        printf("Le résultat est %d\n", atoi(argv[2]) * atoi(argv[3]));
    else if(strcmp(argv[1], "/") == 0){
        if(atoi(argv[3]) == 0){
            printf("Impossible, division par 0\n");
            exit(1);
        }
        else printf("Le résultat est %d\n", atoi(argv[2]) / atoi(argv[3]));
        }
    else {
        printf("Le premier argument doit être un opérateur parmi +, -, x et /\n");
        exit(1);
    }

    return 0;
}