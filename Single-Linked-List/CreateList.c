#include "list.h"
#include <stdlib.h>

Lnode *CreateList(int n) //Create a single linkedlist with n elements
{
	Lnode *head, *current, *s;
	head = (Lnode*)malloc(sizeof(Lnode));
	current = head;
	for (int i = 0; i < n; i++) {
		s = (Lnode*)malloc(sizeof(Lnode));
		s->data = 100 - i;
		current->next = s;
		current = s;
	}
	current->next = NULL;
	return head;
}
