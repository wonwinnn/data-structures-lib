#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"

static void SplitChild(BTnode *x, int i)
{
	BTnode *z = malloc(sizeof(BTnode));
	if(!z) {
		printf("failed %s %d \r\n", __func__, __LINE__);
		return;
	}

	BTnode *y = x->children[i];
	z->leaf = y->leaf;
	z->key_num = MIN_DEGREE - 1;
	z->key = malloc(sizeof(eletype) * z->key_num);
	if (!z->key) {
		printf("failed %s %d \r\n", __func__, __LINE__);
		return;
	}
	if (!z->leaf) {
		z->children = malloc(sizeof(BTnode *) * (z->key_num + 1));
		if (!z->children) {
			printf("failed %s %d \r\n", __func__, __LINE__);
			return;
		}
	}
	else
		z->children = NULL;
	
	for(int j = 0; j < MIN_DEGREE - 1; j++)
		z->key[j] = y->key[j + MIN_DEGREE];
	
	if(y->leaf == false) {
		for(int j = 0; j < MIN_DEGREE; j++)
			z->children[j] = y->children[j + MIN_DEGREE];
	}

	y->key_num = MIN_DEGREE - 1;

	eletype *key_temp = x->key;
	x->key = realloc(x->key, sizeof(eletype) * (x->key_num + 1));
	if (!x->key) {
		free(key_temp);
		printf("failed %s %d \r\n", __func__, __LINE__);
		return;
	}
	BTnode **children_temp = x->children;
	x->children = realloc(x->children, sizeof(BTnode *) * (x->key_num + 2));
	if (!x->children) {
		free(children_temp);
		printf("failed %s %d \r\n", __func__, __LINE__);
		return;
	}

	for(int j = x->key_num; j >= i + 1; j--)
		x->children[j + 1] = x->children[j];
	x->children[i + 1] = z;

	for(int j = x->key_num - 1; j >= i; j--)
		x->key[j + 1] = x->key[j];
	x->key[i] = y->key[MIN_DEGREE - 1];	

	x->key_num++;

	key_temp = y->key;
	y->key = realloc(y->key, sizeof(eletype) * y->key_num);
	if(!y->key) {
		free(key_temp);
		printf("failed %s %d \r\n", __func__, __LINE__);
		return;
	}
	if (!y->leaf) {
		children_temp = y->children;
		y->children = realloc(y->children, sizeof(BTnode *) * (y->key_num + 1));
		if (!y->children) {
			free(children_temp);
			printf("failed %s %d \r\n", __func__, __LINE__);
			return;
		}
	}
}

static void InsertNonFull(BTnode *x, eletype k)
{
	int i = x->key_num - 1;

	if(x->leaf) {
		eletype *key_temp = x->key;
		x->key = realloc(x->key, sizeof(eletype) * (x->key_num + 1));
		if (!x->key) {
			free(key_temp);
			printf("failed %s %d \r\n", __func__, __LINE__);
			return;
		}
		while(i >= 0 && k < x->key[i]) {
			x->key[i + 1] = x->key[i];
			i--;
		}
		x->key[i + 1] = k;
		x->key_num = x->key_num + 1;
	}
	else {
		while (i >= 0 && k < x->key[i]) {
			i--;
		}
		i = i + 1;
		if(x->children[i]->key_num == 2 * MIN_DEGREE - 1) {
			SplitChild(x, i);
			if(k > x->key[i])
				i = i + 1;
		}
		InsertNonFull(x->children[i], k);
	}
}

BTnode *Insert(BTnode *root, eletype data)
{	
	BTnode *Troot = root;
	if(!root) {
		printf("failed %s %d \r\n", __func__, __LINE__);
		return Troot;
	}

	BTnode *r = Troot;
	if(r->key_num == 2 * MIN_DEGREE - 1) {
		BTnode *s = malloc(sizeof(BTnode));
		if(NULL == s) {
			printf("failed %s %d \r\n", __func__, __LINE__);
			return Troot;
		}
		Troot = s;
		s->leaf = false;
		s->key_num = 0;
		s->key = NULL;
		s->children = malloc(sizeof(BTnode *));
		s->children[0] = r;
		SplitChild(s,0);
		InsertNonFull(s, data);
	}
	else
		InsertNonFull(r, data);

	return Troot;
}
