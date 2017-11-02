#pragma once
#include "stdafx.h"
#include <iostream>
#include <time.h>
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
class link_list
{
private:
	void masssort(int a[], int n);
	void errors();
public:
	link_list();
	~link_list();
	void pushright(List* list, int x);
	void pushleft(List* list, int x);
	void printlist(List* list);
	void vstavka(List* list, int x, int n); //вставка между n и n+1-элементами, крайний левый считать нулевым
	void listsort(List* list);
	void delete_list(List* list);
};

