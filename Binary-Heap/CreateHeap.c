#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

Heap *CreateHeap(int max)
{
	Heap *H;
	H = malloc(sizeof(Heap));
	if (H == NULL) {
		printf("Out of space\n");
		return NULL;
	}

	H->arr = malloc(sizeof(eletype) * (max + 1));
	if (H->arr == NULL) {
		printf("Out of space\n");
		return NULL;
	}

	H->capacity = max;
	H->size = 0;
	H->arr[0] = 0;

	return H;
}
