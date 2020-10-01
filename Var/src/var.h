#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum types{STRING, INTEGER, DOUBLE, CHARACTER, U_INTEGER, NONE};

typedef struct Var{
	enum types type;
	void *valptr;
} Var;

void print_var(Var *ptr);
void free_var(Var **ptr);

void int_var(int val, Var** ptr);
void double_var(double val, Var** ptr);
void uint_var(unsigned int val, Var** ptr);
void char_var(char val, Var** ptr);
void str_var(char *val, Var** ptr);

void *(*malloc_fn)(size_t size);
void (*free_fn)(void *ptr);

/* The allocator is defaulted to glibc's general purpose allocator, 
to change it to your own custom allocator simply change malloc_fc and free_fn */