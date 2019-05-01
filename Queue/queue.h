#ifndef _QUEUE_H
#define _QUEUE_H

typedef int eletype;

typedef struct record
{
	int capacity;
	int front;
	int rear;
	int size;
	eletype *array;
}Queue;

Queue *CreateQueue(int max);
int isFull(Queue *Q);
void Enqueue(Queue *Q, eletype data);

#endif
