#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct sNode{
		const char *str;
		struct sNode *next;
		void (*deallocate)(void *);

	}sNode;

void FreeList(sNode **ptr);
void RemoveNode(sNode **ptr, const char *str);
void PrintNodes(sNode **ptr);
void CreateNode(sNode **ptr, const char *str, void* (*allocate)(size_t), void (*deallocate)(void *)); 
/* 
	allocate and deallocate are exported init functions for allocating and deallocating memory on your own custom heap,
	you can set it to &malloc and &free if you still want to use glibc's general purpous allocator
*/
