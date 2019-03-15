#ifndef _LIST_H
#define _LIST_H

typedef int eletype;

typedef struct node
{
	eletype data;
	struct node *next;
}Lnode;

Lnode *CreateList(int n);
void DeleteList(Lnode *head);
void PrintList(Lnode *head);
void BubbleSort(Lnode *head);
void InsertSort(Lnode *head);
void SwapData(Lnode *p, Lnode *q);
void QuickSort(Lnode *head, Lnode *left, Lnode *right);
Lnode *MergeList(Lnode *head1, Lnode *head2);
Lnode *MergeListCore(Lnode *head1, Lnode *head2);
void MergeSort(Lnode *head);
Lnode *MergeSortCore(Lnode *head);

#endif
