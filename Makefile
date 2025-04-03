#  PIE
# Makefile   OBLIGATORIO-1
#
#

ARCHIVOS_ENTREGAR= obligatorio1.c bits.c bits.h Makefile

.PHONY: entrega

all : libbits.a obligatorio1 obligatorio1_dyn

COPT = -Wall -ansi -g -O0

obligatorio1 : obligatorio1.o libbits.a
	echo $<
	cc $(COPT) $<  -L ./ -lbits -o $@

obligatorio1_dyn: obligatorio1.o libbits.so
	echo $<
	cc $(COPT) $<  -L.  -lbits_dyn -o $@

.c.o:
	cc $(COPT) -c $<

libbits.a : bits.o
	ar rcs $@ $<

libbits.so : bits_dyn.o
	echo $<
	cc -shared -o libbits_dyn.so $<

bits_dyn.o : bits.c
	cc $(COPT) -c $< -fPIC  -o bits_dyn.o



clean:
	rm -f *.o *.a obligatorio1

entrega:
	zip  alberto_DANIEL_SANCHEZ_LATRONICO.zip   $(ARCHIVOS_ENTREGAR)

