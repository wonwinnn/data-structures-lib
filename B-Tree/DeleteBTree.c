#include <stdlib.h>
#include "btree.h"

void DeleteBTree(BTnode *x)
{
	free(x->key);
	x->key = NULL;

	if (!x->leaf) {
		for (int i = 0; i <= x->key_num; i++) {
			DeleteBTree(x->children[i]);
		}
		free(x->children);
		x->children = NULL;
	}

	free(x);
	x = NULL;
}