#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void Pop(Stack *S)
{
	Stack *first;
	if (S->next == NULL) {
		printf("Empty stack\n");
		return;
	}
	else {
		first = S->next;
		S->next = S->next->next;
		free(first);
	}
}
