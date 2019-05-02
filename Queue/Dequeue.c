#include "queue.h"
#include <stdio.h>

void Dequeue(Queue *Q)
{
	if (isEmpty(Q)) 
		printf("The queue is Empty\n");
	else {
		Q->size--;
		Q->front = Succ(Q, Q->front);
	}
}
