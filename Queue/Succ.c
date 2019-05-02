#include "queue.h"

int Succ(Queue *Q, int value)
{
	if(++value == Q->capacity)
		value = 0;
	return value;
}
