CC = gcc
CFLAGS = -Wall -pedantic -g -mconsole

all: prog_stack prog_somme prog_search prog_pointeur prog_tri

# Compilation du programme `prog_stack` (Exercice B.1)
prog_stack: stack_overflow.o main_stack.o
	$(CC) $(CFLAGS) -o prog_stack stack_overflow.o main_stack.o

# Compilation du programme `prog_somme` (Exercice B.2)
prog_somme: somme_tableau.o main_somme.o
	$(CC) $(CFLAGS) -o prog_somme somme_tableau.o main_somme.o

# Compilation du programme `prog_search` (Exercice B.4)
prog_search: search_array.o main_search.o
	$(CC) $(CFLAGS) -o prog_search search_array.o main_search.o

# Compilation du programme `prog_pointeur` (Exercice B.5)
prog_pointeur: pointeurs_fonctions.o main_pointeurs.o
	$(CC) $(CFLAGS) -o prog_pointeur pointeurs_fonctions.o main_pointeurs.o

# Compilation du programme `prog_tri` (Exercice B.6)
prog_tri: tri_fonctions.o main_tri.o
	$(CC) $(CFLAGS) -o prog_tri tri_fonctions.o main_tri.o

# Règle générique pour compiler les fichiers `.o`
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et exécutables
clean:
	rm -f *.o prog_stack prog_somme prog_chaine prog_search prog_pointeur prog_pointeur2 prog_tri
