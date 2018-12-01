/*	       Redefinition des noms des signaux           */

#define SIG_EN_OUT  SIGALRM  // plus d'energie
#define SIG_DEAD	SIGHUP     // le bateau tué par un autre
#define SIG_VICTORY SIGABRT  // le bateau gagnant
#define SIG_PLAY	SIGUSR1    //quand le bateau veut jouer
#define SIG_SHIELD  SIGUSR2  // l'existance du bouclier
