#include "stdafx.h"
#include "Hash_table.h"

Hash_table::Hash_table()
{
	for (int i = 0; i < mass_size; i++)
		arr[i] = nullptr;
}


Hash_table::~Hash_table()
{
	for (int i = 0; i < mass_size; i++) {
		Node *temp = arr[i];
		while (temp != nullptr) {
			Node *del = temp;
			temp = del->next;
			delete del;
		}
		arr[i] = nullptr;
	}
}

int Hash_table::arr_adr(std::string key) {
	int sum = 0;
	for (int i = 0; i < key.size() - 1; i = i + 1) {
		int m = key[i] * key[i + 1];
		int d = key[i] / key[i + 1];
		sum = sum + m;
		sum = sum + d;
	}
	return sum % mass_size;
}

/*int Hash_table::arr_adr(std::string key) {
	return 1;
}*/

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
				lift->value = val;
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
	for (int i = 0; i < mass_size; i++) {
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
	for (int i = 0; i < mass_size; i++) {
		if (arr[i] != nullptr) {
			Node *temp = arr[i];
			while (temp != nullptr) {
				std::cout << temp->value << " ";
				temp = temp->next;
			}
		}

	}
}

void Hash_table::size_change(int n) {
	Node **arr_tmp = new Node*[n];
	for (int i = 0; i < n; i++)
		arr_tmp[i] = nullptr;
	int old_mass_size = mass_size;
	mass_size = n;
	for (int i = 0; i < old_mass_size; i++) {
		if (arr[i] != nullptr) {
			if (arr_tmp[arr_adr(arr[i]->key)]!=nullptr) {
				bool flag = 0;
				Node *lift = arr_tmp[arr_adr(arr[i]->key)];
				while (lift->next != nullptr)
				{
					if (lift->key == arr[i]->key) {
						lift->value = arr[i]->value;
						flag = 1;
					}
					lift = lift->next;
				}
				if (flag == 0) {
					Node *temp = new Node;
					temp->key = arr[i]->key;
					temp->value = arr[i]->value;
					temp->next = 0;
					lift->next = temp;
				}
			}
			else {
				arr_tmp[arr_adr(arr[i]->key)] = arr[i];
			}
		}
	}
	delete[] arr;
	arr = arr_tmp;
}