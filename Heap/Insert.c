#include "heap.h"
#include <stdio.h>

void Insert(Heap *H,  eletype data)
{
	if (H->size == H->capacity) {
		printf("Heap is full\n");
		return;
	}
	int i;
	for (i = ++H->size; data < H->arr[i / 2]; i /= 2 )
		H->arr[i] = H->arr[i / 2]; //precolate up
	H->arr[i] = data;
}
