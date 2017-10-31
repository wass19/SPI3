/*
 * auteur : LeNomDeLEtudiant
 * version 0.1 : Date : Sun Oct 01 18:35:44 CEST 2017
 *
*/
#include <stdlib.h>
#include <stdio.h>

#include "eltsdd.h"
#include "eltprim.h"
#include "operations.h"

int main(){
	
	ELEMENT e1 = ElementCreer();
	ELEMENT e2 = ElementCreer();
	ELEMENT e3 = ElementCreer();
	ELEMENT e4;

	// Saisie des élements
	printf("Veuillez saisir l'élement e1 (nombre)    : ");
	ElementLire(&e1);
	printf("Veuillez saisir l'élement e2 (operation) : ");
	ElementLire(&e2);
	printf("Veuillez saisir l'élement e1 (nombre)    : ");
	ElementLire(&e3);

	// Test sur e1
	printf("\nTests sur `");
	ElementAfficher(e1);
	printf("` : \n");
	
	printf(" - Est un nombre     : %i\n", Nombre(e1));
	printf(" - Est un opérateur  : %i\n", Operateur(e1));
	printf(" - Est une ouvrante  : %i\n", Ouvrante(e1));
	printf(" - Est une fermante  : %i\n", Fermante(e1));

	// Test sur e2
	printf("\nTests sur `");
	ElementAfficher(e2);
	printf("` : \n");
	
	printf(" - Est un nombre     : %i\n", Nombre(e2));
	printf(" - Est un opérateur  : %i\n", Operateur(e2));
	printf(" - Est une ouvrante  : %i\n", Ouvrante(e2));
	printf(" - Est une fermante  : %i\n", Fermante(e2));


	// Test sur e3
	printf("\nTests sur `");
	ElementAfficher(e3);
	printf("` : \n");
	
	printf(" - Est un nombre     : %i\n", Nombre(e3));
	printf(" - Est un opérateur  : %i\n", Operateur(e3));
	printf(" - Est une ouvrante  : %i\n", Ouvrante(e3));
	printf(" - Est une fermante  : %i\n", Fermante(e3));
	

	// Test globaux
	printf("\nTest sur `");
	ElementAfficher(e1);
	printf("` et `");
	ElementAfficher(e2);
	printf("` : \n");
	
	printf(" - `");
	ElementAfficher(e1);
	printf(    "` est prioritaire sur `");
	ElementAfficher(e2);
	printf("` : %i\n", Prioritaire(e1, e2));
	printf(" - `");
	ElementAfficher(e2);
	printf(    "` est prioritaire sur `");
	ElementAfficher(e1);
	printf("` : %i\n", Prioritaire(e2, e1));


	// Test d'application
	printf("\nTest d'application de ");
	ElementAfficher(e1);
	printf(" ");
	ElementAfficher(e2);
	printf(" ");
	ElementAfficher(e3);
	printf(" = ");
	e4 = Applique(e2, e1, e3);
	ElementAfficher(e4);
	printf("\n");
	
	// Destruction
	ElementDetruire(e1);
	ElementDetruire(e2);
	ElementDetruire(e3);
	ElementDetruire(e4);
	
	printf("\n");
}
