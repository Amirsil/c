CC = gcc
CFLAGS = -Wall -Werror -g
BIN = main
OBJS = *.o
	   
all: $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(BIN)
	@rm *.o

%.o: src/%.c
	@$(CC) $(CFLAGS) -c $^
	
clean:
	-@rm $(BIN) *.o $(BIN).exe 2>/dev/null || true
