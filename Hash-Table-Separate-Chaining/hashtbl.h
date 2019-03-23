#ifndef _HASHTBL_H
#define _HASHTBL_H

typedef char * eletype; //use string as eletype
typedef unsigned int uint;

typedef struct node
{
	eletype data;
	struct node *next;
}Lnode;

typedef Lnode * pLnode;

typedef struct table
{
	int size;
	pLnode *pList;
}Htable;

int NextPrime(int N);
Htable *CreateHashTable(int tsize);
uint Hash(Htable *H, const char *key);
Lnode *Find(Htable *H, eletype key);
void Insert(Htable *H, eletype key);


#endif
