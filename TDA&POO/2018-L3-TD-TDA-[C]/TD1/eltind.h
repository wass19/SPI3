#ifndef _ELTIND_H
#define _ELTIND_H


/*Declaration type ELEMENT qui est une structure composée de :
 * 	-prenom : chaine de caracteres
 * 	-nom : chaine de caracteres
 * 	-adresse : structure composée de :
 * 		+rue : chaine de caracteres
 * 		+ville : chaine de caracteres
 * 		code : int 	
 */
typedef struct{
	char *prenom,*nom;
	struct{
		char *rue;
		char *vile;
		long int code;
	} adresse;
}FICHE,*ELEMENT;

#endif
