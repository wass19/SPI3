/*
* Programme qui mesure le temps moyen d'excution d'un programme C en excutant K fois C par N processus
*
* ./prog K C N
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

void initTab(int tab[], int tailleTab) {
	int i;
	for(i = 0; i < tailleTab; i++) {
		tab[i] = 0;
	}
}

int main(int argc, char * argv[]) {
	if(argc != 4) {
		printf("Utilisation : %s <nbExecutions> <commande> <nbProcessus>\n", argv[0]);
		exit(-1);
	}
	int nbExecutions = atoi(argv[1]),nbProcessus = atoi(argv[3]), nbFils;
	int tube[nbProcessus][2];
	for(nbFils = 0; nbFils < nbProcessus; nbFils++) {
		pipe(tube[nbFils]);
	}
	int tabTemps[nbProcessus];
	int nbExecutionsFaites;
	int premierTemps=0;
	struct timeval tpsDepart;
	struct timeval tpsArrivee;
	int tpsTotal;
	int cr = 1;
	int tpsRetenu;
	int estPere = 1;
  char cmd[20] ;
	char poubelle[20];

	strcpy(poubelle,"/dev/null");
  strcpy(cmd,argv[2]);

	int fd = open(poubelle, 0666);

	initTab(tabTemps, nbProcessus);
	nbFils = 0;


	for(nbFils=0;nbFils < nbProcessus && estPere;nbFils++) {
		switch(estPere = fork()) {
			case -1:
				printf("Erreur 1er fork\n");
				exit(-1);

			case 0:
				close(0);
				close(tube[nbFils][0]);
				if(gettimeofday(&tpsDepart, NULL)) {
					printf("Erreur lors de la recuperation du temps\n");
				}
        for(nbExecutionsFaites = 0; nbExecutionsFaites < nbExecutions; nbExecutionsFaites++){

          switch(fork()){
            case -1:
              perror("erreur 2eme fork");
              exit(-1);
            case 0:;
						 	dup2(fd,1);
              cr=execlp(cmd,cmd,NULL);
              perror("Error execlp");
              exit(cr);
          }
				}
        while(wait(&cr)!=-1);

        if(gettimeofday(&tpsArrivee, NULL)) {
					printf("Erreur lors de la recuperation du temps\n");
				}
				tpsTotal = tpsArrivee.tv_sec * 1000 + tpsArrivee.tv_usec / 1000 - tpsDepart.tv_sec * 1000 + tpsDepart.tv_usec / 1000;

        if(cr) {
          if(WIFEXITED(cr)) {
            printf("Exit avec CR = %d \n",WEXITSTATUS(cr));
          }
          if(WIFSIGNALED(cr)) {
            printf("Exit avec signal : %d \n",WTERMSIG(cr));
          }
          tpsTotal = -cr;
          write(tube[nbFils][1], &tpsTotal, sizeof(int));
          printf("\n");
        };

				write(tube[nbFils][1], &tpsTotal, sizeof(int));
				close(tube[nbFils][1]);

				exit(0);
		}
	}
	/* Ecriture dans le tableau */
	for(nbFils = 0; nbFils < nbProcessus; nbFils++) {
		close(tube[nbFils][1]);
		read(tube[nbFils][0], &(tabTemps[nbFils]), sizeof(int));
		close(tube[nbFils][0]);
	}

	int taille;
	int j;
	int flag=0;
	for(nbFils = 0,taille=nbProcessus; nbFils < nbProcessus; nbFils++){
			if(tabTemps[nbFils]> 0) {
				flag=1;
			}
	}if(flag!=0){
		for(nbFils = 0,taille=nbProcessus; nbFils < nbProcessus; nbFils++){
			if(tabTemps[nbFils] <= 0) {
				for(int i=nbFils+1, j=nbFils;i<nbProcessus;i++,nbFils++){
					tabTemps[nbFils]=tabTemps[i];
				}nbFils=j;
				taille--;
			}
		}
	}else{
		printf("tableau vide\n");
		exit(0);
	}
  printf("\n\n");
	for(nbFils = 0; nbFils < taille; nbFils++) {
		if(tabTemps[nbFils] <= 0) {
			printf("Erreur pour l'execution du fils n°%i\n", nbFils);
			premierTemps++;
		} else {
			printf("Temps n°%i : %i\n", nbFils, tabTemps[nbFils]);
		}
	}
	tpsRetenu = tabTemps[(nbProcessus + premierTemps)/2];
	if(taille>0){
	  printf("-+tab+-\n");
	  printf("Indice  Valeur\n");

	  for(int i=0 ;i<taille;i++){
	      printf("%i        %.2f	secondes\n",i,(float)tabTemps[i]/1000);
	  }

		printf("\n\n");
	}
	else{
		perror("tableau vide");
	}

	if(tpsRetenu > 0) {
		printf("Temps retenu : %i ms\n", tpsRetenu);
		printf("La commande \"%s\" necessite donc %.2f secondes pour etre executee\n", argv[2], (float)tpsRetenu / nbExecutions);

	} else {
		printf("Aucune execution ne s'est bien deroulee\n");
	}


	return 0;
}
