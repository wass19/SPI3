#ifndef ELTOPERATION
#define ELTOPERATION

/*
 * Pour sauvegarder un élément, j'ai choisi de le stocker dans un type union.
 * Ainsi, lorsqu'il s'agit d'un nombre (et pas simplement un chiffre) on a directement accès
 *  à celui-ci sans avoir besoin de le convertir si cela aurait été un char *.
 * En contre partie, il faut stocker un champ pour savoir pour chaque ELEMENT si celui-ci 
 *  est un nombre, opérateur ou parenthèse.
 */

// Type opérateur
typedef enum {OP_PLUS, OP_MOINS, OP_MULT, OP_DIV, OP_ERR} Op;

// Type parenthèse
typedef enum {PA_OUV, PA_FER, PA_ERR} Pa;

// Reconnaisance du type stocké dans l'union
typedef enum {OPERATEUR, PARENTHESE, NOMBRE} Type;

// Type élement : soit un opérateur, soit une parenthèse, soit un nombre
typedef union {
	Op op;  // Type : OPERATEUR
	Pa pa;  // Type : PARENTHESE
	int nb; // Type : NOMBRE
} Elt;

// Le type ELEMENT : l'element union + le champ de reconnaisance du type de l'element
typedef struct {
	Elt e;
	Type typeElement;
} ELEMENT;

#define ELEMENT_VIDE ElementCreer()


// Lit un élement depuis un buffer
// fonctionne exactement comme la fonction ElementLire
void ElementLireBuffer(ELEMENT * s, char * buffer);

#endif
