#ifndef _TREE_H
#define _TREE_H

typedef int eletype;

typedef struct node
{
	eletype data;
	struct node *lchild;
	struct node *rchild;
}Tnode;

Tnode *CreateTree(eletype data);
Tnode *Insert(Tnode *root, eletype data);
//void Insert(Tnode **root, eletype data); //using **pointer
void PreOrderPrint(Tnode *root);
void InOrderPrint(Tnode *root);
void PostOrderPrint(Tnode *root);
Tnode *Find(Tnode *root, eletype data);
Tnode *FindMin(Tnode *root);
Tnode *DeleteNode(Tnode *root, eletype data);
void DeleteTree(Tnode *root);

#endif
