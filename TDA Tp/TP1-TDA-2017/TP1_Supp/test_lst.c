/*
 * auteur : PELLOIN Valentin
 * version 0.1 : Date : Wed Sep 27 13:36:22 CEST 2017
 *
*/
#include <stdlib.h>
#include <stdio.h>

#include "eltprim.h"
#include "lstprim.h"

#include "lstop.h"

#define N 3

int main(){

	int i;
		
	ELEMENT elt;
	LISTE l1 = ListeCreer();
	LISTE l2 = ListeCreer();
	
	POSITION pos1 = ListePremier(l1);
	POSITION pos2 = ListePremier(l2);

	printf("Lecture des elements de la liste l1 : \n");
	for(i = 1 ; i <= N ; i++){
		elt = ElementCreer();
		printf("Veuillez indiquer l'élement %i: ", i);
		ElementLire(&elt);
		ListeInserer(elt, pos1, l1);
		pos1 = ListeSuivant(pos1, l1);
	}

	printf("Lecture des elements de la liste l2 : \n");
	for(i = 1 ; i <= N ; i++){
		elt = ElementCreer();
		printf("Veuillez indiquer l'élement %i: ", i);
		ElementLire(&elt);
		ListeInserer(elt, pos2, l2);
		pos2 = ListeSuivant(pos2, l2);
	}


	printf("Affichage de la liste l1 : \n");
	ListeAfficher(l1);
	printf("Affichage de la liste l2 : \n");
	ListeAfficher(l2);

	printf("Suppression du premier élement de l1 :\n");
	ListeSupprimer(ListePremier(l1), l1);
	ListeAfficher(l1);

	printf("Destruction de l1\n");
	ListeDetruire(l1);
	printf("Destruction de l2\n");
	ListeDetruire(l1);
}
