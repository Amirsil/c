#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct node_t{
		const char *str;
		struct node_t *next;

	}node_t;

void FreeList(node_t **ptr);
void RemoveNode(node_t **ptr, const char *str);
void PrintNodes(node_t **ptr);
void CreateNode(node_t **ptr, const char *str); 

void *(*malloc_fn)(size_t size);
void (*free_fn)(void *ptr);
/*
The allocator is defaulted to glibc's general purpose allocator, to change it to your own custom allocator simply change malloc_fc and free_fn
*/	