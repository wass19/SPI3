#ifndef ENSEMBLE_H
#define ENSEMBLE_H

// Définition du type ENSEMBLE : une liste
typedef LISTE ENSEMBLE;


// Retourne un ensemble vide
ENSEMBLE EnsembleCreer();

// Libère la mémoire allouée pour l'ensemble e
void EnsembleDetruire(ENSEMBLE e);

// Teste si l'élément x appartient à l'ensemble e
bool EnsembleAppartenir(ELEMENT x, ENSEMBLE e);

// Ajoute l'élément x dans l'ensemble e si il n'y est pas déjà
bool EnsembleAjouter(ELEMENT x, ENSEMBLE e);

// Supprime l'élément x de l'ensemble e
bool EnsembleSupprimer(ELEMENT x, ENSEMBLE e);

// Teste si l'ensemble e est vide
bool EnsembleVide(ENSEMBLE e);

// Retourne le nombre d'élements de l'ensemble e
int EnsembleCardinal(ENSEMBLE e);


#endif
