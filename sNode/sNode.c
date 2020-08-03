
void CreateNode(sNode **ptr, char *str)
{
	sNode *newptr = (sNode *)malloc(sizeof(sNode *));
	if (*ptr) *newptr = (sNode){str, *ptr};
	else *newptr = (sNode){str, NULL};
	printf("Added \"%s\" (0x%x)\n", newptr -> str, newptr);
	*ptr = newptr;
}

void RemoveNode(sNode **ptr, char *str)
{
	sNode *node = *ptr;
	if (!node)
		return;
	
	if (!strcmp(node -> str, str))
	{
		if (!(node -> next)) *ptr = NULL;
		else  *ptr = node -> next;
		printf("Removed \"%s\" (0x%x)  1\n", node -> str, node);
		free(node);
		return;
	}

	sNode *nextptr;	
	for (sNode *node = *ptr ; node -> next ; node = node -> next)
	{
		nextptr = node -> next;
		if (!strcmp(nextptr -> str, str))
		{
			if (node -> next -> next)
				node -> next = node -> next -> next;
			else
				node -> next = NULL;
			printf("Removed \"%s\" (0x%x)\n", nextptr -> str, nextptr);
			free(nextptr);
			return;
		}

	}
}

void PrintNodes(sNode **ptr)
{
	printf("[");
	for (sNode *node = *ptr; node ; node = node -> next) printf("\"%s\" -> ", node -> str);
	printf("NULL]\n");
	return;
}

void free_mem(sNode **ptr)
{
	sNode tmp;
	sNode *node = *ptr;
	while(node)
	{
		tmp = *node;
		printf("Freed \"%s\" (0x%x) \n", node -> str, ptr);
		free(node);
		node = tmp.next;
	}
}