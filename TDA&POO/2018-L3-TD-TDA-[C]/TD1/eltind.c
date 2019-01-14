/*
 * auteur : LeNomDeLEtudiant
 * version 0.1 : Date : Sun Sep 30 15:28:36 CEST 2018
 *
*/
#include <stdlib.h>
#include <stdio.h>

#include "eltprim.h"
#include <stdio.h>
#include <string.h>

#define ELEMENT_VIDE NULL
/*
void ElementLire(ELEMENT * e){
	printf("Entrez un prenom : ");
	scanf("%s",e->prenom);
	printf("Entrez un nom : ");
	scanf("%s",e->nom);
	printf("Entrez une rue : ");
	scanf("%s",e->adresse.rue);
	printf("Entrez une ville : ");
	scanf("%s",e->adresse.ville);
	printf("Entrez un code : ");
	scanf("%s",e->adresse.code);
}

void ElementAfficher(ELEMENT e){
	printf("Nom : %s Prenom : %s Adresse : rue %s %s %i\n",e->nom,e->prenom,e->adresse.rue,e->adresse.ville,e->adresse.code);
}

ELEMENT ElementAffecter(ELEMENT *e1, ELEMENT e2){
	strcpy(e1->nom,e2->nom);
	strcpy(e1->prenom,e2->prenom);
	strcpy(e1->adresse.rue,e2->adresse.rue);
	strcpy(e1->adresse.ville,e2->adresse.ville);
	e1->adresse.code=e2->adresse.code;
}

bool ElementIdentique(ELEMENT e1, ELEMENT e2){
	if((strcmp(e1->nom,e2->nom)) || (strcmp(e1->prenom,e2->prenom)) || (strcmp(e1->adresse.rue,e2->adresse.rue)) || (strcmp(e1->adresse.ville,e2->adresse.ville)) || (e1->adresse.code!=e2->adresse.code)){
		return FAUX;
	}else{
		return VRAI;
	}
}

ELEMENT ElementCreer(){
	ELEMENT x = (ELEMENT)malloc(sizeof(FICHE));
	if(!x){
		printf("probleme de memoire\n");
		exit(0);
	}
	x->nom = x->prenom = NULL;
	x->adresse.rue = x->adresse.ville = NULL;
	x->adresse.code=0;
	return x;
}

void ElementDetruire (ELEMENT x){
	if(x){
		free(x->prenom);
		free(x->nom);
		free(x->adresse.rue);
		free(x->adresse.ville);
		free(x);
	}
}*/
