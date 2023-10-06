SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include
TESTDIR=tests
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g -std=c99  -I$(INCLUDEDIR)  
LDFLAGS=-lm -lncurses
EXEC=jeuDeLaVie

all :  $(BINDIR)/$(EXEC)

tests: $(SRCDIR)/testJeuDeLaVie.o $(SRCDIR)/GrilleJeuDeLaVie.o $(SRCDIR)/JeuDeLaVie.o
	gcc -o $(TESTDIR)/testJeuDeLaVie $(SRCDIR)/testJeuDeLaVie.o $(SRCDIR)/GrilleJeuDeLaVie.o $(SRCDIR)/JeuDeLaVie.o  $(LDFLAGS) -lcunit

$(BINDIR)/$(EXEC) : $(SRCDIR)/main.o $(SRCDIR)/GrilleJeuDeLaVie.o $(SRCDIR)/JeuDeLaVie.o
	$(CC)  -o $@ $^ $(LDFLAGS)

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean :
	rm -rf $(BINDIR)/*
	rm -rf $(LIBDIR)/*
	rm -rf $(SRCDIR)/*.o
	rm -rf $(TESTDIR)/*
	rm -rf $(SRCDIR)/*~
