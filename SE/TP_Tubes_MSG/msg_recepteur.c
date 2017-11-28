#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#ifdef _LINUX_
#include <string.h>
#else
#include <strings.h>
#endif

#include <msg_messages.h>


int id_BAL;

void hand_arret(int sig){
	msgctl(id_BAL, IPC_RMID,0);
	printf(" Destruction de la boite aux Lettres \n");
	exit(0);
}


int 
main( int nb_arg , char * tab_arg[] )
{     
	char nomprog[128] ;
	message_t recu;
	int i;
	struct timeval debut,fin,temps;
	float duree , duree_transmission, debut_transmission, fin_transmission;

     /*-----*/

     if( nb_arg !=1 )
       {
	 fprintf( stderr , "%s - Recepteur dans la communication par paquet\n\n" , tab_arg[0] );
	 fprintf( stderr , "usage : %s \n" , tab_arg[0] );
	 exit(-1);
       }
     strcpy( nomprog , tab_arg[0] );

     /*=============================*/
     /*    |      A FAIRE     |     */
     /*====v==================v=====*/

	/*Creation de la boite aux lettres*/

	if((id_BAL=msgget(CLE_BAL, IPC_CREAT | IPC_EXCL | 0666)) == -1){
		perror("Erreur lors de la creation de la Boite aux lettres \n");
		exit(-1);
	}

	printf("Debut de la recuption \n");

	/*Attente de la recuperation d'un message*/
	if((msgrcv(id_BAL,&recu,sizeof(corps_t),MSG_TYPE_RECEPTEUR,0))== -1){
		perror("Erreur lors de la reception d'un message \n\n");
		exit(-1);
	}
	msg_afficher(&recu);
	
	/*Recuperation du temps apres reception des messages*/

	if(gettimeofday(&fin,NULL) == -1){
		perror("Erreur lors de la recuperation du temps apres reception \n\n");
		exit(-1);
	}

	printf("Fin de la reception\n");
	
	/*reception de la date de debut d'emission*/
	if((msgrcv(id_BAL,&recu,sizeof(corps_t),MSG_TYPE_RECEPTEUR,0)) == -1){
		perror("Erreur lors de la reception d'un message \n\n");
		exit(-1);
	}

	
	/*Transformation du corps du message en duree*/
	debut_transmission = strtod(recu.corps.buffer, NULL);
	fin_transmission = (fin.tv_sec   + fin.tv_usec * 1e-6); 
	


	/*Calcul de la duree de transmission et affichage*/	
	duree_transmission = fin_transmission-debut_transmission;

	/*affichage du temps*/
	printf("debut_transmission : %.3f \n",debut_transmission);
	printf("fin_transmission  : %.3f \n",fin_transmission);
	printf("le temps total de la transmission : %.2f s \n",duree_transmission);

	/*Suppression de la boite aux lettres*/
	if( (msgctl(id_BAL, IPC_RMID, 0)) == -1){
		perror("Erreur lors de la suprression de la la Boite aux Lettres");
		exit(-1);
	}

	exit(0);

}
