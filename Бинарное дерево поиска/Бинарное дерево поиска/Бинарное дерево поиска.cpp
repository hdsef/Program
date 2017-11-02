// Бинарное дерево поиска.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BST.h"

int main()
{
	BST tree;
	tree.isEmpty();
	tree.Add(5);
	tree.Add(3);
	tree.Add(7);
	tree.isEmpty();
	tree.search(3);
    return 0;
}

