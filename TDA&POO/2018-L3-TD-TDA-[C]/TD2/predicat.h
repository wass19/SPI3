
/*****************************************************************
* Fichier :  	PREDICAT.H
*		Format :	Source C 
*		Version  : 	02/10/2018
*		Programmeurs :	Oktay Samed
*		Contenu :      déclarations des opérations TD2 
******************************************************************/

#ifndef _PREDICAT_H                   /* pour l'inclusion conditionnelle */
#define _PREDICAT_H


#include "eltprim.h"

int Nombre(ELEMENT x);
	/* Retourne vrai si x est un nombre si non faux */

int Operateur(ELEMENT x);
	/* Retourne vrai si x est un opérateur si non faux */

int Ouvrante(ELEMENT x);
	/* Retourne vrai si x est une paranthèse ouvrante si non faux */

int Fermante(ELEMENT x);
	/* Retourne vrai si x est une paranthèse fermante si non faux */

int Prioritaire(ELEMENT x1,ELEMENT x2);
	/* Retourne vrai si x1 à une prioriyé supérieur ou égal à x2 si non faux */

ELEMENT Applique(ELEMENT op,ELEMENT xg, ELEMENT xd);
	/* Retourne la valeur de l'operation entre les 2 opérandes et l'operateur si le paramètre n'est pas un opérateur retourne -1 */

int ElementToEntier(ELEMENT x);
	/* Retourne un entier correspondant à la valeur de l'élement en paramètre */

char ElementToCar(ELEMENT x);
	/* Retourne un caractère correspondant à l'élement en paramètre */

ELEMENT EntierToElement(int x);
	/* Retourne un entier correspondant à l'entier en paramètre */

#endif
