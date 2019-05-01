#include "queue.h"

int isFull(Queue *Q)
{
	return Q->size == Q->capacity;
}
