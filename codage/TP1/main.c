#include <stdlib.h>
#include <stdio.h>
#include "matrice.h"

int checkpussancede2(int n){/* Decallage de n jusqu'a la puissance la plus proche */
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}

int NbUtil(){ /* Demande le nombre d'utilisateur */
	int users;
	printf("Entrer le nombre d'utilisateur : ");
	scanf("%i",&users);
	return users;
}

int TailleMsg(){ /* Demande la taille du message */
	int taille;
	printf("Entrer la taille de vos messages: ");
	scanf("%i",&taille);
	return taille;
}

int entrerMessage(int TMSG,int nb_users,int res[nb_users][TMSG]){/* Entre le Message dans la Matrice res[][] */
    int i=0;
    int j=0;
    while (i<nb_users){
            printf("\nUtilisateur N°%i :\n",i+1);
        while (j<TMSG)
        {
            printf("----->Bit N° %i :",j+1);
            scanf("%i",&res[i][j]);
            while ( getchar() != '\n');
             j++;
        }
        j=0;
        i++;
    }
}

void Etallement(int hauteur, int largeur ,int msg[hauteur][largeur],int res[largeur]){ /*Additions de tous les messages dans une seule matrice res[][]*/
	for(int i=0;i<hauteur;i++){
		for(int j=0;j<largeur;j++){
			 res[j]=res[j] + msg[i][j];
		}    
	}
}

void attribution(int TMSG, int users,int nb_users,int message[nb_users][TMSG], int h[users][users],int res[nb_users][TMSG*users]){/*Attribution des messages dans res[]*/
	int x,i,j,w,z=0;
	for(i=0;i<nb_users;i++){
		printf("M%i : |",i+1);        
		for(j=0;j<TMSG;j++){
			if(message[i][j]==0){
				for(w=0;w<users;w++){
					printf("%i ",-h[i][w]);
					res[i][z]=-h[i][w];
					z++;
				}
			}
			else if(message[i][j]==1){
				for(w=0;w<users;w++){
					printf(" %i ",h[i][w]);
					res[i][z]=h[i][w];
					z++;
				}
			}
		}
	 printf("|\n");
	z=0;
	}
}
    
 void Desetallement(int nb_users,int users, int TMSG,int etares[TMSG*users],int h[users][users]){/*Multiplication ligne afin de redonner le message originale*/
	int x=0,i,j,w,z=0;
	int tmp[nb_users][TMSG*users];
	for(i=0;i<nb_users;i++){     
		for(j=0;j<TMSG;j++){
				for(w=0;w<users;w++){
					tmp[i][z]=etares[z]*h[i][w];
					z++;
				}
		}
		z=0;
	}
	for(i=0;i<nb_users;i++){
		printf("M%i : |",i+1);        
		for(j=0;j<TMSG;j++){
				for(w=0;w<users;w++){
					x=x+tmp[i][z];
					z++;
				}
		printf("%i",x/4);
		x=0;
		}
		printf("|\n");
		z=0;
	}
}


void main(){
    int nb_users = NbUtil();
    int TMSG = TailleMsg();
    int users = checkpussancede2(nb_users);
    int messageres[nb_users][TMSG];
    int i;
    int msg1[nb_users][TMSG*users];
    int etares[TMSG*users];
    int h[users][users];
    raz(nb_users,TMSG*users,msg1);    
    raz(1,TMSG*users,etares);    
    printf("------------------- Matrice Hadamard ------------------- \n");
	hadamard(users,h);
    afficher(users,users,h);
    printf("------------------- Fin Matrice Hadamard -------------------\n\n\n");
    printf("--------------------   Messages	 ---------------------");
    entrerMessage(TMSG,nb_users,messageres);
    printf("\n");
    afficher(nb_users,TMSG,messageres);
    printf("-------------------  Fin Messages   -------------------\n\n\n");
    printf("------------------- Messages Codes -------------------\n");
    attribution(TMSG,users,nb_users,messageres,h,msg1);
    Etallement(nb_users,TMSG*users,msg1,etares);
    printf("-------------------  Fin Messages Codes  -------------------\n\n\n");
    printf("-------------------   Resultat   -------------------\n");
    afficher(1,TMSG*users,etares);
    printf("-------------------  Desetallement  -------------------\n");
    Desetallement(nb_users,users,TMSG,etares,h);
    printf("\n-----------------  Fin Desetallement  -----------------\n");
	printf("-----------------  FIN PROGRAMME  -----------------\n");
}
