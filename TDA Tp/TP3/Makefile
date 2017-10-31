#============================
# Makefile du Cours 3 / ARBRE
#============================

#-------------
# Executables 
#-------------

ARBRE = ARBRE_liste
ELT   = eltstr
FILE  = File_PTR_Circulaire

#all: ARBRE_test ARBRE_op_test eltstr_test
all: ARBRE_op_test eltstr_test


ARBRE_test: ARBRE_test.o eltprim.o ARBRE_prim.o 
	gcc $^ -o $@

ARBRE_op_test: ARBRE_op_test.o File_Prim.o eltprim.o ARBRE_prim.o ARBRE_op.o 
	gcc $^ -o $@

eltstr_test: eltstr_test.o eltprim.o
	gcc $^ -o $@

ARBRE_op.o: ARBRE_op.c File_Prim.o ARBRE_prim.o
	gcc -c $^ -o $@

%.o: %.c
	gcc -c $^ -o $@


eltprim.o : $(ELT).c  $(ELT).h eltprim.h
	gcc -c $(ELT).c -o eltprim.o

File_Prim.o : $(FILE).c  $(FILE).h File_Prim.h
	gcc -c $(FILE).c -o File_Prim.o

ARBRE_prim.o : $(ARBRE).c $(ARBRE).h ARBRE_prim.h
	gcc -c $(ARBRE).c -o ARBRE_prim.o



clean:
	rm *.o