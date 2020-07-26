#include <stdio.h>
#include "btree.h"

void InOrderPrint(BTnode *node)
{
	if(node == NULL)
		return;
	int i;
	for(i = 0; i < node->key_num; i++) {
		if(!node->leaf)
			InOrderPrint(node->children[i]);
		printf("%d ", node->key[i]);
	}
	if (!node->leaf)
		InOrderPrint(node->children[i]);
}
