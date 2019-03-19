#include "list.h"
#include <stdio.h>

Lnode *Partation(Lnode *left, Lnode *right);

void QuickSort(Lnode *head, Lnode *left, Lnode *right) //left is head->next, right is null
{
	if ( left != right) {	
		Lnode *p = Partation(left, right);
		QuickSort(head, left, p);
		QuickSort(head, p->next, NULL);
	}
}

Lnode *Partation(Lnode *left, Lnode *right)
{
	if (left == right)
		return left;
	
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
	return p;
}
