all : test_lst

CHOIX_ELT = eltint
CHOIX_LST = lstfauxptr

#-------------
# Executables 
#-------------

test_lst : test_lst.o eltprim.o lstprim.o lstop.o
	gcc -Wall $^ -o $@

%o: %.c
	gcc -Wall -c $^ -o $@

#----------
# Modules
#----------

# TDA ELEMENT
#

# -- Primitives avec realisation par "int"
#
eltprim.o : $(CHOIX_ELT).c $(CHOIX_ELT).h
	gcc -c $(CHOIX_ELT).c -o eltprim.o

eltprim.h : eltsdd.h
	touch eltprim.h

eltsdd.h : $(CHOIX_ELT).h
	touch eltsdd.h

# -- Operations 
#

# TDA LISTE
#

# -- Primitives avec realisation par pointeurs : 
#

lstprim.o : $(CHOIX_LST).c lstprim.h
	gcc -c $(CHOIX_LST).c -o lstprim.o

lstsdd.h : $(CHOIX_LST).h
	touch lstsdd.h

# -- Primitives avec realisation par faux pointeurs : 
#

# lstprim.o : lsttab.c lstprim.h
# 	gcc -c lsttab.c -o lstprim.o

# lstsdd.h : lsttab.h
# 	touch lstsdd.h

lstprim.h : lstsdd.h 
	touch lstprim.h


#----------------------------
# Gestion generale du projet 
#----------------------------

clean :
	rm *.o

tags : 
	etags *.c *.h