#ifndef COLOCOS
#define COLOCOS


#include <stdbool.h>
unsigned long *tabl;
unsigned long N;
struct abr *list_abr;//list_abr[i*N+j]=Poids de AbrOpt(i,j)//taille de N/2 N
struct node *arbre;//liste qui copie le principe d'une liste chainé
struct abr {
    unsigned long poids;
    int sommet;
    long poids_somme;
};
struct node {
    int sommet;
    int noeudd;//noeud droite 
    int noeudg;//noeud gauche
    bool fait;//si on l'a deja placé
};

void racine_optimal(int i,int j);
struct abr parcour_moy(int i,int j);
struct abr* addr_parcour_moy(int i,int j);
void construire_arbre();
void calc_poids();
#endif
