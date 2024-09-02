//
// Exercice 1: question 4
// Created by Manar Nssair and Sarah Nguyen on 10/02/2022.
//

// gcc -std=c17 -Wall tp2-exo1.4progc.c -o tp2-exo1.4progc
// ./tp2-exo1.4progc

#include <string.h>
#include <stdio.h>

int main(void){
    char *s = "abcabc";
    char a = 'a';
    char b = 'b';
    char c = 'c';

    fprintf(stderr, "strchr '%s', '%c': %s\n", s, a, strchr(s, a));
    fprintf(stderr, "strchr '%s', '%c': %s\n", s, b, strchr(s, b));
    fprintf(stderr, "strchr '%s', '%c': %s\n", s, c, strchr(s, c));

    fprintf(stderr, "strrchr '%s', '%c': %s\n", s, a, strrchr(s, a));
    fprintf(stderr, "strrchr '%s', '%c': %s\n", s, b, strrchr(s, b));
    fprintf(stderr, "strrchr '%s', '%c': %s\n", s, c, strrchr(s, c));

    return 0;
}