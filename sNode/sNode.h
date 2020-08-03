#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define sNode type */

typedef struct sNode{
		char *str;
		struct sNode *next;
	}sNode;

void CreateNode();
void RemoveNode();
void PrintNodes();
void free_mem();