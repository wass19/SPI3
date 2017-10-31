/*
 * auteur : LeNomDeLEtudiant
 * version 0.1 : Date : Sun Oct 15 19:29:05 CEST 2017
 *
*/
#include <stdlib.h>
#include <stdio.h>

#include "eltprim.h"

int main(){
	ELEMENT tmp = ElementCreer();
	ElementLire(&tmp);
	ElementAfficher(tmp);
	ElementAffecter(&tmp, "salut");
	ElementAfficher(tmp);
	ElementDetruire(tmp);
}
