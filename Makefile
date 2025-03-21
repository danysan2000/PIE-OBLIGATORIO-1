#  PIE
# Makefile   OBLIGATORIO-1
#
#


all : libbits.a obligatorio1

COPT = -Wall -ansi -g -O0

obligatorio1 : obligatorio1.o libbits.a
	echo $<
	cc $(COPT) $<  -L ./ -lbits -o $@


.c.o:
	cc $(COPT) -c $<

libbits.a : bits.o
	ar rcs $@ $<

clean:
	rm -f *.o *.a obligatorio1
