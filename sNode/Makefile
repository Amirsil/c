CC = gcc
CFLAGS = -Wall -g -I include
BIN = bin/main
OBJS = build/main.o build/s_node.o
   
all: $(OBJS)
	@mkdir -p bin
	@$(CC) $(CFLAGS) $(OBJS) -o $(BIN)

build/%.o: src/%.c
	@mkdir -p build
	@$(CC) $(CFLAGS) -c $^ -o $@
	
clean:
	@rm -rf build bin
