#include "btree.h"
#include <stdlib.h>
#define ARRAY_SIZE 10

int main(void)
{

	eletype arr[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++)
		arr[i] = i;


	BTnode *btree = CreateBTree();

	for(int i = 0; i < ARRAY_SIZE; i++)
		btree = Insert(btree, arr[i]);

	InOrderPrint(btree);
	DeleteBTree(btree);

	return 0;
}
