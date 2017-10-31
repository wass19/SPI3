/*****************************************************************
*		Fichier :  	ELTcar.C
*		Format :	Source C 
*		Version  : 	19/9/96
*		Programmeurs :	Delozanne , Futtersack
*		Contenu :      	Définition des primitives pour une réalisatioon
*				par des caractères du TDA ELEMENT.
*		
******************************************************************/



/* définition des primitives du type concret ELEMENT caractère */

#include "eltprim.h"
#include <stdio.h>

void ElementLire(ELEMENT * elt)	{
	char s[2];
	scanf("%s",s);
	/* pour se debarrasser du RC; solution plus élégante ?*/
	*elt = s[0];
}

void ElementAfficher(ELEMENT elt)	{
	printf(" %c  ",elt);
}

ELEMENT ElementAffecter(ELEMENT * e1, ELEMENT e2)   {
	return  *e1 = e2  ;
}

bool ElementIdentique(ELEMENT e1, ELEMENT e2)  {
	/* retourne vrai si les deux arguments sont identiques */
	return 	e1 == e2 ;
}

ELEMENT ElementCreer () {
	return ELEMENT_VIDE ;
}

void ElementDetruire (ELEMENT e) {
}
