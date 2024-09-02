#include <ncurses.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    fprintf(stdout, "Le nombre d'arguments avec lequel ce programme a été lancé est %d\n", argc - 1);
    return 0;
}