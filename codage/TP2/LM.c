
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TAILLE_MAX 200

 /*Calcul la valeur maximale de chaque vecteur qui va determiner le nombre de colonne de la matrice matLM*/
int MaxTab(int taille,int tab[taille]){
        int i=0;
        int max=tab[0];
        for(i=0;i<taille;i++){
                if(max<tab[i]){
                        max=tab[i];
                }
        }return max;
}

/* Affiche toute la matrice */
void Afficher(int L,int taille,int tab[L][taille]){
        int i=0,j=0;
        for(i=0;i<L;i++){
                for(j=0;j<taille;j++){
                        printf("%i",tab[i][j]);
                }printf("\n");
        }
}

/* Afficher le vecteur */
void AfficherTab(int taille,int tab[taille]){
        int i=0;
        for(i=0;i<taille;i++){
                printf("%i",tab[i]);
        }
}

/* Initialise toute la matrice */
void initMat(int max,int L,int matLM[L][max]){
        int i,j;
        for(i=0;i<L;i++){
                for(j=0;j<max;j++){
                        matLM[i][j]=1;
                }
        }
}

/* Effectue le décalade pour Gold */
void decalage(int taille,int max,int pos,int matLM[][max],int tab[taille]){
        matLM[pos][0]=1;
        int i=0,j;
        int res=matLM[pos-1][(tab[0])-1];
        for(i=1;i<taille;i++){
                if(res!=matLM[pos-1][(tab[i])-1]){
                        res=1;
                }else{
                        res=0;
                }
        }
        matLM[pos][0]=res;
        for(j=1;j<max;j++){
                        matLM[pos][j]=matLM[pos-1][j-1];
        }
}

/*Creation de la matrice LM*/
void MatriceLM(int max,int L,int taille,int tab[taille],int matLM[L][max]){
        int i,j;
        initMat(max,L,matLM);
        for(i=1;i<L;i++){
                decalage(taille,max,i,matLM,tab);
        }
}

 /*Attribution de la derniere colonne de la matrice matLM à un tableau res qui comporte le resultat */
void Attribution(int L, int max, int matLM[L][max],int res[L]){
        int i=0;
        printf("\n");
        for(i=0;i<L;i++){
                res[i]=matLM[i][max-1];
        }
}

/*Calcul premiere case de chaque ligne de la matrice matLM*/
void Xor(int L ,int msg[L],int res[L]){
				int i;
        for(i=0;i<L;i++){
                res[i]=res[i] ^ msg[i];
        }
}

/*Permet de calculer chaque case du tableau du code JPL */
void Xorcase(int L ,int L2,int msg[L],int res[L2],int tab[L]){

        int j=0,i=0,z;
        printf("Valeur 1er : %i \nValeur 2eme : %i \n",L2,L/L2);
        for(z=0;z<L-1;z++,i++){
                tab[z]=res[j] ^ msg[i];
                if(i==L2-1){
                        i=-1;
                        j++;
                }
        }
}

/* Fonction permettant de calculer le code Gold */
int Gold(int L,int max,int matLM[L][max]){
        int taille,nb_poly;
        printf(">>>>>Entrez le nombre de polynome:");
        scanf("%i",&nb_poly);
        printf("\n>>>>>Entrez le nombre de parametre:");
        scanf("%i",&taille);
        int tab[taille];
        int i=0,val=0,j=0;
        for(i=0;i<taille;i++){
								printf("---->Entrez le paramètre n° %i du polynome :\n",i);
                scanf("%i",&val);
                tab[i]=val;
        }
        max=MaxTab(taille,tab);
				printf("*****			max colonne: %i	*****\n",max);
        L=pow(2,max)-1;
        int res[L];
        int resf[L];
				printf("*****		max possibilite (nb ligne) : %i	*****\n",L);
        MatriceLM(max,L,taille,tab,matLM);
        Attribution(L,max,matLM,resf);
        Afficher(L,max,matLM);
        AfficherTab(L,resf);
        nb_poly--;
				printf("\n*****				RESTE POLYNOME : %i			****\n",nb_poly);
        while(nb_poly>0){
                printf(">>>>>Entrez le nombre d'etage:");
                scanf("%i",&taille);
                int i=0,val=0;
                for(i=0;i<taille;i++){
									printf("---->Entrez le paramètre n° %i du polynome :\n",i);
                        scanf("%i",&val);
                        tab[i]=val;
                }
                max=MaxTab(taille,tab);
								printf("*****			max colonne: %i	*****\n",max);
                L=pow(2,max)-1;
								printf("*****		max possibilite (nb ligne) : %i	*****\n",L);
                AfficherTab(L,resf);
                printf("\n");
                MatriceLM(max,L,taille,tab,matLM);
                Afficher(L,max,matLM);
                printf("\n");
                Attribution(L,max,matLM,res);
                nb_poly--;
                printf("\n*****				RESTE POLYNOME : %i			****\n",nb_poly);
                printf("\n-->TAB 1:	");
                AfficherTab(L,resf);
                printf("\n-->NVX 2:	");
                AfficherTab(L,res);
                Xor(L,res,resf);
                printf("\n");
        }printf("==>Résultat final :	");
        AfficherTab(L,resf);
        printf("\n");
}

 /*Retourne 1 si val2 est un nombre premier de val1 si non retourne 0*/
