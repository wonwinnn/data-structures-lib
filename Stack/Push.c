#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void Push(Stack *S, eletype data)
{
	Stack *tmp;
	tmp = malloc(sizeof(Stack));
	if (tmp == NULL) {
		printf("Out of space\n");
		return;
	}
	else {
		tmp->data = data;
		tmp->next = S->next;
		S->next = tmp;
	}
}
