#=====================
# Makefile du Cours 1
#=====================

#-------------
# Executables 
#-------------

td1test1 : td1test1.o eltprim.o lstprim.o td1.o
	gcc td1test1.o eltprim.o lstprim.o td1.o -o td1test1 

td1.o : td1lstop.c td1lstop.h 
	gcc -c td1lstop.c -o td1.o
	
c1test1 : c1test1.o eltprim.o lstprim.o lstop.o
	gcc c1test1.o eltprim.o lstprim.o lstop.o -o c1test1

c1test1.o : c1test1.c
	gcc -c c1test1.c -o c1test1.o 
	
td1test1.o : td1test1.c
	gcc -c td1test1.c -o td1test1.o 

td1lstop.o : td1lstop.c td1lstop.h
	gcc -c td1lstop.c -o td1lstop.o 

td1lstop.h : lstprim.h
	touch td1lstop.h

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

# -- Primitives avec realisation par "struct"
#
eltprim.o : eltint.c eltint.h
	gcc -c eltint.c -o eltprim.o

eltprim.h : eltsdd.h
	touch eltprim.h

eltsdd.h : eltint.h
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

# -- Operations 
#

lstop.o : c1lstop.c c1lstop.h 
	gcc -c c1lstop.c -o lstop.o

c1lstop.h : lstprim.h
	touch c1lstop.h

#----------------------------
# Gestion generale du projet 
#----------------------------

all : td1test1 c1test1 

clean :
	rm *.o

tags : 
	etags *.c *.h