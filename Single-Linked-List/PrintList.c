#include "list.h"
#include <stdio.h>

void PrintList(Lnode *head) //Print list form head to end
{
	Lnode *current;
	if (head->next == NULL)
		printf("The list is empty.\n");
	else {
		current = head->next;
		while (current != NULL) {
			printf("%d\n", current->data);
			current = current->next;
		}
	}
}
