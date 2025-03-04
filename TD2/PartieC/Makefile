CC = gcc
CFLAGS = -Wall -pedantic -g -mconsole

all: prog_factorielle prog_puissance

# Compilation du programme `prog_factorielle`
prog_factorielle: factorielle.o main_factorielle.o
	$(CC) $(CFLAGS) -o prog_factorielle factorielle.o main_factorielle.o

# Compilation du programme `prog_puissance`
prog_puissance: puissance.o main_puissance.o
	$(CC) $(CFLAGS) -o prog_puissance puissance.o main_puissance.o

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o prog_factorielle prog_puissance
