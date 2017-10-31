#ifndef OPERATIONS
#define OPERATIONS

#include "eltsdd.h"
#include "eltprim.h"

// Renvoie VRAI si x est un nombre
bool Nombre(ELEMENT x);

// Renvoie VRAI si x est un opérateur
bool Operateur(ELEMENT x);

// Renvoie VRAI si x est une parenthèse ouvrante
bool Ouvrante(ELEMENT x);

// Renvoie VRAI si x est une parenthèse fermante
bool Fermante(ELEMENT x);

// Renvoie VRAI si x1 a une priorité supérieure ou égale à x2
bool Prioritaire(ELEMENT x1, ELEMENT x2);

// Retourne l'élement correspondant à xG op xD
ELEMENT Applique(ELEMENT op, ELEMENT xG, ELEMENT xD);

// Convertit l'entier en un élement
ELEMENT EntierToElement(int x);

// Convertit l'element en un entier
int  ElementToEntier(ELEMENT x);

// Convertit l'element en un caractère
char ElementToCar(ELEMENT x);

// Renvoie vrai si x est un élement valide
bool ElementValide(char * x);

#endif
