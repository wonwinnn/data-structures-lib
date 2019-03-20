#include "tree.h"
#include <stdlib.h>

void DeleteTree(Tnode *root)
{
	if (root == NULL)
		return;
	DeleteTree(root->lchild);
	DeleteTree(root->rchild);
	root->lchild = root->rchild = NULL;
	free(root);
}
