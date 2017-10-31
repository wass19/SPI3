#ifndef LSTOP
#define LSTOP

#include "lstsdd.h"
#include "eltsdd.h"

#include  "lstprim.h"
#include "pileprim.h"

// Compte le nombre d'élements de la liste l
int ListeNbElements(LISTE l);

// Affiche la liste L
void ListeAfficher(LISTE L);

// Renverse la liste src dans la liste dst
void ListeInverser(LISTE dst, LISTE src);

// Efface une liste de façon radicale (supprime les élements et les cellules et la liste)
void ListeBazooka(LISTE l);

#endif
