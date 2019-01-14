/*
 * auteur : LeNomDeLEtudiant
 * version 0.1 : Date : Tue Oct 02 17:59:43 CEST 2018
 *
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "predicat.h"

int Nombre(ELEMENT x){
	if(isdigit(x)){
		return 1;
	}return 0;
}

int Operateur(ELEMENT x){
	if((x=='+') ||(x=='-') ||(x=='*') ||(x=='/') ){
		return 1;
	}return 0;
}

int Ouvrante(ELEMENT x){
	if((x=='(') ){
		return 1;
	}return 0;
}

int Fermante(ELEMENT x){
	if((x==')')){
		return 1;
	}return 0;
}

int Prioritaire(ELEMENT x1,ELEMENT x2){
	if((x1=='*') ||(x1=='/') ){
		return 1;
	}return 0;
}

ELEMENT Applique(ELEMENT op,ELEMENT xg, ELEMENT xd){
	if(op='+'){
		return xg+xd;
	}else if(op='-'){
		return xg-xd;
	}else if(op='*'){
		return xg*xd;
	}else if(op='/'){
		return xg-xd;
	}else{
		return -1;
	}
}

int ElementToEntier(ELEMENT x){
	return x-0;
}

char ElementToCar(ELEMENT x){
	char c=x+'0';
	return c;
}

ELEMENT EntierToElement(int x){
	ELEMENT i=x+'0';
	return i;
}
