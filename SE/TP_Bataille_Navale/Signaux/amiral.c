#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


#include <mer.h>
#include <bateaux.h>

#include "common.h" /* définition des signaux */


/*
 * VARIABLES GLOBALES (utilisees dans les handlers)
 */

char Nom_Prog[256] ;
int fd_mer;
int end = 0;
pid_t shield = 0;
int nbSpawned = 0;
int i=0;
int nbVoulu=0;

bateaux_t * liste_bateaux;

/*
 * FONCTIONS LOCALES
 */


/**
 * Etat du bouclier
 * @param signal Signal capturé
 * @param siginfo Informations sur l'envoyeur
 * @param ucontext Context
 */
static void shieldEnabled(int signal, siginfo_t * siginfo, void * ucontext){

    if(signal == SIG_SHIELD){
        #ifdef _DEBUG_
            fprintf(stderr, "Signal SIG_SHIELD reçu ! \n");
        #endif
            shield = siginfo->si_pid;
    }else{
        fprintf(stderr, "Signal capturé non reconnu par shieldEnabled()");
        return;
    }
}

/**
 * Wake up du amiral
 * @param signal Signal capturé
 */
static void wakeUp(int signal){

    #ifdef _DEBUG_
        fprintf(stdout, "Wake up!\n");
    #endif
}

/**
 *
 * Ce handler permet aux bateaux de s'initialiser de bouger et de tirer sur d'autre bateaux
 *
 * @param signal   Signal capturé
 * @param siginfo  Informations de l'envoyeur
 * @param ucontext Context
 */
static void playAnswer(int signal, siginfo_t * siginfo, void * ucontext){
    int noerr = CORRECT;
    int nbBateaux = 0;
    int pidTarget = 0;
    int indTarget = 0;
    int indBateau = 0;

    booleen_t bouger = FAUX;
    booleen_t acquisition = VRAI;
    coord_t cible;

    sigset_t waitMask;

    pid_t bateau_pid = siginfo->si_pid;
    coords_t * liste_voisins = NULL;

    #if _DEBUG_
        fprintf(stdout, "Demande de jeu provenant du bateau de PID: %i\n", siginfo->si_pid);
    #endif

    bateau_t * bateau = NULL;

    /* initialisation du bateau si iln'est pas présent dans la liste*/
    if (( indBateau = bateaux_pid_seek(liste_bateaux, bateau_pid)) == -1){

        bateau = bateau_new(NULL , 'A'+i , bateau_pid);
        i++;
        /* on kill le bateau si il n'a pu etre initialiser */
        if( (noerr = mer_bateau_initialiser(fd_mer, bateau)) == ERREUR){
            fprintf(stderr, "Le bateau %i de marque %c n'a pu s'intialiser dans la mer.\n",
                bateau_pid, bateau_marque_get(bateau));
            bateau_destroy(&bateau);
            kill(bateau_pid, SIGKILL);
            return;
        }

        /* On ajoute notre bateau a la liste */
        if((noerr = bateaux_bateau_add( liste_bateaux, bateau ))){
            fprintf(stderr, "Le bateau %i de marque %c n'a pu être ajouté à la liste.\n",
                bateau_pid, bateau_marque_get(bateau));
            bateau_destroy(&bateau);
            kill(bateau_pid, SIGKILL);
            return;
        }

        /* nombre de bateaux dans la liste */
        nbBateaux = bateaux_nb_get(liste_bateaux);

        /* on ecrit le nombre de bateau dans la mer */
        mer_nb_bateaux_ecrire( fd_mer , nbBateaux);

        nbSpawned++;

        /* affichage de la mer */
        if((noerr = mer_afficher(fd_mer))){
            fprintf(stderr, "Impossible d'afficher la mer.\n");
            exit(ERREUR);
        }

        sleep(1);

        bateau_destroy(&bateau);

        return;
    }else{

        bateau = bateaux_bateau_get(liste_bateaux, indBateau);

        /* Recherche des voisins */
        mer_voisins_rechercher(fd_mer, bateau, &liste_voisins);

        /* deplacer le bateau*/
        mer_bateau_deplacer(fd_mer, bateau, liste_voisins, &bouger);

        /* Envoie du signal SIG_PLAY au processus du bateau */
        kill(bateau_pid, SIG_PLAY);

        coords_destroy(&liste_voisins);

        /* Confirmation du déplacement */
        if(bouger)
            fprintf(stdout, "Le bateau %i de marque %c s'est déplacé.\n",
                bateau_pid, bateau_marque_get(bateau));
        else
            fprintf(stdout, "Le bateau %i de marque %c ne peut se déplacer.\n",
                bateau_pid, bateau_marque_get(bateau));

        /* Recherche de cible */
        mer_bateau_cible_acquerir(fd_mer, bateau, &acquisition, &cible);

        /* Cible trouver*/
        if(acquisition){
            fprintf(stdout, "Cible acquise en [%i,%i]\n", cible.l, cible.c);

            if ((indTarget = bateaux_coord_seek(liste_bateaux, cible)) == -1){
                fprintf(stderr, "Ind of target [%i,%i] not found.\n", cible.l, cible.c);
                return;
            }else{

                pidTarget = bateau_pid_get(bateaux_bateau_get(liste_bateaux, indTarget));

                if(pidTarget == -1){
                    fprintf(stderr, "Pid of target [%i,%i] not found.\n", cible.l, cible.c );
                    return ;
                }

                shield = 0;

                /* Voir si la cible a un bouclier */
                kill(pidTarget, SIG_SHIELD);

                /* Attente des informations de notre bateau*/
                sigfillset(&waitMask);
                sigdelset(&waitMask, SIG_SHIELD); /* On débloque SIG_SHIELD */
                sigdelset(&waitMask, SIGALRM); /* reveil du amiral */

                alarm(1);

                sigsuspend(&waitMask);

                if(shield == pidTarget){
                    fprintf(stdout, "Le bateau %i a un bouclier, impossible de l'attaquer.\n", pidTarget);
                }else{
                    mer_bateau_cible_tirer(fd_mer, cible);

                    if( mer_afficher(fd_mer) == ERREUR ){
                        printf ("Impossible d'afficher la mer\n");
                        exit(ERREUR) ;
                    }

                    printf("Le bateau %i coule.\n", pidTarget);

                    sleep(1);

                    indTarget = bateaux_pid_seek(liste_bateaux, pidTarget);

                    mer_bateau_couler(fd_mer, bateaux_bateau_get(liste_bateaux, indTarget)); // Boat no longer exist on sea

                    bateaux_bateau_del(liste_bateaux, indTarget); // suppression du bateau de la liste

                    kill(pidTarget, SIG_DEAD);

                    /* réecriture du nombre de bateau dans la mer */
                    mer_nb_bateaux_ecrire( fd_mer , bateaux_nb_get(liste_bateaux));
                }

            }

        }else{
            #if _DEBUG_
                fprintf(stderr, "Pas de cible trouvée pour le bateau %i.\n", bateau_pid);
            #endif
        }

        if((noerr = mer_afficher(fd_mer))){
            fprintf(stderr, "Impossible d'afficher la mer.\n");
            exit(ERREUR);
        }

        /* nombre de bateau initialiser */
        mer_nb_bateaux_lire(fd_mer, &nbBateaux);

        if(nbSpawned > nbVoulu-1 && nbBateaux == 1){
            kill(bateau_pid, SIG_VICTORY);

            fprintf(stdout, "Le vainqueur est %i de marque %c.\n", bateau_pid, bateau_marque_get(bateau));
            end = 1;
        }
    }

}

