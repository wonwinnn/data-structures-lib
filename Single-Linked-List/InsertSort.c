#include "list.h"
#include <stdio.h>

void InsertSort(Lnode *head)
{
	Lnode *current, *prev, *tail;
	prev = current = tail = head;
	while (tail->next != NULL) {
		prev = head;
		current = tail->next; //current is the begin of unsorted part
		while (prev->next != current && prev->next->data < current->data) 
			prev = prev->next; //Find minimum in sorted elements
		if (prev != tail) { //There exists an element in sorted part which is bigger than current
			tail->next = current->next;
			current->next = prev->next;
			prev->next = current;
		}
		else //Every sorted element is smaller than current
			tail = current; //tail is the end of sorted part
	}	
}
