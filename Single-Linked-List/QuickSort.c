#include "list.h"
#include <stdio.h>

Lnode *Partation(Lnode *left, Lnode *right);

//left is head->next, right is null

void QuickSort(Lnode *head, Lnode *left, Lnode *right) 
{
	if ( left != right) {	
		Lnode *par = Partation(left, right);
		QuickSort(head, left, par);
		QuickSort(head, par->next, NULL);
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


//left is head, right is null
/*
void QuickSort(Lnode *head, Lnode *left, Lnode *right)
{
	if (left->next != right) {	
		Lnode *par = Partation(left, right);
		QuickSort(head, left, par);
		QuickSort(head, par, NULL);
	}
}

Lnode *Partation(Lnode *left, Lnode *right)
{
	if (left->next->next == right)
		return left->next;
	
	Lnode *p, *q;
	eletype pivot = left->next->data;	
	p = left->next;
	q = p->next;
	while (q != right) {
		if (q->data < pivot) {
			p = p->next;
			SwapData(p, q);
		}
		q = q->next;
	}
	SwapData(left->next, p);
	return p;
}
*/
