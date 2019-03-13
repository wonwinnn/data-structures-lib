#include "list.h"
#include <stdio.h>

void QuickSort(Lnode *head, Lnode *left, Lnode *right) //left is head->next, right is null
{
	if ( left != right) {	
		Lnode *p, *q;
		eletype pivot = left->data;	
		p = left;
		q = p->next;
		while (q != right) {
			if (q->data < pivot) {
					p = p->next;
					SwapData(p, q);
			}
			q = q->next;
		}
		SwapData(left, p);
		QuickSort(head, left, p);
		QuickSort(head, p->next, NULL);
	}
}
