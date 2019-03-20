#include "tree.h"
#include <stdio.h>

int main()
{
	eletype arr[10] = {50, 30, 40, 20, 10, 90, 0, 60, 70, 80};
	Tnode *Tree1 = CreateTree(arr[0]);
	for (int i = 1; i < 10; i++)
		Insert(Tree1, arr[i]);
	//Insert(Tree1, 75);
	//Insert(&Tree1, 75); //using **pointer
	PreOrderPrint(Tree1);
	printf("\n");
	Tnode *n1 = DeleteNode(Tree1, 30);
	printf("%d\n", n1->data);
	PreOrderPrint(Tree1);
	printf("\n");
	DeleteTree(Tree1);
	return 0;
}

