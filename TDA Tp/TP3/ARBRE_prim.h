#ifndef ARBRE_PRIM
#define ARBRE_PRIM

#include "ARBRE_sdd.h"
#include "eltprim.h"

//
// Frères
//
// Créé une liste de frères vide
FRERES FreresCreer();
// Ajoute un frère à la liste des frères
void FreresAjouter(FRERES f, ARBRE a);

//
// primitives de construction et destruction
//

// retourne un arbre dont la racine a pour etiquette e et les fils sont dans la liste l
ARBRE ArbreConstruire(ELEMENT e, FRERES L);

// libére la mémoire allouée pour l'arbre A
void ArbreDetruire(ARBRE A);



//
// primitives de consultation
//

// retourne le premier fils de A si A n'est pas une feuille
ARBRE PremierFils(ARBRE A);

// retourne le fils de A suivant de F si F n'est pas le dernier
ARBRE FilsSuivant(ARBRE F, ARBRE A);

// retourne l'étiquette de A
ELEMENT Etiquette(ARBRE A);



//
// primitives de test
//

// retourne vrai si A est une feuille (liste des fils est vide)
bool EstFeuille(ARBRE A);

// retourne vrai si F est le dernier fils de A
bool DernierFils(ARBRE F, ARBRE A);


// Affiche l'arbre A
void ArbreAfficher(ARBRE a);

#endif
