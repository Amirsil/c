CC = gcc
CFLAGS = -Wall -Werror -g
BIN = var
OBJS = *.o
	   
all: mainapp


mainapp: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)
	rm *.o

%.o: src/%.c
	$(CC) $(CFLAGS) -c 	$^
	
clean:
	touch foo.o
	rm $(BIN) *.o