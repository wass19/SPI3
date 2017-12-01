#include <stdlib.h>
#include <stdio.h>
#include "matrice.h"


void hadamard(int nb_users, int h[nb_users][nb_users]){/*Création Matrice avec en parametre le nombre d'utilisateurs ainsi qu'une matrice initiale*/
	h[0][0] = 1;
	int i,j;
	int puiss=1;
	while(puiss< nb_users){
		for(i=0; i<puiss ; i++){
			for(j=0;j<puiss; j++){
				h[i+puiss][j] = h[i][j];
				h[i][j+puiss] = h[i][j];
				h[i+puiss][j+puiss] = - h[i][j];
			}
		}
		puiss+= puiss;
	}
}

void afficher(int hauteur, int largeur ,int h[hauteur][largeur]){/*Affichage Matrice*/
    for(int i=0;i<hauteur;i++){
		if(largeur==2){
			printf(" ___  ___\n");
		}if(largeur==4){
			printf(" ___  ___  ___  ___ \n");
		}if(largeur==8){
			printf(" ___  ___  ___  ___  ___  ___  ___  ___ \n");
		}if(largeur==16){
			printf(" ___  ___  ___  ___  ___  ___  ___  ___  ___  ___  ___  ___  ___  ___  ___  ___ \n");
		}
        for(int j=0;j<largeur;j++){
            if(h[i][j]<0){
				printf("|%i |", h[i][j] );
			}else{
				printf("| %i |", h[i][j] );
			}
		}
		if(largeur==2){
			printf("\n|___||___|\n");
		}if(largeur==4){
			printf("\n|___||___||___||___| \n");
		}if(largeur==8){
			printf("\n|___||___||___||___||___||___||___||___|\n");
		}if(largeur==16){
			printf("\n|___||___||___||___||___||___||___||___||___||___||___||___||___||___||___||___|\n");
		}
    }
}

void raz(int hauteur, int largeur ,int h[hauteur][largeur]){/*Reinitialisation Matrice a zero*/
    for(int i=0;i<hauteur;i++){
        for(int j=0;j<largeur;j++){
             h[i][j] = 0;
        }    
    }
}