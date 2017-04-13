#ifndef COLOCOS
#define COLOCOS
long N;
struct abr {
    unsigned long poids;
    int sommet;
};
struct abr *list_abr;//list_abr[i*N+j]=Poids de AbrOpt(i,j)//taille de N/2 N
void racine_optimal(int i,int j);
int *sommet;
struct abr parcour_moy(int i,int j);
struct abr* addr_parcour_moy(int i,int j);
void construire_arbre();
int *get_sommet(int i,int j);
int get_sommet_val(int i,int j);
#endif
