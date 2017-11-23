// Stack-VM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack_VM.h"

int main()
{
	int code[] = { 0x1008, 0x1009, 0x3000, 0x1003, 0x3000, 0x0000 };
	int j = sizeof(code) / sizeof(code[0]);
	Stack_VM VM;
	VM.treatment(code, j);
    return 0;
}

