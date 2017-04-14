/*! \file racine_optimal.c
 * \brief calcul et fonction de creation d'arbre
 * \author milang
 * \date 12/04/2017
 */



#include <stdlib.h>
#include <stdio.h>
#include "racine_optimal.h"
/**
 * \brief remplie le tableau 
 * \param i origine de l'essemble a generer 
 * \param j fin de l'ensemble à generer 
 */
void racine_optimal(int i,int j) {//suppose que pour i,j-1 et i+1,j deja calculé
    struct abr* addr=addr_parcour_moy(i,j);
    struct abr IJmoin=parcour_moy(i,j-1);
    struct abr IJplus=parcour_moy(i+1,j);
    if(i==j) {
	/*addr->poids=tabl[i];
	addr->sommet=i;
	addr->poids_somme=tabl[i];*/ //pas besoin de le memoyser : on a toute les info dans tabl 
//	printf("J'ai trouvé : %d\n",i);
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
/**
 * \brief hachage pour linéariser la memoire
 * \param i coordonnee virtuel i
 * \param j coordonnee virtuel j
 * \returns la struct abr contenu aux adresse virtuel (i,j)
 */
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
    if(i>N/2) {
	j=N-(j+1);//cf dessin
	i=N-(i+1);
	//printf("i : %d , j : %d\n",i,j);
    }
    return list_abr[i*N+j];
}
/**
 * \brief Voir parcour_moy différence : la coordonnee (i,i) est interdite
 * \params i coordonnee virtuel i
 * \params j coordonnee virtuel j
 * \returns l'adresse de la struct abr contenu à l'adresse (i,j)
 */
struct abr* addr_parcour_moy(int i,int j) {
    if(i>=j) { return NULL;}//Tableau triangulaire sup 
    if(i>N/2) {
	j=N-(j+1);//cf dessin
	i=N-(i+1);
	//printf("i : %d , j : %d\n",i,j);
    }
    return list_abr+i*N+j;
}
/**
 * \brief insere les valeurs dans l'arbre de manière récursive (si le premier appelle est bien (0,N-1)
 * \param i debut de l'ensemble ou chercher la racine optimal
 * \param j fin de l'ensemble ou chercher la racine optimal
 * \returns la valeur du sommet choisi pour pouvoir l'afficher comme racined du noeud precedent
 */
int inserer_recure(int i,int j) {
    int sommet;
    if(i==j) {
	arbre[i].noeudd=-1;
	arbre[i].noeudg=-1;
	return i;
    }
    if(i<j) {
	sommet = parcour_moy(i,j).sommet;
    }
    else {
	//normalement inutile
	sommet = parcour_moy(j,i).sommet;
    }
    //printf("Le sommet est %d\n",sommet);
    if(sommet==j) {
	arbre[sommet].noeudd=-1;
	arbre[sommet].noeudg=inserer_recure(i,sommet-1);
    }
    else if(sommet==i) {
	arbre[sommet].noeudd=inserer_recure(sommet+1,j);
	arbre[sommet].noeudg=-1;
    }
    else {
	arbre[sommet].noeudg=inserer_recure(i,sommet-1);
	arbre[sommet].noeudd=inserer_recure(sommet+1,j);
    }
    return sommet;
}
/**
 * \brief fait l'affichage de l'arbre sur la sortie stdout
 */
void construire_arbre() {
    int i;
    int racine =  parcour_moy(0,(int)N-1).sommet;
    //printf("RACINE = %d de (0,%lu)\n",racine,N-1);
    arbre[racine].fait=true;
    arbre[racine].noeudd=-1;
    arbre[racine].noeudg=-1;
    arbre[racine].sommet=racine;//on pourrait lavoir avec une diff de ptr
    //mais ca fait gagner des bannanes 
    inserer_recure(0,(int)N-1);
    printf("static int BSTroot = %d;\n",racine);
    printf("static int BSTtree[%lu][2] = {",N);
    for(i=0;i<N;i++) {
	if(i<N-1) 
	    printf("\n{%d, %d}, ",arbre[i].noeudg,arbre[i].noeudd);
	else 
	    printf("\n{%d, %d}",arbre[i].noeudg,arbre[i].noeudd);
    }
    printf(" };");
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
