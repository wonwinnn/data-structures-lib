#include "queue.h"

int main()
{
	Queue *q1 = CreateQueue(10);
	Enqueue(q1, 8);
	Enqueue(q1, 9);
	Dequeue(q1);
	DeleteQueue(q1);

	return 0;
}
