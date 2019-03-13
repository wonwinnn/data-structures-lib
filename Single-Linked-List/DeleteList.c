#include "list.h"
#include <stdlib.h>

void DeleteList(Lnode *head) //Delete list
{
	Lnode *current, *tmp;
	current = head->next;
	head->next = NULL;
	while (current != NULL) {
		tmp = current->next;
		free(current);
		current = tmp;
	}
	//If just want to clear the list, do not free(head)
	free(head); //Forget to free head can lead to memory leakage.
}
