/*
 * auteur : LeNomDeLEtudiant
 * version 0.1 : Date : Wed Oct 04 15:09:38 CEST 2017
 *
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "interpreteur.h"

// Tableau qui stocke les noms de variables et leurs valeurs
Entree tabVariables[MAX_VARIABLES];
bool tabVariablesInitialise = FAUX;

// Convertit une expression infixe en expression postfixe
LISTE inf2Post(LISTE inf){

	LISTE L  = ListeCreer(); // Liste à renvoyer
	LISTE Lp = ListeCreer(); // Liste de travail //        => ListeDetruire a faire avant de quitter
	PILE   P = PileCreer(ListeNbElements(inf)); // o(i) // => PileDetruire a faire avant de quitter
	ELEMENT tmp, tmp2;

	POSITION posI   = ListePremier(inf);
	POSITION posA   = ListePremier(Lp);
	POSITION infMax = ListeSentinelle(inf); // o(i)

	while(infMax != posI){ // o(i)

		tmp = ListeAcceder(posI, inf);

		if(Ouvrante(tmp))
			PileEmpiler(tmp, P);
		else if(Nombre(tmp))
			ListeInserer(tmp, posA, Lp);
		else if(Fermante(tmp)){
			tmp2 = PileDepiler(P);

			while(!Ouvrante(tmp2)){ // o(P)
				ListeInserer(tmp2, posA, Lp);
				tmp2 = PileDepiler(P);
			}
		}
		else if(Operateur(tmp)){
			
			while(!PileVide(P) && Prioritaire(PileSommet(P), tmp)){ // o(P)
				tmp2 = PileDepiler(P);
				ListeInserer(tmp2, posA, Lp);
			}
			PileEmpiler(tmp, P);
		}

		posI = ListeSuivant(posI, inf);
	}

	while(!PileVide(P)){ // O(P)
		tmp2 = PileDepiler(P);
		ListeInserer(tmp2, posA, Lp);
	}

	// Au lieu d'insérér à la fin de la liste à chaque fois
	// j'insère au début, puis j'inverse toute la liste à la fin
	// car quand on insère à la fin d'une liste, en fonction de la réalisation du tda
	// il faut calculer la sentinelle à chaque fois
	ListeInverser(L, Lp); // O(2Lp)
	ListeDetruire(Lp);
	PileDetruire(P);
	
	return L;
	 
}

// Evalue une expression postfixée
// O(p + p) = O(2p) (si p = l'expression postfixée)
ELEMENT evaluationPost(LISTE postfix){
	
	POSITION max = ListeSentinelle(postfix); // o(p)
	POSITION cur = ListePremier(postfix);

	ELEMENT x, xG, xD; // => ElementDetruire à faire avant de quitter

	PILE p = PileCreer(ListeNbElements(postfix)); // => PileDetruire à faire avant de quitter

	while(cur != max){ // o(p)

		x = ListeAcceder(cur, postfix);

		if(Nombre(x))
			PileEmpiler(x, p);
		else if(Operateur(x)){
			xD = PileDepiler(p);
			xG = PileDepiler(p);

			PileEmpiler(Applique(x, xG, xD), p);
		}
		else {
			printf("evaluationPost: Cette expression n'est pas postfixée !\n");
		}
		
		cur = ListeSuivant(cur, postfix);
	}

	ElementDetruire(xG);
	ElementDetruire(xD);
	ElementDetruire(x);
	
	x = PileSommet(p);
	PileDetruire(p);
	return x;
	
}

// Affiche le prompt et enregistre la commande entrée dans le buffer
void prompt(char * buffer){

	int len;

	memset(buffer, '\0', sizeof(char) * MAX_BUFFER);
	
	printf("> ");

	fgets(buffer, MAX_BUFFER, stdin);

	// Replacement du \n par \0 à la fin de la commande
	len = strlen(buffer);
	if(buffer[len - 1] == '\n')
		buffer[len - 1] = '\0';

}

// Initialise le tableau des variables + ajoute l'entrée ANS
void initTabVariables(){
	int i;

	for(i = 1 ; i < MAX_VARIABLES ; i++){
		tabVariables[i].entreeLibre = VRAI;
	}

	strcpy(tabVariables[0].nom, "ANS");
	tabVariables[0].valeur = ELEMENT_VIDE;
	tabVariables[0].entreeLibre = FAUX;

	tabVariablesInitialise = VRAI;
}

// Retourne la position de la variable nomVariable si elle existe déjà ou retourne -1
int pTabVariables(char * nomVariable){
	int i;

	for(i = 0 ; i < MAX_VARIABLES ; i++){
		if(tabVariables[i].entreeLibre == FAUX && strcmp(tabVariables[i].nom, nomVariable) == 0)
			return i;
	}
	return -1;
}

// Ajoute la variable nomVariable au tableau des variables
// exit le programme si plus de place
// return la position de cette variable
int pNouvelleVariable(char * nomVariable){
	int i;

	for(i = 0 ; i < MAX_VARIABLES ; i++){
		if(tabVariables[i].entreeLibre == VRAI){
			strcpy(tabVariables[i].nom, nomVariable);
			return i;
		}
	}

	printf("pNouvelleVariable: Il n'y a plus de place dans le tableau des varialbes !\n");
	exit(1);
}

// Affiche tout le tableau des variables et leurs valeurs
void afficherTabVariables(){
	int i;

	for(i = 0 ; i < MAX_VARIABLES ; i++){
		if(tabVariables[i].entreeLibre == FAUX){
			printf("%s\t : ", tabVariables[i].nom);
			ElementAfficher(tabVariables[i].valeur);
			printf("\n");
		}
	}
}

// Interprete la commande
//  => Renvoie FAUX si l'utilisateur souhaite arreter l'interpreteur
bool interpreter(char * commande){

	// On initialise le tableau des variables si il n'a pas déjà été initialisé
	if(!tabVariablesInitialise){
		initTabVariables();
	}

	// On test les différentes commandes prédéfinies
	if(strcmp(commande, "exit") == 0){
		return FAUX;
	}
	else if(strcmp(commande, "list") == 0){
		afficherTabVariables();
		return VRAI;
	}
	else if(strcmp(commande, "help") == 0){
		printf("Commandes possibles : \n");

		printf(" - list : affiche toutes les variables en mémoire\n");
		printf(" - help : affiche cette interface d'aide\n");
		printf(" - exit : termine ce programme\n");
		
		return VRAI;
	}



	const int MAX = sizeof(char) * MAX_BUFFER;

	int r = 0;                 // resultats temporaire de certaines fonctions
	bool formeAvecEgal = FAUX; // se rapelle si la commande est de la forme ( a = b ) ou ( b )
	
	ELEMENT elt = ElementCreer();    // element temporaire       => ElementDetruire a faire avant de quitter
	LISTE   inf = ListeCreer();      // liste infixe de travail  => ListeDetruire a faire avant de quitter
	LISTE  post;                     // liste postfixe de calcul
	POSITION  p = ListePremier(inf); // position dans la liste de travail
	
	char * mot = NULL;           // permet de parcours tous les mots de la commande separés d'un espace
	char * gauche = malloc(MAX); // partie gauche de l'expression (avant le =) => free a faire avant de quitter
	char * droite = malloc(MAX); // partie droite de l'expression (après le =) => free a faire avant de quitter

	/*
	 * 
	 * REFORMATION DE TOUTES LES COMMANDES EN QUELQUE CHOSE DE LA FORME
	 * a = b
	 * (si juste b est donné, on met ANS = b)
	 * 
	 */

	// Test si la commande est de la forme qqchose = autrechose
	r = sscanf(commande, "%[^ \n] = %[^\n]", gauche, droite);

	// => a
	if(r == 1){
		strcpy(gauche, "ANS");
		strcpy(droite, commande);

		formeAvecEgal = FAUX;
	}
	// => a = b
	else if(r == 2){
		formeAvecEgal = VRAI;
	}
	else {
		printf("interpreter: Erreur, impossible de savoir si la commande est une expression. r = %i\n", r); 
		free(gauche);
		free(droite);
		ListeDetruire(inf);
		exit(1);
	}
		


	/*
	 * 
	 * PARCOURS DE LA PARTIE DROITE DE L'EXPRESSION
	 * 
	 * 
	 */

	// strtok permet de parcourir tous les mots de la partie droite qui sont séparés d'un espace

	mot = droite;
	mot = strtok(mot, " ");

	// On parcours tous les mots 1 à 1 qui sont séparés par des espaces
	while(mot != NULL){

		// On a rentré un élement valide (pas une variable)
		if(ElementValide(mot)){
			// On lit le mot dans l'élement
			ElementLireBuffer(&elt, mot);
		}
		// On a rentré un nom de variable
		else {

			// on recherche cette variable
			r = pTabVariables(mot);
			if(r == -1){
				printf("ERREUR: %s - symbole indéfini\n", mot);
				
				free(gauche);
				free(droite);
				ListeDetruire(inf);
				
				return VRAI;
			}
			ElementAffecter(&elt, tabVariables[r].valeur);
		}

		// On l'ajoute à notre liste
		ListeInserer(elt, p, inf);
		p = ListeSuivant(p, inf);

		// On passe au mot suivant
		mot = strtok(NULL, " ");
	}

	/*
	 * 
	 * ON TRAITE L'EXPRESSION
	 * 
	 */

	post = inf2Post(inf);       // => ListeDetruire a faire avant de quitter
	elt = evaluationPost(post);

	if(!formeAvecEgal){
		printf("= ");
		ElementAfficher(elt);
		printf("\n");
	}

	/*
	 * 
	 * ON ENREGISTRE LE RESULTAT
	 * 
	 */
	
	// Recherche si le nom gauche est déjà dans le tableau des variables
	r = pTabVariables(gauche);

	if(r == -1){
		// La variable n'est pas déjà presente
		r = pNouvelleVariable(gauche); // pNouvelleVariable exit si il n'y a plus de place
	}

	ElementAffecter(&(tabVariables[r].valeur), elt);
	tabVariables[r].entreeLibre = FAUX;


	// Libération de la mémoire, des listes et de l'element tmp

	free(gauche);
	free(droite);

	ListeDetruire(inf);
	ListeDetruire(post);
	ElementDetruire(elt);

	return VRAI;
}
