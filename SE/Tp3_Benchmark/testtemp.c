/info/tmp/AnnexesTPL3_175UD03/TP_Benchmark/Linux/com*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

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
	int cr = 0;
	int tpsRetenu;
	int estPere = 1;
	float t=0.0;
	initTab(tabTemps, nbProcessus);
	nbFils = 0;
	for(nbFils=0;nbFils < nbProcessus && estPere;nbFils++) {
		switch(estPere = fork()) {
			case -1:
				printf("Erreur lors du fork\n");
				exit(-1);

			case 0:
				printf("Fils n° : %i\n", nbFils);
				close(0);
				close(tube[nbFils][0]);
				if(gettimeofday(&tpsDepart, NULL)) {
					printf("Erreur lors de la recuperation du temps\n");
				}
				for(nbExecutionsFaites = 0; nbExecutionsFaites < nbExecutions ; nbExecutionsFaites++) {
						switch(fork()){
							case -1:
											 perror("Pb petit fils");
											 exit(-1);
							case 0:
											cr=execlp(argv[2],argv[2],NULL);
						}
				}
				while(wait(&cr)!=-1);
				if(gettimeofday(&tpsArrivee, NULL)) {
					printf("Erreur lors de la recuperation du temps\n");
				}
				tpsTotal = tpsArrivee.tv_sec * 1000 + tpsArrivee.tv_usec / 1000 - tpsDepart.tv_sec * 1000 + tpsDepart.tv_usec / 1000;

				if(cr) {
					printf("Interruption du fils n°%i lors de l'execution de %s : ", nbFils, argv[2]);
					if (WIFEXITED(cr)) {
				    printf("EXIT : CR=%d\n",WEXITSTATUS(cr));
				  }
				  if (WIFSIGNALED(cr)) {
				    printf("SIGNAL : %d\n",WTERMSIG(cr));
				  }
					tpsTotal = -cr;

				}
				write(tube[nbFils][1], &tpsTotal, sizeof(int));
				printf("\n");
				close(tube[nbFils][1]);

				exit(0);
		}
	}
	for(nbFils = 0; nbFils < nbProcessus; nbFils++) {
		close(tube[nbFils][1]);
		read(tube[nbFils][0], &(tabTemps[nbFils]), sizeof(int));
		close(tube[nbFils][0]);
	}
	for(nbFils = 0; nbFils < nbProcessus; nbFils++) {
		if(tabTemps[nbFils] <= 0) {
			printf("Erreur pour l'execution du fils n°%i\n", nbFils);
			premierTemps++;
		} else {
			printf("Temps n°%i : %.2f\n", nbFils, (float)tabTemps[nbFils]/1000);
		}
	}
	tpsRetenu = tabTemps[(nbProcessus + premierTemps)/2];

	if(tpsRetenu > 0) {
		printf("Temps retenu : %.2f ms\n", (float)tpsRetenu/1000);
		printf("La commande \"%s\" necessite donc %.2f millisecondes pour etre executee\n", argv[2],t=(float)tpsRetenu/1000);
	} else {
		printf("Aucune execution ne s'est pas bien deroulee\n");
	}


	return 0;
}
