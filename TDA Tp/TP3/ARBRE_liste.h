#ifndef ARBILIST
#define ARBILIST

#include "eltprim.h"

#define PAS_DE_FILS  NULL
#define PAS_DE_FRERE NULL

typedef struct cell{
	struct arb  * fils;
	struct cell * suivant;
}cell, * FRERES;

typedef struct arb {
	ELEMENT etiquette;
	FRERES  listeDesFils;
}arb, * ARBRE;

#endif
