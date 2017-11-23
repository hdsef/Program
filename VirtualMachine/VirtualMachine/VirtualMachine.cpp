// VirtualMachine.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "VM.h"

 
int main()
{
	int code[] = { 0x1008, 0x1106, 0x2201 ,0x2312, 0x0000};
	VM vm;
	vm.treatment(code);
    return 0;
}