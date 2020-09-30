#include "var.h"

#define PRINT_VAR(type, var_type, format) case var_type: printf(""#format"\n", *(type*)ptr->valptr); break

#define ALLOC_VAL(type, var_type) {\
        void *valptr; \
        valptr = (ptr->valptr) ? realloc(ptr->valptr, sizeof(val)) : malloc(sizeof(val)); \
        *(type*)valptr = val; \
        *ptr = (Var){var_type, valptr}; \
       }

void free_var(Var *ptr){
	if (ptr->type == NONE) 
	{
		printf("This variable has already been freed");
		return;
	}
	free(ptr->valptr);
	ptr->type = NONE;
	ptr->valptr = 0x0;
}

void print_var(Var *ptr){
	switch (ptr->type){
		PRINT_VAR(char*, STRING, "%s");
		PRINT_VAR(int, INTEGER, %d);
		PRINT_VAR(double, DOUBLE, %f);
		PRINT_VAR(char, CHARACTER, '%c');
		PRINT_VAR(unsigned int, U_INTEGER, %u);
		default: printf("This variable doesn't exist anymore\n");

	}
}

void int_var(const int val, Var *ptr) 
	ALLOC_VAL(int, INTEGER)

void double_var(const double val, Var *ptr) 
	ALLOC_VAL(double, DOUBLE)

void uint_var(const unsigned int val, Var *ptr) 
	ALLOC_VAL(unsigned int, U_INTEGER)

void char_var(const char val, Var *ptr) 
	ALLOC_VAL(char, CHARACTER)
	
void str_var(char *val, Var *ptr)
{
	void *valptr;
    valptr = (ptr->valptr) ? realloc(ptr->valptr, strlen(val)) : malloc(strlen(val));
    *(char**)valptr = strdup(val);
    *ptr = (Var){STRING, valptr}; 
}

void *(*malloc_fn)(size_t size) = &malloc;
void (*free_fn)(void *ptr) = &free;