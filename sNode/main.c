#include "sNode.c"

int main(void)
{
	sNode *node = NULL;
	CreateNode(&node, "z", &malloc, &free);
	CreateNode(&node, "B", &malloc, &free);
	PrintNodes(&node);
	RemoveNode(&node, "z");
	CreateNode(&node, "BBB", &malloc, &free);
	PrintNodes(&node);
	FreeList(&node);
}