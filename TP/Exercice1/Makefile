CC = gcc
CFLAGS = -Wall -pedantic -g -mconsole
EXEC = fabbriyohannexo
OBJS = fabbriyohannlisteint.o fabbriyohannexo.o

#1)
all: $(EXEC)

#2) , 4)
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

#3)
%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(EXEC) savelist.bin

