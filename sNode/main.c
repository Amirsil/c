#include "sNode.c"

int main(void)
{
	
	sNode *node = NULL;
	CreateNode(&node, "z");
	CreateNode(&node, "B");
	PrintNodes(&node);
	RemoveNode(&node, "z");
	CreateNode(&node, "BBB");
	PrintNodes(&node);
	free_mem(&node);
}