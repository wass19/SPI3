/*
 * auteur : LeNomDeLEtudiant
 * version 0.1 : Date : Wed Sep 27 13:53:12 CEST 2017
 *
*/
#include <stdlib.h>
#include <stdio.h>

#include "lstop.h"

void ListeAfficher(LISTE L) {
	POSITION p = ListePremier(L), fin = ListeSentinelle(L);
	printf("(");
	while(p!= fin) {
		ElementAfficher(ListeAcceder(p, L));
		p = ListeSuivant(p, L);
	}
	printf(")\n");
}


// Copier la liste src dans la liste dst
void ListeCopier(LISTE dst, LISTE src){
	POSITION iDst   = ListeSentinelle(dst);
	POSITION iSrc   = ListePremier(src);
	POSITION maxSrc = ListeSentinelle(src);

	ELEMENT tmp;

	while(iSrc != maxSrc){
		tmp = ListeAcceder(iSrc, src);
		
		if(!ListeInserer(tmp, iDst, dst)){
			printf("ListeCopier > Problème d'insertion\n");
			return;
		}

		iSrc = ListeSuivant(iSrc, src);
		iDst = ListeSuivant(iDst, dst);
	}
}