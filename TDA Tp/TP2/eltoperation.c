/*
 * auteur : PELLOIN Valentin
 * version 0.1 : Date : Sun Oct 01 18:33:16 CEST 2017
 *
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "eltprim.h"

char op2char(Op o){
	switch(o){
		case OP_PLUS : return '+';
		case OP_MOINS: return '-';
		case OP_MULT : return '*';
		case OP_DIV  : return '/';

		default      : return '?';
	}
}

Op char2op(char c){
	switch(c){
		case '+': return OP_PLUS;
		case '-': return OP_MOINS;
		case '*': return OP_MULT;
		case '/': return OP_DIV;
	}
	return OP_ERR;
}

char pa2char(Pa p){
	switch(p){
		case PA_OUV: return '(';
		case PA_FER: return ')';

		default    : return '?';
	}
}

Pa char2pa(char c){
	switch(c){
		case '(': return PA_OUV;
		case ')': return PA_FER;
	}
	return PA_ERR;
}

// Lit un élement depuis stdin
void ElementLire(ELEMENT * s){
	char buffer[50];
	
	scanf("%s", buffer);

	ElementLireBuffer(s, buffer);
}

// Lit un élement depuis buffer
// fonctionne exactement comme la fonction ElementLire
void ElementLireBuffer(ELEMENT * s, char * buffer){

	int r;
	int len = strlen(buffer);

	// C'est un opérateur, une parenthèse ou un chiffre
	if(len == 1){
		// C'est un chiffre
		if(isdigit(buffer[0])){
			s->typeElement = NOMBRE;
			s->e.nb        = buffer[0] - '0';
		}
		// C'est un opérateur
		else if(buffer[0] == '(' || buffer[0] == ')'){
			s->typeElement = PARENTHESE;
			s->e.pa        = char2pa(buffer[0]);
		}
		else {
			s->typeElement = OPERATEUR;
			s->e.op        = char2op(buffer[0]);

			if(s->e.op == OP_ERR)
				printf("ElementLire: L'opérateur %c n'est pas valide !\n", buffer[0]);
		}
	}
	// C'est un nombre
	else if(len > 1){
		s->typeElement = NOMBRE;
		r = sscanf(buffer, "%i", &(s->e.nb));

		if(r != 1)
			printf("ElementLire: %s n'est pas un nombre valide !\n", buffer);
	}
	// C'est une erreur
	else {
		printf("ElementLire: Tu aurais pas oublié quelque chose par hasard ?\n");
	}
}


void ElementAfficher(ELEMENT elt){

	switch(elt.typeElement){
		case OPERATEUR:  printf("%c", op2char(elt.e.op)); break;
		case PARENTHESE: printf("%c", pa2char(elt.e.pa)); break;
		case NOMBRE:     printf("%i", elt.e.nb);          break;

		default: printf("ElementAfficher: Type inconnu"); break;
	}
}

ELEMENT ElementAffecter(ELEMENT * e1, ELEMENT e2){
	if(!e1){
		printf("ElementAffecter: L'element e1 n'existe pas !\n");
		exit(0);
	}
	
	*e1 = e2;
	
	return *e1;
}

bool ElementIdentique(ELEMENT e1, ELEMENT e2){
	/* retourne vrai si les deux arguments sont identiques */
	if(e1.typeElement == e2.typeElement){
		switch(e1.typeElement){
			case OPERATEUR:  return e1.e.op == e2.e.op;
			case PARENTHESE: return e1.e.pa == e2.e.pa;
			case NOMBRE:     return e1.e.nb == e2.e.nb;

			default:         return FAUX;
		}
	}
	return FAUX;
}

/* INUTILE Mais cohérent pour le stockage indirect */
ELEMENT ElementCreer(){
	ELEMENT e = {{(int) 0}, NOMBRE};
	return e;
}

void ElementDetruire(ELEMENT x){
	
}
