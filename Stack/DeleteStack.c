#include "stack.h"
#include <stdlib.h>

void DeleteStack(Stack *S)
{
	Stack *tmp, *current;
	current = S;
	while (current != NULL) {
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
