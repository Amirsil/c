#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* define sNode type */

typedef struct sNode{
		char *str;
		struct sNode *next;
	}sNode;

sNode *CreateNode(sNode *ptr, char *str)
{
	sNode *newptr = (sNode *)malloc(sizeof(*ptr));
	*newptr = (sNode){str, ptr};
    printf("Allocated 0x%x (\"%s\")\n", newptr, newptr -> str);
	return newptr;
}

sNode *RemoveNode(sNode *ptr, char *str)
{
	sNode *nextptr = ptr -> next;
	if (!strcmp(nextptr -> str, str))
	{
		ptr -> next = ptr -> next -> next;
		printf("Freeing 0x%x (\"%s\")\n", nextptr, nextptr -> str);
		free(nextptr);
	}
	else 
		RemoveNode(ptr -> next, str);
}

void PrintNodes(sNode *ptr)
{
	while (ptr -> next)
	{
		printf("\"%s\" is located in 0x%x\n", ptr -> str, ptr);
		ptr = ptr -> next;
	}
}
void free_mem(sNode *ptr)
{
	if (ptr -> next)
	{
		printf("Freeing 0x%x (\"%s\")\n", ptr, ptr -> str);
		free_mem(ptr -> next);
		free(ptr);
	}
}

int main(void)
{
	sNode *ptr;
	sNode first = {"hi", NULL};


	ptr = &first;

	ptr = CreateNode(ptr, "x");
	ptr = CreateNode(ptr, "y");
	ptr = CreateNode(ptr, "z");
	PrintNodes(ptr);
	ptr = CreateNode(ptr, "cool");
	PrintNodes(ptr);
	RemoveNode(ptr, "x");
	PrintNodes(ptr);
	RemoveNode(ptr, "z");
	PrintNodes(ptr);
	free_mem(ptr);

}