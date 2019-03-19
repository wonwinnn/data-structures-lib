#include "list.h"
#include <stdio.h>

void ReverseList(Lnode *head)
{
	if (head == NULL || head->next == NULL || head->next->next == NULL)
		return;
	Lnode *prev, *current, *s;
	current = head->next;
	prev = NULL;
	while (current != NULL) {
		s = current->next;
		current->next = prev;
		prev = current;
		current = s;
	}
	head->next = prev;
}
