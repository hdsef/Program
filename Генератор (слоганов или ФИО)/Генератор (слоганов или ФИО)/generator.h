#pragma once
#include <iostream>
#include <clocale>
#include <time.h>
class generator
{
private:
	char name[4][20] = {"������","������","����","������"};
	char surname[4][20] = { "��������","������","�������","������" };
	char patronymic[4][20] = {"��������������","�����������","�����","���������	"};
public:
	generator();
	~generator();
	void output();
};

