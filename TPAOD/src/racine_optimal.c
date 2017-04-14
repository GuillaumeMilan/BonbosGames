#include <stdlib.h>
#include <stdio.h>
#include "racine_optimal.h"
void racine_optimal(int i,int j) {//suppose que pour i,j-1 et i+1,j deja calculé
    struct abr IJmoin=parcour_moy(i,j-1);
    struct abr IJplus=parcour_moy(i+1,j);
    struct abr* addr=addr_parcour_moy(i,j);
    if(i==j) {
	/*addr->poids=tabl[i];
	addr->sommet=i;
	addr->poids_somme=tabl[i];*/ //pas besoin de le memoyser : on a toute les info dans tabl 
	//printf("J'ai trouvé : %d\n",i);
	return;
    }
    else {
	addr->poids=(unsigned long)-1;
	addr->sommet=-1;
	int k;
	unsigned long poids;
	//printf("(i,j-1) : %d\n(i+1,j) : %d\n",IJmoin.sommet,IJplus.sommet);
	for(k=IJmoin.sommet;k<=IJplus.sommet;k++) {
	    struct abr tempd;
	    struct abr tempg;
	    if(k==i) {
		//printf("k==i==%d\n",i);
		tempg = parcour_moy(k+1,j);
		//printf("sommet %d prof : %lu poids :%lu\n",tempg.sommet,tempg.poids,tempg.poids_somme); 
		//printf("poids_origine : %lu\n",tabl[k+1]);
		poids = tabl[k]+tempg.poids+tempg.poids_somme;
		tempd.poids_somme=0;
	    }
	    else if(k==j) {
		//printf("k==j==%d\n",j);
		tempg = parcour_moy(i,k-1);
		//printf("sommet %d prof : %lu poids :%lu\n",tempg.sommet,tempg.poids,tempg.poids_somme); 
		poids = tempg.poids+tabl[k]+tempg.poids_somme;
		tempd.poids_somme=0;
	    }
	    else {
		tempg = parcour_moy(k+1,j);
		tempd = parcour_moy(i,k-1);
		if(i==0&&j==4) {
		  //  printf("poids_d: %d,sme_poids_d: %d",1,2);
		}
		poids = tempg.poids_somme+tempg.poids+tabl[k]+tempd.poids_somme+tempd.poids;
	    }
		//printf("sommet : %d , poids : %lu\n",k,poids);
	    if(poids<addr->poids) {
		addr->sommet=k;
		addr->poids=poids;
		addr->poids_somme=tempd.poids_somme+tempg.poids_somme+tabl[k];
		//printf("poids somme %lu\n",addr->poids_somme); 
	    }

	}
    }

    //printf("j'ai trouvé : %d\n",addr->sommet);
}

struct abr parcour_moy(int i,int j) {
    struct abr rien={-1,-1};
    if(i>j) { return rien;}//Tableau de diagonal 
    if(i==j) {
	struct abr retour;
	retour.poids=tabl[i];
	retour.poids_somme=tabl[i];
	retour.sommet=i;
	return retour;
    }
    if(j>N/2) {
	j=N-(j+1);//cf dessin
	i=N-(i+1);
	//printf("i : %d , j %d\n",i,j);
    }
    return list_abr[i*N+j];
}
struct abr* addr_parcour_moy(int i,int j) {
    if(i>j) { return NULL;}//Tableau de diagonal 
    if(j>N/2) {
	j=N-(j+1);//cf dessin
	i=N-(i+1);
	//printf("i : %d , j %d\n",i,j);
    }
    return list_abr+i*N+j;
}
void construire_arbre() {
    int i;
    int j;
    int current_vert;
    int next_vert;
    for(i=0;i<N;i++) {
	for(j=i;j<N;j++) {
	    if(j==0&&i==0) {
		current_vert = parcour_moy(i,j).sommet;
	    }
	    else {
		next_vert = parcour_moy(i,j).sommet;
		if(current_vert!=next_vert) {
		    //ajouter a l'arbre
		}
	    }
	}
    }
}
void calc_poids() {
    int i,j;
    for(i=0;i<N;i++) {
	for(j=i;j<N;j++) {
	    //printf("(%d,%d)\n",j-i,j);
	    racine_optimal(j-i,j);
	}
    }
}
