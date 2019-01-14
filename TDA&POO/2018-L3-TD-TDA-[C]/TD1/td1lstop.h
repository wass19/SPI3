#ifndef _TD1LSTOP_H
#define _TD1LSTOP_H


#include "lstprim.h"

/*  opérations d'affichage */

void ListeAfficher(LISTE L) ;
	/* affiche un par un les élements de la liste L */
	/* remarque le type Element doit posséder une fonction d'affichage */

	
/* opérations de modification */

LISTE ListeCopier(LISTE l);
	/* retourne une copie de la liste l donnée en paramètre */

int ListeRemplacer(ELEMENT x,ELEMENT y,LISTE l);
	/* Remplace toutes les occurences de x par y dans la liste l et retourne le nombre d'opérations effectuées */

void ListeInverser(LISTE L1,LISTE L2);
	/* Effectue une copie de la liste L2 dans la liste L1 de facon inverser */

LISTE ListePermuter(POSITION p, POSITION q, LISTE L);
	/* Effectue une copie de la liste L en inversant les elements aux positions p et q */

LISTE ListeConcatener(LISTE L1,LISTE L2);
	/* Renvoi la liste L1 après l'avoir concatener avec la liste L2 */

#endif
