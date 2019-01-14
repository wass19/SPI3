/************  FICHIER  TestTD1.C  **************/
/* programme de test du TD N°1 Exercice 1 */

#include "c1lstop.h" 	/* Cours 1 (umtice)*/
#include "eltprim.h" 	/* Cours 1 (umtice)*/
#include "lstprim.h" 	/* Cours 1 (umtice)*/
#include "td1lstop.h"  	/* Prototype des fonctions du TD1 (a écrire)*/
#include  <stdio.h>
#include  <stdlib.h>

int main()
{
	LISTE L1, LDES, LFIN;
	ELEMENT elt; 	
	POSITION p;
	int i,n; 
	printf("\nEntrez 4 éléments pour L1 : \n ");
	L1 = ListeCreer();
	/* saisir une liste d' élements et les insérer au début */
	p = ListePremier(L1);
	printf("\nEntrez 4 éléments pour L1 : \n ");
	for (i=1; i<=4; i++) {
		
        elt=ElementCreer() ;	 
     	ElementLire(&elt);
		ListeInserer(elt, p, L1);
		p = ListeSuivant(p, L1);
	};
	/* Inverser les ELEMENTS de Tete et de fin */
	printf("\nL1 Avant remplacement : ");
	ListeAfficher(L1);
	printf("\nEntrez l'élément à remplacer : ");
	ELEMENT eltARemplacer = ElementCreer();
	ElementLire(&eltARemplacer);
	printf("\nEntrez l'éléments de remplacement : ");
	ELEMENT eltDeRemplacement = ElementCreer();
	ElementLire(&eltDeRemplacement);
	printf("\nL1 Après remplacement : ");
	ListeRemplacer(eltARemplacer,eltDeRemplacement, L1);
	ListeAfficher(L1);
    
	LDES= ListeCreer () ;
	ListeInverser(LDES, L1);
	printf("\nTest de inverser L1");
	printf("\tLe résultat est dans LDES") ;
	ListeAfficher(LDES);
	ListeConcatener(LDES, L1);
	printf("\nTest de concatener LDES et son inverse L1 ");
    printf("\tLe résultat est dans LDES") ;	
    ListeAfficher(LDES);
   // LFIN = ListeFusionner (LDES, L1) ;
	printf("\nTest de fusionner L1 et LDES\n") ;
	
	ListeDetruire(LDES);
	ListeDetruire(L1);
	exit(0);
}