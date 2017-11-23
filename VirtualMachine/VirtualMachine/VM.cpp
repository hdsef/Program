#include "stdafx.h"
#include "VM.h"


VM::VM()
{
}


VM::~VM()
{
}
int VM::fetch(int &val, int code[])
{
	return code[ip++];
}

void VM::decode(int inst, int prs[]) {
	if (inst != 0) {
		prs[0] = (inst & 0xF000) >> 12;
		prs[1] = (inst & 0x0F00) >> 8;
		prs[2] = (inst & 0x00F0) >> 4;
		prs[3] = (inst & 0x000F);
		prs[4] = (inst & 0x00FF);
	}
	else prs[0] = 0;
}
void VM::eval(int reg[], int prs[]) {
	switch (prs[0])
	{
	case 0: //exit
	break;
	case 1: //add
		reg[prs[1]] = prs[4];
	break;
	case 2://plus
		reg[prs[1]] = reg[prs[2]] + reg[prs[3]];
	break;
	}
}
void VM::treatment(int code[]) { 
	int y = 0;
	do{
		y = fetch(ip, code);
		decode(y, prs);
		eval(reg, prs);
	} while (y != 0);
}