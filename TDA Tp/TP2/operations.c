/*
 * auteur : LeNomDeLEtudiant
 * version 0.1 : Date : Sun Oct 01 18:42:00 CEST 2017
 *
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "operations.h"
#define MAX_OPERATEURS 6

bool TabOperateursInitialise = FAUX;
int priorites[MAX_OPERATEURS];

// Retourne la position dans le tableau des priorités l'operateur
int op2pos(char op){
	switch(op){
		case '+': return 0;
		case '-': return 1;
		case '*': return 2;
		case '/': return 3;
		case '(': return 4;
		
		return 5;
	}
	printf("op2pos: L'operateur est inconnu\n");
	return -1;
}

// Renvoie VRAI si x est un nombre
bool Nombre(ELEMENT x){
	return x.typeElement == NOMBRE;
}

// Renvoie VRAI si x est un opérateur
bool Operateur(ELEMENT x){
	return x.typeElement == OPERATEUR && x.e.op != OP_ERR;
}

// Renvoie VRAI si x est une parenthèse ouvrante
bool Ouvrante(ELEMENT x){
	return x.typeElement == PARENTHESE && x.e.pa == PA_OUV;
}

// Renvoie VRAI si x est une parenthèse fermante
bool Fermante(ELEMENT x){
	return x.typeElement == PARENTHESE && x.e.pa == PA_FER;
}

// Renvoie VRAI si x1 a une priorité supérieure ou égale à x2
bool Prioritaire(ELEMENT x1, ELEMENT x2){

	if(Ouvrante(x2))
		return VRAI;
	
	if(Operateur(x1) && Operateur(x2)){

		// Définition du tableau des prioritées :
		//  1 : OP_PLUS OP_MOINS
		//  2 : OP_MULT OP_DIV
		int priorites[4] = {1, 1, 2, 2};

		return priorites[x1.e.op] >= priorites[x2.e.op];
	}

	return FAUX;
}

// Retourne l'élement correspondant à xG op xD
ELEMENT Applique(ELEMENT op, ELEMENT xG, ELEMENT xD){
	if(Nombre(xG) && Nombre(xD) && Operateur(op)){
		
		switch(op.e.op){
			case OP_PLUS : return EntierToElement(xG.e.nb + xD.e.nb);
			case OP_MOINS: return EntierToElement(xG.e.nb - xD.e.nb);
			case OP_MULT : return EntierToElement(xG.e.nb * xD.e.nb);
			case OP_DIV  : return EntierToElement(xG.e.nb / xD.e.nb);

			default: break;
		}
		
	}
	printf("Applique: op n'est pas un opérateur OU xG ou xD ne sont pas des nombres\n");
	return ELEMENT_VIDE;
}

// Convertit l'entier en un élement
ELEMENT EntierToElement(int x){
	ELEMENT e = ElementCreer();

	e.e.nb = x;
	e.typeElement = NOMBRE;
	
	return e;
}

// Convertit l'element en un entier
int ElementToEntier(ELEMENT x){
	if(Nombre(x)){
		return x.e.nb;
	}
	printf("ElementToEntier: x n'est pas un nombre !\n");
	return 0;
}


char op2char2(Op o){
	switch(o){
		case OP_PLUS : return '+';
		case OP_MOINS: return '-';
		case OP_MULT : return '*';
		case OP_DIV  : return '/';

		default      : return '?';
	}
}

char pa2char2(Pa p){
	switch(p){
		case PA_OUV: return '(';
		case PA_FER: return ')';

		default    : return '?';
	}
}

// Convertit l'element en un caractère
char ElementToCar(ELEMENT x){
	if(Nombre(x)){
		printf("ElementToCar: L'element est un nombre, pas un caractère\n");
		return ' ';
	}
	else if(Operateur(x))
		return op2char2(x.e.op);
	else
		return pa2char2(x.e.pa);
	
}

// Renvoie vrai si x est un élement valide
bool ElementValide(char * x){
	int i;
	int len = strlen(x);

	// Operateur, parenthèse ou chiffre
	if(len == 1){
		return isdigit(x[0]) || x[0] == '(' || x[0] == ')' || x[0] == '+' || x[0] == '-'|| x[0] == '/'|| x[0] == '*';
	}

	// Nombre
	else if(len > 1){

		// Nombre négatif
		if(!isdigit(x[0]) && x[0] != '-')
			return FAUX;
		
		for(i = 1 ; i < len ; i++){
			if(!isdigit(x[i]))
				return FAUX;
		}

		return VRAI;
	}
	
	printf("ElementValide: L'element est vide\n");
	return FAUX;

}

