#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum types{STRING, INTEGER, DOUBLE, CHARACTER, UINTEGER, NONE};

typedef struct Var{
	enum types type;
	void *valptr;
} Var;

void print_var(Var *ptr);
void new_var(enum types type, void *valptr, Var *ptr);
void free_var(Var *ptr);

void *intptr(const int val);
void *doubleptr(const double val);
void *uintptr(const unsigned int val);
void *charptr(const char val);
void *strptr(const char *val);