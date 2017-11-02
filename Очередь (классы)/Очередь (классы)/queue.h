#pragma once
struct Node {
	int val;
	struct Node* right = 0;
	struct Node* left = 0;
};
struct List {
	int size = 0;
	Node* tright = 0;
	Node* tleft = 0;
};

class queue
{
public:
	queue();
	~queue();
	void push(List* list, int x);
	void printlist(List* list);
	int pop(List* list);
};

