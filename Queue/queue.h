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
int Succ(Queue *Q, int value);
void Enqueue(Queue *Q, eletype data);
int isEmpty(Queue *Q);
void Dequeue(Queue *Q);

#endif
