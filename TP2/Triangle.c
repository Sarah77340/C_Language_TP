#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Ce programme dois avoir exactement 2 arguments.\n");
        exit(1);
    }
    int i, j;
    int n = atoi(argv[1]);
    int base = 2 * n + 1;

    initscr();
    curs_set(FALSE);
    for(i = 0; i < n + 1; i++){
        for(j = 0; j < base; j++){
            mvprintw(i, i + j, argv[2]);
        }
        base = base - 2;
    }
    // refresh();
    getch();
    endwin();
    return 0;
}