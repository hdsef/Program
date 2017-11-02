#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "Stack.h"


Stack::Stack()
{
}


Stack::~Stack()
{
}

void Stack::push(top* item, int val) {
	node* elem = new node;
	elem->data = val;
	if (item->top != 0)
		elem->prev = item->top;
	else
		elem->prev = 0;
	item->top = elem;
}

int Stack::pop(top* item) {
	if (item != 0)
	{
		int tmp = item->top->data;
		node *stack = item->top;
		item->top = item->top->prev;
		delete(stack);
		return tmp;
	}
}