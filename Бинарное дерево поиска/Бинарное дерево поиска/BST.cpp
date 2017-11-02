#include "BST.h"
#include "stdafx.h"


BST::BST()
{
}


BST::~BST()
{
	tree_distruct(root);
}

node* createNode(int val){
	node *item = new node;
	item->data = val;
	return item;
}

//PoC (Proof-of-Concept)
void BST::Add_ins(node *&top, int val) {
	if (top == nullptr) {
		top = createNode(val);
	}
	else {
		if (val > top->data) {
			Add_ins(top->right, val);
		}
		else {
			Add_ins(top->left, val);
		}
	}

}

void BST::Add(int val) {
	Add_ins(root,val);
}

void BST::search_ins(node *top, int val) {
	if (top->data == val) {
		printf_s("Found element - %d", val);
	}
	else {
		if (top->data < val)
			search_ins(top->right, val);
		else
			search_ins(top->left, val);
	}
}

void BST::search(int val) {
	search_ins(root, val);
}

void BST::tree_travel(node *root) {
	if (root == NULL)
	{
		return;
	}
	std::queue <node*> q;
	q.push(root);
	while (!q.empty())
	{
		node* temp = q.front();
		q.pop();
		printf_s("%d ", temp->data);
		if (temp->left != NULL)
			q.push(temp->left);

		if (temp->right != NULL)
			q.push(temp->right);
	}
}

void BST::tree_distruct(node *top){
	if (root == NULL)
	{
		return;
	}
	std::queue <node*> q;
	q.push(root);
	while (!q.empty())
	{
		node* temp = q.front();
		q.pop();

		if (temp->left != NULL)
			q.push(temp->left);

		if (temp->right != NULL)
			q.push(temp->right);
		delete(temp);
	}
}

bool BST::isEmpty_ins(node *top){
	if (top == 0)
		return 1;
	else
		return 0;
}

bool BST::isEmpty() {
	return(isEmpty_ins(root));
}
