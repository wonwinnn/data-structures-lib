#include "hashtbl.h"
//#include <string.h>

uint Find(Htable *H, eletype key)
{
	uint pos;
	int num = 0; //count collision 
	pos = Hash(H, key);
	while (H->CellArray[pos].info != Empty
			//&& strcmp(H->CellArray[pos].data, key) != 0) { //if data is a string
			&& H->CellArray[pos].data != key) {
		pos += 2 * ++num - 1; //quad probing
		//pos += 1; //linear probing
		if (pos >= H->size)
			pos -= H->size;
	}
	return pos;
}
