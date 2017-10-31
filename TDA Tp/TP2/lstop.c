/*
 * auteur : LeNomDeLEtudiant
 * version 0.1 : Date : Wed Oct 04 13:44:50 CEST 2017
 *
*/
#include <stdlib.h>
#include <stdio.h>

#include "lstop.h"

// Compte le nombre d'élements de la liste l
int ListeNbElements(LISTE l){
	POSITION p = ListePremier(l);
	POSITION m = ListeSentinelle(l);
	
	int i = 1;

	while(p != m){
		p = ListeSuivant(p, l);
		i++;
	}

	return i;
}

// Affiche la liste L
void ListeAfficher(LISTE L) {
	POSITION p = ListePremier(L), fin = ListeSentinelle(L);
		printf("\n(");
		while(p!= fin) {
			printf(" ");
			ElementAfficher(ListeAcceder(p, L));
			p = ListeSuivant(p, L);
		}
		printf(" )\n");
}


// Renverse la liste src dans la liste dst
void ListeInverser(LISTE dst, LISTE src){
	
	if(!ListeVide(dst)){
		printf("ListeInverser > La liste de destination n'est pas vide !");
		return;
	}

	ELEMENT tmp;
	POSITION pos  = ListePremier(src);
	POSITION tete = ListePremier(dst);
	POSITION fin  = ListeSentinelle(src);

	while(pos != fin){
		ListeInserer(ListeAcceder(pos, src), tete, dst);
		pos = ListeSuivant(pos, src);
	}
	
}

// Efface une liste de façon radicale (supprime les élements et les cellules et la liste)
void ListeBazooka(LISTE l){
	POSITION p;
	
	for(p = ListePremier(l) ; !ListeVide(l) ; p = ListePremier(l)){
		ElementDetruire(ListeAcceder(p,l));
		ListeSupprimer(p,l);
	} 

	ListeDetruire(l);
}
