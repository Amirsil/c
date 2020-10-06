#include "var.h"

#define PRINT_VAR(var_type, format) printf(""#format" (%p)\n", *(var_type*)ptr->valptr, ptr->valptr)

#define ALLOC_VAL(var_type, enum_type, new_size)\
	do { \
		void *valptr; \
		const size_t old_size = (STRING == ptr->type) ? strlen(*(char**)ptr->valptr) : sizeof(*(var_type*)ptr->valptr); \
		if (ptr->valptr) { /* valptr is not NULL, therefore a var already exist and holds some kind of value and type */ \
			if (STRING == ptr->type) \
				free_fn(*(char **)ptr->valptr); /* Freeing the string allocated by strdup before replacing value*/ \
			if (new_size == old_size) \
				valptr = ptr->valptr; \
			else { \
				free_fn(ptr->valptr); \
				if (!(valptr = malloc_fn(new_size))) { \
					fputs("Failed to allocate memory, cancelling\n", stderr); \
					return; \
				} \
			} \
		} \
		else if (!(valptr = malloc_fn(new_size))) { \
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
	if (STRING == ptr->type) {
		free_fn(*(char **)ptr->valptr);
	}
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