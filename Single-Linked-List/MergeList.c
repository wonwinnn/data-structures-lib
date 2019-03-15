#include "list.h"
#include <stdio.h>
#include <stdlib.h>

Lnode *MergeList(Lnode *head1, Lnode *head2) //Recursive, in place
{
	if (head1->next == NULL) {
		free(head1);
		return head2;
	}
	if (head2->next == NULL) {
		free(head2);
		return head1;
	}

	if (head1->next->data <= head2->next->data) {
		head1->next = MergeListCore(head1->next, head2->next);
		free(head2);
		return head1;
	}
	if (head1->next->data > head2->next->data) {
		head2->next = MergeListCore(head1->next, head2->next);
		free(head1);
		return head2;
	}
}

Lnode *MergeListCore(Lnode *head1, Lnode *head2) 
{
	if (head1 == NULL) 
		return head2;
	if (head2 == NULL)
		return head1;
	
	if (head1->data <= head2->data) {
		head1->next = MergeListCore(head1->next, head2);
		return head1;
	}
	if (head1->data > head2->data) {
		head2->next = MergeListCore(head1, head2->next);
		return head2;
	}
}
		
	
