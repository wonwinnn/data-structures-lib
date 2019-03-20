#include "tree.h"
#include <stdio.h>

void PreOrderPrint(Tnode *root) 
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	PreOrderPrint(root->lchild);
	PreOrderPrint(root->rchild);
}
	
