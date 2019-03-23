#include "hashtbl.h"
#include <stdlib.h>
#include <stdio.h>

void Insert(Htable *H, eletype key)
{
	Lnode *pos, *Lhead, *s;
	pos = Find(H, key);
	if (pos == NULL) {
		s = malloc(sizeof(Lnode));
		if (s == NULL) {
			printf("Out of space\n");
			return;
		}
		Lhead = H->pList[Hash(H, key)];
		s->next = Lhead->next; //insert new node from head, old nodes move backward
		s->data = key; //should use strcpy, however strcpy is unsafe
		Lhead->next = s;
	}
}
