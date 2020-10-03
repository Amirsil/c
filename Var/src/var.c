#include "var.h"

#define PRINT_VAR(var_type, format) printf(""#format" (%p)\n", *(var_type*)ptr->valptr, ptr->valptr)

#define OPTIMIZED_REALLOC(var_type, old_size, size) \
	do { \
		if (size > old_size) { \
			/* When scaling up free/malloc is faster */ \
			free_fn(ptr->valptr); \
			if (!(valptr = malloc_fn(size))) { \
				fputs("Failed to allocate memory, cancelling\n", stderr); \
				return; \
			} \
		} \
		else if (old_size > size){ \
			/* When scaling down realloc is faster */ \
			if (!(valptr = realloc(ptr->valptr, size))) { \
				fputs("Failed to reallocate memory, cancelling\n", stderr); \
				return; \
			} \
		} \
		else valptr = ptr->valptr; \
	} while (0)

#define ALLOC_VAL(var_type, enum_type, size)\
	do { \
		void *valptr; \
		if (ptr->valptr){ /* valptr is not NULL, therefore a var already exist and holds some kind of value and type */ \
			if (STRING == ptr->type ) free_fn(*(char **)ptr->valptr); \
			switch (ptr->type){ \
				case INTEGER: OPTIMIZED_REALLOC(int, sizeof(int), size); break; \
				case DOUBLE: OPTIMIZED_REALLOC(double, sizeof(double), size); break; \
				case CHARACTER: OPTIMIZED_REALLOC(char, sizeof(char), size); break; \
				case U_INTEGER: OPTIMIZED_REALLOC(unsigned int, sizeof(unsigned int), size); break; \
				case STRING: OPTIMIZED_REALLOC(char*, strlen(*(char**)ptr->valptr)*sizeof(char), size); break; \
				case NONE: {}  /* the var type cannot be NONE, because valptr is not NULL */ \
			} \
		} \
		else if (!(valptr = malloc_fn(size))) { \
			fputs("Failed to allocate memory, cancelling\n", stderr); \
			return; \
		} \
		*(var_type*)valptr = val; \
		*ptr = (var_t){enum_type, valptr}; \
	} while(0)

void *(*malloc_fn)(size_t size) = &malloc;
void (*free_fn)(void *ptr) = &free;



void int_var(int val, var_t *ptr) {
	ALLOC_VAL(int, INTEGER, sizeof(val));
}
void double_var(double val, var_t *ptr) {
	ALLOC_VAL(double, DOUBLE, sizeof(val));
}
void uint_var(unsigned int val, var_t *ptr) {
	ALLOC_VAL(unsigned int, U_INTEGER, sizeof(val));
}
void char_var(char val, var_t *ptr) {
	ALLOC_VAL(char, CHARACTER, sizeof(val));
}
void str_var(char *val, var_t *ptr) {
	val = strdup(val);
	ALLOC_VAL(char*, STRING, strlen(val)*sizeof(char));
}

void free_var(var_t *ptr) {
	if (NONE == ptr->type) {
		fputs("This variable has already been freed\n", stderr);
		return;
	}
	if (STRING == ptr->type) free_fn(*(char **)ptr->valptr);
	free_fn(ptr->valptr);
	ptr->type = NONE;
	ptr->valptr = NULL;
}

void print_var(var_t *ptr) {
	switch (ptr->type){
		case STRING: PRINT_VAR(char*, "%s"); break;
		case INTEGER: PRINT_VAR(int, %d); break;
		case DOUBLE: PRINT_VAR(double, %f); break;
		case CHARACTER: PRINT_VAR(char, '%c'); break;
		case U_INTEGER: PRINT_VAR(unsigned int, %u); break;
		default: fputs("This variable doesn't exist anymore\n", stderr);

	}
}