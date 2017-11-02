#pragma once
#include <iostream>
#include <queue>

typedef struct node_s {
	int data;
	struct node_s *left = nullptr;
	struct node_s *right = nullptr;
} node;

class BST
{
private:
	node* root;
	void Add_ins(node *&top, int val);
	void search_ins(node *top, int val);
	void tree_travel(node *top);
	void tree_distruct(node *top);
	bool isEmpty_ins(node *top);
public:
	BST();
	~BST();
	void Add(int val);
	void search(int val);
	bool isEmpty();
};

