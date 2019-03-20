#include "tree.h"
#include <stdlib.h>
#include <stdio.h>	

Tnode *CreateTree(eletype data)
{
	Tnode *root;
	root = malloc(sizeof(Tnode));
	if (!root)
		printf("Create tree failed.");
	root->data = data;
	root->lchild = NULL;
	root->rchild = NULL;	
}
