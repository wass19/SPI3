#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#include <msg_messages.h>

int 
main( int nb_arg , char * tab_arg[] )
{     
	char nomprog[128] ;
	int id_BAL;
	int i;
	message_t envoi;
	struct timeval debut,fin,temps;
	float duree, debut_transmission;


     /*-----*/

     if( nb_arg !=1 )
       {
	 fprintf( stderr , "%s - Emetteur dans la communication par paquet\n\n" , tab_arg[0] );
	 fprintf( stderr , "usage : %s \n" , tab_arg[0] );
	 exit(-1);
       }
     strcpy( nomprog , tab_arg[0] );

     /*=============================*/
     /*    |      A FAIRE     |     */
     /*====v==================v=====*/

	/*recuperation de l'identifiant de la BAL*/

	if((id_BAL = msgget(CLE_BAL,0666)) == -1){
		perror("Erreur dans la recuperation de l'identifiant de la Boite Aux Lettres \n\n");
		exit(-1);
	}

	/*remplissage du message a envoyer*/

	msg_remplir(&envoi,'b');

	printf("Debut de l'emission \n");

	/*recuperation du temps du début de l'emission*/
	if( (gettimeofday(&debut, NULL)) == -1){

		perror("Erreur lors de la recuperation du temps avant emission\n\n");
		exit(-1);
	}

	/*Boucle d envoi de messages au recepteur*/
int a = 0;
	if( (a=msgsnd(id_BAL, &envoi, sizeof(corps_t), 0)) == -1){
		printf("a = %i\n", a );
		perror(" Erreur lors de l envoi d'un message\n\n");
          	exit(-1);
        }
	
	printf("Fin de l emission\n");

	/*Envoi de la date de debut d'emission*/
	debut_transmission = debut.tv_sec + (debut.tv_usec * 1e-6);

	/*printf("debut_transmission -1- : %.3f \n",debut_transmission);*/
	sprintf(envoi.corps.buffer, "%f", debut_transmission);

	if( (msgsnd(id_BAL, &envoi, sizeof(corps_t), 0)) == -1){
		fprintf(stderr, "%s : Erreur lors de l envoi du message de date de transmission\n\n", nomprog);
		exit(-1);
     	}


     exit(0);
}
