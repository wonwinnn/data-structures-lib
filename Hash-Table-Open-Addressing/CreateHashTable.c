#include "hashtbl.h"
#include <stdlib.h>
#include <stdio.h>

#define MinSize 10 //assume tablesize >= 10 in NextPrime

Htable *CreateHashTable(int tsize)
{
	Htable *H;

	if (tsize < MinSize) {
		printf("Table size must >= %d\n", MinSize);
		return NULL;
	}

	H = malloc(sizeof(Htable));
	if (H == NULL) {
		printf("Create table failed\n");
		return NULL;
	}
	
	H->size = NextPrime(tsize);
	H->CellArray = malloc(sizeof(Hcell) * H->size);
	if (H->CellArray == NULL) {
		printf("Out of space\n");
		return NULL;
	}

	Hcell *pcell;
	pcell = H->CellArray;
	for (int i = 0; i < H->size; i++) {
		pcell->info = Empty;
		pcell++;
	}

	return H;
}
		
