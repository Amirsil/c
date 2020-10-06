CC = gcc
CFLAGS = -Wall -Werror -g -I include
BIN = bin/main
OBJS = build/main.o build/s_node.o
   
all: $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(BIN)

build/%.o: src/%.c
	@$(CC) $(CFLAGS) -c $^ -o $@
	
clean:
	@rm -f $(BIN) *.o $(BIN).exe build/*
