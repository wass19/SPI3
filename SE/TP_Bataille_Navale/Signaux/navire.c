#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <mer.h>
#include <bateaux.h>

#include "common.h"

/*
 * VARIABLES GLOBALES (utilisees dans les handlers)
 */

int Energie ;
pid_t pid_amiral ;

/*
 * Handlers
 */

/**
 * This boat can't handle anymore action:
 * SIG_EN_OUT  ---> Plus d'énergie dans le bateau
 * SIG_DEAD    ---> le bateau a été coulé
 * SIG_VICTORY ---> le bateau gagnant
 * @param signal le signal capturé
 */
static void stopBoat (int signal){

	if(signal == SIG_EN_OUT){
		fprintf(stdout, "Votre bateau %i est à cours d'énergie, oups !\n", getpid());
		/* Le bateau n'a plus d'énergie donc il attend jusqu'a ce qu'un autre bateau le tue*/
		pause();
	}else if(signal == SIG_DEAD)

		fprintf(stdout, "Votre bateau %i a été coulé, à bientôt !\n", getpid());

	else if(signal == SIG_VICTORY)

		fprintf(stdout, "Votre bateau %i a gagné !\n", getpid());

	else{

		fprintf(stderr, "Le bateau %i a capturé un signal non reconnu.\n", getpid());
		exit(ERREUR);

	}

	exit(CORRECT);
}

/**
 * le bateau a jouer donc on lui enlève de l'energie
 * @param signal Signal capturé
 */
static void hasPlayed (int signal){

	if(signal == SIG_PLAY){
		Energie -= BATEAU_MAX_ENERGIE / 20;

		/* Raise  SIG_EN_OUT pour indiquer que le bateau ne peux plus rien faire */
		if(Energie <= 0)
			raise(SIG_EN_OUT);

	}else{
		fprintf(stderr, "Le bateau %i a capturé un signal non reconnu lors de la phase de jeu.\n", getpid());
		exit(ERREUR);
	}
}

/**
 * Indiquer à l'amiral que le bateau a un bouclier
 * @param signal Signal capturé
 */
static void hasShield (int signal){

	if(signal == SIG_SHIELD){
		if(Energie >= BATEAU_SEUIL_BOUCLIER){
			kill(pid_amiral, SIG_SHIELD); // bouclier active
			kill(pid_amiral, SIGALRM); // bouclier active
		}
	}else{
		fprintf(stderr, "Le bateau %i a capturé un signal non reconnu.\n", getpid());
		exit(ERREUR);
	}
}

/*
 * Programme Principal
 */

int
main( int nb_arg , char * tab_arg[] )
{
	char nomprog[128] ;
	pid_t pid_bateau = getpid()  ;

	/*----------*/

	/*
	 * Capture des parametres
	 */

	if( nb_arg != 2 )
		{
			fprintf( stderr , "Usage : %s <pid amiral>\n",
				 tab_arg[0] );
			exit(-1);
		}

	/* Nom du programme */
	strcpy( nomprog , tab_arg[0] );
	sscanf( tab_arg[1] , "%d" , &pid_amiral ) ;

	/* Initialisation de la generation des nombres pseudo-aleatoires */
	srandom((unsigned int)pid_bateau);


	/* Affectation du niveau d'energie */
	Energie = BATEAU_MAX_ENERGIE/2 ;

	printf( "\n\n--- Debut bateau [%d]---\n\n" , pid_bateau );

	/*
	 * Deroulement du jeu
	 */

	/**
	 *  définition des hundlers
	 */
	signal(SIG_EN_OUT, stopBoat);
	signal(SIG_DEAD, stopBoat);
	signal(SIG_VICTORY, stopBoat);

	signal(SIG_PLAY, hasPlayed);
	signal(SIG_SHIELD, hasShield);

	/* le bateau peut commancer à jouer */
	while(1){
		fprintf(stdout, "Le bateau %i demande à jouer.\n", getpid());

		/* temps d'attente aléatoire entre chaque requete*/
		sleep(2 + rand() % 8);

		/* envoie d'une requete pour demander si il peut jouer*/
		if(kill(pid_amiral, SIG_PLAY) != 0){
			fprintf(stderr, "Erreur: Amiral absent (vérifiez son état sait-on jamais).\n");
			exit(ERREUR);
		}
	}

	printf( "\n\n--- Arret bateau (%d) ---\n\n" , pid_bateau );

	exit(ERREUR);
}
