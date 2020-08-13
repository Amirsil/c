#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum types{STRING, INTEGER, DOUBLE, CHARACTER, UINTEGER};

typedef struct var{
	enum types type;
	void *valueptr;
} var;

void PrintTvar(var *ptr);