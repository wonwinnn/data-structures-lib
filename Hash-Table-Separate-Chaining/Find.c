#include "hashtbl.h"
#include <string.h>

Lnode *Find(Htable *H, eletype key)
{
	Lnode *Lhead, *current;
	Lhead = H->pList[Hash(H, key)];
	current = Lhead->next; //Lhead->next is NULL, initialized in CreateHashTable()
	while (current != NULL && strcmp(current->data, key) != 0) //eletype is string, use strcmp!
		current = current->next;
	return current;
}
