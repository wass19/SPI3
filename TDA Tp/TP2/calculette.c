/*
 * auteur : LeNomDeLEtudiant
 * version 0.1 : Date : Wed Oct 04 15:26:55 CEST 2017
 *
*/
#include <stdlib.h>
#include <stdio.h>

#include "eltsdd.h"
#include "eltprim.h"
#include "operations.h"

#include  "lstprim.h"
#include "pileprim.h"

#include "lstop.h"
#include "interpreteur.h"


int main(){


	bool continuer = VRAI;
	char commande[MAX_BUFFER];

	do {
		
		prompt(commande);
		continuer = interpreter(commande);
		
	} while(continuer);
}
