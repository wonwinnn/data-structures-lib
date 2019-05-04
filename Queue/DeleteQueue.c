#include "queue.h"
#include <stdlib.h>

void DeleteQueue(Queue *Q)
{
	if (Q != NULL) {
		free(Q->array);
		free(Q);
	}
		
}
