#include "list.h"
#include <stdio.h>

void MergeSort(Lnode *head)
{
	if (head->next == NULL)
		return;
	head->next = MergeSortCore(head->next);
}

Lnode *MergeSortCore(Lnode *head)
{
	if (head->next == NULL)
		return head;

	Lnode *slow, *fast;
	slow = head;
	fast = slow->next;
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) { 
			slow = slow->next;
			fast = fast->next;
		}
	}

	Lnode *righthead;
	righthead = slow->next;
	slow->next = NULL;
	head = MergeSortCore(head);
	righthead = MergeSortCore(righthead);
	return MergeListCore(head, righthead);
}
