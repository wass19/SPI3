#include <stdio.h>
#include <stdlib.h>	/* exit */
#include <sys/stat.h>	/* mknod */
#include <sys/types.h>	/* open */
#include <fcntl.h>
#include <unistd.h>	/* close , write */
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
     
     struct timeval debut;


     /*----------*/

     strcpy( nomprog , tab_arg[0] );

     if( nb_arg != 1 )
     {
	  fprintf( stderr , "%s - Emetteur dans la communication par flot\n\n" , nomprog );
	  fprintf( stderr , "usage : %s \n" , nomprog );
	  exit(-1);
     }


     /*=============================*/
     /*     |     A FAIRE     |     */
     /*=====v=================v=====*/
     
     if(mknod(NomTube , S_IFIFO | 0666 , 0)){
       perror("Pb sur creation du tube nomme\n");
       exit(-2);
     }
     if(mknod(TubeTemps , S_IFIFO | 0666 , 0)){
       perror("Pb sur creation du tube nomme\n");
       exit(-2);
     }
     /* ouverture du tube en écriture */
     if((fd_tube=open(NomTube,O_WRONLY,S_IWUSR)) == -1){
       perror("Erreur dans l ouverture du tube en ecriture\n\n");
       exit(-2);
     }

     pipe_remplir(msg , 'a' );
     pipe_afficher(msg);
     printf("Debut de l emission\n");
     
     if( (gettimeofday(&debut, NULL)) == -1){
	perror("Erreur dans la recuperation du temps avant l emission des msgs\n\n");
	exit(-1);
     }/*Fin du if*/

     /*Ecriture dans le tube de MESSAGES_NB messages de taille MESSAGES_TAILLE*/
    for(i = 0; i < MESSAGES_NB; i ++){
      if( (write(fd_tube, msg, MESSAGES_TAILLE)) == -1){
          perror("Erreur dans l ecriture du tube");
          exit(-1);
      }/*Fin du if*/
    }/*Fin du for*/
    
    printf("Fin de l'emission du message\n");

    /*fermiture du premier tube*/
    close(fd_tube);

    /*emission du temps*/
    if((fd_tube2=open(TubeTemps,O_WRONLY,S_IWUSR)) == -1){
    	perror("Erreur dans l ouverture du tube en ecriture\n\n");
       exit(-2);
    }
    if(write(fd_tube2,&debut, sizeof(debut)) == -1){
    	perror("Erreur dans l ecriture dans le tube\n");
	exit(-1);
    }
    

      /*fermeture du 2eme tube   */

      close(fd_tube2);
     exit(0);
}
