/*
 * auteur : LeNomDeLEtudiant
 * version 0.1 : Date : Sun Sep 30 13:31:10 CEST 2018
 *
*/
#include <stdlib.h>
#include <stdio.h>

#include "td1lstop.h"

void ListeAfficher(LISTE L) {
	POSITION p = ListePremier(L), fin = ListeSentinelle(L);
		printf("\n(");
		while(p!= fin) {
			ElementAfficher(ListeAcceder(p, L));
			p = ListeSuivant(p, L);
		}
		printf(")\n");
}

LISTE ListeCopier(LISTE l){
	POSITION p=ListePremier(l);
	POSITION fin=ListeSentinelle(l);
	LISTE copie=ListeCreer();
	POSITION q=ListePremier(copie);
	while(p!=fin){
		ListeInserer(ListeAcceder(p,l),q,copie);
		p=ListeSuivant(p,l);
		q=ListeSuivant(q,copie);
	}return copie;
}

int ListeRemplacer(ELEMENT x,ELEMENT y,LISTE l){
	POSITION p=ListePremier(l);
	int nb=0;
	for(;p!=ListeSentinelle(l);p=ListeSuivant(p,l)){
		if(ElementIdentique(x,ListeAcceder(p,l))){
			ListeSupprimer(p,l);
			ListeInserer(y,p,l);
			nb++;
		}
	}return nb;
}

void ListeInverser(LISTE L1,LISTE L2){
	POSITION p= ListePremier(L2);
	POSITION fin = ListeSentinelle(L2);
	POSITION q= ListePremier(L1);
	for(;p!=fin;p=ListeSuivant(p,L2)){
		ListeInserer(ListeAcceder(p,L2),q,L1);
	}
}

LISTE ListePermuter(POSITION p, POSITION q, LISTE L){
	LISTE LL = ListeCreer();
	POSITION courant = ListePremier(L);
	POSITION finL = ListeSentinelle(L);
	POSITION courantLL=ListePremier(LL);
	for(;courant != finL;){
		if(courant==p){
			ListeInserer(ListeAcceder(q,L),courantLL,LL);
		}else if(courant == q){
			ListeInserer(ListeAcceder(p,L),courantLL,LL);
		}else{
			ListeInserer(ListeAcceder(courant,L),courantLL,LL);
		}courant = ListeSuivant(courant,L);
		courantLL = ListeSuivant(courantLL,LL);
	}return LL;
}

LISTE ListeConcatener(LISTE L1,LISTE L2){
	POSITION fin=ListeSentinelle(L1);
	POSITION debut=ListePremier(L2);
	POSITION dernier=ListeSentinelle(L2);
	while(debut!=dernier){
		ListeInserer(ListeAcceder(debut,L2),fin,L1);
		fin=ListeSuivant(fin,L1);
		debut=ListeSuivant(debut,L2);
	}return L1;
}
