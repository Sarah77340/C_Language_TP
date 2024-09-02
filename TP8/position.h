#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef enum {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8
}Case;

typedef struct{
    unsigned long long pos;
}Position;

int est_case_occupee(Position pos, Case c);
int afficher_position(Position pos);
int placer_dame_position(Position *posit, Case c);
int calculer_cases_attaques(Position *pos, Case c);
int est_sans_attaque_mutuelle(Position pos);
int joueur_gagne(Position pos, int cmpt);
