#include "tree.h"
#include "stdio.h"

Tnode *FindMax(Tnode *root)
{
	if (root == NULL)
		return NULL;
	Tnode *tmp = root;
	while (tmp->rchild != NULL)
		tmp = tmp->rchild;
	return tmp;
}
