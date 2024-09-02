//
// Exercice 1: question 6
// Created by Manar Nssair and Sarah Nguyen on 10/02/2022.
//

// gcc -std=c17 -Wall tp2-exo1.6progc.c -o tp2-exo1.6progc
// ./tp2-exo1.6progc

#include <stdlib.h>
#include <stdio.h>

int main(void){
    char *a = "50";
    char *b = "5";
    char *c = "0";
    char *d = "toto";

    fprintf(stderr, " '%s', atoi: %d\n", a, atoi(a));
    fprintf(stderr, " '%s', atoi: %d\n", b, atoi(b));
    fprintf(stderr, " '%s', atoi: %d\n", c, atoi(c));
    fprintf(stderr, " '%s', atoi: %d\n", d, atoi(d));

    return 0;
}