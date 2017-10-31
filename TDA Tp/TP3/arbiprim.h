/******************************************************************
*		Fichier :  	Arbiprim.H
*		Format :	Source C 
*		Version  : 	24/9/97
*		Programmeurs :	Delozanne, Jacoboni
*		Contenu :      	Déclaration des primitives du TDA Arbre binaire
*				(fichier indépendant de la représentation	
******************************************************************/
#ifndef _ARBIPRIM_H
	#define _ARBIPRIM_H
#include "eltprim.h"	/* utilise le TDA ELEMENT */
#include "arbisdd.h"	/* inclusion de la structure de donnée adoptée pour représenter les arbres */

/****************************************************/
/*		Déclaration des primitives		*/
/****************************************************/
/*		Primitives de création/destruction		*/
ARBIN ArbinCreer(void);
	/* retourne l'arbre  vide */
ARBIN ArbinDetruire(ARBIN A) ;
	/*	libère les cases mémoires occupées par A,
		retourne l'arbre vide */

/*****************************************************/
/*		Primitives de construction		*/
/* construction en programmation fonctionnelle - construction à côté*/
ARBIN ArbinConstruire(ELEMENT e, ARBIN G, ARBIN D);
	/*	retourne un arbre dont la racine  a
		- pour étiquette élément 
		- pour ss-arbre gauche et droit les deux autres arguments
	Remarque : l'arbre n'est construit qu'après tous ses sous-arbres*/

/* construction en programmation impérative, modification d'arbres non vides
construction sur place. pratiques pour les arbres "dynamiques"(ceux où l'on modifie souvent les noeuds)
Ces primitives permettent de modifier un arbre sans le reconstruire totalement*/
ARBIN ArbinGrefferAGauche (ARBIN n, ARBIN A);
	/*	A étant d'un arbre (non vide) ,  
		Greffe le sous-arbre n comme sous-arbre gauche de A
			( et écrase l'ancien sans le détuire )*/
ARBIN ArbinGrefferADroite (ARBIN n, ARBIN A);
	/*	A étant d'un arbre (non vide) ,
		Greffe le sous-arbre n comme sous-arbre droit de A
			( et écrase l'ancien sans le détuire )*/
void ArbinModifierEtiquette (ELEMENT E, ARBIN A);
	/*	A étant d'un arbre (non vide) ,
		remplace l'étiquette de la racine de A par E
			( et écrase l'ancienne sans la détuire )*/

/****************************************************/
/*		Primitives d'accès aux caractéristiques des noeuds		*/
ARBIN ArbinGauche(ARBIN A);
	/* si a n'est pas vide, retourne le sous-arbre gauche de l'arbre A
		sinon pas défini*/
ARBIN ArbinDroit(ARBIN A);
	/* si a n'est pas vide, retourne le sous-arbre gauche de l'arbre A
		sinon pas défini*/
ARBIN ArbinRacine(ARBIN A);
	/* si a n'est pas vide, retourne la racine l'arbre A
		sinon pas défini*/
ELEMENT ArbinEtiquette( ARBIN A);
	/* si a n'est pas vide,	retourne l'élément étiquette de la racine
	de l'arbre A sinon pas défini
	on parlera d'étiquette de l'arbre pour l'etiquette de sa racine*/

/****************************************************/
/*		Primitives de tests sur l'arbre binaire		*/
int ArbinVide( ARBIN A);
	/*retourne 1 si l' arbre est vide, 0 sinon */

#endif
/***********************************************************************/

