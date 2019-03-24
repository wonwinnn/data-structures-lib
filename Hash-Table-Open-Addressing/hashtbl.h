#ifndef _HASHTBL_H
#define _HASHTBL_H

//typedef char * eletype;
typedef int eletype;
typedef unsigned int uint;

enum entrykind {Legitimate, Empty, Deleted};

typedef struct cell
{
	eletype data;
	enum entrykind info;
}Hcell;

typedef struct table
{
	int size;
	Hcell *CellArray;
}Htable;

int NextPrime(int N);
Htable *CreateHashTable(int tsize);
//uint Hash(Htable *H, const char *key);
uint Hash(Htable *H, const int key);
uint Find(Htable *H, eletype key);
void Insert(Htable *H, eletype key);

#endif
