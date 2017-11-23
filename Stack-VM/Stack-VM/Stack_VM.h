#pragma once
#include "Stack.h"
class Stack_VM
{
private:
	Stack IP;
	Stack SP;

public:
	Stack_VM();
	~Stack_VM();
	void decode(int inst);
	void fill(int code[], int j);
	void eval();
	void treatment(int code[], int j);
};

