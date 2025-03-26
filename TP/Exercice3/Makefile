# Variables
CC = gcc
CFLAGS = -Wall -pedantic -g -mconsole
EXEC = horaires
OBJS = main_horaires.o horaires.o

# 1) Cible par défaut
all: $(EXEC)

# 2) Cible qui crée l'exécutable à partir des objets
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# 3) Règle de compilation générique pour les fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# 4) Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f *.o $(EXEC)
