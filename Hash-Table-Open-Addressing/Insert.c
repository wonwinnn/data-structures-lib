#include "hashtbl.h"
//#include <string.h>

void Insert(Htable *H, eletype key)
{
	uint pos;
	pos = Find(H, key);
	if (H->CellArray[pos].info != Legitimate) {
		H->CellArray[pos].info = Legitimate;
		//strcpy(H->CellArray[pos].data, key);
		H->CellArray[pos].data = key;
	}
}
