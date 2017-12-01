all : prog
prog : LM.o
	gcc -o prog LM.o -lm
LM.o : LM.c
	gcc -c LM.c -lm
clean :
	rm *.o prog