CC = gcc
CFLAGS = -Wall

all: lef

lef: lef-bib.o testa-lef.o
	$(CC) $(CFLAGS) -o lef lef.o testa-lef.o

lef-bib.o: lef.c
	$(CC) $(CFLAGS) -c lef.c

testa-lef.o: testa-lef.c
	$(CC) $(CFLAGS) -c testa-lef.c

clean:
	rm -f lef *.o

