#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>


int main(int argc, char * argv[]){

int tube[2];
int tube2[2];
pipe(tube);
pipe(tube2);

char poubelle[20];
strcpy(poubelle,"/dev/null");
int fd = open(poubelle, 0666);

  if(argc != 4) {
    printf("Utilisation : %s <nbExecutions> <commande> <nbProcessus>\n", argv[0]);
    exit(-1);
  }

  int cr=0;
  int i=0;

  switch (fork()) {
    case -1:
      perror("erreur fork");
      exit(-1);
    case 0:
      close(1);
      dup2(fd,1);
      close(tube[0]);
      close(tube2[0]);
      execlp(argv[2],argv[2],NULL);
      cr=1;
      i=1;
      write(tube[1],&cr,sizeof(char));
      write(tube2[1],&i,sizeof(int));
      close(tube2[1]);
      close(tube[1]);
      exit(cr);
    default:
      close(0);
      close(tube[1]);
      close(tube2[1]);
      read(tube2[0],&i,sizeof(int));
      read(tube[0],&cr,sizeof(char));
      close(tube[0]);

      if(i==1)
        printf("%s n'est pas une commande \n",argv[2]);
      if(cr == 0)
        execlp("./tempsmoy","./tempsmoy",argv[1],argv[2],argv[3],NULL);

  }

  exit(0);

}
