#include "stdafx.h"
#include "Stack_VM.h"


Stack_VM::Stack_VM()
{
}


Stack_VM::~Stack_VM()
{
}

void Stack_VM::decode(int inst) 
{
	if (inst != 0) {
		IP.push((inst & 0x0FFF));
		IP.push((inst & 0xF000) >> 12);
	}
}

void Stack_VM::fill(int code[],int j)
{
	for (int i = j-1; i >= 0; i--) {
		decode(code[i]);
	}
}

void Stack_VM::eval() {
	while (IP.isEmpty() != 1) {
		int a = IP.pop();
		switch (a)
		{
		case 0:
			break;
		case 1:
			SP.push(IP.pop());
			break;
		case 2:
			SP.pop();
			break;
		case 3:
			int b = SP.pop();
			int c = SP.pop();
			SP.push(b + c);
		}
	}
}

void Stack_VM::treatment(int code[], int j) {
	fill(code, j);
	eval();
}