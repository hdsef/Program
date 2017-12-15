#pragma once
#include <iostream>
#include <string>
struct Node {
	int value;
	std::string key;
	Node *next = nullptr;
};
class Hash_table
{
private:
	Node *arr[256];
	int arr_adr(std::string key);
public:
	Hash_table();
	void put(std::string key, int val);
	void delete_n(std::string key);
	void get(std::string key);
	void all_keys();
	void all_vals();
	~Hash_table();
};

