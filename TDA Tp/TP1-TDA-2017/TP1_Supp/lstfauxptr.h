#ifndef LSTFAUXPTR
#define LSTFAUXPTR

	#include "eltprim.h"
	
	#define MAX_ENTRY 100
	
	typedef int LISTE;
	typedef int POSITION;
	
	typedef struct {
		ELEMENT element;
		int suivant;
	} Entry;
	

#endif
