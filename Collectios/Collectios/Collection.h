#pragma once
#include <iostream>
#include <string>
using namespace std;
template <typename T>
struct Entry {
	string hash;
	string key;
	Entry *next = nullptr;
	T value;
};

template <typename T>
class Collection
{
public:
	Collection<T>() {};
	~Collection<T>() {};
	//virtual int size() = 0;
	//virtual void clear() = 0;
	//virtual bool isEmpty() = 0;
	virtual void add() = 0;
};

/*template <typename T>
class Set : public Collection<T> {
public:
	Set<T>() {};
	~Set<T>() {};
	//virtual int size() = 0;
	//virtual void clear() = 0;
	//virtual bool isEmpty() = 0;
	//virtual void add() = 0;
};*/


template <typename T>
class Hash_Set : public Collection<T> {
private:
	Entry <T> *map[16];
public:
	void add(T val, string key);
	Hash_Set<T>() {};
	~Hash_Set<T>() {};
};


template <typename T>
void Hash_Set<T>::add(T val, string key) {
	Entry<T> *temp = new Entry<T>;
	temp->hash = stoi(key);
	temp->key = key;
	temp->next = nullptr;
	temp->value = val;
	map[stoi(temp->hash) % 16] = temp;
}