#include "tree.h"
#include <stdio.h>

void InOrderPrint(Tnode *root) 
{
	if (root == NULL)
		return;
	InOrderPrint(root->lchild);
	printf("%d ", root->data);
	InOrderPrint(root->rchild);
}
	
