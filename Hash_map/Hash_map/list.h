#pragma once
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <string>
#include "MD5.h"
struct Node {
	std::string key;
	struct Node* right = 0;
	struct Node* left = 0;
	struct Account* acc = 0;
	std::string hash;
};
struct List {
	int size = 0;
	Node* tright = 0;
	Node* tleft = 0;
};
struct Account {
	int balance = 0;
};

class link_list
{
private:
	MD5 function;
	List* tabl = new List;
	bool originality(List* list, std::string key, int bal);
	void put_ins(List* list, std::string key, int bal);
	void printkey_ins(List* list);
	void printbalance_ins(List* list);
	void delete_list_ins(List* list);
	void delete_node_ins(List* list, std::string key);
	int get_ins(List* list, std::string key);
public:
	link_list();
	~link_list();
	void put(std::string key, int bal);
	void printkey();
	void printbalance();
	void delete_list();
	void delete_node(std::string key);
	int get(std::string key);
};

