#include "var.h"

#define ALLOC_VAL(type, TYPE) {\
        void *valptr; \
        valptr = (ptr->valptr) ? realloc(ptr->valptr, sizeof(val)) : malloc(sizeof(val)); \
        *(type*)valptr = val; \
        *ptr = (Var){TYPE, valptr}; \
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
		case STRING: printf("\"%s\"\n", *(char**)ptr->valptr); break;
		case INTEGER: printf("%d\n", *(int*)ptr->valptr); break;
		case DOUBLE: printf("%f\n", *(double*)ptr->valptr); break;
		case CHARACTER: printf("\'%c\'\n", *(char*)ptr->valptr); break;
		case U_INTEGER: printf("%u\n", *(unsigned int*)ptr->valptr); break;
		case NONE: printf("This variable doesn't exist anymore\n");

	}
}

void int_var(const int val, Var *ptr) ALLOC_VAL(int, INTEGER);
void double_var(const double val, Var *ptr) ALLOC_VAL(double, DOUBLE);
void uint_var(const unsigned int val, Var *ptr) ALLOC_VAL(unsigned int, U_INTEGER);
void char_var(const char val, Var *ptr) ALLOC_VAL(char, CHARACTER);
void str_var(char *val, Var *ptr) ALLOC_VAL(char*, STRING);

void *(*malloc_fn)(size_t size) = &malloc;
void (*free_fn)(void *ptr) = &free;