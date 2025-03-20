#  PIE
# Makefile   OBLIGATORIO-1
#
#


all : libbits.a obligatorio1

COPT = -Wall -ansi -ggdb -O0

obligatorio1 : obligatorio1.o libbits.a
	cc $(COPT) -o $@obligatorio1.o -L ./ -lbits

.c.o:
	cc $(COPT) -c $<

libbits.a : bits.o
	ar rcs $@ $<

clean:
	rm -f *.o *.a obligatorio1
