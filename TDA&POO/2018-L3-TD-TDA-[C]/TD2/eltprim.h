/*****************************************************************
*  Fichier :  	ELTPRIM.H
*		Format :	Source C 
*		Version  : 	19/9/96
*		Programmeurs :	Delozanne, Jacoboni , Futtersack
*		Contenu :      	Déclaration des primitives du TDA ELEMENT.
******************************************************************/
#ifndef _ELTPRIM_H                   /* pour l'inclusion conditionnelle */
#define  _ELTPRIM_H

/*  inclusion de la déclaration du type concret ELEMENT */
    #include "eltsdd.h"

/*  Déclaration du type auxiliaire bool */
    typedef enum {FAUX, VRAI} bool ;

/* Déclaration des primitives du TDA ELEMENT */
    void ElementLire(ELEMENT *);
    void ElementAfficher(ELEMENT);

/* affecte le deuxieme argument dans le premier
qui est donc modifié et passé par adresse */
    ELEMENT ElementAffecter(ELEMENT*, ELEMENT);

/* retourne vrai si les deux arguments sont identiques */
    bool ElementIdentique(ELEMENT, ELEMENT);

/* retourne l'élément vide (et l'alloue en stockage indirect */
/* pour le stockage indirect */
    ELEMENT ElementCreer(void) ;

/* en stockage indirect libére la mémoire dynamique adressée par le paramètre
/* en stockage direct ne fait rien */
    void ElementDetruire (ELEMENT);

#endif
