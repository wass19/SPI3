#ifndef INTERPRETEUR
#define INTERPRETEUR

#include "eltsdd.h"
#include "eltprim.h"
#include "operations.h"

#include  "lstprim.h"
#include "pileprim.h"

#include "lstop.h"


#define MAX_BUFFER 255
#define MAX_VARIABLES 20

// Entrée dans le tableau qui stocke les variables et leurs valeurs
typedef struct {
	char nom[MAX_BUFFER];
	ELEMENT valeur;
	bool entreeLibre;
} Entree;

// Convertit une expression infixe en expression postfixe
LISTE inf2Post(LISTE inf);

// Evalue une expression postfixée
// O(p + p) = O(2p) (si p = l'expression postfixée)
ELEMENT evaluationPost(LISTE postfix);

// Affiche le prompt et enregistre la commande entrée dans le buffer
void prompt(char * buffer);

// Interprete la commande
//  => Renvoie FAUX si l'utilisateur souhaite arreter l'interpreteur
bool interpreter(char * commande);

#endif
