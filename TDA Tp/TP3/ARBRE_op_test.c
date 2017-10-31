/*
 * auteur : LeNomDeLEtudiant
 * version 0.1 : Date : Sun Oct 15 15:47:33 CEST 2017
 *
*/
#include <stdlib.h>
#include <stdio.h>

#include "ARBRE_prim.h"
#include "ARBRE_op.h"

int main(){

	ELEMENT eE = ElementCreer(), 
			eF = ElementCreer(), 
			eC = ElementCreer(), 
			eG = ElementCreer(), 
			eB = ElementCreer(), 
			eD = ElementCreer(), 
			eA = ElementCreer();
	
	ElementAffecter(&eE, "e");
	ElementAffecter(&eF, "f");
	ElementAffecter(&eC, "c");
	ElementAffecter(&eG, "g");
	ElementAffecter(&eB, "b");
	ElementAffecter(&eD, "d");
	ElementAffecter(&eA, "a");
	
	ARBRE e = ArbreConstruire(eE, PAS_DE_FILS);
	ARBRE f = ArbreConstruire(eF, PAS_DE_FILS);
	ARBRE c = ArbreConstruire(eC, PAS_DE_FILS);
	ARBRE g = ArbreConstruire(eG, PAS_DE_FILS);
	
	// Fils de B
	FRERES filsDeB = FreresCreer();
	FreresAjouter(filsDeB, e);
	FreresAjouter(filsDeB, f);
	ARBRE b = ArbreConstruire(eB, filsDeB);

	// Fils de D
	FRERES filsDeD = FreresCreer();
	FreresAjouter(filsDeD, g);
	ARBRE d = ArbreConstruire(eD, filsDeD);

	// Fils de A
	FRERES filsDeA = FreresCreer();
	FreresAjouter(filsDeA, b);
	FreresAjouter(filsDeA, c);
	FreresAjouter(filsDeA, d);
	ARBRE a = ArbreConstruire(eA, filsDeA);

	ArbreAfficher(a);

	printf("\nTest d'affichage préfixe de l'arbre a:\n");
	ArbreAffichePref(a);

	ARBRE fils = PremierFils(a);
	printf("\nTest d'affichage du père du premier fils de a:");
	ElementAfficher(Etiquette(ArbrePereNoeud(fils, a)));
	printf("\nTest d'affichage du père du premier fils du premier fils de a:");
	ElementAfficher(Etiquette(ArbrePereNoeud(PremierFils(fils), a)));
	printf("\nTest d'affichage du père du deuxième fils de a:");
	fils = FilsSuivant(fils, a);
	ElementAfficher(Etiquette(ArbrePereNoeud(fils, a)));

	printf("\nTest d'affichage de l'arbre a par niveau: ");
	ArbreAfficherNiveau(a);
	printf("\nTest d'affichage des feuilles de a: ");
	ArbreAfficherFeuilles(a);

	printf("\nTest de lecture d'un arbre :\n");
	ARBRE a2 = ArbreLire();

	ArbreAfficher(a2);

	
	ArbreDetruire(a);
	ArbreDetruire(a2);

	ElementDetruire(eE);
	ElementDetruire(eF);
	ElementDetruire(eC);
	ElementDetruire(eG);
	ElementDetruire(eB);
	ElementDetruire(eD);
	ElementDetruire(eA);

	printf("\n");
}
