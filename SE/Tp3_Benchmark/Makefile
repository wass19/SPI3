
#==================
# Makefile Codage
#==================

#-------------
# Executables
#-------------

exectemps : exectemps.o
	gcc exectemps.o -o exectemps

exectemps.o : exectemps.c
			gcc -c exectemps.c -o exectemps.o

tempsmoy : tempsmoy.o
	gcc tempsmoy.o -o tempsmoy

tempsmoy.o : tempsmoy.c
	gcc -c tempsmoy.c -o tempsmoy.o

#----------------------------
# Gestion generale du projet
#----------------------------

all : tempsmoy exectemps

clean :
	rm *.o
	rm tempsmoy
	rm exectemps
