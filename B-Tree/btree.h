#ifndef _BTREE_H
#define _BTREE_H

#define MIN_DEGREE 2

typedef enum {false = 0, true = 1} bool;

typedef int eletype;

typedef struct node
{
	bool leaf;
	int key_num;
	eletype *key;
	struct node **children;
}BTnode;

BTnode *CreateBTree(void);
BTnode *Insert(BTnode *root, eletype data);
void InOrderPrint(BTnode *root);
void DeleteBTree(BTnode *x);

#endif