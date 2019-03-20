#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Tnode *Insert(Tnode *root, eletype data)
{
	if(root == NULL) {
		root = malloc(sizeof(Tnode));
		if (!root)
			printf("Create tree failed.");
		root->data = data;
		root->lchild = NULL;
		root->rchild = NULL;	
	}	
	else {
		if (data < root->data) 
			root->lchild = Insert(root->lchild, data);
		else
			root->rchild = Insert(root->rchild, data);
	}
	
	return root;
}

//using **pointer
/*
void Insert(Tnode **root, eletype data)
{
	if((*root) == NULL) {
		*root = malloc(sizeof(Tnode));
		if (!root)
			printf("Create tree failed.");
		(*root)->data = data;
		(*root)->lchild = NULL;
		(*root)->rchild = NULL;	
	}	
	else {
		if (data < (*root)->data) 
			Insert(&((*root)->lchild), data);
		else
			Insert(&((*root)->rchild), data);
	}
}
*/
