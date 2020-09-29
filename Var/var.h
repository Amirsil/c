#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum types{STRING, INTEGER, DOUBLE, CHARACTER, U_INTEGER, NONE};

typedef struct Var{
	enum types type;
	void *valptr;
} Var;

void print_var(Var *ptr);
void free_var(Var *ptr);

void int_var(const int val, Var* ptr);
void double_var(const double val, Var* ptr);
void uint_var(const unsigned int val, Var* ptr);
void char_var(const char val, Var* ptr);
void str_var(char *val, Var* ptr);