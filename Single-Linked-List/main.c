#include "list.h"
#include <stdio.h>

int main()
{
	Lnode *List = CreateList(10);
	PrintList(List);
	//BubbleSort(List);
	//InsertSort(List);
	QuickSort(List);
	PrintList(List);
	DeleteList(List);
	return 0;
}
