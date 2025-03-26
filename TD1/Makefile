CC = gcc
CFLAGS = -Wall -Wextra

SRC = main.c

PREPROC_OUT = preprocess_output.i

all: compile

compile: $(SRC)
	$(CC) $(CFLAGS) -o program $(SRC)

preprocess: $(SRC)
	$(CC) -E $(SRC) -o $(PREPROC_OUT)
	cat $(PREPROC_OUT) | less  # Affiche le fichier après pré-processing

clean:
	rm -f program $(PREPROC_OUT)
