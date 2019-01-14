/*****************************************************************
*		Fichier :  	c1test1.C
*		Format :	Source C 
*		Version  : 	19/9/96
*		Programmeurs :	Delozanne, Jacoboni
*		Contenu :      	Test du TDA LISTE
*		
******************************************************************/

/* programme de test des opérations du TDA LISTE du cours N°1 */

/* test de la réalisation du TDA liste  */
/* les éléments sont ici des entiers  stockage direct */
/* stockage indirect à tester Cf. TD2 et TP1 */

#include <stdio.h>
#include <stdlib.h>
#include "c1lstop.h"
#include "eltprim.h"
#include "lstprim.h"
#include "predicat.h"
#include "pileprim.h"

int main( int nb_arg , char * tab_arg[] )	{
	printf("sa compile\n");
	LISTE L = ListeCreer();
	POSITION p = ListePremier(L);
	ELEMENT elt;
	for(int i = 0; i < 11  ; i++ ){
		elt = ElementCreer() ;
		ElementLire(&elt) ;
		ListeInserer(elt, p, L);
		p = ListeSuivant(p, L);
	}
	ListeAfficher(L);
	p = ListePremier(L);
	POSITION q = ListeSuivant(p,L);
	printf("Nombre : %i\n",Nombre(ListeAcceder(p,L)));
	printf("Operateur : %i\n",Operateur(ListeAcceder(p,L)));
	printf("Ouvrante : %i\n",Ouvrante(ListeAcceder(p,L)));
	printf("Fermante : %i\n",Fermante(ListeAcceder(p,L)));
	printf("Appliquer : %i\n",Applique(ListeAcceder(p,L),ListeAcceder(q,L),ListeAcceder(ListeSuivant(q,L),L)));
	exit(0) ;
}

