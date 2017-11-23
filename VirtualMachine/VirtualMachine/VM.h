#pragma once

#include "stdafx.h"
class VM
{
private:
	int ip = 0;
	int reg[4];
	int prs[5];
	int fetch(int &val, int code[]);
	void decode(int inst, int prs[]);
	void eval(int reg[], int prs[]);
public:
	VM();
	~VM();
	void treatment(int code[]);
};

