#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

BTnode *CreateBTree(void)
{
	BTnode *root = NULL;
	root = malloc(sizeof(BTnode));
	if(!root) {
		printf("failed %s %d \r\n", __func__, __LINE__);
		return NULL;
	}

	root->leaf = true;
	root->key_num = 0;
	root->key = NULL;
	root->children = NULL;

	return root;	
}