#include "sNode.h"

int main(void)
{	
	node_t *node = NULL;
	CreateNode(&node, "z");
	CreateNode(&node, "B");
	PrintNodes(&node);
	RemoveNode(&node, "z");
	CreateNode(&node, "BBB");
	PrintNodes(&node);
	FreeList(&node);
}