#include "var.h"
#define PRINT_VAR(var_type, format) printf(""#format" (%p)\n", *(var_type*)ptr->valptr, ptr->valptr)

#define OPTIMIZED_REALLOC(var_type, old_size, size) valptr = (size > old_size) ? realloc(var->valptr, size) : var->valptr

#define ALLOC_VAL(var_type, enum_type, size)\
	Var *var = *ptr; \
	void *valptr; \
	if (var){ \
	    if (var->valptr){ /* valptr is not NULL, therefore a var already exist and holds some kind of value and type */ \
	    	if (var->type == enum_type && var->type != STRING) valptr = var->valptr;\
			else switch (var->type){ \
	 			case INTEGER: OPTIMIZED_REALLOC(int, sizeof(int), size); break; \
	 			case DOUBLE: OPTIMIZED_REALLOC(double, sizeof(double), size); break; \
	 			case CHARACTER: OPTIMIZED_REALLOC(char, sizeof(char), size); break; \
	 			case U_INTEGER: OPTIMIZED_REALLOC(unsigned int, sizeof(unsigned int), size); break; \
	 			case STRING: OPTIMIZED_REALLOC(char*, strlen(*(char**)var->valptr)*sizeof(char), size); break; \
	 			case NONE: {}  /* the var type cannot be NONE, because valptr is not NULL */ \
			} \
		} \
		else valptr = malloc_fn(size); \
	} \
	else { \
		var = (Var*)malloc_fn(sizeof(Var)); \
		valptr = malloc_fn(size); \
	} \
    *(var_type*)valptr = val; \
    *var = (Var){enum_type, valptr}; \
    *ptr = var; \


void *(*malloc_fn)(size_t size) = &malloc;
void (*free_fn)(void *ptr) = &free;

void int_var(int val, Var **ptr) {
	ALLOC_VAL(int, INTEGER, sizeof(val))
}
void double_var(double val, Var **ptr) {
	ALLOC_VAL(double, DOUBLE, sizeof(val))
}
void uint_var(unsigned int val, Var **ptr) {
	ALLOC_VAL(unsigned int, U_INTEGER, sizeof(val))
}
void char_var(char val, Var **ptr) {
	ALLOC_VAL(char, CHARACTER, sizeof(val))
}
void str_var(char *val, Var **ptr) {
	ALLOC_VAL(char*, STRING, strlen(val)*sizeof(char))
}

void free_var(Var **ptr){
	Var *var = *ptr;
	if (var->type == NONE) {
		printf("This variable has already been freed");
		return;
	}
	free_fn(var->valptr);
	var->type = NONE;
	var->valptr = NULL;
	free_fn(var);
}

void print_var(Var *ptr){
	switch (ptr->type){
		case STRING: PRINT_VAR(char*, "%s"); break;
		case INTEGER: PRINT_VAR(int, %d); break;
		case DOUBLE: PRINT_VAR(double, %f); break;
		case CHARACTER: PRINT_VAR(char, '%c'); break;
		case U_INTEGER: PRINT_VAR(unsigned int, %u); break;
		default: printf("This variable doesn't exist anymore\n");

	}
}