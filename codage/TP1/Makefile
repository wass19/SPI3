all : prog
prog : main.o matrice.o
	gcc -o prog main.o matrice.o
main.o : main.c matrice.h
	gcc -c main.c
matrice.o : matrice.c matrice.h
	gcc -c matrice.c
clean :
	rm *.o prog