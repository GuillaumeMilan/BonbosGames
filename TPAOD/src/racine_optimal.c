#include <stdlib.h>
#include "racine_optimal.h"
int racine_optimal(i,j) {
    if(i==j) {
	return 1;
    }
    else {
	
    }
}

long parcour_moy(i,j) {
    if(i>j) { return -1;}//Tableau de diagonal 
    if(j>N/2) {
	j=N-(j);//cf dessin
	i=N-i(i+1);
    }
    return poids[i*N+j];
}
long* addr_parcour_moy(i,j) {
    if(i>j) { return -1;}//Tableau de diagonal 
    if(j>N/2) {
	j=N-(j);//cf dessin
	i=N-i(i+1);
    }
    return poids+i*N+j;
}
int *get_sommet(i,j) {
    return sommet+j+N-1-i;
}
int get_sommet_val(i,j) {
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
