#ifndef FILPTRCI
#define FILPTRCI

#include "ARBRE_prim.h"

typedef struct file {
	ARBRE data;
	struct file * suivant;
} file;

typedef file * FFILE;


#endif