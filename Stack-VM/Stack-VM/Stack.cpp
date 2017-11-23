#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "Stack.h"


Stack::Stack()
{
}


Stack::~Stack()
{
	while (s->top != 0) {
		int a = pop();
	}
	delete(s);
}

void Stack::push_ins(top* item, int val) {
	node* elem = new node;
	elem->data = val;
	if (item->top != 0)
		elem->prev = item->top;
	else
		elem->prev = 0;
	item->top = elem;
}

int Stack::pop_ins(top* item) {
	if (item != 0)
	{
		int tmp = item->top->data;
		node *stack = item->top;
		item->top = item->top->prev;
		delete(stack);
		return tmp;
	}
}

bool Stack::isEmpty_ins(top *item) {
	if (item->top == 0)
		return 1;
	else return 0;
}

void Stack::push(int val) {
	push_ins(s, val);
}

int Stack::pop() {
	return pop_ins(s);
}

bool Stack::isEmpty() {
	return isEmpty_ins(s);
}