//
// Exercice 1: question 2
// Created by Manar Nssair and Sarah Nguyen on 10/02/2022.
//

// gcc -std=c17 -Wall tp2-exo1.2progc.c -o tp2-exo1.2progc
// ./tp2-exo1.2progc

#include <string.h>
#include <stdio.h>

int main(void){
    char *s1 = "abc";
    char *s2 = "acb";
    char *s3 = "bbc";

    fprintf(stderr, "comparaison '%s', '%s': %d\n", s1, s1, strcmp(s1, s1));
    fprintf(stderr, "comparaison '%s', '%s': %d\n", s1, s3, strcmp(s1, s3));
    fprintf(stderr, "comparaison '%s', '%s': %d\n", s2, s1, strcmp(s2, s1));
    
    return 0;
}
