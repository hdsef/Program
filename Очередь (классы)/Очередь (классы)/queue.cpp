#include "stdafx.h"
#include "queue.h"


queue::queue()
{
}


queue::~queue()
{
}

void queue::push(List* list, int x)
{
	Node* note = new Node;
	note->val = x;
	note->right = list->tleft;
	if (list->tleft != 0)
		list->tleft->left = note;
	list->tleft = note;
	if (list->tright == NULL)
	{
		list->tright = note;
	}
	list->size++;
}

void queue::printlist(List* list)
{
	Node* temp = list->tleft;
	while (temp != 0)
	{
		printf_s("%d ", temp->val);
		temp = temp->right;
	}
	printf_s("\n");
}

int queue::pop(List* list)
{
	Node* temp = list->tright;
	int data = temp->val;
	//printf_s("%d ",temp->val);
	list->tright = list->tright->left;
	list->tright->right = NULL;
	list->size--;
	delete temp;
	return data;
}