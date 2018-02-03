/*
 * auteur : PELLOIN Valentin
 * version 0.1 : Date : Wed Sep 27 13:25:21 CEST 2017
 *
*/
#include <stdlib.h>
#include <stdio.h>

#include "lstprim.h"
#include "lstfauxptr.h"

#define DEBUG 0 // active ou non le mode debug

#define NON_INITIALISEE -1 // Permet de savoir si la liste a été initialisée

// Dans la case suivant de la ligne 0, nous enregistrons la position de la première case libre
// Ensuite, chaque case libre contient une autre libre dans son champ suivant, ou 0
Entry MEMOIRE[MAX_ENTRY + 1] = {ELEMENT_VIDE, NON_INITIALISEE};


// Affiche la mémoire (debug)
void AfficherMemoire(char * info){
	int i;

	printf("%s\n", info);

	for(i = 0 ; i < MAX_ENTRY + 1 ; i++){
		printf("%02d - ", i);
		ElementAfficher(MEMOIRE[i].element);
		printf("- %02d\n", MEMOIRE[i].suivant);
	}
	printf("\n");
}

// Trouve la premiere case vide de la mémoire et ne l'indique plus comme vide
// Renvoie 0 si la mémoire est pleine
LISTE TrouverCaseVide(){

	// La position de la première case vide est stockée dans la ligne 0
	LISTE t = MEMOIRE[0].suivant;

	if(t == 0){
		printf("ERREUR: La mémoire est pleine !\n");
		exit(0);
	}

	// On refait les liens pour avoir la case vide d'après
	MEMOIRE[0].suivant = MEMOIRE[t].suivant;
	MEMOIRE[t].suivant = 0;

	#if DEBUG
		AfficherMemoire("Nouvelle case demandée :"); 
	#endif

	return t;
}

// Initialise la liste en mettant toutes les cases à vide et les chainent entre elles
void InitialiserListe(){
	int i;

	for(i = 0 ; i < MAX_ENTRY + 1 ; i++){
		ElementAffecter(&(MEMOIRE[i].element), ELEMENT_VIDE);
		MEMOIRE[i].suivant = i + 1;
	}

	MEMOIRE[i - 1].suivant = 0;

	#if DEBUG
		AfficherMemoire("Liste initialisée :"); 
	#endif
}

// Retourne vrai si la position est valide
bool PositionValide(LISTE L){
	bool rslt = L >= 0 && L <= MAX_ENTRY;

	if(!rslt)
		printf("ERREUR: position %i non valide", L);
	return rslt;
}

LISTE ListeCreer(void){
	// Vérifie que notre mémoire a été initialisée
	if(MEMOIRE[0].suivant == NON_INITIALISEE)
		InitialiserListe();
	
	return TrouverCaseVide();
}

bool ListeVide(LISTE L){
	return PositionValide(L) && MEMOIRE[L].suivant == 0;
}	
	
POSITION ListeSentinelle(LISTE L){
	if(PositionValide(L)){
		POSITION p = L;
		// Parcours la liste jusqu'a la sentinelle
		while(MEMOIRE[p].suivant != 0)
			p = MEMOIRE[p].suivant;
		return p;
	}
	return 0;
}

POSITION ListePremier(LISTE L){
	if(PositionValide(L))
		return L;
	return 0;
}

POSITION ListeSuivant(POSITION p, LISTE L){
	if(PositionValide(p))
		return MEMOIRE[p].suivant;
	return 0;
}

bool ListeInserer(ELEMENT x, POSITION p, LISTE L){
	if(PositionValide(p)){
		
		POSITION n = TrouverCaseVide();

		// Une fois la nouvelle case trouvée, il suffit de refaire les liens
		POSITION precedent = MEMOIRE[p].suivant;
		MEMOIRE[p].suivant = n;
		MEMOIRE[n].suivant = precedent;

		ElementAffecter(&(MEMOIRE[n].element), x);

		#if DEBUG
			AfficherMemoire("Element inséré dans la liste :"); 
		#endif

		return VRAI;
	}
	return FAUX;
}

bool ListeSupprimer(POSITION p, LISTE L){
	if(PositionValide(p)){

		// On détruit l'élément
		ElementDetruire(MEMOIRE[MEMOIRE[p].suivant].element);

		// On refait les liens
		POSITION tmp = MEMOIRE[p].suivant;
		MEMOIRE[p].suivant = MEMOIRE[tmp].suivant;

		// On ajoute notre case à la liste des cellules libres
		MEMOIRE[tmp].suivant = MEMOIRE[0].suivant;
		MEMOIRE[0].suivant   = tmp;

		#if DEBUG
			AfficherMemoire("Element supprimé de la liste :"); 
		#endif

		return VRAI;
	}

	return FAUX;
}

ELEMENT ListeAcceder(POSITION p, LISTE L){
	if(PositionValide(p) && !ListeVide(L)){
		return MEMOIRE[MEMOIRE[p].suivant].element;
	}
	return ELEMENT_VIDE;
}

void ListeDetruire(LISTE L){
	POSITION p;

	if(PositionValide(L)){

		// On supprime tous les élements de la liste
		while(!ListeVide(L)){
			p = ListePremier(L);
			ListeSupprimer(p, L);
		}

		// On défait le lien de l'entête pour ne pas avoir de perte
		MEMOIRE[L].suivant = MEMOIRE[0].suivant;
		MEMOIRE[0].suivant = L;

		#if DEBUG
			AfficherMemoire("Liste détruite :"); 
		#endif

	}
}

