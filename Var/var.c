#include "var.h"

void new_var(enum types type, void* valptr, Var *ptr) {
	if (ptr->valptr) free_var(ptr);
	*ptr = (Var){type, valptr};
}
void free_var(Var *ptr){
	free(ptr->valptr);
	ptr->type = NONE;
	ptr->valptr = 0;
}

void print_var(Var *ptr){
	switch (ptr->type){
		case STRING: printf("%s\n", *(char**)ptr->valptr); break;
		case INTEGER: printf("%d\n", *(int*)ptr->valptr); break;
		case DOUBLE: printf("%f\n", *(double*)ptr->valptr); break;
		case CHARACTER: printf("%c\n", *(char*)ptr->valptr); break;
		case UINTEGER: printf("%u\n", *(unsigned int*)ptr->valptr); break;
		case NONE: printf("This var doesn't exist anymore\n");

	}
}

void *intptr(const int val)
{
	void *ptr = malloc(sizeof(val));
	*(int*)ptr = val;
	return ptr;
}
void *doubleptr(const double val)
{
	void *ptr = malloc(sizeof(val));
	*(double*)ptr = val;
	return ptr;
}
void *uintptr(const unsigned int val)
{
	void *ptr = malloc(sizeof(val));
	*(unsigned int*)ptr = val;
	return ptr;
}
void *charptr(const char val)
{
	void *ptr = malloc(sizeof(val));
	*(char*)ptr = val;
	return ptr;

}
void *strptr(const char *val)
{
	void *ptr = malloc(strlen(val));
	*(char**)ptr = strdup(val);
	return ptr;
}

