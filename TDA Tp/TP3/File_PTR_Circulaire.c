/*
 * auteur : LeNomDeLEtudiant
 * version 0.1 : Date : Sat Oct 07 16:09:00 CEST 2017
 *
*/
#include <stdlib.h>
#include <stdio.h>

#include "File_PTR_Circulaire.h"
#include "File_Prim.h"

// crée et retourne une file vide en lui allouant dynamqiuement de la mémoire
FFILE FileCreer(int profondeur){

	FFILE rslt = malloc(sizeof(file));

	if(rslt == NULL){
		printf("FileCreer: malloc a renvoyé NULL\n");
		exit(1);
	}
	
	ElementAffecter(&(rslt->data), NULL);
	rslt->suivant = NULL;

	return rslt;
}

// libère la mémoire allouée pour la file
void FileDetruire(FFILE f){
	while(!FileVide(f))
		FileSortir(f);
	free(f);
}
	
// teste si la file est vide
int FileVide(FFILE f){
	return f == NULL || f->suivant == NULL;
}

// retourne l'élément au début de la file sans le retirer de la file
ARBRE FileDebut(FFILE f){
	if(!FileVide(f)){
		return f->suivant->suivant->data;
	}
	printf("FileDebut: La file est vide");
	return NULL;
}

// retourne l'élément au début de la file en le retirant de la file
ARBRE FileSortir(FFILE f){
	if(!FileVide(f)){
		FFILE aSortir = f->suivant->suivant;
		ARBRE elt;

		ElementAffecter(&elt, aSortir->data);

		// On regarde si il y a plus d'un élement dans la liste
		if(aSortir != aSortir->suivant){
			f->suivant->suivant = aSortir->suivant;
		}
		else {
			// La file devient vide
			f->suivant = NULL;
		}

		free(aSortir);

		return elt;
	}
	printf("FileSortir: La file est vide");
	return NULL;
}

// place l'élément à la fin de la file
int FileEntrer(ARBRE e, FFILE a){
	if(a != NULL){
		FFILE n = FileCreer(0);

		if(a->suivant == NULL){
			n->suivant = n;
		}
		else {
			n->suivant = a->suivant->suivant;
			a->suivant->suivant = n;
		}
		a->suivant = n;

		ElementAffecter(&(n->data), e);

		return VRAI;
	}
	else {
		printf("FileEntrer: La file n'existe pas !\n");
		return FAUX;
	}
}

// Affiche la file
void FileAfficher(FFILE f){
	printf("\n[ ");
	if(!FileVide(f)){
		FFILE tmp;

		for(tmp = f->suivant->suivant ; tmp != f->suivant ; tmp = tmp->suivant){
			ElementAfficher(tmp->data);
			printf(" ");
		}
		ElementAfficher(tmp->data);
	}

	printf(" ]\n");
}

// Affiche la file en interne
void FileRadiographier(FFILE f){
	if(f != NULL){
		FFILE tmp;
		
		printf("\n");
		printf("[RIEN : %p | suivant : %p]\n", f, f->suivant);

		if(f->suivant != NULL){
			for(tmp = f->suivant->suivant ; tmp != f->suivant ; tmp = tmp->suivant){
				printf("\n\t[");
				ElementAfficher(tmp->data);
				printf(" : %p | suivant : %p] ", tmp, tmp->suivant);
			}
			printf("\n\t[");
			ElementAfficher(tmp->data);
			printf(" : %p | suivant : %p] ", tmp, tmp->suivant);
		}
	}
	printf("\n");
}
