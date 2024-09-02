#include "type.h"
#include <time.h>

int case_initialiser(int colonne, int ligne, Case * c, int taille){
    c->colonne = colonne;
    c->ligne = ligne;
    c->next = NULL;
    if (taille > 1){
        c->next  = (Case *) malloc(sizeof(Case));
        if (c == NULL)
            return 0;
        return case_initialiser(colonne-1, ligne, (Case *)(c->next), taille-1);
    }
    return 1;
}

Pomme pomme_aleatoire(int nb_lignes, int nb_colonnes){
    Case *p =  (Case *) malloc(sizeof(Case));
    if (p == NULL){
        return NULL;
    }
    srand(time(NULL));
    p->colonne = rand() % (nb_colonnes-1);
    p->ligne = rand() % (nb_lignes-1);
    p->next = NULL;
    return p;
}

Serpent serpent_initialiser(int nb_lignes, int nb_colonnes, int taille){
    Serpent *s;
    s = (Serpent *) malloc(sizeof(Serpent));
    s->direction = EST;
    s->tete = (Case *) malloc(sizeof(Case));
    case_initialiser(nb_colonnes / 2, nb_lignes / 2, s->tete , taille);
    return *s;
}

Case serpent_case_visee(Serpent serp){
    Case* cell = (Case *) malloc(sizeof(Case));

    if (serp.direction == NORD){
        cell->ligne = ((serp.tete) -> ligne) - 1;
        cell->colonne = (serp.tete) -> colonne;
    }
    else if (serp.direction == SUD){
        cell->ligne = ((serp.tete) -> ligne) + 1;
        cell->colonne = (serp.tete) -> colonne;
    }
    else if (serp.direction == EST){
        cell->ligne = (serp.tete) -> ligne;
        cell->colonne = ((serp.tete) -> colonne) + 1;
    }
    else if (serp.direction == OUEST){
        cell->ligne = (serp.tete) -> ligne;
        cell->colonne = ((serp.tete) -> colonne) - 1;
    }
    return *cell;
}

int toucher_tete_serpent(int ligne_visee, int colonne_visee, Case * c){
    if (c != NULL){
        if (c->ligne == ligne_visee && c->colonne == colonne_visee)
            return 1;
        return toucher_tete_serpent(ligne_visee, colonne_visee, c->next);
    }
    return 0;
}

void corps_serpent_avance(Case * c, int ligne, int colonne){
    int ligne_tmp, colonne_tmp;
    
    if (c != NULL){
        ligne_tmp = c->ligne;
        colonne_tmp = c->colonne;
        c->ligne = ligne;
        c->colonne = colonne;
        corps_serpent_avance(c->next, ligne_tmp, colonne_tmp);
    }
}