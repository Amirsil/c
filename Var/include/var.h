#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum types {
	NONE = 0,
	STRING, 
	INTEGER, 
	DOUBLE, 
	CHARACTER, 
	U_INTEGER
} types_t;

typedef struct var_t {
	types_t type;
	void *valptr;
} var_t;

void print_var(var_t *ptr);
void free_var(var_t *ptr);

void int_var(int val, var_t* ptr);
void double_var(double val, var_t* ptr);
void uint_var(unsigned int val, var_t* ptr);
void char_var(char val, var_t* ptr);
void str_var(char *val, var_t* ptr);

void *(*malloc_fn)(size_t size);
void (*free_fn)(void *ptr);

/* The allocator is defaulted to glibc's general purpose allocator, 
to change it to your own custom allocator simply change malloc_fc and free_fn */