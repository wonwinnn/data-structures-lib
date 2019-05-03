#ifndef _STACK_H
#define _STACK_H

typedef int eletype;

typedef struct node
{
		eletype data;
		struct node *next;
}Stack;

Stack *CreateStack();
void DeleteStack(Stack *S)
void Pop(Stack *S);
void Push(Stack *S, eletype data);

#endif
