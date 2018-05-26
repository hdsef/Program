#pragma once
#include <iostream>
#include <iomanip>
template <typename T>
struct Node
{
	T data;
	Node *prev=nullptr;
};

template <typename T>
class Stack
{
private:
	Node <T> *top = nullptr;
	int size = 0;
public:
	Stack();
	~Stack();
	void push(const T cont);
	T pop();
};

template <typename T>
Stack<T>::Stack() {

};

template <typename T>
Stack<T>::~Stack() {
};

template <typename T>
void Stack<T>::push(const T cont) {
	if (size == 0) {
		Node <T> *temp = new Node <T>;
		top = temp;
		temp->data = cont;
		temp->prev = 0;
	}
	else {
		Node <T> *temp = new Node <T>;
		temp->data = cont;
		temp->prev = top;
		top = temp;
	}
	size++;
}

template <typename T>
T Stack<T>::pop() {
	size--;
	T val = top->data;
	Node <T> *tmp = top;
	top = top->prev;
	delete tmp;
	return val;
};