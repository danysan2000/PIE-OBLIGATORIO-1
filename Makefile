#  PIE
# Makefile   OBLIGATORIO-1
#
#

ARCHIVOS_ENTREGAR= obligatorio1.c bits.c bits.h Makefile

.PHONY: entrega

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

entrega:
	zip  alberto_DANIEL_SANCHEZ_LATRONICO.zip   $(ARCHIVOS_ENTREGAR)