/*
 * Programme Principal
 */
int
main( int nb_arg , char * tab_arg[] )
{
    char fich_mer[128] ;

    /*----------*/

    struct sigaction playRequest;

    /*
    * Capture des parametres
    */

    if( nb_arg != 3 )
    {
    fprintf( stderr , "Usage : %s <fichier mer> <nb bateaux>\n",
       tab_arg[0] );
    exit(-1);
    }

    strcpy( Nom_Prog , tab_arg[0] );
    strcpy( fich_mer , tab_arg[1] );
    nbVoulu=atoi(tab_arg[2]);

    playRequest.sa_sigaction = playAnswer;
    playRequest.sa_flags     = SA_SIGINFO;
    sigemptyset(&playRequest.sa_mask);

    if(sigaction(SIG_PLAY, &playRequest, NULL) < 0){
        fprintf(stderr, "Erreur pour le signal SIG_PLAY lors de l'application du sigaction.\n");
        exit(ERREUR);
    }

    playRequest.sa_sigaction = shieldEnabled;

    if(sigaction(SIG_SHIELD, &playRequest, NULL) < 0){
        fprintf(stderr, "Erreur pour le signal SIG_SHIELD lors de l'application du sigaction.\n");
        exit(ERREUR);
    }

    /* timeout */
    playRequest.sa_handler = wakeUp;
    playRequest.sa_flags   = 0;

    if(sigaction(SIGALRM, &playRequest, NULL) < 0){
        fprintf(stderr, "Erreur pour le signal SIGALRM lors de l'application du sigaction.\n");
        exit(ERREUR);
    }

    /*
    * Affichage pid bateau amiral
    */

    printf(" PID bateau amiral = %d\n" , getpid() ) ;
    printf("%s %s \n", Nom_Prog, fich_mer);
    /* Initialisation de la generation des nombres pseudo-aleatoires */
    srandom((unsigned int)getpid());

    /* Opening sea file */
    if( (fd_mer = open( fich_mer, O_RDWR, 0644)) == ERREUR){
        fprintf(stderr, "%s: Erreur lors de l'ouverture de la sainte mer %s.\n", Nom_Prog, fich_mer);
        exit(ERREUR);
    }

    printf("Accès à la mer ouvert !");

    printf("Creation liste\n");
    liste_bateaux = bateaux_new() ;

    while(!end)
        pause();

    printf("\n\n\t----- Fin du jeu -----\n\n");

    exit(0);
}
