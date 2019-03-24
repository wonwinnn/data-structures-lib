#include "hashtbl.h"

/*uint Hash(Htable *H, const char *key) //const eletype key != const char *key
{
	uint hashval = 0;
	while (*key != '\0')
		hashval = (hashval << 5) + *key++;
	return hashval % H->size;
}
*/

uint Hash(Htable *H, const int key)
{
	uint hashval = 0;
	hashval = key; //a simple hash function
	return hashval % H->size;
}
