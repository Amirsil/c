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
	allocate and deallocate are exported init functions for allocating and deallocating memory on your own custom heap,
	you can set it to &malloc and &free if you still want to use glibc's general purpose allocator
*/