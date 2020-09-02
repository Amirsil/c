#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNode{
		char *str;
		struct sNode *next;
	}sNode;

void CreateNode();
void RemoveNode();
void PrintNodes();
void free_mem();