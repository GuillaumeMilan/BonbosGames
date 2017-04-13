#include <stdlib.h>
#include "racine_optimal.h"
void racine_optimal(int i,int j) {//suppose que pour i,j-1 et i+1,j deja calculé
    struct abr IJmoin=parcour_moy(i,j);
    struct abr IJplus=parcour_moy(i,j);
    struct abr* addr=addr_parcour_moy(i,j);
    if(i==j) {
	addr->poids=tabl[i];
	addr->sommet=i;
    }
    else {
	addr->poids=(unsigned long)-1;
	addr->sommet=-1;
	int k,l;
	unsigned long poids;
	if(IJplus.sommet-IJmoin.sommet<=1) {

	    for(k=IJmoin.sommet;k<IJplus.sommet;k++) {
		poids = 1+parcour_moy(i,k-1).poids+tabl[k]+1+parcour_moy(k+1,j).poids;
		if(poids<addr->poids) {
		    addr->sommet=k;
		    addr->poids=poids;
		}
	    }
	}
    }
}

    struct abr parcour_moy(int i,int j) {
    struct abr rien={0,-1};
    if(i>j) { return rien;}//Tableau de diagonal 
    if(j>N/2) {
	j=N-j;//cf dessin
	i=N-i*(i+1);
    }
    return list_abr[i*N+j];
}
struct abr* addr_parcour_moy(int i,int j) {
    if(i>j) { return NULL;}//Tableau de diagonal 
    if(j>N/2) {
	j=N-(j);//cf dessin
	i=N-i*(i+1);
    }
    return list_abr+i*N+j;
}
int *get_sommet(int i,int j) {
    return sommet+j+N-1-i;
}
int get_sommet_val(int i,int j) {
    return sommet[j,N-1-i];
}
void construire_arbre() {
    int i;
    int j;
    int current_vert;
    int next_vert;
    for(i=0;i<N;i++) {
	for(j=i;j<N;j++) {
	    if(j==0&&i==0) {
		current_vert = get_sommet_val(i,j);
	    }
	    else {
		next_vert = get_sommet_val(i,j);
		if(current_vert!=next_vert) {
		    //ajouter a l'arbre
		}
	    }
	}
    }
}
