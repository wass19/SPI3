#include <stdio.h>
#include <stdlib.h>


int entrerMessage(int TMSG,int nb_users,int res[nb_users][TMSG]); /* Entre le Message dans la Matrice res[][] */
int NbUtil();/* Demande le nombre d'utilisateur */
int TailleMsg();/* Demande la taille du message */
void Etallement(int hauteur, int largeur ,int msg[hauteur][largeur],int res[largeur]); /*Additions de tous les messages dans une seule matrice res[][]*/
void attribution(int TMSG, int users,int nb_users,int message[nb_users][TMSG], int h[users][users],int res[nb_users][TMSG*users]); /*Attribution des messages dans res[]*/
void Desetallement(int nb_users,int users, int TMSG,int etares[TMSG*users],int h[users][users]);/*Multiplication ligne afin de redonner le message originale*/
void hadamard(int nb_users, int h[nb_users][nb_users]);/*Création Matrice avec en parametre le nombre d'utilisateurs ainsi qu'une matrice initiale*/
int checkpussancede2(int n);/* Decallage de n jusqu'a la puissance la plus proche */
void afficher(int hauteur, int largeur ,int h[hauteur][largeur]);/*Affichage Matrice*/
void raz(int hauteur, int largeur ,int h[hauteur][largeur]);/*Reinitialisation Matrice a zero*/
