#include "hashtbl.h"
#include <stdio.h>

int main()
{
	Htable *Hashtbl = CreateHashTable(10);
	int a[3] = {12, 34, 23};
	for (int i = 0; i < 3; i++)
		Insert(Hashtbl, a[i]);
	Hcell c[Hashtbl->size];
	for (int i = 0; i < Hashtbl->size; i++) 
		c[i] = Hashtbl->CellArray[i];

	return 0;
}
