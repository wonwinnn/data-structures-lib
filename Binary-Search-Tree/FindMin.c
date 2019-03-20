#include "tree.h"
#include <stdlib.h>

Tnode *FindMin(Tnode *root)
{
	if (root == NULL)
		return NULL;
	else {
		if (root->lchild == NULL)
			return root;
		else
			return FindMin(root->lchild);
	}
}