int premier(int val1, int val2){
    if(val1%val2==0){
                return 0;
    }else{
                return 1;
        }
}

/*Copie du tableau tab dans le tableau tab2 */
int copietab(int L,int tab[L],int tab2[L]){
        int i=0;
        for(i=0;i<L-1;i++){
                tab2[i]=tab[i];
        }
}

/* Fonction permettant de calculer le code JPL */
int JPL(int L,int max,int matLM[L][max]){
        int taille,nb_poly;
				printf(">>>>>Entrez le nombre de polynome:");
        scanf("%i",&nb_poly);
        taille=2;
        int tab[taille];
        int i=0,val=0,j=0;
        for(i=0;i<taille;i++){
								printf("---->Entrez le paramètre n° %i du polynome :\n",i);
                scanf("%i",&val);
                tab[i]=val;
        }
        max=MaxTab(taille,tab);
				printf("*****			max colonne: %i	*****\n",max);
        L=pow(2,max)-1;
        int res[L];
        int resf[2000];
        int tabfinal[2000];
        int tabmax[nb_poly];
				printf("*****		max possibilite (nb ligne) : %i	*****\n",L);
        MatriceLM(max,L,taille,tab,matLM);
        Attribution(L,max,matLM,resf);
        Afficher(L,max,matLM);
        nb_poly--;
				printf("\n*****				RESTE POLYNOME : %i			****\n",nb_poly);
        tabmax[0]=max;
        int max2,L2;
        int m=0;
        int valid=0;
        int cmpt=0;
        while(nb_poly>0){
                int i=0,val=0;
                if(cmpt!=0){
                        copietab(L,tabfinal,resf);
                }
                valid=0;
                while(valid==0){
                        for(i=0;i<taille;i++){
																printf("---->Entrez le paramètre n° %i du polynome :\n",i);
                                scanf("%i",&val);
                                tab[i]=val;
                        }
                        max2=MaxTab(taille,tab);
                        for(m=0;m<nb_poly;m++){
                                if(premier(tabmax[m],max2)==0){
                                        valid=0;
                                        printf("/!\\/!\\/!\\Ressaisir un etage premier par rapport aux anciens polynomes\n");
                                }else{
                                        valid=1;
                                }
                        }
                }
								printf("*****			max colonne: %i	*****\n",max);
                L2=pow(2,max2)-1;
								printf("*****		max possibilite (nb ligne) : %i	*****\n",L);
                printf("\n");
                MatriceLM(max2,L2,taille,tab,matLM);
                Afficher(L2,max2,matLM);
                printf("\n");
                Attribution(L2,max2,matLM,res);
                nb_poly--;
								printf("\n****				RESTE POLYNOME : %i				****\n",nb_poly);
                printf("\n-->TAB 1:	");
                AfficherTab(L,resf);
                printf("\n-->NVX 2:	");
                AfficherTab(L2,res);
                L=L*L2;
                printf("\n****	nombre de case de Tabfinal: %i	**** \n",L);
                Xorcase(L,L2,res,resf,tabfinal);
                printf("\n");
                printf("====>	Résultat final du 'tabfinal' :	");
                AfficherTab(L,tabfinal);
                printf("\n");
                cmpt++;
        }
}
void main(){
        int taille,nb_poly,L=TAILLE_MAX,max=TAILLE_MAX;
        int tab[max];
        int matLM[L][max];
        int choix;
        int i=0,val=0,j=0;
				printf(" _______________________________\n");
        printf("|   Choisir le codage voulu :   |\n|             1-Gold            |\n|             2-JPL             |\n");
				printf("|_______________________________|\n");
        scanf("%i",&choix);
				switch(choix){
					case  1: Gold(L,max,matLM); break;
					case  2: JPL(L,max,matLM);  break;
				}

}
