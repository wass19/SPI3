#=====================
# Makefile du Cours 1
#=====================

#-------------
# Executables 
#-------------

c1test1 : c1test1.o eltprim.o lstprim.o lstop.o pileprim.o predicat.o
	gcc c1test1.o eltprim.o lstprim.o lstop.o pileprim.o predicat.o -o c1test1

c1test1.o : c1test1.c
	gcc -c c1test1.c -o c1test1.o 

#----------
# Modules
#----------

# TDA ELEMENT
#

# -- Primitives avec realisation par "int"
#
#eltprim.o : eltint.c eltint.h
#	gcc -c eltint.c -o eltprim.o

#eltprim.h : eltsdd.h
#	touch eltprim.h

#eltsdd.h : eltint.h
#	touch eltsdd.h

# -- Primitives avec realisation par "char"
#
eltprim.o : eltcar.c eltcar.h
	gcc -c eltcar.c -o eltprim.o

eltprim.h : eltsdd.h
	touch eltprim.h

eltsdd.h : eltcar.h
	touch eltsdd.h
	
# -- Operations 
#

# TDA LISTE
#

# -- Primitives avec realisation par pointeurs : 
#
lstprim.o : lstptr.c lstprim.h
	gcc -c lstptr.c -o lstprim.o

lstsdd.h : lstptr.h
	touch lstsdd.h

# -- Primitives avec realisation par faux pointeurs : 
#
# lstprim.o : lsttab.c lstprim.h
# 	gcc -c lsttab.c -o lstprim.o
# 
# lstsdd.h : lsttab.h
# 	touch lstsdd.h
# 
lstprim.h : lstsdd.h 
	touch lstprim.h

# -- Primitives avec realisation par faux pointeurs : (pile)
pileprim.o : piltabdy.c pileprim.h
	gcc -c piltabdy.c -o pileprim.o

pileprim.h : pilesdd.h 
	touch pileprim.h

pilesdd.h : piltabdy.h 
	touch pilesdd.h


# -- Operations 
#

lstop.o : c1lstop.c c1lstop.h 
	gcc -c c1lstop.c -o lstop.o

c1lstop.h : lstprim.h
	touch c1lstop.h

predicat.o : predicat.c predicat.h
	gcc -c predicat.c -o predicat.o

predicat.h : lstprim.h
	touch predicat.h
#----------------------------
# Gestion generale du projet 
#----------------------------

all : c1test1

clean :
	rm *.o

tags : 
	etags *.c *.h