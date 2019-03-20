#include "tree.h"
#include <stdlib.h>

Tnode *Find(Tnode *root, eletype data)
{
	if (root == NULL)
		return NULL;
	if (data < root->data)
		return Find(root->lchild, data);
	if (data > root->data)
		return Find(root->rchild, data);
	if (data == root->data)
		return root;
}
