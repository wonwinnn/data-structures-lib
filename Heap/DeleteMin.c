#include "heap.h"
#include <stdio.h>

eletype DeleteMin(Heap *H)
{
	if (H->size == 0) {
		printf("Heap is empty\n");
		return 0;
	}
	eletype min = H->arr[1];
	eletype last = H->arr[H->size--]; //--!
	int i, child;
	for(i = 1; i * 2 <= H->size; i = child) {
		//Find smaller child
		child = i * 2;
		if (child != H->size && H->arr[child + 1] < H->arr[child])
			child++;
		//precolate one leve
		if (last > H->arr[child])
			H->arr[i] = H->arr[child];
		else
			break;
	}
	H->arr[i] = last;
	return min;
}
