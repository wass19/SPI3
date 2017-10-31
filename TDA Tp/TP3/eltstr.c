/*
 * auteur : LeNomDeLEtudiant
 * version 0.1 : Date : Sun Oct 15 19:15:09 CEST 2017
 *
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "eltprim.h"

void ElementLire(ELEMENT * elt) {
	char tmp[256];
	int len;
	scanf("%s", tmp);

	len = strlen(tmp) + 1;

	*elt = malloc(sizeof(char) * len);
	memcpy(*elt, tmp, sizeof(char) * len);
}

void ElementAfficher(ELEMENT elt) {
	printf("%s", elt);
}

ELEMENT ElementAffecter(ELEMENT * e1, ELEMENT e2) {
	ElementDetruire(*e1);
	*e1 = malloc(sizeof(char) * (1 + strlen(e2)));
	memcpy(*e1, e2, sizeof(char) * (strlen(e2) + 1));
	return *e1;
}

bool ElementIdentique(ELEMENT e1, ELEMENT e2) {
	/* retourne vrai si les deux arguments sont identiques */
	return strcmp(e1, e2) == 0;
}

ELEMENT ElementCreer() {
	return NULL;
}

void ElementDetruire(ELEMENT e) {
	if(e != NULL)
		free(e);
}
