# Variables
CC = gcc
CFLAGS = -Wall -pedantic -g -mconsole
EXEC = pile
OBJS = main_pile.o pile.o

#1)
all: $(EXEC)

#2) , 4)
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

#3)
%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(EXEC)
