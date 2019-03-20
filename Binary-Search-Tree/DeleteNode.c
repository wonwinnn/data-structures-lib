#include "tree.h"
#include <stdlib.h>

Tnode *DeleteNode(Tnode *root, eletype data)
{
	if (root == NULL)
		return NULL;
	if (data < root->data)
		root->lchild = DeleteNode(root->lchild, data);
	if (data > root->data)
		root->rchild = DeleteNode(root->rchild, data);
	if (data == root->data) { //Find element to be deleted
		Tnode *tmp;
		if (root->lchild && root->rchild) { //has two children
			tmp = FindMin(root->rchild); //Replace with smallest in right subtree
			root->data = tmp->data;
			root->rchild = DeleteNode(root->rchild, tmp->data); //delete smallest in right subtree
		}
		else { //has one child or no child
			tmp = root;
			if (root->lchild == NULL)
				root = root->rchild;
			else if (root->rchild == NULL)
				root = root->lchild;
			free(tmp);
		}
	}
	return root;
}
