/*
 * auteur : LeNomDeLEtudiant
 * version 0.1 : Date : Mon Oct 02 18:28:27 CEST 2017
 *
*/
#include <stdlib.h>
#include <stdio.h>


// Retourne un ensemble vide
ENSEMBLE EnsembleCreer(){
	return ListeCreer();
}

// Libère la mémoire allouée pour l'ensemble e
void EnsembleDetruire(ENSEMBLE e){
	
}

// Teste si l'élément x appartient à l'ensemble e
bool EnsembleAppartenir(ELEMENT x, ENSEMBLE e){
	return FAUX;
}

// Ajoute l'élément x dans l'ensemble e si il n'y est pas déjà
bool EnsembleAjouter(ELEMENT x, ENSEMBLE e){
	return FAUX;
}

// Supprime l'élément x de l'ensemble e
bool EnsembleSupprimer(ELEMENT x, ENSEMBLE e){
	return FAUX;
}

// Teste si l'ensemble e est vide
bool EnsembleVide(ENSEMBLE e){
	return FAUX;
}

// Retourne le nombre d'élements de l'ensemble e
int EnsembleCardinal(ENSEMBLE e){
	return 0;
}

