#include "position.h"

int est_case_occupee(Position pos, Case c){
    return (1 << c) & pos.pos;
}

int afficher_position(Position pos){
    int i, j;
    for (i = 56; i >= 0; i-= 8){
        for (j = 0; j < 8; j++){
            if (((pos.pos >> (i+j)) & 1) == 1)
                printf(" + ");
            else 
                printf(" . ");
        }
        printf("\n");
    }
    return 1;
}

int placer_dame_position(Position *pos, Case c){
    assert(pos != NULL);
    if (0 > c || c > 63)
        return 0;
    Position pos_tmp;
    pos_tmp.pos = pow(2, c);
    pos->pos = pos_tmp.pos | pos->pos;
    return 1;
}

int calculer_cases_attaques(Position *pos, Case c){
    int i, x, y;
    int c1, c2, c3, c4, c5, c6;
    assert(pos != NULL);
    if (0 > c || c > 63)
        return 1;

    x = c % 8;
    y = c / 8;
    c3 = c;
    c4 = c;
    c5 = c;
    c6 = c;

    for (i = 0; i < 8; i++){
        c1 = (y * 8) + i;
        c2 = x + (8 * i);
        c3 += 9;
        c4 -= 9;
        c5 += 7;
        c6 -= 7;

        if ((c3 % 8) == 7 || x == 7)
            c3 = 64;
        if ((c4 % 8) == 0 || x == 0)
            c4 = -1;
        if ((c5 % 8) == 0 || x == 0)
            c5 = 64;
        if ((c6 % 8) == 7 || x == 7)
            c6 = -1;

        placer_dame_position(pos, c1);
        placer_dame_position(pos, c2);
        placer_dame_position(pos, c3);
        placer_dame_position(pos, c4);
        placer_dame_position(pos, c5);
        placer_dame_position(pos, c6);
    }
    Position pos_tmp;
    pos_tmp.pos = pow(2, c);
    pos->pos = pos_tmp.pos ^ pos->pos;
    return 0;
}

int est_sans_attaque_mutuelle(Position pos){
    Position pos_attaques;
    Case tab_dames[64];
    int i, j;
    j = 0;
    for (i = 0; i <= 63; i++){
            if (((pos.pos >>(i)) & 1) == 1){
                tab_dames[j] = i;
                pos_attaques.pos = 0;
                calculer_cases_attaques(&pos_attaques, tab_dames[j]);
                if ((pos_attaques.pos & pos.pos) != 0)
                    return 0;
                j++;
            }   
    }
    return 1;
}

int joueur_gagne(Position pos, int cmpt){
    if(est_sans_attaque_mutuelle(pos) && (cmpt == 8))
            return 1;
    return 0;
}
