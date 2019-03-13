#include "list.h"

void SwapData(Lnode *p, Lnode *q)
{
	eletype tmp;
	tmp = p->data;
	p->data = q->data;
	q->data = tmp;
}
