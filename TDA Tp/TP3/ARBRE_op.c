/*
 * auteur : LeNomDeLEtudiant
 * version 0.1 : Date : Sun Oct 15 15:46:12 CEST 2017
 *
*/
#include <stdlib.h>
#include <stdio.h>

#include "ARBRE_op.h"
#include "File_Prim.h"

// affiche en mode préfixe l'arbre
void ArbreAffichePref(ARBRE a){

	ARBRE fils;
	
	ElementAfficher(Etiquette(a));

	if(!EstFeuille(a)){
		ARBRE fils = PremierFils(a);
		do {
			ArbreAffichePref(fils);
			fils = FilsSuivant(fils, a);
		} while(!DernierFils(fils, a));
	}
}

// retourne l'arbre après avoir demandé son étiquette et ses fils
ARBRE ArbreLire(){
	int nbFils;
	int i;
	ELEMENT etiquette = ElementCreer();
	ARBRE   a;
	FRERES  f = FreresCreer();

	printf("Veuillez indiquer l'étiquette : ");
	ElementLire(&etiquette);

	printf(" => Combien de fils possède ce noeud ? ");
	scanf("%i", &nbFils);

	for(i = 0 ; i < nbFils ; i++){
		printf("Lecture du fils n° %i :\n", i);
		a = ArbreLire();
		FreresAjouter(f, a);
	}

	a = ArbreConstruire(etiquette, f);
	ElementDetruire(etiquette);
	return a;
}


// retourne le père du noeud dans l'arbre source
ARBRE ArbrePereNoeud(ARBRE noeud, ARBRE source){
	
	ARBRE fils, rslt;
	
	if(noeud == source){
		printf("ArbrePereNoeud: le noeud est la racine !\n");
		return source;
	}

	if(!EstFeuille(source)){
		ARBRE fils = PremierFils(source);
		do {
			if(fils == noeud)
				return source;
				
			rslt = ArbrePereNoeud(noeud, fils);
			if(rslt != noeud)
				return rslt;
			
			fils = FilsSuivant(fils, source);
		} while(!DernierFils(fils, source));
	}

	return noeud;
}


// affiche l'arbre par niveau
void ArbreAfficherNiveau(ARBRE a){
	// how?
	FFILE f = FileCreer(0);
	ARBRE fils, tmp;
	FileEntrer(a, f);

	while(!FileVide(f)){
		tmp = FileSortir(f);
		ElementAfficher(Etiquette(tmp));

		fils = PremierFils(tmp);
		do {
			FileEntrer(fils, f);
			fils = FilsSuivant(fils, tmp);
		} while(!DernierFils(fils, tmp));
	
	}

	FileDetruire(f);
}

// affiche les feuilles de l'arbre
void ArbreAfficherFeuilles(ARBRE a){
	ARBRE fils;

	if(!EstFeuille(a)){
		ARBRE fils = PremierFils(a);
		do {
			ArbreAfficherFeuilles(fils);
			fils = FilsSuivant(fils, a);
		} while(!DernierFils(fils, a));
	}
	else {
		ElementAfficher(Etiquette(a));
	}
}
