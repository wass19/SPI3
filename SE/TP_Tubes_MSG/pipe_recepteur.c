#include <stdio.h>
#include <unistd.h>	/* close, read, write */
#include <stdlib.h>	/* exit */
#include <sys/types.h>	/*open */
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#ifdef _LINUX_
#include <string.h>
#else
#include <strings.h>
#endif
#include <pipe_messages.h>

int
main( int nb_arg , char * tab_arg[])
{
     char nomprog[128] ;
     int fd_tube,fd_tube2,i;
     char msg[MESSAGES_TAILLE];
     char * NomTube = "tube";
     char * TubeTemps = "PipeTime";
     struct timeval debut, fin;
     float temps;


     /*-----*/
     strcpy( nomprog , tab_arg[0] );

     if( nb_arg != 1 )
     {
	  fprintf( stderr , "%s - Recepteur dans la communication par flot\n\n" , tab_arg[0] );
	  fprintf( stderr , "usage : %s \n" , nomprog );
	  exit(-1);
     }


     /*=============================*/
     /*           A FAIRE           */
     /*=============================*/

     /*ouverture du tube en lecture */

     if((fd_tube=open(NomTube, O_RDONLY ,0)) == -1){
       perror("Erreur dans l ouverture du tube en lecture\n\n");
       exit(-2);
     }

    /*lecture dans le tube de MESSAGES_NB messages de taille MESSAGES_TAILLE*/
    for(i = 0; i < MESSAGES_NB; i ++){
      if( (read(fd_tube, msg, MESSAGES_TAILLE)) == -1){
        perror("Erreur dans la lecture du tube \n");
        exit(-1);
      }/*Fin du if*/
     }/*Fin du for*/

     /*récupération du temps de fin de transmission */
     if( (gettimeofday(&fin, NULL)) == -1){
	perror("Erreur dans la recuperation du temps après l emission des msgs\n\n");
	exit(-1);
     }/*Fin du if*/

     /*fermeture du premier tube*/
     close(fd_tube);

     /*lecture dans le deuxième tube après ouverture, pour récuperer le temps du debut de l'emission */
     if((fd_tube2=open(TubeTemps, O_RDONLY ,0)) == -1){
       perror("Erreur dans l ouverture du tube en lecture\n\n");
       exit(-2);
     }
     if(read(fd_tube2,&debut,sizeof(debut)) == -1){
        perror( "erreur dans la lecture du tube ");
        exit(-1);
     }/*Fin du if*/

     /*lecture du message récuperer dans le tube*/
     pipe_afficher( msg );
     printf("fin de la lecture \n");

     /* la différence entre le temps du départ et le temps de la fin de l'emission pour trouver le temps total */

     temps =fin.tv_sec   + fin.tv_usec * 1e-6 - debut.tv_sec + debut.tv_usec * 1e-6;

     /*affichage du temps*/
     printf("temps d'emission total	: %.3f s \n",temps);
	

     /*fermeture du 2eme tube*/
     close(fd_tube2);
     exit( 0 );
}
