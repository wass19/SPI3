/*****************************************************************
*		Fichier :  	ELTCAR.H
*		Format :	Source C 
*		Version  : 	24/9/96
*		Programmeurs :	Delozanne
*		Contenu :      	Déclaration de la structure de données adoptée
*				pour une réalisation par des caractères du TDA ELEMENT.
*				
******************************************************************/

#ifndef _ELTCAR_H                   /* pour l'inclusion conditionnelle */
#define  _ELTCAR_H

/* Déclaration d'un type concret ELEMENT
- un élément est dans ce fichier de type int ; en effet un caractère en C est un entier par convention l'élément vide est 32767;
 le stockage est direct*/

/* plus généralement pour un stockage direct un élément de type simple ou "pas trop gros"
par exemple : un nombre complexe, un point */

typedef int ELEMENT;

#define ELEMENT_VIDE '*'


#endif


