#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include "signal.h"


void tricroissant( int *tab, int tab_size){
  int i=0;
  int tmp=0;
  int j=0;

  for(i = 0; i < tab_size; i++)
    {
      for(j = 1; j < tab_size; j++)
        {
          if(tab[i] < tab[j])
            {
              tmp = tab[i];
              tab[i] = tab[j];
              tab[j] = tmp;
              j--;
            }
        }
    }
  tmp = tab[0];
  for(i = 0; i < tab_size; i++)
    tab[i] = tab[i+1];
  tab[tab_size-1] = tmp;
}

int mediane (int tab[],int taille){
  int pair=0;
  int med = 0;
  if ((taille % 2) != pair){
    //printf("#DEBUG tab[taille/2 +1] :  taille / 2 +1  %i   %i\n",taille / 2 +1,tab[taille/2 +1]  );
    med=tab[(taille / 2)];
    return (med);
  }
  else{
  //  printf("#DEBUG tab[taille/2 -1] :  taille / 2  %i   %i\n",taille/2 -1 ,tab[taille/2 -1] );
  //  printf("#DEBUG tab[taille/2 ] :   taille/2 %i   %i\n",taille/2,tab[(taille/2)] );

    med=(tab[taille/2 - 1] + tab[taille/2]) / 2;
    return med ;
  }


}

/*
 * Programme Principal
 */

int main( int nb_arg , char * tab_arg[] ){
  char nomprog[128] ;
  int N;
  int K;
  char * C;
  int i,j;
  int pidfils;
  int med;
  int pipe(int tube[2]);
  struct timeval tpdepart;
  struct timeval tpfin;
  /*
  * Capture des parametres
  */

  if( nb_arg != 4 )
  {
    fprintf( stderr , "Usage : %s <nbExecution> <commande> <nbProcessusfils>\n",
    tab_arg[0] );
    exit(-1);
  }

  strcpy( nomprog , tab_arg[0] );
  sscanf( tab_arg[1] , "%d" , &K) ;
  sscanf( tab_arg[2] , "%s" , &C) ;
  sscanf( tab_arg[3] , "%d" , &N) ;

  int r;
  int * tabpid;
  int * Time;
  int Moy[N];
  Time=malloc(N * sizeof(int)+1);
  tabpid=malloc(N * sizeof(int)+1);
  int tube[N][2];
  for(i = 0; i < N; i++) {
    pipe(tube[i]);
  }
  /*********/

  for(i=0;i<N;i++){
    switch(tabpid[i]=fork()){

    case -1 : perror("PB FORK()");
              exit(1);
              break;

    case  0 :
              // Les fils ecrivent mais ne lisent pas
              close(tube[i][0]);
              if(gettimeofday(&tpdepart,NULL)){
                printf("ERROR temps depart :-");
              }

              for(j=0;j<K;j++){
                r=system(&C);
                //printf("#DEBUG r => %i\n",r );
                if(r==32512){
                  kill(getpid(),SIGKILL);
                  return -1;
                }
              //  printf("\n#DEBUG processus fils n° %i: -%i- ",i,getpid());
              //  printf("#DEBUG resultat de la commande :	%i",system(&C));
              }

              if(gettimeofday(&tpfin,NULL)){
                printf("ERROR temps fin :-");
              }

              Time[i]=(tpfin.tv_sec * 1000 +tpfin.tv_usec / 1000)-(tpdepart.tv_sec * 1000 + tpdepart.tv_usec / 1000);
              printf("\n");
            //  printf("#DEBUG time %i -> %i \n",i,Time[i]);

              write(tube[i][1], &Time[i], sizeof(int));
              close(tube[i][1]);
              exit(r);
              perror("Problème fork() \n");
              break;
    }
  }

  while((pidfils=wait(&r))!=-1 ){
    //printf("#DEBG r => %i\n",r);
    //printf("#DEBUG pidfils %i\n",pidfils);
    for(i=0;i != N;i++){
        close(tube[i][1]);
        read(tube[i][0], &(Time[i]), sizeof(int));
      //  printf("#DEBUG tube %i\n",tube[i][0] );
        close(tube[i][0]);
      //  printf("#DEBUG time %i %i\n",i,Time[i]);
    }
  }
  if(r!=0){
      printf("ERROR <commande> :-\n");
      kill (getpid (), SIGKILL);
  }


  for (j = 0; j < N ; j++) {
    Moy[j]=(Time[j])/(K);
  }

  tricroissant(&Moy,N);
  for (j = 0; j < N ; j++) {
    printf("\n processus fils n° %i: -%i-	",j+1,tabpid[j]);
    //printf(" ***pidtab*** %i  ",tabpid[j]);
    //printf(" ***Time*** %i ",Time[j]);
    printf(" ***MOYENNE*** %i \n",Moy[j]);
  }

  med = mediane(Moy,N);
  printf("La Moyenne est de   =>    %i\n",med);

  free(Time);
  free(tabpid);
  exit(0);
}
