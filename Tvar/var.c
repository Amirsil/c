#include "var.h"

void PrintVar(var *ptr){
	switch (ptr->type){
		case STRING: printf("%s\n", *(char**)ptr->valueptr); break;
		case INTEGER: printf("%d\n", *(int*)ptr->valueptr); break;
		case DOUBLE: printf("%f\n", *(double*)ptr->valueptr); break;
		case CHARACTER: printf("%c\n", *(char*)ptr->valueptr); break;
		case UINTEGER: printf("0x%x\n", *(unsigned int*)ptr->valueptr); break;

	}
}
