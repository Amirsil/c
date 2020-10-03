CC = gcc
CFLAGS = -Wall -Werror -g
BIN = main
OBJS = *.o
   
all: $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(BIN)
	@rm -f $(OBJS)

%.o: src/%.c
	@$(CC) $(CFLAGS) -c $^
	
clean:
	@rm -f $(BIN) $(BIN).exe $(OBJS)
