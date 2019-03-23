#include "hashtbl.h"
#include <stdio.h>

int main()
{
	Htable *Hashtbl = CreateHashTable(10);
	eletype key1 = "hello";
	Insert(Hashtbl, key1);
	Lnode *n = Find(Hashtbl, key1);
	printf("%s\n", n->data);
	return 0;
}
