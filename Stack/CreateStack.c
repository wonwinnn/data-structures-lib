#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack *CreateStack()
{
	Stack *S;
	S = malloc(sizeof(Stack));
	if (S == NULL) {
		printf("Out of space\n");
		return NULL;
	}
	while (S->next != NULL)
		Pop(S);
	return S;
}
