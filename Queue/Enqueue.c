#include "queue.h"
#include <stdio.h>

static int Succ(Queue *Q, int value)
{
	if(++value == Q->capacity)
		value = 0;
	return value;
}

void Enqueue(Queue *Q, eletype data)
{
	if (isFull(Q)) {
		printf("The queue is full!\n");
	}
	else {
		Q->size++;
		Q->rear = Succ(Q, Q->rear);
		Q->array[Q->rear] = data;
	}
}
