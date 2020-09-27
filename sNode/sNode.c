#include "sNode.h"

void CreateNode(node_t **ptr, const char *str, void* (*allocate)(size_t), void (*deallocate)(void *))
{
	node_t *newptr;
	if (!( newptr = (node_t *)allocate(sizeof(node_t)))) printf("Failed to allocate memory in the heap :(");
	if (*ptr) *newptr = (node_t){str, *ptr, deallocate};
	else *newptr = (node_t){str, NULL, deallocate};
	printf("Added \"%s\" (%p)\n", newptr -> str, newptr);
	*ptr = newptr;
}


void RemoveNode(node_t **ptr, const char *str)
{
	node_t *node = *ptr;
	if (!node)
		return;
	
	if (!strcmp(node -> str, str))
	{
		if (!(node -> next)) *ptr = NULL;
		else  *ptr = node -> next;
		printf("Removed \"%s\" (%p)  1\n", node -> str, node);
		free(node);
		return;
	}

	node_t *nextptr;	
	for (node_t *node = *ptr ; node -> next ; node = node -> next)
	{
		nextptr = node -> next;
		void (*deallocate)(void *) = nextptr -> deallocate;
		if (!strcmp(nextptr -> str, str))
		{
			if (node -> next -> next)
				node -> next = node -> next -> next;
			else
				node -> next = NULL;
			printf("Removed \"%s\" (%p)\n", nextptr -> str, nextptr);
			deallocate(nextptr);
			return;
		}

	}
	printf("\"%s\" is not in the list, therefore it cannot be removed.", str);
}

void PrintNodes(node_t **ptr)
{
	printf("[");
	for (node_t *node = *ptr; node ; node = node -> next) printf("\"%s\" -> ", node -> str);
	printf("NULL]\n");
	return;
}

void FreeList(node_t **ptr)
{
	node_t tmp;
	node_t *node = *ptr;
	while(node)
	{
		tmp = *node;
		void (*deallocate)(void *) = node -> deallocate; 
		printf("Freed \"%s\" (%p) \n", node -> str, ptr);
		deallocate(node);
		node = tmp.next;
	}
}
