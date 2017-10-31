/*
 * auteur : LeNomDeLEtudiant
 * version 0.1 : Date : Wed Oct 11 16:55:53 CEST 2017
 *
*/
#include <stdlib.h>
#include <stdio.h>

#include "ARBRE_prim.h"


//
// primitives de construction et destruction
//

// Créé une liste de frères vide
FRERES FreresCreer(){
	FRERES f = malloc(sizeof(cell));

	if(f == NULL){
		printf("FreresCreer: malloc a renvoyé NULL\n");
		exit(0);
	}

	f->fils    = PAS_DE_FILS;
	f->suivant = PAS_DE_FRERE;

	return f;
}

// Ajoute un frère à la liste des frères
void FreresAjouter(FRERES f, ARBRE a){

	FRERES tmp = f;
	FRERES nouveau = FreresCreer();
	nouveau->fils = a;

	// On ajoute à la fin notre nouveau frère
	while(tmp->suivant != NULL)
		tmp = tmp->suivant;

	tmp->suivant = nouveau;
	
}

// retourne un arbre dont la racine a pour etiquette e et les fils sont dans la liste l
ARBRE ArbreConstruire(ELEMENT e, FRERES L){
	
	ARBRE ab = malloc(sizeof(arb));
	
	if(ab == NULL){
		printf("ArbreConstruire: malloc a renvoyé NULL\n");
		exit(0);
	}

	ab->etiquette = ElementCreer();
	ElementAffecter(&(ab->etiquette), e);
	ab->listeDesFils = L;

	return ab;
}

// Libère une liste et ses sous arbres
void FreresDetruire(FRERES l){
	if(l != NULL){
		if(l->suivant != NULL)
			FreresDetruire(l->suivant);

		ArbreDetruire(l->fils);
		free(l);
	}
}

// libére la mémoire allouée pour l'arbre A
void ArbreDetruire(ARBRE a){
	if(a != NULL){
		if(a->listeDesFils != NULL)
			FreresDetruire(a->listeDesFils);

		ElementDetruire(a->etiquette);
		free(a);
	}
}



//
// primitives de consultation
//

// retourne le premier fils de A si A n'est pas une feuille
ARBRE PremierFils(ARBRE A){
	if(A != NULL){
		if(A->listeDesFils == PAS_DE_FILS){
			printf("PremierFils: L'arbre n'a pas de fils !\n");
			return PAS_DE_FILS;
		}
		else {
			return A->listeDesFils->suivant->fils;
		}
	}
	printf("PremierFils: L'arbre est vide !\n");
	return PAS_DE_FILS;
}

// retourne le fils de A suivant de F si F n'est pas le dernier
ARBRE FilsSuivant(ARBRE F, ARBRE A){
	if(A != NULL && F != NULL){
		if(A->listeDesFils == PAS_DE_FILS){
			printf("FilsSuivant: L'arbre A n'a pas de fils !\n");
			return PAS_DE_FILS;
		}
		
		FRERES tmp = A->listeDesFils->suivant;

		while(tmp->suivant != PAS_DE_FRERE && tmp->fils != F)
			tmp = tmp->suivant;

		if(tmp->fils == F && tmp->suivant != PAS_DE_FRERE){
			return tmp->suivant->fils;
		}

		//printf("FilsSuivant: Je n'ai pas trouvé le frère suivant de F dans A\n");
		return PAS_DE_FILS;
	}
	printf("FilsSuivant: ARBRE VIDE !!!!\n");
	return PAS_DE_FILS;
}

// retourne l'étiquette de A
ELEMENT Etiquette(ARBRE A){
	if(A != NULL)
		return A->etiquette;
	printf("Etiquette: L'arbre est vide !\n");
	return ELEMENT_VIDE;
}



//
// primitives de test
//

// retourne vrai si A est une feuille (liste des fils est vide)
bool EstFeuille(ARBRE A){
	return A == NULL || A->listeDesFils == PAS_DE_FILS;
}

// retourne vrai si F est le dernier fils de A
bool DernierFils(ARBRE F, ARBRE A){
	if(A != NULL && F != NULL){
		if(A->listeDesFils == PAS_DE_FILS){
			//printf("DernierFils: L'arbre A n'a pas de fils !\n");
			return VRAI;
		}
		
		FRERES tmp = A->listeDesFils->suivant;

		while(tmp->suivant != PAS_DE_FRERE && tmp->fils != F)
			tmp = tmp->suivant;

		if(tmp->fils == F && tmp->suivant != PAS_DE_FRERE){
			return FAUX;
		}

		return FAUX;
	}
	//printf("DernierFils: ARBRE VIDE !!!!\n");
	return VRAI;
}

// Affiche un espace horizontal tab fois (utile pour affiche un arbre)
void afficherTab(int tab){
	int i;

	for(i = 0 ; i < tab ; i++)
		printf("  ");
}

void ArbreAfficherTab(ARBRE a, int tab);

// Affiche les arbres des frères donnés
void FreresAfficher(FRERES f, int tab){
	if(f != NULL){
		ArbreAfficherTab(f->fils, tab + 1);
		FreresAfficher(f->suivant, tab);
	}
}

// Affiche un arbre
void ArbreAfficherTab(ARBRE a, int tab){
	if(a != NULL){
		afficherTab(tab);
		ElementAfficher(a->etiquette);
		printf("\n");
		FreresAfficher(a->listeDesFils, tab + 1);
	}
}

// Affiche l'arbre A
void ArbreAfficher(ARBRE a){
	ArbreAfficherTab(a, 0);
}

