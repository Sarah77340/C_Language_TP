#include "monde.h"

int case_valide(Case* cell, Case * serp_pom){
    /* renvoie 1 si la case n'appartient pas au corps du serpents ou aux pommes, et 0 sinon */
    Case * tmp;
    tmp = serp_pom;
    while(tmp != NULL){
        if((tmp -> ligne == cell -> ligne) && (tmp -> colonne == cell -> colonne))
            return 0;
        tmp = tmp -> next;
    }
    return 1;
}

void monde_ajouter_pomme(Monde *mon){
    Pomme p;
    p = pomme_aleatoire(mon -> nb_lignes, mon -> nb_colonnes);
    while(!case_valide(p, mon -> s.tete) || !case_valide(p, mon -> pomme)){
        p = pomme_aleatoire(mon -> nb_lignes, mon -> nb_colonnes);
    }
    /* ajout de la pomme : */
    p -> next = mon -> pomme;
    mon -> pomme = p;
    
}

void monde_supprimer_pomme(Monde *mon, int ligne, int colonne){
    Pomme tmp;
    tmp = mon->pomme;
    while(tmp != NULL){
        if (tmp->ligne == ligne && tmp->colonne == colonne){
            mon->pomme = mon->pomme->next;
            return;
        }
        tmp = tmp->next;
    }
}

Monde monde_initialiser(int nb_lignes, int nb_colonnes, int taille_serpent, int nb_pommes){
    Monde *mon = (Monde *) malloc(sizeof(Monde));
    int i;
    mon->nb_lignes = nb_lignes;
    mon->nb_colonnes = nb_colonnes;
    mon->s = serpent_initialiser(nb_lignes, nb_colonnes, taille_serpent);
    mon->pomme = NULL;
    mon->nb_mangees = 0;
    for (i = 0; i < nb_pommes; i++){
        monde_ajouter_pomme(mon);
    }
    return *mon;
}

int monde_est_mort_serpent(Monde mon){
    Case c;
    c = serpent_case_visee(mon.s);
    if (c.ligne < 0 || c.ligne > mon.nb_lignes || c.colonne < 0 || c.colonne > mon.nb_colonnes)
        return 1;
    return toucher_tete_serpent(c.ligne, c.colonne, mon.s.tete);
}

int monde_insere_tete_serpent(Monde * mon, int ligne, int colonne){
    Case * c = (Case *) malloc(sizeof(Case));
    if (c == NULL)
        return 0;
    c->colonne = colonne;
    c->ligne = ligne;
    c->next = mon->s.tete;
    mon->s.tete = c;
    return 1;
}

void monde_evoluer_serpent(Monde *mon){
    Case c;
    c = serpent_case_visee(mon->s);
    
    if (toucher_tete_serpent(c.ligne, c.colonne, mon->pomme) == 1){
        monde_supprimer_pomme(mon, c.ligne, c.colonne);
        monde_ajouter_pomme(mon);
        monde_insere_tete_serpent(mon, c.ligne, c.colonne);
        mon->nb_mangees += 1;
    }
    else{
        corps_serpent_avance(mon->s.tete, mon->s.tete->ligne, mon->s.tete->ligne);
        mon->s.tete->ligne = c.ligne;
        mon->s.tete->colonne = c.colonne;
    }
}