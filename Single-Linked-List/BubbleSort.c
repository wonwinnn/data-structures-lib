#include "list.h"
#include "stdio.h"

void BubbleSort(Lnode *head)
{
	Lnode *current, *prev, *tmp;
	current = head;
	int n = 0;
	while (current != NULL) { //Find length of the list, length = n
		n++;
		current = current->next;
	}
	for (int i = 0; i < n; i++) { //n-1 cycles
		prev = head; //Every cycle begins from head
		current = head->next;
		for (int j = n - 1- i; j > 0; j--) { //n-1-i comparisons in every cycle
			if (current->next != NULL && current->data > current->next->data) {
				tmp = current->next;
				prev->next = tmp;
				current->next = tmp->next;
				tmp->next = current;
				prev = tmp;
			}
			else {
				prev = current;
				current = current->next;
			}
		}
	}
}

