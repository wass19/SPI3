/*
 * auteur : LeNomDeLEtudiant
 * version 0.1 : Date : Wed Oct 11 17:10:14 CEST 2017
 *
*/
#include <stdlib.h>
#include <stdio.h>

#include "ARBRE_prim.h"

int main(){

	printf("Test de construction de l'arbre\n");
	
	ARBRE e = ArbreConstruire('e', PAS_DE_FILS);
	ARBRE f = ArbreConstruire('f', PAS_DE_FILS);
	ARBRE c = ArbreConstruire('c', PAS_DE_FILS);
	ARBRE g = ArbreConstruire('g', PAS_DE_FILS);
	
	// Fils de B
	FRERES filsDeB = FreresCreer();
	FreresAjouter(filsDeB, e);
	FreresAjouter(filsDeB, f);
	ARBRE b = ArbreConstruire('b', filsDeB);

	// Fils de D
	FRERES filsDeD = FreresCreer();
	FreresAjouter(filsDeD, g);
	ARBRE d = ArbreConstruire('d', filsDeD);

	// Fils de A
	FRERES filsDeA = FreresCreer();
	FreresAjouter(filsDeA, b);
	FreresAjouter(filsDeA, c);
	FreresAjouter(filsDeA, d);
	ARBRE a = ArbreConstruire('a', filsDeA);

	printf("Test d'affichage de l'arbre :\n");
	ArbreAfficher(a);

	printf("Test du premier sous-arbre de l'arbre :\n");
	ArbreAfficher(PremierFils(a));

	printf("Test du deuxième sous-arbre de l'arbre :\n");
	ArbreAfficher(FilsSuivant(PremierFils(a), a));

	printf("Test du troisième sous-arbre de l'arbre :\n");
	ArbreAfficher(FilsSuivant(FilsSuivant(PremierFils(a), a), a));

	printf("Test du quatrième sous-arbre de l'arbre :\n");
	ArbreAfficher(FilsSuivant(FilsSuivant(FilsSuivant(PremierFils(a), a), a), a));

	printf("Test du premier sous-arbre du premier sous-arbre de l'arbre :\n");
	ArbreAfficher(PremierFils(PremierFils(a)));

	printf("Test du premier sous-arbre du premier sous-arbre du premier sous-arbre de l'arbre :\n");
	ArbreAfficher(PremierFils(PremierFils(PremierFils(a))));

	printf("Test de l'étiquette de A : \n");
	ElementAfficher(Etiquette(a));
	printf("\n");

	printf("Test de feuille sur a : %i (booléen)\n", EstFeuille(a));
	printf("Test de feuille sur b : %i (booléen)\n", EstFeuille(PremierFils(a)));
	printf("Test de feuille sur c : %i (booléen)\n", EstFeuille(FilsSuivant(PremierFils(a), a)));

	printf("Test de déstruction de l'arbre\n");
	ArbreDetruire(a);

}
