#ifndef _HEAP_H
#define _HEAP_H

typedef int eletype;

typedef struct heapstruct
{
	int capacity;
	int size;
	eletype *arr; //used for saving data
}Heap;

Heap *CreateHeap(int max);
void Insert(Heap *H, eletype data);
eletype DeleteMin(Heap *H);
#endif
