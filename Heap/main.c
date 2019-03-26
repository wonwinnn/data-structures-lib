#include "heap.h"

#define LEN 10

int main()
{
	Heap *binheap = CreateHeap(LEN);
	Insert(binheap, 5);
	Insert(binheap, 7);
	Insert(binheap, 9);
	Insert(binheap, 6);
	DeleteMin(binheap);
	return 0;
}
