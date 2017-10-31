/*
 * auteur : LeNomDeLEtudiant
 * version 0.1 : Date : Sun Oct 01 21:20:01 CEST 2017
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

	LISTE infixe = ListeCreer();
	LISTE postfixe;
	POSITION pos = ListePremier(infixe);
	ELEMENT tmp;

	int i, n = 0;
	printf("De combien élements est composé votre expression bien parenthésée ? : ");
	scanf("%i", &n);
	
	for(i = 1 ; i <= n ; i++){
		tmp = ElementCreer();
		printf("Element n° %i : ", i);
		ElementLire(&tmp);

		ListeInserer(tmp, pos, infixe);
		pos = ListeSuivant(pos, infixe);

		ElementDetruire(tmp);
	}

	printf("Expression infixe : ");
	ListeAfficher(infixe);

	printf("Expression postfixe : ");
	postfixe = inf2Post(infixe);
	ListeAfficher(postfixe);

	printf("Evaluation de l'expression postfixée : ");
	tmp = evaluationPost(postfixe);
	ElementAfficher(tmp);

	printf("\n");
	
	ListeBazooka(infixe);
	ListeBazooka(postfixe);
}
