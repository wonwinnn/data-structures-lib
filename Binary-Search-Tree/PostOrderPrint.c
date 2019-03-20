#include "tree.h"
#include <stdio.h>

void PostOrderPrint(Tnode *root) 
{
	if (root == NULL)
		return;
	PostOrderPrint(root->lchild);
	PostOrderPrint(root->rchild);
	printf("%d ", root->data);
}
