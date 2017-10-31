all : testOperations calculette

ELEMENT = eltoperation
PILE    = piltabdy
LISTE   = lstptr

#-------------
# Executables 
#-------------

testOperations: testOperations.o eltprim.o operations.o
	gcc $^ -o $@

testPost: testPost.o eltprim.o operations.o lstprim.o pileprim.o lstop.o interpreteur.o
	gcc $^ -o $@

calculette: calculette.o eltprim.o operations.o lstprim.o pileprim.o lstop.o interpreteur.o
	gcc $^ -o $@

%.o: %.c
	gcc -c $^ -o $@

#----------
# Modules
#----------

# TDA ELEMENT
#

# -- Primitives avec realisation par "int"
#
eltprim.o : $(ELEMENT).c eltprim.h
	gcc -c $(ELEMENT).c -o eltprim.o

eltprim.h : eltsdd.h
	touch eltprim.h

eltsdd.h : $(ELEMENT).h
	touch eltsdd.h

# -- Operations 
#


# -- Primitives avec realisation par faux pointeurs : 
#

# PILE

pileprim.o : $(PILE).c pileprim.h
	gcc -c $(PILE).c -o pileprim.o

pileprim.h : pilesdd.h 
	touch pileprim.h

pilesdd.h : $(PILE).h 
	touch pilesdd.h

# LISTE


lstprim.o : $(LISTE).c lstprim.h
	gcc -c $(LISTE).c -o lstprim.o
	
lstprim.h : lstsdd.h 
	touch lstprim.h

lstsdd.h : $(LISTE).h
	touch lstsdd.h

# -- Operations 
#

#----------------------------
# Gestion generale du projet 
#----------------------------

clean :
	rm *.o

tags : 
	etags *.c *.h