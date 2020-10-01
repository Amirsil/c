#include "var.h"

#define PRINT_VAR(var_type, format) printf(""#format" (%p)\n", *(var_type*)ptr->valptr, ptr->valptr)

#define OPTIMIZED_REALLOC(var_type, old_size, size) valptr = (size > old_size)\
	? realloc(ptr->valptr, size) : ptr->valptr

#define ALLOC_VAL(var_type, enum_type, size)\
    void *valptr; \
    if (ptr->valptr){ \
    	if (ptr->type == enum_type && ptr->type != STRING) valptr = ptr->valptr;\
		else switch (ptr->type){ \
 			case INTEGER: OPTIMIZED_REALLOC(int, sizeof(int), size); break; \
 			case DOUBLE: OPTIMIZED_REALLOC(double, sizeof(double), size); break; \
 			case CHARACTER: OPTIMIZED_REALLOC(char, sizeof(char), size); break; \
 			case U_INTEGER: OPTIMIZED_REALLOC(unsigned int, sizeof(unsigned int), size); break; \
 			case STRING: OPTIMIZED_REALLOC(char*, strlen(*(char**)ptr->valptr)*sizeof(char), size); break; \
		} \
	} \
	else valptr = malloc_fn(size); \
    *(var_type*)valptr = val; \
    *ptr = (Var){enum_type, valptr}; \

void *(*malloc_fn)(size_t size) = &malloc;
void (*free_fn)(void *ptr) = &free;

void int_var(int val, Var *ptr) {
	ALLOC_VAL(int, INTEGER, sizeof(val))
}
void double_var(double val, Var *ptr) {
	ALLOC_VAL(double, DOUBLE, sizeof(val))
}
void uint_var(unsigned int val, Var *ptr) {
	ALLOC_VAL(unsigned int, U_INTEGER, sizeof(val))
}
void char_var(char val, Var *ptr) {
	ALLOC_VAL(char, CHARACTER, sizeof(val))
}
void str_var(char *val, Var *ptr) {
	val = strdup(val);
	ALLOC_VAL(char*, STRING, strlen(val)*sizeof(char))
}


void free_var(Var *ptr){
	if (ptr->type == NONE) {
		printf("This variable has already been freed");
		return;
	}
	free_fn(ptr->valptr);
	ptr->type = NONE;
	ptr->valptr = 0x0;
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