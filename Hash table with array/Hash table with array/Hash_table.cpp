#include "stdafx.h"
#include "Hash_table.h"

Hash_table::Hash_table()
{
	for (int i = 0; i < 256; i++)
		arr[i] = nullptr;
}


Hash_table::~Hash_table()
{
	for (int i = 0; i < 256; i++) {
		Node *temp = arr[i];
		while (temp != nullptr) {
			Node *del = temp;
			temp = del->next;
			delete del;
		}
		arr[i] = nullptr;
	}
}

/*int Hash_table::arr_adr(std::string key) {
	int sum = 0;
	for (int i = 0; i < key.size() - 1; i = i + 1) {
		int m = key[i] * key[i + 1];
		int d = key[i] / key[i + 1];
		sum = sum + m;
		sum = sum + d;
	}
	return sum % 256;
}*/

int Hash_table::arr_adr(std::string key) {
	return 1;
}

void Hash_table::put(std::string key, int val) {
	if (arr[arr_adr(key)] == nullptr) {
		Node *tmp = new Node;
		tmp->key = key;
		tmp->value = val;
		arr[arr_adr(key)] = tmp;
	}
	else {
		bool flag = 0;
		Node *lift = arr[arr_adr(key)];
		while (lift->next != nullptr)
		{
			if (lift->key == key) {
				lift->key = key;
				flag = 1; 
			}
			lift = lift->next;
		}
		if (flag == 0) {
			Node *temp = new Node;
			temp->key = key;
			temp->value = val;
			temp->next = 0;
			lift->next = temp;
		}
	}
}

void Hash_table::delete_n(std::string key) {
	Node *temp = arr[arr_adr(key)];
	while (temp != nullptr) {
		Node *del = temp;
		temp = del->next;
		delete del;
	}
	arr[arr_adr(key)] = nullptr;
}

void Hash_table::get(std::string key) {
	Node *tmp = arr[arr_adr(key)];
	while (tmp != nullptr){
		std::cout << tmp->value << " ";
		tmp = tmp->next;
	}
}

void Hash_table::all_keys() {
	for (int i = 0; i < 256; i++) {
		if (arr[i] != nullptr) {
			Node *temp = arr[i];
			while (temp!=nullptr) {
				std::cout<< temp->key << " ";
				temp = temp->next;
			}
		}
			
	}
}

void Hash_table::all_vals() {
	for (int i = 0; i < 256; i++) {
		if (arr[i] != nullptr) {
			Node *temp = arr[i];
			while (temp != nullptr) {
				std::cout << temp->value << " ";
				temp = temp->next;
			}
		}

	}
}