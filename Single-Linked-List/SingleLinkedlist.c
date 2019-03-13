#include <stdio.h>
#include <stdlib.h>

typedef int eletype;

typedef struct node
{
	eletype data;
	struct node *next;
}Lnode;

Lnode *CreateList(int n) //Create a single linkedlist with n elements
{
	Lnode *head, *current, *s;
	head = (Lnode*)malloc(sizeof(Lnode));
	current = head;
	for (int i = 0; i < n; i++) {
		s = (Lnode*)malloc(sizeof(Lnode));
		s->data = 100 - i;
		current->next = s;
		current = s;
	}
	current->next = NULL;
	return head;
}

void DeleteList(Lnode *head) //Delete list
{
	Lnode *current, *tmp;
	current = head->next;
	head->next = NULL;
	while (current != NULL) {
		tmp = current->next;
		free(current);
		current = tmp;
	}
	//If just want to clear the list, do not free(head)
	free(head); //Forget to free head can lead to memory leakage.
}

void PrintList(Lnode *head) //Print list form head to end
{
	Lnode *current;
	if (head->next == NULL)
		printf("The list is empty.\n");
	else {
		current = head->next;
		while (current != NULL) {
			printf("%d\n", current->data);
			current = current->next;
		}
	}
}

Lnode *Find(Lnode *head, eletype e)
{
	Lnode *current = head;
	while (current != NULL && current->data != e)
		current = current->next;
	return current;
}

Lnode *FindPrev(Lnode *head, eletype e)
{
	Lnode *current = head;
	while (current->next != NULL && current->next->data != e)
		current = current->next;
	return current;
}

void swap(Lnode *head, eletype e1, eletype e2)
{
	Lnode *p1, *p2, *c1, *c2, *tmp;
	p1 = FindPrev(head, e1);
	p2 = FindPrev(head, e2);
	c1 = Find(head,e1);
	c2 = Find(head, e2);
	if (c1 == c2)
		return;
	p1->next = c2;
	tmp = c1->next;
	c1->next = c2->next;
	p2->next = c1;
	c2->next = tmp;
}

void BubbleSort(Lnode *head)
{
	Lnode *current, *prev, *tmp;
	current = head;
	int n = 0;
	while (current != NULL) { //Find length of the list, length = n
		n++;
		current = current->next;
	}
	for (int i = 0; i < n; i++) { //n-1 cycles
		prev = head; //Every cycle begins from head
		current = head->next;
		for (int j = n - 1- i; j > 0; j--) { //n-1-i comparisons in every cycle
			if (current->next != NULL && current->data > current->next->data) {
				tmp = current->next;
				prev->next = tmp;
				current->next = tmp->next;
				tmp->next = current;
				prev = tmp;
			}
			else {
				prev = current;
				current = current->next;
			}
		}
	}
}

void InsertSort(Lnode *head)
{
	Lnode *current, *prev, *tail;
	prev = current = tail = head;
	while (tail->next != NULL) {
		prev = head;
		current = tail->next; //current is the begin of unsorted part
		while (prev->next != current && prev->next->data < current->data) 
			prev = prev->next; //Find minimum in sorted elements
		if (prev != tail) { //There exists an element in sorted part which is bigger than curren
			tail->next = current->next;
			current->next = prev->next;
			prev->next = current;
		}
		else //Every sorted element is smaller than current
			tail = current; //tail is the end of sorted part
	}	
}	
			
				
int main()
{
	Lnode *List = CreateList(10);
	PrintList(List);
	//BubbleSort(List);
	InsertSort(List);
	PrintList(List);
	DeleteList(List);
	return 0;
}
