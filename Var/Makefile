CC = gcc
CFLAGS = -Wall -Werror -g -I include
BIN = bin/main
OBJS = build/main.o build/var.o
   
all: $(OBJS)
	@mkdir -p bin
	@$(CC) $(CFLAGS) $(OBJS) -o $(BIN)

build/%.o: src/%.c
	@mkdir -p build
	@$(CC) $(CFLAGS) -c $^ -o $@

	
clean:
	@rm -rf bin build
