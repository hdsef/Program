#include "stdafx.h"
#include "list.h"



link_list::link_list()
{
}

void link_list::delete_list_ins(List* list) {
	list->tright = 0;
	while (list->tleft != 0)
	{
		Node *temp = 0;
		temp = list->tleft;
		list->tleft = list->tleft->right;
		delete temp->acc;
		delete temp;
	}
}

bool link_list::originality(List* list, std::string key, int bal) {
	bool flag = 0;
	if (list->tleft && list->tright != 0) {
		Node* tmp = 0;
		tmp = list->tleft;
		while(tmp!=0)
		{
			if (tmp->hash == function.get_md5(key)) {
				flag = 1;
				tmp->acc->balance = bal;
			}
			tmp = tmp->right;
		}
	}
	return flag;
}

void link_list::put_ins(List* list, std::string key, int bal) {//put добавляет справа
	if (originality(list, key, bal)==0) {
		Node* note = new Node;
		note->key = key;
		note->hash = function.get_md5(key);
		note->acc = new Account;
		note->acc->balance = bal;
		note->left = list->tright;
		if (list->tright != 0)
			list->tright->right = note;
		list->tright = note;
		if (list->tleft == NULL) {
			list->tleft = note;
		}
		list->size++;
	}
}

void link_list::printkey_ins(List* list)
{
	Node* temp = (*list).tleft;
	while (temp != 0)
	{
		std::cout << temp->key;
		printf_s(" ");
		temp = (*temp).right;
	}
	printf_s("\n");
}

void link_list::printbalance_ins(List* list)
{
	Node* temp = (*list).tleft;
	while (temp != 0)
	{
		printf_s("%d ", temp->acc->balance);
		temp = (*temp).right;
	}
	printf_s("\n");
}

void link_list::delete_node_ins(List* list, std::string key) 
{
	bool flag = 0;
	if (list->tleft && list->tright != 0) {
		Node* tmp = 0;
		tmp = list->tleft;
		while (tmp != 0 && flag==0)
		{
			if (flag == 0) {
				if (tmp->key == key) {
					flag = 1;
					tmp->left->right = tmp->right;
					tmp->right->left = tmp->left;
					delete tmp->acc;
					delete tmp;
				}
			}
			if(flag == 0)
			tmp = tmp->right;
		}
	}
}

int link_list::get_ins(List* list, std::string key) 
{
	if (list->tleft && list->tright != 0) {
		Node* tmp = 0;
		tmp = list->tleft;
		while (tmp != 0)
		{
			if (tmp->key == key) {
				return tmp->acc->balance;
			}
				tmp = tmp->right;
		}
	}
}
// wrappers
void link_list::delete_list() {
	delete_list_ins(tabl);
}

void link_list::put(std::string key, int bal) {
	put_ins(tabl, key, bal);
}

void link_list::printbalance() {
	printbalance_ins(tabl);
}

void link_list::printkey() {
	printkey_ins(tabl);
}

void link_list::delete_node(std::string key) {
	delete_node_ins(tabl, key);
}

int link_list::get(std::string key) {
	return get_ins(tabl, key);
}

link_list::~link_list()
{
	delete_list();
	delete tabl;
}
