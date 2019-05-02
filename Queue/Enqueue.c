#include "queue.h"
#include <stdio.h>

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
