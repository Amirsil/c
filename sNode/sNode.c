#include "sNode.h"

void CreateNode(sNode **ptr, const char *str, void* (*allocate)(size_t), void (*deallocate)(void *))
{
	sNode *newptr;
	if (!( newptr = (sNode *)allocate(sizeof(sNode)))) printf("Failed to allocate memory in the heap :(");
	if (*ptr) *newptr = (sNode){str, *ptr, deallocate};
	else *newptr = (sNode){str, NULL, deallocate};
	printf("Added \"%s\" (%p)\n", newptr -> str, newptr);
	*ptr = newptr;
}


void RemoveNode(sNode **ptr, const char *str)
{
	sNode *node = *ptr;
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

	sNode *nextptr;	
	for (sNode *node = *ptr ; node -> next ; node = node -> next)
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

void PrintNodes(sNode **ptr)
{
	printf("[");
	for (sNode *node = *ptr; node ; node = node -> next) printf("\"%s\" -> ", node -> str);
	printf("NULL]\n");
	return;
}

void FreeList(sNode **ptr)
{
	sNode tmp;
	sNode *node = *ptr;
	while(node)
	{
		tmp = *node;
		void (*deallocate)(void *) = node -> deallocate; 
		printf("Freed \"%s\" (%p) \n", node -> str, ptr);
		deallocate(node);
		node = tmp.next;
	}
}
