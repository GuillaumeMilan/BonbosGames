#ifndef COLOCOS
#define COLOCOS



unsigned long *tabl;
unsigned long N;
struct abr *list_abr;//list_abr[i*N+j]=Poids de AbrOpt(i,j)//taille de N/2 N

struct abr {
    unsigned long poids;
    int sommet;
    long poids_somme;
};


void racine_optimal(int i,int j);
struct abr parcour_moy(int i,int j);
struct abr* addr_parcour_moy(int i,int j);
void construire_arbre();
void calc_poids();
#endif
