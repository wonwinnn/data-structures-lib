#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue *CreateQueue(int max)
{
	Queue *Q;

	Q = malloc(sizeof(Queue));
		if (Q == NULL) {
			printf("Create queue failed\n");
			return NULL;
	}
	
	Q->capacity = max;
	Q->front = 1;
	Q->rear = 0;
	Q->size = 0;
	Q->array = malloc(sizeof(int) * max);
	if (Q == NULL) {
		printf("Create queue array failed\n");
		return NULL;
	}

	return Q;	
}
