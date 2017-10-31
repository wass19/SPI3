#ifndef ARBRE_OP
#define ARBRE_OP

#include "ARBRE_prim.h"
#include    "eltprim.h"

// affiche en mode préfixe l'arbre
void ArbreAffichePref(ARBRE a);

// retourne l'arbre après avoir demandé son étiquette et ses fils
ARBRE ArbreLire();

// retourne le père du noeud dans l'arbre source
ARBRE ArbrePereNoeud(ARBRE noeud, ARBRE source);

// affiche l'arbre par niveau
void ArbreAfficherNiveau(ARBRE a);

// affiche les feuilles de l'arbre
void ArbreAfficherFeuilles(ARBRE a);

#endif
