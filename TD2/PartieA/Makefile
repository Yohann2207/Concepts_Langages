CC = gcc
CFLAGS = -Wall -pedantic -g -mconsole

all: prog_rand prog_des prog_stat  # Compile tout

# Compilation du programme `prog_rand` (Exercice 1)
prog_rand: util_rand.o main_rand.o
	$(CC) $(CFLAGS) -o prog_rand util_rand.o main_rand.o

# Compilation du programme `prog_des` (Exercice 2)
prog_des: util_rand.o jeu_des.o main_des.o
	$(CC) $(CFLAGS) -o prog_des util_rand.o jeu_des.o main_des.o

# Compilation du programme `prog_stat` (Exercice 3)
prog_stat: util_rand.o stat_rand.o main_stat.o
	$(CC) $(CFLAGS) -o prog_stat util_rand.o stat_rand.o main_stat.o

# Règle générique pour compiler les fichiers .o
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et exécutables
clean:
	rm -f *.o prog_rand prog_des prog_stat
