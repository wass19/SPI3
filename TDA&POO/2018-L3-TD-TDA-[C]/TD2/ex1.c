/*
 * auteur : LeNomDeLEtudiant
 * version 0.1 : Date : Tue Oct 02 17:47:40 CEST 2018
 *
*/
#include <stdlib.h>
#include <stdio.h>

#include "pileprim.h"
#include "lstprim.h"

LISTE Inf2Post(LISTE LI){
	ELEMENT x;
	LISTE LP = ListeCreer();
	PILE P = PileCreer();
	POSITION pos = ListePremier(LI),fin = ListeSentinelle(LI);
	for(;pos!=fin;pos=ListeSuivant(LI)){
		ElementAffecter(&x,ListeAcceder(pos,LI));
		if(Ouvrante(x)){
	}
}
