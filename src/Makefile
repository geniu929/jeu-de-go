CC=gcc
CEFLAGS= -g -W -Wall -ansi -pedantic
FICHIERS=liste.o listegroup.o groupes.o plateau.o partie.o main.o
PROG = Go

all: $(FICHIERS)
	$(CC) $(FICHIERS) $(CEFLAGS) -o $(PROG)

liste.o: liste.c
	$(CC) -c $(CEFLAGS) liste.c

listegroup.o: listegroup.c
	$(CC) -c $(CEFLAGS) listegroup.c

groupes.o:groupes.c
	$(CC) -c $(CEFLAGS) groupes.c

plateau.o: plateau.c
	$(CC) -c $(CEFLAGS) plateau.c

partie.o:partie.c
	$(CC) -c $(CEFLAGS) partie.c

main.exe: liste.o listegroup.o groupes.o plateau.o partie.o main.o
	$(CC) $(CEFLAGS) $(FICHIERS) $(PROG)
clean:
	rm -f *.o
