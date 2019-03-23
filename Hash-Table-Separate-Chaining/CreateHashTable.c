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
	H->pList = malloc(sizeof(pLnode) * H->size);
	
	//I prefer to use pointer rather than using array
	//actually *H->pList is the head of a single-linked list, there are "size" single-linked lists
	pLnode *pLhead; 
	pLhead = H->pList; 
	for (int i = 0; i < H->size; i++) {		
		*pLhead = malloc(sizeof(Lnode));
		if (*pLhead == NULL) {
			printf("Out of space\n");
			return NULL;
		}
		(*pLhead)->next = NULL;
		pLhead++; //!!!!!go to head of next single-linked list 
	}
	
	//using array
	/*
	for (int i = 0; i < H->size; i++) {
		H->pList[i] = malloc(sizeof(Lnode));
		if (H->pList[i] == NULL) {
			printf("Out of space\n");
			return NULL;
		}
		H->pList[i]->next = NULL;
	}
	*/
	return H;
}
