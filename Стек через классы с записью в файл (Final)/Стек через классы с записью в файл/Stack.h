#pragma once
typedef struct node_s {
	int data;
	struct node_s *prev;
} node;

typedef struct top_s {
	struct node_s *top;
} top;

class Stack
{
public:
	Stack();
	~Stack();
	void push(top* data, int val);
	int pop(top* data);
};

